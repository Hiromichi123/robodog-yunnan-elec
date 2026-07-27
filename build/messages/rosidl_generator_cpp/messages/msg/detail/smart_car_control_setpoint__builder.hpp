// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/SmartCarControlSetpoint.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/smart_car_control_setpoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_SmartCarControlSetpoint_target_accel_mps2
{
public:
  explicit Init_SmartCarControlSetpoint_target_accel_mps2(::messages::msg::SmartCarControlSetpoint & msg)
  : msg_(msg)
  {}
  ::messages::msg::SmartCarControlSetpoint target_accel_mps2(::messages::msg::SmartCarControlSetpoint::_target_accel_mps2_type arg)
  {
    msg_.target_accel_mps2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::SmartCarControlSetpoint msg_;
};

class Init_SmartCarControlSetpoint_target_yaw_rate_dps
{
public:
  explicit Init_SmartCarControlSetpoint_target_yaw_rate_dps(::messages::msg::SmartCarControlSetpoint & msg)
  : msg_(msg)
  {}
  Init_SmartCarControlSetpoint_target_accel_mps2 target_yaw_rate_dps(::messages::msg::SmartCarControlSetpoint::_target_yaw_rate_dps_type arg)
  {
    msg_.target_yaw_rate_dps = std::move(arg);
    return Init_SmartCarControlSetpoint_target_accel_mps2(msg_);
  }

private:
  ::messages::msg::SmartCarControlSetpoint msg_;
};

class Init_SmartCarControlSetpoint_target_curvature
{
public:
  explicit Init_SmartCarControlSetpoint_target_curvature(::messages::msg::SmartCarControlSetpoint & msg)
  : msg_(msg)
  {}
  Init_SmartCarControlSetpoint_target_yaw_rate_dps target_curvature(::messages::msg::SmartCarControlSetpoint::_target_curvature_type arg)
  {
    msg_.target_curvature = std::move(arg);
    return Init_SmartCarControlSetpoint_target_yaw_rate_dps(msg_);
  }

private:
  ::messages::msg::SmartCarControlSetpoint msg_;
};

class Init_SmartCarControlSetpoint_target_speed_mps
{
public:
  explicit Init_SmartCarControlSetpoint_target_speed_mps(::messages::msg::SmartCarControlSetpoint & msg)
  : msg_(msg)
  {}
  Init_SmartCarControlSetpoint_target_curvature target_speed_mps(::messages::msg::SmartCarControlSetpoint::_target_speed_mps_type arg)
  {
    msg_.target_speed_mps = std::move(arg);
    return Init_SmartCarControlSetpoint_target_curvature(msg_);
  }

private:
  ::messages::msg::SmartCarControlSetpoint msg_;
};

class Init_SmartCarControlSetpoint_flags
{
public:
  explicit Init_SmartCarControlSetpoint_flags(::messages::msg::SmartCarControlSetpoint & msg)
  : msg_(msg)
  {}
  Init_SmartCarControlSetpoint_target_speed_mps flags(::messages::msg::SmartCarControlSetpoint::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return Init_SmartCarControlSetpoint_target_speed_mps(msg_);
  }

private:
  ::messages::msg::SmartCarControlSetpoint msg_;
};

class Init_SmartCarControlSetpoint_mode
{
public:
  Init_SmartCarControlSetpoint_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartCarControlSetpoint_flags mode(::messages::msg::SmartCarControlSetpoint::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_SmartCarControlSetpoint_flags(msg_);
  }

private:
  ::messages::msg::SmartCarControlSetpoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::SmartCarControlSetpoint>()
{
  return messages::msg::builder::Init_SmartCarControlSetpoint_mode();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__BUILDER_HPP_
