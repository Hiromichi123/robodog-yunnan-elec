#include "layer3_mission/dog_mission_executor.hpp"
#include <thread>
#include <chrono>
#include <cmath>

using namespace fly_to_target_args;

DogMissionExecutor::DogMissionExecutor(
    FlightController& fc,
    IStateProvider&   state,
    IVisionProvider&  vision,
    IDvsAvoidProvider& dvs,
    ICommandPublisher& cmd,
    rclcpp::Logger    logger,
    RobotDogHAL&      dog_hal,
    float             default_altitude)
    : MissionExecutor(fc, state, vision, dvs, cmd, logger, default_altitude)
    , dog_hal_(dog_hal)
{}

void DogMissionExecutor::fail_and_disarm(const std::string& reason) {
    RCLCPP_ERROR(logger_, "[FAULT] %s —— 发 passive 卸力并中止任务", reason.c_str());
    // 安全路径：require_state 留空，**绝不能被前置判断挡住**。
    // 状态码仍然确认（expect_state=RLFSMStatePassive），确认不了也照样进 FAULT。
    if (!dog_hal_.transition_to("passive", "RLFSMStatePassive", "",
                                dog_hal_.get_transition_settle_s())) {
        RCLCPP_ERROR(logger_,
            "[FAULT] passive 也没等到确认 —— 狗可能已经卸力，或链路已断");
    }
    current_state_ = State::FAULT;
}

void DogMissionExecutor::on_takeoff() {
    // getup 已经在预检里发过、并且等到了 DONE + 状态码确认 + 稳定延迟
    // （见 dog_system.cpp）。这里进 RL 模式，同样走四道把关：
    //   前置：当前必须真的站着（RLFSMStateGetUp）
    //   确认：FSM 状态码真的变成 RLFSMStateRLLocomotion（"同时状态码改变"）
    //   延迟：默认 1s（进 RL 也是状态切换，但不需要起立那样的长稳定期）
    if (!dog_hal_.wait_for_enter("已站起。按回车进入 RL 运动模式")) {
        fail_and_disarm("操作员放弃（进入 RL 前）");
        return;
    }

    RCLCPP_INFO(logger_, "[TAKEOFF] 进入 RL 运动模式...");
    if (!dog_hal_.transition_to("locomotion", "RLFSMStateRLLocomotion",
                                "RLFSMStateGetUp",
                                dog_hal_.get_transition_settle_s())) {
        fail_and_disarm("进入 RL 运动模式失败");
        return;
    }

    // 不再发 nav_on（2026-09-28 移除）：
    //   nav_on 只是把 navigation_mode 打开，让 cmd_vel 走 obs.commands 的
    //   cmd_vel 分支；但 CmdvelCallback 本来就同时把 cmd_vel 写进 control.x/y/yaw，
    //   关着 navigation_mode 一样能驱动。它唯一多出的那层「小脑侧 cmd_vel 超时归零」
    //   保护，桥自己的 cmd_vel_timeout_s=0.5 看门狗已经在 ROS 层覆盖了。
    //   而 getdown/passive 命令本身就会清 control.*，所以也不需要额外的清速度步骤。

    const auto s = state_.get_state();
    hover_anchor_x_   = s.x;
    hover_anchor_y_   = s.y;
    hover_anchor_yaw_ = s.yaw;
    hover_target_     = Target(hover_anchor_x_, hover_anchor_y_, 0.0f, hover_anchor_yaw_);
    hover_start_time_ = steady_clock_.now();
    RCLCPP_INFO(logger_, "[TAKEOFF] 就绪，切换 HOVER");
    current_state_ = State::HOVER;
}

void DogMissionExecutor::on_hover() {
    const double dur = dog_hal_.get_forward_duration_s();
    const double vx  = dog_hal_.get_forward_vx();

    if (dur > 0.0) {
        // 移动是最危险的一步，闸门放在这儿（照 ~/dog_step_test.py 的移动步）
        char gate_msg[160];
        std::snprintf(gate_msg, sizeof(gate_msg),
                      "即将前进 vx=%.2f m/s × %.1fs (≈%.0fcm)。"
                      "确认前方空旷后按回车",
                      vx, dur, vx * dur * 100.0);
        if (!dog_hal_.wait_for_enter(gate_msg)) {
            fail_and_disarm("操作员放弃（前进前）");
            return;
        }
        RCLCPP_INFO(logger_, "[HOVER] 前进 vx=%.2f m/s × %.1fs ≈ %.2f m",
                    vx, dur, vx * dur);
        Velocity fwd(static_cast<float>(vx), 0.0f, 0.0f, 0.0f);
        fc_.fly_by_vel_duration(fwd, static_cast<float>(dur));
        RCLCPP_INFO(logger_, "[HOVER] 前进完成");
    } else {
        // forward_duration_s=0：用于"只起立→进RL→趴下"的验证，不产生任何位移
        RCLCPP_INFO(logger_, "[HOVER] 前进已禁用（forward_duration_s=0），原地保持");
    }

    RCLCPP_INFO(logger_, "[HOVER] 切换 LAND");
    current_state_ = State::LAND;
}

void DogMissionExecutor::on_land() {
    // 这是唯一一道「拒绝 = 什么都不做」的闸门：任务已跑完，
    // 操作员若不想趴下，就保持站立姿态，而不是自作主张卸力。
    if (!dog_hal_.wait_for_enter(
            "按回车趴下（getdown 平滑趴下；按 q = 保持站立姿态，需人工看护）")) {
        RCLCPP_WARN(logger_,
            "[LAND] 操作员放弃趴下 —— 狗保持站立，**需人工看护/处置**");
        current_state_ = State::DONE;
        return;
    }

    // 用 getdown 而不是 passive：
    //   passive → P 键 → 直接跳 Passive，kp=0 卸力，狗靠重力砸下去（急停语义）
    //   getdown → 数字9 → GetDown，2s 平滑插值趴下（正常趴下语义）
    // 任务正常收尾要的是后者。急停路径（fail_and_disarm / 预检失败）仍用 passive。
    //
    // 目标状态写两个：RLFSMStateGetDown 是过渡态，动画跑完会自动转 Passive，
    // 只等前者会擦肩而过、误报超时（协议文档 §6）。
    RCLCPP_INFO(logger_, "[LAND] 发送 getdown（平滑趴下）...");
    if (!dog_hal_.transition_to("getdown",
                                "RLFSMStateGetDown|RLFSMStatePassive", "",
                                dog_hal_.get_transition_settle_s())) {
        // 这里不转 FAULT：任务本身已经跑完，趴下没确认多半是狗已经卸力。
        // 但仍然要说清楚，别让人以为一切正常。
        RCLCPP_WARN(logger_, "[LAND] 趴下未确认完成（狗可能已卸力，或链路已断）");
    } else {
        RCLCPP_INFO(logger_, "[LAND] 趴下完成");
    }
    current_state_ = State::DONE;
}
