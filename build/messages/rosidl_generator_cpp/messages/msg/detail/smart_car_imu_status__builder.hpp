// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/SmartCarImuStatus.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/smart_car_imu_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_SmartCarImuStatus_calibrated
{
public:
  explicit Init_SmartCarImuStatus_calibrated(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  ::messages::msg::SmartCarImuStatus calibrated(::messages::msg::SmartCarImuStatus::_calibrated_type arg)
  {
    msg_.calibrated = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_temperature_c_x100
{
public:
  explicit Init_SmartCarImuStatus_temperature_c_x100(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_calibrated temperature_c_x100(::messages::msg::SmartCarImuStatus::_temperature_c_x100_type arg)
  {
    msg_.temperature_c_x100 = std::move(arg);
    return Init_SmartCarImuStatus_calibrated(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_accel_z_mg
{
public:
  explicit Init_SmartCarImuStatus_accel_z_mg(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_temperature_c_x100 accel_z_mg(::messages::msg::SmartCarImuStatus::_accel_z_mg_type arg)
  {
    msg_.accel_z_mg = std::move(arg);
    return Init_SmartCarImuStatus_temperature_c_x100(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_accel_y_mg
{
public:
  explicit Init_SmartCarImuStatus_accel_y_mg(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_accel_z_mg accel_y_mg(::messages::msg::SmartCarImuStatus::_accel_y_mg_type arg)
  {
    msg_.accel_y_mg = std::move(arg);
    return Init_SmartCarImuStatus_accel_z_mg(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_accel_x_mg
{
public:
  explicit Init_SmartCarImuStatus_accel_x_mg(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_accel_y_mg accel_x_mg(::messages::msg::SmartCarImuStatus::_accel_x_mg_type arg)
  {
    msg_.accel_x_mg = std::move(arg);
    return Init_SmartCarImuStatus_accel_y_mg(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_gyro_bias_z_dps
{
public:
  explicit Init_SmartCarImuStatus_gyro_bias_z_dps(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_accel_x_mg gyro_bias_z_dps(::messages::msg::SmartCarImuStatus::_gyro_bias_z_dps_type arg)
  {
    msg_.gyro_bias_z_dps = std::move(arg);
    return Init_SmartCarImuStatus_accel_x_mg(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_yaw_rate_dps
{
public:
  explicit Init_SmartCarImuStatus_yaw_rate_dps(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_gyro_bias_z_dps yaw_rate_dps(::messages::msg::SmartCarImuStatus::_yaw_rate_dps_type arg)
  {
    msg_.yaw_rate_dps = std::move(arg);
    return Init_SmartCarImuStatus_gyro_bias_z_dps(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_yaw_rate_raw_dps
{
public:
  explicit Init_SmartCarImuStatus_yaw_rate_raw_dps(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_yaw_rate_dps yaw_rate_raw_dps(::messages::msg::SmartCarImuStatus::_yaw_rate_raw_dps_type arg)
  {
    msg_.yaw_rate_raw_dps = std::move(arg);
    return Init_SmartCarImuStatus_yaw_rate_dps(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_gyro_z_mdps
{
public:
  explicit Init_SmartCarImuStatus_gyro_z_mdps(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_yaw_rate_raw_dps gyro_z_mdps(::messages::msg::SmartCarImuStatus::_gyro_z_mdps_type arg)
  {
    msg_.gyro_z_mdps = std::move(arg);
    return Init_SmartCarImuStatus_yaw_rate_raw_dps(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_gyro_y_mdps
{
public:
  explicit Init_SmartCarImuStatus_gyro_y_mdps(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_gyro_z_mdps gyro_y_mdps(::messages::msg::SmartCarImuStatus::_gyro_y_mdps_type arg)
  {
    msg_.gyro_y_mdps = std::move(arg);
    return Init_SmartCarImuStatus_gyro_z_mdps(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_gyro_x_mdps
{
public:
  explicit Init_SmartCarImuStatus_gyro_x_mdps(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_gyro_y_mdps gyro_x_mdps(::messages::msg::SmartCarImuStatus::_gyro_x_mdps_type arg)
  {
    msg_.gyro_x_mdps = std::move(arg);
    return Init_SmartCarImuStatus_gyro_y_mdps(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_error_count
{
public:
  explicit Init_SmartCarImuStatus_error_count(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_gyro_x_mdps error_count(::messages::msg::SmartCarImuStatus::_error_count_type arg)
  {
    msg_.error_count = std::move(arg);
    return Init_SmartCarImuStatus_gyro_x_mdps(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_overrun_count
{
public:
  explicit Init_SmartCarImuStatus_overrun_count(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_error_count overrun_count(::messages::msg::SmartCarImuStatus::_overrun_count_type arg)
  {
    msg_.overrun_count = std::move(arg);
    return Init_SmartCarImuStatus_error_count(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_sample_count
{
public:
  explicit Init_SmartCarImuStatus_sample_count(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_overrun_count sample_count(::messages::msg::SmartCarImuStatus::_sample_count_type arg)
  {
    msg_.sample_count = std::move(arg);
    return Init_SmartCarImuStatus_overrun_count(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_time_boot_ms
{
public:
  explicit Init_SmartCarImuStatus_time_boot_ms(::messages::msg::SmartCarImuStatus & msg)
  : msg_(msg)
  {}
  Init_SmartCarImuStatus_sample_count time_boot_ms(::messages::msg::SmartCarImuStatus::_time_boot_ms_type arg)
  {
    msg_.time_boot_ms = std::move(arg);
    return Init_SmartCarImuStatus_sample_count(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

class Init_SmartCarImuStatus_stamp
{
public:
  Init_SmartCarImuStatus_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartCarImuStatus_time_boot_ms stamp(::messages::msg::SmartCarImuStatus::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_SmartCarImuStatus_time_boot_ms(msg_);
  }

private:
  ::messages::msg::SmartCarImuStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::SmartCarImuStatus>()
{
  return messages::msg::builder::Init_SmartCarImuStatus_stamp();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__SMART_CAR_IMU_STATUS__BUILDER_HPP_
