// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/SmartCarCalibStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__STRUCT_HPP_

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
# define DEPRECATED__messages__msg__SmartCarCalibStatus __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__SmartCarCalibStatus __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SmartCarCalibStatus_
{
  using Type = SmartCarCalibStatus_<ContainerAllocator>;

  explicit SmartCarCalibStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->point_id = 0ul;
      this->sweep_index = 0ul;
      this->sweep_count = 0ul;
      this->valid_count = 0ul;
      this->invalid_count = 0ul;
      this->v_center_avg = 0.0f;
      this->yaw_rate_avg = 0.0f;
      this->kappa_avg = 0.0f;
      this->radius_est = 0.0f;
      this->target_rpm = 0;
      this->servo_pwm_us = 0;
      this->state = 0;
      this->sweep_enabled = 0;
      this->yaw_sign_inverted = 0;
    }
  }

  explicit SmartCarCalibStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->point_id = 0ul;
      this->sweep_index = 0ul;
      this->sweep_count = 0ul;
      this->valid_count = 0ul;
      this->invalid_count = 0ul;
      this->v_center_avg = 0.0f;
      this->yaw_rate_avg = 0.0f;
      this->kappa_avg = 0.0f;
      this->radius_est = 0.0f;
      this->target_rpm = 0;
      this->servo_pwm_us = 0;
      this->state = 0;
      this->sweep_enabled = 0;
      this->yaw_sign_inverted = 0;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _time_boot_ms_type =
    uint32_t;
  _time_boot_ms_type time_boot_ms;
  using _point_id_type =
    uint32_t;
  _point_id_type point_id;
  using _sweep_index_type =
    uint32_t;
  _sweep_index_type sweep_index;
  using _sweep_count_type =
    uint32_t;
  _sweep_count_type sweep_count;
  using _valid_count_type =
    uint32_t;
  _valid_count_type valid_count;
  using _invalid_count_type =
    uint32_t;
  _invalid_count_type invalid_count;
  using _v_center_avg_type =
    float;
  _v_center_avg_type v_center_avg;
  using _yaw_rate_avg_type =
    float;
  _yaw_rate_avg_type yaw_rate_avg;
  using _kappa_avg_type =
    float;
  _kappa_avg_type kappa_avg;
  using _radius_est_type =
    float;
  _radius_est_type radius_est;
  using _target_rpm_type =
    int16_t;
  _target_rpm_type target_rpm;
  using _servo_pwm_us_type =
    uint16_t;
  _servo_pwm_us_type servo_pwm_us;
  using _state_type =
    uint8_t;
  _state_type state;
  using _sweep_enabled_type =
    uint8_t;
  _sweep_enabled_type sweep_enabled;
  using _yaw_sign_inverted_type =
    uint8_t;
  _yaw_sign_inverted_type yaw_sign_inverted;

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
  Type & set__point_id(
    const uint32_t & _arg)
  {
    this->point_id = _arg;
    return *this;
  }
  Type & set__sweep_index(
    const uint32_t & _arg)
  {
    this->sweep_index = _arg;
    return *this;
  }
  Type & set__sweep_count(
    const uint32_t & _arg)
  {
    this->sweep_count = _arg;
    return *this;
  }
  Type & set__valid_count(
    const uint32_t & _arg)
  {
    this->valid_count = _arg;
    return *this;
  }
  Type & set__invalid_count(
    const uint32_t & _arg)
  {
    this->invalid_count = _arg;
    return *this;
  }
  Type & set__v_center_avg(
    const float & _arg)
  {
    this->v_center_avg = _arg;
    return *this;
  }
  Type & set__yaw_rate_avg(
    const float & _arg)
  {
    this->yaw_rate_avg = _arg;
    return *this;
  }
  Type & set__kappa_avg(
    const float & _arg)
  {
    this->kappa_avg = _arg;
    return *this;
  }
  Type & set__radius_est(
    const float & _arg)
  {
    this->radius_est = _arg;
    return *this;
  }
  Type & set__target_rpm(
    const int16_t & _arg)
  {
    this->target_rpm = _arg;
    return *this;
  }
  Type & set__servo_pwm_us(
    const uint16_t & _arg)
  {
    this->servo_pwm_us = _arg;
    return *this;
  }
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__sweep_enabled(
    const uint8_t & _arg)
  {
    this->sweep_enabled = _arg;
    return *this;
  }
  Type & set__yaw_sign_inverted(
    const uint8_t & _arg)
  {
    this->yaw_sign_inverted = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::SmartCarCalibStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::SmartCarCalibStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::SmartCarCalibStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::SmartCarCalibStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarCalibStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarCalibStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarCalibStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarCalibStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::SmartCarCalibStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::SmartCarCalibStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__SmartCarCalibStatus
    std::shared_ptr<messages::msg::SmartCarCalibStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__SmartCarCalibStatus
    std::shared_ptr<messages::msg::SmartCarCalibStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartCarCalibStatus_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->time_boot_ms != other.time_boot_ms) {
      return false;
    }
    if (this->point_id != other.point_id) {
      return false;
    }
    if (this->sweep_index != other.sweep_index) {
      return false;
    }
    if (this->sweep_count != other.sweep_count) {
      return false;
    }
    if (this->valid_count != other.valid_count) {
      return false;
    }
    if (this->invalid_count != other.invalid_count) {
      return false;
    }
    if (this->v_center_avg != other.v_center_avg) {
      return false;
    }
    if (this->yaw_rate_avg != other.yaw_rate_avg) {
      return false;
    }
    if (this->kappa_avg != other.kappa_avg) {
      return false;
    }
    if (this->radius_est != other.radius_est) {
      return false;
    }
    if (this->target_rpm != other.target_rpm) {
      return false;
    }
    if (this->servo_pwm_us != other.servo_pwm_us) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->sweep_enabled != other.sweep_enabled) {
      return false;
    }
    if (this->yaw_sign_inverted != other.yaw_sign_inverted) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartCarCalibStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartCarCalibStatus_

// alias to use template instance with default allocator
using SmartCarCalibStatus =
  messages::msg::SmartCarCalibStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__STRUCT_HPP_
