// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/SmartCarControlSetpoint.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/smart_car_control_setpoint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const SmartCarControlSetpoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << ", ";
  }

  // member: target_speed_mps
  {
    out << "target_speed_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.target_speed_mps, out);
    out << ", ";
  }

  // member: target_curvature
  {
    out << "target_curvature: ";
    rosidl_generator_traits::value_to_yaml(msg.target_curvature, out);
    out << ", ";
  }

  // member: target_yaw_rate_dps
  {
    out << "target_yaw_rate_dps: ";
    rosidl_generator_traits::value_to_yaml(msg.target_yaw_rate_dps, out);
    out << ", ";
  }

  // member: target_accel_mps2
  {
    out << "target_accel_mps2: ";
    rosidl_generator_traits::value_to_yaml(msg.target_accel_mps2, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SmartCarControlSetpoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << "\n";
  }

  // member: target_speed_mps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_speed_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.target_speed_mps, out);
    out << "\n";
  }

  // member: target_curvature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_curvature: ";
    rosidl_generator_traits::value_to_yaml(msg.target_curvature, out);
    out << "\n";
  }

  // member: target_yaw_rate_dps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_yaw_rate_dps: ";
    rosidl_generator_traits::value_to_yaml(msg.target_yaw_rate_dps, out);
    out << "\n";
  }

  // member: target_accel_mps2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_accel_mps2: ";
    rosidl_generator_traits::value_to_yaml(msg.target_accel_mps2, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SmartCarControlSetpoint & msg, bool use_flow_style = false)
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
  const messages::msg::SmartCarControlSetpoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::SmartCarControlSetpoint & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::SmartCarControlSetpoint>()
{
  return "messages::msg::SmartCarControlSetpoint";
}

template<>
inline const char * name<messages::msg::SmartCarControlSetpoint>()
{
  return "messages/msg/SmartCarControlSetpoint";
}

template<>
struct has_fixed_size<messages::msg::SmartCarControlSetpoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<messages::msg::SmartCarControlSetpoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<messages::msg::SmartCarControlSetpoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_CONTROL_SETPOINT__TRAITS_HPP_
