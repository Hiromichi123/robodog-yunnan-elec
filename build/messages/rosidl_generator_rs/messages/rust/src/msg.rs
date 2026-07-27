pub mod rmw {
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__msg__VisionMsg() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__msg__VisionMsg__init(msg: *mut VisionMsg) -> bool;
    fn messages__msg__VisionMsg__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<VisionMsg>, size: usize) -> bool;
    fn messages__msg__VisionMsg__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<VisionMsg>);
    fn messages__msg__VisionMsg__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<VisionMsg>, out_seq: *mut rosidl_runtime_rs::Sequence<VisionMsg>) -> bool;
}

// Corresponds to messages__msg__VisionMsg
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VisionMsg {
    pub is_line_detected: bool,
    pub lateral_error: i32,
    pub angle_error: f32,
    pub is_square_detected: bool,
    pub center_x1_error: i32,
    pub center_y1_error: i32,
    pub is_circle_detected: bool,
    pub center_x2_error: i32,
    pub center_y2_error: i32,
}



impl Default for VisionMsg {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__msg__VisionMsg__init(&mut msg as *mut _) {
        panic!("Call to messages__msg__VisionMsg__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for VisionMsg {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__VisionMsg__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__VisionMsg__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__VisionMsg__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for VisionMsg {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for VisionMsg where Self: Sized {
  const TYPE_NAME: &'static str = "messages/msg/VisionMsg";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__msg__VisionMsg() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__msg__Vision() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__msg__Vision__init(msg: *mut Vision) -> bool;
    fn messages__msg__Vision__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Vision>, size: usize) -> bool;
    fn messages__msg__Vision__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Vision>);
    fn messages__msg__Vision__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Vision>, out_seq: *mut rosidl_runtime_rs::Sequence<Vision>) -> bool;
}

// Corresponds to messages__msg__Vision
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Vision {
    pub is_detected: bool,
    pub center_x: i32,
    pub center_y: i32,
    pub center_x1_error: i32,
    pub label: rosidl_runtime_rs::String,
}



impl Default for Vision {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__msg__Vision__init(&mut msg as *mut _) {
        panic!("Call to messages__msg__Vision__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Vision {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__Vision__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__Vision__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__Vision__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Vision {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Vision where Self: Sized {
  const TYPE_NAME: &'static str = "messages/msg/Vision";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__msg__Vision() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarControlSetpoint() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__msg__SmartCarControlSetpoint__init(msg: *mut SmartCarControlSetpoint) -> bool;
    fn messages__msg__SmartCarControlSetpoint__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartCarControlSetpoint>, size: usize) -> bool;
    fn messages__msg__SmartCarControlSetpoint__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartCarControlSetpoint>);
    fn messages__msg__SmartCarControlSetpoint__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartCarControlSetpoint>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartCarControlSetpoint>) -> bool;
}

// Corresponds to messages__msg__SmartCarControlSetpoint
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarControlSetpoint {
    pub mode: u8,
    pub flags: u16,
    pub target_speed_mps: f32,
    pub target_curvature: f32,
    pub target_yaw_rate_dps: f32,
    pub target_accel_mps2: f32,
}

impl SmartCarControlSetpoint {
    pub const SMART_CAR_MODE_IDLE: u8 = 0;
    pub const SMART_CAR_MODE_MANUAL: u8 = 1;
    pub const SMART_CAR_MODE_AUTO: u8 = 2;
    pub const SMART_CAR_MODE_CALIB: u8 = 3;
    pub const SMART_CAR_CONTROL_FLAG_ENABLE: u16 = 1;
    pub const SMART_CAR_CONTROL_FLAG_BRAKE: u16 = 2;
    pub const SMART_CAR_CONTROL_FLAG_REVERSE: u16 = 4;
    pub const SMART_CAR_CONTROL_FLAG_HOLD: u16 = 8;
}


impl Default for SmartCarControlSetpoint {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__msg__SmartCarControlSetpoint__init(&mut msg as *mut _) {
        panic!("Call to messages__msg__SmartCarControlSetpoint__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartCarControlSetpoint {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarControlSetpoint__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarControlSetpoint__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarControlSetpoint__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartCarControlSetpoint {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartCarControlSetpoint where Self: Sized {
  const TYPE_NAME: &'static str = "messages/msg/SmartCarControlSetpoint";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarControlSetpoint() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarStatus() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__msg__SmartCarStatus__init(msg: *mut SmartCarStatus) -> bool;
    fn messages__msg__SmartCarStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartCarStatus>, size: usize) -> bool;
    fn messages__msg__SmartCarStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartCarStatus>);
    fn messages__msg__SmartCarStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartCarStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartCarStatus>) -> bool;
}

