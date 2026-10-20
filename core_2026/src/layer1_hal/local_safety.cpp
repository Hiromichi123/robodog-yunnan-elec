#include "layer1_hal/local_safety.hpp"
#include "layer2_control/startup_unknown.hpp"
#include "layer2_control/local_recovery.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <nlohmann/json.hpp>

LocalSafety::LocalSafety(rclcpp::Node& node) : node_(node) {
    // 启动时固定配置；禁止静默热切换。
    rcl_interfaces::msg::ParameterDescriptor fixed;
    fixed.read_only = true;
    mode_ = node_.declare_parameter<std::string>("safety_mode", "disabled", fixed);
    if (mode_ != "disabled" && mode_ != "observe" && mode_ != "enforce")
        throw std::invalid_argument("safety_mode must be disabled, observe or enforce");
    config_revision_ = node_.declare_parameter<std::string>(
        "safety_config_revision", "lidar-only-explicit-v2", fixed);
    if (config_revision_.empty() || config_revision_.size() > 128)
        throw std::invalid_argument("invalid safety_config_revision");
    // Deprecated CLI parameter: retained for compatibility, not a readiness gate.
    node_.declare_parameter<bool>("safety_calibration_validated", false, fixed);
    unknown_as_free_=node_.declare_parameter<bool>("safety_unknown_as_free",false,fixed);
    unknown_exploration_range_=node_.declare_parameter<double>("safety_unknown_exploration_range_m",5.0,fixed);
    if (!std::isfinite(unknown_exploration_range_) || unknown_exploration_range_<.5 || unknown_exploration_range_>5.)
        throw std::invalid_argument("invalid unknown exploration range");
    startup_unknown_enabled_=node_.declare_parameter<bool>("safety_startup_unknown_free",true,fixed);
    timeout_s_ = node_.declare_parameter<double>("safety_timeout_s", 0.5, fixed);
    auto param = [&](const char* name, double& value) {
        value = node_.declare_parameter<double>(name, value, fixed);
    };
    param("safety_footprint_front", config_.footprint_front);
    param("safety_footprint_rear", config_.footprint_rear);
    param("safety_half_width", config_.half_width);
    param("safety_margin", config_.margin);
    config_.soft_buffer_enabled=node_.declare_parameter<bool>("safety_soft_buffer_enabled",true,fixed);
    param("safety_hard_margin",config_.hard_margin);
    param("safety_buffer_max_vx",config_.buffer_max_vx);
    param("safety_buffer_max_wz",config_.buffer_max_wz);
    param("safety_reaction_s", config_.reaction_s);
    param("safety_decel", config_.decel);
    param("safety_angular_decel", config_.angular_decel);
    param("safety_max_vx", config_.max_vx);
    param("safety_max_wz", config_.max_wz);
    param("safety_max_lateral_shift", config_.max_lateral_shift);
    param("safety_max_longitudinal_loss", config_.max_longitudinal_loss);
    if (!local_nav::valid_config(config_) || !std::isfinite(timeout_s_) ||
        timeout_s_ <= 0.0 || timeout_s_ > 1.0)
        throw std::invalid_argument("invalid local safety configuration");
    status_pub_ = node_.create_publisher<std_msgs::msg::String>(
        "/dog/safety/status", rclcpp::QoS(1).reliable());
    status_timer_ = node_.create_wall_timer(std::chrono::seconds(1), [this] { publish_status(); });
    if (mode_ == "disabled") return;
    const auto topic = node_.declare_parameter<std::string>("safety_map_topic", "/local_safety/map", fixed);
    map_sub_ = node_.create_subscription<ros2_tools::msg::LocalSafetyMap>(
        topic, rclcpp::QoS(1).best_effort(),
        [this](ros2_tools::msg::LocalSafetyMap::ConstSharedPtr msg) { receive(*msg); });
    origin_sub_ = node_.create_subscription<std_msgs::msg::String>(
        "/navigation_origin", rclcpp::QoS(1).reliable().transient_local(),
        [this](std_msgs::msg::String::ConstSharedPtr msg) { origin(*msg); });
    RCLCPP_WARN(node_.get_logger(), "[近场安全] mode=%s source=lidar；无需人工标定门禁，observe不提供碰撞保护",
                mode_.c_str());
}

