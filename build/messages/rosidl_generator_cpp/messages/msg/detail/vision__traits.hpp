// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:msg/Vision.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__VISION__TRAITS_HPP_
#define MESSAGES__MSG__DETAIL__VISION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/msg/detail/vision__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace messages
{

namespace msg
{

inline void to_flow_style_yaml(
  const Vision & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_detected
  {
    out << "is_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_detected, out);
    out << ", ";
  }

  // member: center_x
  {
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << ", ";
  }

  // member: center_y
  {
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
    out << ", ";
  }

  // member: center_x1_error
  {
    out << "center_x1_error: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x1_error, out);
    out << ", ";
  }

  // member: label
  {
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Vision & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_detected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_detected: ";
    rosidl_generator_traits::value_to_yaml(msg.is_detected, out);
    out << "\n";
  }

  // member: center_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_x: ";
    rosidl_generator_traits::value_to_yaml(msg.center_x, out);
    out << "\n";
  }

  // member: center_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center_y: ";
    rosidl_generator_traits::value_to_yaml(msg.center_y, out);
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

  // member: label
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "label: ";
    rosidl_generator_traits::value_to_yaml(msg.label, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Vision & msg, bool use_flow_style = false)
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
  const messages::msg::Vision & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::msg::to_yaml() instead")]]
inline std::string to_yaml(const messages::msg::Vision & msg)
{
  return messages::msg::to_yaml(msg);
}

template<>
inline const char * data_type<messages::msg::Vision>()
{
  return "messages::msg::Vision";
}

template<>
inline const char * name<messages::msg::Vision>()
{
  return "messages/msg/Vision";
}

template<>
struct has_fixed_size<messages::msg::Vision>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<messages::msg::Vision>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<messages::msg::Vision>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__MSG__DETAIL__VISION__TRAITS_HPP_
