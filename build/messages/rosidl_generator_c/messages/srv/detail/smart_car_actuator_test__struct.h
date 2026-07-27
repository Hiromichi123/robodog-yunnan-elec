// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:srv/SmartCarActuatorTest.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__STRUCT_H_
#define MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'TEST_SERVO_ANGLE'.
enum
{
  messages__srv__SmartCarActuatorTest_Request__TEST_SERVO_ANGLE = 1
};

/// Constant 'TEST_SERVO_PWM'.
enum
{
  messages__srv__SmartCarActuatorTest_Request__TEST_SERVO_PWM = 2
};

/// Constant 'TEST_MOTOR_RPM'.
enum
{
  messages__srv__SmartCarActuatorTest_Request__TEST_MOTOR_RPM = 4
};

/// Struct defined in srv/SmartCarActuatorTest in the package messages.
typedef struct messages__srv__SmartCarActuatorTest_Request
{
  uint16_t test_mask;
  float servo_angle_deg;
  uint16_t servo_pwm_us;
  int16_t motor1_rpm;
  int16_t motor2_rpm;
  uint16_t duration_ms;
} messages__srv__SmartCarActuatorTest_Request;

// Struct for a sequence of messages__srv__SmartCarActuatorTest_Request.
typedef struct messages__srv__SmartCarActuatorTest_Request__Sequence
{
  messages__srv__SmartCarActuatorTest_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__srv__SmartCarActuatorTest_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SmartCarActuatorTest in the package messages.
typedef struct messages__srv__SmartCarActuatorTest_Response
{
  bool accepted;
  rosidl_runtime_c__String message;
} messages__srv__SmartCarActuatorTest_Response;

// Struct for a sequence of messages__srv__SmartCarActuatorTest_Response.
typedef struct messages__srv__SmartCarActuatorTest_Response__Sequence
{
  messages__srv__SmartCarActuatorTest_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__srv__SmartCarActuatorTest_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__SRV__DETAIL__SMART_CAR_ACTUATOR_TEST__STRUCT_H_
