// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/SmartCarCalibStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/smart_car_calib_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_SmartCarCalibStatus_yaw_sign_inverted
{
public:
  explicit Init_SmartCarCalibStatus_yaw_sign_inverted(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  ::messages::msg::SmartCarCalibStatus yaw_sign_inverted(::messages::msg::SmartCarCalibStatus::_yaw_sign_inverted_type arg)
  {
    msg_.yaw_sign_inverted = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_sweep_enabled
{
public:
  explicit Init_SmartCarCalibStatus_sweep_enabled(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_yaw_sign_inverted sweep_enabled(::messages::msg::SmartCarCalibStatus::_sweep_enabled_type arg)
  {
    msg_.sweep_enabled = std::move(arg);
    return Init_SmartCarCalibStatus_yaw_sign_inverted(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_state
{
public:
  explicit Init_SmartCarCalibStatus_state(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_sweep_enabled state(::messages::msg::SmartCarCalibStatus::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_SmartCarCalibStatus_sweep_enabled(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_servo_pwm_us
{
public:
  explicit Init_SmartCarCalibStatus_servo_pwm_us(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_state servo_pwm_us(::messages::msg::SmartCarCalibStatus::_servo_pwm_us_type arg)
  {
    msg_.servo_pwm_us = std::move(arg);
    return Init_SmartCarCalibStatus_state(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_target_rpm
{
public:
  explicit Init_SmartCarCalibStatus_target_rpm(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_servo_pwm_us target_rpm(::messages::msg::SmartCarCalibStatus::_target_rpm_type arg)
  {
    msg_.target_rpm = std::move(arg);
    return Init_SmartCarCalibStatus_servo_pwm_us(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_radius_est
{
public:
  explicit Init_SmartCarCalibStatus_radius_est(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_target_rpm radius_est(::messages::msg::SmartCarCalibStatus::_radius_est_type arg)
  {
    msg_.radius_est = std::move(arg);
    return Init_SmartCarCalibStatus_target_rpm(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_kappa_avg
{
public:
  explicit Init_SmartCarCalibStatus_kappa_avg(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_radius_est kappa_avg(::messages::msg::SmartCarCalibStatus::_kappa_avg_type arg)
  {
    msg_.kappa_avg = std::move(arg);
    return Init_SmartCarCalibStatus_radius_est(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_yaw_rate_avg
{
public:
  explicit Init_SmartCarCalibStatus_yaw_rate_avg(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_kappa_avg yaw_rate_avg(::messages::msg::SmartCarCalibStatus::_yaw_rate_avg_type arg)
  {
    msg_.yaw_rate_avg = std::move(arg);
    return Init_SmartCarCalibStatus_kappa_avg(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_v_center_avg
{
public:
  explicit Init_SmartCarCalibStatus_v_center_avg(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_yaw_rate_avg v_center_avg(::messages::msg::SmartCarCalibStatus::_v_center_avg_type arg)
  {
    msg_.v_center_avg = std::move(arg);
    return Init_SmartCarCalibStatus_yaw_rate_avg(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_invalid_count
{
public:
  explicit Init_SmartCarCalibStatus_invalid_count(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_v_center_avg invalid_count(::messages::msg::SmartCarCalibStatus::_invalid_count_type arg)
  {
    msg_.invalid_count = std::move(arg);
    return Init_SmartCarCalibStatus_v_center_avg(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_valid_count
{
public:
  explicit Init_SmartCarCalibStatus_valid_count(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_invalid_count valid_count(::messages::msg::SmartCarCalibStatus::_valid_count_type arg)
  {
    msg_.valid_count = std::move(arg);
    return Init_SmartCarCalibStatus_invalid_count(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_sweep_count
{
public:
  explicit Init_SmartCarCalibStatus_sweep_count(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_valid_count sweep_count(::messages::msg::SmartCarCalibStatus::_sweep_count_type arg)
  {
    msg_.sweep_count = std::move(arg);
    return Init_SmartCarCalibStatus_valid_count(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_sweep_index
{
public:
  explicit Init_SmartCarCalibStatus_sweep_index(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_sweep_count sweep_index(::messages::msg::SmartCarCalibStatus::_sweep_index_type arg)
  {
    msg_.sweep_index = std::move(arg);
    return Init_SmartCarCalibStatus_sweep_count(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_point_id
{
public:
  explicit Init_SmartCarCalibStatus_point_id(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_sweep_index point_id(::messages::msg::SmartCarCalibStatus::_point_id_type arg)
  {
    msg_.point_id = std::move(arg);
    return Init_SmartCarCalibStatus_sweep_index(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_time_boot_ms
{
public:
  explicit Init_SmartCarCalibStatus_time_boot_ms(::messages::msg::SmartCarCalibStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarCalibStatus_point_id time_boot_ms(::messages::msg::SmartCarCalibStatus::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_SmartCarCalibStatus_point_id(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

class Init_SmartCarCalibStatus_stamp
{
public:
  Init_SmartCarCalibStatus_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartCarCalibStatus_time_boot_ms stamp(::messages::msg::SmartCarCalibStatus::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_SmartCarCalibStatus_time_boot_ms(msg_);
  }

private:
  ::messages::msg::SmartCarCalibStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::SmartCarCalibStatus>()
{
  return messages::msg::builder::Init_SmartCarCalibStatus_stamp();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__BUILDER_HPP_