// Corresponds to messages__msg__SmartCarStatus
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarStatus {
    pub stamp: builtin_interfaces::msg::rmw::Time,
    pub time_boot_ms: u32,
    pub mode: u8,
    pub state: u8,
    pub fault_flags: u32,
    pub warn_flags: u32,
    pub cmd_age_ms: u16,
    pub control_loop_hz: u16,
    pub imu_online: u8,
    pub can_online: u8,
    pub host_online: u8,
    pub servo_online: u8,
    pub motor_online_mask: u8,
}

impl SmartCarStatus {
    pub const SMART_CAR_MODE_IDLE: u8 = 0;
    pub const SMART_CAR_MODE_MANUAL: u8 = 1;
    pub const SMART_CAR_MODE_AUTO: u8 = 2;
    pub const SMART_CAR_MODE_CALIB: u8 = 3;
    pub const SMART_CAR_STATE_IDLE: u8 = 0;
    pub const SMART_CAR_STATE_ARMED: u8 = 1;
    pub const SMART_CAR_STATE_RUNNING: u8 = 2;
    pub const SMART_CAR_STATE_FAULT: u8 = 3;
    pub const SMART_CAR_STATE_CALIB: u8 = 4;
    pub const SMART_CAR_FAULT_CMD_TIMEOUT: u32 = 1;
    pub const SMART_CAR_FAULT_MOTOR1_OFFLINE: u32 = 2;
    pub const SMART_CAR_FAULT_MOTOR2_OFFLINE: u32 = 4;
    pub const SMART_CAR_FAULT_IMU_NOT_READY: u32 = 8;
    pub const SMART_CAR_FAULT_CAN_ERROR: u32 = 16;
    pub const SMART_CAR_FAULT_SERVO_CLAMPED: u32 = 32;
}


impl Default for SmartCarStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__msg__SmartCarStatus__init(&mut msg as *mut _) {
        panic!("Call to messages__msg__SmartCarStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartCarStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartCarStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartCarStatus where Self: Sized {
  const TYPE_NAME: &'static str = "messages/msg/SmartCarStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarStatus() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarMotionState() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__msg__SmartCarMotionState__init(msg: *mut SmartCarMotionState) -> bool;
    fn messages__msg__SmartCarMotionState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartCarMotionState>, size: usize) -> bool;
    fn messages__msg__SmartCarMotionState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartCarMotionState>);
    fn messages__msg__SmartCarMotionState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartCarMotionState>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartCarMotionState>) -> bool;
}

// Corresponds to messages__msg__SmartCarMotionState
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarMotionState {
    pub stamp: builtin_interfaces::msg::rmw::Time,
    pub time_boot_ms: u32,
    pub speed_mps: f32,
    pub target_speed_mps: f32,
    pub yaw_rate_dps: f32,
    pub yaw_deg: f32,
    pub curvature_meas: f32,
    pub curvature_cmd: f32,
    pub steering_angle_deg: f32,
    pub steering_pwm_us: u16,
    pub steering_clamped: u8,
}



impl Default for SmartCarMotionState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__msg__SmartCarMotionState__init(&mut msg as *mut _) {
        panic!("Call to messages__msg__SmartCarMotionState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartCarMotionState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarMotionState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarMotionState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarMotionState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartCarMotionState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartCarMotionState where Self: Sized {
  const TYPE_NAME: &'static str = "messages/msg/SmartCarMotionState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarMotionState() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarMotorStatus() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__msg__SmartCarMotorStatus__init(msg: *mut SmartCarMotorStatus) -> bool;
    fn messages__msg__SmartCarMotorStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartCarMotorStatus>, size: usize) -> bool;
    fn messages__msg__SmartCarMotorStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartCarMotorStatus>);
    fn messages__msg__SmartCarMotorStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartCarMotorStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartCarMotorStatus>) -> bool;
}

// Corresponds to messages__msg__SmartCarMotorStatus
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarMotorStatus {
    pub stamp: builtin_interfaces::msg::rmw::Time,
    pub time_boot_ms: u32,
    pub target_rpm_1: i16,
    pub target_rpm_2: i16,
    pub actual_rpm_1: i16,
    pub actual_rpm_2: i16,
    pub current_cmd_1: i16,
    pub current_cmd_2: i16,
    pub feedback_current_1: i16,
    pub feedback_current_2: i16,
    pub angle_1: u16,
    pub angle_2: u16,
    pub online_mask: u8,
    pub can_tx_busy_count: u32,
    pub can_error_count: u32,
}



