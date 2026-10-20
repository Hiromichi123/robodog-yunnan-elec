#include "layer2_control/local_recovery.hpp"
#include "layer3_mission/dog_plan_executor.hpp"

#include <chrono>
#include <cmath>
#include <cstdio>
#include <thread>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <nlohmann/json.hpp>

#include "layer0_common/velocity.hpp"
#include "layer3_mission/goto_control.hpp"
#include "layer2_control/local_navigation.hpp"

namespace mission {

namespace {

// 到点控制律和容差集中在 goto_control.hpp，普通点不校准终点航向。
constexpr double kPoseTimeoutS = 1.0;   // 位姿多久没更新就停
constexpr int    kStopFrames  = 5;      // 到位后连发几帧零速再 vel_stop
constexpr double kControlHz   = 20.0;

double seconds_since(const std::chrono::steady_clock::time_point& t0) {
    return std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
}

// Written only after publishing zero velocity, never in the moving hot path.
std::string save_recovery_failure(const LocalSafety::Snapshot& snapshot,const local_nav::Pose& pose,
                                 const local_nav::Pose& goal,const local_nav::Config& cfg,
                                 const local_nav::RecoveryDecision& decision,const std::string& revision,
                                 const std::string& prefix="recovery") {
    try {
        const char* home=std::getenv("HOME");if(!home||!*home)return {};
        const auto directory=std::filesystem::path(home)/"logs/navigation_failures";
        std::filesystem::create_directories(directory);
        static unsigned sequence=0;
        const auto path=directory/(prefix+"-failure-"+std::to_string(++sequence%16)+".json");
        const auto encode=[](const std::shared_ptr<const local_nav::Grid>& g)->nlohmann::json {
            if(!g)return nullptr;
            return {{"valid",g->valid},{"resolution",g->resolution},{"origin_x",g->origin_x},
                    {"origin_y",g->origin_y},{"width",g->width},{"height",g->height},{"cells",g->cells}};
        };
        nlohmann::json data={
            {"schema_version",1},{"unix_ms",std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count()},
            {"state",decision.state},{"detail",decision.detail},{"session_id",snapshot.session_id},
            {"map_sequence",snapshot.sequence},{"revision",revision},
            {"pose",{{"x",pose.x},{"y",pose.y},{"yaw",pose.yaw}}},
            {"goal",{{"x",goal.x},{"y",goal.y},{"yaw",goal.yaw}}},
            {"control_config",{{"footprint_front",cfg.footprint_front},{"footprint_rear",cfg.footprint_rear},
                {"half_width",cfg.half_width},{"margin",cfg.margin},{"max_vx",cfg.max_vx},{"max_wz",cfg.max_wz},
                {"reaction_s",cfg.reaction_s},{"decel",cfg.decel},{"angular_decel",cfg.angular_decel},
                {"rollout_s",cfg.rollout_s},{"soft_buffer_enabled",cfg.soft_buffer_enabled},
                {"hard_margin",local_nav::hard_margin(cfg)},
                {"buffer_max_vx",cfg.buffer_max_vx},{"buffer_max_wz",cfg.buffer_max_wz}}},
            {"observed_grid",encode(snapshot.observed_grid)},{"control_grid",encode(snapshot.grid)}};
        const auto temporary=path.string()+".tmp";
        {std::ofstream out(temporary,std::ios::trunc);out<<data.dump();out.flush();if(!out)return {};}
        std::filesystem::rename(temporary,path);
        return path.string();
    }catch(const std::exception&){return {};}
}

}  // namespace

DogPlanExecutor::DogPlanExecutor(RobotDogHAL&       hal,
                                 FlightController&  fc,
                                 DogMissionChannel& channel,
                                 rclcpp::Logger     logger)
    : hal_(hal), fc_(fc), channel_(channel), logger_(logger) {}

void DogPlanExecutor::request_abort() {
    abort_ = true;
}

void DogPlanExecutor::drain_cmds() {
    std::string ignored;
    while (channel_.take_cmd(ignored)) {
        RCLCPP_WARN(logger_, "[任务] 丢掉一条过期指令：%s", ignored.c_str());
    }
}

// ────────────────────────────────────────────────────────────────────────
// 主流程
// ────────────────────────────────────────────────────────────────────────
void DogPlanExecutor::execute(const MissionPlan& plan) {
    abort_ = false;
    last_error_.clear();
    drain_cmds();                        // 上一轮残留的 confirm/abort 不算数
    channel_.set_doc_accepting(false);   // 跑任务期间不再收新任务
    current_name_ = plan.name;
    safety_session_.clear();
    navigation_results_.clear();
    navigation_state_ = hal_.safety_mode() == "observe" ? "observe_only_no_protection" : "";
    step_started_at_ = {};

    const std::size_t total = plan.steps.size();
    current_total_ = total;
    RCLCPP_INFO(logger_, "[任务] 开始「%s」：%zu 步，确认方式=%s",
                plan.name.c_str(), total,
                plan.confirm == ConfirmMode::Each ? "逐步确认（危险步骤前暂停）"
                                                  : "一次授权（全程不暂停）");

    std::size_t completed = 0;
    bool failed = false;
    bool failed_keep_standing = false;   // 失败，但狗已停住、要留在站立位（不 getdown）

    for (std::size_t i = 0; i < total; ++i) {
        if (abort_) break;
        const MissionStep& st = plan.steps[i];
        const std::string label = step_label(st);
        current_index_ = i + 1;
        current_type_ = to_string(st.type);
        navigation_state_ = hal_.safety_mode() == "observe" ? "observe_only_no_protection" : "";

        // 危险步骤前的人工闸门。尺度与原来的终端闸门一致：
        // 会改变姿态/位置的那几步要问，check_stand / wait 不问。
        if (plan.confirm == ConfirmMode::Each && is_dangerous_step(st.type)) {
            switch (confirm_gate(st.type, gate_prompt(st), i + 1, total)) {
                case Gate::Continue: break;
                case Gate::AbortMission: abort_ = true; break;
                case Gate::SkipStep:
                    RCLCPP_WARN(logger_, "[任务] 第 %zu 步「%s」被跳过", i + 1, label.c_str());
                    continue;
            }
            if (abort_) break;
        }

        push("running", i + 1, total, to_string(st.type), "", "", true);
        const Outcome out = dispatch(st, i + 1);

        if (abort_) break;
        if (out == Outcome::Failed) { failed = true; break; }
        if (out == Outcome::FailedKeepStanding) { failed_keep_standing = true; break; }
        ++completed;
    }

    channel_.set_doc_accepting(true);

    if (abort_) {
        go_down_and_report("操作员急停");
        push("aborted", -1, total, "", "已急停：停速 + getdown 回趴下", "", false);
        RCLCPP_WARN(logger_, "[任务] 「%s」已中止（完成 %zu/%zu 步）",
                    plan.name.c_str(), completed, total);
        return;
    }
    if (failed || failed_keep_standing) {
        if (failed_keep_standing) {
            // 已经就地停住的失败（goto 超时）：**只压零速，不 getdown** ——
            // 狗留在 RL 站立状态等人工处置。压零速这一步是防守性的：
            // 返回前那一步自己也压过，这里再压一次保证"不管哪个步骤返回
            // 这个结果，速度一定是 0"。
            publish_zero_velocity();
        } else {
            go_down_and_report(last_error_);
        }
        push("failed", -1, total, "", last_error_, "", false);
        RCLCPP_ERROR(logger_, "[任务] 「%s」失败于 %zu/%zu 步：%s%s",
                     plan.name.c_str(), completed + 1, total, last_error_.c_str(),
                     failed_keep_standing ? " —— 已停速保持站立（不趴下，等人工处置）" : "");
        return;
    }

    push("done", -1, total, "", "任务完成", "", false);
    RCLCPP_INFO(logger_, "[任务] 「%s」完成（%zu 步）", plan.name.c_str(), total);
}

DogPlanExecutor::Outcome DogPlanExecutor::dispatch(const MissionStep& st, std::size_t index) {
    Outcome out = Outcome::Failed;
    switch (st.type) {
        case StepType::CheckStand: out = do_check_stand(st); break;
        case StepType::GetUp:      out = do_getup(st);      break;
        case StepType::Locomotion: out = do_locomotion(st); break;
        case StepType::Move:       out = do_move(st);       break;
        case StepType::Goto:
        case StepType::GotoPose:   out = do_goto(st);       break;
        case StepType::Wait:       out = do_wait(st);       break;
        case StepType::GetDown:    out = do_getdown(st);    break;
    }

    // 失败原因补上"第几步、什么类型" —— 网页上只显示这一行，必须能直接定位。
    if ((out == Outcome::Failed || out == Outcome::FailedKeepStanding) &&
        !abort_ && !last_error_.empty()) {
        last_error_ = "第 " + std::to_string(index) + " 步（" + to_string(st.type) +
                      "）：" + last_error_;
    }
    return out;
}

// ────────────────────────────────────────────────────────────────────────
// 各步骤
// ────────────────────────────────────────────────────────────────────────
DogPlanExecutor::Outcome DogPlanExecutor::do_check_stand(const MissionStep& st) {
    const double timeout = st.timeout_s > 0.0 ? st.timeout_s : hal_.get_check_stand_timeout_s();
    RCLCPP_INFO(logger_, "[任务] 站立自检（超时 %.1fs）", timeout);
    if (hal_.run_check_stand(timeout)) return Outcome::Ok;

    last_error_ = hal_.is_gamepad_override()
                      ? "站立自检未通过（手柄正抢着控制权）"
                      : "站立自检未通过：" + hal_.get_check_stand_error() + " —— 不可起立";
    return Outcome::Failed;
}

DogPlanExecutor::Outcome DogPlanExecutor::do_getup(const MissionStep& st) {
    const double settle = st.settle_s >= 0.0 ? st.settle_s : hal_.get_stand_settle_s();

    // 先等 Passive，再单发探针；Unknown 不能跳过探针后直接起立。
    if (!hal_.wait_for_fsm_state("RLFSMStatePassive", hal_.get_precondition_timeout_s())) {
        last_error_ = "起立前状态未确认趴下 —— 不发送探针或起立";
        return Outcome::Failed;
    }
    if (abort_) { last_error_ = "操作员急停"; return Outcome::Failed; }
    if (!hal_.run_probe_motors(hal_.get_probe_motors_timeout_s())) {
        last_error_ = "起立前电机探针未回复成功（失败、拒绝或超时）—— 不可起立";
        return Outcome::Failed;
    }
    if (abort_) { last_error_ = "操作员急停"; return Outcome::Failed; }

    // 前置：狗必须是趴着的。已经站着时这一步会失败 —— 这是对的，
    // 硬发一次 getup 只会被 FSM 拒，不如把"当前状态"如实报出来。
    if (hal_.transition_to("getup", "RLFSMStateGetUp", "RLFSMStatePassive", settle)) {
        return Outcome::Ok;
    }
    if (abort_) { last_error_ = "操作员急停"; return Outcome::Failed; }
    last_error_ = "起立未确认完成（当前 " + hal_.get_current_fsm_state() +
                  "）—— 若狗已站着，这一步是多余的，删掉它";
    return Outcome::Failed;
}

DogPlanExecutor::Outcome DogPlanExecutor::do_locomotion(const MissionStep& st) {
    (void)st;

    // ── 进入 RL 门禁：站姿校验（小脑 v7.5.1 起强制）──────────────────────
    // 小脑 locomotion 处理要求 stand_check_done_ && stand_check_ok_，同样每次
    // 趴下即作废。只在狗处于站立的稳定态（GetUp）时才校验：若已在 RLLocomotion
    // 行走中，CheckStandingPose 天然不过，不能拿它误伤"重复发 locomotion"的情况。
    if (hal_.get_current_fsm_state() == "RLFSMStateGetUp") {
        if (!hal_.run_check_standing(hal_.get_check_standing_timeout_s())) {
            last_error_ = hal_.is_gamepad_override()
                              ? "进入 RL 前站姿校验未通过（手柄正抢着控制权）"
                              : "进入 RL 前站姿校验未通过（关节偏离站姿或未静止）";
            return Outcome::Failed;
        }
    }

    if (hal_.transition_to("locomotion", "RLFSMStateRLLocomotion", "RLFSMStateGetUp",
                           hal_.get_transition_settle_s())) {
        return Outcome::Ok;
    }
    if (abort_) { last_error_ = "操作员急停"; return Outcome::Failed; }
    last_error_ = "进入 RL 运动模式失败（当前 " + hal_.get_current_fsm_state() + "）";
    return Outcome::Failed;
}

DogPlanExecutor::Outcome DogPlanExecutor::do_move(const MissionStep& st) {
    RCLCPP_INFO(logger_, "[任务] 移动 vx=%.2f vy=%.2f wz=%.2f × %.1fs",
                st.vx, st.vy, st.wz, st.duration_s);

    const auto t0 = std::chrono::steady_clock::now();
    rclcpp::Rate rate(kControlHz);

    while (rclcpp::ok()) {
        if (abort_) {
            last_error_ = "操作员急停";   // 停速由统一处置负责
            return Outcome::Failed;
        }
        if (hal_.is_gamepad_override()) {
            last_error_ = "手柄抢走了控制权（小脑行为：抢走后所有指令被忽略）—— 先放开手柄";
            return Outcome::Failed;
        }
        // 真机检查：狗必须真的在 RL 模式。计划文本里有没有 getup/locomotion
        // 不算数 —— 上一轮任务结束时它可能还站着，那时"只移动"是合法的；
        // 反之计划里写了 getup 但狗已经站着，getup 那步自己会失败。
        const std::string fsm = hal_.get_current_fsm_state();
        if (fsm != "RLFSMStateRLLocomotion") {
            last_error_ = "狗不在 RL 运动模式（当前 " + fsm +
                          "）—— 任务里要先有 getup 和 locomotion";
            return Outcome::Failed;
        }

        if (hal_.safety_enforced()) {
            const auto safety = hal_.get_safety_snapshot();
            if (!accept_safety_session(safety) || !safety.valid || !safety.grid) {
                publish_zero_velocity();
                last_error_ = "定时移动安全数据不可用或导航会话变化：" + safety.reason;
                navigation_status("blocked", last_error_);
                return Outcome::FailedKeepStanding;
            }
        }
        if (seconds_since(t0) >= st.duration_s) break;

        Velocity v(static_cast<float>(st.vx), static_cast<float>(st.vy), 0.0f,
                   static_cast<float>(st.wz));
        fc_.fly_by_velocity(v);
        if (hal_.safety_enforced() && hal_.last_velocity_blocked()) {
            last_error_ = "定时移动被安全门禁阻挡：" + hal_.last_safety_reason();
            publish_zero_velocity();
            navigation_status("blocked", last_error_);
            return Outcome::FailedKeepStanding;
        }
        rate.sleep();
    }

    const bool stopped = stop_motion();
    if (hal_.safety_enforced() && (!rclcpp::ok() || !stopped)) {
        last_error_ = "定时移动停车收尾未确认";
        return Outcome::FailedKeepStanding;
    }
    return Outcome::Ok;
}

DogPlanExecutor::Outcome DogPlanExecutor::do_goto(const MissionStep& st) {
    const bool require_yaw = st.type == StepType::GotoPose;
    const bool enforce = hal_.safety_enforced();
    const auto t0 = std::chrono::steady_clock::now();
    auto last_log = t0;
    auto blocked_since = t0;
    auto progress_at = t0;
    bool blocked = false, have_start = false, adjusted = false;
    int occupied_frames = 0, arrived_frames = 0, adjustments = 0, arrival_rechecks = 0, arrival_safety_rechecks = 0;
    std::uint64_t last_map_sequence = 0, last_arrived_sample = 0;
    double best_distance = 0.0;
    local_nav::Pose start{};
    MissionStep effective = st;
    GotoController controller;
    local_nav::LocalRecovery recovery;
    std::string last_recovery_state;
    int last_recovery_plan_count=-1;
    auto tolerance_revision = hal_.get_goto_config().tolerance_revision;
    rclcpp::Rate rate(kControlHz);
    RCLCPP_INFO(logger_, "[任务] %s，总超时 %.1fs，安全模式=%s",
                step_label(st).c_str(), st.goto_timeout_s, hal_.safety_mode().c_str());

    const auto fail_blocked = [&](const std::string& reason) {
        publish_zero_velocity();
        last_error_ = reason + " —— 已停速保持站立，任务不继续";
        navigation_status("blocked", last_error_);
        record_navigation_result(st, effective, "blocked", reason);
        return Outcome::FailedKeepStanding;
    };
    const auto hold = [&](const std::string& reason) {
        Velocity zero(0.0f, 0.0f, 0.0f, 0.0f);
        hal_.publish_velocity(zero);
        arrived_frames = 0;
        if (!blocked) { blocked = true; blocked_since = std::chrono::steady_clock::now(); }
        navigation_status("waiting_clearance", reason);
        return seconds_since(blocked_since) >= 5.0;
    };

    while (rclcpp::ok()) {
        if (abort_) { last_error_ = "操作员急停"; return Outcome::Failed; }
        if (hal_.is_gamepad_override()) {
            last_error_ = "手柄抢走了控制权 —— 先放开手柄";
            return Outcome::Failed;
        }
        if (!pose_is_fresh(kPoseTimeoutS)) {
            last_error_ = "位姿超时 —— 已停速";
            return Outcome::Failed;
        }
        if (hal_.get_current_fsm_state() != "RLFSMStateRLLocomotion") {
            last_error_ = "狗不在 RL 运动模式 —— 已停速";
            return Outcome::Failed;
        }
        if (seconds_since(t0) > st.goto_timeout_s) return fail_blocked("在规定时间内未到达目标");

        const auto snapshot = hal_.get_navigation_snapshot();
        const double age = std::chrono::duration<double>(
            std::chrono::steady_clock::now() - snapshot.received_at).count();
        if (!snapshot.available || age < 0.0 || age > kPoseTimeoutS) {
            return fail_blocked("导航快照不可用或过期");
        }
        const auto& s = snapshot.state;
        const local_nav::Pose pose{s.x, s.y, s.yaw};
        if (enforce) hal_.prepare_safety_startup(pose,true);
        if (!have_start) {
            start = pose;
            have_start = true;
            best_distance = std::hypot(st.x - s.x, st.y - s.y);
        }
        const auto safety = hal_.get_safety_snapshot();
        if (hal_.safety_mode() == "observe") {
            navigation_status(safety.valid ? "observe_ready_no_protection" : "observe_invalid_no_protection",
                              "仅观测，不提供碰撞保护：" + safety.reason);
        }
        if (enforce) {
            if (!accept_safety_session(safety)) return fail_blocked("导航原点会话已变化，请重新确认任务坐标");
            if (!safety.valid || !safety.grid) {
                if (hold("感知不可用：" + safety.reason)) return fail_blocked("感知不可用：" + safety.reason);
                rate.sleep();
                continue;
            }
            const auto& cfg = hal_.get_local_nav_config();
            const double target_yaw = require_yaw ? st.yaw : std::atan2(effective.y - s.y, effective.x - s.x);
            const local_nav::Pose target{effective.x, effective.y, target_yaw};
            if (safety.sequence != last_map_sequence) {
                last_map_sequence = safety.sequence;
                occupied_frames = local_nav::goal_needs_adjustment(*safety.grid, target, cfg)
                                      ? occupied_frames + 1 : 0;
            }
            if (occupied_frames >= 3) {
                if (adjustments >= 3) return fail_blocked("目标多次重新受阻，停止继续修正");
                const local_nav::Pose original{st.x, st.y, require_yaw ? st.yaw : target_yaw};
                const auto replacement = local_nav::find_adjusted_goal(*safety.grid, pose, original, start, cfg);
                if (!replacement.found) {
                    // 滚动地图可能看见墙，却还没覆盖终点附近的安全落点。远端尚不能
                    // 修正时仍可执行已验证的局部轨迹，不能在此提前等待到失败。
                    // 靠近终点才等待落点；足迹安全检查仍禁止把墙边位置算到达。
                    if (std::hypot(effective.x - s.x, effective.y - s.y) <= 1.0) {
                        if (hold("目标被障碍占据，未找到保留前进距离的安全落点")) {
                            return fail_blocked("目标受阻且没有连通的安全修正目标");
                        }
                        rate.sleep();
                        continue;
                    }
                } else {
                    effective.x = replacement.goal.x;
                    effective.y = replacement.goal.y;
                    // goto_pose 的 yaw 始终来自原计划，位置修正不能取消终点航向。
                    adjusted = true;
                    ++adjustments;
                    occupied_frames = 0;
                    arrived_frames = 0;
                    controller.reset();
                    best_distance = std::hypot(effective.x - s.x, effective.y - s.y);
                    progress_at = std::chrono::steady_clock::now();
                    navigation_status("goal_adjusted", "目标位于障碍或缓冲区，已回退/侧移到可达自由区域");
                    RCLCPP_WARN(logger_, "[任务] 目标修正 (%.2f, %.2f) -> (%.2f, %.2f)",
                                st.x, st.y, effective.x, effective.y);
                }
            }
        }

        const auto tuning = hal_.get_goto_config();
        if (tuning.tolerance_revision != tolerance_revision) {
            arrived_frames = 0;
            tolerance_revision = tuning.tolerance_revision;
        }
        const double sample_time = std::chrono::duration<double>(snapshot.received_at.time_since_epoch()).count();
        bool recovery_tick=false;
        bool recovery_reverse=false;
        const auto control = controller.update(effective, s.x, s.y, s.yaw,
                                               snapshot.sample_id, sample_time, tuning.config);
        if (!control.valid) return fail_blocked("导航位姿、配置或目标含无效数值");
        const bool safe_arrival = !enforce ||
            (local_nav::footprint_safe(*safety.grid, pose, hal_.get_local_nav_config()) &&
             local_nav::goal_in_free_space(*safety.grid,
                {effective.x, effective.y, require_yaw ? st.yaw : s.yaw}, hal_.get_local_nav_config()));
        if (control.arrived && safe_arrival) {
            Velocity zero(0.0f, 0.0f, 0.0f, 0.0f);
            hal_.publish_velocity(zero);
            blocked = false;
            if (snapshot.sample_id != last_arrived_sample) {
                last_arrived_sample = snapshot.sample_id;
                ++arrived_frames;
            }
            if (arrived_frames >= kStopFrames) {
                const bool stopped = stop_motion();
                if (abort_) { last_error_ = "操作员急停"; return Outcome::Failed; }
                if (enforce) {
                    auto final_map = hal_.get_safety_snapshot();
                    auto final_pose = hal_.get_navigation_snapshot();
                    bool pose_after_stop=false,map_after_stop=false;
                    if(stopped) {
                        const auto settled_from=std::chrono::steady_clock::now();
                        const auto pose_before=final_pose.sample_id,map_before=final_map.sequence;
                        while(rclcpp::ok()&&!abort_&&seconds_since(settled_from)<.75) {
                            hal_.publish_velocity(zero);
                            final_map=hal_.get_safety_snapshot();final_pose=hal_.get_navigation_snapshot();
                            pose_after_stop=final_pose.sample_id>=pose_before+2&&final_pose.received_at>=settled_from;
                            map_after_stop=final_map.sequence>map_before;
                            if(pose_after_stop&&map_after_stop&&seconds_since(settled_from)>=.20)break;
                            std::this_thread::sleep_for(std::chrono::milliseconds(50));
                        }
                        if(abort_){last_error_="操作员急停";return Outcome::Failed;}
                    }
                    const double final_age = std::chrono::duration<double>(
                        std::chrono::steady_clock::now() - final_pose.received_at).count();
                    const auto final_tuning=hal_.get_goto_config();
                    const auto& f=final_pose.state;
                    const local_nav::Pose final_body{f.x,f.y,f.yaw};
                    const local_nav::Pose final_goal{effective.x,effective.y,require_yaw?st.yaw:f.yaw};
                    const bool session_ok=accept_safety_session(final_map);
                    const bool pose_ok=pose_after_stop&&final_pose.available&&final_age>=0&&final_age<=kPoseTimeoutS&&local_nav::valid_pose(final_body);
                    const bool map_ok=map_after_stop&&final_map.valid&&final_map.grid;
                    const bool body_ok=map_ok&&pose_ok&&local_nav::footprint_safe(*final_map.grid,final_body,hal_.get_local_nav_config());
                    const bool target_ok=map_ok&&pose_ok&&local_nav::goal_in_free_space(*final_map.grid,final_goal,hal_.get_local_nav_config());
                    const double final_distance=std::hypot(f.x-effective.x,f.y-effective.y);
                    const double final_yaw_error=require_yaw?std::abs(std::remainder(f.yaw-st.yaw,2*M_PI)):0.;
                    std::string reason;
                    bool retry=false;
                    if(!stopped)reason="arrival_stop_unconfirmed";
                    else if(!session_ok)reason="arrival_session_changed";
                    else if(!pose_ok)reason=pose_after_stop?"arrival_pose_stale":"arrival_pose_not_updated";
                    else if(!map_ok){reason="arrival_map_unavailable";retry=true;}
                    else if(!body_ok)reason="arrival_body_blocked";
                    else if(!target_ok){reason="arrival_target_buffer_blocked";retry=true;}
                    else if(final_distance>final_tuning.config.tol_xy){reason="arrival_position_drift";retry=true;}
                    else if(require_yaw&&final_yaw_error>final_tuning.config.tol_yaw){reason="arrival_yaw_drift";retry=true;}
                    if(!reason.empty()) {
                        const std::string detail=nlohmann::json({{"reason",reason},{"rechecks",arrival_rechecks},
                            {"stop_confirmed",stopped},{"session_ok",session_ok},{"map_ok",map_ok},{"map_reason",final_map.reason},
                            {"pose_ok",pose_ok},{"pose_after_stop",pose_after_stop},{"map_after_stop",map_after_stop},{"pose_age_s",final_age},{"body_ok",body_ok},{"target_ok",target_ok},
                            {"distance_m",final_distance},{"tolerance_m",final_tuning.config.tol_xy},
                            {"yaw_error",final_yaw_error},{"yaw_tolerance",final_tuning.config.tol_yaw},
                            {"before_pose",{{"x",s.x},{"y",s.y},{"yaw",s.yaw}}},
                            {"after_pose",{{"x",f.x},{"y",f.y},{"yaw",f.yaw}}}}).dump();
                        local_nav::RecoveryDecision evidence;evidence.state=reason;evidence.detail=detail;
                        const auto file=save_recovery_failure(final_map,final_body,final_goal,hal_.get_local_nav_config(),evidence,
                            hal_.get_parameter("safety_config_revision").as_string(),"arrival");
                        RCLCPP_WARN(logger_,"[停车复核] %s snapshot=%s",detail.c_str(),file.c_str());
                        if(!retry)return fail_blocked("停车复核失败："+reason);
                        ++arrival_rechecks;
                        const bool tolerance_only=reason=="arrival_position_drift"||reason=="arrival_yaw_drift";
                        if(!tolerance_only&&++arrival_safety_rechecks>3)return fail_blocked("停车安全复核超过3次："+reason);
                        // Resume through the ordinary fresh-map/pose, target correction,
                        // swept trajectory and HAL gates; never publish a special bypass.
                        arrived_frames=0;last_arrived_sample=0;controller.reset();blocked=false;
                        progress_at=std::chrono::steady_clock::now();
                        navigation_status("arrival_reapproach","停车复核未通过，重新安全接近目标："+reason);
                        rate.sleep();continue;
                    }
                }
                record_navigation_result(st, effective, adjusted ? "adjusted_arrival" : "arrived",
                                         adjusted ? "原目标受阻，已到达保留前进距离的安全修正目标" : "已到达原目标");
                navigation_status(adjusted ? "adjusted_arrival" : "arrived");
                return adjusted ? Outcome::AdjustedArrival : Outcome::Ok;
            }
        } else {
            arrived_frames = 0;
            double vx = control.vx, wz = control.wz;
            if (enforce) {
                if (control.arrived) {
                    if (hold("位置已接近目标，但目标或车身足迹尚未确认安全")) return fail_blocked("终点足迹不安全");
                    rate.sleep();
                    continue;
                }
                auto candidate = local_nav::select_command(*safety.grid, pose,
                    {effective.x, effective.y, require_yaw ? st.yaw : s.yaw}, vx, wz, hal_.get_local_nav_config());
                // Let the existing multi-frame occupied-goal correction settle
                // before recovery. Reversing cannot make an occupied goal valid.
                if (control.mode!=GotoMode::FinalYaw && safety.observed_grid &&
                    !local_nav::goal_needs_adjustment(*safety.grid,
                        {effective.x,effective.y,require_yaw?st.yaw:s.yaw},hal_.get_local_nav_config())) {
                    const auto decision=recovery.update(*safety.grid,*safety.observed_grid,pose,
                        {effective.x,effective.y,require_yaw?st.yaw:s.yaw},hal_.get_local_nav_config(),candidate,seconds_since(t0));
                    if(decision.active && (decision.state!=last_recovery_state || recovery.plan_count()!=last_recovery_plan_count)) {
                        RCLCPP_WARN(logger_,"[局部恢复] %s | %s | pose=(%.3f,%.3f,%.3f)",
                            decision.state.c_str(),decision.detail.c_str(),pose.x,pose.y,pose.yaw);
                        last_recovery_state=decision.state;last_recovery_plan_count=recovery.plan_count();
                    }
                    if(decision.failed) {
                        publish_zero_velocity();
                        const auto file=save_recovery_failure(safety,pose,
                            {effective.x,effective.y,require_yaw?st.yaw:s.yaw},hal_.get_local_nav_config(),decision,
                            hal_.get_parameter("safety_config_revision").as_string());
                        RCLCPP_ERROR(logger_,"[局部恢复] 失败地图快照：%s",file.empty()?"保存失败":file.c_str());
                        return fail_blocked("局部绕行/脱困终止："+decision.state);
                    }
                    if(decision.active) {
                        candidate=decision.command;recovery_tick=true;recovery_reverse=decision.reverse;
                        progress_at=std::chrono::steady_clock::now();
                        navigation_status(decision.state,"局部绕行/有界脱困，原任务目标保持不变");
                    }
                }
                if (!candidate.safe) {
                    if (hold(candidate.reason)) return fail_blocked("没有安全的局部前进/转向轨迹：" + candidate.reason);
                    rate.sleep();
                    continue;
                }
                vx = candidate.vx;
                wz = candidate.wz;
            }
            Velocity v(static_cast<float>(vx), 0.0f, 0.0f, static_cast<float>(wz));
            if(recovery_reverse) hal_.publish_recovery_reverse(v);
            else fc_.fly_by_velocity(v);
            if (enforce && hal_.last_velocity_blocked()) {
                if (hold("发速安全门禁：" + hal_.last_safety_reason())) return fail_blocked("发速安全门禁持续阻挡");
            } else {
                blocked = false;
                if (enforce && !recovery_tick) navigation_status(adjusted ? "driving_adjusted" : "driving");
            }
        }
        if (enforce && !control.arrived && !recovery_tick) {
            if (control.distance < best_distance - 0.05) {
                best_distance = control.distance;
                progress_at = std::chrono::steady_clock::now();
            } else if (seconds_since(progress_at) >= 20.0) {
                return fail_blocked("局部导航持续无前进进展");
            }
        }
        if (seconds_since(last_log) >= 1.0) {
            last_log = std::chrono::steady_clock::now();
            RCLCPP_INFO(logger_, "[任务] %s: 现在 (%.2f, %.2f, %.2f) -> 实际目标 (%.2f, %.2f)，"
                        "原目标 (%.2f, %.2f)，距离 %.2f m，mode=%s",
                        to_string(st.type), s.x, s.y, s.yaw, effective.x, effective.y,
                        st.x, st.y, control.distance, goto_mode_name(control.mode));
        }
        rate.sleep();
    }
    stop_motion();
    last_error_ = "rclcpp 已请求关闭";
    return Outcome::Failed;
}

DogPlanExecutor::Outcome DogPlanExecutor::do_wait(const MissionStep& st) {
    RCLCPP_INFO(logger_, "[任务] 原地等 %.1fs", st.duration_s);
    const auto t0 = std::chrono::steady_clock::now();
    rclcpp::Rate rate(kControlHz);
    while (rclcpp::ok() && seconds_since(t0) < st.duration_s) {
        if (abort_) {
            last_error_ = "操作员急停";
            return Outcome::Failed;
        }
        rate.sleep();
    }
    return Outcome::Ok;
}

DogPlanExecutor::Outcome DogPlanExecutor::do_getdown(const MissionStep& st) {
    RCLCPP_INFO(logger_, "[任务] 趴下（getdown 平滑 2s 插值）");
    // 直接用 HAL 的安全趴下：已经趴着就什么都不发、起立动画中会重试，
    // 逻辑与失败路径完全同一条，不重复实现。
    if (hal_.safe_go_down(st.settle_s)) return Outcome::Ok;
    last_error_ = "趴下未确认完成（当前 " + hal_.get_current_fsm_state() + "）";
    return Outcome::Failed;
}

// ────────────────────────────────────────────────────────────────────────
// 闸门 / 停止 / 上报
// ────────────────────────────────────────────────────────────────────────
DogPlanExecutor::Gate DogPlanExecutor::confirm_gate(StepType type, const std::string& prompt,
                                                    std::size_t index, std::size_t total) {
    drain_cmds();   // 先清残留：连点两下"继续"不能把下一步也批准了
    push("waiting_confirm", index, total, to_string(type), "", prompt, false);
    RCLCPP_WARN(logger_, "[任务] 第 %zu/%zu 步等网页确认：%s", index, total, prompt.c_str());

    rclcpp::Rate rate(kControlHz);
    auto last_warn = std::chrono::steady_clock::now();

    while (rclcpp::ok()) {
        if (abort_) return Gate::AbortMission;

        std::string cmd;
        if (channel_.take_cmd(cmd)) {
            if (cmd == "confirm") {
                RCLCPP_INFO(logger_, "[任务] 操作员确认，继续");
                return Gate::Continue;
            }
            if (cmd == "reject") {
                // 趴下这一步的"放弃"= 跳过它、保持站立（照原来"趴下前按 q"的语义：
                // 任务已经跑完，不替操作员做主卸力，但要提醒需人工看护）。
                if (type == StepType::GetDown) {
                    RCLCPP_WARN(logger_, "[任务] 操作员放弃趴下 —— 保持站立，需人工看护");
                    return Gate::SkipStep;
                }
                RCLCPP_WARN(logger_, "[任务] 操作员放弃 —— 中止任务");
                return Gate::AbortMission;
            }
            // abort 由 spin 线程的钩子直接置位，这里多半读不到；读到也当中止
            if (cmd == "abort") return Gate::AbortMission;
        }

        // 不设超时中止：操作员去接个电话，比"等不到人回答就自动动"安全得多。
        // 只是每 30s 提醒一次还在等。
        if (seconds_since(last_warn) >= 30.0) {
            last_warn = std::chrono::steady_clock::now();
            RCLCPP_WARN(logger_, "[任务] 还在等确认（第 %zu 步）—— 网页上点「继续」或「放弃」",
                        index);
        }
        rate.sleep();
    }
    return Gate::AbortMission;
}

void DogPlanExecutor::publish_zero_velocity() {
    // 桥自己的 cmd_vel_timeout_s=0.5 也会把速度归零，但那要等半秒。
    // 这里直接连发几帧零速，停下来的延迟是"一帧 50ms"，不是"等看门狗"。
    Velocity zero(0.0f, 0.0f, 0.0f, 0.0f);
    for (int i = 0; i < kStopFrames; ++i) {
        hal_.publish_velocity(zero);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

bool DogPlanExecutor::stop_motion() {
    publish_zero_velocity();
    // 零速已经发出；enforce 的成功路径还必须确认停车收尾，不能把失联算到达。
    const bool stopped = hal_.transition_to("vel_stop", "", "", 0.0);
    if (!stopped) RCLCPP_WARN(logger_, "[任务] vel_stop 未确认（桥断了？）—— 已发送零速");
    return stopped;
}

bool DogPlanExecutor::accept_safety_session(const RobotDogHAL::SafetySnapshot& safety) {
    if (!hal_.safety_enforced()) return true;
    if (safety.session_id.empty()) return safety_session_.empty();
    if (safety_session_.empty()) safety_session_ = safety.session_id;
    return safety_session_ == safety.session_id;
}

void DogPlanExecutor::navigation_status(const std::string& state, const std::string& message) {
    if (navigation_state_ == state) return;
    navigation_state_ = state;
    push("running", current_index_, current_total_, current_type_, message, "", false);
}

void DogPlanExecutor::record_navigation_result(const MissionStep& original, const MissionStep& effective,
                                              const std::string& outcome, const std::string& reason) {
    if (navigation_results_.size() >= kMaxSteps) return;
    DogMissionChannel::NavigationResult result;
    result.index = static_cast<int>(current_index_);
    result.outcome = outcome;
    result.reason = reason;
    result.original_x = original.x; result.original_y = original.y;
    result.effective_x = effective.x; result.effective_y = effective.y;
    navigation_results_.push_back(result);
}

bool DogPlanExecutor::pose_is_fresh(double max_age_s) const {
    if (!hal_.has_state()) return false;
    const rclcpp::Time stamp = hal_.get_state_stamp();
    if (stamp.nanoseconds() == 0) return false;   // 从来没收到过
    const double age = (hal_.now() - stamp).seconds();
    return age >= 0.0 && age <= max_age_s;
}

void DogPlanExecutor::go_down_and_report(const std::string& reason) {
    RCLCPP_ERROR(logger_, "[任务] %s —— 停速 + getdown 回趴下（不用 passive）", reason.c_str());
    publish_zero_velocity();   // 只压零速：紧接着就 getdown，不必再等一次 vel_stop 确认
    if (!hal_.safe_go_down()) {
        RCLCPP_ERROR(logger_,
                     "[任务] 安全趴下未成功确认 —— 狗的状态需要人工确认后处置");
    }
}

void DogPlanExecutor::push(const std::string& phase, std::size_t index, std::size_t total,
                           const std::string& type, const std::string& msg,
                           const std::string& prompt, bool reset_step_clock) {
    DogMissionChannel::Status s;
    s.phase   = phase;
    s.type    = type;
    s.msg     = msg;
    s.prompt  = prompt;
    s.index   = static_cast<int>(index);
    s.total   = static_cast<int>(total);
    if (reset_step_clock) step_started_at_ = std::chrono::steady_clock::now();
    s.step_started_at = step_started_at_;
    s.safety_mode = hal_.safety_mode();
    s.navigation_state = navigation_state_;
    s.navigation_results = navigation_results_;
    // 名字每次任务开始时 push 一次就够，但这里每次都带上，省得记状态
    s.name = current_name_;
    channel_.set_status(s);
    channel_.publish_status_now();
}

std::string DogPlanExecutor::step_label(const MissionStep& st) const {
    char buf[96];
    switch (st.type) {
        case StepType::CheckStand: return "站立自检";
        case StepType::GetUp:      return "起立";
        case StepType::Locomotion: return "进入 RL 运动模式";
        case StepType::Move:
            std::snprintf(buf, sizeof(buf), "移动 (vx %.2f, vy %.2f, wz %.2f, %.1fs)",
                          st.vx, st.vy, st.wz, st.duration_s);
            return buf;
        case StepType::Goto:
            std::snprintf(buf, sizeof(buf), "位置到点 (%.2f, %.2f)", st.x, st.y);
            return buf;
        case StepType::GotoPose:
            std::snprintf(buf, sizeof(buf), "带航向到点 (%.2f, %.2f, %.2f rad)", st.x, st.y, st.yaw);
            return buf;
        case StepType::Wait:
            std::snprintf(buf, sizeof(buf), "等待 %.1fs", st.duration_s);
            return buf;
        case StepType::GetDown:    return "趴下";
    }
    return "未知步骤";
}

std::string DogPlanExecutor::gate_prompt(const MissionStep& st) const {
    char buf[224];
    switch (st.type) {
        case StepType::GetUp:
            std::snprintf(buf, sizeof(buf),
                          "即将起立（狗会从趴姿站起来）。确认周围安全后点「继续」");
            break;
        case StepType::Locomotion:
            std::snprintf(buf, sizeof(buf),
                          "即将进入 RL 运动模式（此后狗会响应速度指令）。确认后点「继续」");
            break;
        case StepType::Move:
            std::snprintf(buf, sizeof(buf),
                          "即将移动 vx=%.2f vy=%.2f wz=%.2f × %.1fs (≈%.0fcm)。"
                          "确认前方空旷后点「继续」",
                          st.vx, st.vy, st.wz, st.duration_s,
                          std::hypot(st.vx, st.vy) * st.duration_s * 100.0);
            break;
        case StepType::Goto:
            std::snprintf(buf, sizeof(buf),
                          "即将闭环前往 (%.2f, %.2f)，只判断位置，不校准终点航向。"
                          "确认路线空旷后点「继续」", st.x, st.y);
            break;
        case StepType::GotoPose:
            std::snprintf(buf, sizeof(buf),
                          "即将闭环前往 (%.2f, %.2f)，到点后校准航向 %.2f rad。"
                          "确认路线空旷后点「继续」",
                          st.x, st.y, st.yaw);
            break;
        case StepType::GetDown:
            std::snprintf(buf, sizeof(buf),
                          "任务已跑完。点「继续」趴下（平滑）；"
                          "点「放弃」保持站立姿态（需人工看护）");
            break;
        default:
            std::snprintf(buf, sizeof(buf), "即将执行「%s」", step_label(st).c_str());
            break;
    }
    return buf;
}

}  // namespace mission
