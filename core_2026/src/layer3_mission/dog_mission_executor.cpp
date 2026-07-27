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

void DogMissionExecutor::on_takeoff() {
    RCLCPP_INFO(logger_, "[TAKEOFF] 发送站立命令...");
    dog_hal_.request_fsm_transition("getup");

    // 等待站立动画完成
    std::this_thread::sleep_for(std::chrono::seconds(4));

    // 进入 RL 运动模式 (LB+DPadUp)
    RCLCPP_INFO(logger_, "[TAKEOFF] 进入运动模式...");
    dog_hal_.request_fsm_transition("locomotion");
    std::this_thread::sleep_for(std::chrono::seconds(1));

    RCLCPP_INFO(logger_, "[TAKEOFF] 就绪，切换 HOVER");
    const auto s = state_.get_state();
    hover_anchor_x_ = s.x;
    hover_anchor_y_ = s.y;
    hover_anchor_yaw_ = s.yaw;
    hover_target_ = Target(hover_anchor_x_, hover_anchor_y_, 0.0f, hover_anchor_yaw_);
    hover_start_time_ = steady_clock_.now();
    current_state_ = State::HOVER;
}

void DogMissionExecutor::on_hover() {
    // 前进: vx=0.3m/s, 持续3.5s ≈ 1m
    RCLCPP_INFO(logger_, "[HOVER] 前进1m (vx=0.3m/s, 3.5s)...");
    Velocity fwd(0.3f, 0.0f, 0.0f, 0.0f);
    fc_.fly_by_vel_duration(fwd, 3.5f);

    RCLCPP_INFO(logger_, "[HOVER] 前进完成，切换 LAND");
    current_state_ = State::LAND;
}

void DogMissionExecutor::on_land() {
    RCLCPP_INFO(logger_, "[LAND] 发送趴下命令...");
    dog_hal_.request_fsm_transition("passive");

    std::this_thread::sleep_for(std::chrono::seconds(2));

    RCLCPP_INFO(logger_, "[LAND] 趴下完成");
    current_state_ = State::DONE;
}
