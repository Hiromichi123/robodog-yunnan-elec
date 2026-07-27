// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:srv/SmartCarCommand.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__STRUCT_HPP_
#define MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages__srv__SmartCarCommand_Request __attribute__((deprecated))
#else
# define DEPRECATED__messages__srv__SmartCarCommand_Request __declspec(deprecated)
#endif

namespace messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SmartCarCommand_Request_
{
  using Type = SmartCarCommand_Request_<ContainerAllocator>;

  explicit SmartCarCommand_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->param1 = 0.0f;
      this->param2 = 0.0f;
      this->param3 = 0.0f;
      this->param4 = 0.0f;
    }
  }

  explicit SmartCarCommand_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = 0;
      this->param1 = 0.0f;
      this->param2 = 0.0f;
      this->param3 = 0.0f;
      this->param4 = 0.0f;
    }
  }

  // field types and members
  using _command_type =
    uint16_t;
  _command_type command;
  using _param1_type =
    float;
  _param1_type param1;
  using _param2_type =
    float;
  _param2_type param2;
  using _param3_type =
    float;
  _param3_type param3;
  using _param4_type =
    float;
  _param4_type param4;

  // setters for named parameter idiom
  Type & set__command(
    const uint16_t & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__param1(
    const float & _arg)
  {
    this->param1 = _arg;
    return *this;
  }
  Type & set__param2(
    const float & _arg)
  {
    this->param2 = _arg;
    return *this;
  }
  Type & set__param3(
    const float & _arg)
  {
    this->param3 = _arg;
    return *this;
  }
  Type & set__param4(
    const float & _arg)
  {
    this->param4 = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint16_t SMART_CAR_COMMAND_ENABLE =
    1u;
  static constexpr uint16_t SMART_CAR_COMMAND_DISABLE =
    2u;
  static constexpr uint16_t SMART_CAR_COMMAND_STOP =
    3u;
  static constexpr uint16_t SMART_CAR_COMMAND_RECENTER_SERVO =
    4u;
  static constexpr uint16_t SMART_CAR_COMMAND_GYRO_CAL =
    5u;
  static constexpr uint16_t SMART_CAR_COMMAND_CLEAR_FAULTS =
    6u;
  static constexpr uint16_t SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT =
    7u;
  static constexpr uint16_t SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT =
    8u;
  static constexpr uint16_t SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT =
    9u;
  static constexpr uint16_t SMART_CAR_COMMAND_STOP_CURVATURE_CAL =
    10u;
  static constexpr uint16_t SMART_CAR_COMMAND_FIREWATER_OFF =
    11u;

  // pointer types
  using RawPtr =
    messages::srv::SmartCarCommand_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::srv::SmartCarCommand_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::srv::SmartCarCommand_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::srv::SmartCarCommand_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::srv::SmartCarCommand_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::srv::SmartCarCommand_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::srv::SmartCarCommand_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::srv::SmartCarCommand_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::srv::SmartCarCommand_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::srv::SmartCarCommand_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__srv__SmartCarCommand_Request
    std::shared_ptr<messages::srv::SmartCarCommand_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__srv__SmartCarCommand_Request
    std::shared_ptr<messages::srv::SmartCarCommand_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartCarCommand_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->param1 != other.param1) {
      return false;
    }
    if (this->param2 != other.param2) {
      return false;
    }
    if (this->param3 != other.param3) {
      return false;
    }
    if (this->param4 != other.param4) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartCarCommand_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartCarCommand_Request_

// alias to use template instance with default allocator
using SmartCarCommand_Request =
  messages::srv::SmartCarCommand_Request_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_ENABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_DISABLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_STOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_RECENTER_SERVO;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_GYRO_CAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_CLEAR_FAULTS;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_STOP_CURVATURE_CAL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint16_t SmartCarCommand_Request_<ContainerAllocator>::SMART_CAR_COMMAND_FIREWATER_OFF;
#endif  // __cplusplus < 201703L

}  // namespace srv

}  // namespace messages


#ifndef _WIN32
# define DEPRECATED__messages__srv__SmartCarCommand_Response __attribute__((deprecated))
#else
# define DEPRECATED__messages__srv__SmartCarCommand_Response __declspec(deprecated)
#endif

namespace messages
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SmartCarCommand_Response_
{
  using Type = SmartCarCommand_Response_<ContainerAllocator>;

  explicit SmartCarCommand_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->message = "";
    }
  }

  explicit SmartCarCommand_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->message = "";
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::srv::SmartCarCommand_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::srv::SmartCarCommand_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::srv::SmartCarCommand_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::srv::SmartCarCommand_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::srv::SmartCarCommand_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::srv::SmartCarCommand_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::srv::SmartCarCommand_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::srv::SmartCarCommand_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::srv::SmartCarCommand_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::srv::SmartCarCommand_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__srv__SmartCarCommand_Response
    std::shared_ptr<messages::srv::SmartCarCommand_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__srv__SmartCarCommand_Response
    std::shared_ptr<messages::srv::SmartCarCommand_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SmartCarCommand_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SmartCarCommand_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SmartCarCommand_Response_

// alias to use template instance with default allocator
using SmartCarCommand_Response =
  messages::srv::SmartCarCommand_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace messages

namespace messages
{

namespace srv
{

struct SmartCarCommand
{
  using Request = messages::srv::SmartCarCommand_Request;
  using Response = messages::srv::SmartCarCommand_Response;
};

}  // namespace srv

}  // namespace messages

#endif  // MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__STRUCT_HPP_
