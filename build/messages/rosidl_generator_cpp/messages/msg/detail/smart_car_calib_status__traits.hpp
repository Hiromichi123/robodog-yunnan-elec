// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/SmartCarCalibStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/smart_car_calib_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const SmartCarCalibStatus & msg,
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

  // member: point_id
  {
    out << "point_id: ";
    rosidl_generator_traits::value_to_yaml(msg.point_id, out);
    out << ", ";
  }

  // member: sweep_index
  {
    out << "sweep_index: ";
    rosidl_generator_traits::value_to_yaml(msg.sweep_index, out);
    out << ", ";
  }

  // member: sweep_count
  {
    out << "sweep_count: ";
    rosidl_generator_traits::value_to_yaml(msg.sweep_count, out);
    out << ", ";
  }

  // member: valid_count
  {
    out << "valid_count: ";
    rosidl_generator_traits::value_to_yaml(msg.valid_count, out);
    out << ", ";
  }

  // member: invalid_count
  {
    out << "invalid_count: ";
    rosidl_generator_traits::value_to_yaml(msg.invalid_count, out);
    out << ", ";
  }

  // member: v_center_avg
  {
    out << "v_center_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.v_center_avg, out);
    out << ", ";
  }

  // member: yaw_rate_avg
  {
    out << "yaw_rate_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_rate_avg, out);
    out << ", ";
  }

  // member: kappa_avg
  {
    out << "kappa_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.kappa_avg, out);
    out << ", ";
  }

  // member: radius_est
  {
    out << "radius_est: ";
    rosidl_generator_traits::value_to_yaml(msg.radius_est, out);
    out << ", ";
  }

  // member: target_rpm
  {
    out << "target_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.target_rpm, out);
    out << ", ";
  }

  // member: servo_pwm_us
  {
    out << "servo_pwm_us: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_pwm_us, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: sweep_enabled
  {
    out << "sweep_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.sweep_enabled, out);
    out << ", ";
  }

  // member: yaw_sign_inverted
  {
    out << "yaw_sign_inverted: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_sign_inverted, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SmartCarCalibStatus & msg,
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

  // member: point_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "point_id: ";
    rosidl_generator_traits::value_to_yaml(msg.point_id, out);
    out << "\n";
  }

  // member: sweep_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sweep_index: ";
    rosidl_generator_traits::value_to_yaml(msg.sweep_index, out);
    out << "\n";
  }

  // member: sweep_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sweep_count: ";
    rosidl_generator_traits::value_to_yaml(msg.sweep_count, out);
    out << "\n";
  }

  // member: valid_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "valid_count: ";
    rosidl_generator_traits::value_to_yaml(msg.valid_count, out);
    out << "\n";
  }

  // member: invalid_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "invalid_count: ";
    rosidl_generator_traits::value_to_yaml(msg.invalid_count, out);
    out << "\n";
  }

  // member: v_center_avg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_center_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.v_center_avg, out);
    out << "\n";
  }

  // member: yaw_rate_avg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_rate_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_rate_avg, out);
    out << "\n";
  }

  // member: kappa_avg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "kappa_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.kappa_avg, out);
    out << "\n";
  }

  // member: radius_est
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius_est: ";
    rosidl_generator_traits::value_to_yaml(msg.radius_est, out);
    out << "\n";
  }

  // member: target_rpm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.target_rpm, out);
    out << "\n";
  }

  // member: servo_pwm_us
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_pwm_us: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_pwm_us, out);
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

  // member: sweep_enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sweep_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.sweep_enabled, out);
    out << "\n";
  }

  // member: yaw_sign_inverted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_sign_inverted: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_sign_inverted, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SmartCarCalibStatus & msg, bool use_flow_style = false)
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
  const messages::msg::SmartCarCalibStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::SmartCarCalibStatus & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::SmartCarCalibStatus>()
{
  return "messages::msg::SmartCarCalibStatus";
}

template<>
inline const char * name<messages::msg::SmartCarCalibStatus>()
{
  return "messages/msg/SmartCarCalibStatus";
}

template<>
struct has_fixed_size<messages::msg::SmartCarCalibStatus>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<messages::msg::SmartCarCalibStatus>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<messages::msg::SmartCarCalibStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_CALIB_STATUS__TRAITS_HPP_
