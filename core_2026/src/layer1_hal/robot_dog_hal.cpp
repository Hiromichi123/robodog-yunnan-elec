#include "layer1_hal/robot_dog_hal.hpp"
#include "layer0_common/target.hpp"
#include "layer0_common/velocity.hpp"
#include <algorithm>

RobotDogHAL::RobotDogHAL() : Node("robot_dog_hal_node") {
    // 发布速度命令到 rl_real_xkai
    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>(
        "/cmd_vel", 10);

    // 发布 FSM 状态切换
    fsm_command_pub_ = this->create_publisher<std_msgs::msg::String>(
        "/dog/fsm_command", 10);

    // 订阅 LiDAR 里程计（复用已有 node）
    lidar_sub_ = this->create_subscription<ros2_tools::msg::LidarPose>(
        "lidar_data", 10,
        [this](const ros2_tools::msg::LidarPose::SharedPtr msg) {
            RobotDogHAL::lidar_cb(msg);
        });

    // 订阅机器狗 FSM 状态反馈
    dog_state_sub_ = this->create_subscription<std_msgs::msg::String>(
        "/dog/state", 10,
        [this](const std_msgs::msg::String::SharedPtr msg) {
            RobotDogHAL::dog_state_cb(msg);
        });

    RCLCPP_INFO(this->get_logger(), "[RobotDogHAL] 硬件抽象层初始化完成");
}

// ===== IStateProvider =====
DroneState RobotDogHAL::get_state() const {
    std::lock_guard<std::mutex> lock(state_mutex_);
    return state_;
}

bool RobotDogHAL::has_state() const {
    std::lock_guard<std::mutex> lock(state_mutex_);
    return has_state_;
}

// ===== ICommandPublisher =====
void RobotDogHAL::publish_velocity(Velocity& velocity) {
    auto msg = geometry_msgs::msg::Twist();
    msg.linear.x  = velocity.get_vx();
    msg.linear.y  = velocity.get_vy();
    msg.angular.z = velocity.get_vyaw();
    // vz/vpitch/vroll ignored for ground robot
    cmd_vel_pub_->publish(msg);
}

void RobotDogHAL::publish_position(Target& target) {
    // 地面机器人不支持绝对位置设点，用 P 控制转为速度
    DroneState s = get_state();
    float vx = 0.3f * (target.get_x() - s.x);
    float vy = 0.3f * (target.get_y() - s.y);
    vx = std::clamp(vx, -0.3f, 0.3f);
    vy = std::clamp(vy, -0.3f, 0.3f);
    Velocity vel(vx, vy, 0.0f, 0.0f);
    publish_velocity(vel);
}

// ===== IVisionProvider (空实现) =====
messages::msg::Vision RobotDogHAL::get_vision() const {
    return empty_vision_;
}

bool RobotDogHAL::has_vision() const {
    return false;
}

// ===== IDvsAvoidProvider (空实现) =====
geometry_msgs::msg::Twist RobotDogHAL::get_dvs_avoid_cmd() const {
    return empty_dvs_cmd_;
}

bool RobotDogHAL::has_recent_dvs_avoid(double /*max_age_sec*/) const {
    return false;
}

int64_t RobotDogHAL::get_last_dvs_detect_time_ns() const {
    return 0;
}

// ===== 机器狗特有 =====
void RobotDogHAL::request_fsm_transition(const std::string& fsm_state) {
    auto msg = std_msgs::msg::String();
    msg.data = fsm_state;
    fsm_command_pub_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "[RobotDogHAL] FSM → %s", fsm_state.c_str());
}

void RobotDogHAL::set_navigation_mode(bool enable) {
    request_fsm_transition(enable ? "locomotion" : "passive");
}

// ===== 回调 =====
void RobotDogHAL::lidar_cb(const ros2_tools::msg::LidarPose::SharedPtr msg) {
    std::lock_guard<std::mutex> lock(state_mutex_);
    state_.x   = msg->x;
    state_.y   = msg->y;
    state_.z   = msg->z;
    state_.yaw = msg->yaw;
    state_.roll  = msg->roll;
    state_.pitch = msg->pitch;
    has_state_ = true;
}

void RobotDogHAL::dog_state_cb(const std_msgs::msg::String::SharedPtr msg) {
    std::lock_guard<std::mutex> lock(state_mutex_);
    current_fsm_state_ = msg->data;
}

std::string RobotDogHAL::get_current_fsm_state() const {
    std::lock_guard<std::mutex> lock(state_mutex_);
    return current_fsm_state_;
}

bool RobotDogHAL::wait_for_fsm_state(const std::string& target, double timeout_sec) {
    auto start = this->now();
    rclcpp::Rate rate(10);
    while (rclcpp::ok()) {
        if (get_current_fsm_state() == target) {
            return true;
        }
        if ((this->now() - start).seconds() > timeout_sec) {
            RCLCPP_WARN(this->get_logger(),
                "[RobotDogHAL] wait_for_fsm_state('%s') 超时(%.1fs), 当前='%s'",
                target.c_str(), timeout_sec, get_current_fsm_state().c_str());
            return false;
        }
        rate.sleep();
    }
    return false;
}
