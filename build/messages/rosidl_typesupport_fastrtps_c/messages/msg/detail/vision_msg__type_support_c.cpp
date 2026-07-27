// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from messages:msg/VisionMsg.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/vision_msg__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "messages/msg/detail/vision_msg__struct.h"
#include "messages/msg/detail/vision_msg__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _VisionMsg__ros_msg_type = messages__msg__VisionMsg;

static bool _VisionMsg__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _VisionMsg__ros_msg_type * ros_message = static_cast<const _VisionMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: is_line_detected
  {
    cdr << (ros_message->is_line_detected ? true : false);
  }

  // Field name: lateral_error
  {
    cdr << ros_message->lateral_error;
  }

  // Field name: angle_error
  {
    cdr << ros_message->angle_error;
  }

  // Field name: is_square_detected
  {
    cdr << (ros_message->is_square_detected ? true : false);
  }

  // Field name: center_x1_error
  {
    cdr << ros_message->center_x1_error;
  }

  // Field name: center_y1_error
  {
    cdr << ros_message->center_y1_error;
  }

  // Field name: is_circle_detected
  {
    cdr << (ros_message->is_circle_detected ? true : false);
  }

  // Field name: center_x2_error
  {
    cdr << ros_message->center_x2_error;
  }

  // Field name: center_y2_error
  {
    cdr << ros_message->center_y2_error;
  }

  return true;
}

static bool _VisionMsg__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _VisionMsg__ros_msg_type * ros_message = static_cast<_VisionMsg__ros_msg_type *>(untyped_ros_message);
  // Field name: is_line_detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_line_detected = tmp ? true : false;
  }

  // Field name: lateral_error
  {
    cdr >> ros_message->lateral_error;
  }

  // Field name: angle_error
  {
    cdr >> ros_message->angle_error;
  }

  // Field name: is_square_detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_square_detected = tmp ? true : false;
  }

  // Field name: center_x1_error
  {
    cdr >> ros_message->center_x1_error;
  }

  // Field name: center_y1_error
  {
    cdr >> ros_message->center_y1_error;
  }

  // Field name: is_circle_detected
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->is_circle_detected = tmp ? true : false;
  }

  // Field name: center_x2_error
  {
    cdr >> ros_message->center_x2_error;
  }

  // Field name: center_y2_error
  {
    cdr >> ros_message->center_y2_error;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t get_serialized_size_messages__msg__VisionMsg(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VisionMsg__ros_msg_type * ros_message = static_cast<const _VisionMsg__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name is_line_detected
  {
    size_t item_size = sizeof(ros_message->is_line_detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lateral_error
  {
    size_t item_size = sizeof(ros_message->lateral_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name angle_error
  {
    size_t item_size = sizeof(ros_message->angle_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_square_detected
  {
    size_t item_size = sizeof(ros_message->is_square_detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_x1_error
  {
    size_t item_size = sizeof(ros_message->center_x1_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_y1_error
  {
    size_t item_size = sizeof(ros_message->center_y1_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name is_circle_detected
  {
    size_t item_size = sizeof(ros_message->is_circle_detected);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_x2_error
  {
    size_t item_size = sizeof(ros_message->center_x2_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name center_y2_error
  {
    size_t item_size = sizeof(ros_message->center_y2_error);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _VisionMsg__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_messages__msg__VisionMsg(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t max_serialized_size_messages__msg__VisionMsg(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: is_line_detected
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: lateral_error
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: angle_error
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: is_square_detected
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: center_x1_error
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: center_y1_error
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: is_circle_detected
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: center_x2_error
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: center_y2_error
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = messages__msg__VisionMsg;
    is_plain =
      (
      offsetof(DataType, center_y2_error) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _VisionMsg__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_messages__msg__VisionMsg(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_VisionMsg = {
  "messages::msg",
  "VisionMsg",
  _VisionMsg__cdr_serialize,
  _VisionMsg__cdr_deserialize,
  _VisionMsg__get_serialized_size,
  _VisionMsg__max_serialized_size
};

static rosidl_message_type_support_t _VisionMsg__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VisionMsg,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, messages, msg, VisionMsg)() {
  return &_VisionMsg__type_support;
}

#if defined(__cplusplus)
}
#endif