impl Default for SmartCarMotorStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__msg__SmartCarMotorStatus__init(&mut msg as *mut _) {
        panic!("Call to messages__msg__SmartCarMotorStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartCarMotorStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarMotorStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarMotorStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarMotorStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartCarMotorStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartCarMotorStatus where Self: Sized {
  const TYPE_NAME: &'static str = "messages/msg/SmartCarMotorStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarMotorStatus() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarImuStatus() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__msg__SmartCarImuStatus__init(msg: *mut SmartCarImuStatus) -> bool;
    fn messages__msg__SmartCarImuStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartCarImuStatus>, size: usize) -> bool;
    fn messages__msg__SmartCarImuStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartCarImuStatus>);
    fn messages__msg__SmartCarImuStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartCarImuStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartCarImuStatus>) -> bool;
}

// Corresponds to messages__msg__SmartCarImuStatus
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarImuStatus {
    pub stamp: builtin_interfaces::msg::rmw::Time,
    pub time_boot_ms: u32,
    pub sample_count: u32,
    pub overrun_count: u32,
    pub error_count: u32,
    pub gyro_x_mdps: i32,
    pub gyro_y_mdps: i32,
    pub gyro_z_mdps: i32,
    pub yaw_rate_raw_dps: f32,
    pub yaw_rate_dps: f32,
    pub gyro_bias_z_dps: f32,
    pub accel_x_mg: i16,
    pub accel_y_mg: i16,
    pub accel_z_mg: i16,
    pub temperature_c_x100: i16,
    pub calibrated: u8,
}



impl Default for SmartCarImuStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__msg__SmartCarImuStatus__init(&mut msg as *mut _) {
        panic!("Call to messages__msg__SmartCarImuStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartCarImuStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarImuStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarImuStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarImuStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartCarImuStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartCarImuStatus where Self: Sized {
  const TYPE_NAME: &'static str = "messages/msg/SmartCarImuStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarImuStatus() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarCalibStatus() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__msg__SmartCarCalibStatus__init(msg: *mut SmartCarCalibStatus) -> bool;
    fn messages__msg__SmartCarCalibStatus__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartCarCalibStatus>, size: usize) -> bool;
    fn messages__msg__SmartCarCalibStatus__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartCarCalibStatus>);
    fn messages__msg__SmartCarCalibStatus__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartCarCalibStatus>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartCarCalibStatus>) -> bool;
}

// Corresponds to messages__msg__SmartCarCalibStatus
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarCalibStatus {
    pub stamp: builtin_interfaces::msg::rmw::Time,
    pub time_boot_ms: u32,
    pub point_id: u32,
    pub sweep_index: u32,
    pub sweep_count: u32,
    pub valid_count: u32,
    pub invalid_count: u32,
    pub v_center_avg: f32,
    pub yaw_rate_avg: f32,
    pub kappa_avg: f32,
    pub radius_est: f32,
    pub target_rpm: i16,
    pub servo_pwm_us: u16,
    pub state: u8,
    pub sweep_enabled: u8,
    pub yaw_sign_inverted: u8,
}



impl Default for SmartCarCalibStatus {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__msg__SmartCarCalibStatus__init(&mut msg as *mut _) {
        panic!("Call to messages__msg__SmartCarCalibStatus__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartCarCalibStatus {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarCalibStatus__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarCalibStatus__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__SmartCarCalibStatus__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartCarCalibStatus {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartCarCalibStatus where Self: Sized {
  const TYPE_NAME: &'static str = "messages/msg/SmartCarCalibStatus";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__msg__SmartCarCalibStatus() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__msg__PlatformTarget() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__msg__PlatformTarget__init(msg: *mut PlatformTarget) -> bool;
    fn messages__msg__PlatformTarget__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<PlatformTarget>, size: usize) -> bool;
    fn messages__msg__PlatformTarget__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<PlatformTarget>);
    fn messages__msg__PlatformTarget__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<PlatformTarget>, out_seq: *mut rosidl_runtime_rs::Sequence<PlatformTarget>) -> bool;
}

// Corresponds to messages__msg__PlatformTarget
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlatformTarget {
    pub platform: u8,
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub yaw: f32,
    pub vx_mps: f32,
    pub vy_mps: f32,
    pub vz_mps: f32,
    pub speed_mps: f32,
    pub curvature: f32,
    pub yaw_rate_dps: f32,
}

