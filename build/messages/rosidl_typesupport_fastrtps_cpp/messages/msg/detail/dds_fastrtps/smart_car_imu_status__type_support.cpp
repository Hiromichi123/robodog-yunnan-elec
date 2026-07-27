// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from messages:msg/SmartCarImuStatus.idl
// generated code does not contain a copyright notice
#include "messages/msg/detail/smart_car_imu_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "messages/msg/detail/smart_car_imu_status__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace builtin_interfaces
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const builtin_interfaces::msg::Time &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  builtin_interfaces::msg::Time &);
size_t get_serialized_size(
  const builtin_interfaces::msg::Time &,
  size_t current_alignment);
size_t
max_serialized_size_Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace builtin_interfaces


namespace messages
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_messages
cdr_serialize(
  const messages::msg::SmartCarImuStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.stamp,
    cdr);
  // Member: time_boot_ms
  cdr << ros_message.time_boot_ms;
  // Member: sample_count
  cdr << ros_message.sample_count;
  // Member: overrun_count
  cdr << ros_message.overrun_count;
  // Member: error_count
  cdr << ros_message.error_count;
  // Member: gyro_x_mdps
  cdr << ros_message.gyro_x_mdps;
  // Member: gyro_y_mdps
  cdr << ros_message.gyro_y_mdps;
  // Member: gyro_z_mdps
  cdr << ros_message.gyro_z_mdps;
  // Member: yaw_rate_raw_dps
  cdr << ros_message.yaw_rate_raw_dps;
  // Member: yaw_rate_dps
  cdr << ros_message.yaw_rate_dps;
  // Member: gyro_bias_z_dps
  cdr << ros_message.gyro_bias_z_dps;
  // Member: accel_x_mg
  cdr << ros_message.accel_x_mg;
  // Member: accel_y_mg
  cdr << ros_message.accel_y_mg;
  // Member: accel_z_mg
  cdr << ros_message.accel_z_mg;
  // Member: temperature_c_x100
  cdr << ros_message.temperature_c_x100;
  // Member: calibrated
  cdr << ros_message.calibrated;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_messages
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  messages::msg::SmartCarImuStatus & ros_message)
{
  // Member: stamp
  builtin_interfaces::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.stamp);

  // Member: time_boot_ms
  cdr >> ros_message.time_boot_ms;

  // Member: sample_count
  cdr >> ros_message.sample_count;

  // Member: overrun_count
  cdr >> ros_message.overrun_count;

  // Member: error_count
  cdr >> ros_message.error_count;

  // Member: gyro_x_mdps
  cdr >> ros_message.gyro_x_mdps;

  // Member: gyro_y_mdps
  cdr >> ros_message.gyro_y_mdps;

  // Member: gyro_z_mdps
  cdr >> ros_message.gyro_z_mdps;

  // Member: yaw_rate_raw_dps
  cdr >> ros_message.yaw_rate_raw_dps;

  // Member: yaw_rate_dps
  cdr >> ros_message.yaw_rate_dps;

  // Member: gyro_bias_z_dps
  cdr >> ros_message.gyro_bias_z_dps;

  // Member: accel_x_mg
  cdr >> ros_message.accel_x_mg;

  // Member: accel_y_mg
  cdr >> ros_message.accel_y_mg;

  // Member: accel_z_mg
  cdr >> ros_message.accel_z_mg;

  // Member: temperature_c_x100
  cdr >> ros_message.temperature_c_x100;

  // Member: calibrated
  cdr >> ros_message.calibrated;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_messages
get_serialized_size(
  const messages::msg::SmartCarImuStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: stamp

  current_alignment +=
    builtin_interfaces::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.stamp, current_alignment);
  // Member: time_boot_ms
  {
    size_t item_size = sizeof(ros_message.time_boot_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sample_count
  {
    size_t item_size = sizeof(ros_message.sample_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: overrun_count
  {
    size_t item_size = sizeof(ros_message.overrun_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: error_count
  {
    size_t item_size = sizeof(ros_message.error_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_x_mdps
  {
    size_t item_size = sizeof(ros_message.gyro_x_mdps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_y_mdps
  {
    size_t item_size = sizeof(ros_message.gyro_y_mdps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_z_mdps
  {
    size_t item_size = sizeof(ros_message.gyro_z_mdps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: yaw_rate_raw_dps
  {
    size_t item_size = sizeof(ros_message.yaw_rate_raw_dps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: yaw_rate_dps
  {
    size_t item_size = sizeof(ros_message.yaw_rate_dps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: gyro_bias_z_dps
  {
    size_t item_size = sizeof(ros_message.gyro_bias_z_dps);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: accel_x_mg
  {
    size_t item_size = sizeof(ros_message.accel_x_mg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: accel_y_mg
  {
    size_t item_size = sizeof(ros_message.accel_y_mg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: accel_z_mg
  {
    size_t item_size = sizeof(ros_message.accel_z_mg);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temperature_c_x100
  {
    size_t item_size = sizeof(ros_message.temperature_c_x100);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: calibrated
  {
    size_t item_size = sizeof(ros_message.calibrated);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_messages
max_serialized_size_SmartCarImuStatus(
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


  // Member: stamp
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        builtin_interfaces::msg::typesupport_fastrtps_cpp::max_serialized_size_Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: time_boot_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: sample_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: overrun_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: error_count
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gyro_x_mdps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gyro_y_mdps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gyro_z_mdps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: yaw_rate_raw_dps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: yaw_rate_dps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: gyro_bias_z_dps
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: accel_x_mg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: accel_y_mg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: accel_z_mg
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: temperature_c_x100
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: calibrated
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
    using DataType = messages::msg::SmartCarImuStatus;
    is_plain =
      (
      offsetof(DataType, calibrated) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _SmartCarImuStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const messages::msg::SmartCarImuStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SmartCarImuStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<messages::msg::SmartCarImuStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SmartCarImuStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const messages::msg::SmartCarImuStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SmartCarImuStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SmartCarImuStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SmartCarImuStatus__callbacks = {
  "messages::msg",
  "SmartCarImuStatus",
  _SmartCarImuStatus__cdr_serialize,
  _SmartCarImuStatus__cdr_deserialize,
  _SmartCarImuStatus__get_serialized_size,
  _SmartCarImuStatus__max_serialized_size
};

static rosidl_message_type_support_t _SmartCarImuStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SmartCarImuStatus__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace messages

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_messages
const rosidl_message_type_support_t *
get_message_type_support_handle<messages::msg::SmartCarImuStatus>()
{
  return &messages::msg::typesupport_fastrtps_cpp::_SmartCarImuStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, messages, msg, SmartCarImuStatus)() {
  return &messages::msg::typesupport_fastrtps_cpp::_SmartCarImuStatus__handle;
}

#ifdef __cplusplus
}
#endif
