#include "layer1_hal/robot_dog_hal.hpp"
#include "layer0_common/target.hpp"
#include "layer0_common/velocity.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <unistd.h>   // isatty(STDIN_FILENO) —— 人工闸门判断有没有终端

namespace {

// ── 极简 JSON 取值 ────────────────────────────────────────────────────────
// cmd_state 报文由我们自己的桥生成，格式完全受控（键名固定、字符串无转义、
// 数字是整数），所以不引入 JSON 库，用定界查找足够且无依赖。
// 若以后报文格式变复杂，这里要换成正经的 JSON 解析。
bool json_find(const std::string& s, const std::string& key, size_t& vbeg, size_t& vend)
{
    const std::string pat = "\"" + key + "\"";
    const size_t k = s.find(pat);
    if (k == std::string::npos) return false;
    const size_t colon = s.find(':', k + pat.size());
    if (colon == std::string::npos) return false;
    size_t p = colon + 1;
    while (p < s.size() && std::isspace(static_cast<unsigned char>(s[p]))) ++p;
    if (p >= s.size()) return false;
    if (s[p] == '"') {                       // 字符串值
        const size_t e = s.find('"', p + 1);
        if (e == std::string::npos) return false;
        vbeg = p + 1;
        vend = e;
        return true;
    }
    size_t e = p;                            // 数字（或 true/false/null）
    while (e < s.size() && s[e] != ',' && s[e] != '}') ++e;
    vbeg = p;
    vend = e;
    return true;
}

bool json_get_str(const std::string& s, const std::string& key, std::string& out)
{
    size_t a = 0, b = 0;
    if (!json_find(s, key, a, b)) return false;
    out.assign(s, a, b - a);
    return true;
}

bool json_get_int(const std::string& s, const std::string& key, int& out)
{
    size_t a = 0, b = 0;
    if (!json_find(s, key, a, b)) return false;
    try {
        out = std::stoi(s.substr(a, b - a));
        return true;
    } catch (...) {
        return false;
    }
}

}  // namespace