void LocalSafety::origin(const std_msgs::msg::String& msg) {
    std::lock_guard<std::mutex> lock(mutex_);
    try {
        const auto j = nlohmann::json::parse(msg.data);
        const auto session = j.at("session_id").get<std::string>();
        const std::array<double, 4> values{{j.at("x").get<double>(), j.at("y").get<double>(),
                                            j.at("z").get<double>(), j.at("yaw").get<double>()}};
        if (session.empty() || session.size() > 128 || j.at("frame") != "startup_navigation" ||
            !std::all_of(values.begin(), values.end(), [](double v) {
                return std::isfinite(v) && std::abs(v) < 100000;
            }))
            throw std::invalid_argument("origin frame/session/coordinates");
        if (!origin_session_.empty() &&
            (session != origin_session_ || values != origin_values_)) epoch_changed_ = true;
        origin_session_ = session;
        origin_values_ = values;
        origin_valid_ = true;
        origin_received_at_ = std::chrono::steady_clock::now();
    } catch (...) {
        // A later map callback cannot repair missing/invalid origin metadata.
        origin_valid_ = false;
        latest_.valid = false;
        latest_.reason = "无效导航原点";
    }
}

void LocalSafety::receive(const ros2_tools::msg::LocalSafetyMap& msg) {
    Snapshot next;
    next.valid = msg.valid;
    next.reason = msg.reason;
    next.session_id = msg.session_id;
    next.sequence = msg.sequence;
    const auto& m = msg.grid;
    const auto& q = m.info.origin.orientation;
    const bool shape_ok = m.info.width > 0 && m.info.height > 0 &&
        m.info.width <= 400 && m.info.height <= 400 &&
        m.data.size() == static_cast<std::size_t>(m.info.width) * m.info.height &&
        std::isfinite(m.info.resolution) && m.info.resolution >= 0.02 && m.info.resolution <= 0.5 &&
        std::isfinite(m.info.origin.position.x) && std::isfinite(m.info.origin.position.y) &&
        std::isfinite(q.x) && std::isfinite(q.y) && std::isfinite(q.z) && std::isfinite(q.w) &&
        std::abs(q.x) < 1e-6 && std::abs(q.y) < 1e-6 && std::abs(q.z) < 1e-6 &&
        std::abs(std::abs(q.w) - 1.0) < 1e-6 &&
        msg.header.frame_id == "startup_navigation" && m.header.frame_id == msg.header.frame_id &&
        !msg.session_id.empty() && msg.sequence > 0 &&
        std::isfinite(msg.observation_age_s) && msg.observation_age_s >= 0.0 &&
        std::all_of(m.data.begin(), m.data.end(), [](int8_t v) { return v == -1 || v == 0 || v == 100; });
    if (shape_ok) {
        auto grid = std::make_shared<local_nav::Grid>();
        grid->resolution = m.info.resolution;
        grid->origin_x = m.info.origin.position.x;
        grid->origin_y = m.info.origin.position.y;
        grid->width = static_cast<int>(m.info.width);
        grid->height = static_cast<int>(m.info.height);
        grid->cells = m.data;
        grid->valid = msg.valid;
        next.grid = grid;
    } else {
        next.valid = false;
        next.reason = "安全地图格式/坐标系无效";
    }
    if (msg.config_revision.empty() || msg.config_revision != config_revision_) {
        next.valid = false;
        next.reason = "安全地图配置版本缺失/不一致";
    }
    const std::int64_t stamp = static_cast<std::int64_t>(msg.header.stamp.sec) * 1000000000LL + msg.header.stamp.nanosec;
    std::lock_guard<std::mutex> lock(mutex_);
    if (latest_.sequence && latest_.session_id == next.session_id &&
        (next.sequence <= latest_.sequence || stamp < stamp_ns_)) {
        latest_.valid = false;
        latest_.reason = "安全地图序号/时间倒退，需重启核验";
        epoch_changed_ = true;
        return;
    }
    if (!latest_.session_id.empty() && next.session_id != latest_.session_id) epoch_changed_ = true;
    latest_ = std::move(next);
    received_at_ = std::chrono::steady_clock::now();
    source_age_s_ = msg.observation_age_s;
    stamp_ns_ = stamp;
}

