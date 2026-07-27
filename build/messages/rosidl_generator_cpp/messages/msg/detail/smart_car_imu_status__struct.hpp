// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/SmartCarImuStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__STRUCT_HPP_

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
# define DEPRECATED__messages__msg__SmartCarImuStatus __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__SmartCarImuStatus __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SmartCarImuStatus_
{
  using Type = SmartCarImuStatus_<ContainerAllocator>;

  explicit SmartCarImuStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->sample_count = 0ul;
      this->overrun_count = 0ul;
      this->error_count = 0ul;
      this->gyro_x_mdps = 0l;
      this->gyro_y_mdps = 0l;
      this->gyro_z_mdps = 0l;
      this->yaw_rate_raw_dps = 0.0f;
      this->yaw_rate_dps = 0.0f;
      this->gyro_bias_z_dps = 0.0f;
      this->accel_x_mg = 0;
      this->accel_y_mg = 0;
      this->accel_z_mg = 0;
      this->temperature_c_x100 = 0;
      this->calibrated = 0;
    }
  }

  explicit SmartCarImuStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->time_boot_ms = 0ul;
      this->sample_count = 0ul;
      this->overrun_count = 0ul;
      this->error_count = 0ul;
      this->gyro_x_mdps = 0l;
      this->gyro_y_mdps = 0l;
      this->gyro_z_mdps = 0l;
      this->yaw_rate_raw_dps = 0.0f;
      this->yaw_rate_dps = 0.0f;
      this->gyro_bias_z_dps = 0.0f;
      this->accel_x_mg = 0;
      this->accel_y_mg = 0;
      this->accel_z_mg = 0;
      this->temperature_c_x100 = 0;
      this->calibrated = 0;
    }
  }

  // field types and members
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _time_boot_ms_type =
    uint32_t;
  _time_boot_ms_type time_boot_ms;
  using _sample_count_type =
    uint32_t;
  _sample_count_type sample_count;
  using _overrun_count_type =
    uint32_t;
  _overrun_count_type overrun_count;
  using _error_count_type =
    uint32_t;
  _error_count_type error_count;
  using _gyro_x_mdps_type =
    int32_t;
  _gyro_x_mdps_type gyro_x_mdps;
  using _gyro_y_mdps_type =
    int32_t;
  _gyro_y_mdps_type gyro_y_mdps;
  using _gyro_z_mdps_type =
    int32_t;
  _gyro_z_mdps_type gyro_z_mdps;
  using _yaw_rate_raw_dps_type =
    float;
  _yaw_rate_raw_dps_type yaw_rate_raw_dps;
  using _yaw_rate_dps_type =
    float;
  _yaw_rate_dps_type yaw_rate_dps;
  using _gyro_bias_z_dps_type =
    float;
  _gyro_bias_z_dps_type gyro_bias_z_dps;
  using _accel_x_mg_type =
    int16_t;
  _accel_x_mg_type accel_x_mg;
  using _accel_y_mg_type =
    int16_t;
  _accel_y_mg_type accel_y_mg;
  using _accel_z_mg_type =
    int16_t;
  _accel_z_mg_type accel_z_mg;
  using _temperature_c_x100_type =
    int16_t;
  _temperature_c_x100_type temperature_c_x100;
  using _calibrated_type =
    uint8_t;
  _calibrated_type calibrated;

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
  Type & set__sample_count(
    const uint32_t & _arg)
  {
    this->sample_count = _arg;
    return *this;
  }
  Type & set__overrun_count(
    const uint32_t & _arg)
  {
    this->overrun_count = _arg;
    return *this;
  }
  Type & set__error_count(
    const uint32_t & _arg)
  {
    this->error_count = _arg;
    return *this;
  }
  Type & set__gyro_x_mdps(
    const int32_t & _arg)
  {
    this->gyro_x_mdps = _arg;
    return *this;
  }
  Type & set__gyro_y_mdps(
    const int32_t & _arg)
  {
    this->gyro_y_mdps = _arg;
    return *this;
  }
  Type & set__gyro_z_mdps(
    const int32_t & _arg)
  {
    this->gyro_z_mdps = _arg;
    return *this;
  }
  Type & set__yaw_rate_raw_dps(
    const float & _arg)
  {
    this->yaw_rate_raw_dps = _arg;
    return *this;
  }
  Type & set__yaw_rate_dps(
    const float & _arg)
  {
    this->yaw_rate_dps = _arg;
    return *this;
  }
  Type & set__gyro_bias_z_dps(
    const float & _arg)
  {
    this->gyro_bias_z_dps = _arg;
    return *this;
  }
  Type & set__accel_x_mg(
    const int16_t & _arg)
  {
    this->accel_x_mg = _arg;
    return *this;
  }
  Type & set__accel_y_mg(
    const int16_t & _arg)
  {
    this->accel_y_mg = _arg;
    return *this;
  }
  Type & set__accel_z_mg(
    const int16_t & _arg)
  {
    this->accel_z_mg = _arg;
    return *this;
  }
  Type & set__temperature_c_x100(
    const int16_t & _arg)
  {
    this->temperature_c_x100 = _arg;
    return *this;
  }
  Type & set__calibrated(
    const uint8_t & _arg)
  {
    this->calibrated = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::SmartCarImuStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::SmartCarImuStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::SmartCarImuStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::SmartCarImuStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarImuStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarImuStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::SmartCarImuStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::SmartCarImuStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::SmartCarImuStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::SmartCarImuStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__SmartCarImuStatus
    std::shared_ptr<messages::msg::SmartCarImuStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__SmartCarImuStatus
    std::shared_ptr<messages::msg::SmartCarImuStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartCarImuStatus_ & other) const
  {
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->time_boot_ms != other.time_boot_ms) {
      return false;
    }
    if (this->sample_count != other.sample_count) {
      return false;
    }
    if (this->overrun_count != other.overrun_count) {
      return false;
    }
    if (this->error_count != other.error_count) {
      return false;
    }
    if (this->gyro_x_mdps != other.gyro_x_mdps) {
      return false;
    }
    if (this->gyro_y_mdps != other.gyro_y_mdps) {
      return false;
    }
    if (this->gyro_z_mdps != other.gyro_z_mdps) {
      return false;
    }
    if (this->yaw_rate_raw_dps != other.yaw_rate_raw_dps) {
      return false;
    }
    if (this->yaw_rate_dps != other.yaw_rate_dps) {
      return false;
    }
    if (this->gyro_bias_z_dps != other.gyro_bias_z_dps) {
      return false;
    }
    if (this->accel_x_mg != other.accel_x_mg) {
      return false;
    }
    if (this->accel_y_mg != other.accel_y_mg) {
      return false;
    }
    if (this->accel_z_mg != other.accel_z_mg) {
      return false;
    }
    if (this->temperature_c_x100 != other.temperature_c_x100) {
      return false;
    }
    if (this->calibrated != other.calibrated) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartCarImuStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartCarImuStatus_

// alias to use template instance with default allocator
using SmartCarImuStatus =
  messages::msg::SmartCarImuStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__STRUCT_HPP_