RobotDogHAL::RobotDogHAL() : Node("robot_dog_hal_node") {
    // ── 话题名对齐底层契约 ──────────────────────────────────────────
    // 底层是 dog_ws_bridge（把机器狗的 WebSocket 接口暴露成 ROS 话题），
    // 它提供的是 /rl_real/* 这一套。分工上"底层给协议、上层去适配"，
    // 所以直接改在这里，不在 launch 里加 remap。
    // 全部做成参数：现场若要换话题名，不用重编。
    this->declare_parameter<std::string>("cmd_vel_topic",     "/rl_real/cmd_vel");
    this->declare_parameter<std::string>("fsm_command_topic", "/rl_real/command");
    this->declare_parameter<std::string>("dog_state_topic",   "/rl_real/feedback");
    this->declare_parameter<std::string>("lidar_pose_topic",  "/lidar_data");
    this->declare_parameter<std::string>("cmd_state_topic",   "/rl_real/cmd_state");

    // ── 任务参数 ────────────────────────────────────────────────────
    // 等命令终态的超时。注意 getup 在控制器里是 1s 预起身 + 2s 起身 = 3s，
    // locomotion 要等起身插值跑完（percent_getup>=1）才能进，所以都要留余量。
    this->declare_parameter<double>("stand_timeout_s",      8.0);
    this->declare_parameter<double>("locomotion_timeout_s", 8.0);
    this->declare_parameter<double>("passive_timeout_s",    8.0);
    // 前进时长；设为 0 就跳过前进 —— 用于"只起立→进RL→趴下"的验证
    this->declare_parameter<double>("forward_duration_s",   3.5);
    this->declare_parameter<double>("forward_vx",           0.1);

    // ── 状态切换把关参数 ────────────────────────────────────────────
    this->declare_parameter<std::string>("check_stand_result_topic",
                                         "/rl_real/check_stand_result");
    // check_stand 走命令生命周期，正常几十毫秒就回；给 5s 是因为小脑那边要
    // 实打实读一遍电机零位 + IMU（CheckMotorInitPosition）。
    this->declare_parameter<double>("check_stand_timeout_s", 5.0);
    // 起立后的稳定等待：从**发 getup 起算**补足到这个时长。getup 自身约 3s
    // （1s 预起身 + 2s 起身），所以实际是 DONE 后再等约 7s。这是"状态码确认"
    // 之外的第二道保险，给狗留够真的站稳的时间，之后才允许进 RL。
    this->declare_parameter<double>("stand_settle_s",       10.0);
    // 其他状态切换（locomotion / passive）的默认稳定延迟
    this->declare_parameter<double>("transition_settle_s",  1.0);
    // 前置判断：等当前 FSM 状态变成期望值的超时。状态由桥 2Hz 的 status 轮询
    // 驱动，启动时还是 "Unknown"，必须给时间到货，不能瞬时比较。
    this->declare_parameter<double>("precondition_timeout_s", 5.0);
    // 切换后校验 FSM 状态码是否真的变了的等待超时
    this->declare_parameter<double>("fsm_confirm_timeout_s",  2.0);
    // 人工闸门：每次状态切换前等操作员按回车（照 ~/dog_step_test.py 的 gate()）。
    // 默认开。非交互场景（launch 拉起 / stdin 重定向）会被安全中止，
    // 必须显式关掉才会自动往下走。
    this->declare_parameter<bool>("confirm_transitions", true);

    const std::string cmd_vel_topic     = this->get_parameter("cmd_vel_topic").as_string();
    const std::string fsm_command_topic = this->get_parameter("fsm_command_topic").as_string();
    const std::string dog_state_topic   = this->get_parameter("dog_state_topic").as_string();
    const std::string lidar_pose_topic  = this->get_parameter("lidar_pose_topic").as_string();
    const std::string cmd_state_topic   = this->get_parameter("cmd_state_topic").as_string();
    const std::string check_stand_result_topic =
        this->get_parameter("check_stand_result_topic").as_string();

    stand_timeout_s_      = this->get_parameter("stand_timeout_s").as_double();
    locomotion_timeout_s_ = this->get_parameter("locomotion_timeout_s").as_double();
    passive_timeout_s_    = this->get_parameter("passive_timeout_s").as_double();
    forward_duration_s_   = this->get_parameter("forward_duration_s").as_double();
    forward_vx_           = this->get_parameter("forward_vx").as_double();
    check_stand_timeout_s_  = this->get_parameter("check_stand_timeout_s").as_double();
    stand_settle_s_         = this->get_parameter("stand_settle_s").as_double();
    transition_settle_s_    = this->get_parameter("transition_settle_s").as_double();
    precondition_timeout_s_ = this->get_parameter("precondition_timeout_s").as_double();
    fsm_confirm_timeout_s_  = this->get_parameter("fsm_confirm_timeout_s").as_double();
    confirm_transitions_    = this->get_parameter("confirm_transitions").as_bool();

    // 发布速度命令到桥
    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>(
        cmd_vel_topic, 10);

    // 发布 FSM 状态切换（桥会转成 WebSocket 的 command 帧）
    fsm_command_pub_ = this->create_publisher<std_msgs::msg::String>(
        fsm_command_topic, 10);

    // 订阅 LiDAR 里程计（本地 lidar_data_node 发的，不经桥）
    lidar_sub_ = this->create_subscription<ros2_tools::msg::LidarPose>(
        lidar_pose_topic, 10,
        [this](const ros2_tools::msg::LidarPose::SharedPtr msg) {
            RobotDogHAL::lidar_cb(msg);
        });

    // 订阅机器狗 FSM 状态反馈（桥把 WebSocket 的 feedback 转到这里）
    dog_state_sub_ = this->create_subscription<std_msgs::msg::String>(
        dog_state_topic, 10,
        [this](const std_msgs::msg::String::SharedPtr msg) {
            RobotDogHAL::dog_state_cb(msg);
        });

    // 订阅命令生命周期（桥转发）。这是本版"发命令后等结果"的依据。
    cmd_state_sub_ = this->create_subscription<std_msgs::msg::String>(
        cmd_state_topic, 10,
        [this](const std_msgs::msg::String::SharedPtr msg) {
            RobotDogHAL::cmd_state_cb(msg);
        });

    // 订阅 check_stand 的细节结果。注意它**不在** cmd_state 生命周期里，
    // 所以不能用来等终态，只用来把 reason/motors/imu 写进日志。
    check_stand_result_sub_ = this->create_subscription<std_msgs::msg::String>(
        check_stand_result_topic, 10,
        [this](const std_msgs::msg::String::SharedPtr msg) {
            RobotDogHAL::check_stand_result_cb(msg);
        });

    RCLCPP_INFO(this->get_logger(),
                "[RobotDogHAL] 硬件抽象层初始化完成 | cmd_vel=%s fsm_cmd=%s state=%s "
                "cmd_state=%s lidar=%s | 前进时长=%.1fs",
                cmd_vel_topic.c_str(), fsm_command_topic.c_str(),
                dog_state_topic.c_str(), cmd_state_topic.c_str(),
                lidar_pose_topic.c_str(), forward_duration_s_);
}

