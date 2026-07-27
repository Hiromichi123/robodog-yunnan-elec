// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/PlatformTarget.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__PLATFORM_TARGET__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__PLATFORM_TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/platform_target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const PlatformTarget & msg,
  std::ostream & out)
{
  out << "{";
  // member: platform
  {
    out << "platform: ";
    rosidl_generator_traits::value_to_yaml(msg.platform, out);
    out << ", ";
  }

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

  // member: yaw
  {
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << ", ";
  }

  // member: vx_mps
  {
    out << "vx_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.vx_mps, out);
    out << ", ";
  }

  // member: vy_mps
  {
    out << "vy_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.vy_mps, out);
    out << ", ";
  }

  // member: vz_mps
  {
    out << "vz_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.vz_mps, out);
    out << ", ";
  }

  // member: speed_mps
  {
    out << "speed_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.speed_mps, out);
    out << ", ";
  }

  // member: curvature
  {
    out << "curvature: ";
    rosidl_generator_traits::value_to_yaml(msg.curvature, out);
    out << ", ";
  }

  // member: yaw_rate_dps
  {
    out << "yaw_rate_dps: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw_rate_dps, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PlatformTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: platform
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "platform: ";
    rosidl_generator_traits::value_to_yaml(msg.platform, out);
    out << "\n";
  }

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

  // member: yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "yaw: ";
    rosidl_generator_traits::value_to_yaml(msg.yaw, out);
    out << "\n";
  }

  // member: vx_mps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vx_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.vx_mps, out);
    out << "\n";
  }

  // member: vy_mps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vy_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.vy_mps, out);
    out << "\n";
  }

  // member: vz_mps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vz_mps: ";
    rosidl_generator_traits::value_to_yaml(msg.vz_mps, out);
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

  // member: curvature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "curvature: ";
    rosidl_generator_traits::value_to_yaml(msg.curvature, out);
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PlatformTarget & msg, bool use_flow_style = false)
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
  const messages::msg::PlatformTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::PlatformTarget & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::PlatformTarget>()
{
  return "messages::msg::PlatformTarget";
}

template<>
inline const char * name<messages::msg::PlatformTarget>()
{
  return "messages/msg/PlatformTarget";
}

template<>
struct has_fixed_size<messages::msg::PlatformTarget>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<messages::msg::PlatformTarget>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<messages::msg::PlatformTarget>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__PLATFORM_TARGET__TRAITS_HPP_
