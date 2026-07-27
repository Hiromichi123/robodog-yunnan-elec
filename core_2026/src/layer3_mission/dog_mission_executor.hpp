#pragma once

#include "layer3_mission/mission_executor.hpp"
#include "layer1_hal/robot_dog_hal.hpp"

/**
 * @brief 机器狗任务执行器
 *
 * 继承 MissionExecutor，覆写状态方法：
 *   TAKEOFF → 发送 getup FSM 命令让狗站起
 *   LAND    → 发送 passive FSM 命令让狗趴下
 *   HOVER   → 保持不动（复用基类）
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

    RobotDogHAL& dog_hal_;
};
