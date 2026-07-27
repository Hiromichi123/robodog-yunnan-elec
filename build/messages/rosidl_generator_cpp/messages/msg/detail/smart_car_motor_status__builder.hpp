// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/SmartCarMotorStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/smart_car_motor_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_SmartCarMotorStatus_can_error_count
{
public:
  explicit Init_SmartCarMotorStatus_can_error_count(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  ::messages::msg::SmartCarMotorStatus can_error_count(::messages::msg::SmartCarMotorStatus::_can_error_count_type arg)
  {
    msg_.can_error_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_can_tx_busy_count
{
public:
  explicit Init_SmartCarMotorStatus_can_tx_busy_count(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_can_error_count can_tx_busy_count(::messages::msg::SmartCarMotorStatus::_can_tx_busy_count_type arg)
  {
    msg_.can_tx_busy_count = std::move(arg);
    return Init_SmartCarMotorStatus_can_error_count(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_online_mask
{
public:
  explicit Init_SmartCarMotorStatus_online_mask(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_can_tx_busy_count online_mask(::messages::msg::SmartCarMotorStatus::_online_mask_type arg)
  {
    msg_.online_mask = std::move(arg);
    return Init_SmartCarMotorStatus_can_tx_busy_count(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_angle_2
{
public:
  explicit Init_SmartCarMotorStatus_angle_2(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_online_mask angle_2(::messages::msg::SmartCarMotorStatus::_angle_2_type arg)
  {
    msg_.angle_2 = std::move(arg);
    return Init_SmartCarMotorStatus_online_mask(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_angle_1
{
public:
  explicit Init_SmartCarMotorStatus_angle_1(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_angle_2 angle_1(::messages::msg::SmartCarMotorStatus::_angle_1_type arg)
  {
    msg_.angle_1 = std::move(arg);
    return Init_SmartCarMotorStatus_angle_2(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_feedback_current_2
{
public:
  explicit Init_SmartCarMotorStatus_feedback_current_2(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_angle_1 feedback_current_2(::messages::msg::SmartCarMotorStatus::_feedback_current_2_type arg)
  {
    msg_.feedback_current_2 = std::move(arg);
    return Init_SmartCarMotorStatus_angle_1(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_feedback_current_1
{
public:
  explicit Init_SmartCarMotorStatus_feedback_current_1(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_feedback_current_2 feedback_current_1(::messages::msg::SmartCarMotorStatus::_feedback_current_1_type arg)
  {
    msg_.feedback_current_1 = std::move(arg);
    return Init_SmartCarMotorStatus_feedback_current_2(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_current_cmd_2
{
public:
  explicit Init_SmartCarMotorStatus_current_cmd_2(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_feedback_current_1 current_cmd_2(::messages::msg::SmartCarMotorStatus::_current_cmd_2_type arg)
  {
    msg_.current_cmd_2 = std::move(arg);
    return Init_SmartCarMotorStatus_feedback_current_1(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_current_cmd_1
{
public:
  explicit Init_SmartCarMotorStatus_current_cmd_1(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_current_cmd_2 current_cmd_1(::messages::msg::SmartCarMotorStatus::_current_cmd_1_type arg)
  {
    msg_.current_cmd_1 = std::move(arg);
    return Init_SmartCarMotorStatus_current_cmd_2(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_actual_rpm_2
{
public:
  explicit Init_SmartCarMotorStatus_actual_rpm_2(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_current_cmd_1 actual_rpm_2(::messages::msg::SmartCarMotorStatus::_actual_rpm_2_type arg)
  {
    msg_.actual_rpm_2 = std::move(arg);
    return Init_SmartCarMotorStatus_current_cmd_1(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_actual_rpm_1
{
public:
  explicit Init_SmartCarMotorStatus_actual_rpm_1(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_actual_rpm_2 actual_rpm_1(::messages::msg::SmartCarMotorStatus::_actual_rpm_1_type arg)
  {
    msg_.actual_rpm_1 = std::move(arg);
    return Init_SmartCarMotorStatus_actual_rpm_2(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_target_rpm_2
{
public:
  explicit Init_SmartCarMotorStatus_target_rpm_2(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_actual_rpm_1 target_rpm_2(::messages::msg::SmartCarMotorStatus::_target_rpm_2_type arg)
  {
    msg_.target_rpm_2 = std::move(arg);
    return Init_SmartCarMotorStatus_actual_rpm_1(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_target_rpm_1
{
public:
  explicit Init_SmartCarMotorStatus_target_rpm_1(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_target_rpm_2 target_rpm_1(::messages::msg::SmartCarMotorStatus::_target_rpm_1_type arg)
  {
    msg_.target_rpm_1 = std::move(arg);
    return Init_SmartCarMotorStatus_target_rpm_2(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_time_boot_ms
{
public:
  explicit Init_SmartCarMotorStatus_time_boot_ms(::messages::msg::SmartCarMotorStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarMotorStatus_target_rpm_1 time_boot_ms(::messages::msg::SmartCarMotorStatus::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_SmartCarMotorStatus_target_rpm_1(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

class Init_SmartCarMotorStatus_stamp
{
public:
  Init_SmartCarMotorStatus_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartCarMotorStatus_time_boot_ms stamp(::messages::msg::SmartCarMotorStatus::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_SmartCarMotorStatus_time_boot_ms(msg_);
  }

private:
  ::messages::msg::SmartCarMotorStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::SmartCarMotorStatus>()
{
  return messages::msg::builder::Init_SmartCarMotorStatus_stamp();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__BUILDER_HPP_
