// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:msg/VisionMsg.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__VISION_MSG__STRUCT_HPP_
#define MESSAGES__MSG__DETAIL__VISION_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages__msg__VisionMsg __attribute__((deprecated))
#else
# define DEPRECATED__messages__msg__VisionMsg __declspec(deprecated)
#endif

namespace messages
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct VisionMsg_
{
  using Type = VisionMsg_<ContainerAllocator>;

  explicit VisionMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_line_detected = false;
      this->lateral_error = 0l;
      this->angle_error = 0.0f;
      this->is_square_detected = false;
      this->center_x1_error = 0l;
      this->center_y1_error = 0l;
      this->is_circle_detected = false;
      this->center_x2_error = 0l;
      this->center_y2_error = 0l;
    }
  }

  explicit VisionMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->is_line_detected = false;
      this->lateral_error = 0l;
      this->angle_error = 0.0f;
      this->is_square_detected = false;
      this->center_x1_error = 0l;
      this->center_y1_error = 0l;
      this->is_circle_detected = false;
      this->center_x2_error = 0l;
      this->center_y2_error = 0l;
    }
  }

  // field types and members
  using _is_line_detected_type =
    bool;
  _is_line_detected_type is_line_detected;
  using _lateral_error_type =
    int32_t;
  _lateral_error_type lateral_error;
  using _angle_error_type =
    float;
  _angle_error_type angle_error;
  using _is_square_detected_type =
    bool;
  _is_square_detected_type is_square_detected;
  using _center_x1_error_type =
    int32_t;
  _center_x1_error_type center_x1_error;
  using _center_y1_error_type =
    int32_t;
  _center_y1_error_type center_y1_error;
  using _is_circle_detected_type =
    bool;
  _is_circle_detected_type is_circle_detected;
  using _center_x2_error_type =
    int32_t;
  _center_x2_error_type center_x2_error;
  using _center_y2_error_type =
    int32_t;
  _center_y2_error_type center_y2_error;

  // setters for named parameter idiom
  Type & set__is_line_detected(
    const bool & _arg)
  {
    this->is_line_detected = _arg;
    return *this;
  }
  Type & set__lateral_error(
    const int32_t & _arg)
  {
    this->lateral_error = _arg;
    return *this;
  }
  Type & set__angle_error(
    const float & _arg)
  {
    this->angle_error = _arg;
    return *this;
  }
  Type & set__is_square_detected(
    const bool & _arg)
  {
    this->is_square_detected = _arg;
    return *this;
  }
  Type & set__center_x1_error(
    const int32_t & _arg)
  {
    this->center_x1_error = _arg;
    return *this;
  }
  Type & set__center_y1_error(
    const int32_t & _arg)
  {
    this->center_y1_error = _arg;
    return *this;
  }
  Type & set__is_circle_detected(
    const bool & _arg)
  {
    this->is_circle_detected = _arg;
    return *this;
  }
  Type & set__center_x2_error(
    const int32_t & _arg)
  {
    this->center_x2_error = _arg;
    return *this;
  }
  Type & set__center_y2_error(
    const int32_t & _arg)
  {
    this->center_y2_error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::msg::VisionMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::msg::VisionMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::msg::VisionMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::msg::VisionMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::msg::VisionMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::msg::VisionMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::msg::VisionMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::msg::VisionMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::msg::VisionMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::msg::VisionMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__msg__VisionMsg
    std::shared_ptr<messages::msg::VisionMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__msg__VisionMsg
    std::shared_ptr<messages::msg::VisionMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const VisionMsg_ & other) const
  {
    if (this->is_line_detected != other.is_line_detected) {
      return false;
    }
    if (this->lateral_error != other.lateral_error) {
      return false;
    }
    if (this->angle_error != other.angle_error) {
      return false;
    }
    if (this->is_square_detected != other.is_square_detected) {
      return false;
    }
    if (this->center_x1_error != other.center_x1_error) {
      return false;
    }
    if (this->center_y1_error != other.center_y1_error) {
      return false;
    }
    if (this->is_circle_detected != other.is_circle_detected) {
      return false;
    }
    if (this->center_x2_error != other.center_x2_error) {
      return false;
    }
    if (this->center_y2_error != other.center_y2_error) {
      return false;
    }
    return true;
  }
  bool operator!=(const VisionMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct VisionMsg_

// alias to use template instance with default allocator
using VisionMsg =
  messages::msg::VisionMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__VISION_MSG__STRUCT_HPP_