impl PlatformTarget {
    pub const PLATFORM_CAR: u8 = 0;
    pub const PLATFORM_FLIGHT: u8 = 1;
}


impl Default for PlatformTarget {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__msg__PlatformTarget__init(&mut msg as *mut _) {
        panic!("Call to messages__msg__PlatformTarget__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for PlatformTarget {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__PlatformTarget__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__PlatformTarget__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__msg__PlatformTarget__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for PlatformTarget {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for PlatformTarget where Self: Sized {
  const TYPE_NAME: &'static str = "messages/msg/PlatformTarget";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__msg__PlatformTarget() }
  }
}


}  // mod rmw


#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct VisionMsg {
    pub is_line_detected: bool,
    pub lateral_error: i32,
    pub angle_error: f32,
    pub is_square_detected: bool,
    pub center_x1_error: i32,
    pub center_y1_error: i32,
    pub is_circle_detected: bool,
    pub center_x2_error: i32,
    pub center_y2_error: i32,
}



impl Default for VisionMsg {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::msg::rmw::VisionMsg::default())
  }
}

impl rosidl_runtime_rs::Message for VisionMsg {
  type RmwMsg = crate::msg::rmw::VisionMsg;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        is_line_detected: msg.is_line_detected,
        lateral_error: msg.lateral_error,
        angle_error: msg.angle_error,
        is_square_detected: msg.is_square_detected,
        center_x1_error: msg.center_x1_error,
        center_y1_error: msg.center_y1_error,
        is_circle_detected: msg.is_circle_detected,
        center_x2_error: msg.center_x2_error,
        center_y2_error: msg.center_y2_error,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      is_line_detected: msg.is_line_detected,
      lateral_error: msg.lateral_error,
      angle_error: msg.angle_error,
      is_square_detected: msg.is_square_detected,
      center_x1_error: msg.center_x1_error,
      center_y1_error: msg.center_y1_error,
      is_circle_detected: msg.is_circle_detected,
      center_x2_error: msg.center_x2_error,
      center_y2_error: msg.center_y2_error,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      is_line_detected: msg.is_line_detected,
      lateral_error: msg.lateral_error,
      angle_error: msg.angle_error,
      is_square_detected: msg.is_square_detected,
      center_x1_error: msg.center_x1_error,
      center_y1_error: msg.center_y1_error,
      is_circle_detected: msg.is_circle_detected,
      center_x2_error: msg.center_x2_error,
      center_y2_error: msg.center_y2_error,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Vision {
    pub is_detected: bool,
    pub center_x: i32,
    pub center_y: i32,
    pub center_x1_error: i32,
    pub label: std::string::String,
}



impl Default for Vision {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::msg::rmw::Vision::default())
  }
}

impl rosidl_runtime_rs::Message for Vision {
  type RmwMsg = crate::msg::rmw::Vision;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        is_detected: msg.is_detected,
        center_x: msg.center_x,
        center_y: msg.center_y,
        center_x1_error: msg.center_x1_error,
        label: msg.label.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      is_detected: msg.is_detected,
      center_x: msg.center_x,
      center_y: msg.center_y,
      center_x1_error: msg.center_x1_error,
        label: msg.label.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      is_detected: msg.is_detected,
      center_x: msg.center_x,
      center_y: msg.center_y,
      center_x1_error: msg.center_x1_error,
      label: msg.label.to_string(),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarControlSetpoint {
    pub mode: u8,
    pub flags: u16,
    pub target_speed_mps: f32,
    pub target_curvature: f32,
    pub target_yaw_rate_dps: f32,
    pub target_accel_mps2: f32,
}

impl SmartCarControlSetpoint {
    pub const SMART_CAR_MODE_IDLE: u8 = 0;
    pub const SMART_CAR_MODE_MANUAL: u8 = 1;
    pub const SMART_CAR_MODE_AUTO: u8 = 2;
    pub const SMART_CAR_MODE_CALIB: u8 = 3;
    pub const SMART_CAR_CONTROL_FLAG_ENABLE: u16 = 1;
    pub const SMART_CAR_CONTROL_FLAG_BRAKE: u16 = 2;
    pub const SMART_CAR_CONTROL_FLAG_REVERSE: u16 = 4;
    pub const SMART_CAR_CONTROL_FLAG_HOLD: u16 = 8;
}


impl Default for SmartCarControlSetpoint {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::msg::rmw::SmartCarControlSetpoint::default())
  }
}

