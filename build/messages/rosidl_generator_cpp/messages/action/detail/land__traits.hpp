// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:action/Land.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__ACTION__DETAIL__LAND__TRAITS_HPP_
#define MESSAGES__ACTION__DETAIL__LAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/action/detail/land__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace messages
{

namespace action
{

inline void to_flow_style_yaml(
  const Land_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_id
  {
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << ", ";
  }

  // member: priority
  {
    out << "priority: ";
    rosidl_generator_traits::value_to_yaml(msg.priority, out);
    out << ", ";
  }

  // member: timeout_sec
  {
    out << "timeout_sec: ";
    rosidl_generator_traits::value_to_yaml(msg.timeout_sec, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Land_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << "\n";
  }

  // member: priority
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "priority: ";
    rosidl_generator_traits::value_to_yaml(msg.priority, out);
    out << "\n";
  }

  // member: timeout_sec
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timeout_sec: ";
    rosidl_generator_traits::value_to_yaml(msg.timeout_sec, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Land_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::action::Land_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::action::to_yaml() instead")]]
inline std::string to_yaml(const messages::action::Land_Goal & msg)
{
  return messages::action::to_yaml(msg);
}

template<>
inline const char * data_type<messages::action::Land_Goal>()
{
  return "messages::action::Land_Goal";
}

template<>
inline const char * name<messages::action::Land_Goal>()
{
  return "messages/action/Land_Goal";
}

template<>
struct has_fixed_size<messages::action::Land_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<messages::action::Land_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<messages::action::Land_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace messages
{

namespace action
{

inline void to_flow_style_yaml(
  const Land_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: final_state_code
  {
    out << "final_state_code: ";
    rosidl_generator_traits::value_to_yaml(msg.final_state_code, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: elapsed_sec
  {
    out << "elapsed_sec: ";
    rosidl_generator_traits::value_to_yaml(msg.elapsed_sec, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Land_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: final_state_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "final_state_code: ";
    rosidl_generator_traits::value_to_yaml(msg.final_state_code, out);
    out << "\n";
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: elapsed_sec
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "elapsed_sec: ";
    rosidl_generator_traits::value_to_yaml(msg.elapsed_sec, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Land_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::action::Land_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::action::to_yaml() instead")]]
inline std::string to_yaml(const messages::action::Land_Result & msg)
{
  return messages::action::to_yaml(msg);
}

template<>
inline const char * data_type<messages::action::Land_Result>()
{
  return "messages::action::Land_Result";
}

template<>
inline const char * name<messages::action::Land_Result>()
{
  return "messages/action/Land_Result";
}

template<>
struct has_fixed_size<messages::action::Land_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<messages::action::Land_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<messages::action::Land_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'current_twist'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace messages
{

namespace action
{

inline void to_flow_style_yaml(
  const Land_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_id
  {
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << ", ";
  }

  // member: priority
  {
    out << "priority: ";
    rosidl_generator_traits::value_to_yaml(msg.priority, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
    out << ", ";
  }

  // member: state_code
  {
    out << "state_code: ";
    rosidl_generator_traits::value_to_yaml(msg.state_code, out);
    out << ", ";
  }

  // member: error_code
  {
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: progress
  {
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << ", ";
  }

  // member: distance_error
  {
    out << "distance_error: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_error, out);
    out << ", ";
  }

  // member: yaw_error
  {
    out << "yaw_error: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_error, out);
    out << ", ";
  }

  // member: current_pose
  {
    out << "current_pose: ";
    to_flow_style_yaml(msg.current_pose, out);
    out << ", ";
  }

  // member: current_twist
  {
    out << "current_twist: ";
    to_flow_style_yaml(msg.current_twist, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Land_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << "\n";
  }

  // member: priority
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "priority: ";
    rosidl_generator_traits::value_to_yaml(msg.priority, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }

  // member: state_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_code: ";
    rosidl_generator_traits::value_to_yaml(msg.state_code, out);
    out << "\n";
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_code: ";
    rosidl_generator_traits::value_to_yaml(msg.error_code, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << "\n";
  }

  // member: distance_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance_error: ";
    rosidl_generator_traits::value_to_yaml(msg.distance_error, out);
    out << "\n";
  }

  // member: yaw_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_error: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_error, out);
    out << "\n";
  }

  // member: current_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_pose:\n";
    to_block_style_yaml(msg.current_pose, out, indentation + 2);
  }

  // member: current_twist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_twist:\n";
    to_block_style_yaml(msg.current_twist, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Land_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::action::Land_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::action::to_yaml() instead")]]
inline std::string to_yaml(const messages::action::Land_Feedback & msg)
{
  return messages::action::to_yaml(msg);
}

template<>
inline const char * data_type<messages::action::Land_Feedback>()
{
  return "messages::action::Land_Feedback";
}

template<>
inline const char * name<messages::action::Land_Feedback>()
{
  return "messages/action/Land_Feedback";
}

template<>
struct has_fixed_size<messages::action::Land_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<messages::action::Land_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<messages::action::Land_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "messages/action/detail/land__traits.hpp"

namespace messages
{

namespace action
{

inline void to_flow_style_yaml(
  const Land_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Land_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Land_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::action::Land_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::action::to_yaml() instead")]]
inline std::string to_yaml(const messages::action::Land_SendGoal_Request & msg)
{
  return messages::action::to_yaml(msg);
}

template<>
inline const char * data_type<messages::action::Land_SendGoal_Request>()
{
  return "messages::action::Land_SendGoal_Request";
}

template<>
inline const char * name<messages::action::Land_SendGoal_Request>()
{
  return "messages/action/Land_SendGoal_Request";
}

template<>
struct has_fixed_size<messages::action::Land_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<messages::action::Land_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<messages::action::Land_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<messages::action::Land_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<messages::action::Land_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
// already included above
// #include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace messages
{

namespace action
{

inline void to_flow_style_yaml(
  const Land_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Land_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Land_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::action::Land_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::action::to_yaml() instead")]]
inline std::string to_yaml(const messages::action::Land_SendGoal_Response & msg)
{
  return messages::action::to_yaml(msg);
}

template<>
inline const char * data_type<messages::action::Land_SendGoal_Response>()
{
  return "messages::action::Land_SendGoal_Response";
}

template<>
inline const char * name<messages::action::Land_SendGoal_Response>()
{
  return "messages/action/Land_SendGoal_Response";
}

template<>
struct has_fixed_size<messages::action::Land_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<messages::action::Land_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<messages::action::Land_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<messages::action::Land_SendGoal>()
{
  return "messages::action::Land_SendGoal";
}

template<>
inline const char * name<messages::action::Land_SendGoal>()
{
  return "messages/action/Land_SendGoal";
}

template<>
struct has_fixed_size<messages::action::Land_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<messages::action::Land_SendGoal_Request>::value &&
    has_fixed_size<messages::action::Land_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<messages::action::Land_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<messages::action::Land_SendGoal_Request>::value &&
    has_bounded_size<messages::action::Land_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<messages::action::Land_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<messages::action::Land_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<messages::action::Land_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace messages
{

namespace action
{

inline void to_flow_style_yaml(
  const Land_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Land_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Land_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::action::Land_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::action::to_yaml() instead")]]
inline std::string to_yaml(const messages::action::Land_GetResult_Request & msg)
{
  return messages::action::to_yaml(msg);
}

template<>
inline const char * data_type<messages::action::Land_GetResult_Request>()
{
  return "messages::action::Land_GetResult_Request";
}

template<>
inline const char * name<messages::action::Land_GetResult_Request>()
{
  return "messages/action/Land_GetResult_Request";
}

template<>
struct has_fixed_size<messages::action::Land_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<messages::action::Land_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<messages::action::Land_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "messages/action/detail/land__traits.hpp"

namespace messages
{

namespace action
{

inline void to_flow_style_yaml(
  const Land_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Land_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Land_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::action::Land_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::action::to_yaml() instead")]]
inline std::string to_yaml(const messages::action::Land_GetResult_Response & msg)
{
  return messages::action::to_yaml(msg);
}

template<>
inline const char * data_type<messages::action::Land_GetResult_Response>()
{
  return "messages::action::Land_GetResult_Response";
}

template<>
inline const char * name<messages::action::Land_GetResult_Response>()
{
  return "messages/action/Land_GetResult_Response";
}

template<>
struct has_fixed_size<messages::action::Land_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<messages::action::Land_Result>::value> {};

template<>
struct has_bounded_size<messages::action::Land_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<messages::action::Land_Result>::value> {};

template<>
struct is_message<messages::action::Land_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<messages::action::Land_GetResult>()
{
  return "messages::action::Land_GetResult";
}

template<>
inline const char * name<messages::action::Land_GetResult>()
{
  return "messages/action/Land_GetResult";
}

template<>
struct has_fixed_size<messages::action::Land_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<messages::action::Land_GetResult_Request>::value &&
    has_fixed_size<messages::action::Land_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<messages::action::Land_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<messages::action::Land_GetResult_Request>::value &&
    has_bounded_size<messages::action::Land_GetResult_Response>::value
  >
{
};

template<>
struct is_service<messages::action::Land_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<messages::action::Land_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<messages::action::Land_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "messages/action/detail/land__traits.hpp"

namespace messages
{

namespace action
{

inline void to_flow_style_yaml(
  const Land_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Land_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Land_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::action::Land_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::action::to_yaml() instead")]]
inline std::string to_yaml(const messages::action::Land_FeedbackMessage & msg)
{
  return messages::action::to_yaml(msg);
}

template<>
inline const char * data_type<messages::action::Land_FeedbackMessage>()
{
  return "messages::action::Land_FeedbackMessage";
}

template<>
inline const char * name<messages::action::Land_FeedbackMessage>()
{
  return "messages/action/Land_FeedbackMessage";
}

template<>
struct has_fixed_size<messages::action::Land_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<messages::action::Land_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<messages::action::Land_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<messages::action::Land_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<messages::action::Land_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<messages::action::Land>
  : std::true_type
{
};

template<>
struct is_action_goal<messages::action::Land_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<messages::action::Land_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<messages::action::Land_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // MESSAGES__ACTION__DETAIL__LAND__TRAITS_HPP_
