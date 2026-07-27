// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/Vision.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__VISION__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__VISION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages__msg__Vision __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__Vision __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Vision_
{
  using Type = Vision_<ContainerAllocator>;

  explicit Vision_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_detected = false;
      this->center_x = 0l;
      this->center_y = 0l;
      this->center_x1_error = 0l;
      this->label = "";
    }
  }

  explicit Vision_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : label(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_detected = false;
      this->center_x = 0l;
      this->center_y = 0l;
      this->center_x1_error = 0l;
      this->label = "";
    }
  }

  // field types and members
  using _is_detected_type =
    bool;
  _is_detected_type is_detected;
  using _center_x_type =
    int32_t;
  _center_x_type center_x;
  using _center_y_type =
    int32_t;
  _center_y_type center_y;
  using _center_x1_error_type =
    int32_t;
  _center_x1_error_type center_x1_error;
  using _label_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _label_type label;

  // setters for named parameter idiom
  Type & set__is_detected(
    const bool & _arg)
  {
    this->is_detected = _arg;
    return *this;
  }
  Type & set__center_x(
    const int32_t & _arg)
  {
    this->center_x = _arg;
    return *this;
  }
  Type & set__center_y(
    const int32_t & _arg)
  {
    this->center_y = _arg;
    return *this;
  }
  Type & set__center_x1_error(
    const int32_t & _arg)
  {
    this->center_x1_error = _arg;
    return *this;
  }
  Type & set__label(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->label = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::Vision_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::Vision_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::Vision_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::Vision_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::Vision_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::Vision_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::Vision_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::Vision_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::Vision_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::Vision_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__Vision
    std::shared_ptr<messages::msg::Vision_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__Vision
    std::shared_ptr<messages::msg::Vision_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Vision_ & other) const
  {
    if (this->is_detected != other.is_detected) {
      return false;
    }
    if (this->center_x != other.center_x) {
      return false;
    }
    if (this->center_y != other.center_y) {
      return false;
    }
    if (this->center_x1_error != other.center_x1_error) {
      return false;
    }
    if (this->label != other.label) {
      return false;
    }
    return true;
  }
  bool operator!=(const Vision_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Vision_

// alias to use template instance with default allocator
using Vision =
  messages::msg::Vision_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__VISION__STRUCT_HPP_
