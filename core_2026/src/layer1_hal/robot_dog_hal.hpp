#pragma once

#include <mutex>
#include <memory>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/twist_stamped.hpp>
#include <std_msgs/msg/string.hpp>
#include <ros2_tools/msg/lidar_pose.hpp>

#include "layer1_hal/i_state_provider.hpp"
#include "layer1_hal/i_command_publisher.hpp"
#include "layer1_hal/i_vision_provider.hpp"
#include "layer1_hal/i_dvs_avoid_provider.hpp"

/**
 * @brief 机器狗硬件抽象层
 *
 * 实现与 DroneHAL 相同的四个接口，适配 XKAI 四足机器人。
 *
 * 关键映射:
 *   publish_velocity(Velocity) → Twist on /cmd_vel
 *   publish_position(Target)   → 内部 P 控制器转速度
 *   get_state()                → DroneState from lidar_data
 *   FSM 控制                    → /dog/fsm_command
 */
class RobotDogHAL
    : public rclcpp::Node
    , public IStateProvider
    , public ICommandPublisher
    , public IVisionProvider
    , public IDvsAvoidProvider
{
public:
    explicit RobotDogHAL();

    // IStateProvider
    [[nodiscard]] DroneState get_state() const override;
    [[nodiscard]] bool       has_state() const override;

    // ICommandPublisher
    void publish_position(Target& target) override;
    void publish_velocity(Velocity& velocity) override;

    // IVisionProvider (空实现)
    [[nodiscard]] messages::msg::Vision get_vision() const override;
    [[nodiscard]] bool                   has_vision() const override;

    // IDvsAvoidProvider (空实现)
    [[nodiscard]] geometry_msgs::msg::Twist get_dvs_avoid_cmd() const override;
    [[nodiscard]] bool has_recent_dvs_avoid(double max_age_sec) const override;
    [[nodiscard]] int64_t get_last_dvs_detect_time_ns() const override;

    // === 机器狗特有接口 ===
    void request_fsm_transition(const std::string& fsm_state);
    void set_navigation_mode(bool enable);
    [[nodiscard]] std::string get_current_fsm_state() const;
    [[nodiscard]] bool wait_for_fsm_state(const std::string& target, double timeout_sec);

private:
    void lidar_cb(const ros2_tools::msg::LidarPose::SharedPtr msg);
    void dog_state_cb(const std_msgs::msg::String::SharedPtr msg);

    // 发布器
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr  cmd_vel_pub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr       fsm_command_pub_;

    // 订阅器
    rclcpp::Subscription<ros2_tools::msg::LidarPose>::SharedPtr lidar_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr      dog_state_sub_;

    // 状态
    mutable std::mutex state_mutex_;
    DroneState         state_{};
    bool               has_state_{false};
    std::string        current_fsm_state_{"Unknown"};

    // 空 vision / dvs 返回
    messages::msg::Vision empty_vision_{};
    geometry_msgs::msg::Twist empty_dvs_cmd_{};
};
