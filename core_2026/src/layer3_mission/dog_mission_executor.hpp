#pragma once

#include "layer3_mission/mission_executor.hpp"
#include "layer1_hal/robot_dog_hal.hpp"

/**
 * @brief 机器狗任务执行器
 *
 * 继承 MissionExecutor，覆写状态方法。与旧版的区别：
 *   旧版：发完命令 sleep 固定秒数，假定狗做到了
 *   本版：发完命令**等控制器回报的终态状态码**，确认做到了才往下走；
 *         任一步失败就发 passive 卸力、进 FAULT、中止任务
 *
 *   TAKEOFF → 发 locomotion 进 RL 运动模式，等 DONE
 *   HOVER   → 前进（时长由 forward_duration_s 参数控制，设为 0 则跳过）
 *   LAND    → 问回车 → 发 getdown 平滑趴下，等 DONE
 */
class DogMissionExecutor : public MissionExecutor {
public:
    DogMissionExecutor(FlightController& fc,
                       IStateProvider&   state,
                       IVisionProvider&  vision,
                       IDvsAvoidProvider& dvs,
                       ICommandPublisher& cmd,
                       rclcpp::Logger    logger,
                       RobotDogHAL&      dog_hal,
                       float             default_altitude = 0.0f);

private:
    void on_takeoff() override;
    void on_hover() override;
    void on_land() override;

    /**
     * 失败处置：发 passive 卸力 → 等确认 → 进 FAULT（run() 会据此退出）。
     * 中止时狗可能处于任何姿态，保持力矩反而是危险的，所以选择卸力。
     */
    void fail_and_disarm(const std::string& reason);

    RobotDogHAL& dog_hal_;
};
