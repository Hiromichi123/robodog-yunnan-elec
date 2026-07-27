// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/VisionMsg.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__VISION_MSG__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__VISION_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/vision_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const VisionMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_line_detected
  {
    out << "is_line_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_line_detected, out);
    out << ", ";
  }

  // member: lateral_error
  {
    out << "lateral_error: ";
    rosidl_generator_traits::value_to_yaml(msg.lateral_error, out);
    out << ", ";
  }

  // member: angle_error
  {
    out << "angle_error: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_error, out);
    out << ", ";
  }

  // member: is_square_detected
  {
    out << "is_square_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_square_detected, out);
    out << ", ";
  }

  // member: center_x1_error
  {
    out << "center_x1_error: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x1_error, out);
    out << ", ";
  }

  // member: center_y1_error
  {
    out << "center_y1_error: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y1_error, out);
    out << ", ";
  }

  // member: is_circle_detected
  {
    out << "is_circle_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_circle_detected, out);
    out << ", ";
  }

  // member: center_x2_error
  {
    out << "center_x2_error: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x2_error, out);
    out << ", ";
  }

  // member: center_y2_error
  {
    out << "center_y2_error: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y2_error, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VisionMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_line_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_line_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_line_detected, out);
    out << "\n";
  }

  // member: lateral_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lateral_error: ";
    rosidl_generator_traits::value_to_yaml(msg.lateral_error, out);
    out << "\n";
  }

  // member: angle_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angle_error: ";
    rosidl_generator_traits::value_to_yaml(msg.angle_error, out);
    out << "\n";
  }

  // member: is_square_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_square_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_square_detected, out);
    out << "\n";
  }

  // member: center_x1_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_x1_error: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x1_error, out);
    out << "\n";
  }

  // member: center_y1_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_y1_error: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y1_error, out);
    out << "\n";
  }

  // member: is_circle_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_circle_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_circle_detected, out);
    out << "\n";
  }

  // member: center_x2_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_x2_error: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x2_error, out);
    out << "\n";
  }

  // member: center_y2_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_y2_error: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y2_error, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VisionMsg & msg, bool use_flow_style = false)
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
  const messages::msg::VisionMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::VisionMsg & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::VisionMsg>()
{
  return "messages::msg::VisionMsg";
}

template<>
inline const char * name<messages::msg::VisionMsg>()
{
  return "messages/msg/VisionMsg";
}

template<>
struct has_fixed_size<messages::msg::VisionMsg>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<messages::msg::VisionMsg>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<messages::msg::VisionMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__VISION_MSG__TRAITS_HPP_
