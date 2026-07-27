// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:srv/SmartCarActuatorTest.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__STRUCT_HPP_
#define MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages__srv__SmartCarActuatorTest_Request __attribute__((deprecated))
#else
# define DEPRECATED__messages__srv__SmartCarActuatorTest_Request __declspec(deprecated)
#endif

namespace messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SmartCarActuatorTest_Request_
{
  using Type = SmartCarActuatorTest_Request_<ContainerAllocator>;

  explicit SmartCarActuatorTest_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->test_mask = 0;
      this->servo_angle_deg = 0.0f;
      this->servo_pwm_us = 0;
      this->motor1_rpm = 0;
      this->motor2_rpm = 0;
      this->duration_ms = 0;
    }
  }

  explicit SmartCarActuatorTest_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->test_mask = 0;
      this->servo_angle_deg = 0.0f;
      this->servo_pwm_us = 0;
      this->motor1_rpm = 0;
      this->motor2_rpm = 0;
      this->duration_ms = 0;
    }
  }

  // field types and members
  using _test_mask_type =
    uint16_t;
  _test_mask_type test_mask;
  using _servo_angle_deg_type =
    float;
  _servo_angle_deg_type servo_angle_deg;
  using _servo_pwm_us_type =
    uint16_t;
  _servo_pwm_us_type servo_pwm_us;
  using _motor1_rpm_type =
    int16_t;
  _motor1_rpm_type motor1_rpm;
  using _motor2_rpm_type =
    int16_t;
  _motor2_rpm_type motor2_rpm;
  using _duration_ms_type =
    uint16_t;
  _duration_ms_type duration_ms;

  // setters for named parameter idiom
  Type & set__test_mask(
    const uint16_t & _arg)
  {
    this->test_mask = _arg;
    return *this;
  }
  Type & set__servo_angle_deg(
    const float & _arg)
  {
    this->servo_angle_deg = _arg;
    return *this;
  }
  Type & set__servo_pwm_us(
    const uint16_t & _arg)
  {
    this->servo_pwm_us = _arg;
    return *this;
  }
  Type & set__motor1_rpm(
    const int16_t & _arg)
  {
    this->motor1_rpm = _arg;
    return *this;
  }
  Type & set__motor2_rpm(
    const int16_t & _arg)
  {
    this->motor2_rpm = _arg;
    return *this;
  }
  Type & set__duration_ms(
    const uint16_t & _arg)
  {
    this->duration_ms = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint16_t TEST_SERVO_ANGLE =
    1u;
  static constexpr uint16_t TEST_SERVO_PWM =
    2u;
  static constexpr uint16_t TEST_MOTOR_RPM =
    4u;

  // pointer types
  using RawPtr =
    messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__srv__SmartCarActuatorTest_Request
    std::shared_ptr<messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__srv__SmartCarActuatorTest_Request
    std::shared_ptr<messages::srv::SmartCarActuatorTest_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartCarActuatorTest_Request_ & other) const
  {
    if (this->test_mask != other.test_mask) {
      return false;
    }
    if (this->servo_angle_deg != other.servo_angle_deg) {
      return false;
    }
    if (this->servo_pwm_us != other.servo_pwm_us) {
      return false;
    }
    if (this->motor1_rpm != other.motor1_rpm) {
      return false;
    }
    if (this->motor2_rpm != other.motor2_rpm) {
      return false;
    }
    if (this->duration_ms != other.duration_ms) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartCarActuatorTest_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartCarActuatorTest_Request_

// alias to use template instance with default allocator
using SmartCarActuatorTest_Request =
  messages::srv::SmartCarActuatorTest_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarActuatorTest_Request_<ContainerAllocator>::TEST_SERVO_ANGLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarActuatorTest_Request_<ContainerAllocator>::TEST_SERVO_PWM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarActuatorTest_Request_<ContainerAllocator>::TEST_MOTOR_RPM;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace messages


#ifndef _WIN32
# define DEPRECATED__messages__srv__SmartCarActuatorTest_Response __attribute__((deprecated))
#else
# define DEPRECATED__messages__srv__SmartCarActuatorTest_Response __declspec(deprecated)
#endif

namespace messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SmartCarActuatorTest_Response_
{
  using Type = SmartCarActuatorTest_Response_<ContainerAllocator>;

  explicit SmartCarActuatorTest_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->message = "";
    }
  }

  explicit SmartCarActuatorTest_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->message = "";
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__srv__SmartCarActuatorTest_Response
    std::shared_ptr<messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__srv__SmartCarActuatorTest_Response
    std::shared_ptr<messages::srv::SmartCarActuatorTest_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartCarActuatorTest_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartCarActuatorTest_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartCarActuatorTest_Response_

// alias to use template instance with default allocator
using SmartCarActuatorTest_Response =
  messages::srv::SmartCarActuatorTest_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace messages

namespace messages
{

namespace srv
{

struct SmartCarActuatorTest
{
  using Request = messages::srv::SmartCarActuatorTest_Request;
  using Response = messages::srv::SmartCarActuatorTest_Response;
};

}  // namespace srv

}  // namespace messages

#endif  // MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__STRUCT_HPP_
