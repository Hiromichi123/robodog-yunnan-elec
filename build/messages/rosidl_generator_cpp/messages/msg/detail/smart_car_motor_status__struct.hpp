// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/SmartCarMotorStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__STRUCT_HPP_

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
# define DEPRECATED__messages__msg__SmartCarMotorStatus __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__SmartCarMotorStatus __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SmartCarMotorStatus_
{
  using Type = SmartCarMotorStatus_<ContainerAllocator>;

  explicit SmartCarMotorStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->target_rpm_1 = 0;
      this->target_rpm_2 = 0;
      this->actual_rpm_1 = 0;
      this->actual_rpm_2 = 0;
      this->current_cmd_1 = 0;
      this->current_cmd_2 = 0;
      this->feedback_current_1 = 0;
      this->feedback_current_2 = 0;
      this->angle_1 = 0;
      this->angle_2 = 0;
      this->online_mask = 0;
      this->can_tx_busy_count = 0ul;
      this->can_error_count = 0ul;
    }
  }

  explicit SmartCarMotorStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->target_rpm_1 = 0;
      this->target_rpm_2 = 0;
      this->actual_rpm_1 = 0;
      this->actual_rpm_2 = 0;
      this->current_cmd_1 = 0;
      this->current_cmd_2 = 0;
      this->feedback_current_1 = 0;
      this->feedback_current_2 = 0;
      this->angle_1 = 0;
      this->angle_2 = 0;
      this->online_mask = 0;
      this->can_tx_busy_count = 0ul;
      this->can_error_count = 0ul;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _time_boot_ms_type =
    uint32_t;
  _time_boot_ms_type time_boot_ms;
  using _target_rpm_1_type =
    int16_t;
  _target_rpm_1_type target_rpm_1;
  using _target_rpm_2_type =
    int16_t;
  _target_rpm_2_type target_rpm_2;
  using _actual_rpm_1_type =
    int16_t;
  _actual_rpm_1_type actual_rpm_1;
  using _actual_rpm_2_type =
    int16_t;
  _actual_rpm_2_type actual_rpm_2;
  using _current_cmd_1_type =
    int16_t;
  _current_cmd_1_type current_cmd_1;
  using _current_cmd_2_type =
    int16_t;
  _current_cmd_2_type current_cmd_2;
  using _feedback_current_1_type =
    int16_t;
  _feedback_current_1_type feedback_current_1;
  using _feedback_current_2_type =
    int16_t;
  _feedback_current_2_type feedback_current_2;
  using _angle_1_type =
    uint16_t;
  _angle_1_type angle_1;
  using _angle_2_type =
    uint16_t;
  _angle_2_type angle_2;
  using _online_mask_type =
    uint8_t;
  _online_mask_type online_mask;
  using _can_tx_busy_count_type =
    uint32_t;
  _can_tx_busy_count_type can_tx_busy_count;
  using _can_error_count_type =
    uint32_t;
  _can_error_count_type can_error_count;

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
  Type & set__target_rpm_1(
    const int16_t & _arg)
  {
    this->target_rpm_1 = _arg;
    return *this;
  }
  Type & set__target_rpm_2(
    const int16_t & _arg)
  {
    this->target_rpm_2 = _arg;
    return *this;
  }
  Type & set__actual_rpm_1(
    const int16_t & _arg)
  {
    this->actual_rpm_1 = _arg;
    return *this;
  }
  Type & set__actual_rpm_2(
    const int16_t & _arg)
  {
    this->actual_rpm_2 = _arg;
    return *this;
  }
  Type & set__current_cmd_1(
    const int16_t & _arg)
  {
    this->current_cmd_1 = _arg;
    return *this;
  }
  Type & set__current_cmd_2(
    const int16_t & _arg)
  {
    this->current_cmd_2 = _arg;
    return *this;
  }
  Type & set__feedback_current_1(
    const int16_t & _arg)
  {
    this->feedback_current_1 = _arg;
    return *this;
  }
  Type & set__feedback_current_2(
    const int16_t & _arg)
  {
    this->feedback_current_2 = _arg;
    return *this;
  }
  Type & set__angle_1(
    const uint16_t & _arg)
  {
    this->angle_1 = _arg;
    return *this;
  }
  Type & set__angle_2(
    const uint16_t & _arg)
  {
    this->angle_2 = _arg;
    return *this;
  }
  Type & set__online_mask(
    const uint8_t & _arg)
  {
    this->online_mask = _arg;
    return *this;
  }
  Type & set__can_tx_busy_count(
    const uint32_t & _arg)
  {
    this->can_tx_busy_count = _arg;
    return *this;
  }
  Type & set__can_error_count(
    const uint32_t & _arg)
  {
    this->can_error_count = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::SmartCarMotorStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::SmartCarMotorStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::SmartCarMotorStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::SmartCarMotorStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarMotorStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarMotorStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarMotorStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarMotorStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::SmartCarMotorStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::SmartCarMotorStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__SmartCarMotorStatus
    std::shared_ptr<messages::msg::SmartCarMotorStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__SmartCarMotorStatus
    std::shared_ptr<messages::msg::SmartCarMotorStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartCarMotorStatus_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->time_boot_ms != other.time_boot_ms) {
      return false;
    }
    if (this->target_rpm_1 != other.target_rpm_1) {
      return false;
    }
    if (this->target_rpm_2 != other.target_rpm_2) {
      return false;
    }
    if (this->actual_rpm_1 != other.actual_rpm_1) {
      return false;
    }
    if (this->actual_rpm_2 != other.actual_rpm_2) {
      return false;
    }
    if (this->current_cmd_1 != other.current_cmd_1) {
      return false;
    }
    if (this->current_cmd_2 != other.current_cmd_2) {
      return false;
    }
    if (this->feedback_current_1 != other.feedback_current_1) {
      return false;
    }
    if (this->feedback_current_2 != other.feedback_current_2) {
      return false;
    }
    if (this->angle_1 != other.angle_1) {
      return false;
    }
    if (this->angle_2 != other.angle_2) {
      return false;
    }
    if (this->online_mask != other.online_mask) {
      return false;
    }
    if (this->can_tx_busy_count != other.can_tx_busy_count) {
      return false;
    }
    if (this->can_error_count != other.can_error_count) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartCarMotorStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartCarMotorStatus_

// alias to use template instance with default allocator
using SmartCarMotorStatus =
  messages::msg::SmartCarMotorStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__STRUCT_HPP_