// ===== IStateProvider =====
DroneState RobotDogHAL::get_state() const {
    std::lock_guard<std::mutex> lock(state_mutex_);
    return state_;
}

bool RobotDogHAL::has_state() const {
    std::lock_guard<std::mutex> lock(state_mutex_);
    return has_state_;
}

// ===== ICommandPublisher =====
void RobotDogHAL::publish_velocity(Velocity& velocity) {
    auto msg = geometry_msgs::msg::Twist();
    msg.linear.x  = velocity.get_vx();
    msg.linear.y  = velocity.get_vy();
    msg.angular.z = velocity.get_vyaw();
    // vz/vpitch/vroll ignored for ground robot
    cmd_vel_pub_->publish(msg);
}

void RobotDogHAL::publish_position(Target& target) {
    // 地面机器人不支持绝对位置设点，用 P 控制转为速度
    DroneState s = get_state();
    float vx = 0.3f * (target.get_x() - s.x);
    float vy = 0.3f * (target.get_y() - s.y);
    vx = std::clamp(vx, -0.3f, 0.3f);
    vy = std::clamp(vy, -0.3f, 0.3f);
    Velocity vel(vx, vy, 0.0f, 0.0f);
    publish_velocity(vel);
}

// ===== IVisionProvider (空实现) =====
messages::msg::Vision RobotDogHAL::get_vision() const {
    return empty_vision_;
}

bool RobotDogHAL::has_vision() const {
    return false;
}

// ===== IDvsAvoidProvider (空实现) =====
geometry_msgs::msg::Twist RobotDogHAL::get_dvs_avoid_cmd() const {
    return empty_dvs_cmd_;
}

bool RobotDogHAL::has_recent_dvs_avoid(double /*max_age_sec*/) const {
    return false;
}

int64_t RobotDogHAL::get_last_dvs_detect_time_ns() const {
    return 0;
}

// ===== 命令生命周期 =====
void RobotDogHAL::request_fsm_transition(const std::string& fsm_state) {
    {
        // 先清上一次的终态，再记下这次要等的命令。
        // 顺序很重要：如果先发后清，回包快的话会被自己清掉。
        std::lock_guard<std::mutex> lock(cmd_mutex_);
        pending_cmd_   = fsm_state;
        pending_code_  = -1;
        pending_phase_.clear();
        pending_state_.clear();
    }
    auto msg = std_msgs::msg::String();
    msg.data = fsm_state;
    fsm_command_pub_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "[RobotDogHAL] → %s（等状态码）", fsm_state.c_str());
}

bool RobotDogHAL::wait_for_command_done(double timeout_sec) {
    return wait_for_command_code(timeout_sec, /*verbose=*/true) == 2;
}