impl rosidl_runtime_rs::Message for SmartCarControlSetpoint {
  type RmwMsg = crate::msg::rmw::SmartCarControlSetpoint;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        mode: msg.mode,
        flags: msg.flags,
        target_speed_mps: msg.target_speed_mps,
        target_curvature: msg.target_curvature,
        target_yaw_rate_dps: msg.target_yaw_rate_dps,
        target_accel_mps2: msg.target_accel_mps2,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      mode: msg.mode,
      flags: msg.flags,
      target_speed_mps: msg.target_speed_mps,
      target_curvature: msg.target_curvature,
      target_yaw_rate_dps: msg.target_yaw_rate_dps,
      target_accel_mps2: msg.target_accel_mps2,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      mode: msg.mode,
      flags: msg.flags,
      target_speed_mps: msg.target_speed_mps,
      target_curvature: msg.target_curvature,
      target_yaw_rate_dps: msg.target_yaw_rate_dps,
      target_accel_mps2: msg.target_accel_mps2,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarStatus {
    pub stamp: builtin_interfaces::msg::Time,
    pub time_boot_ms: u32,
    pub mode: u8,
    pub state: u8,
    pub fault_flags: u32,
    pub warn_flags: u32,
    pub cmd_age_ms: u16,
    pub control_loop_hz: u16,
    pub imu_online: u8,
    pub can_online: u8,
    pub host_online: u8,
    pub servo_online: u8,
    pub motor_online_mask: u8,
}

impl SmartCarStatus {
    pub const SMART_CAR_MODE_IDLE: u8 = 0;
    pub const SMART_CAR_MODE_MANUAL: u8 = 1;
    pub const SMART_CAR_MODE_AUTO: u8 = 2;
    pub const SMART_CAR_MODE_CALIB: u8 = 3;
    pub const SMART_CAR_STATE_IDLE: u8 = 0;
    pub const SMART_CAR_STATE_ARMED: u8 = 1;
    pub const SMART_CAR_STATE_RUNNING: u8 = 2;
    pub const SMART_CAR_STATE_FAULT: u8 = 3;
    pub const SMART_CAR_STATE_CALIB: u8 = 4;
    pub const SMART_CAR_FAULT_CMD_TIMEOUT: u32 = 1;
    pub const SMART_CAR_FAULT_MOTOR1_OFFLINE: u32 = 2;
    pub const SMART_CAR_FAULT_MOTOR2_OFFLINE: u32 = 4;
    pub const SMART_CAR_FAULT_IMU_NOT_READY: u32 = 8;
    pub const SMART_CAR_FAULT_CAN_ERROR: u32 = 16;
    pub const SMART_CAR_FAULT_SERVO_CLAMPED: u32 = 32;
}


impl Default for SmartCarStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::msg::rmw::SmartCarStatus::default())
  }
}

impl rosidl_runtime_rs::Message for SmartCarStatus {
  type RmwMsg = crate::msg::rmw::SmartCarStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        time_boot_ms: msg.time_boot_ms,
        mode: msg.mode,
        state: msg.state,
        fault_flags: msg.fault_flags,
        warn_flags: msg.warn_flags,
        cmd_age_ms: msg.cmd_age_ms,
        control_loop_hz: msg.control_loop_hz,
        imu_online: msg.imu_online,
        can_online: msg.can_online,
        host_online: msg.host_online,
        servo_online: msg.servo_online,
        motor_online_mask: msg.motor_online_mask,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      time_boot_ms: msg.time_boot_ms,
      mode: msg.mode,
      state: msg.state,
      fault_flags: msg.fault_flags,
      warn_flags: msg.warn_flags,
      cmd_age_ms: msg.cmd_age_ms,
      control_loop_hz: msg.control_loop_hz,
      imu_online: msg.imu_online,
      can_online: msg.can_online,
      host_online: msg.host_online,
      servo_online: msg.servo_online,
      motor_online_mask: msg.motor_online_mask,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      time_boot_ms: msg.time_boot_ms,
      mode: msg.mode,
      state: msg.state,
      fault_flags: msg.fault_flags,
      warn_flags: msg.warn_flags,
      cmd_age_ms: msg.cmd_age_ms,
      control_loop_hz: msg.control_loop_hz,
      imu_online: msg.imu_online,
      can_online: msg.can_online,
      host_online: msg.host_online,
      servo_online: msg.servo_online,
      motor_online_mask: msg.motor_online_mask,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarMotionState {
    pub stamp: builtin_interfaces::msg::Time,
    pub time_boot_ms: u32,
    pub speed_mps: f32,
    pub target_speed_mps: f32,
    pub yaw_rate_dps: f32,
    pub yaw_deg: f32,
    pub curvature_meas: f32,
    pub curvature_cmd: f32,
    pub steering_angle_deg: f32,
    pub steering_pwm_us: u16,
    pub steering_clamped: u8,
}



impl Default for SmartCarMotionState {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::msg::rmw::SmartCarMotionState::default())
  }
}

