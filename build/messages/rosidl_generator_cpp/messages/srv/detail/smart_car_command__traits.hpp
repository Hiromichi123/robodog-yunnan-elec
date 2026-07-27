// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:srv/SmartCarCommand.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__TRAITS_HPP_
#define MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/srv/detail/smart_car_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace messages
{

namespace srv
{

inline void to_flow_style_yaml(
  const SmartCarCommand_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: param1
  {
    out << "param1: ";
    rosidl_generator_traits::value_to_yaml(msg.param1, out);
    out << ", ";
  }

  // member: param2
  {
    out << "param2: ";
    rosidl_generator_traits::value_to_yaml(msg.param2, out);
    out << ", ";
  }

  // member: param3
  {
    out << "param3: ";
    rosidl_generator_traits::value_to_yaml(msg.param3, out);
    out << ", ";
  }

  // member: param4
  {
    out << "param4: ";
    rosidl_generator_traits::value_to_yaml(msg.param4, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SmartCarCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: param1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param1: ";
    rosidl_generator_traits::value_to_yaml(msg.param1, out);
    out << "\n";
  }

  // member: param2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param2: ";
    rosidl_generator_traits::value_to_yaml(msg.param2, out);
    out << "\n";
  }

  // member: param3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param3: ";
    rosidl_generator_traits::value_to_yaml(msg.param3, out);
    out << "\n";
  }

  // member: param4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "param4: ";
    rosidl_generator_traits::value_to_yaml(msg.param4, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SmartCarCommand_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::srv::SmartCarCommand_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::srv::to_yaml() instead")]]
inline std::string to_yaml(const messages::srv::SmartCarCommand_Request & msg)
{
  return messages::srv::to_yaml(msg);
}

template<>
inline const char * data_type<messages::srv::SmartCarCommand_Request>()
{
  return "messages::srv::SmartCarCommand_Request";
}

template<>
inline const char * name<messages::srv::SmartCarCommand_Request>()
{
  return "messages/srv/SmartCarCommand_Request";
}

template<>
struct has_fixed_size<messages::srv::SmartCarCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<messages::srv::SmartCarCommand_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<messages::srv::SmartCarCommand_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace messages
{

namespace srv
{

inline void to_flow_style_yaml(
  const SmartCarCommand_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SmartCarCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SmartCarCommand_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace messages

namespace rosidl_generator_traits
{

[[deprecated("use messages::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const messages::srv::SmartCarCommand_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::srv::to_yaml() instead")]]
inline std::string to_yaml(const messages::srv::SmartCarCommand_Response & msg)
{
  return messages::srv::to_yaml(msg);
}

template<>
inline const char * data_type<messages::srv::SmartCarCommand_Response>()
{
  return "messages::srv::SmartCarCommand_Response";
}

template<>
inline const char * name<messages::srv::SmartCarCommand_Response>()
{
  return "messages/srv/SmartCarCommand_Response";
}

template<>
struct has_fixed_size<messages::srv::SmartCarCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<messages::srv::SmartCarCommand_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<messages::srv::SmartCarCommand_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<messages::srv::SmartCarCommand>()
{
  return "messages::srv::SmartCarCommand";
}

template<>
inline const char * name<messages::srv::SmartCarCommand>()
{
  return "messages/srv/SmartCarCommand";
}

template<>
struct has_fixed_size<messages::srv::SmartCarCommand>
  : std::integral_constant<
    bool,
    has_fixed_size<messages::srv::SmartCarCommand_Request>::value &&
    has_fixed_size<messages::srv::SmartCarCommand_Response>::value
  >
{
};

template<>
struct has_bounded_size<messages::srv::SmartCarCommand>
  : std::integral_constant<
    bool,
    has_bounded_size<messages::srv::SmartCarCommand_Request>::value &&
    has_bounded_size<messages::srv::SmartCarCommand_Response>::value
  >
{
};

template<>
struct is_service<messages::srv::SmartCarCommand>
  : std::true_type
{
};

template<>
struct is_service_request<messages::srv::SmartCarCommand_Request>
  : std::true_type
{
};

template<>
struct is_service_response<messages::srv::SmartCarCommand_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__TRAITS_HPP_