LocalSafety::Snapshot LocalSafety::snapshot() const {
    std::unique_lock<std::mutex> lock(mutex_);
    auto out = latest_;
    auto fail = [&](const char* reason) { out.valid = false; out.reason = reason; };
    const auto steady_now = std::chrono::steady_clock::now();
    const double rx_age = std::chrono::duration<double>(steady_now - received_at_).count();
    const double origin_age = std::chrono::duration<double>(steady_now - origin_received_at_).count();
    const double stamp_age = (node_.now().nanoseconds() - stamp_ns_) / 1e9;
    if (epoch_changed_) fail("定位/地图会话改变，需人工重启任务节点核验");
    else if (!origin_valid_ || origin_session_.empty() || origin_age > 2.5 || origin_age < 0.0 ||
             origin_session_ != out.session_id) fail("安全地图与导航原点不一致/过期");
    else if (!out.grid || rx_age < 0.0 || rx_age > timeout_s_ ||
             source_age_s_ + rx_age > timeout_s_ || stamp_age < -0.05 || stamp_age > timeout_s_)
        fail("近场观测过期/时间不一致");
    out.observed_grid=out.grid;
    const bool apply=startup_unknown_enabled_ && startup_fixed_ && !startup_retired_;
    const auto seed=startup_pose_;
    lock.unlock();
    if (out.valid && out.grid && (apply || unknown_as_free_)) {
        auto grid=std::make_shared<local_nav::Grid>(*out.grid);
        if (apply && !unknown_as_free_) out.startup_unknown_cells=local_nav::apply_startup_unknown(*grid,seed,config_);
        if (unknown_as_free_) out.exploration_unknown_cells=local_nav::apply_unknown_exploration(*grid,unknown_exploration_range_);
        out.grid=grid;
    }
    return out;
}

void LocalSafety::prepare_startup(const local_nav::Pose& pose,bool pose_fresh) {
    if (!startup_unknown_enabled_ || mode_!="enforce" || !pose_fresh || !local_nav::valid_pose(pose)) return;
    const auto current=snapshot();
    if (!current.valid || !current.grid) return;
    std::lock_guard<std::mutex> lock(mutex_);
    if (epoch_changed_ || !origin_valid_ || startup_retired_) return;
    if (!startup_fixed_) {
        startup_pose_=pose;startup_fixed_=true;
        RCLCPP_WARN(node_.get_logger(),"起步未知区一次性放行，固定于(%.3f,%.3f,%.3f)，占据格仍拦截",
                    pose.x,pose.y,pose.yaw);
    } else if (std::hypot(pose.x-startup_pose_.x,pose.y-startup_pose_.y) >
               std::max(config_.footprint_front,config_.footprint_rear)+config_.margin+current.grid->resolution) {
        startup_retired_=true;
    }
}

bool LocalSafety::check(const local_nav::Pose& pose, bool pose_fresh, double vx, double wz) {
    if (vx>=0) {std::lock_guard<std::mutex> lock(mutex_);reverse_gate_active_=false;}
    bool safe = std::isfinite(vx) && std::isfinite(wz);
    std::string why = safe ? "" : "速度非有限值";
    if (safe && mode_ != "disabled" && (vx != 0.0 || wz != 0.0)) {
        prepare_startup(pose,pose_fresh);
        const auto s = snapshot();
        if (!s.valid) { safe = false; why = s.reason; }
        else if (!pose_fresh) { safe = false; why = "位姿过期"; }
        else if (vx < 0.0 || vx > config_.max_vx + 1e-6 || std::abs(wz) > config_.max_wz + 1e-6) {
            safe = false; why = "速度超出近场配置范围";
        } else if (!local_nav::swept_safe(*s.grid, pose, vx, wz, config_)) {
            safe = false; why = "预测扫掠/制停区域受阻或未知";
        }
    }
    std::lock_guard<std::mutex> lock(mutex_);
    blocked_ = !safe && (enforced() || !std::isfinite(vx) || !std::isfinite(wz));
    reason_ = why;
    return !blocked_;
}