int RobotDogHAL::wait_for_command_code(double timeout_sec, bool verbose) {
    const auto start = this->now();
    rclcpp::Rate rate(20);   // 50 ms 查一次

    while (rclcpp::ok()) {
        std::string cmd, phase, state;
        int code = -1;
        {
            std::lock_guard<std::mutex> lock(cmd_mutex_);
            if (pending_code_ >= 0) {
                cmd   = pending_cmd_;
                code  = pending_code_;
                phase = pending_phase_;
                state = pending_state_;
            }
        }
        if (code >= 0) {
            const double dt = (this->now() - start).seconds();
            if (code == 2) {
                RCLCPP_INFO(this->get_logger(),
                            "[RobotDogHAL] ✓ '%s' 完成（%.2fs，狗现在 %s）",
                            cmd.c_str(), dt, state.c_str());
            } else {
                RCLCPP_ERROR(this->get_logger(),
                             "[RobotDogHAL] ✗ '%s' 未完成：%s(%d)，狗现在 %s（%.2fs）",
                             cmd.c_str(), phase.c_str(), code, state.c_str(), dt);
            }
            return code;
        }
        if ((this->now() - start).seconds() > timeout_sec) {
            if (verbose) {
                std::string cmd_snapshot;
                {
                    std::lock_guard<std::mutex> lock(cmd_mutex_);
                    cmd_snapshot = pending_cmd_;
                }
                RCLCPP_ERROR(this->get_logger(),
                             "[RobotDogHAL] ✗ 等 '%s' 完成超时 %.1fs —— 没收到终态状态码。"
                             "桥在跑吗？cmd_state 话题有数据吗？（当前 FSM=%s）",
                             cmd_snapshot.c_str(), timeout_sec,
                             get_current_fsm_state().c_str());
            }
            return -1;
        }
        rate.sleep();
    }
    return -1;
}

void RobotDogHAL::set_navigation_mode(bool enable) {
    request_fsm_transition(enable ? "locomotion" : "passive");
}

// ===== 回调 =====
void RobotDogHAL::lidar_cb(const ros2_tools::msg::LidarPose::SharedPtr msg) {
    std::lock_guard<std::mutex> lock(state_mutex_);
    state_.x   = msg->x;
    state_.y   = msg->y;
    state_.z   = msg->z;
    state_.yaw = msg->yaw;
    state_.roll  = msg->roll;
    state_.pitch = msg->pitch;
    has_state_ = true;
}

void RobotDogHAL::dog_state_cb(const std_msgs::msg::String::SharedPtr msg) {
    // 反馈是空格分隔的**整句**，例如：
    //   "status state=RLFSMStatePassive gamepad_override=false"
    // 必须只取 state= 那个 token。原来把整句塞进 current_fsm_state_，
    // 于是 wait_for_fsm_state("RLFSMStatePassive") 永远比不中 —— 这正是
    // 它写好之后一直零调用的原因（前置判断/状态码确认全靠它，必须修）。
    const std::string& s = msg->data;
    std::string st;
    for (size_t p = 0; p + 6 <= s.size(); ++p) {
        if (s.compare(p, 6, "state=") != 0) continue;
        // 排除 xxx_state= 这种（本协议没有，稳妥起见）
        if (p > 0 && (std::isalnum(static_cast<unsigned char>(s[p - 1])) ||
                      s[p - 1] == '_')) continue;
        size_t e = p + 6;
        while (e < s.size() && !std::isspace(static_cast<unsigned char>(s[e]))) ++e;
        st.assign(s, p + 6, e - (p + 6));
        break;
    }
    if (st.empty()) return;   // 这条反馈里没有状态字段，别把已有状态冲掉

    std::lock_guard<std::mutex> lock(state_mutex_);
    current_fsm_state_ = st;
}

void RobotDogHAL::cmd_state_cb(const std_msgs::msg::String::SharedPtr msg) {
    std::string cmd, phase, state;
    int code = -1;
    if (!json_get_str(msg->data, "cmd", cmd))  return;
    if (!json_get_int(msg->data, "code", code)) return;
    if (code < 2) return;                       // 0 RECEIVED / 1 EXECUTING：还不是终态

    json_get_str(msg->data, "phase", phase);
    json_get_str(msg->data, "state", state);

    std::lock_guard<std::mutex> lock(cmd_mutex_);
    // 只认自己正在等的那条。桥自己轮询 status（cmd="status"）、
    // 以及连上时自动发的 nav_on 都会产生 cmd_state，必须滤掉。
    if (pending_cmd_.empty() || cmd != pending_cmd_) return;

    pending_code_  = code;
    pending_phase_ = phase;
    pending_state_ = state;
}

