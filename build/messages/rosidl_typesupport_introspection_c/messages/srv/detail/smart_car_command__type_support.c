// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from messages:srv/SmartCarCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "messages/srv/detail/smart_car_command__rosidl_typesupport_introspection_c.h"
#include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "messages/srv/detail/smart_car_command__functions.h"
#include "messages/srv/detail/smart_car_command__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__srv__SmartCarCommand_Request__init(message_memory);
}

void messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_fini_function(void * message_memory)
{
  messages__srv__SmartCarCommand_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_message_member_array[5] = {
  {
    "command",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__srv__SmartCarCommand_Request, command),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "param1",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__srv__SmartCarCommand_Request, param1),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "param2",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__srv__SmartCarCommand_Request, param2),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "param3",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__srv__SmartCarCommand_Request, param3),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "param4",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__srv__SmartCarCommand_Request, param4),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_message_members = {
  "messages__srv",  // message namespace
  "SmartCarCommand_Request",  // message name
  5,  // number of fields
  sizeof(messages__srv__SmartCarCommand_Request),
  messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_message_member_array,  // message members
  messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_message_type_support_handle = {
  0,
  &messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, srv, SmartCarCommand_Request)() {
  if (!messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_message_type_support_handle.typesupport_identifier) {
    messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__srv__SmartCarCommand_Request__rosidl_typesupport_introspection_c__SmartCarCommand_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "messages/srv/detail/smart_car_command__rosidl_typesupport_introspection_c.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "messages/srv/detail/smart_car_command__functions.h"
// already included above
// #include "messages/srv/detail/smart_car_command__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  messages__srv__SmartCarCommand_Response__init(message_memory);
}

void messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_fini_function(void * message_memory)
{
  messages__srv__SmartCarCommand_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(messages__srv__SmartCarCommand_Response, accepted),  // bytes offset in struct
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
    offsetof(messages__srv__SmartCarCommand_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_message_members = {
  "messages__srv",  // message namespace
  "SmartCarCommand_Response",  // message name
  2,  // number of fields
  sizeof(messages__srv__SmartCarCommand_Response),
  messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_message_member_array,  // message members
  messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_message_type_support_handle = {
  0,
  &messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, srv, SmartCarCommand_Response)() {
  if (!messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_message_type_support_handle.typesupport_identifier) {
    messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &messages__srv__SmartCarCommand_Response__rosidl_typesupport_introspection_c__SmartCarCommand_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "messages/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "messages/srv/detail/smart_car_command__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers messages__srv__detail__smart_car_command__rosidl_typesupport_introspection_c__SmartCarCommand_service_members = {
  "messages__srv",  // service namespace
  "SmartCarCommand",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // messages__srv__detail__smart_car_command__rosidl_typesupport_introspection_c__SmartCarCommand_Request_message_type_support_handle,
  NULL  // response message
  // messages__srv__detail__smart_car_command__rosidl_typesupport_introspection_c__SmartCarCommand_Response_message_type_support_handle
};

static rosidl_service_type_support_t messages__srv__detail__smart_car_command__rosidl_typesupport_introspection_c__SmartCarCommand_service_type_support_handle = {
  0,
  &messages__srv__detail__smart_car_command__rosidl_typesupport_introspection_c__SmartCarCommand_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, srv, SmartCarCommand_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, srv, SmartCarCommand_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_messages
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, srv, SmartCarCommand)() {
  if (!messages__srv__detail__smart_car_command__rosidl_typesupport_introspection_c__SmartCarCommand_service_type_support_handle.typesupport_identifier) {
    messages__srv__detail__smart_car_command__rosidl_typesupport_introspection_c__SmartCarCommand_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)messages__srv__detail__smart_car_command__rosidl_typesupport_introspection_c__SmartCarCommand_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, srv, SmartCarCommand_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, messages, srv, SmartCarCommand_Response)()->data;
  }

  return &messages__srv__detail__smart_car_command__rosidl_typesupport_introspection_c__SmartCarCommand_service_type_support_handle;
}
