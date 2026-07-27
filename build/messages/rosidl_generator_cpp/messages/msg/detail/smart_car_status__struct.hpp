// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/SmartCarStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__STRUCT_HPP_

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
# define DEPRECATED__messages__msg__SmartCarStatus __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__SmartCarStatus __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SmartCarStatus_
{
  using Type = SmartCarStatus_<ContainerAllocator>;

  explicit SmartCarStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->mode = 0;
      this->state = 0;
      this->fault_flags = 0ul;
      this->warn_flags = 0ul;
      this->cmd_age_ms = 0;
      this->control_loop_hz = 0;
      this->imu_online = 0;
      this->can_online = 0;
      this->host_online = 0;
      this->servo_online = 0;
      this->motor_online_mask = 0;
    }
  }

  explicit SmartCarStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->mode = 0;
      this->state = 0;
      this->fault_flags = 0ul;
      this->warn_flags = 0ul;
      this->cmd_age_ms = 0;
      this->control_loop_hz = 0;
      this->imu_online = 0;
      this->can_online = 0;
      this->host_online = 0;
      this->servo_online = 0;
      this->motor_online_mask = 0;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _time_boot_ms_type =
    uint32_t;
  _time_boot_ms_type time_boot_ms;
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _state_type =
    uint8_t;
  _state_type state;
  using _fault_flags_type =
    uint32_t;
  _fault_flags_type fault_flags;
  using _warn_flags_type =
    uint32_t;
  _warn_flags_type warn_flags;
  using _cmd_age_ms_type =
    uint16_t;
  _cmd_age_ms_type cmd_age_ms;
  using _control_loop_hz_type =
    uint16_t;
  _control_loop_hz_type control_loop_hz;
  using _imu_online_type =
    uint8_t;
  _imu_online_type imu_online;
  using _can_online_type =
    uint8_t;
  _can_online_type can_online;
  using _host_online_type =
    uint8_t;
  _host_online_type host_online;
  using _servo_online_type =
    uint8_t;
  _servo_online_type servo_online;
  using _motor_online_mask_type =
    uint8_t;
  _motor_online_mask_type motor_online_mask;

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
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__fault_flags(
    const uint32_t & _arg)
  {
    this->fault_flags = _arg;
    return *this;
  }
  Type & set__warn_flags(
    const uint32_t & _arg)
  {
    this->warn_flags = _arg;
    return *this;
  }
  Type & set__cmd_age_ms(
    const uint16_t & _arg)
  {
    this->cmd_age_ms = _arg;
    return *this;
  }
  Type & set__control_loop_hz(
    const uint16_t & _arg)
  {
    this->control_loop_hz = _arg;
    return *this;
  }
  Type & set__imu_online(
    const uint8_t & _arg)
  {
    this->imu_online = _arg;
    return *this;
  }
  Type & set__can_online(
    const uint8_t & _arg)
  {
    this->can_online = _arg;
    return *this;
  }
  Type & set__host_online(
    const uint8_t & _arg)
  {
    this->host_online = _arg;
    return *this;
  }
  Type & set__servo_online(
    const uint8_t & _arg)
  {
    this->servo_online = _arg;
    return *this;
  }
  Type & set__motor_online_mask(
    const uint8_t & _arg)
  {
    this->motor_online_mask = _arg;
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
  static constexpr uint8_t SMART_CAR_STATE_IDLE =
    0u;
  static constexpr uint8_t SMART_CAR_STATE_ARMED =
    1u;
  static constexpr uint8_t SMART_CAR_STATE_RUNNING =
    2u;
  static constexpr uint8_t SMART_CAR_STATE_FAULT =
    3u;
  static constexpr uint8_t SMART_CAR_STATE_CALIB =
    4u;
  static constexpr uint32_t SMART_CAR_FAULT_CMD_TIMEOUT =
    1u;
  static constexpr uint32_t SMART_CAR_FAULT_MOTOR1_OFFLINE =
    2u;
  static constexpr uint32_t SMART_CAR_FAULT_MOTOR2_OFFLINE =
    4u;
  static constexpr uint32_t SMART_CAR_FAULT_IMU_NOT_READY =
    8u;
  static constexpr uint32_t SMART_CAR_FAULT_CAN_ERROR =
    16u;
  static constexpr uint32_t SMART_CAR_FAULT_SERVO_CLAMPED =
    32u;

  // pointer types
  using RawPtr =
    messages::msg::SmartCarStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::SmartCarStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::SmartCarStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::SmartCarStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::SmartCarStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::SmartCarStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__SmartCarStatus
    std::shared_ptr<messages::msg::SmartCarStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__SmartCarStatus
    std::shared_ptr<messages::msg::SmartCarStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartCarStatus_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->time_boot_ms != other.time_boot_ms) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->fault_flags != other.fault_flags) {
      return false;
    }
    if (this->warn_flags != other.warn_flags) {
      return false;
    }
    if (this->cmd_age_ms != other.cmd_age_ms) {
      return false;
    }
    if (this->control_loop_hz != other.control_loop_hz) {
      return false;
    }
    if (this->imu_online != other.imu_online) {
      return false;
    }
    if (this->can_online != other.can_online) {
      return false;
    }
    if (this->host_online != other.host_online) {
      return false;
    }
    if (this->servo_online != other.servo_online) {
      return false;
    }
    if (this->motor_online_mask != other.motor_online_mask) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartCarStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartCarStatus_

// alias to use template instance with default allocator
using SmartCarStatus =
  messages::msg::SmartCarStatus_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_MODE_IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_MODE_MANUAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_MODE_AUTO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_MODE_CALIB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_STATE_IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_STATE_ARMED;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_STATE_RUNNING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_STATE_FAULT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_STATE_CALIB;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_FAULT_CMD_TIMEOUT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_FAULT_MOTOR1_OFFLINE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_FAULT_MOTOR2_OFFLINE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_FAULT_IMU_NOT_READY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_FAULT_CAN_ERROR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint32_t SmartCarStatus_<ContainerAllocator>::SMART_CAR_FAULT_SERVO_CLAMPED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__STRUCT_HPP_