std::string RobotDogHAL::get_current_fsm_state() const {
    std::lock_guard<std::mutex> lock(state_mutex_);
    return current_fsm_state_;
}

bool RobotDogHAL::wait_for_fsm_state(const std::string& target, double timeout_sec) {
    // target 支持 "A|B" 多个候选，任一命中即算到达。
    // getdown 非要这个不可：RLFSMStateGetDown 是**过渡态**，2s 动画跑完会自动
    // 转到 RLFSMStatePassive，只等 GetDown 会擦肩而过、误报超时
    // （小脑 CMD_STATE_PROTOCOL.md §6 明确警告过）。
    std::vector<std::string> wanted;
    {
        std::string cur;
        for (char c : target) {
            if (c == '|') {
                if (!cur.empty()) { wanted.push_back(cur); cur.clear(); }
            } else {
                cur += c;
            }
        }
        if (!cur.empty()) wanted.push_back(cur);
    }
    auto hit = [&wanted](const std::string& s) {
        for (const auto& w : wanted) if (s == w) return true;
        return false;
    };

    auto start = this->now();
    rclcpp::Rate rate(10);
    while (rclcpp::ok()) {
        if (hit(get_current_fsm_state())) {
            return true;
        }
        if ((this->now() - start).seconds() > timeout_sec) {
            RCLCPP_WARN(this->get_logger(),
                "[RobotDogHAL] wait_for_fsm_state('%s') 超时(%.1fs), 当前='%s'",
                target.c_str(), timeout_sec, get_current_fsm_state().c_str());
            return false;
        }
        rate.sleep();
    }
    return false;
}

// ===== 状态切换把关 =====
double RobotDogHAL::timeout_for_cmd(const std::string& cmd) const {
    if (cmd == "getup" || cmd == "stand" || cmd == "up")         return stand_timeout_s_;
    if (cmd == "locomotion" || cmd == "rl" || cmd == "walk")     return locomotion_timeout_s_;
    if (cmd == "passive" || cmd == "stop" || cmd == "safe_stop") return passive_timeout_s_;
    // getdown 也是"趴下"，而且要多留出 2s 插值动画的时间
    if (cmd == "getdown" || cmd == "down" || cmd == "lie" || cmd == "sit")
        return passive_timeout_s_;
    if (cmd == "check_stand" || cmd == "stand_check" || cmd == "check")
        return check_stand_timeout_s_;
    return stand_timeout_s_;   // 未知命令：给最宽的那个兜底
}

void RobotDogHAL::check_stand_result_cb(const std_msgs::msg::String::SharedPtr msg) {
    // 报文是内嵌 JSON 字符串（小脑 web_bridge publishCheckStandResult）：
    //   {"ready":true,"motors_ready":true,"imu_ready":true,"reason":""}
    // 只用来打日志；通过与否以 cmd_state 的状态码为准（见 run_check_stand）。
    std::string ready, motors, imu, reason;
    json_get_str(msg->data, "ready", ready);
    json_get_str(msg->data, "motors_ready", motors);
    json_get_str(msg->data, "imu_ready", imu);
    json_get_str(msg->data, "reason", reason);

    std::string detail = "motors_ready=" + (motors.empty() ? std::string("?") : motors)
                       + " imu_ready="    + (imu.empty()    ? std::string("?") : imu);
    if (!reason.empty()) detail += " reason=\"" + reason + "\"";

    {
        std::lock_guard<std::mutex> lock(check_stand_mutex_);
        check_stand_detail_ = detail;
    }
    RCLCPP_INFO(this->get_logger(), "[RobotDogHAL] check_stand 细节：ready=%s %s",
                ready.empty() ? "?" : ready.c_str(), detail.c_str());
}

