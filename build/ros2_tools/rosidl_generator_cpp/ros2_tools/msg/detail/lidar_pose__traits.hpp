// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_tools:msg/LidarPose.idl
// generated code does not contain a copyright notice

#ifndef ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__TRAITS_HPP_
#define ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_tools/msg/detail/lidar_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_tools
{

namespace msg
{

inline void to_flow_style_yaml(
  const LidarPose & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: roll
  {
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << ", ";
  }

  // member: pitch
  {
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << ", ";
  }

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const LidarPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: roll
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "roll: ";
    rosidl_generator_traits::value_to_yaml(msg.roll, out);
    out << "\n";
  }

  // member: pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pitch: ";
    rosidl_generator_traits::value_to_yaml(msg.pitch, out);
    out << "\n";
  }

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const LidarPose & msg, bool use_flow_style = false)
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

}  // namespace ros2_tools

namespace rosidl_generator_traits
{

[[deprecated("use ros2_tools::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_tools::msg::LidarPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_tools::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_tools::msg::to_yaml() instead")]]
inline std::string to_yaml(const ros2_tools::msg::LidarPose & msg)
{
  return ros2_tools::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_tools::msg::LidarPose>()
{
  return "ros2_tools::msg::LidarPose";
}

template<>
inline const char * name<ros2_tools::msg::LidarPose>()
{
  return "ros2_tools/msg/LidarPose";
}

template<>
struct has_fixed_size<ros2_tools::msg::LidarPose>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<ros2_tools::msg::LidarPose>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<ros2_tools::msg::LidarPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_TOOLS__MSG__DETAIL__LIDAR_POSE__TRAITS_HPP_
