// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:srv/SmartCarCommand.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__STRUCT_H_
#define MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SMART_CAR_COMMAND_ENABLE'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_ENABLE = 1
};

/// Constant 'SMART_CAR_COMMAND_DISABLE'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_DISABLE = 2
};

/// Constant 'SMART_CAR_COMMAND_STOP'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_STOP = 3
};

/// Constant 'SMART_CAR_COMMAND_RECENTER_SERVO'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_RECENTER_SERVO = 4
};

/// Constant 'SMART_CAR_COMMAND_GYRO_CAL'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_GYRO_CAL = 5
};

/// Constant 'SMART_CAR_COMMAND_CLEAR_FAULTS'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_CLEAR_FAULTS = 6
};

/// Constant 'SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT = 7
};

/// Constant 'SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT = 8
};

/// Constant 'SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT = 9
};

/// Constant 'SMART_CAR_COMMAND_STOP_CURVATURE_CAL'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_STOP_CURVATURE_CAL = 10
};

/// Constant 'SMART_CAR_COMMAND_FIREWATER_OFF'.
enum
{
  messages__srv__SmartCarCommand_Request__SMART_CAR_COMMAND_FIREWATER_OFF = 11
};

/// Struct defined in srv/SmartCarCommand in the package messages.
typedef struct messages__srv__SmartCarCommand_Request
{
  uint16_t command;
  float param1;
  float param2;
  float param3;
  float param4;
} messages__srv__SmartCarCommand_Request;

// Struct for a sequence of messages__srv__SmartCarCommand_Request.
typedef struct messages__srv__SmartCarCommand_Request__Sequence
{
  messages__srv__SmartCarCommand_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__srv__SmartCarCommand_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SmartCarCommand in the package messages.
typedef struct messages__srv__SmartCarCommand_Response
{
  bool accepted;
  rosidl_runtime_c__String message;
} messages__srv__SmartCarCommand_Response;

// Struct for a sequence of messages__srv__SmartCarCommand_Response.
typedef struct messages__srv__SmartCarCommand_Response__Sequence
{
  messages__srv__SmartCarCommand_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__srv__SmartCarCommand_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__STRUCT_H_
