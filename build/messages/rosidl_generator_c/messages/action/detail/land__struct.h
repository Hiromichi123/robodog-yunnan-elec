// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:action/Land.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__ACTION__DETAIL__LAND__STRUCT_H_
#define MESSAGES__ACTION__DETAIL__LAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'task_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Land in the package messages.
typedef struct messages__action__Land_Goal
{
  rosidl_runtime_c__String task_id;
  uint8_t priority;
  float timeout_sec;
} messages__action__Land_Goal;

// Struct for a sequence of messages__action__Land_Goal.
typedef struct messages__action__Land_Goal__Sequence
{
  messages__action__Land_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__Land_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Land in the package messages.
typedef struct messages__action__Land_Result
{
  bool success;
  uint8_t final_state_code;
  uint16_t error_code;
  rosidl_runtime_c__String message;
  float elapsed_sec;
} messages__action__Land_Result;

// Struct for a sequence of messages__action__Land_Result.
typedef struct messages__action__Land_Result__Sequence
{
  messages__action__Land_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__Land_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'task_id'
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'current_twist'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in action/Land in the package messages.
typedef struct messages__action__Land_Feedback
{
  rosidl_runtime_c__String task_id;
  uint8_t priority;
  builtin_interfaces__msg__Time stamp;
  uint8_t state_code;
  uint16_t error_code;
  rosidl_runtime_c__String message;
  float progress;
  float distance_error;
  float yaw_error;
  geometry_msgs__msg__Pose current_pose;
  geometry_msgs__msg__Twist current_twist;
} messages__action__Land_Feedback;

// Struct for a sequence of messages__action__Land_Feedback.
typedef struct messages__action__Land_Feedback__Sequence
{
  messages__action__Land_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__Land_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "messages/action/detail/land__struct.h"

/// Struct defined in action/Land in the package messages.
typedef struct messages__action__Land_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  messages__action__Land_Goal goal;
} messages__action__Land_SendGoal_Request;

// Struct for a sequence of messages__action__Land_SendGoal_Request.
typedef struct messages__action__Land_SendGoal_Request__Sequence
{
  messages__action__Land_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__Land_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
// already included above
// #include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Land in the package messages.
typedef struct messages__action__Land_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} messages__action__Land_SendGoal_Response;

// Struct for a sequence of messages__action__Land_SendGoal_Response.
typedef struct messages__action__Land_SendGoal_Response__Sequence
{
  messages__action__Land_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__Land_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Land in the package messages.
typedef struct messages__action__Land_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} messages__action__Land_GetResult_Request;

// Struct for a sequence of messages__action__Land_GetResult_Request.
typedef struct messages__action__Land_GetResult_Request__Sequence
{
  messages__action__Land_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__Land_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "messages/action/detail/land__struct.h"

/// Struct defined in action/Land in the package messages.
typedef struct messages__action__Land_GetResult_Response
{
  int8_t status;
  messages__action__Land_Result result;
} messages__action__Land_GetResult_Response;

// Struct for a sequence of messages__action__Land_GetResult_Response.
typedef struct messages__action__Land_GetResult_Response__Sequence
{
  messages__action__Land_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__Land_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "messages/action/detail/land__struct.h"

/// Struct defined in action/Land in the package messages.
typedef struct messages__action__Land_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  messages__action__Land_Feedback feedback;
} messages__action__Land_FeedbackMessage;

// Struct for a sequence of messages__action__Land_FeedbackMessage.
typedef struct messages__action__Land_FeedbackMessage__Sequence
{
  messages__action__Land_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__Land_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__ACTION__DETAIL__LAND__STRUCT_H_
