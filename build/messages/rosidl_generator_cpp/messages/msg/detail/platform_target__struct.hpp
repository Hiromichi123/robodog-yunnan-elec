// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/PlatformTarget.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__PLATFORM_TARGET__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__PLATFORM_TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages__msg__PlatformTarget __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__PlatformTarget __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PlatformTarget_
{
  using Type = PlatformTarget_<ContainerAllocator>;

  explicit PlatformTarget_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->platform = 0;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->yaw = 0.0f;
      this->vx_mps = 0.0f;
      this->vy_mps = 0.0f;
      this->vz_mps = 0.0f;
      this->speed_mps = 0.0f;
      this->curvature = 0.0f;
      this->yaw_rate_dps = 0.0f;
    }
  }

  explicit PlatformTarget_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->platform = 0;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->yaw = 0.0f;
      this->vx_mps = 0.0f;
      this->vy_mps = 0.0f;
      this->vz_mps = 0.0f;
      this->speed_mps = 0.0f;
      this->curvature = 0.0f;
      this->yaw_rate_dps = 0.0f;
    }
  }

  // field types and members
  using _platform_type =
    uint8_t;
  _platform_type platform;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _yaw_type =
    float;
  _yaw_type yaw;
  using _vx_mps_type =
    float;
  _vx_mps_type vx_mps;
  using _vy_mps_type =
    float;
  _vy_mps_type vy_mps;
  using _vz_mps_type =
    float;
  _vz_mps_type vz_mps;
  using _speed_mps_type =
    float;
  _speed_mps_type speed_mps;
  using _curvature_type =
    float;
  _curvature_type curvature;
  using _yaw_rate_dps_type =
    float;
  _yaw_rate_dps_type yaw_rate_dps;

  // setters for named parameter idiom
  Type & set__platform(
    const uint8_t & _arg)
  {
    this->platform = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__vx_mps(
    const float & _arg)
  {
    this->vx_mps = _arg;
    return *this;
  }
  Type & set__vy_mps(
    const float & _arg)
  {
    this->vy_mps = _arg;
    return *this;
  }
  Type & set__vz_mps(
    const float & _arg)
  {
    this->vz_mps = _arg;
    return *this;
  }
  Type & set__speed_mps(
    const float & _arg)
  {
    this->speed_mps = _arg;
    return *this;
  }
  Type & set__curvature(
    const float & _arg)
  {
    this->curvature = _arg;
    return *this;
  }
  Type & set__yaw_rate_dps(
    const float & _arg)
  {
    this->yaw_rate_dps = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t PLATFORM_CAR =
    0u;
  static constexpr uint8_t PLATFORM_FLIGHT =
    1u;

  // pointer types
  using RawPtr =
    messages::msg::PlatformTarget_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::PlatformTarget_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::PlatformTarget_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::PlatformTarget_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::PlatformTarget_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::PlatformTarget_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::PlatformTarget_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::PlatformTarget_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::PlatformTarget_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::PlatformTarget_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__PlatformTarget
    std::shared_ptr<messages::msg::PlatformTarget_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__PlatformTarget
    std::shared_ptr<messages::msg::PlatformTarget_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlatformTarget_ & other) const
  {
    if (this->platform != other.platform) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->vx_mps != other.vx_mps) {
      return false;
    }
    if (this->vy_mps != other.vy_mps) {
      return false;
    }
    if (this->vz_mps != other.vz_mps) {
      return false;
    }
    if (this->speed_mps != other.speed_mps) {
      return false;
    }
    if (this->curvature != other.curvature) {
      return false;
    }
    if (this->yaw_rate_dps != other.yaw_rate_dps) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlatformTarget_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlatformTarget_

// alias to use template instance with default allocator
using PlatformTarget =
  messages::msg::PlatformTarget_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PlatformTarget_<ContainerAllocator>::PLATFORM_CAR;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t PlatformTarget_<ContainerAllocator>::PLATFORM_FLIGHT;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__PLATFORM_TARGET__STRUCT_HPP_