bool LocalSafety::check_recovery_reverse(const local_nav::Pose& pose,bool fresh,double vx,double wz) {
    const auto s=snapshot();
    bool safe=enforced() && fresh && local_nav::valid_pose(pose) && std::isfinite(vx) &&
              std::isfinite(wz) && vx<0 && vx>=-std::min(.08,config_.max_vx)-1e-6 && std::abs(wz)<1e-9 &&
              s.valid && s.grid && s.observed_grid;
    std::string why="后退恢复需要有效位姿、原始地图及限速直退命令";
    if(safe) {safe=local_nav::certified_reverse(*s.observed_grid,*s.grid,pose,-vx,config_);
        if(!safe)why="新增后退扫掠区域缺少真实自由证据或存在障碍";}
    std::lock_guard<std::mutex> lock(mutex_);
    const auto now=std::chrono::steady_clock::now();
    if(safe&&!reverse_gate_active_) {reverse_gate_active_=true;reverse_gate_start_=pose;reverse_gate_time_=now;}
    if(safe && (std::chrono::duration<double>(now-reverse_gate_time_).count()>4.0 ||
                std::hypot(pose.x-reverse_gate_start_.x,pose.y-reverse_gate_start_.y)>.30 ||
                std::abs(std::remainder(pose.yaw-reverse_gate_start_.yaw,2*M_PI))>.15)) {
        safe=false;why="后退恢复超出距离、时间或航向限制";
    }
    blocked_=!safe;reason_=safe?"":why;return safe;
}

void LocalSafety::publish_status() {
    const auto current = snapshot();
    bool last_blocked;
    std::string velocity_reason;
    bool seed_fixed,seed_retired;
    local_nav::Pose seed_pose;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        last_blocked = blocked_;
        velocity_reason = reason_;
        seed_fixed=startup_fixed_;seed_retired=startup_retired_;seed_pose=startup_pose_;
    }
    const nlohmann::json control = {
        {"footprint_front", config_.footprint_front}, {"footprint_rear", config_.footprint_rear},
        {"half_width", config_.half_width}, {"margin", config_.margin},
        {"soft_buffer_enabled",config_.soft_buffer_enabled},
        {"hard_margin",config_.hard_margin},{"effective_hard_margin",local_nav::hard_margin(config_)},
        {"buffer_max_vx",config_.buffer_max_vx},{"buffer_max_wz",config_.buffer_max_wz},
        {"reaction_s", config_.reaction_s}, {"decel", config_.decel},
        {"angular_decel", config_.angular_decel}, {"max_vx", config_.max_vx},
        {"max_wz", config_.max_wz}, {"max_lateral_shift", config_.max_lateral_shift},
        {"max_longitudinal_loss", config_.max_longitudinal_loss}, {"timeout_s", timeout_s_}
    };
    std_msgs::msg::String msg;
    msg.data = nlohmann::json({
        {"protocol_version", 2}, {"sensor_source", "lidar"}, {"calibration_required", false}, {"mode", mode_}, {"revision", config_revision_},
        {"config", {{"control", control}}}, {"calibration_validated", false},
        {"map_valid", current.valid}, {"protection_ready", enforced() && current.valid},
        {"reason", mode_ == "disabled" ? "任务通道保护已关闭" : current.reason},
        {"blocked", last_blocked}, {"last_velocity_reason", velocity_reason},
        {"session_id", current.session_id}, {"sequence", current.sequence},
        {"unknown_exploration", {{"enabled",unknown_as_free_},{"range_m",unknown_exploration_range_},
            {"speed_limit_m_s",config_.max_vx},{"changed_cells",current.exploration_unknown_cells}}},
        {"startup_unknown", {{"enabled",startup_unknown_enabled_},{"fixed",seed_fixed},
            {"retired",seed_retired},{"changed_cells",current.startup_unknown_cells},
            {"x",seed_pose.x},{"y",seed_pose.y},{"yaw",seed_pose.yaw}}},
        {"scope", "dog_node_task_velocity_only"}
    }).dump();
    status_pub_->publish(msg);
}

bool LocalSafety::blocked() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return blocked_;
}
std::string LocalSafety::reason() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return reason_;
}
