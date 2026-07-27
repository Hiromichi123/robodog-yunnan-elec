// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/SmartCarControlSetpoint.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages__msg__SmartCarControlSetpoint __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__SmartCarControlSetpoint __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SmartCarControlSetpoint_
{
  using Type = SmartCarControlSetpoint_<ContainerAllocator>;

  explicit SmartCarControlSetpoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->flags = 0;
      this->target_speed_mps = 0.0f;
      this->target_curvature = 0.0f;
      this->target_yaw_rate_dps = 0.0f;
      this->target_accel_mps2 = 0.0f;
    }
  }

  explicit SmartCarControlSetpoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->flags = 0;
      this->target_speed_mps = 0.0f;
      this->target_curvature = 0.0f;
      this->target_yaw_rate_dps = 0.0f;
      this->target_accel_mps2 = 0.0f;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _flags_type =
    uint16_t;
  _flags_type flags;
  using _target_speed_mps_type =
    float;
  _target_speed_mps_type target_speed_mps;
  using _target_curvature_type =
    float;
  _target_curvature_type target_curvature;
  using _target_yaw_rate_dps_type =
    float;
  _target_yaw_rate_dps_type target_yaw_rate_dps;
  using _target_accel_mps2_type =
    float;
  _target_accel_mps2_type target_accel_mps2;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__flags(
    const uint16_t & _arg)
  {
    this->flags = _arg;
    return *this;
  }
  Type & set__target_speed_mps(
    const float & _arg)
  {
    this->target_speed_mps = _arg;
    return *this;
  }
  Type & set__target_curvature(
    const float & _arg)
  {
    this->target_curvature = _arg;
    return *this;
  }
  Type & set__target_yaw_rate_dps(
    const float & _arg)
  {
    this->target_yaw_rate_dps = _arg;
    return *this;
  }
  Type & set__target_accel_mps2(
    const float & _arg)
  {
    this->target_accel_mps2 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t SMART_CAR_MODE_IDLE =
    0u;
  static constexpr uint8_t SMART_CAR_MODE_MANUAL =
    1u;
  static constexpr uint8_t SMART_CAR_MODE_AUTO =
    2u;
  static constexpr uint8_t SMART_CAR_MODE_CALIB =
    3u;
  static constexpr uint16_t SMART_CAR_CONTROL_FLAG_ENABLE =
    1u;
  static constexpr uint16_t SMART_CAR_CONTROL_FLAG_BRAKE =
    2u;
  static constexpr uint16_t SMART_CAR_CONTROL_FLAG_REVERSE =
    4u;
  static constexpr uint16_t SMART_CAR_CONTROL_FLAG_HOLD =
    8u;

  // pointer types
  using RawPtr =
    messages::msg::SmartCarControlSetpoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::SmartCarControlSetpoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::SmartCarControlSetpoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::SmartCarControlSetpoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarControlSetpoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarControlSetpoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarControlSetpoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarControlSetpoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::SmartCarControlSetpoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::SmartCarControlSetpoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__SmartCarControlSetpoint
    std::shared_ptr<messages::msg::SmartCarControlSetpoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__SmartCarControlSetpoint
    std::shared_ptr<messages::msg::SmartCarControlSetpoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartCarControlSetpoint_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->flags != other.flags) {
      return false;
    }
    if (this->target_speed_mps != other.target_speed_mps) {
      return false;
    }
    if (this->target_curvature != other.target_curvature) {
      return false;
    }
    if (this->target_yaw_rate_dps != other.target_yaw_rate_dps) {
      return false;
    }
    if (this->target_accel_mps2 != other.target_accel_mps2) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartCarControlSetpoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartCarControlSetpoint_

// alias to use template instance with default allocator
using SmartCarControlSetpoint =
  messages::msg::SmartCarControlSetpoint_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarControlSetpoint_<ContainerAllocator>::SMART_CAR_MODE_IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarControlSetpoint_<ContainerAllocator>::SMART_CAR_MODE_MANUAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarControlSetpoint_<ContainerAllocator>::SMART_CAR_MODE_AUTO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarControlSetpoint_<ContainerAllocator>::SMART_CAR_MODE_CALIB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarControlSetpoint_<ContainerAllocator>::SMART_CAR_CONTROL_FLAG_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarControlSetpoint_<ContainerAllocator>::SMART_CAR_CONTROL_FLAG_BRAKE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarControlSetpoint_<ContainerAllocator>::SMART_CAR_CONTROL_FLAG_REVERSE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarControlSetpoint_<ContainerAllocator>::SMART_CAR_CONTROL_FLAG_HOLD;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__STRUCT_HPP_
