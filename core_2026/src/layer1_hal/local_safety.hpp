#pragma once

#include <array>
#include <chrono>
#include <memory>
#include <mutex>
#include <string>
#include <rclcpp/rclcpp.hpp>
#include <ros2_tools/msg/local_safety_map.hpp>
#include <std_msgs/msg/string.hpp>
#include "layer2_control/local_navigation.hpp"

// 感知回调只替换不可变快照，控制线程不持锁遍历栅格。
class LocalSafety {
public:
    struct Snapshot {
        std::shared_ptr<const local_nav::Grid> grid;
        std::shared_ptr<const local_nav::Grid> observed_grid;
        bool valid{false};
        std::string reason{"未收到安全地图"};
        std::string session_id;
        std::uint64_t sequence{0};
        std::size_t startup_unknown_cells{0};
        std::size_t exploration_unknown_cells{0};
    };
    explicit LocalSafety(rclcpp::Node& node);
    Snapshot snapshot() const;
    void prepare_startup(const local_nav::Pose& pose, bool pose_fresh);
    bool check_recovery_reverse(const local_nav::Pose& pose,bool fresh,double vx,double wz);
    bool enforced() const { return mode_ == "enforce"; }
    const std::string& mode() const { return mode_; }
    const local_nav::Config& config() const { return config_; }
    bool check(const local_nav::Pose& pose, bool pose_fresh, double vx, double wz);
    bool blocked() const;
    std::string reason() const;

private:
    void receive(const ros2_tools::msg::LocalSafetyMap& msg);
    void origin(const std_msgs::msg::String& msg);
    void publish_status();
    rclcpp::Node& node_;
    std::string mode_;
    std::string config_revision_;
    local_nav::Config config_;
    double timeout_s_{0.5};
    mutable std::mutex mutex_;
    Snapshot latest_;
    std::chrono::steady_clock::time_point received_at_{};
    std::chrono::steady_clock::time_point origin_received_at_{};
    double source_age_s_{0.0};
    std::int64_t stamp_ns_{0};
    std::string origin_session_;
    std::array<double, 4> origin_values_{};
    bool origin_valid_{false};
    bool epoch_changed_{false};
    bool reverse_gate_active_{false};
    local_nav::Pose reverse_gate_start_;
    std::chrono::steady_clock::time_point reverse_gate_time_{};
    bool unknown_as_free_{false};
    double unknown_exploration_range_{5.0};
    bool startup_unknown_enabled_{true};
    bool startup_fixed_{false};
    bool startup_retired_{false};
    local_nav::Pose startup_pose_;
    bool blocked_{false};
    std::string reason_;
    rclcpp::Subscription<ros2_tools::msg::LocalSafetyMap>::SharedPtr map_sub_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr origin_sub_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr status_pub_;
    rclcpp::TimerBase::SharedPtr status_timer_;
};
