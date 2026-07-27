// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from messages:action/Takeoff.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__ACTION__DETAIL__TAKEOFF__STRUCT_HPP_
#define MESSAGES__ACTION__DETAIL__TAKEOFF__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__messages__action__Takeoff_Goal __attribute__((deprecated))
#else
# define DEPRECATED__messages__action__Takeoff_Goal __declspec(deprecated)
#endif

namespace messages
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Takeoff_Goal_
{
  using Type = Takeoff_Goal_<ContainerAllocator>;

  explicit Takeoff_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_id = "";
      this->priority = 0;
      this->target_altitude = 0.0f;
      this->timeout_sec = 0.0f;
    }
  }

  explicit Takeoff_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_id = "";
      this->priority = 0;
      this->target_altitude = 0.0f;
      this->timeout_sec = 0.0f;
    }
  }

  // field types and members
  using _task_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _task_id_type task_id;
  using _priority_type =
    uint8_t;
  _priority_type priority;
  using _target_altitude_type =
    float;
  _target_altitude_type target_altitude;
  using _timeout_sec_type =
    float;
  _timeout_sec_type timeout_sec;

  // setters for named parameter idiom
  Type & set__task_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->task_id = _arg;
    return *this;
  }
  Type & set__priority(
    const uint8_t & _arg)
  {
    this->priority = _arg;
    return *this;
  }
  Type & set__target_altitude(
    const float & _arg)
  {
    this->target_altitude = _arg;
    return *this;
  }
  Type & set__timeout_sec(
    const float & _arg)
  {
    this->timeout_sec = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::action::Takeoff_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::action::Takeoff_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::action::Takeoff_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::action::Takeoff_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::action::Takeoff_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::action::Takeoff_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__action__Takeoff_Goal
    std::shared_ptr<messages::action::Takeoff_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__action__Takeoff_Goal
    std::shared_ptr<messages::action::Takeoff_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Takeoff_Goal_ & other) const
  {
    if (this->task_id != other.task_id) {
      return false;
    }
    if (this->priority != other.priority) {
      return false;
    }
    if (this->target_altitude != other.target_altitude) {
      return false;
    }
    if (this->timeout_sec != other.timeout_sec) {
      return false;
    }
    return true;
  }
  bool operator!=(const Takeoff_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Takeoff_Goal_

// alias to use template instance with default allocator
using Takeoff_Goal =
  messages::action::Takeoff_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace messages


#ifndef _WIN32
# define DEPRECATED__messages__action__Takeoff_Result __attribute__((deprecated))
#else
# define DEPRECATED__messages__action__Takeoff_Result __declspec(deprecated)
#endif

namespace messages
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Takeoff_Result_
{
  using Type = Takeoff_Result_<ContainerAllocator>;

  explicit Takeoff_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->final_state_code = 0;
      this->error_code = 0;
      this->message = "";
      this->elapsed_sec = 0.0f;
    }
  }

  explicit Takeoff_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->final_state_code = 0;
      this->error_code = 0;
      this->message = "";
      this->elapsed_sec = 0.0f;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _final_state_code_type =
    uint8_t;
  _final_state_code_type final_state_code;
  using _error_code_type =
    uint16_t;
  _error_code_type error_code;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _elapsed_sec_type =
    float;
  _elapsed_sec_type elapsed_sec;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__final_state_code(
    const uint8_t & _arg)
  {
    this->final_state_code = _arg;
    return *this;
  }
  Type & set__error_code(
    const uint16_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__elapsed_sec(
    const float & _arg)
  {
    this->elapsed_sec = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::action::Takeoff_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::action::Takeoff_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::action::Takeoff_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::action::Takeoff_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::action::Takeoff_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::action::Takeoff_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__action__Takeoff_Result
    std::shared_ptr<messages::action::Takeoff_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__action__Takeoff_Result
    std::shared_ptr<messages::action::Takeoff_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Takeoff_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->final_state_code != other.final_state_code) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->elapsed_sec != other.elapsed_sec) {
      return false;
    }
    return true;
  }
  bool operator!=(const Takeoff_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Takeoff_Result_

// alias to use template instance with default allocator
using Takeoff_Result =
  messages::action::Takeoff_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace messages


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'current_twist'
#include "geometry_msgs/msg/detail/twist__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__messages__action__Takeoff_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__messages__action__Takeoff_Feedback __declspec(deprecated)
#endif

namespace messages
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Takeoff_Feedback_
{
  using Type = Takeoff_Feedback_<ContainerAllocator>;

  explicit Takeoff_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init),
    current_pose(_init),
    current_twist(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_id = "";
      this->priority = 0;
      this->state_code = 0;
      this->error_code = 0;
      this->message = "";
      this->progress = 0.0f;
      this->distance_error = 0.0f;
      this->yaw_error = 0.0f;
    }
  }

  explicit Takeoff_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task_id(_alloc),
    stamp(_alloc, _init),
    message(_alloc),
    current_pose(_alloc, _init),
    current_twist(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_id = "";
      this->priority = 0;
      this->state_code = 0;
      this->error_code = 0;
      this->message = "";
      this->progress = 0.0f;
      this->distance_error = 0.0f;
      this->yaw_error = 0.0f;
    }
  }

  // field types and members
  using _task_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _task_id_type task_id;
  using _priority_type =
    uint8_t;
  _priority_type priority;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;
  using _state_code_type =
    uint8_t;
  _state_code_type state_code;
  using _error_code_type =
    uint16_t;
  _error_code_type error_code;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _progress_type =
    float;
  _progress_type progress;
  using _distance_error_type =
    float;
  _distance_error_type distance_error;
  using _yaw_error_type =
    float;
  _yaw_error_type yaw_error;
  using _current_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _current_pose_type current_pose;
  using _current_twist_type =
    geometry_msgs::msg::Twist_<ContainerAllocator>;
  _current_twist_type current_twist;

  // setters for named parameter idiom
  Type & set__task_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->task_id = _arg;
    return *this;
  }
  Type & set__priority(
    const uint8_t & _arg)
  {
    this->priority = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }
  Type & set__state_code(
    const uint8_t & _arg)
  {
    this->state_code = _arg;
    return *this;
  }
  Type & set__error_code(
    const uint16_t & _arg)
  {
    this->error_code = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__progress(
    const float & _arg)
  {
    this->progress = _arg;
    return *this;
  }
  Type & set__distance_error(
    const float & _arg)
  {
    this->distance_error = _arg;
    return *this;
  }
  Type & set__yaw_error(
    const float & _arg)
  {
    this->yaw_error = _arg;
    return *this;
  }
  Type & set__current_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->current_pose = _arg;
    return *this;
  }
  Type & set__current_twist(
    const geometry_msgs::msg::Twist_<ContainerAllocator> & _arg)
  {
    this->current_twist = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::action::Takeoff_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::action::Takeoff_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::action::Takeoff_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::action::Takeoff_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::action::Takeoff_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::action::Takeoff_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__action__Takeoff_Feedback
    std::shared_ptr<messages::action::Takeoff_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__action__Takeoff_Feedback
    std::shared_ptr<messages::action::Takeoff_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Takeoff_Feedback_ & other) const
  {
    if (this->task_id != other.task_id) {
      return false;
    }
    if (this->priority != other.priority) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    if (this->state_code != other.state_code) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->progress != other.progress) {
      return false;
    }
    if (this->distance_error != other.distance_error) {
      return false;
    }
    if (this->yaw_error != other.yaw_error) {
      return false;
    }
    if (this->current_pose != other.current_pose) {
      return false;
    }
    if (this->current_twist != other.current_twist) {
      return false;
    }
    return true;
  }
  bool operator!=(const Takeoff_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Takeoff_Feedback_

// alias to use template instance with default allocator
using Takeoff_Feedback =
  messages::action::Takeoff_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace messages


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "messages/action/detail/takeoff__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__messages__action__Takeoff_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__messages__action__Takeoff_SendGoal_Request __declspec(deprecated)
#endif

namespace messages
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Takeoff_SendGoal_Request_
{
  using Type = Takeoff_SendGoal_Request_<ContainerAllocator>;

  explicit Takeoff_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit Takeoff_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    messages::action::Takeoff_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const messages::action::Takeoff_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::action::Takeoff_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::action::Takeoff_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::action::Takeoff_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::action::Takeoff_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::action::Takeoff_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::action::Takeoff_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__action__Takeoff_SendGoal_Request
    std::shared_ptr<messages::action::Takeoff_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__action__Takeoff_SendGoal_Request
    std::shared_ptr<messages::action::Takeoff_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Takeoff_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const Takeoff_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Takeoff_SendGoal_Request_

// alias to use template instance with default allocator
using Takeoff_SendGoal_Request =
  messages::action::Takeoff_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace messages


// Include directives for member types
// Member 'stamp'
// already included above
// #include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__messages__action__Takeoff_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__messages__action__Takeoff_SendGoal_Response __declspec(deprecated)
#endif

namespace messages
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Takeoff_SendGoal_Response_
{
  using Type = Takeoff_SendGoal_Response_<ContainerAllocator>;

  explicit Takeoff_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit Takeoff_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::action::Takeoff_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::action::Takeoff_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::action::Takeoff_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::action::Takeoff_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::action::Takeoff_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::action::Takeoff_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__action__Takeoff_SendGoal_Response
    std::shared_ptr<messages::action::Takeoff_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__action__Takeoff_SendGoal_Response
    std::shared_ptr<messages::action::Takeoff_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Takeoff_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const Takeoff_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Takeoff_SendGoal_Response_

// alias to use template instance with default allocator
using Takeoff_SendGoal_Response =
  messages::action::Takeoff_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace messages

namespace messages
{

namespace action
{

struct Takeoff_SendGoal
{
  using Request = messages::action::Takeoff_SendGoal_Request;
  using Response = messages::action::Takeoff_SendGoal_Response;
};

}  // namespace action

}  // namespace messages


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__messages__action__Takeoff_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__messages__action__Takeoff_GetResult_Request __declspec(deprecated)
#endif

namespace messages
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Takeoff_GetResult_Request_
{
  using Type = Takeoff_GetResult_Request_<ContainerAllocator>;

  explicit Takeoff_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit Takeoff_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::action::Takeoff_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::action::Takeoff_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::action::Takeoff_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::action::Takeoff_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::action::Takeoff_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::action::Takeoff_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__action__Takeoff_GetResult_Request
    std::shared_ptr<messages::action::Takeoff_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__action__Takeoff_GetResult_Request
    std::shared_ptr<messages::action::Takeoff_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Takeoff_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const Takeoff_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Takeoff_GetResult_Request_

// alias to use template instance with default allocator
using Takeoff_GetResult_Request =
  messages::action::Takeoff_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace messages


// Include directives for member types
// Member 'result'
// already included above
// #include "messages/action/detail/takeoff__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__messages__action__Takeoff_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__messages__action__Takeoff_GetResult_Response __declspec(deprecated)
#endif

namespace messages
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Takeoff_GetResult_Response_
{
  using Type = Takeoff_GetResult_Response_<ContainerAllocator>;

  explicit Takeoff_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit Takeoff_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    messages::action::Takeoff_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const messages::action::Takeoff_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::action::Takeoff_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::action::Takeoff_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::action::Takeoff_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::action::Takeoff_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::action::Takeoff_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::action::Takeoff_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__action__Takeoff_GetResult_Response
    std::shared_ptr<messages::action::Takeoff_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__action__Takeoff_GetResult_Response
    std::shared_ptr<messages::action::Takeoff_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Takeoff_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Takeoff_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Takeoff_GetResult_Response_

// alias to use template instance with default allocator
using Takeoff_GetResult_Response =
  messages::action::Takeoff_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace messages

namespace messages
{

namespace action
{

struct Takeoff_GetResult
{
  using Request = messages::action::Takeoff_GetResult_Request;
  using Response = messages::action::Takeoff_GetResult_Response;
};

}  // namespace action

}  // namespace messages


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "messages/action/detail/takeoff__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__messages__action__Takeoff_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__messages__action__Takeoff_FeedbackMessage __declspec(deprecated)
#endif

namespace messages
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct Takeoff_FeedbackMessage_
{
  using Type = Takeoff_FeedbackMessage_<ContainerAllocator>;

  explicit Takeoff_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit Takeoff_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    messages::action::Takeoff_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const messages::action::Takeoff_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    messages::action::Takeoff_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const messages::action::Takeoff_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<messages::action::Takeoff_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<messages::action::Takeoff_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      messages::action::Takeoff_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<messages::action::Takeoff_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<messages::action::Takeoff_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<messages::action::Takeoff_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__messages__action__Takeoff_FeedbackMessage
    std::shared_ptr<messages::action::Takeoff_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__messages__action__Takeoff_FeedbackMessage
    std::shared_ptr<messages::action::Takeoff_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Takeoff_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const Takeoff_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Takeoff_FeedbackMessage_

// alias to use template instance with default allocator
using Takeoff_FeedbackMessage =
  messages::action::Takeoff_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace messages

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace messages
{

namespace action
{

struct Takeoff
{
  /// The goal message defined in the action definition.
  using Goal = messages::action::Takeoff_Goal;
  /// The result message defined in the action definition.
  using Result = messages::action::Takeoff_Result;
  /// The feedback message defined in the action definition.
  using Feedback = messages::action::Takeoff_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = messages::action::Takeoff_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = messages::action::Takeoff_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = messages::action::Takeoff_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct Takeoff Takeoff;

}  // namespace action

}  // namespace messages

#endif  // MESSAGES__ACTION__DETAIL__TAKEOFF__STRUCT_HPP_
