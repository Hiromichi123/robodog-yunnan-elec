// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/SmartCarStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/smart_car_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const SmartCarStatus & msg,
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

  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: fault_flags
  {
    out << "fault_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_flags, out);
    out << ", ";
  }

  // member: warn_flags
  {
    out << "warn_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.warn_flags, out);
    out << ", ";
  }

  // member: cmd_age_ms
  {
    out << "cmd_age_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_age_ms, out);
    out << ", ";
  }

  // member: control_loop_hz
  {
    out << "control_loop_hz: ";
    rosidl_generator_traits::value_to_yaml(msg.control_loop_hz, out);
    out << ", ";
  }

  // member: imu_online
  {
    out << "imu_online: ";
    rosidl_generator_traits::value_to_yaml(msg.imu_online, out);
    out << ", ";
  }

  // member: can_online
  {
    out << "can_online: ";
    rosidl_generator_traits::value_to_yaml(msg.can_online, out);
    out << ", ";
  }

  // member: host_online
  {
    out << "host_online: ";
    rosidl_generator_traits::value_to_yaml(msg.host_online, out);
    out << ", ";
  }

  // member: servo_online
  {
    out << "servo_online: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_online, out);
    out << ", ";
  }

  // member: motor_online_mask
  {
    out << "motor_online_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_online_mask, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SmartCarStatus & msg,
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

  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: fault_flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fault_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_flags, out);
    out << "\n";
  }

  // member: warn_flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "warn_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.warn_flags, out);
    out << "\n";
  }

  // member: cmd_age_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd_age_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd_age_ms, out);
    out << "\n";
  }

  // member: control_loop_hz
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "control_loop_hz: ";
    rosidl_generator_traits::value_to_yaml(msg.control_loop_hz, out);
    out << "\n";
  }

  // member: imu_online
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "imu_online: ";
    rosidl_generator_traits::value_to_yaml(msg.imu_online, out);
    out << "\n";
  }

  // member: can_online
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "can_online: ";
    rosidl_generator_traits::value_to_yaml(msg.can_online, out);
    out << "\n";
  }

  // member: host_online
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "host_online: ";
    rosidl_generator_traits::value_to_yaml(msg.host_online, out);
    out << "\n";
  }

  // member: servo_online
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_online: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_online, out);
    out << "\n";
  }

  // member: motor_online_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_online_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_online_mask, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SmartCarStatus & msg, bool use_flow_style = false)
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
  const messages::msg::SmartCarStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::SmartCarStatus & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::SmartCarStatus>()
{
  return "messages::msg::SmartCarStatus";
}

template<>
inline const char * name<messages::msg::SmartCarStatus>()
{
  return "messages/msg/SmartCarStatus";
}

template<>
struct has_fixed_size<messages::msg::SmartCarStatus>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<messages::msg::SmartCarStatus>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<messages::msg::SmartCarStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_STATUS__TRAITS_HPP_
