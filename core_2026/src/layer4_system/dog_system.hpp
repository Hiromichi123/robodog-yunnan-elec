#pragma once

#include <memory>
#include <thread>
#include <rclcpp/rclcpp.hpp>

#include "layer1_hal/robot_dog_hal.hpp"
#include "layer2_control/flight_controller.hpp"
#include "layer3_mission/dog_mission_executor.hpp"

/**
 * @brief 机器狗系统编排层
 *
 * 参考 DroneSystem，适配四足机器人:
 * - pre_flight: 站起 (getup FSM)
 * - 使用 FlightController (地面 PID 参数)
 * - MissionExecutor (不变！通过接口适配)
 */
class DogSystem {
public:
    DogSystem();
    ~DogSystem();

    void run();

private:
    void pre_flight_checks();

    std::shared_ptr<RobotDogHAL>        hal_;
    std::unique_ptr<FlightController>   fc_;
    std::unique_ptr<MissionExecutor>    mission_;
    std::shared_ptr<std::thread>        spin_thread_;
};
