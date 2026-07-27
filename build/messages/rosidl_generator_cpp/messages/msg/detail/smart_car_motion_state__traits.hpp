// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/SmartCarMotionState.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/smart_car_motion_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const SmartCarMotionState & msg,
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

  // member: speed_mps
  {
    out << "speed_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_mps, out);
    out << ", ";
  }

  // member: target_speed_mps
  {
    out << "target_speed_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.target_speed_mps, out);
    out << ", ";
  }

  // member: yaw_rate_dps
  {
    out << "yaw_rate_dps: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_rate_dps, out);
    out << ", ";
  }

  // member: yaw_deg
  {
    out << "yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_deg, out);
    out << ", ";
  }

  // member: curvature_meas
  {
    out << "curvature_meas: ";
    rosidl_generator_traits::value_to_yaml(msg.curvature_meas, out);
    out << ", ";
  }

  // member: curvature_cmd
  {
    out << "curvature_cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.curvature_cmd, out);
    out << ", ";
  }

  // member: steering_angle_deg
  {
    out << "steering_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_angle_deg, out);
    out << ", ";
  }

  // member: steering_pwm_us
  {
    out << "steering_pwm_us: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_pwm_us, out);
    out << ", ";
  }

  // member: steering_clamped
  {
    out << "steering_clamped: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_clamped, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SmartCarMotionState & msg,
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

  // member: speed_mps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_mps, out);
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

  // member: yaw_rate_dps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_rate_dps: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_rate_dps, out);
    out << "\n";
  }

  // member: yaw_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_deg, out);
    out << "\n";
  }

  // member: curvature_meas
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "curvature_meas: ";
    rosidl_generator_traits::value_to_yaml(msg.curvature_meas, out);
    out << "\n";
  }

  // member: curvature_cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "curvature_cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.curvature_cmd, out);
    out << "\n";
  }

  // member: steering_angle_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_angle_deg, out);
    out << "\n";
  }

  // member: steering_pwm_us
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering_pwm_us: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_pwm_us, out);
    out << "\n";
  }

  // member: steering_clamped
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steering_clamped: ";
    rosidl_generator_traits::value_to_yaml(msg.steering_clamped, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SmartCarMotionState & msg, bool use_flow_style = false)
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
  const messages::msg::SmartCarMotionState & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::SmartCarMotionState & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::SmartCarMotionState>()
{
  return "messages::msg::SmartCarMotionState";
}

template<>
inline const char * name<messages::msg::SmartCarMotionState>()
{
  return "messages/msg/SmartCarMotionState";
}

template<>
struct has_fixed_size<messages::msg::SmartCarMotionState>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<messages::msg::SmartCarMotionState>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<messages::msg::SmartCarMotionState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_MOTION_STATE__TRAITS_HPP_
