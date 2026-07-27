// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/PlatformTarget.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__PLATFORM_TARGET__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__PLATFORM_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/platform_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_PlatformTarget_yaw_rate_dps
{
public:
  explicit Init_PlatformTarget_yaw_rate_dps(::messages::msg::PlatformTarget & msg)
  : msg_(msg)
  {}
  ::messages::msg::PlatformTarget yaw_rate_dps(::messages::msg::PlatformTarget::_yaw_rate_dps_type arg)
  {
    msg_.yaw_rate_dps = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

class Init_PlatformTarget_curvature
{
public:
  explicit Init_PlatformTarget_curvature(::messages::msg::PlatformTarget & msg)
  : msg_(msg)
  {}
  Init_PlatformTarget_yaw_rate_dps curvature(::messages::msg::PlatformTarget::_curvature_type arg)
  {
    msg_.curvature = std::move(arg);
    return Init_PlatformTarget_yaw_rate_dps(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

class Init_PlatformTarget_speed_mps
{
public:
  explicit Init_PlatformTarget_speed_mps(::messages::msg::PlatformTarget & msg)
  : msg_(msg)
  {}
  Init_PlatformTarget_curvature speed_mps(::messages::msg::PlatformTarget::_speed_mps_type arg)
  {
    msg_.speed_mps = std::move(arg);
    return Init_PlatformTarget_curvature(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

class Init_PlatformTarget_vz_mps
{
public:
  explicit Init_PlatformTarget_vz_mps(::messages::msg::PlatformTarget & msg)
  : msg_(msg)
  {}
  Init_PlatformTarget_speed_mps vz_mps(::messages::msg::PlatformTarget::_vz_mps_type arg)
  {
    msg_.vz_mps = std::move(arg);
    return Init_PlatformTarget_speed_mps(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

class Init_PlatformTarget_vy_mps
{
public:
  explicit Init_PlatformTarget_vy_mps(::messages::msg::PlatformTarget & msg)
  : msg_(msg)
  {}
  Init_PlatformTarget_vz_mps vy_mps(::messages::msg::PlatformTarget::_vy_mps_type arg)
  {
    msg_.vy_mps = std::move(arg);
    return Init_PlatformTarget_vz_mps(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

class Init_PlatformTarget_vx_mps
{
public:
  explicit Init_PlatformTarget_vx_mps(::messages::msg::PlatformTarget & msg)
  : msg_(msg)
  {}
  Init_PlatformTarget_vy_mps vx_mps(::messages::msg::PlatformTarget::_vx_mps_type arg)
  {
    msg_.vx_mps = std::move(arg);
    return Init_PlatformTarget_vy_mps(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

class Init_PlatformTarget_yaw
{
public:
  explicit Init_PlatformTarget_yaw(::messages::msg::PlatformTarget & msg)
  : msg_(msg)
  {}
  Init_PlatformTarget_vx_mps yaw(::messages::msg::PlatformTarget::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_PlatformTarget_vx_mps(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

class Init_PlatformTarget_z
{
public:
  explicit Init_PlatformTarget_z(::messages::msg::PlatformTarget & msg)
  : msg_(msg)
  {}
  Init_PlatformTarget_yaw z(::messages::msg::PlatformTarget::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_PlatformTarget_yaw(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

class Init_PlatformTarget_y
{
public:
  explicit Init_PlatformTarget_y(::messages::msg::PlatformTarget & msg)
  : msg_(msg)
  {}
  Init_PlatformTarget_z y(::messages::msg::PlatformTarget::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_PlatformTarget_z(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

class Init_PlatformTarget_x
{
public:
  explicit Init_PlatformTarget_x(::messages::msg::PlatformTarget & msg)
  : msg_(msg)
  {}
  Init_PlatformTarget_y x(::messages::msg::PlatformTarget::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_PlatformTarget_y(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

class Init_PlatformTarget_platform
{
public:
  Init_PlatformTarget_platform()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlatformTarget_x platform(::messages::msg::PlatformTarget::_platform_type arg)
  {
    msg_.platform = std::move(arg);
    return Init_PlatformTarget_x(msg_);
  }

private:
  ::messages::msg::PlatformTarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::PlatformTarget>()
{
  return messages::msg::builder::Init_PlatformTarget_platform();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__PLATFORM_TARGET__BUILDER_HPP_
