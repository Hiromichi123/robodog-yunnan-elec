// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/SmartCarStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/smart_car_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_SmartCarStatus_motor_online_mask
{
public:
  explicit Init_SmartCarStatus_motor_online_mask(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  ::messages::msg::SmartCarStatus motor_online_mask(::messages::msg::SmartCarStatus::_motor_online_mask_type arg)
  {
    msg_.motor_online_mask = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_servo_online
{
public:
  explicit Init_SmartCarStatus_servo_online(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_motor_online_mask servo_online(::messages::msg::SmartCarStatus::_servo_online_type arg)
  {
    msg_.servo_online = std::move(arg);
    return Init_SmartCarStatus_motor_online_mask(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_host_online
{
public:
  explicit Init_SmartCarStatus_host_online(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_servo_online host_online(::messages::msg::SmartCarStatus::_host_online_type arg)
  {
    msg_.host_online = std::move(arg);
    return Init_SmartCarStatus_servo_online(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_can_online
{
public:
  explicit Init_SmartCarStatus_can_online(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_host_online can_online(::messages::msg::SmartCarStatus::_can_online_type arg)
  {
    msg_.can_online = std::move(arg);
    return Init_SmartCarStatus_host_online(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_imu_online
{
public:
  explicit Init_SmartCarStatus_imu_online(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_can_online imu_online(::messages::msg::SmartCarStatus::_imu_online_type arg)
  {
    msg_.imu_online = std::move(arg);
    return Init_SmartCarStatus_can_online(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_control_loop_hz
{
public:
  explicit Init_SmartCarStatus_control_loop_hz(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_imu_online control_loop_hz(::messages::msg::SmartCarStatus::_control_loop_hz_type arg)
  {
    msg_.control_loop_hz = std::move(arg);
    return Init_SmartCarStatus_imu_online(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_cmd_age_ms
{
public:
  explicit Init_SmartCarStatus_cmd_age_ms(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_control_loop_hz cmd_age_ms(::messages::msg::SmartCarStatus::_cmd_age_ms_type arg)
  {
    msg_.cmd_age_ms = std::move(arg);
    return Init_SmartCarStatus_control_loop_hz(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_warn_flags
{
public:
  explicit Init_SmartCarStatus_warn_flags(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_cmd_age_ms warn_flags(::messages::msg::SmartCarStatus::_warn_flags_type arg)
  {
    msg_.warn_flags = std::move(arg);
    return Init_SmartCarStatus_cmd_age_ms(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_fault_flags
{
public:
  explicit Init_SmartCarStatus_fault_flags(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_warn_flags fault_flags(::messages::msg::SmartCarStatus::_fault_flags_type arg)
  {
    msg_.fault_flags = std::move(arg);
    return Init_SmartCarStatus_warn_flags(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_state
{
public:
  explicit Init_SmartCarStatus_state(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_fault_flags state(::messages::msg::SmartCarStatus::_state_type arg)
  {
    msg_.state = std::move(arg);
    return Init_SmartCarStatus_fault_flags(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_mode
{
public:
  explicit Init_SmartCarStatus_mode(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_state mode(::messages::msg::SmartCarStatus::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_SmartCarStatus_state(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_time_boot_ms
{
public:
  explicit Init_SmartCarStatus_time_boot_ms(::messages::msg::SmartCarStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarStatus_mode time_boot_ms(::messages::msg::SmartCarStatus::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_SmartCarStatus_mode(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

class Init_SmartCarStatus_stamp
{
public:
  Init_SmartCarStatus_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartCarStatus_time_boot_ms stamp(::messages::msg::SmartCarStatus::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_SmartCarStatus_time_boot_ms(msg_);
  }

private:
  ::messages::msg::SmartCarStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::SmartCarStatus>()
{
  return messages::msg::builder::Init_SmartCarStatus_stamp();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__BUILDER_HPP_