impl rosidl_runtime_rs::Message for SmartCarMotionState {
  type RmwMsg = crate::msg::rmw::SmartCarMotionState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        time_boot_ms: msg.time_boot_ms,
        speed_mps: msg.speed_mps,
        target_speed_mps: msg.target_speed_mps,
        yaw_rate_dps: msg.yaw_rate_dps,
        yaw_deg: msg.yaw_deg,
        curvature_meas: msg.curvature_meas,
        curvature_cmd: msg.curvature_cmd,
        steering_angle_deg: msg.steering_angle_deg,
        steering_pwm_us: msg.steering_pwm_us,
        steering_clamped: msg.steering_clamped,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      time_boot_ms: msg.time_boot_ms,
      speed_mps: msg.speed_mps,
      target_speed_mps: msg.target_speed_mps,
      yaw_rate_dps: msg.yaw_rate_dps,
      yaw_deg: msg.yaw_deg,
      curvature_meas: msg.curvature_meas,
      curvature_cmd: msg.curvature_cmd,
      steering_angle_deg: msg.steering_angle_deg,
      steering_pwm_us: msg.steering_pwm_us,
      steering_clamped: msg.steering_clamped,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      time_boot_ms: msg.time_boot_ms,
      speed_mps: msg.speed_mps,
      target_speed_mps: msg.target_speed_mps,
      yaw_rate_dps: msg.yaw_rate_dps,
      yaw_deg: msg.yaw_deg,
      curvature_meas: msg.curvature_meas,
      curvature_cmd: msg.curvature_cmd,
      steering_angle_deg: msg.steering_angle_deg,
      steering_pwm_us: msg.steering_pwm_us,
      steering_clamped: msg.steering_clamped,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarMotorStatus {
    pub stamp: builtin_interfaces::msg::Time,
    pub time_boot_ms: u32,
    pub target_rpm_1: i16,
    pub target_rpm_2: i16,
    pub actual_rpm_1: i16,
    pub actual_rpm_2: i16,
    pub current_cmd_1: i16,
    pub current_cmd_2: i16,
    pub feedback_current_1: i16,
    pub feedback_current_2: i16,
    pub angle_1: u16,
    pub angle_2: u16,
    pub online_mask: u8,
    pub can_tx_busy_count: u32,
    pub can_error_count: u32,
}



impl Default for SmartCarMotorStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::msg::rmw::SmartCarMotorStatus::default())
  }
}

