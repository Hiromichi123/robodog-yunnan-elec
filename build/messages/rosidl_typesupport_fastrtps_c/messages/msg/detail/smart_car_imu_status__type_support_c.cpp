// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from messages:msg/SmartCarImuStatus.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/smart_car_imu_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "messages/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "messages/msg/detail/smart_car_imu_status__struct.h"
#include "messages/msg/detail/smart_car_imu_status__functions.h"
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


using _SmartCarImuStatus__ros_msg_type = messages__msg__SmartCarImuStatus;

static bool _SmartCarImuStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SmartCarImuStatus__ros_msg_type * ros_message = static_cast<const _SmartCarImuStatus__ros_msg_type *>(untyped_ros_message);
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

  // Field name: sample_count
  {
    cdr << ros_message->sample_count;
  }

  // Field name: overrun_count
  {
    cdr << ros_message->overrun_count;
  }

  // Field name: error_count
  {
    cdr << ros_message->error_count;
  }

  // Field name: gyro_x_mdps
  {
    cdr << ros_message->gyro_x_mdps;
  }

  // Field name: gyro_y_mdps
  {
    cdr << ros_message->gyro_y_mdps;
  }

  // Field name: gyro_z_mdps
  {
    cdr << ros_message->gyro_z_mdps;
  }

  // Field name: yaw_rate_raw_dps
  {
    cdr << ros_message->yaw_rate_raw_dps;
  }

  // Field name: yaw_rate_dps
  {
    cdr << ros_message->yaw_rate_dps;
  }

  // Field name: gyro_bias_z_dps
  {
    cdr << ros_message->gyro_bias_z_dps;
  }

  // Field name: accel_x_mg
  {
    cdr << ros_message->accel_x_mg;
  }

  // Field name: accel_y_mg
  {
    cdr << ros_message->accel_y_mg;
  }

  // Field name: accel_z_mg
  {
    cdr << ros_message->accel_z_mg;
  }

  // Field name: temperature_c_x100
  {
    cdr << ros_message->temperature_c_x100;
  }

  // Field name: calibrated
  {
    cdr << ros_message->calibrated;
  }

  return true;
}

static bool _SmartCarImuStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SmartCarImuStatus__ros_msg_type * ros_message = static_cast<_SmartCarImuStatus__ros_msg_type *>(untyped_ros_message);
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

  // Field name: sample_count
  {
    cdr >> ros_message->sample_count;
  }

  // Field name: overrun_count
  {
    cdr >> ros_message->overrun_count;
  }

  // Field name: error_count
  {
    cdr >> ros_message->error_count;
  }

  // Field name: gyro_x_mdps
  {
    cdr >> ros_message->gyro_x_mdps;
  }

  // Field name: gyro_y_mdps
  {
    cdr >> ros_message->gyro_y_mdps;
  }

  // Field name: gyro_z_mdps
  {
    cdr >> ros_message->gyro_z_mdps;
  }

  // Field name: yaw_rate_raw_dps
  {
    cdr >> ros_message->yaw_rate_raw_dps;
  }

  // Field name: yaw_rate_dps
  {
    cdr >> ros_message->yaw_rate_dps;
  }

  // Field name: gyro_bias_z_dps
  {
    cdr >> ros_message->gyro_bias_z_dps;
  }

  // Field name: accel_x_mg
  {
    cdr >> ros_message->accel_x_mg;
  }

  // Field name: accel_y_mg
  {
    cdr >> ros_message->accel_y_mg;
  }

  // Field name: accel_z_mg
  {
    cdr >> ros_message->accel_z_mg;
  }

  // Field name: temperature_c_x100
  {
    cdr >> ros_message->temperature_c_x100;
  }

  // Field name: calibrated
  {
    cdr >> ros_message->calibrated;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t get_serialized_size_messages__msg__SmartCarImuStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SmartCarImuStatus__ros_msg_type * ros_message = static_cast<const _SmartCarImuStatus__ros_msg_type *>(untyped_ros_message);
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
  // field.name sample_count
  {
    size_t item_size = sizeof(ros_message->sample_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name overrun_count
  {
    size_t item_size = sizeof(ros_message->overrun_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name error_count
  {
    size_t item_size = sizeof(ros_message->error_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_x_mdps
  {
    size_t item_size = sizeof(ros_message->gyro_x_mdps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_y_mdps
  {
    size_t item_size = sizeof(ros_message->gyro_y_mdps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_z_mdps
  {
    size_t item_size = sizeof(ros_message->gyro_z_mdps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw_rate_raw_dps
  {
    size_t item_size = sizeof(ros_message->yaw_rate_raw_dps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name yaw_rate_dps
  {
    size_t item_size = sizeof(ros_message->yaw_rate_dps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name gyro_bias_z_dps
  {
    size_t item_size = sizeof(ros_message->gyro_bias_z_dps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name accel_x_mg
  {
    size_t item_size = sizeof(ros_message->accel_x_mg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name accel_y_mg
  {
    size_t item_size = sizeof(ros_message->accel_y_mg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name accel_z_mg
  {
    size_t item_size = sizeof(ros_message->accel_z_mg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name temperature_c_x100
  {
    size_t item_size = sizeof(ros_message->temperature_c_x100);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name calibrated
  {
    size_t item_size = sizeof(ros_message->calibrated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SmartCarImuStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_messages__msg__SmartCarImuStatus(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_messages
size_t max_serialized_size_messages__msg__SmartCarImuStatus(
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
  // member: sample_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: overrun_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: error_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gyro_x_mdps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gyro_y_mdps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gyro_z_mdps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: yaw_rate_raw_dps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: yaw_rate_dps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: gyro_bias_z_dps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: accel_x_mg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: accel_y_mg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: accel_z_mg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: temperature_c_x100
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: calibrated
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = messages__msg__SmartCarImuStatus;
    is_plain =
      (
      offsetof(DataType, calibrated) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SmartCarImuStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_messages__msg__SmartCarImuStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SmartCarImuStatus = {
  "messages::msg",
  "SmartCarImuStatus",
  _SmartCarImuStatus__cdr_serialize,
  _SmartCarImuStatus__cdr_deserialize,
  _SmartCarImuStatus__get_serialized_size,
  _SmartCarImuStatus__max_serialized_size
};

static rosidl_message_type_support_t _SmartCarImuStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SmartCarImuStatus,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, messages, msg, SmartCarImuStatus)() {
  return &_SmartCarImuStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
