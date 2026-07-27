// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:action/ExecuteMission.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_
#define MESSAGES__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_

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
// Member 'mission_name'
// Member 'bt_xml_uri'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMission in the package messages.
typedef struct messages__action__ExecuteMission_Goal
{
  rosidl_runtime_c__String task_id;
  uint8_t priority;
  rosidl_runtime_c__String mission_name;
  rosidl_runtime_c__String bt_xml_uri;
  float timeout_sec;
} messages__action__ExecuteMission_Goal;

// Struct for a sequence of messages__action__ExecuteMission_Goal.
typedef struct messages__action__ExecuteMission_Goal__Sequence
{
  messages__action__ExecuteMission_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__ExecuteMission_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// Member 'failed_node'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/ExecuteMission in the package messages.
typedef struct messages__action__ExecuteMission_Result
{
  bool success;
  uint8_t final_state_code;
  uint16_t error_code;
  rosidl_runtime_c__String message;
  float elapsed_sec;
  rosidl_runtime_c__String failed_node;
} messages__action__ExecuteMission_Result;

// Struct for a sequence of messages__action__ExecuteMission_Result.
typedef struct messages__action__ExecuteMission_Result__Sequence
{
  messages__action__ExecuteMission_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__ExecuteMission_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'task_id'
// Member 'message'
// Member 'current_node'
// Member 'current_stage'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"
// Member 'current_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'current_twist'
#include "geometry_msgs/msg/detail/twist__struct.h"

/// Struct defined in action/ExecuteMission in the package messages.
typedef struct messages__action__ExecuteMission_Feedback
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
  rosidl_runtime_c__String current_node;
  rosidl_runtime_c__String current_stage;
} messages__action__ExecuteMission_Feedback;

// Struct for a sequence of messages__action__ExecuteMission_Feedback.
typedef struct messages__action__ExecuteMission_Feedback__Sequence
{
  messages__action__ExecuteMission_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__ExecuteMission_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "messages/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package messages.
typedef struct messages__action__ExecuteMission_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  messages__action__ExecuteMission_Goal goal;
} messages__action__ExecuteMission_SendGoal_Request;

// Struct for a sequence of messages__action__ExecuteMission_SendGoal_Request.
typedef struct messages__action__ExecuteMission_SendGoal_Request__Sequence
{
  messages__action__ExecuteMission_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__ExecuteMission_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
// already included above
// #include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ExecuteMission in the package messages.
typedef struct messages__action__ExecuteMission_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} messages__action__ExecuteMission_SendGoal_Response;

// Struct for a sequence of messages__action__ExecuteMission_SendGoal_Response.
typedef struct messages__action__ExecuteMission_SendGoal_Response__Sequence
{
  messages__action__ExecuteMission_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__ExecuteMission_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ExecuteMission in the package messages.
typedef struct messages__action__ExecuteMission_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} messages__action__ExecuteMission_GetResult_Request;

// Struct for a sequence of messages__action__ExecuteMission_GetResult_Request.
typedef struct messages__action__ExecuteMission_GetResult_Request__Sequence
{
  messages__action__ExecuteMission_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__ExecuteMission_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "messages/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package messages.
typedef struct messages__action__ExecuteMission_GetResult_Response
{
  int8_t status;
  messages__action__ExecuteMission_Result result;
} messages__action__ExecuteMission_GetResult_Response;

// Struct for a sequence of messages__action__ExecuteMission_GetResult_Response.
typedef struct messages__action__ExecuteMission_GetResult_Response__Sequence
{
  messages__action__ExecuteMission_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__ExecuteMission_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "messages/action/detail/execute_mission__struct.h"

/// Struct defined in action/ExecuteMission in the package messages.
typedef struct messages__action__ExecuteMission_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  messages__action__ExecuteMission_Feedback feedback;
} messages__action__ExecuteMission_FeedbackMessage;

// Struct for a sequence of messages__action__ExecuteMission_FeedbackMessage.
typedef struct messages__action__ExecuteMission_FeedbackMessage__Sequence
{
  messages__action__ExecuteMission_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} messages__action__ExecuteMission_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__ACTION__DETAIL__EXECUTE_MISSION__STRUCT_H_
