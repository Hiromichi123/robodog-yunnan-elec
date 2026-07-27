// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:srv/SmartCarActuatorTest.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__BUILDER_HPP_
#define MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/srv/detail/smart_car_actuator_test__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace srv
{

namespace builder
{

class Init_SmartCarActuatorTest_Request_duration_ms
{
public:
  explicit Init_SmartCarActuatorTest_Request_duration_ms(::messages::srv::SmartCarActuatorTest_Request & msg)
  : msg_(msg)
  {}
  ::messages::srv::SmartCarActuatorTest_Request duration_ms(::messages::srv::SmartCarActuatorTest_Request::_duration_ms_type arg)
  {
    msg_.duration_ms = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::srv::SmartCarActuatorTest_Request msg_;
};

class Init_SmartCarActuatorTest_Request_motor2_rpm
{
public:
  explicit Init_SmartCarActuatorTest_Request_motor2_rpm(::messages::srv::SmartCarActuatorTest_Request & msg)
  : msg_(msg)
  {}
  Init_SmartCarActuatorTest_Request_duration_ms motor2_rpm(::messages::srv::SmartCarActuatorTest_Request::_motor2_rpm_type arg)
  {
    msg_.motor2_rpm = std::move(arg);
    return Init_SmartCarActuatorTest_Request_duration_ms(msg_);
  }

private:
  ::messages::srv::SmartCarActuatorTest_Request msg_;
};

class Init_SmartCarActuatorTest_Request_motor1_rpm
{
public:
  explicit Init_SmartCarActuatorTest_Request_motor1_rpm(::messages::srv::SmartCarActuatorTest_Request & msg)
  : msg_(msg)
  {}
  Init_SmartCarActuatorTest_Request_motor2_rpm motor1_rpm(::messages::srv::SmartCarActuatorTest_Request::_motor1_rpm_type arg)
  {
    msg_.motor1_rpm = std::move(arg);
    return Init_SmartCarActuatorTest_Request_motor2_rpm(msg_);
  }

private:
  ::messages::srv::SmartCarActuatorTest_Request msg_;
};

class Init_SmartCarActuatorTest_Request_servo_pwm_us
{
public:
  explicit Init_SmartCarActuatorTest_Request_servo_pwm_us(::messages::srv::SmartCarActuatorTest_Request & msg)
  : msg_(msg)
  {}
  Init_SmartCarActuatorTest_Request_motor1_rpm servo_pwm_us(::messages::srv::SmartCarActuatorTest_Request::_servo_pwm_us_type arg)
  {
    msg_.servo_pwm_us = std::move(arg);
    return Init_SmartCarActuatorTest_Request_motor1_rpm(msg_);
  }

private:
  ::messages::srv::SmartCarActuatorTest_Request msg_;
};

class Init_SmartCarActuatorTest_Request_servo_angle_deg
{
public:
  explicit Init_SmartCarActuatorTest_Request_servo_angle_deg(::messages::srv::SmartCarActuatorTest_Request & msg)
  : msg_(msg)
  {}
  Init_SmartCarActuatorTest_Request_servo_pwm_us servo_angle_deg(::messages::srv::SmartCarActuatorTest_Request::_servo_angle_deg_type arg)
  {
    msg_.servo_angle_deg = std::move(arg);
    return Init_SmartCarActuatorTest_Request_servo_pwm_us(msg_);
  }

private:
  ::messages::srv::SmartCarActuatorTest_Request msg_;
};

class Init_SmartCarActuatorTest_Request_test_mask
{
public:
  Init_SmartCarActuatorTest_Request_test_mask()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartCarActuatorTest_Request_servo_angle_deg test_mask(::messages::srv::SmartCarActuatorTest_Request::_test_mask_type arg)
  {
    msg_.test_mask = std::move(arg);
    return Init_SmartCarActuatorTest_Request_servo_angle_deg(msg_);
  }

private:
  ::messages::srv::SmartCarActuatorTest_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::srv::SmartCarActuatorTest_Request>()
{
  return messages::srv::builder::Init_SmartCarActuatorTest_Request_test_mask();
}

}  // namespace messages


namespace messages
{

namespace srv
{

namespace builder
{

class Init_SmartCarActuatorTest_Response_message
{
public:
  explicit Init_SmartCarActuatorTest_Response_message(::messages::srv::SmartCarActuatorTest_Response & msg)
  : msg_(msg)
  {}
  ::messages::srv::SmartCarActuatorTest_Response message(::messages::srv::SmartCarActuatorTest_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::srv::SmartCarActuatorTest_Response msg_;
};

class Init_SmartCarActuatorTest_Response_accepted
{
public:
  Init_SmartCarActuatorTest_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartCarActuatorTest_Response_message accepted(::messages::srv::SmartCarActuatorTest_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_SmartCarActuatorTest_Response_message(msg_);
  }

private:
  ::messages::srv::SmartCarActuatorTest_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::srv::SmartCarActuatorTest_Response>()
{
  return messages::srv::builder::Init_SmartCarActuatorTest_Response_accepted();
}

}  // namespace messages

#endif  // MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__BUILDER_HPP_
