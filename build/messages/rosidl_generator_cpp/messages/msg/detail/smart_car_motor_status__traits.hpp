// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/SmartCarMotorStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/smart_car_motor_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const SmartCarMotorStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
    out << ", ";
  }

  // member: time_boot_ms
  {
    out << "time_boot_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.time_boot_ms, out);
    out << ", ";
  }

  // member: target_rpm_1
  {
    out << "target_rpm_1: ";
    rosidl_generator_traits::value_to_yaml(msg.target_rpm_1, out);
    out << ", ";
  }

  // member: target_rpm_2
  {
    out << "target_rpm_2: ";
    rosidl_generator_traits::value_to_yaml(msg.target_rpm_2, out);
    out << ", ";
  }

  // member: actual_rpm_1
  {
    out << "actual_rpm_1: ";
    rosidl_generator_traits::value_to_yaml(msg.actual_rpm_1, out);
    out << ", ";
  }

  // member: actual_rpm_2
  {
    out << "actual_rpm_2: ";
    rosidl_generator_traits::value_to_yaml(msg.actual_rpm_2, out);
    out << ", ";
  }

  // member: current_cmd_1
  {
    out << "current_cmd_1: ";
    rosidl_generator_traits::value_to_yaml(msg.current_cmd_1, out);
    out << ", ";
  }

  // member: current_cmd_2
  {
    out << "current_cmd_2: ";
    rosidl_generator_traits::value_to_yaml(msg.current_cmd_2, out);
    out << ", ";
  }

  // member: feedback_current_1
  {
    out << "feedback_current_1: ";
    rosidl_generator_traits::value_to_yaml(msg.feedback_current_1, out);
    out << ", ";
  }

  // member: feedback_current_2
  {
    out << "feedback_current_2: ";
    rosidl_generator_traits::value_to_yaml(msg.feedback_current_2, out);
    out << ", ";
  }

  // member: angle_1
  {
    out << "angle_1: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_1, out);
    out << ", ";
  }

  // member: angle_2
  {
    out << "angle_2: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_2, out);
    out << ", ";
  }

  // member: online_mask
  {
    out << "online_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.online_mask, out);
    out << ", ";
  }

  // member: can_tx_busy_count
  {
    out << "can_tx_busy_count: ";
    rosidl_generator_traits::value_to_yaml(msg.can_tx_busy_count, out);
    out << ", ";
  }

  // member: can_error_count
  {
    out << "can_error_count: ";
    rosidl_generator_traits::value_to_yaml(msg.can_error_count, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SmartCarMotorStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }

  // member: time_boot_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_boot_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.time_boot_ms, out);
    out << "\n";
  }

  // member: target_rpm_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_rpm_1: ";
    rosidl_generator_traits::value_to_yaml(msg.target_rpm_1, out);
    out << "\n";
  }

  // member: target_rpm_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_rpm_2: ";
    rosidl_generator_traits::value_to_yaml(msg.target_rpm_2, out);
    out << "\n";
  }

  // member: actual_rpm_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "actual_rpm_1: ";
    rosidl_generator_traits::value_to_yaml(msg.actual_rpm_1, out);
    out << "\n";
  }

  // member: actual_rpm_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "actual_rpm_2: ";
    rosidl_generator_traits::value_to_yaml(msg.actual_rpm_2, out);
    out << "\n";
  }

  // member: current_cmd_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_cmd_1: ";
    rosidl_generator_traits::value_to_yaml(msg.current_cmd_1, out);
    out << "\n";
  }

  // member: current_cmd_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_cmd_2: ";
    rosidl_generator_traits::value_to_yaml(msg.current_cmd_2, out);
    out << "\n";
  }

  // member: feedback_current_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback_current_1: ";
    rosidl_generator_traits::value_to_yaml(msg.feedback_current_1, out);
    out << "\n";
  }

  // member: feedback_current_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback_current_2: ";
    rosidl_generator_traits::value_to_yaml(msg.feedback_current_2, out);
    out << "\n";
  }

  // member: angle_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_1: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_1, out);
    out << "\n";
  }

  // member: angle_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_2: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_2, out);
    out << "\n";
  }

  // member: online_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "online_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.online_mask, out);
    out << "\n";
  }

  // member: can_tx_busy_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "can_tx_busy_count: ";
    rosidl_generator_traits::value_to_yaml(msg.can_tx_busy_count, out);
    out << "\n";
  }

  // member: can_error_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "can_error_count: ";
    rosidl_generator_traits::value_to_yaml(msg.can_error_count, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SmartCarMotorStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::msg::SmartCarMotorStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::SmartCarMotorStatus & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::SmartCarMotorStatus>()
{
  return "messages::msg::SmartCarMotorStatus";
}

template<>
inline const char * name<messages::msg::SmartCarMotorStatus>()
{
  return "messages/msg/SmartCarMotorStatus";
}

template<>
struct has_fixed_size<messages::msg::SmartCarMotorStatus>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<messages::msg::SmartCarMotorStatus>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<messages::msg::SmartCarMotorStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_MOTOR_STATUS__TRAITS_HPP_
