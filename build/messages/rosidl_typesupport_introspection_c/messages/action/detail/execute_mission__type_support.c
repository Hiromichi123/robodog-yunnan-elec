// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from messages:action/ExecuteMission.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
#include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "messages/action/detail/execute_mission__functions.h"
#include "messages/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `task_id`
// Member `mission_name`
// Member `bt_xml_uri`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__action__ExecuteMission_Goal__init(message_memory);
}

void messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_fini_function(void * message_memory)
{
  messages__action__ExecuteMission_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_member_array[5] = {
  {
    "task_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Goal, task_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "priority",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Goal, priority),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "mission_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Goal, mission_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bt_xml_uri",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Goal, bt_xml_uri),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timeout_sec",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Goal, timeout_sec),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_members = {
  "messages__action",  // message namespace
  "ExecuteMission_Goal",  // message name
  5,  // number of fields
  sizeof(messages__action__ExecuteMission_Goal),
  messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_member_array,  // message members
  messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_type_support_handle = {
  0,
  &messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_Goal)() {
  if (!messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_type_support_handle.typesupport_identifier) {
    messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__action__ExecuteMission_Goal__rosidl_typesupport_introspection_c__ExecuteMission_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "messages/action/detail/execute_mission__functions.h"
// already included above
// #include "messages/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `message`
// Member `failed_node`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__action__ExecuteMission_Result__init(message_memory);
}

void messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_fini_function(void * message_memory)
{
  messages__action__ExecuteMission_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_member_array[6] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Result, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "final_state_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Result, final_state_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Result, error_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Result, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "elapsed_sec",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Result, elapsed_sec),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "failed_node",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Result, failed_node),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_members = {
  "messages__action",  // message namespace
  "ExecuteMission_Result",  // message name
  6,  // number of fields
  sizeof(messages__action__ExecuteMission_Result),
  messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_member_array,  // message members
  messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_type_support_handle = {
  0,
  &messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_Result)() {
  if (!messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_type_support_handle.typesupport_identifier) {
    messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__action__ExecuteMission_Result__rosidl_typesupport_introspection_c__ExecuteMission_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "messages/action/detail/execute_mission__functions.h"
// already included above
// #include "messages/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `task_id`
// Member `message`
// Member `current_node`
// Member `current_stage`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `current_pose`
#include "geometry_msgs/msg/pose.h"
// Member `current_pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `current_twist`
#include "geometry_msgs/msg/twist.h"
// Member `current_twist`
#include "geometry_msgs/msg/detail/twist__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__action__ExecuteMission_Feedback__init(message_memory);
}

void messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_fini_function(void * message_memory)
{
  messages__action__ExecuteMission_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_member_array[13] = {
  {
    "task_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, task_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "priority",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, priority),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, state_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_code",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, error_code),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "progress",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, progress),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance_error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, distance_error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw_error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, yaw_error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, current_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_twist",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, current_twist),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_node",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, current_node),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current_stage",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_Feedback, current_stage),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_members = {
  "messages__action",  // message namespace
  "ExecuteMission_Feedback",  // message name
  13,  // number of fields
  sizeof(messages__action__ExecuteMission_Feedback),
  messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_member_array,  // message members
  messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_type_support_handle = {
  0,
  &messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_Feedback)() {
  messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_member_array[9].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_member_array[10].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Twist)();
  if (!messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_type_support_handle.typesupport_identifier) {
    messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__action__ExecuteMission_Feedback__rosidl_typesupport_introspection_c__ExecuteMission_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "messages/action/detail/execute_mission__functions.h"
// already included above
// #include "messages/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "messages/action/execute_mission.h"
// Member `goal`
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__action__ExecuteMission_SendGoal_Request__init(message_memory);
}

void messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_fini_function(void * message_memory)
{
  messages__action__ExecuteMission_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_members = {
  "messages__action",  // message namespace
  "ExecuteMission_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(messages__action__ExecuteMission_SendGoal_Request),
  messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_member_array,  // message members
  messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle = {
  0,
  &messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_SendGoal_Request)() {
  messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_Goal)();
  if (!messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__action__ExecuteMission_SendGoal_Request__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "messages/action/detail/execute_mission__functions.h"
// already included above
// #include "messages/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `stamp`
// already included above
// #include "builtin_interfaces/msg/time.h"
// Member `stamp`
// already included above
// #include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__action__ExecuteMission_SendGoal_Response__init(message_memory);
}

void messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_fini_function(void * message_memory)
{
  messages__action__ExecuteMission_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_members = {
  "messages__action",  // message namespace
  "ExecuteMission_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(messages__action__ExecuteMission_SendGoal_Response),
  messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_member_array,  // message members
  messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle = {
  0,
  &messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_SendGoal_Response)() {
  messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__action__ExecuteMission_SendGoal_Response__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_members = {
  "messages__action",  // service namespace
  "ExecuteMission_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_type_support_handle = {
  0,
  &messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_SendGoal)() {
  if (!messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_type_support_handle.typesupport_identifier) {
    messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_SendGoal_Response)()->data;
  }

  return &messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "messages/action/detail/execute_mission__functions.h"
// already included above
// #include "messages/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__action__ExecuteMission_GetResult_Request__init(message_memory);
}

void messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_fini_function(void * message_memory)
{
  messages__action__ExecuteMission_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_members = {
  "messages__action",  // message namespace
  "ExecuteMission_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(messages__action__ExecuteMission_GetResult_Request),
  messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_member_array,  // message members
  messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle = {
  0,
  &messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_GetResult_Request)() {
  messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__action__ExecuteMission_GetResult_Request__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "messages/action/detail/execute_mission__functions.h"
// already included above
// #include "messages/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "messages/action/execute_mission.h"
// Member `result`
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__action__ExecuteMission_GetResult_Response__init(message_memory);
}

void messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_fini_function(void * message_memory)
{
  messages__action__ExecuteMission_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_members = {
  "messages__action",  // message namespace
  "ExecuteMission_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(messages__action__ExecuteMission_GetResult_Response),
  messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_member_array,  // message members
  messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle = {
  0,
  &messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_GetResult_Response)() {
  messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_Result)();
  if (!messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__action__ExecuteMission_GetResult_Response__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_members = {
  "messages__action",  // service namespace
  "ExecuteMission_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_type_support_handle = {
  0,
  &messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_GetResult)() {
  if (!messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_type_support_handle.typesupport_identifier) {
    messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_GetResult_Response)()->data;
  }

  return &messages__action__detail__execute_mission__rosidl_typesupport_introspection_c__ExecuteMission_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "messages/action/detail/execute_mission__functions.h"
// already included above
// #include "messages/action/detail/execute_mission__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "messages/action/execute_mission.h"
// Member `feedback`
// already included above
// #include "messages/action/detail/execute_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__action__ExecuteMission_FeedbackMessage__init(message_memory);
}

void messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_fini_function(void * message_memory)
{
  messages__action__ExecuteMission_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__action__ExecuteMission_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_members = {
  "messages__action",  // message namespace
  "ExecuteMission_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(messages__action__ExecuteMission_FeedbackMessage),
  messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_member_array,  // message members
  messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_type_support_handle = {
  0,
  &messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_FeedbackMessage)() {
  messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, action, ExecuteMission_Feedback)();
  if (!messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__action__ExecuteMission_FeedbackMessage__rosidl_typesupport_introspection_c__ExecuteMission_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
