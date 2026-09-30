#include "layer3_mission/dog_plan_executor.hpp"

#include <chrono>
#include <cmath>
#include <cstdio>
#include <thread>

#include "layer0_common/velocity.hpp"

namespace mission {

namespace {

// ── goto 闭环参数 ────────────────────────────────────────────────────────
// 照抄 dog_nav_demo/dog_nav_demo/goto_goal.py 的实测值 —— 那套已经在真机上跑通
// （README 场景 B），不要凭感觉调，要调也在现场对着实测改。
constexpr double kGotoKpXy        = 0.55;
constexpr double kGotoKpYaw       = 0.75;
constexpr double kGotoMaxVx       = 0.25;   // m/s
constexpr double kGotoMaxVy       = 0.18;   // m/s
constexpr double kGotoMaxYawRate  = 0.45;   // rad/s
constexpr double kGotoTolXy       = 0.20;   // m，到位判据
constexpr double kGotoTolYaw      = 0.15;   // rad
constexpr double kPoseTimeoutS = 1.0;   // 位姿多久没更新就停
constexpr int    kStopFrames  = 5;      // 到位后连发几帧零速再 vel_stop
constexpr double kControlHz   = 20.0;

// 不用 M_PI：glibc 的扩展，`-std=c++17` 下可能不给（flight_controller.cpp 用的是
// gnu++17 才没事，这里不想依赖那个）。
constexpr double kTwoPi = 6.283185307179586476925286766559;

double clamp(double v, double lo, double hi) { return v < lo ? lo : (v > hi ? hi : v); }

/** 角度归一化到 (-π, π]，与 flight_controller.cpp 的 wrap_pi 一致。 */
double wrap_pi(double a) {
    return std::remainder(a, kTwoPi);
}

double seconds_since(const std::chrono::steady_clock::time_point& t0) {
    return std::chrono::duration<double>(std::chrono::steady_clock::now() - t0).count();
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

    const std::size_t total = plan.steps.size();
    RCLCPP_INFO(logger_, "[任务] 开始「%s」：%zu 步，确认方式=%s",
                plan.name.c_str(), total,
                plan.confirm == ConfirmMode::Each ? "逐步确认（危险步骤前暂停）"
                                                  : "一次授权（全程不暂停）");

    std::size_t completed = 0;
    bool failed = false;

    for (std::size_t i = 0; i < total; ++i) {
        if (abort_) break;
        const MissionStep& st = plan.steps[i];
        const std::string label = step_label(st);

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
    if (failed) {
        go_down_and_report(last_error_);
        push("failed", -1, total, "", last_error_, "", false);
        RCLCPP_ERROR(logger_, "[任务] 「%s」失败于 %zu/%zu 步：%s",
                     plan.name.c_str(), completed + 1, total, last_error_.c_str());
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
        case StepType::Goto:       out = do_goto(st);       break;
        case StepType::Wait:       out = do_wait(st);       break;
        case StepType::GetDown:    out = do_getdown(st);    break;
    }

    // 失败原因补上"第几步、什么类型" —— 网页上只显示这一行，必须能直接定位。
    if (out == Outcome::Failed && !abort_ && !last_error_.empty()) {
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
                      : "站立自检未通过（电机零位或 IMU 不达标）—— 不可起立";
    return Outcome::Failed;
}

DogPlanExecutor::Outcome DogPlanExecutor::do_getup(const MissionStep& st) {
    const double settle = st.settle_s >= 0.0 ? st.settle_s : hal_.get_stand_settle_s();
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

        if (seconds_since(t0) >= st.duration_s) break;

        Velocity v(static_cast<float>(st.vx), static_cast<float>(st.vy), 0.0f,
                   static_cast<float>(st.wz));
        fc_.fly_by_velocity(v);
        rate.sleep();
    }

    stop_motion();
    return Outcome::Ok;
}

DogPlanExecutor::Outcome DogPlanExecutor::do_goto(const MissionStep& st) {
    RCLCPP_INFO(logger_, "[任务] 到点 (%.2f, %.2f) 航向 %.2f rad，总超时 %.1fs",
                st.x, st.y, st.yaw, st.goto_timeout_s);

    const auto t0 = std::chrono::steady_clock::now();
    auto last_log = t0;
    rclcpp::Rate rate(kControlHz);
    int arrived_frames = 0;

    while (rclcpp::ok()) {
        if (abort_) {
            last_error_ = "操作员急停";   // 停速由统一处置负责
            return Outcome::Failed;
        }
        if (hal_.is_gamepad_override()) {
            last_error_ = "手柄抢走了控制权（小脑行为：抢走后所有指令被忽略）—— 先放开手柄";
            return Outcome::Failed;
        }
        if (!pose_is_fresh(kPoseTimeoutS)) {
            last_error_ = "位姿超时（超过 " + std::to_string(kPoseTimeoutS) +
                          "s 没更新）—— 已停速保持站立，需人工处置";
            return Outcome::Failed;
        }
        const std::string fsm = hal_.get_current_fsm_state();
        if (fsm != "RLFSMStateRLLocomotion") {
            last_error_ = "狗不在 RL 运动模式（当前 " + fsm + "）—— 已停速";
            return Outcome::Failed;
        }

        const DroneState s = hal_.get_state();
        const double dx   = st.x - s.x;
        const double dy   = st.y - s.y;
        const double dist = std::hypot(dx, dy);
        const double yaw_err = wrap_pi(st.yaw - s.yaw);

        if (dist <= kGotoTolXy && std::abs(yaw_err) <= kGotoTolYaw) {
            // 到位：连发几帧零速（桥自己 0.5s 也会归零，但别等那半秒）
            Velocity zero(0.0f, 0.0f, 0.0f, 0.0f);
            hal_.publish_velocity(zero);
            if (++arrived_frames >= kStopFrames) {
                RCLCPP_INFO(logger_, "[任务] 到点：距离 %.3f m，航向误差 %.3f rad",
                            dist, yaw_err);
                stop_motion();
                return Outcome::Ok;
            }
        } else {
            arrived_frames = 0;
            // 世界系误差 → 机体系（与狗端里程计的旋转互逆）
            const double c  = std::cos(s.yaw);
            const double sn = std::sin(s.yaw);
            const double err_x =  c * dx + sn * dy;
            const double err_y = -sn * dx + c * dy;

            Velocity v(static_cast<float>(clamp(kGotoKpXy * err_x, -kGotoMaxVx, kGotoMaxVx)),
                       static_cast<float>(clamp(kGotoKpXy * err_y, -kGotoMaxVy, kGotoMaxVy)),
                       0.0f,
                       static_cast<float>(clamp(kGotoKpYaw * yaw_err, -kGotoMaxYawRate, kGotoMaxYawRate)));
            fc_.fly_by_velocity(v);

            // 1 Hz 打一次距离/航向误差：现场查"走歪了"只能靠这个
            if (seconds_since(last_log) >= 1.0) {
                last_log = std::chrono::steady_clock::now();
                RCLCPP_INFO(logger_,
                            "[任务] goto: 现在 (%.2f, %.2f, %.2f) → 目标 (%.2f, %.2f, %.2f)，"
                            "距离 %.2f m，航向误差 %.2f rad，已走 %.1fs",
                            s.x, s.y, s.yaw, st.x, st.y, st.yaw, dist, yaw_err,
                            seconds_since(t0));
            }
        }

        // 超时判在到位之后：最后一拍刚好到位时应该算成功
        if (seconds_since(t0) > st.goto_timeout_s) {
            last_error_ = "在规定时间内没走到目标点（剩余距离 " + std::to_string(dist) +
                          " m）—— 已停速保持站立，需人工处置";
            return Outcome::Failed;
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

void DogPlanExecutor::stop_motion() {
    publish_zero_velocity();
    // vel_stop：只归零速度、**保持站立**（不是 passive）。失败只警告 ——
    // 多数情况是桥断了，那时发什么都白搭，但速度已经归零。
    if (!hal_.transition_to("vel_stop", "", "", 0.0)) {
        RCLCPP_WARN(logger_, "[任务] vel_stop 未确认（桥断了？）—— 速度已归零");
    }
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
    if (reset_step_clock) s.step_started_at = std::chrono::steady_clock::now();
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
            std::snprintf(buf, sizeof(buf), "到点 (%.2f, %.2f, %.2f)", st.x, st.y, st.yaw);
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
                          "即将闭环前往 (%.2f, %.2f) 航向 %.2f rad。"
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
