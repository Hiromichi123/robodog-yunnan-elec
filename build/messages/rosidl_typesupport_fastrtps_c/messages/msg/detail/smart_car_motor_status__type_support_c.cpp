// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from messages:msg/SmartCarMotorStatus.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/smart_car_motor_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "messages/msg/detail/smart_car_motor_status__struct.h"
#include "messages/msg/detail/smart_car_motor_status__functions.h"
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

#include "builtin_interfaces/msg/detail/time__functions.h"  // stamp

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_messages
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_messages
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_messages
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();


using _SmartCarMotorStatus__ros_msg_type = messages__msg__SmartCarMotorStatus;

static bool _SmartCarMotorStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SmartCarMotorStatus__ros_msg_type * ros_message = static_cast<const _SmartCarMotorStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->stamp, cdr))
    {
      return false;
    }
  }

  // Field name: time_boot_ms
  {
    cdr << ros_message->time_boot_ms;
  }

  // Field name: target_rpm_1
  {
    cdr << ros_message->target_rpm_1;
  }

  // Field name: target_rpm_2
  {
    cdr << ros_message->target_rpm_2;
  }

  // Field name: actual_rpm_1
  {
    cdr << ros_message->actual_rpm_1;
  }

  // Field name: actual_rpm_2
  {
    cdr << ros_message->actual_rpm_2;
  }

  // Field name: current_cmd_1
  {
    cdr << ros_message->current_cmd_1;
  }

  // Field name: current_cmd_2
  {
    cdr << ros_message->current_cmd_2;
  }

  // Field name: feedback_current_1
  {
    cdr << ros_message->feedback_current_1;
  }

  // Field name: feedback_current_2
  {
    cdr << ros_message->feedback_current_2;
  }

  // Field name: angle_1
  {
    cdr << ros_message->angle_1;
  }

  // Field name: angle_2
  {
    cdr << ros_message->angle_2;
  }

  // Field name: online_mask
  {
    cdr << ros_message->online_mask;
  }

  // Field name: can_tx_busy_count
  {
    cdr << ros_message->can_tx_busy_count;
  }

  // Field name: can_error_count
  {
    cdr << ros_message->can_error_count;
  }

  return true;
}

static bool _SmartCarMotorStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SmartCarMotorStatus__ros_msg_type * ros_message = static_cast<_SmartCarMotorStatus__ros_msg_type *>(untyped_ros_message);
  // Field name: stamp
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->stamp))
    {
      return false;
    }
  }

  // Field name: time_boot_ms
  {
    cdr >> ros_message->time_boot_ms;
  }

  // Field name: target_rpm_1
  {
    cdr >> ros_message->target_rpm_1;
  }

  // Field name: target_rpm_2
  {
    cdr >> ros_message->target_rpm_2;
  }

  // Field name: actual_rpm_1
  {
    cdr >> ros_message->actual_rpm_1;
  }

  // Field name: actual_rpm_2
  {
    cdr >> ros_message->actual_rpm_2;
  }

  // Field name: current_cmd_1
  {
    cdr >> ros_message->current_cmd_1;
  }

  // Field name: current_cmd_2
  {
    cdr >> ros_message->current_cmd_2;
  }

  // Field name: feedback_current_1
  {
    cdr >> ros_message->feedback_current_1;
  }

  // Field name: feedback_current_2
  {
    cdr >> ros_message->feedback_current_2;
  }

  // Field name: angle_1
  {
    cdr >> ros_message->angle_1;
  }

  // Field name: angle_2
  {
    cdr >> ros_message->angle_2;
  }

  // Field name: online_mask
  {
    cdr >> ros_message->online_mask;
  }

  // Field name: can_tx_busy_count
  {
    cdr >> ros_message->can_tx_busy_count;
  }

  // Field name: can_error_count
  {
    cdr >> ros_message->can_error_count;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t get_serialized_size_messages__msg__SmartCarMotorStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SmartCarMotorStatus__ros_msg_type * ros_message = static_cast<const _SmartCarMotorStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name stamp

  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->stamp), current_alignment);
  // field.name time_boot_ms
  {
    size_t item_size = sizeof(ros_message->time_boot_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_rpm_1
  {
    size_t item_size = sizeof(ros_message->target_rpm_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_rpm_2
  {
    size_t item_size = sizeof(ros_message->target_rpm_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name actual_rpm_1
  {
    size_t item_size = sizeof(ros_message->actual_rpm_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name actual_rpm_2
  {
    size_t item_size = sizeof(ros_message->actual_rpm_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_cmd_1
  {
    size_t item_size = sizeof(ros_message->current_cmd_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_cmd_2
  {
    size_t item_size = sizeof(ros_message->current_cmd_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name feedback_current_1
  {
    size_t item_size = sizeof(ros_message->feedback_current_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name feedback_current_2
  {
    size_t item_size = sizeof(ros_message->feedback_current_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name angle_1
  {
    size_t item_size = sizeof(ros_message->angle_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name angle_2
  {
    size_t item_size = sizeof(ros_message->angle_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name online_mask
  {
    size_t item_size = sizeof(ros_message->online_mask);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name can_tx_busy_count
  {
    size_t item_size = sizeof(ros_message->can_tx_busy_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name can_error_count
  {
    size_t item_size = sizeof(ros_message->can_error_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SmartCarMotorStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_messages__msg__SmartCarMotorStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t max_serialized_size_messages__msg__SmartCarMotorStatus(
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

  // member: stamp
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: time_boot_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: target_rpm_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: target_rpm_2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: actual_rpm_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: actual_rpm_2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: current_cmd_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: current_cmd_2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: feedback_current_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: feedback_current_2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: angle_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: angle_2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: online_mask
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: can_tx_busy_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: can_error_count
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
    using DataType = messages__msg__SmartCarMotorStatus;
    is_plain =
      (
      offsetof(DataType, can_error_count) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SmartCarMotorStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_messages__msg__SmartCarMotorStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SmartCarMotorStatus = {
  "messages::msg",
  "SmartCarMotorStatus",
  _SmartCarMotorStatus__cdr_serialize,
  _SmartCarMotorStatus__cdr_deserialize,
  _SmartCarMotorStatus__get_serialized_size,
  _SmartCarMotorStatus__max_serialized_size
};

static rosidl_message_type_support_t _SmartCarMotorStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SmartCarMotorStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, messages, msg, SmartCarMotorStatus)() {
  return &_SmartCarMotorStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
