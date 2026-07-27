// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_tools:msg/LidarPose.idl
// generated code does not contain a copyright notice

#ifndef ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__BUILDER_HPP_
#define ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_tools/msg/detail/lidar_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_tools
{

namespace msg
{

namespace builder
{

class Init_LidarPose_yaw
{
public:
  explicit Init_LidarPose_yaw(::ros2_tools::msg::LidarPose & msg)
  : msg_(msg)
  {}
  ::ros2_tools::msg::LidarPose yaw(::ros2_tools::msg::LidarPose::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_tools::msg::LidarPose msg_;
};

class Init_LidarPose_pitch
{
public:
  explicit Init_LidarPose_pitch(::ros2_tools::msg::LidarPose & msg)
  : msg_(msg)
  {}
  Init_LidarPose_yaw pitch(::ros2_tools::msg::LidarPose::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_LidarPose_yaw(msg_);
  }

private:
  ::ros2_tools::msg::LidarPose msg_;
};

class Init_LidarPose_roll
{
public:
  explicit Init_LidarPose_roll(::ros2_tools::msg::LidarPose & msg)
  : msg_(msg)
  {}
  Init_LidarPose_pitch roll(::ros2_tools::msg::LidarPose::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_LidarPose_pitch(msg_);
  }

private:
  ::ros2_tools::msg::LidarPose msg_;
};

class Init_LidarPose_z
{
public:
  explicit Init_LidarPose_z(::ros2_tools::msg::LidarPose & msg)
  : msg_(msg)
  {}
  Init_LidarPose_roll z(::ros2_tools::msg::LidarPose::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_LidarPose_roll(msg_);
  }

private:
  ::ros2_tools::msg::LidarPose msg_;
};

class Init_LidarPose_y
{
public:
  explicit Init_LidarPose_y(::ros2_tools::msg::LidarPose & msg)
  : msg_(msg)
  {}
  Init_LidarPose_z y(::ros2_tools::msg::LidarPose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_LidarPose_z(msg_);
  }

private:
  ::ros2_tools::msg::LidarPose msg_;
};

class Init_LidarPose_x
{
public:
  Init_LidarPose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LidarPose_y x(::ros2_tools::msg::LidarPose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_LidarPose_y(msg_);
  }

private:
  ::ros2_tools::msg::LidarPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_tools::msg::LidarPose>()
{
  return ros2_tools::msg::builder::Init_LidarPose_x();
}

}  // namespace ros2_tools

#endif  // ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__BUILDER_HPP_