bool RobotDogHAL::run_check_stand(double timeout_sec) {
    {
        std::lock_guard<std::mutex> lock(check_stand_mutex_);
        check_stand_detail_.clear();
    }

    // 走 /rl_real/command（和 ws_demo.py 的 send_action("check_stand") 一致），
    // 这样能拿到完整的 cmd_state 生命周期：DONE=可站立，FAILED=不可站立。
    // 不走 /rl_real/check_stand 专线：那条只回 check_stand_result，不在生命周期里。
    //
    // check_stand 是**查询型**命令：要上位机主动触发才有回复，不是小脑主动推送。
    // 只发一次可能拿不到终态（去重窗口 / 链路抖动 / 小脑那边恰好没跑到），
    // 所以**反复触发**直到拿到终态或总超时。每次发布桥都会重新分配 seq，
    // 重发不会被小脑的 (seq,cmd) 去重吃掉 —— 用户 2026-09-28 明确：
    // check_stand 可以多次发布，不用关心去重。
    const auto t_start = this->now();
    constexpr double kSliceS = 1.0;   // 每轮最多等 1s，拿不到就重发
    int attempt = 0;
    bool got_terminal = false;

    while (rclcpp::ok()) {
        const double remain = timeout_sec - (this->now() - t_start).seconds();
        if (remain <= 0.0) break;

        ++attempt;
        RCLCPP_INFO(this->get_logger(),
                    "[RobotDogHAL] 触发 check_stand（第 %d 次）", attempt);
        request_fsm_transition("check_stand");

        // 故意不看返回值：这一轮只关心"有没有拿到终态"，统一在下面读 pending_code_
        (void)wait_for_command_code((std::min)(kSliceS, remain), /*verbose=*/false);
        {
            std::lock_guard<std::mutex> lock(cmd_mutex_);
            got_terminal = (pending_code_ >= 0);
        }
        if (got_terminal) break;
    }

    if (!got_terminal) {
        RCLCPP_ERROR(this->get_logger(),
                     "[RobotDogHAL] ✗ check_stand 触发 %d 次、共 %.1fs 都没收到终态 —— "
                     "不可站立。桥在跑吗？cmd_state 话题有数据吗？（当前 FSM=%s）",
                     attempt, (this->now() - t_start).seconds(),
                     get_current_fsm_state().c_str());
        return false;
    }

    int code = -1;
    {
        std::lock_guard<std::mutex> lock(cmd_mutex_);
        code = pending_code_;
    }
    if (code != 2) {
        RCLCPP_ERROR(this->get_logger(),
                     "[RobotDogHAL] ✗ check_stand 未通过（code=%d）—— 不可站立", code);
        return false;
    }

    std::string detail;
    {
        std::lock_guard<std::mutex> lock(check_stand_mutex_);
        detail = check_stand_detail_;
    }
    const std::string suffix = detail.empty() ? std::string() : (" | " + detail);
    RCLCPP_INFO(this->get_logger(),
                "[RobotDogHAL] ✓ check_stand 通过（第 %d 次触发拿到结果）%s",
                attempt, suffix.c_str());
    return true;
}

