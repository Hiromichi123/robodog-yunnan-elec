// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/SmartCarImuStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/smart_car_imu_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const SmartCarImuStatus & msg,
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

  // member: sample_count
  {
    out << "sample_count: ";
    rosidl_generator_traits::value_to_yaml(msg.sample_count, out);
    out << ", ";
  }

  // member: overrun_count
  {
    out << "overrun_count: ";
    rosidl_generator_traits::value_to_yaml(msg.overrun_count, out);
    out << ", ";
  }

  // member: error_count
  {
    out << "error_count: ";
    rosidl_generator_traits::value_to_yaml(msg.error_count, out);
    out << ", ";
  }

  // member: gyro_x_mdps
  {
    out << "gyro_x_mdps: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_x_mdps, out);
    out << ", ";
  }

  // member: gyro_y_mdps
  {
    out << "gyro_y_mdps: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_y_mdps, out);
    out << ", ";
  }

  // member: gyro_z_mdps
  {
    out << "gyro_z_mdps: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_z_mdps, out);
    out << ", ";
  }

  // member: yaw_rate_raw_dps
  {
    out << "yaw_rate_raw_dps: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_rate_raw_dps, out);
    out << ", ";
  }

  // member: yaw_rate_dps
  {
    out << "yaw_rate_dps: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_rate_dps, out);
    out << ", ";
  }

  // member: gyro_bias_z_dps
  {
    out << "gyro_bias_z_dps: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_bias_z_dps, out);
    out << ", ";
  }

  // member: accel_x_mg
  {
    out << "accel_x_mg: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_x_mg, out);
    out << ", ";
  }

  // member: accel_y_mg
  {
    out << "accel_y_mg: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_y_mg, out);
    out << ", ";
  }

  // member: accel_z_mg
  {
    out << "accel_z_mg: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_z_mg, out);
    out << ", ";
  }

  // member: temperature_c_x100
  {
    out << "temperature_c_x100: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature_c_x100, out);
    out << ", ";
  }

  // member: calibrated
  {
    out << "calibrated: ";
    rosidl_generator_traits::value_to_yaml(msg.calibrated, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SmartCarImuStatus & msg,
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

  // member: sample_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sample_count: ";
    rosidl_generator_traits::value_to_yaml(msg.sample_count, out);
    out << "\n";
  }

  // member: overrun_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "overrun_count: ";
    rosidl_generator_traits::value_to_yaml(msg.overrun_count, out);
    out << "\n";
  }

  // member: error_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_count: ";
    rosidl_generator_traits::value_to_yaml(msg.error_count, out);
    out << "\n";
  }

  // member: gyro_x_mdps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_x_mdps: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_x_mdps, out);
    out << "\n";
  }

  // member: gyro_y_mdps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_y_mdps: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_y_mdps, out);
    out << "\n";
  }

  // member: gyro_z_mdps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_z_mdps: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_z_mdps, out);
    out << "\n";
  }

  // member: yaw_rate_raw_dps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw_rate_raw_dps: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_rate_raw_dps, out);
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

  // member: gyro_bias_z_dps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gyro_bias_z_dps: ";
    rosidl_generator_traits::value_to_yaml(msg.gyro_bias_z_dps, out);
    out << "\n";
  }

  // member: accel_x_mg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accel_x_mg: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_x_mg, out);
    out << "\n";
  }

  // member: accel_y_mg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accel_y_mg: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_y_mg, out);
    out << "\n";
  }

  // member: accel_z_mg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accel_z_mg: ";
    rosidl_generator_traits::value_to_yaml(msg.accel_z_mg, out);
    out << "\n";
  }

  // member: temperature_c_x100
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature_c_x100: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature_c_x100, out);
    out << "\n";
  }

  // member: calibrated
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "calibrated: ";
    rosidl_generator_traits::value_to_yaml(msg.calibrated, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SmartCarImuStatus & msg, bool use_flow_style = false)
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
  const messages::msg::SmartCarImuStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::SmartCarImuStatus & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::SmartCarImuStatus>()
{
  return "messages::msg::SmartCarImuStatus";
}

template<>
inline const char * name<messages::msg::SmartCarImuStatus>()
{
  return "messages/msg/SmartCarImuStatus";
}

template<>
struct has_fixed_size<messages::msg::SmartCarImuStatus>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<messages::msg::SmartCarImuStatus>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<messages::msg::SmartCarImuStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__TRAITS_HPP_