impl rosidl_runtime_rs::Message for SmartCarMotorStatus {
  type RmwMsg = crate::msg::rmw::SmartCarMotorStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        time_boot_ms: msg.time_boot_ms,
        target_rpm_1: msg.target_rpm_1,
        target_rpm_2: msg.target_rpm_2,
        actual_rpm_1: msg.actual_rpm_1,
        actual_rpm_2: msg.actual_rpm_2,
        current_cmd_1: msg.current_cmd_1,
        current_cmd_2: msg.current_cmd_2,
        feedback_current_1: msg.feedback_current_1,
        feedback_current_2: msg.feedback_current_2,
        angle_1: msg.angle_1,
        angle_2: msg.angle_2,
        online_mask: msg.online_mask,
        can_tx_busy_count: msg.can_tx_busy_count,
        can_error_count: msg.can_error_count,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      time_boot_ms: msg.time_boot_ms,
      target_rpm_1: msg.target_rpm_1,
      target_rpm_2: msg.target_rpm_2,
      actual_rpm_1: msg.actual_rpm_1,
      actual_rpm_2: msg.actual_rpm_2,
      current_cmd_1: msg.current_cmd_1,
      current_cmd_2: msg.current_cmd_2,
      feedback_current_1: msg.feedback_current_1,
      feedback_current_2: msg.feedback_current_2,
      angle_1: msg.angle_1,
      angle_2: msg.angle_2,
      online_mask: msg.online_mask,
      can_tx_busy_count: msg.can_tx_busy_count,
      can_error_count: msg.can_error_count,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      time_boot_ms: msg.time_boot_ms,
      target_rpm_1: msg.target_rpm_1,
      target_rpm_2: msg.target_rpm_2,
      actual_rpm_1: msg.actual_rpm_1,
      actual_rpm_2: msg.actual_rpm_2,
      current_cmd_1: msg.current_cmd_1,
      current_cmd_2: msg.current_cmd_2,
      feedback_current_1: msg.feedback_current_1,
      feedback_current_2: msg.feedback_current_2,
      angle_1: msg.angle_1,
      angle_2: msg.angle_2,
      online_mask: msg.online_mask,
      can_tx_busy_count: msg.can_tx_busy_count,
      can_error_count: msg.can_error_count,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarImuStatus {
    pub stamp: builtin_interfaces::msg::Time,
    pub time_boot_ms: u32,
    pub sample_count: u32,
    pub overrun_count: u32,
    pub error_count: u32,
    pub gyro_x_mdps: i32,
    pub gyro_y_mdps: i32,
    pub gyro_z_mdps: i32,
    pub yaw_rate_raw_dps: f32,
    pub yaw_rate_dps: f32,
    pub gyro_bias_z_dps: f32,
    pub accel_x_mg: i16,
    pub accel_y_mg: i16,
    pub accel_z_mg: i16,
    pub temperature_c_x100: i16,
    pub calibrated: u8,
}



impl Default for SmartCarImuStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::msg::rmw::SmartCarImuStatus::default())
  }
}

impl rosidl_runtime_rs::Message for SmartCarImuStatus {
  type RmwMsg = crate::msg::rmw::SmartCarImuStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        time_boot_ms: msg.time_boot_ms,
        sample_count: msg.sample_count,
        overrun_count: msg.overrun_count,
        error_count: msg.error_count,
        gyro_x_mdps: msg.gyro_x_mdps,
        gyro_y_mdps: msg.gyro_y_mdps,
        gyro_z_mdps: msg.gyro_z_mdps,
        yaw_rate_raw_dps: msg.yaw_rate_raw_dps,
        yaw_rate_dps: msg.yaw_rate_dps,
        gyro_bias_z_dps: msg.gyro_bias_z_dps,
        accel_x_mg: msg.accel_x_mg,
        accel_y_mg: msg.accel_y_mg,
        accel_z_mg: msg.accel_z_mg,
        temperature_c_x100: msg.temperature_c_x100,
        calibrated: msg.calibrated,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      time_boot_ms: msg.time_boot_ms,
      sample_count: msg.sample_count,
      overrun_count: msg.overrun_count,
      error_count: msg.error_count,
      gyro_x_mdps: msg.gyro_x_mdps,
      gyro_y_mdps: msg.gyro_y_mdps,
      gyro_z_mdps: msg.gyro_z_mdps,
      yaw_rate_raw_dps: msg.yaw_rate_raw_dps,
      yaw_rate_dps: msg.yaw_rate_dps,
      gyro_bias_z_dps: msg.gyro_bias_z_dps,
      accel_x_mg: msg.accel_x_mg,
      accel_y_mg: msg.accel_y_mg,
      accel_z_mg: msg.accel_z_mg,
      temperature_c_x100: msg.temperature_c_x100,
      calibrated: msg.calibrated,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      time_boot_ms: msg.time_boot_ms,
      sample_count: msg.sample_count,
      overrun_count: msg.overrun_count,
      error_count: msg.error_count,
      gyro_x_mdps: msg.gyro_x_mdps,
      gyro_y_mdps: msg.gyro_y_mdps,
      gyro_z_mdps: msg.gyro_z_mdps,
      yaw_rate_raw_dps: msg.yaw_rate_raw_dps,
      yaw_rate_dps: msg.yaw_rate_dps,
      gyro_bias_z_dps: msg.gyro_bias_z_dps,
      accel_x_mg: msg.accel_x_mg,
      accel_y_mg: msg.accel_y_mg,
      accel_z_mg: msg.accel_z_mg,
      temperature_c_x100: msg.temperature_c_x100,
      calibrated: msg.calibrated,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarCalibStatus {
    pub stamp: builtin_interfaces::msg::Time,
    pub time_boot_ms: u32,
    pub point_id: u32,
    pub sweep_index: u32,
    pub sweep_count: u32,
    pub valid_count: u32,
    pub invalid_count: u32,
    pub v_center_avg: f32,
    pub yaw_rate_avg: f32,
    pub kappa_avg: f32,
    pub radius_est: f32,
    pub target_rpm: i16,
    pub servo_pwm_us: u16,
    pub state: u8,
    pub sweep_enabled: u8,
    pub yaw_sign_inverted: u8,
}



impl Default for SmartCarCalibStatus {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::msg::rmw::SmartCarCalibStatus::default())
  }
}

