// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_tools:msg/LidarPose.idl
// generated code does not contain a copyright notice

#ifndef ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__STRUCT_HPP_
#define ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_tools__msg__LidarPose __attribute__((deprecated))
#else
# define DEPRECATED__ros2_tools__msg__LidarPose __declspec(deprecated)
#endif

namespace ros2_tools
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct LidarPose_
{
  using Type = LidarPose_<ContainerAllocator>;

  explicit LidarPose_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  explicit LidarPose_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->roll = 0.0;
      this->pitch = 0.0;
      this->yaw = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _roll_type =
    double;
  _roll_type roll;
  using _pitch_type =
    double;
  _pitch_type pitch;
  using _yaw_type =
    double;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__roll(
    const double & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const double & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const double & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_tools::msg::LidarPose_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_tools::msg::LidarPose_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_tools::msg::LidarPose_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_tools::msg::LidarPose_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_tools::msg::LidarPose_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_tools::msg::LidarPose_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_tools::msg::LidarPose_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_tools::msg::LidarPose_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_tools::msg::LidarPose_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_tools::msg::LidarPose_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_tools__msg__LidarPose
    std::shared_ptr<ros2_tools::msg::LidarPose_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_tools__msg__LidarPose
    std::shared_ptr<ros2_tools::msg::LidarPose_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LidarPose_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const LidarPose_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LidarPose_

// alias to use template instance with default allocator
using LidarPose =
  ros2_tools::msg::LidarPose_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2_tools

#endif  // ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__STRUCT_HPP_
