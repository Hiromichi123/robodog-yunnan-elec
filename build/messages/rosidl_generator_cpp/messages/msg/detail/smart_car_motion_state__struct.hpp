// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/SmartCarMotionState.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__messages__msg__SmartCarMotionState __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__SmartCarMotionState __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SmartCarMotionState_
{
  using Type = SmartCarMotionState_<ContainerAllocator>;

  explicit SmartCarMotionState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->speed_mps = 0.0f;
      this->target_speed_mps = 0.0f;
      this->yaw_rate_dps = 0.0f;
      this->yaw_deg = 0.0f;
      this->curvature_meas = 0.0f;
      this->curvature_cmd = 0.0f;
      this->steering_angle_deg = 0.0f;
      this->steering_pwm_us = 0;
      this->steering_clamped = 0;
    }
  }

  explicit SmartCarMotionState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->speed_mps = 0.0f;
      this->target_speed_mps = 0.0f;
      this->yaw_rate_dps = 0.0f;
      this->yaw_deg = 0.0f;
      this->curvature_meas = 0.0f;
      this->curvature_cmd = 0.0f;
      this->steering_angle_deg = 0.0f;
      this->steering_pwm_us = 0;
      this->steering_clamped = 0;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _time_boot_ms_type =
    uint32_t;
  _time_boot_ms_type time_boot_ms;
  using _speed_mps_type =
    float;
  _speed_mps_type speed_mps;
  using _target_speed_mps_type =
    float;
  _target_speed_mps_type target_speed_mps;
  using _yaw_rate_dps_type =
    float;
  _yaw_rate_dps_type yaw_rate_dps;
  using _yaw_deg_type =
    float;
  _yaw_deg_type yaw_deg;
  using _curvature_meas_type =
    float;
  _curvature_meas_type curvature_meas;
  using _curvature_cmd_type =
    float;
  _curvature_cmd_type curvature_cmd;
  using _steering_angle_deg_type =
    float;
  _steering_angle_deg_type steering_angle_deg;
  using _steering_pwm_us_type =
    uint16_t;
  _steering_pwm_us_type steering_pwm_us;
  using _steering_clamped_type =
    uint8_t;
  _steering_clamped_type steering_clamped;

  // setters for named parameter idiom
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__time_boot_ms(
    const uint32_t & _arg)
  {
    this->time_boot_ms = _arg;
    return *this;
  }
  Type & set__speed_mps(
    const float & _arg)
  {
    this->speed_mps = _arg;
    return *this;
  }
  Type & set__target_speed_mps(
    const float & _arg)
  {
    this->target_speed_mps = _arg;
    return *this;
  }
  Type & set__yaw_rate_dps(
    const float & _arg)
  {
    this->yaw_rate_dps = _arg;
    return *this;
  }
  Type & set__yaw_deg(
    const float & _arg)
  {
    this->yaw_deg = _arg;
    return *this;
  }
  Type & set__curvature_meas(
    const float & _arg)
  {
    this->curvature_meas = _arg;
    return *this;
  }
  Type & set__curvature_cmd(
    const float & _arg)
  {
    this->curvature_cmd = _arg;
    return *this;
  }
  Type & set__steering_angle_deg(
    const float & _arg)
  {
    this->steering_angle_deg = _arg;
    return *this;
  }
  Type & set__steering_pwm_us(
    const uint16_t & _arg)
  {
    this->steering_pwm_us = _arg;
    return *this;
  }
  Type & set__steering_clamped(
    const uint8_t & _arg)
  {
    this->steering_clamped = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::SmartCarMotionState_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::SmartCarMotionState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::SmartCarMotionState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::SmartCarMotionState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarMotionState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarMotionState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarMotionState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarMotionState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::SmartCarMotionState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::SmartCarMotionState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__SmartCarMotionState
    std::shared_ptr<messages::msg::SmartCarMotionState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__SmartCarMotionState
    std::shared_ptr<messages::msg::SmartCarMotionState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartCarMotionState_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->time_boot_ms != other.time_boot_ms) {
      return false;
    }
    if (this->speed_mps != other.speed_mps) {
      return false;
    }
    if (this->target_speed_mps != other.target_speed_mps) {
      return false;
    }
    if (this->yaw_rate_dps != other.yaw_rate_dps) {
      return false;
    }
    if (this->yaw_deg != other.yaw_deg) {
      return false;
    }
    if (this->curvature_meas != other.curvature_meas) {
      return false;
    }
    if (this->curvature_cmd != other.curvature_cmd) {
      return false;
    }
    if (this->steering_angle_deg != other.steering_angle_deg) {
      return false;
    }
    if (this->steering_pwm_us != other.steering_pwm_us) {
      return false;
    }
    if (this->steering_clamped != other.steering_clamped) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartCarMotionState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartCarMotionState_

// alias to use template instance with default allocator
using SmartCarMotionState =
  messages::msg::SmartCarMotionState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__STRUCT_HPP_