impl rosidl_runtime_rs::Message for SmartCarCalibStatus {
  type RmwMsg = crate::msg::rmw::SmartCarCalibStatus;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        time_boot_ms: msg.time_boot_ms,
        point_id: msg.point_id,
        sweep_index: msg.sweep_index,
        sweep_count: msg.sweep_count,
        valid_count: msg.valid_count,
        invalid_count: msg.invalid_count,
        v_center_avg: msg.v_center_avg,
        yaw_rate_avg: msg.yaw_rate_avg,
        kappa_avg: msg.kappa_avg,
        radius_est: msg.radius_est,
        target_rpm: msg.target_rpm,
        servo_pwm_us: msg.servo_pwm_us,
        state: msg.state,
        sweep_enabled: msg.sweep_enabled,
        yaw_sign_inverted: msg.yaw_sign_inverted,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      time_boot_ms: msg.time_boot_ms,
      point_id: msg.point_id,
      sweep_index: msg.sweep_index,
      sweep_count: msg.sweep_count,
      valid_count: msg.valid_count,
      invalid_count: msg.invalid_count,
      v_center_avg: msg.v_center_avg,
      yaw_rate_avg: msg.yaw_rate_avg,
      kappa_avg: msg.kappa_avg,
      radius_est: msg.radius_est,
      target_rpm: msg.target_rpm,
      servo_pwm_us: msg.servo_pwm_us,
      state: msg.state,
      sweep_enabled: msg.sweep_enabled,
      yaw_sign_inverted: msg.yaw_sign_inverted,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      time_boot_ms: msg.time_boot_ms,
      point_id: msg.point_id,
      sweep_index: msg.sweep_index,
      sweep_count: msg.sweep_count,
      valid_count: msg.valid_count,
      invalid_count: msg.invalid_count,
      v_center_avg: msg.v_center_avg,
      yaw_rate_avg: msg.yaw_rate_avg,
      kappa_avg: msg.kappa_avg,
      radius_est: msg.radius_est,
      target_rpm: msg.target_rpm,
      servo_pwm_us: msg.servo_pwm_us,
      state: msg.state,
      sweep_enabled: msg.sweep_enabled,
      yaw_sign_inverted: msg.yaw_sign_inverted,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct PlatformTarget {
    pub platform: u8,
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub yaw: f32,
    pub vx_mps: f32,
    pub vy_mps: f32,
    pub vz_mps: f32,
    pub speed_mps: f32,
    pub curvature: f32,
    pub yaw_rate_dps: f32,
}

impl PlatformTarget {
    pub const PLATFORM_CAR: u8 = 0;
    pub const PLATFORM_FLIGHT: u8 = 1;
}


impl Default for PlatformTarget {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::msg::rmw::PlatformTarget::default())
  }
}

impl rosidl_runtime_rs::Message for PlatformTarget {
  type RmwMsg = crate::msg::rmw::PlatformTarget;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        platform: msg.platform,
        x: msg.x,
        y: msg.y,
        z: msg.z,
        yaw: msg.yaw,
        vx_mps: msg.vx_mps,
        vy_mps: msg.vy_mps,
        vz_mps: msg.vz_mps,
        speed_mps: msg.speed_mps,
        curvature: msg.curvature,
        yaw_rate_dps: msg.yaw_rate_dps,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      platform: msg.platform,
      x: msg.x,
      y: msg.y,
      z: msg.z,
      yaw: msg.yaw,
      vx_mps: msg.vx_mps,
      vy_mps: msg.vy_mps,
      vz_mps: msg.vz_mps,
      speed_mps: msg.speed_mps,
      curvature: msg.curvature,
      yaw_rate_dps: msg.yaw_rate_dps,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      platform: msg.platform,
      x: msg.x,
      y: msg.y,
      z: msg.z,
      yaw: msg.yaw,
      vx_mps: msg.vx_mps,
      vy_mps: msg.vy_mps,
      vz_mps: msg.vz_mps,
      speed_mps: msg.speed_mps,
      curvature: msg.curvature,
      yaw_rate_dps: msg.yaw_rate_dps,
    }
  }
}