bool RobotDogHAL::transition_to(const std::string& cmd,
                                const std::string& expect_state,
                                const std::string& require_state,
                                double settle_s) {
    // ── 第 1 道：前置判断 ────────────────────────────────────────────
    // 用 wait_for_fsm_state 而不是瞬时比较：current_fsm_state_ 由桥 2Hz 的
    // status 轮询驱动，启动时还是 "Unknown"，必须给它时间到货。
    if (!require_state.empty()) {
        RCLCPP_INFO(this->get_logger(),
                    "[RobotDogHAL] 前置判断：等当前状态 → %s", require_state.c_str());
        if (!wait_for_fsm_state(require_state, precondition_timeout_s_)) {
            RCLCPP_ERROR(this->get_logger(),
                         "[RobotDogHAL] ✗ 前置判断不满足：要求 %s，实际 %s —— 不发 '%s'",
                         require_state.c_str(), get_current_fsm_state().c_str(),
                         cmd.c_str());
            return false;
        }
        RCLCPP_INFO(this->get_logger(),
                    "[RobotDogHAL] 前置判断通过：当前 %s ✓", require_state.c_str());
    }

    // ── 第 2 道：发命令 + 等终态状态码 ───────────────────────────────
    // 稳定延迟的起算点 = **发命令这一刻**（需求："发布起立指令后等待10s"）。
    // 不能取在函数开头：前置判断最长会吃掉 precondition_timeout_s，
    // 那样 10s 稳定期会被侵吞掉（前置等 5s + getup 3s 就只剩 2s 了）。
    const auto t_start = this->now();
    request_fsm_transition(cmd);
    if (!wait_for_command_done(timeout_for_cmd(cmd))) {
        RCLCPP_ERROR(this->get_logger(),
                     "[RobotDogHAL] ✗ '%s' 未完成 —— 不继续后续状态切换", cmd.c_str());
        return false;
    }

    // ── 第 3 道：状态码确认（"同时状态码改变"）───────────────────────
    // wait_for_command_done 只保证状态码到了 DONE(2)；这里再要一次实证：
    // 读回来的 FSM 状态必须真的等于期望值，否则不算切换成功。
    if (!expect_state.empty()) {
        if (!wait_for_fsm_state(expect_state, fsm_confirm_timeout_s_)) {
            RCLCPP_ERROR(this->get_logger(),
                         "[RobotDogHAL] ✗ 状态码未变到 %s（当前 %s）—— 视为 '%s' 未完成",
                         expect_state.c_str(), get_current_fsm_state().c_str(),
                         cmd.c_str());
            return false;
        }
        RCLCPP_INFO(this->get_logger(),
                    "[RobotDogHAL] 状态码确认：%s ✓", expect_state.c_str());
    }

    // ── 第 4 道：稳定延迟（从发命令起算补足）─────────────────────────
    const double elapsed = (this->now() - t_start).seconds();
    if (elapsed < settle_s) {
        const double remain = settle_s - elapsed;
        RCLCPP_INFO(this->get_logger(),
                    "[RobotDogHAL] '%s' 已确认，稳定延迟再等 %.1fs（目标共 %.1fs）",
                    cmd.c_str(), remain, settle_s);
        rclcpp::Rate rate(20);
        const auto t_wait = this->now();
        while (rclcpp::ok() && (this->now() - t_wait).seconds() < remain) {
            rate.sleep();
        }
    }

    RCLCPP_INFO(this->get_logger(),
                "[RobotDogHAL] ✓ '%s' 完成（共 %.1fs，含稳定延迟 %.1fs）",
                cmd.c_str(), (this->now() - t_start).seconds(), settle_s);
    return true;
}

// ===== 人工闸门 =====
bool RobotDogHAL::wait_for_enter(const std::string& prompt) {
    if (!confirm_transitions_) {
        return true;   // 显式关掉了闸门，自动往下走
    }

    if (!::isatty(STDIN_FILENO)) {
        RCLCPP_ERROR(this->get_logger(),
            "[人工闸门] stdin 不是终端，没法等回车 —— 按安全策略中止。"
            "若要非交互运行，请显式传 -p confirm_transitions:=false");
        return false;
    }

    std::cout << "\n>>> " << prompt << "   [回车继续 / q 放弃] " << std::flush;

    std::string line;
    const bool got = static_cast<bool>(std::getline(std::cin, line));
    if (!got || !rclcpp::ok()) {
        std::cout << std::endl;
        RCLCPP_WARN(this->get_logger(),
                    "[人工闸门] 没读到输入（EOF 或已请求关闭）—— 视为放弃");
        return false;
    }

    // 去掉所有空白再转小写：空行 = 直接回车 = 继续
    std::string s;
    for (char c : line) {
        if (!std::isspace(static_cast<unsigned char>(c)))
            s += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    if (s == "q" || s == "quit") {
        RCLCPP_WARN(this->get_logger(), "[人工闸门] 操作员按 q 放弃");
        return false;
    }

    RCLCPP_INFO(this->get_logger(), "[人工闸门] 已确认，继续");
    return true;
}

