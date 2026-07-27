// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from messages:srv/SmartCarActuatorTest.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__TRAITS_HPP_
#define MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "messages/srv/detail/smart_car_actuator_test__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace messages
{

namespace srv
{

inline void to_flow_style_yaml(
  const SmartCarActuatorTest_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: test_mask
  {
    out << "test_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.test_mask, out);
    out << ", ";
  }

  // member: servo_angle_deg
  {
    out << "servo_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_angle_deg, out);
    out << ", ";
  }

  // member: servo_pwm_us
  {
    out << "servo_pwm_us: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_pwm_us, out);
    out << ", ";
  }

  // member: motor1_rpm
  {
    out << "motor1_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.motor1_rpm, out);
    out << ", ";
  }

  // member: motor2_rpm
  {
    out << "motor2_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.motor2_rpm, out);
    out << ", ";
  }

  // member: duration_ms
  {
    out << "duration_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.duration_ms, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SmartCarActuatorTest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: test_mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "test_mask: ";
    rosidl_generator_traits::value_to_yaml(msg.test_mask, out);
    out << "\n";
  }

  // member: servo_angle_deg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "servo_angle_deg: ";
    rosidl_generator_traits::value_to_yaml(msg.servo_angle_deg, out);
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

  // member: motor1_rpm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor1_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.motor1_rpm, out);
    out << "\n";
  }

  // member: motor2_rpm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor2_rpm: ";
    rosidl_generator_traits::value_to_yaml(msg.motor2_rpm, out);
    out << "\n";
  }

  // member: duration_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.duration_ms, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SmartCarActuatorTest_Request & msg, bool use_flow_style = false)
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
  const messages::srv::SmartCarActuatorTest_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::srv::to_yaml() instead")]]
inline std::string to_yaml(const messages::srv::SmartCarActuatorTest_Request & msg)
{
  return messages::srv::to_yaml(msg);
}

template<>
inline const char * data_type<messages::srv::SmartCarActuatorTest_Request>()
{
  return "messages::srv::SmartCarActuatorTest_Request";
}

template<>
inline const char * name<messages::srv::SmartCarActuatorTest_Request>()
{
  return "messages/srv/SmartCarActuatorTest_Request";
}

template<>
struct has_fixed_size<messages::srv::SmartCarActuatorTest_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<messages::srv::SmartCarActuatorTest_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<messages::srv::SmartCarActuatorTest_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace messages
{

namespace srv
{

inline void to_flow_style_yaml(
  const SmartCarActuatorTest_Response & msg,
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
  const SmartCarActuatorTest_Response & msg,
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

inline std::string to_yaml(const SmartCarActuatorTest_Response & msg, bool use_flow_style = false)
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
  const messages::srv::SmartCarActuatorTest_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  messages::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use messages::srv::to_yaml() instead")]]
inline std::string to_yaml(const messages::srv::SmartCarActuatorTest_Response & msg)
{
  return messages::srv::to_yaml(msg);
}

template<>
inline const char * data_type<messages::srv::SmartCarActuatorTest_Response>()
{
  return "messages::srv::SmartCarActuatorTest_Response";
}

template<>
inline const char * name<messages::srv::SmartCarActuatorTest_Response>()
{
  return "messages/srv/SmartCarActuatorTest_Response";
}

template<>
struct has_fixed_size<messages::srv::SmartCarActuatorTest_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<messages::srv::SmartCarActuatorTest_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<messages::srv::SmartCarActuatorTest_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<messages::srv::SmartCarActuatorTest>()
{
  return "messages::srv::SmartCarActuatorTest";
}

template<>
inline const char * name<messages::srv::SmartCarActuatorTest>()
{
  return "messages/srv/SmartCarActuatorTest";
}

template<>
struct has_fixed_size<messages::srv::SmartCarActuatorTest>
  : std::integral_constant<
    bool,
    has_fixed_size<messages::srv::SmartCarActuatorTest_Request>::value &&
    has_fixed_size<messages::srv::SmartCarActuatorTest_Response>::value
  >
{
};

template<>
struct has_bounded_size<messages::srv::SmartCarActuatorTest>
  : std::integral_constant<
    bool,
    has_bounded_size<messages::srv::SmartCarActuatorTest_Request>::value &&
    has_bounded_size<messages::srv::SmartCarActuatorTest_Response>::value
  >
{
};

template<>
struct is_service<messages::srv::SmartCarActuatorTest>
  : std::true_type
{
};

template<>
struct is_service_request<messages::srv::SmartCarActuatorTest_Request>
  : std::true_type
{
};

template<>
struct is_service_response<messages::srv::SmartCarActuatorTest_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__TRAITS_HPP_
