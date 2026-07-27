// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/SmartCarMotionState.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/smart_car_motion_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_SmartCarMotionState_steering_clamped
{
public:
  explicit Init_SmartCarMotionState_steering_clamped(::messages::msg::SmartCarMotionState & msg)
  : msg_(msg)
  {}
  ::messages::msg::SmartCarMotionState steering_clamped(::messages::msg::SmartCarMotionState::_steering_clamped_type arg)
  {
    msg_.steering_clamped = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

class Init_SmartCarMotionState_steering_pwm_us
{
public:
  explicit Init_SmartCarMotionState_steering_pwm_us(::messages::msg::SmartCarMotionState & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotionState_steering_clamped steering_pwm_us(::messages::msg::SmartCarMotionState::_steering_pwm_us_type arg)
  {
    msg_.steering_pwm_us = std::move(arg);
    return Init_SmartCarMotionState_steering_clamped(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

class Init_SmartCarMotionState_steering_angle_deg
{
public:
  explicit Init_SmartCarMotionState_steering_angle_deg(::messages::msg::SmartCarMotionState & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotionState_steering_pwm_us steering_angle_deg(::messages::msg::SmartCarMotionState::_steering_angle_deg_type arg)
  {
    msg_.steering_angle_deg = std::move(arg);
    return Init_SmartCarMotionState_steering_pwm_us(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

class Init_SmartCarMotionState_curvature_cmd
{
public:
  explicit Init_SmartCarMotionState_curvature_cmd(::messages::msg::SmartCarMotionState & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotionState_steering_angle_deg curvature_cmd(::messages::msg::SmartCarMotionState::_curvature_cmd_type arg)
  {
    msg_.curvature_cmd = std::move(arg);
    return Init_SmartCarMotionState_steering_angle_deg(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

class Init_SmartCarMotionState_curvature_meas
{
public:
  explicit Init_SmartCarMotionState_curvature_meas(::messages::msg::SmartCarMotionState & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotionState_curvature_cmd curvature_meas(::messages::msg::SmartCarMotionState::_curvature_meas_type arg)
  {
    msg_.curvature_meas = std::move(arg);
    return Init_SmartCarMotionState_curvature_cmd(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

class Init_SmartCarMotionState_yaw_deg
{
public:
  explicit Init_SmartCarMotionState_yaw_deg(::messages::msg::SmartCarMotionState & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotionState_curvature_meas yaw_deg(::messages::msg::SmartCarMotionState::_yaw_deg_type arg)
  {
    msg_.yaw_deg = std::move(arg);
    return Init_SmartCarMotionState_curvature_meas(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

class Init_SmartCarMotionState_yaw_rate_dps
{
public:
  explicit Init_SmartCarMotionState_yaw_rate_dps(::messages::msg::SmartCarMotionState & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotionState_yaw_deg yaw_rate_dps(::messages::msg::SmartCarMotionState::_yaw_rate_dps_type arg)
  {
    msg_.yaw_rate_dps = std::move(arg);
    return Init_SmartCarMotionState_yaw_deg(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

class Init_SmartCarMotionState_target_speed_mps
{
public:
  explicit Init_SmartCarMotionState_target_speed_mps(::messages::msg::SmartCarMotionState & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotionState_yaw_rate_dps target_speed_mps(::messages::msg::SmartCarMotionState::_target_speed_mps_type arg)
  {
    msg_.target_speed_mps = std::move(arg);
    return Init_SmartCarMotionState_yaw_rate_dps(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

class Init_SmartCarMotionState_speed_mps
{
public:
  explicit Init_SmartCarMotionState_speed_mps(::messages::msg::SmartCarMotionState & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotionState_target_speed_mps speed_mps(::messages::msg::SmartCarMotionState::_speed_mps_type arg)
  {
    msg_.speed_mps = std::move(arg);
    return Init_SmartCarMotionState_target_speed_mps(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

class Init_SmartCarMotionState_time_boot_ms
{
public:
  explicit Init_SmartCarMotionState_time_boot_ms(::messages::msg::SmartCarMotionState & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotionState_speed_mps time_boot_ms(::messages::msg::SmartCarMotionState::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_SmartCarMotionState_speed_mps(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

class Init_SmartCarMotionState_stamp
{
public:
  Init_SmartCarMotionState_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartCarMotionState_time_boot_ms stamp(::messages::msg::SmartCarMotionState::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_SmartCarMotionState_time_boot_ms(msg_);
  }

private:
  ::messages::msg::SmartCarMotionState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::SmartCarMotionState>()
{
  return messages::msg::builder::Init_SmartCarMotionState_stamp();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__BUILDER_HPP_
