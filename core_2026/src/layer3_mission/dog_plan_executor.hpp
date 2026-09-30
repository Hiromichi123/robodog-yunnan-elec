#pragma once

#include <atomic>
#include <cstddef>
#include <string>

#include <rclcpp/rclcpp.hpp>

#include "layer1_hal/robot_dog_hal.hpp"
#include "layer2_control/flight_controller.hpp"
#include "layer3_mission/mission_channel.hpp"
#include "layer3_mission/mission_plan.hpp"

namespace mission {

/**
 * @brief 按网页下发的任务书，一步步执行。
 *
 * **为什么与 MissionExecutor 并列，而不是改它**：`MissionExecutor` 那套
 * TAKEOFF→HOVER→LAND 是同工作区 drone 在用的（`main.cpp` → `DroneSystem`），
 * 它的"高度/悬停"语义在狗的 FSM 世界里根本不存在。改造它 = 拿无人机的回归风险
 * 换零收益。所以这里只**复用**：HAL 的状态切换原语 + FlightController 的单次
 * 速度发布，自己走一条线性的步骤循环。
 *
 * 分工：
 *   解析      → mission_plan（纯逻辑，可离线自测）
 *   收发/心跳 → mission_channel（话题层，不掺语义）
 *   执行      → 本文件
 *
 * 关键实现约束：
 *   - 每步都在 20 Hz 自循环里跑，**不用** `FlightController::fly_by_vel_duration`
 *     —— 那个函数一进去就阻塞到时长结束、中途打不断，急停要等好几秒才生效。
 *   - 每个检查点都看 `abort_`（spin 线程置位）和 `rclcpp::ok()`。
 *   - 失败/中止一律 `safe_go_down()` 回趴下，**没有 passive**。
 */
class DogPlanExecutor {
public:
    DogPlanExecutor(RobotDogHAL&       hal,
                    FlightController&  fc,
                    DogMissionChannel& channel,
                    rclcpp::Logger     logger);

    /** 跑完一整份任务（阻塞到 done / failed / aborted 之一）。 */
    void execute(const MissionPlan& plan);

    /** 由 spin 线程的急停钩子调用：置位后主线程在下一个检查点退出。 */
    void request_abort();

private:
    enum class Outcome { Ok, Skipped, Failed };

    /** 确认闸门的三种结局。 */
    enum class Gate { Continue, AbortMission, SkipStep };

    Outcome dispatch(const MissionStep& st, std::size_t index);

    Outcome do_check_stand(const MissionStep& st);
    Outcome do_getup(const MissionStep& st);
    Outcome do_locomotion(const MissionStep& st);
    Outcome do_move(const MissionStep& st);
    Outcome do_goto(const MissionStep& st);
    Outcome do_wait(const MissionStep& st);
    Outcome do_getdown(const MissionStep& st);

    /** 危险步骤前的人工闸门（终端回车那道闸门的网页版）。 */
    Gate confirm_gate(StepType type, const std::string& prompt,
                      std::size_t index, std::size_t total);

    /** 只压零速：连发几帧零速 Twist，不发任何命令。紧急停下来的第一步。 */
    void publish_zero_velocity();
    /**
     * 动作正常收尾：压零速 + 发 vel_stop（只归零速度、保持站立）。
     * **失败/中止路径不要用它** —— 那边紧接着就 getdown 回趴下了，
     * 再等一次 vel_stop 的确认纯属白等（实测多花 0.6s，急停时这半秒很值钱）。
     */
    void stop_motion();
    /** 位姿够不够新鲜（闭环控制的前提）。 */
    [[nodiscard]] bool pose_is_fresh(double max_age_s) const;
    /** 失败/中止的统一处置：停速 + 回趴下，并如实上报结果。 */
    void go_down_and_report(const std::string& reason);
    /** 丢掉积压的指令 —— 上一轮任务残留的 confirm 不能批准下一轮的闸门。 */
    void drain_cmds();

    /** 上报状态。reset_step_clock=true 时把"本步起始时刻"重置为现在。 */
    void push(const std::string& phase, std::size_t index, std::size_t total,
              const std::string& type, const std::string& msg,
              const std::string& prompt, bool reset_step_clock);

    [[nodiscard]] std::string step_label(const MissionStep& st) const;
    [[nodiscard]] std::string gate_prompt(const MissionStep& st) const;

    RobotDogHAL&       hal_;
    FlightController&  fc_;
    DogMissionChannel& channel_;
    rclcpp::Logger     logger_;

    std::atomic<bool> abort_{false};   // spin 线程写，主线程读
    std::string       last_error_;     // 主线程写读，失败原因（已带"第N步"前缀）
    std::string       current_name_;   // 当前任务名，随每帧状态带给网页
};

}  // namespace mission
