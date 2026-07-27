
pub mod rmw {
#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_Goal() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Takeoff_Goal__init(msg: *mut Takeoff_Goal) -> bool;
    fn messages__action__Takeoff_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Goal>, size: usize) -> bool;
    fn messages__action__Takeoff_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Goal>);
    fn messages__action__Takeoff_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Goal>) -> bool;
}

// Corresponds to messages__action__Takeoff_Goal
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_Goal {
    pub task_id: rosidl_runtime_rs::String,
    pub priority: u8,
    pub target_altitude: f32,
    pub timeout_sec: f32,
}



impl Default for Takeoff_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Takeoff_Goal__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Takeoff_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Takeoff_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_Goal() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_Result() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Takeoff_Result__init(msg: *mut Takeoff_Result) -> bool;
    fn messages__action__Takeoff_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Result>, size: usize) -> bool;
    fn messages__action__Takeoff_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Result>);
    fn messages__action__Takeoff_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Result>) -> bool;
}

// Corresponds to messages__action__Takeoff_Result
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_Result {
    pub success: bool,
    pub final_state_code: u8,
    pub error_code: u16,
    pub message: rosidl_runtime_rs::String,
    pub elapsed_sec: f32,
}



impl Default for Takeoff_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Takeoff_Result__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Takeoff_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_Result where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Takeoff_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_Result() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Takeoff_Feedback__init(msg: *mut Takeoff_Feedback) -> bool;
    fn messages__action__Takeoff_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Feedback>, size: usize) -> bool;
    fn messages__action__Takeoff_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Feedback>);
    fn messages__action__Takeoff_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_Feedback>) -> bool;
}

// Corresponds to messages__action__Takeoff_Feedback
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_Feedback {
    pub task_id: rosidl_runtime_rs::String,
    pub priority: u8,
    pub stamp: builtin_interfaces::msg::rmw::Time,
    pub state_code: u8,
    pub error_code: u16,
    pub message: rosidl_runtime_rs::String,
    pub progress: f32,
    pub distance_error: f32,
    pub yaw_error: f32,
    pub current_pose: geometry_msgs::msg::rmw::Pose,
    pub current_twist: geometry_msgs::msg::rmw::Twist,
}



impl Default for Takeoff_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Takeoff_Feedback__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Takeoff_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Takeoff_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_Feedback() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Takeoff_FeedbackMessage__init(msg: *mut Takeoff_FeedbackMessage) -> bool;
    fn messages__action__Takeoff_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_FeedbackMessage>, size: usize) -> bool;
    fn messages__action__Takeoff_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_FeedbackMessage>);
    fn messages__action__Takeoff_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_FeedbackMessage>) -> bool;
}

// Corresponds to messages__action__Takeoff_FeedbackMessage
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_FeedbackMessage {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
    pub feedback: crate::action::rmw::Takeoff_Feedback,
}



impl Default for Takeoff_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Takeoff_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Takeoff_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Takeoff_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_FeedbackMessage() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_Goal() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__GoToTarget_Goal__init(msg: *mut GoToTarget_Goal) -> bool;
    fn messages__action__GoToTarget_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_Goal>, size: usize) -> bool;
    fn messages__action__GoToTarget_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_Goal>);
    fn messages__action__GoToTarget_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GoToTarget_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_Goal>) -> bool;
}

// Corresponds to messages__action__GoToTarget_Goal
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_Goal {
    pub task_id: rosidl_runtime_rs::String,
    pub priority: u8,
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub yaw: f32,
    pub timeout_sec: f32,
    pub stable_time_sec: f32,
}



impl Default for GoToTarget_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__GoToTarget_Goal__init(&mut msg as *mut _) {
        panic!("Call to messages__action__GoToTarget_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GoToTarget_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GoToTarget_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/GoToTarget_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_Goal() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_Result() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__GoToTarget_Result__init(msg: *mut GoToTarget_Result) -> bool;
    fn messages__action__GoToTarget_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_Result>, size: usize) -> bool;
    fn messages__action__GoToTarget_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_Result>);
    fn messages__action__GoToTarget_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GoToTarget_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_Result>) -> bool;
}

// Corresponds to messages__action__GoToTarget_Result
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_Result {
    pub success: bool,
    pub final_state_code: u8,
    pub error_code: u16,
    pub message: rosidl_runtime_rs::String,
    pub elapsed_sec: f32,
}



impl Default for GoToTarget_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__GoToTarget_Result__init(&mut msg as *mut _) {
        panic!("Call to messages__action__GoToTarget_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GoToTarget_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GoToTarget_Result where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/GoToTarget_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_Result() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__GoToTarget_Feedback__init(msg: *mut GoToTarget_Feedback) -> bool;
    fn messages__action__GoToTarget_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_Feedback>, size: usize) -> bool;
    fn messages__action__GoToTarget_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_Feedback>);
    fn messages__action__GoToTarget_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GoToTarget_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_Feedback>) -> bool;
}

// Corresponds to messages__action__GoToTarget_Feedback
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_Feedback {
    pub task_id: rosidl_runtime_rs::String,
    pub priority: u8,
    pub stamp: builtin_interfaces::msg::rmw::Time,
    pub state_code: u8,
    pub error_code: u16,
    pub message: rosidl_runtime_rs::String,
    pub progress: f32,
    pub distance_error: f32,
    pub yaw_error: f32,
    pub current_pose: geometry_msgs::msg::rmw::Pose,
    pub current_twist: geometry_msgs::msg::rmw::Twist,
}



impl Default for GoToTarget_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__GoToTarget_Feedback__init(&mut msg as *mut _) {
        panic!("Call to messages__action__GoToTarget_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GoToTarget_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GoToTarget_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/GoToTarget_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_Feedback() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__GoToTarget_FeedbackMessage__init(msg: *mut GoToTarget_FeedbackMessage) -> bool;
    fn messages__action__GoToTarget_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_FeedbackMessage>, size: usize) -> bool;
    fn messages__action__GoToTarget_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_FeedbackMessage>);
    fn messages__action__GoToTarget_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GoToTarget_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_FeedbackMessage>) -> bool;
}

// Corresponds to messages__action__GoToTarget_FeedbackMessage
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_FeedbackMessage {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
    pub feedback: crate::action::rmw::GoToTarget_Feedback,
}



impl Default for GoToTarget_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__GoToTarget_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to messages__action__GoToTarget_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GoToTarget_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GoToTarget_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/GoToTarget_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_FeedbackMessage() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_Goal() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__TrackVelocity_Goal__init(msg: *mut TrackVelocity_Goal) -> bool;
    fn messages__action__TrackVelocity_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_Goal>, size: usize) -> bool;
    fn messages__action__TrackVelocity_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_Goal>);
    fn messages__action__TrackVelocity_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackVelocity_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_Goal>) -> bool;
}

// Corresponds to messages__action__TrackVelocity_Goal
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_Goal {
    pub task_id: rosidl_runtime_rs::String,
    pub priority: u8,
    pub vx: f32,
    pub vy: f32,
    pub vz: f32,
    pub yaw_rate: f32,
    pub duration_sec: f32,
}



impl Default for TrackVelocity_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__TrackVelocity_Goal__init(&mut msg as *mut _) {
        panic!("Call to messages__action__TrackVelocity_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackVelocity_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackVelocity_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/TrackVelocity_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_Goal() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_Result() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__TrackVelocity_Result__init(msg: *mut TrackVelocity_Result) -> bool;
    fn messages__action__TrackVelocity_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_Result>, size: usize) -> bool;
    fn messages__action__TrackVelocity_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_Result>);
    fn messages__action__TrackVelocity_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackVelocity_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_Result>) -> bool;
}

// Corresponds to messages__action__TrackVelocity_Result
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_Result {
    pub success: bool,
    pub final_state_code: u8,
    pub error_code: u16,
    pub message: rosidl_runtime_rs::String,
    pub elapsed_sec: f32,
}



impl Default for TrackVelocity_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__TrackVelocity_Result__init(&mut msg as *mut _) {
        panic!("Call to messages__action__TrackVelocity_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackVelocity_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackVelocity_Result where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/TrackVelocity_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_Result() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__TrackVelocity_Feedback__init(msg: *mut TrackVelocity_Feedback) -> bool;
    fn messages__action__TrackVelocity_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_Feedback>, size: usize) -> bool;
    fn messages__action__TrackVelocity_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_Feedback>);
    fn messages__action__TrackVelocity_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackVelocity_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_Feedback>) -> bool;
}

// Corresponds to messages__action__TrackVelocity_Feedback
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_Feedback {
    pub task_id: rosidl_runtime_rs::String,
    pub priority: u8,
    pub stamp: builtin_interfaces::msg::rmw::Time,
    pub state_code: u8,
    pub error_code: u16,
    pub message: rosidl_runtime_rs::String,
    pub progress: f32,
    pub distance_error: f32,
    pub yaw_error: f32,
    pub current_pose: geometry_msgs::msg::rmw::Pose,
    pub current_twist: geometry_msgs::msg::rmw::Twist,
}



impl Default for TrackVelocity_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__TrackVelocity_Feedback__init(&mut msg as *mut _) {
        panic!("Call to messages__action__TrackVelocity_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackVelocity_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackVelocity_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/TrackVelocity_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_Feedback() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__TrackVelocity_FeedbackMessage__init(msg: *mut TrackVelocity_FeedbackMessage) -> bool;
    fn messages__action__TrackVelocity_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_FeedbackMessage>, size: usize) -> bool;
    fn messages__action__TrackVelocity_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_FeedbackMessage>);
    fn messages__action__TrackVelocity_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackVelocity_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_FeedbackMessage>) -> bool;
}

// Corresponds to messages__action__TrackVelocity_FeedbackMessage
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_FeedbackMessage {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
    pub feedback: crate::action::rmw::TrackVelocity_Feedback,
}



impl Default for TrackVelocity_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__TrackVelocity_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to messages__action__TrackVelocity_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackVelocity_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackVelocity_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/TrackVelocity_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_FeedbackMessage() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_Goal() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Land_Goal__init(msg: *mut Land_Goal) -> bool;
    fn messages__action__Land_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_Goal>, size: usize) -> bool;
    fn messages__action__Land_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_Goal>);
    fn messages__action__Land_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_Goal>) -> bool;
}

// Corresponds to messages__action__Land_Goal
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_Goal {
    pub task_id: rosidl_runtime_rs::String,
    pub priority: u8,
    pub timeout_sec: f32,
}



impl Default for Land_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Land_Goal__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Land_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Land_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_Goal() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_Result() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Land_Result__init(msg: *mut Land_Result) -> bool;
    fn messages__action__Land_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_Result>, size: usize) -> bool;
    fn messages__action__Land_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_Result>);
    fn messages__action__Land_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_Result>) -> bool;
}

// Corresponds to messages__action__Land_Result
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_Result {
    pub success: bool,
    pub final_state_code: u8,
    pub error_code: u16,
    pub message: rosidl_runtime_rs::String,
    pub elapsed_sec: f32,
}



impl Default for Land_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Land_Result__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Land_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_Result where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Land_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_Result() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Land_Feedback__init(msg: *mut Land_Feedback) -> bool;
    fn messages__action__Land_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_Feedback>, size: usize) -> bool;
    fn messages__action__Land_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_Feedback>);
    fn messages__action__Land_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_Feedback>) -> bool;
}

// Corresponds to messages__action__Land_Feedback
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_Feedback {
    pub task_id: rosidl_runtime_rs::String,
    pub priority: u8,
    pub stamp: builtin_interfaces::msg::rmw::Time,
    pub state_code: u8,
    pub error_code: u16,
    pub message: rosidl_runtime_rs::String,
    pub progress: f32,
    pub distance_error: f32,
    pub yaw_error: f32,
    pub current_pose: geometry_msgs::msg::rmw::Pose,
    pub current_twist: geometry_msgs::msg::rmw::Twist,
}



impl Default for Land_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Land_Feedback__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Land_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Land_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_Feedback() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Land_FeedbackMessage__init(msg: *mut Land_FeedbackMessage) -> bool;
    fn messages__action__Land_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_FeedbackMessage>, size: usize) -> bool;
    fn messages__action__Land_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_FeedbackMessage>);
    fn messages__action__Land_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_FeedbackMessage>) -> bool;
}

// Corresponds to messages__action__Land_FeedbackMessage
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_FeedbackMessage {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
    pub feedback: crate::action::rmw::Land_Feedback,
}



impl Default for Land_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Land_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Land_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Land_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_FeedbackMessage() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_Goal() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__ExecuteMission_Goal__init(msg: *mut ExecuteMission_Goal) -> bool;
    fn messages__action__ExecuteMission_Goal__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_Goal>, size: usize) -> bool;
    fn messages__action__ExecuteMission_Goal__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_Goal>);
    fn messages__action__ExecuteMission_Goal__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMission_Goal>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_Goal>) -> bool;
}

// Corresponds to messages__action__ExecuteMission_Goal
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_Goal {
    pub task_id: rosidl_runtime_rs::String,
    pub priority: u8,
    pub mission_name: rosidl_runtime_rs::String,
    pub bt_xml_uri: rosidl_runtime_rs::String,
    pub timeout_sec: f32,
}



impl Default for ExecuteMission_Goal {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__ExecuteMission_Goal__init(&mut msg as *mut _) {
        panic!("Call to messages__action__ExecuteMission_Goal__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMission_Goal {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_Goal__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_Goal__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_Goal__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_Goal {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMission_Goal where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/ExecuteMission_Goal";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_Goal() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_Result() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__ExecuteMission_Result__init(msg: *mut ExecuteMission_Result) -> bool;
    fn messages__action__ExecuteMission_Result__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_Result>, size: usize) -> bool;
    fn messages__action__ExecuteMission_Result__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_Result>);
    fn messages__action__ExecuteMission_Result__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMission_Result>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_Result>) -> bool;
}

// Corresponds to messages__action__ExecuteMission_Result
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_Result {
    pub success: bool,
    pub final_state_code: u8,
    pub error_code: u16,
    pub message: rosidl_runtime_rs::String,
    pub elapsed_sec: f32,
    pub failed_node: rosidl_runtime_rs::String,
}



impl Default for ExecuteMission_Result {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__ExecuteMission_Result__init(&mut msg as *mut _) {
        panic!("Call to messages__action__ExecuteMission_Result__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMission_Result {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_Result__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_Result__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_Result__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_Result {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMission_Result where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/ExecuteMission_Result";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_Result() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_Feedback() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__ExecuteMission_Feedback__init(msg: *mut ExecuteMission_Feedback) -> bool;
    fn messages__action__ExecuteMission_Feedback__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_Feedback>, size: usize) -> bool;
    fn messages__action__ExecuteMission_Feedback__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_Feedback>);
    fn messages__action__ExecuteMission_Feedback__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMission_Feedback>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_Feedback>) -> bool;
}

// Corresponds to messages__action__ExecuteMission_Feedback
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_Feedback {
    pub task_id: rosidl_runtime_rs::String,
    pub priority: u8,
    pub stamp: builtin_interfaces::msg::rmw::Time,
    pub state_code: u8,
    pub error_code: u16,
    pub message: rosidl_runtime_rs::String,
    pub progress: f32,
    pub distance_error: f32,
    pub yaw_error: f32,
    pub current_pose: geometry_msgs::msg::rmw::Pose,
    pub current_twist: geometry_msgs::msg::rmw::Twist,
    pub current_node: rosidl_runtime_rs::String,
    pub current_stage: rosidl_runtime_rs::String,
}



impl Default for ExecuteMission_Feedback {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__ExecuteMission_Feedback__init(&mut msg as *mut _) {
        panic!("Call to messages__action__ExecuteMission_Feedback__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMission_Feedback {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_Feedback__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_Feedback__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_Feedback__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_Feedback {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMission_Feedback where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/ExecuteMission_Feedback";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_Feedback() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_FeedbackMessage() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__ExecuteMission_FeedbackMessage__init(msg: *mut ExecuteMission_FeedbackMessage) -> bool;
    fn messages__action__ExecuteMission_FeedbackMessage__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_FeedbackMessage>, size: usize) -> bool;
    fn messages__action__ExecuteMission_FeedbackMessage__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_FeedbackMessage>);
    fn messages__action__ExecuteMission_FeedbackMessage__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMission_FeedbackMessage>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_FeedbackMessage>) -> bool;
}

// Corresponds to messages__action__ExecuteMission_FeedbackMessage
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_FeedbackMessage {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
    pub feedback: crate::action::rmw::ExecuteMission_Feedback,
}



impl Default for ExecuteMission_FeedbackMessage {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__ExecuteMission_FeedbackMessage__init(&mut msg as *mut _) {
        panic!("Call to messages__action__ExecuteMission_FeedbackMessage__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMission_FeedbackMessage {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_FeedbackMessage__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_FeedbackMessage__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_FeedbackMessage__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_FeedbackMessage {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMission_FeedbackMessage where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/ExecuteMission_FeedbackMessage";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_FeedbackMessage() }
  }
}



#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Takeoff_SendGoal_Request__init(msg: *mut Takeoff_SendGoal_Request) -> bool;
    fn messages__action__Takeoff_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Request>, size: usize) -> bool;
    fn messages__action__Takeoff_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Request>);
    fn messages__action__Takeoff_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Request>) -> bool;
}

// Corresponds to messages__action__Takeoff_SendGoal_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_SendGoal_Request {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
    pub goal: crate::action::rmw::Takeoff_Goal,
}



impl Default for Takeoff_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Takeoff_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Takeoff_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Takeoff_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_SendGoal_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Takeoff_SendGoal_Response__init(msg: *mut Takeoff_SendGoal_Response) -> bool;
    fn messages__action__Takeoff_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Response>, size: usize) -> bool;
    fn messages__action__Takeoff_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Response>);
    fn messages__action__Takeoff_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_SendGoal_Response>) -> bool;
}

// Corresponds to messages__action__Takeoff_SendGoal_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_SendGoal_Response {
    pub accepted: bool,
    pub stamp: builtin_interfaces::msg::rmw::Time,
}



impl Default for Takeoff_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Takeoff_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Takeoff_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Takeoff_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_SendGoal_Response() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Takeoff_GetResult_Request__init(msg: *mut Takeoff_GetResult_Request) -> bool;
    fn messages__action__Takeoff_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Request>, size: usize) -> bool;
    fn messages__action__Takeoff_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Request>);
    fn messages__action__Takeoff_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Request>) -> bool;
}

// Corresponds to messages__action__Takeoff_GetResult_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_GetResult_Request {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
}



impl Default for Takeoff_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Takeoff_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Takeoff_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Takeoff_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_GetResult_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Takeoff_GetResult_Response__init(msg: *mut Takeoff_GetResult_Response) -> bool;
    fn messages__action__Takeoff_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Response>, size: usize) -> bool;
    fn messages__action__Takeoff_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Response>);
    fn messages__action__Takeoff_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Takeoff_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Takeoff_GetResult_Response>) -> bool;
}

// Corresponds to messages__action__Takeoff_GetResult_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_GetResult_Response {
    pub status: i8,
    pub result: crate::action::rmw::Takeoff_Result,
}



impl Default for Takeoff_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Takeoff_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Takeoff_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Takeoff_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Takeoff_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Takeoff_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Takeoff_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Takeoff_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Takeoff_GetResult_Response() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__GoToTarget_SendGoal_Request__init(msg: *mut GoToTarget_SendGoal_Request) -> bool;
    fn messages__action__GoToTarget_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_SendGoal_Request>, size: usize) -> bool;
    fn messages__action__GoToTarget_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_SendGoal_Request>);
    fn messages__action__GoToTarget_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GoToTarget_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_SendGoal_Request>) -> bool;
}

// Corresponds to messages__action__GoToTarget_SendGoal_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_SendGoal_Request {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
    pub goal: crate::action::rmw::GoToTarget_Goal,
}



impl Default for GoToTarget_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__GoToTarget_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__action__GoToTarget_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GoToTarget_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GoToTarget_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/GoToTarget_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_SendGoal_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__GoToTarget_SendGoal_Response__init(msg: *mut GoToTarget_SendGoal_Response) -> bool;
    fn messages__action__GoToTarget_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_SendGoal_Response>, size: usize) -> bool;
    fn messages__action__GoToTarget_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_SendGoal_Response>);
    fn messages__action__GoToTarget_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GoToTarget_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_SendGoal_Response>) -> bool;
}

// Corresponds to messages__action__GoToTarget_SendGoal_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_SendGoal_Response {
    pub accepted: bool,
    pub stamp: builtin_interfaces::msg::rmw::Time,
}



impl Default for GoToTarget_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__GoToTarget_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__action__GoToTarget_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GoToTarget_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GoToTarget_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/GoToTarget_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_SendGoal_Response() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__GoToTarget_GetResult_Request__init(msg: *mut GoToTarget_GetResult_Request) -> bool;
    fn messages__action__GoToTarget_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_GetResult_Request>, size: usize) -> bool;
    fn messages__action__GoToTarget_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_GetResult_Request>);
    fn messages__action__GoToTarget_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GoToTarget_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_GetResult_Request>) -> bool;
}

// Corresponds to messages__action__GoToTarget_GetResult_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_GetResult_Request {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
}



impl Default for GoToTarget_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__GoToTarget_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__action__GoToTarget_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GoToTarget_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GoToTarget_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/GoToTarget_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_GetResult_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__GoToTarget_GetResult_Response__init(msg: *mut GoToTarget_GetResult_Response) -> bool;
    fn messages__action__GoToTarget_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_GetResult_Response>, size: usize) -> bool;
    fn messages__action__GoToTarget_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_GetResult_Response>);
    fn messages__action__GoToTarget_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<GoToTarget_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<GoToTarget_GetResult_Response>) -> bool;
}

// Corresponds to messages__action__GoToTarget_GetResult_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_GetResult_Response {
    pub status: i8,
    pub result: crate::action::rmw::GoToTarget_Result,
}



impl Default for GoToTarget_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__GoToTarget_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__action__GoToTarget_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for GoToTarget_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__GoToTarget_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for GoToTarget_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/GoToTarget_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__GoToTarget_GetResult_Response() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__TrackVelocity_SendGoal_Request__init(msg: *mut TrackVelocity_SendGoal_Request) -> bool;
    fn messages__action__TrackVelocity_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_SendGoal_Request>, size: usize) -> bool;
    fn messages__action__TrackVelocity_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_SendGoal_Request>);
    fn messages__action__TrackVelocity_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackVelocity_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_SendGoal_Request>) -> bool;
}

// Corresponds to messages__action__TrackVelocity_SendGoal_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_SendGoal_Request {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
    pub goal: crate::action::rmw::TrackVelocity_Goal,
}



impl Default for TrackVelocity_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__TrackVelocity_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__action__TrackVelocity_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackVelocity_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackVelocity_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/TrackVelocity_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_SendGoal_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__TrackVelocity_SendGoal_Response__init(msg: *mut TrackVelocity_SendGoal_Response) -> bool;
    fn messages__action__TrackVelocity_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_SendGoal_Response>, size: usize) -> bool;
    fn messages__action__TrackVelocity_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_SendGoal_Response>);
    fn messages__action__TrackVelocity_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackVelocity_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_SendGoal_Response>) -> bool;
}

// Corresponds to messages__action__TrackVelocity_SendGoal_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_SendGoal_Response {
    pub accepted: bool,
    pub stamp: builtin_interfaces::msg::rmw::Time,
}



impl Default for TrackVelocity_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__TrackVelocity_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__action__TrackVelocity_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackVelocity_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackVelocity_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/TrackVelocity_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_SendGoal_Response() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__TrackVelocity_GetResult_Request__init(msg: *mut TrackVelocity_GetResult_Request) -> bool;
    fn messages__action__TrackVelocity_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_GetResult_Request>, size: usize) -> bool;
    fn messages__action__TrackVelocity_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_GetResult_Request>);
    fn messages__action__TrackVelocity_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackVelocity_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_GetResult_Request>) -> bool;
}

// Corresponds to messages__action__TrackVelocity_GetResult_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_GetResult_Request {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
}



impl Default for TrackVelocity_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__TrackVelocity_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__action__TrackVelocity_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackVelocity_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackVelocity_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/TrackVelocity_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_GetResult_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__TrackVelocity_GetResult_Response__init(msg: *mut TrackVelocity_GetResult_Response) -> bool;
    fn messages__action__TrackVelocity_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_GetResult_Response>, size: usize) -> bool;
    fn messages__action__TrackVelocity_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_GetResult_Response>);
    fn messages__action__TrackVelocity_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<TrackVelocity_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<TrackVelocity_GetResult_Response>) -> bool;
}

// Corresponds to messages__action__TrackVelocity_GetResult_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_GetResult_Response {
    pub status: i8,
    pub result: crate::action::rmw::TrackVelocity_Result,
}



impl Default for TrackVelocity_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__TrackVelocity_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__action__TrackVelocity_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for TrackVelocity_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__TrackVelocity_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for TrackVelocity_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/TrackVelocity_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__TrackVelocity_GetResult_Response() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Land_SendGoal_Request__init(msg: *mut Land_SendGoal_Request) -> bool;
    fn messages__action__Land_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Request>, size: usize) -> bool;
    fn messages__action__Land_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Request>);
    fn messages__action__Land_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Request>) -> bool;
}

// Corresponds to messages__action__Land_SendGoal_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_SendGoal_Request {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
    pub goal: crate::action::rmw::Land_Goal,
}



impl Default for Land_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Land_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Land_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Land_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_SendGoal_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Land_SendGoal_Response__init(msg: *mut Land_SendGoal_Response) -> bool;
    fn messages__action__Land_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Response>, size: usize) -> bool;
    fn messages__action__Land_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Response>);
    fn messages__action__Land_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_SendGoal_Response>) -> bool;
}

// Corresponds to messages__action__Land_SendGoal_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_SendGoal_Response {
    pub accepted: bool,
    pub stamp: builtin_interfaces::msg::rmw::Time,
}



impl Default for Land_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Land_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Land_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Land_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_SendGoal_Response() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Land_GetResult_Request__init(msg: *mut Land_GetResult_Request) -> bool;
    fn messages__action__Land_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Request>, size: usize) -> bool;
    fn messages__action__Land_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Request>);
    fn messages__action__Land_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Request>) -> bool;
}

// Corresponds to messages__action__Land_GetResult_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_GetResult_Request {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
}



impl Default for Land_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Land_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Land_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Land_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_GetResult_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__Land_GetResult_Response__init(msg: *mut Land_GetResult_Response) -> bool;
    fn messages__action__Land_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Response>, size: usize) -> bool;
    fn messages__action__Land_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Response>);
    fn messages__action__Land_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Land_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Land_GetResult_Response>) -> bool;
}

// Corresponds to messages__action__Land_GetResult_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_GetResult_Response {
    pub status: i8,
    pub result: crate::action::rmw::Land_Result,
}



impl Default for Land_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__Land_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__action__Land_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Land_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__Land_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Land_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Land_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/Land_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__Land_GetResult_Response() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_SendGoal_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__ExecuteMission_SendGoal_Request__init(msg: *mut ExecuteMission_SendGoal_Request) -> bool;
    fn messages__action__ExecuteMission_SendGoal_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_SendGoal_Request>, size: usize) -> bool;
    fn messages__action__ExecuteMission_SendGoal_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_SendGoal_Request>);
    fn messages__action__ExecuteMission_SendGoal_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMission_SendGoal_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_SendGoal_Request>) -> bool;
}

// Corresponds to messages__action__ExecuteMission_SendGoal_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_SendGoal_Request {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
    pub goal: crate::action::rmw::ExecuteMission_Goal,
}



impl Default for ExecuteMission_SendGoal_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__ExecuteMission_SendGoal_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__action__ExecuteMission_SendGoal_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMission_SendGoal_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_SendGoal_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_SendGoal_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_SendGoal_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_SendGoal_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMission_SendGoal_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/ExecuteMission_SendGoal_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_SendGoal_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_SendGoal_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__ExecuteMission_SendGoal_Response__init(msg: *mut ExecuteMission_SendGoal_Response) -> bool;
    fn messages__action__ExecuteMission_SendGoal_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_SendGoal_Response>, size: usize) -> bool;
    fn messages__action__ExecuteMission_SendGoal_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_SendGoal_Response>);
    fn messages__action__ExecuteMission_SendGoal_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMission_SendGoal_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_SendGoal_Response>) -> bool;
}

// Corresponds to messages__action__ExecuteMission_SendGoal_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_SendGoal_Response {
    pub accepted: bool,
    pub stamp: builtin_interfaces::msg::rmw::Time,
}



impl Default for ExecuteMission_SendGoal_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__ExecuteMission_SendGoal_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__action__ExecuteMission_SendGoal_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMission_SendGoal_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_SendGoal_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_SendGoal_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_SendGoal_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_SendGoal_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMission_SendGoal_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/ExecuteMission_SendGoal_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_SendGoal_Response() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_GetResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__ExecuteMission_GetResult_Request__init(msg: *mut ExecuteMission_GetResult_Request) -> bool;
    fn messages__action__ExecuteMission_GetResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_GetResult_Request>, size: usize) -> bool;
    fn messages__action__ExecuteMission_GetResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_GetResult_Request>);
    fn messages__action__ExecuteMission_GetResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMission_GetResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_GetResult_Request>) -> bool;
}

// Corresponds to messages__action__ExecuteMission_GetResult_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_GetResult_Request {
    pub goal_id: unique_identifier_msgs::msg::rmw::UUID,
}



impl Default for ExecuteMission_GetResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__ExecuteMission_GetResult_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__action__ExecuteMission_GetResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMission_GetResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_GetResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_GetResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_GetResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_GetResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMission_GetResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/ExecuteMission_GetResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_GetResult_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_GetResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__action__ExecuteMission_GetResult_Response__init(msg: *mut ExecuteMission_GetResult_Response) -> bool;
    fn messages__action__ExecuteMission_GetResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_GetResult_Response>, size: usize) -> bool;
    fn messages__action__ExecuteMission_GetResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_GetResult_Response>);
    fn messages__action__ExecuteMission_GetResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ExecuteMission_GetResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<ExecuteMission_GetResult_Response>) -> bool;
}

// Corresponds to messages__action__ExecuteMission_GetResult_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_GetResult_Response {
    pub status: i8,
    pub result: crate::action::rmw::ExecuteMission_Result,
}



impl Default for ExecuteMission_GetResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__action__ExecuteMission_GetResult_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__action__ExecuteMission_GetResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ExecuteMission_GetResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_GetResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_GetResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__action__ExecuteMission_GetResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_GetResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ExecuteMission_GetResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/action/ExecuteMission_GetResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__action__ExecuteMission_GetResult_Response() }
  }
}






  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__Takeoff_SendGoal() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__action__Takeoff_SendGoal
  pub struct Takeoff_SendGoal;

  impl rosidl_runtime_rs::Service for Takeoff_SendGoal {
    type Request = crate::action::rmw::Takeoff_SendGoal_Request;
    type Response = crate::action::rmw::Takeoff_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__Takeoff_SendGoal() }
    }
  }




  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__Takeoff_GetResult() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__action__Takeoff_GetResult
  pub struct Takeoff_GetResult;

  impl rosidl_runtime_rs::Service for Takeoff_GetResult {
    type Request = crate::action::rmw::Takeoff_GetResult_Request;
    type Response = crate::action::rmw::Takeoff_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__Takeoff_GetResult() }
    }
  }




  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__GoToTarget_SendGoal() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__action__GoToTarget_SendGoal
  pub struct GoToTarget_SendGoal;

  impl rosidl_runtime_rs::Service for GoToTarget_SendGoal {
    type Request = crate::action::rmw::GoToTarget_SendGoal_Request;
    type Response = crate::action::rmw::GoToTarget_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__GoToTarget_SendGoal() }
    }
  }




  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__GoToTarget_GetResult() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__action__GoToTarget_GetResult
  pub struct GoToTarget_GetResult;

  impl rosidl_runtime_rs::Service for GoToTarget_GetResult {
    type Request = crate::action::rmw::GoToTarget_GetResult_Request;
    type Response = crate::action::rmw::GoToTarget_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__GoToTarget_GetResult() }
    }
  }




  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__TrackVelocity_SendGoal() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__action__TrackVelocity_SendGoal
  pub struct TrackVelocity_SendGoal;

  impl rosidl_runtime_rs::Service for TrackVelocity_SendGoal {
    type Request = crate::action::rmw::TrackVelocity_SendGoal_Request;
    type Response = crate::action::rmw::TrackVelocity_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__TrackVelocity_SendGoal() }
    }
  }




  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__TrackVelocity_GetResult() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__action__TrackVelocity_GetResult
  pub struct TrackVelocity_GetResult;

  impl rosidl_runtime_rs::Service for TrackVelocity_GetResult {
    type Request = crate::action::rmw::TrackVelocity_GetResult_Request;
    type Response = crate::action::rmw::TrackVelocity_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__TrackVelocity_GetResult() }
    }
  }




  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__Land_SendGoal() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__action__Land_SendGoal
  pub struct Land_SendGoal;

  impl rosidl_runtime_rs::Service for Land_SendGoal {
    type Request = crate::action::rmw::Land_SendGoal_Request;
    type Response = crate::action::rmw::Land_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__Land_SendGoal() }
    }
  }




  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__Land_GetResult() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__action__Land_GetResult
  pub struct Land_GetResult;

  impl rosidl_runtime_rs::Service for Land_GetResult {
    type Request = crate::action::rmw::Land_GetResult_Request;
    type Response = crate::action::rmw::Land_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__Land_GetResult() }
    }
  }




  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__ExecuteMission_SendGoal() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__action__ExecuteMission_SendGoal
  pub struct ExecuteMission_SendGoal;

  impl rosidl_runtime_rs::Service for ExecuteMission_SendGoal {
    type Request = crate::action::rmw::ExecuteMission_SendGoal_Request;
    type Response = crate::action::rmw::ExecuteMission_SendGoal_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__ExecuteMission_SendGoal() }
    }
  }




  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__ExecuteMission_GetResult() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__action__ExecuteMission_GetResult
  pub struct ExecuteMission_GetResult;

  impl rosidl_runtime_rs::Service for ExecuteMission_GetResult {
    type Request = crate::action::rmw::ExecuteMission_GetResult_Request;
    type Response = crate::action::rmw::ExecuteMission_GetResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__ExecuteMission_GetResult() }
    }
  }


}  // mod rmw


#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_Goal {
    pub task_id: std::string::String,
    pub priority: u8,
    pub target_altitude: f32,
    pub timeout_sec: f32,
}



impl Default for Takeoff_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Takeoff_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for Takeoff_Goal {
  type RmwMsg = crate::action::rmw::Takeoff_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
        priority: msg.priority,
        target_altitude: msg.target_altitude,
        timeout_sec: msg.timeout_sec,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
      priority: msg.priority,
      target_altitude: msg.target_altitude,
      timeout_sec: msg.timeout_sec,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_id: msg.task_id.to_string(),
      priority: msg.priority,
      target_altitude: msg.target_altitude,
      timeout_sec: msg.timeout_sec,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_Result {
    pub success: bool,
    pub final_state_code: u8,
    pub error_code: u16,
    pub message: std::string::String,
    pub elapsed_sec: f32,
}



impl Default for Takeoff_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Takeoff_Result::default())
  }
}

impl rosidl_runtime_rs::Message for Takeoff_Result {
  type RmwMsg = crate::action::rmw::Takeoff_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        final_state_code: msg.final_state_code,
        error_code: msg.error_code,
        message: msg.message.as_str().into(),
        elapsed_sec: msg.elapsed_sec,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      final_state_code: msg.final_state_code,
      error_code: msg.error_code,
        message: msg.message.as_str().into(),
      elapsed_sec: msg.elapsed_sec,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      final_state_code: msg.final_state_code,
      error_code: msg.error_code,
      message: msg.message.to_string(),
      elapsed_sec: msg.elapsed_sec,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_Feedback {
    pub task_id: std::string::String,
    pub priority: u8,
    pub stamp: builtin_interfaces::msg::Time,
    pub state_code: u8,
    pub error_code: u16,
    pub message: std::string::String,
    pub progress: f32,
    pub distance_error: f32,
    pub yaw_error: f32,
    pub current_pose: geometry_msgs::msg::Pose,
    pub current_twist: geometry_msgs::msg::Twist,
}



impl Default for Takeoff_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Takeoff_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for Takeoff_Feedback {
  type RmwMsg = crate::action::rmw::Takeoff_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
        priority: msg.priority,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        state_code: msg.state_code,
        error_code: msg.error_code,
        message: msg.message.as_str().into(),
        progress: msg.progress,
        distance_error: msg.distance_error,
        yaw_error: msg.yaw_error,
        current_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.current_pose)).into_owned(),
        current_twist: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Owned(msg.current_twist)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
      priority: msg.priority,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      state_code: msg.state_code,
      error_code: msg.error_code,
        message: msg.message.as_str().into(),
      progress: msg.progress,
      distance_error: msg.distance_error,
      yaw_error: msg.yaw_error,
        current_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_pose)).into_owned(),
        current_twist: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_twist)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_id: msg.task_id.to_string(),
      priority: msg.priority,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      state_code: msg.state_code,
      error_code: msg.error_code,
      message: msg.message.to_string(),
      progress: msg.progress,
      distance_error: msg.distance_error,
      yaw_error: msg.yaw_error,
      current_pose: geometry_msgs::msg::Pose::from_rmw_message(msg.current_pose),
      current_twist: geometry_msgs::msg::Twist::from_rmw_message(msg.current_twist),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_FeedbackMessage {
    pub goal_id: unique_identifier_msgs::msg::UUID,
    pub feedback: crate::action::Takeoff_Feedback,
}



impl Default for Takeoff_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Takeoff_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for Takeoff_FeedbackMessage {
  type RmwMsg = crate::action::rmw::Takeoff_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: crate::action::Takeoff_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: crate::action::Takeoff_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: crate::action::Takeoff_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_Goal {
    pub task_id: std::string::String,
    pub priority: u8,
    pub x: f32,
    pub y: f32,
    pub z: f32,
    pub yaw: f32,
    pub timeout_sec: f32,
    pub stable_time_sec: f32,
}



impl Default for GoToTarget_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::GoToTarget_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_Goal {
  type RmwMsg = crate::action::rmw::GoToTarget_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
        priority: msg.priority,
        x: msg.x,
        y: msg.y,
        z: msg.z,
        yaw: msg.yaw,
        timeout_sec: msg.timeout_sec,
        stable_time_sec: msg.stable_time_sec,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
      priority: msg.priority,
      x: msg.x,
      y: msg.y,
      z: msg.z,
      yaw: msg.yaw,
      timeout_sec: msg.timeout_sec,
      stable_time_sec: msg.stable_time_sec,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_id: msg.task_id.to_string(),
      priority: msg.priority,
      x: msg.x,
      y: msg.y,
      z: msg.z,
      yaw: msg.yaw,
      timeout_sec: msg.timeout_sec,
      stable_time_sec: msg.stable_time_sec,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_Result {
    pub success: bool,
    pub final_state_code: u8,
    pub error_code: u16,
    pub message: std::string::String,
    pub elapsed_sec: f32,
}



impl Default for GoToTarget_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::GoToTarget_Result::default())
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_Result {
  type RmwMsg = crate::action::rmw::GoToTarget_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        final_state_code: msg.final_state_code,
        error_code: msg.error_code,
        message: msg.message.as_str().into(),
        elapsed_sec: msg.elapsed_sec,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      final_state_code: msg.final_state_code,
      error_code: msg.error_code,
        message: msg.message.as_str().into(),
      elapsed_sec: msg.elapsed_sec,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      final_state_code: msg.final_state_code,
      error_code: msg.error_code,
      message: msg.message.to_string(),
      elapsed_sec: msg.elapsed_sec,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_Feedback {
    pub task_id: std::string::String,
    pub priority: u8,
    pub stamp: builtin_interfaces::msg::Time,
    pub state_code: u8,
    pub error_code: u16,
    pub message: std::string::String,
    pub progress: f32,
    pub distance_error: f32,
    pub yaw_error: f32,
    pub current_pose: geometry_msgs::msg::Pose,
    pub current_twist: geometry_msgs::msg::Twist,
}



impl Default for GoToTarget_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::GoToTarget_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_Feedback {
  type RmwMsg = crate::action::rmw::GoToTarget_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
        priority: msg.priority,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        state_code: msg.state_code,
        error_code: msg.error_code,
        message: msg.message.as_str().into(),
        progress: msg.progress,
        distance_error: msg.distance_error,
        yaw_error: msg.yaw_error,
        current_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.current_pose)).into_owned(),
        current_twist: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Owned(msg.current_twist)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
      priority: msg.priority,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      state_code: msg.state_code,
      error_code: msg.error_code,
        message: msg.message.as_str().into(),
      progress: msg.progress,
      distance_error: msg.distance_error,
      yaw_error: msg.yaw_error,
        current_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_pose)).into_owned(),
        current_twist: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_twist)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_id: msg.task_id.to_string(),
      priority: msg.priority,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      state_code: msg.state_code,
      error_code: msg.error_code,
      message: msg.message.to_string(),
      progress: msg.progress,
      distance_error: msg.distance_error,
      yaw_error: msg.yaw_error,
      current_pose: geometry_msgs::msg::Pose::from_rmw_message(msg.current_pose),
      current_twist: geometry_msgs::msg::Twist::from_rmw_message(msg.current_twist),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_FeedbackMessage {
    pub goal_id: unique_identifier_msgs::msg::UUID,
    pub feedback: crate::action::GoToTarget_Feedback,
}



impl Default for GoToTarget_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::GoToTarget_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_FeedbackMessage {
  type RmwMsg = crate::action::rmw::GoToTarget_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: crate::action::GoToTarget_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: crate::action::GoToTarget_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: crate::action::GoToTarget_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_Goal {
    pub task_id: std::string::String,
    pub priority: u8,
    pub vx: f32,
    pub vy: f32,
    pub vz: f32,
    pub yaw_rate: f32,
    pub duration_sec: f32,
}



impl Default for TrackVelocity_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::TrackVelocity_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_Goal {
  type RmwMsg = crate::action::rmw::TrackVelocity_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
        priority: msg.priority,
        vx: msg.vx,
        vy: msg.vy,
        vz: msg.vz,
        yaw_rate: msg.yaw_rate,
        duration_sec: msg.duration_sec,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
      priority: msg.priority,
      vx: msg.vx,
      vy: msg.vy,
      vz: msg.vz,
      yaw_rate: msg.yaw_rate,
      duration_sec: msg.duration_sec,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_id: msg.task_id.to_string(),
      priority: msg.priority,
      vx: msg.vx,
      vy: msg.vy,
      vz: msg.vz,
      yaw_rate: msg.yaw_rate,
      duration_sec: msg.duration_sec,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_Result {
    pub success: bool,
    pub final_state_code: u8,
    pub error_code: u16,
    pub message: std::string::String,
    pub elapsed_sec: f32,
}



impl Default for TrackVelocity_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::TrackVelocity_Result::default())
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_Result {
  type RmwMsg = crate::action::rmw::TrackVelocity_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        final_state_code: msg.final_state_code,
        error_code: msg.error_code,
        message: msg.message.as_str().into(),
        elapsed_sec: msg.elapsed_sec,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      final_state_code: msg.final_state_code,
      error_code: msg.error_code,
        message: msg.message.as_str().into(),
      elapsed_sec: msg.elapsed_sec,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      final_state_code: msg.final_state_code,
      error_code: msg.error_code,
      message: msg.message.to_string(),
      elapsed_sec: msg.elapsed_sec,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_Feedback {
    pub task_id: std::string::String,
    pub priority: u8,
    pub stamp: builtin_interfaces::msg::Time,
    pub state_code: u8,
    pub error_code: u16,
    pub message: std::string::String,
    pub progress: f32,
    pub distance_error: f32,
    pub yaw_error: f32,
    pub current_pose: geometry_msgs::msg::Pose,
    pub current_twist: geometry_msgs::msg::Twist,
}



impl Default for TrackVelocity_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::TrackVelocity_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_Feedback {
  type RmwMsg = crate::action::rmw::TrackVelocity_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
        priority: msg.priority,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        state_code: msg.state_code,
        error_code: msg.error_code,
        message: msg.message.as_str().into(),
        progress: msg.progress,
        distance_error: msg.distance_error,
        yaw_error: msg.yaw_error,
        current_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.current_pose)).into_owned(),
        current_twist: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Owned(msg.current_twist)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
      priority: msg.priority,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      state_code: msg.state_code,
      error_code: msg.error_code,
        message: msg.message.as_str().into(),
      progress: msg.progress,
      distance_error: msg.distance_error,
      yaw_error: msg.yaw_error,
        current_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_pose)).into_owned(),
        current_twist: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_twist)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_id: msg.task_id.to_string(),
      priority: msg.priority,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      state_code: msg.state_code,
      error_code: msg.error_code,
      message: msg.message.to_string(),
      progress: msg.progress,
      distance_error: msg.distance_error,
      yaw_error: msg.yaw_error,
      current_pose: geometry_msgs::msg::Pose::from_rmw_message(msg.current_pose),
      current_twist: geometry_msgs::msg::Twist::from_rmw_message(msg.current_twist),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_FeedbackMessage {
    pub goal_id: unique_identifier_msgs::msg::UUID,
    pub feedback: crate::action::TrackVelocity_Feedback,
}



impl Default for TrackVelocity_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::TrackVelocity_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_FeedbackMessage {
  type RmwMsg = crate::action::rmw::TrackVelocity_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: crate::action::TrackVelocity_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: crate::action::TrackVelocity_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: crate::action::TrackVelocity_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_Goal {
    pub task_id: std::string::String,
    pub priority: u8,
    pub timeout_sec: f32,
}



impl Default for Land_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Land_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for Land_Goal {
  type RmwMsg = crate::action::rmw::Land_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
        priority: msg.priority,
        timeout_sec: msg.timeout_sec,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
      priority: msg.priority,
      timeout_sec: msg.timeout_sec,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_id: msg.task_id.to_string(),
      priority: msg.priority,
      timeout_sec: msg.timeout_sec,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_Result {
    pub success: bool,
    pub final_state_code: u8,
    pub error_code: u16,
    pub message: std::string::String,
    pub elapsed_sec: f32,
}



impl Default for Land_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Land_Result::default())
  }
}

impl rosidl_runtime_rs::Message for Land_Result {
  type RmwMsg = crate::action::rmw::Land_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        final_state_code: msg.final_state_code,
        error_code: msg.error_code,
        message: msg.message.as_str().into(),
        elapsed_sec: msg.elapsed_sec,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      final_state_code: msg.final_state_code,
      error_code: msg.error_code,
        message: msg.message.as_str().into(),
      elapsed_sec: msg.elapsed_sec,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      final_state_code: msg.final_state_code,
      error_code: msg.error_code,
      message: msg.message.to_string(),
      elapsed_sec: msg.elapsed_sec,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_Feedback {
    pub task_id: std::string::String,
    pub priority: u8,
    pub stamp: builtin_interfaces::msg::Time,
    pub state_code: u8,
    pub error_code: u16,
    pub message: std::string::String,
    pub progress: f32,
    pub distance_error: f32,
    pub yaw_error: f32,
    pub current_pose: geometry_msgs::msg::Pose,
    pub current_twist: geometry_msgs::msg::Twist,
}



impl Default for Land_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Land_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for Land_Feedback {
  type RmwMsg = crate::action::rmw::Land_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
        priority: msg.priority,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        state_code: msg.state_code,
        error_code: msg.error_code,
        message: msg.message.as_str().into(),
        progress: msg.progress,
        distance_error: msg.distance_error,
        yaw_error: msg.yaw_error,
        current_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.current_pose)).into_owned(),
        current_twist: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Owned(msg.current_twist)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
      priority: msg.priority,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      state_code: msg.state_code,
      error_code: msg.error_code,
        message: msg.message.as_str().into(),
      progress: msg.progress,
      distance_error: msg.distance_error,
      yaw_error: msg.yaw_error,
        current_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_pose)).into_owned(),
        current_twist: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_twist)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_id: msg.task_id.to_string(),
      priority: msg.priority,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      state_code: msg.state_code,
      error_code: msg.error_code,
      message: msg.message.to_string(),
      progress: msg.progress,
      distance_error: msg.distance_error,
      yaw_error: msg.yaw_error,
      current_pose: geometry_msgs::msg::Pose::from_rmw_message(msg.current_pose),
      current_twist: geometry_msgs::msg::Twist::from_rmw_message(msg.current_twist),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_FeedbackMessage {
    pub goal_id: unique_identifier_msgs::msg::UUID,
    pub feedback: crate::action::Land_Feedback,
}



impl Default for Land_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Land_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for Land_FeedbackMessage {
  type RmwMsg = crate::action::rmw::Land_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: crate::action::Land_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: crate::action::Land_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: crate::action::Land_Feedback::from_rmw_message(msg.feedback),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_Goal {
    pub task_id: std::string::String,
    pub priority: u8,
    pub mission_name: std::string::String,
    pub bt_xml_uri: std::string::String,
    pub timeout_sec: f32,
}



impl Default for ExecuteMission_Goal {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::ExecuteMission_Goal::default())
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_Goal {
  type RmwMsg = crate::action::rmw::ExecuteMission_Goal;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
        priority: msg.priority,
        mission_name: msg.mission_name.as_str().into(),
        bt_xml_uri: msg.bt_xml_uri.as_str().into(),
        timeout_sec: msg.timeout_sec,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
      priority: msg.priority,
        mission_name: msg.mission_name.as_str().into(),
        bt_xml_uri: msg.bt_xml_uri.as_str().into(),
      timeout_sec: msg.timeout_sec,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_id: msg.task_id.to_string(),
      priority: msg.priority,
      mission_name: msg.mission_name.to_string(),
      bt_xml_uri: msg.bt_xml_uri.to_string(),
      timeout_sec: msg.timeout_sec,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_Result {
    pub success: bool,
    pub final_state_code: u8,
    pub error_code: u16,
    pub message: std::string::String,
    pub elapsed_sec: f32,
    pub failed_node: std::string::String,
}



impl Default for ExecuteMission_Result {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::ExecuteMission_Result::default())
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_Result {
  type RmwMsg = crate::action::rmw::ExecuteMission_Result;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        final_state_code: msg.final_state_code,
        error_code: msg.error_code,
        message: msg.message.as_str().into(),
        elapsed_sec: msg.elapsed_sec,
        failed_node: msg.failed_node.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      final_state_code: msg.final_state_code,
      error_code: msg.error_code,
        message: msg.message.as_str().into(),
      elapsed_sec: msg.elapsed_sec,
        failed_node: msg.failed_node.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      final_state_code: msg.final_state_code,
      error_code: msg.error_code,
      message: msg.message.to_string(),
      elapsed_sec: msg.elapsed_sec,
      failed_node: msg.failed_node.to_string(),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_Feedback {
    pub task_id: std::string::String,
    pub priority: u8,
    pub stamp: builtin_interfaces::msg::Time,
    pub state_code: u8,
    pub error_code: u16,
    pub message: std::string::String,
    pub progress: f32,
    pub distance_error: f32,
    pub yaw_error: f32,
    pub current_pose: geometry_msgs::msg::Pose,
    pub current_twist: geometry_msgs::msg::Twist,
    pub current_node: std::string::String,
    pub current_stage: std::string::String,
}



impl Default for ExecuteMission_Feedback {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::ExecuteMission_Feedback::default())
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_Feedback {
  type RmwMsg = crate::action::rmw::ExecuteMission_Feedback;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
        priority: msg.priority,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
        state_code: msg.state_code,
        error_code: msg.error_code,
        message: msg.message.as_str().into(),
        progress: msg.progress,
        distance_error: msg.distance_error,
        yaw_error: msg.yaw_error,
        current_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Owned(msg.current_pose)).into_owned(),
        current_twist: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Owned(msg.current_twist)).into_owned(),
        current_node: msg.current_node.as_str().into(),
        current_stage: msg.current_stage.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        task_id: msg.task_id.as_str().into(),
      priority: msg.priority,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      state_code: msg.state_code,
      error_code: msg.error_code,
        message: msg.message.as_str().into(),
      progress: msg.progress,
      distance_error: msg.distance_error,
      yaw_error: msg.yaw_error,
        current_pose: geometry_msgs::msg::Pose::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_pose)).into_owned(),
        current_twist: geometry_msgs::msg::Twist::into_rmw_message(std::borrow::Cow::Borrowed(&msg.current_twist)).into_owned(),
        current_node: msg.current_node.as_str().into(),
        current_stage: msg.current_stage.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      task_id: msg.task_id.to_string(),
      priority: msg.priority,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
      state_code: msg.state_code,
      error_code: msg.error_code,
      message: msg.message.to_string(),
      progress: msg.progress,
      distance_error: msg.distance_error,
      yaw_error: msg.yaw_error,
      current_pose: geometry_msgs::msg::Pose::from_rmw_message(msg.current_pose),
      current_twist: geometry_msgs::msg::Twist::from_rmw_message(msg.current_twist),
      current_node: msg.current_node.to_string(),
      current_stage: msg.current_stage.to_string(),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_FeedbackMessage {
    pub goal_id: unique_identifier_msgs::msg::UUID,
    pub feedback: crate::action::ExecuteMission_Feedback,
}



impl Default for ExecuteMission_FeedbackMessage {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::ExecuteMission_FeedbackMessage::default())
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_FeedbackMessage {
  type RmwMsg = crate::action::rmw::ExecuteMission_FeedbackMessage;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        feedback: crate::action::ExecuteMission_Feedback::into_rmw_message(std::borrow::Cow::Owned(msg.feedback)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        feedback: crate::action::ExecuteMission_Feedback::into_rmw_message(std::borrow::Cow::Borrowed(&msg.feedback)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      feedback: crate::action::ExecuteMission_Feedback::from_rmw_message(msg.feedback),
    }
  }
}





#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_SendGoal_Request {
    pub goal_id: unique_identifier_msgs::msg::UUID,
    pub goal: crate::action::Takeoff_Goal,
}



impl Default for Takeoff_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Takeoff_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Takeoff_SendGoal_Request {
  type RmwMsg = crate::action::rmw::Takeoff_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: crate::action::Takeoff_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: crate::action::Takeoff_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: crate::action::Takeoff_Goal::from_rmw_message(msg.goal),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_SendGoal_Response {
    pub accepted: bool,
    pub stamp: builtin_interfaces::msg::Time,
}



impl Default for Takeoff_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Takeoff_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Takeoff_SendGoal_Response {
  type RmwMsg = crate::action::rmw::Takeoff_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_GetResult_Request {
    pub goal_id: unique_identifier_msgs::msg::UUID,
}



impl Default for Takeoff_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Takeoff_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Takeoff_GetResult_Request {
  type RmwMsg = crate::action::rmw::Takeoff_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Takeoff_GetResult_Response {
    pub status: i8,
    pub result: crate::action::Takeoff_Result,
}



impl Default for Takeoff_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Takeoff_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Takeoff_GetResult_Response {
  type RmwMsg = crate::action::rmw::Takeoff_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: crate::action::Takeoff_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: crate::action::Takeoff_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: crate::action::Takeoff_Result::from_rmw_message(msg.result),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_SendGoal_Request {
    pub goal_id: unique_identifier_msgs::msg::UUID,
    pub goal: crate::action::GoToTarget_Goal,
}



impl Default for GoToTarget_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::GoToTarget_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_SendGoal_Request {
  type RmwMsg = crate::action::rmw::GoToTarget_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: crate::action::GoToTarget_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: crate::action::GoToTarget_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: crate::action::GoToTarget_Goal::from_rmw_message(msg.goal),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_SendGoal_Response {
    pub accepted: bool,
    pub stamp: builtin_interfaces::msg::Time,
}



impl Default for GoToTarget_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::GoToTarget_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_SendGoal_Response {
  type RmwMsg = crate::action::rmw::GoToTarget_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_GetResult_Request {
    pub goal_id: unique_identifier_msgs::msg::UUID,
}



impl Default for GoToTarget_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::GoToTarget_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_GetResult_Request {
  type RmwMsg = crate::action::rmw::GoToTarget_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct GoToTarget_GetResult_Response {
    pub status: i8,
    pub result: crate::action::GoToTarget_Result,
}



impl Default for GoToTarget_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::GoToTarget_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for GoToTarget_GetResult_Response {
  type RmwMsg = crate::action::rmw::GoToTarget_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: crate::action::GoToTarget_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: crate::action::GoToTarget_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: crate::action::GoToTarget_Result::from_rmw_message(msg.result),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_SendGoal_Request {
    pub goal_id: unique_identifier_msgs::msg::UUID,
    pub goal: crate::action::TrackVelocity_Goal,
}



impl Default for TrackVelocity_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::TrackVelocity_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_SendGoal_Request {
  type RmwMsg = crate::action::rmw::TrackVelocity_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: crate::action::TrackVelocity_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: crate::action::TrackVelocity_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: crate::action::TrackVelocity_Goal::from_rmw_message(msg.goal),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_SendGoal_Response {
    pub accepted: bool,
    pub stamp: builtin_interfaces::msg::Time,
}



impl Default for TrackVelocity_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::TrackVelocity_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_SendGoal_Response {
  type RmwMsg = crate::action::rmw::TrackVelocity_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_GetResult_Request {
    pub goal_id: unique_identifier_msgs::msg::UUID,
}



impl Default for TrackVelocity_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::TrackVelocity_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_GetResult_Request {
  type RmwMsg = crate::action::rmw::TrackVelocity_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct TrackVelocity_GetResult_Response {
    pub status: i8,
    pub result: crate::action::TrackVelocity_Result,
}



impl Default for TrackVelocity_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::TrackVelocity_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for TrackVelocity_GetResult_Response {
  type RmwMsg = crate::action::rmw::TrackVelocity_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: crate::action::TrackVelocity_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: crate::action::TrackVelocity_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: crate::action::TrackVelocity_Result::from_rmw_message(msg.result),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_SendGoal_Request {
    pub goal_id: unique_identifier_msgs::msg::UUID,
    pub goal: crate::action::Land_Goal,
}



impl Default for Land_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Land_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Land_SendGoal_Request {
  type RmwMsg = crate::action::rmw::Land_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: crate::action::Land_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: crate::action::Land_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: crate::action::Land_Goal::from_rmw_message(msg.goal),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_SendGoal_Response {
    pub accepted: bool,
    pub stamp: builtin_interfaces::msg::Time,
}



impl Default for Land_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Land_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Land_SendGoal_Response {
  type RmwMsg = crate::action::rmw::Land_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_GetResult_Request {
    pub goal_id: unique_identifier_msgs::msg::UUID,
}



impl Default for Land_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Land_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Land_GetResult_Request {
  type RmwMsg = crate::action::rmw::Land_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Land_GetResult_Response {
    pub status: i8,
    pub result: crate::action::Land_Result,
}



impl Default for Land_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::Land_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Land_GetResult_Response {
  type RmwMsg = crate::action::rmw::Land_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: crate::action::Land_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: crate::action::Land_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: crate::action::Land_Result::from_rmw_message(msg.result),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_SendGoal_Request {
    pub goal_id: unique_identifier_msgs::msg::UUID,
    pub goal: crate::action::ExecuteMission_Goal,
}



impl Default for ExecuteMission_SendGoal_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::ExecuteMission_SendGoal_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_SendGoal_Request {
  type RmwMsg = crate::action::rmw::ExecuteMission_SendGoal_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
        goal: crate::action::ExecuteMission_Goal::into_rmw_message(std::borrow::Cow::Owned(msg.goal)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
        goal: crate::action::ExecuteMission_Goal::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
      goal: crate::action::ExecuteMission_Goal::from_rmw_message(msg.goal),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_SendGoal_Response {
    pub accepted: bool,
    pub stamp: builtin_interfaces::msg::Time,
}



impl Default for ExecuteMission_SendGoal_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::ExecuteMission_SendGoal_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_SendGoal_Response {
  type RmwMsg = crate::action::rmw::ExecuteMission_SendGoal_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Owned(msg.stamp)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        stamp: builtin_interfaces::msg::Time::into_rmw_message(std::borrow::Cow::Borrowed(&msg.stamp)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      stamp: builtin_interfaces::msg::Time::from_rmw_message(msg.stamp),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_GetResult_Request {
    pub goal_id: unique_identifier_msgs::msg::UUID,
}



impl Default for ExecuteMission_GetResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::ExecuteMission_GetResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_GetResult_Request {
  type RmwMsg = crate::action::rmw::ExecuteMission_GetResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Owned(msg.goal_id)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        goal_id: unique_identifier_msgs::msg::UUID::into_rmw_message(std::borrow::Cow::Borrowed(&msg.goal_id)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      goal_id: unique_identifier_msgs::msg::UUID::from_rmw_message(msg.goal_id),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ExecuteMission_GetResult_Response {
    pub status: i8,
    pub result: crate::action::ExecuteMission_Result,
}



impl Default for ExecuteMission_GetResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::action::rmw::ExecuteMission_GetResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for ExecuteMission_GetResult_Response {
  type RmwMsg = crate::action::rmw::ExecuteMission_GetResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        status: msg.status,
        result: crate::action::ExecuteMission_Result::into_rmw_message(std::borrow::Cow::Owned(msg.result)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      status: msg.status,
        result: crate::action::ExecuteMission_Result::into_rmw_message(std::borrow::Cow::Borrowed(&msg.result)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      status: msg.status,
      result: crate::action::ExecuteMission_Result::from_rmw_message(msg.result),
    }
  }
}






#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__Takeoff_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__Takeoff_SendGoal
pub struct Takeoff_SendGoal;

impl rosidl_runtime_rs::Service for Takeoff_SendGoal {
  type Request = crate::action::Takeoff_SendGoal_Request;
  type Response = crate::action::Takeoff_SendGoal_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__Takeoff_SendGoal() }
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__Takeoff_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__Takeoff_GetResult
pub struct Takeoff_GetResult;

impl rosidl_runtime_rs::Service for Takeoff_GetResult {
  type Request = crate::action::Takeoff_GetResult_Request;
  type Response = crate::action::Takeoff_GetResult_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__Takeoff_GetResult() }
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__GoToTarget_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__GoToTarget_SendGoal
pub struct GoToTarget_SendGoal;

impl rosidl_runtime_rs::Service for GoToTarget_SendGoal {
  type Request = crate::action::GoToTarget_SendGoal_Request;
  type Response = crate::action::GoToTarget_SendGoal_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__GoToTarget_SendGoal() }
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__GoToTarget_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__GoToTarget_GetResult
pub struct GoToTarget_GetResult;

impl rosidl_runtime_rs::Service for GoToTarget_GetResult {
  type Request = crate::action::GoToTarget_GetResult_Request;
  type Response = crate::action::GoToTarget_GetResult_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__GoToTarget_GetResult() }
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__TrackVelocity_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__TrackVelocity_SendGoal
pub struct TrackVelocity_SendGoal;

impl rosidl_runtime_rs::Service for TrackVelocity_SendGoal {
  type Request = crate::action::TrackVelocity_SendGoal_Request;
  type Response = crate::action::TrackVelocity_SendGoal_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__TrackVelocity_SendGoal() }
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__TrackVelocity_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__TrackVelocity_GetResult
pub struct TrackVelocity_GetResult;

impl rosidl_runtime_rs::Service for TrackVelocity_GetResult {
  type Request = crate::action::TrackVelocity_GetResult_Request;
  type Response = crate::action::TrackVelocity_GetResult_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__TrackVelocity_GetResult() }
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__Land_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__Land_SendGoal
pub struct Land_SendGoal;

impl rosidl_runtime_rs::Service for Land_SendGoal {
  type Request = crate::action::Land_SendGoal_Request;
  type Response = crate::action::Land_SendGoal_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__Land_SendGoal() }
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__Land_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__Land_GetResult
pub struct Land_GetResult;

impl rosidl_runtime_rs::Service for Land_GetResult {
  type Request = crate::action::Land_GetResult_Request;
  type Response = crate::action::Land_GetResult_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__Land_GetResult() }
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__ExecuteMission_SendGoal() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__ExecuteMission_SendGoal
pub struct ExecuteMission_SendGoal;

impl rosidl_runtime_rs::Service for ExecuteMission_SendGoal {
  type Request = crate::action::ExecuteMission_SendGoal_Request;
  type Response = crate::action::ExecuteMission_SendGoal_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__ExecuteMission_SendGoal() }
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__action__ExecuteMission_GetResult() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__ExecuteMission_GetResult
pub struct ExecuteMission_GetResult;

impl rosidl_runtime_rs::Service for ExecuteMission_GetResult {
  type Request = crate::action::ExecuteMission_GetResult_Request;
  type Response = crate::action::ExecuteMission_GetResult_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__action__ExecuteMission_GetResult() }
  }
}






#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__messages__action__Takeoff() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__Takeoff
pub struct Takeoff;

impl rosidl_runtime_rs::Action for Takeoff {
  type Goal = crate::action::Takeoff_Goal;
  type Result = crate::action::Takeoff_Result;
  type Feedback = crate::action::Takeoff_Feedback;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__messages__action__Takeoff() }
  }
}

impl rosidl_runtime_rs::ActionImpl for Takeoff {
  type GoalStatusMessage = action_msgs::msg::rmw::GoalStatusArray;
  type FeedbackMessage = crate::action::rmw::Takeoff_FeedbackMessage;

  type SendGoalService = crate::action::rmw::Takeoff_SendGoal;
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;
  type GetResultService = crate::action::rmw::Takeoff_GetResult;

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: crate::action::rmw::Takeoff_Goal,
  ) -> crate::action::rmw::Takeoff_SendGoal_Request {
    crate::action::rmw::Takeoff_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn get_goal_request_uuid(
    request: &crate::action::rmw::Takeoff_SendGoal_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> crate::action::rmw::Takeoff_SendGoal_Response {
    crate::action::rmw::Takeoff_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &crate::action::rmw::Takeoff_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &crate::action::rmw::Takeoff_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: crate::action::rmw::Takeoff_Feedback,
  ) -> crate::action::rmw::Takeoff_FeedbackMessage {
    let mut message = crate::action::rmw::Takeoff_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn get_feedback_message_uuid(
    feedback: &crate::action::rmw::Takeoff_FeedbackMessage,
  ) -> &[u8; 16] {
    &feedback.goal_id.uuid
  }

  fn get_feedback_message_feedback(
    feedback: &crate::action::rmw::Takeoff_FeedbackMessage,
  ) -> &crate::action::rmw::Takeoff_Feedback {
    &feedback.feedback
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> crate::action::rmw::Takeoff_GetResult_Request {
    crate::action::rmw::Takeoff_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &crate::action::rmw::Takeoff_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: crate::action::rmw::Takeoff_Result,
  ) -> crate::action::rmw::Takeoff_GetResult_Response {
    crate::action::rmw::Takeoff_GetResult_Response {
      status,
      result,
    }
  }

  fn get_result_response_result(
    response: &crate::action::rmw::Takeoff_GetResult_Response,
  ) -> &crate::action::rmw::Takeoff_Result {
    &response.result
  }

  fn get_result_response_status(
    response: &crate::action::rmw::Takeoff_GetResult_Response,
  ) -> i8 {
    response.status
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__messages__action__GoToTarget() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__GoToTarget
pub struct GoToTarget;

impl rosidl_runtime_rs::Action for GoToTarget {
  type Goal = crate::action::GoToTarget_Goal;
  type Result = crate::action::GoToTarget_Result;
  type Feedback = crate::action::GoToTarget_Feedback;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__messages__action__GoToTarget() }
  }
}

impl rosidl_runtime_rs::ActionImpl for GoToTarget {
  type GoalStatusMessage = action_msgs::msg::rmw::GoalStatusArray;
  type FeedbackMessage = crate::action::rmw::GoToTarget_FeedbackMessage;

  type SendGoalService = crate::action::rmw::GoToTarget_SendGoal;
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;
  type GetResultService = crate::action::rmw::GoToTarget_GetResult;

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: crate::action::rmw::GoToTarget_Goal,
  ) -> crate::action::rmw::GoToTarget_SendGoal_Request {
    crate::action::rmw::GoToTarget_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn get_goal_request_uuid(
    request: &crate::action::rmw::GoToTarget_SendGoal_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> crate::action::rmw::GoToTarget_SendGoal_Response {
    crate::action::rmw::GoToTarget_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &crate::action::rmw::GoToTarget_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &crate::action::rmw::GoToTarget_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: crate::action::rmw::GoToTarget_Feedback,
  ) -> crate::action::rmw::GoToTarget_FeedbackMessage {
    let mut message = crate::action::rmw::GoToTarget_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn get_feedback_message_uuid(
    feedback: &crate::action::rmw::GoToTarget_FeedbackMessage,
  ) -> &[u8; 16] {
    &feedback.goal_id.uuid
  }

  fn get_feedback_message_feedback(
    feedback: &crate::action::rmw::GoToTarget_FeedbackMessage,
  ) -> &crate::action::rmw::GoToTarget_Feedback {
    &feedback.feedback
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> crate::action::rmw::GoToTarget_GetResult_Request {
    crate::action::rmw::GoToTarget_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &crate::action::rmw::GoToTarget_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: crate::action::rmw::GoToTarget_Result,
  ) -> crate::action::rmw::GoToTarget_GetResult_Response {
    crate::action::rmw::GoToTarget_GetResult_Response {
      status,
      result,
    }
  }

  fn get_result_response_result(
    response: &crate::action::rmw::GoToTarget_GetResult_Response,
  ) -> &crate::action::rmw::GoToTarget_Result {
    &response.result
  }

  fn get_result_response_status(
    response: &crate::action::rmw::GoToTarget_GetResult_Response,
  ) -> i8 {
    response.status
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__messages__action__TrackVelocity() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__TrackVelocity
pub struct TrackVelocity;

impl rosidl_runtime_rs::Action for TrackVelocity {
  type Goal = crate::action::TrackVelocity_Goal;
  type Result = crate::action::TrackVelocity_Result;
  type Feedback = crate::action::TrackVelocity_Feedback;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__messages__action__TrackVelocity() }
  }
}

impl rosidl_runtime_rs::ActionImpl for TrackVelocity {
  type GoalStatusMessage = action_msgs::msg::rmw::GoalStatusArray;
  type FeedbackMessage = crate::action::rmw::TrackVelocity_FeedbackMessage;

  type SendGoalService = crate::action::rmw::TrackVelocity_SendGoal;
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;
  type GetResultService = crate::action::rmw::TrackVelocity_GetResult;

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: crate::action::rmw::TrackVelocity_Goal,
  ) -> crate::action::rmw::TrackVelocity_SendGoal_Request {
    crate::action::rmw::TrackVelocity_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn get_goal_request_uuid(
    request: &crate::action::rmw::TrackVelocity_SendGoal_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> crate::action::rmw::TrackVelocity_SendGoal_Response {
    crate::action::rmw::TrackVelocity_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &crate::action::rmw::TrackVelocity_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &crate::action::rmw::TrackVelocity_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: crate::action::rmw::TrackVelocity_Feedback,
  ) -> crate::action::rmw::TrackVelocity_FeedbackMessage {
    let mut message = crate::action::rmw::TrackVelocity_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn get_feedback_message_uuid(
    feedback: &crate::action::rmw::TrackVelocity_FeedbackMessage,
  ) -> &[u8; 16] {
    &feedback.goal_id.uuid
  }

  fn get_feedback_message_feedback(
    feedback: &crate::action::rmw::TrackVelocity_FeedbackMessage,
  ) -> &crate::action::rmw::TrackVelocity_Feedback {
    &feedback.feedback
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> crate::action::rmw::TrackVelocity_GetResult_Request {
    crate::action::rmw::TrackVelocity_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &crate::action::rmw::TrackVelocity_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: crate::action::rmw::TrackVelocity_Result,
  ) -> crate::action::rmw::TrackVelocity_GetResult_Response {
    crate::action::rmw::TrackVelocity_GetResult_Response {
      status,
      result,
    }
  }

  fn get_result_response_result(
    response: &crate::action::rmw::TrackVelocity_GetResult_Response,
  ) -> &crate::action::rmw::TrackVelocity_Result {
    &response.result
  }

  fn get_result_response_status(
    response: &crate::action::rmw::TrackVelocity_GetResult_Response,
  ) -> i8 {
    response.status
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__messages__action__Land() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__Land
pub struct Land;

impl rosidl_runtime_rs::Action for Land {
  type Goal = crate::action::Land_Goal;
  type Result = crate::action::Land_Result;
  type Feedback = crate::action::Land_Feedback;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__messages__action__Land() }
  }
}

impl rosidl_runtime_rs::ActionImpl for Land {
  type GoalStatusMessage = action_msgs::msg::rmw::GoalStatusArray;
  type FeedbackMessage = crate::action::rmw::Land_FeedbackMessage;

  type SendGoalService = crate::action::rmw::Land_SendGoal;
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;
  type GetResultService = crate::action::rmw::Land_GetResult;

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: crate::action::rmw::Land_Goal,
  ) -> crate::action::rmw::Land_SendGoal_Request {
    crate::action::rmw::Land_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn get_goal_request_uuid(
    request: &crate::action::rmw::Land_SendGoal_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> crate::action::rmw::Land_SendGoal_Response {
    crate::action::rmw::Land_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &crate::action::rmw::Land_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &crate::action::rmw::Land_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: crate::action::rmw::Land_Feedback,
  ) -> crate::action::rmw::Land_FeedbackMessage {
    let mut message = crate::action::rmw::Land_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn get_feedback_message_uuid(
    feedback: &crate::action::rmw::Land_FeedbackMessage,
  ) -> &[u8; 16] {
    &feedback.goal_id.uuid
  }

  fn get_feedback_message_feedback(
    feedback: &crate::action::rmw::Land_FeedbackMessage,
  ) -> &crate::action::rmw::Land_Feedback {
    &feedback.feedback
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> crate::action::rmw::Land_GetResult_Request {
    crate::action::rmw::Land_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &crate::action::rmw::Land_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: crate::action::rmw::Land_Result,
  ) -> crate::action::rmw::Land_GetResult_Response {
    crate::action::rmw::Land_GetResult_Response {
      status,
      result,
    }
  }

  fn get_result_response_result(
    response: &crate::action::rmw::Land_GetResult_Response,
  ) -> &crate::action::rmw::Land_Result {
    &response.result
  }

  fn get_result_response_status(
    response: &crate::action::rmw::Land_GetResult_Response,
  ) -> i8 {
    response.status
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_action_type_support_handle__messages__action__ExecuteMission() -> *const std::ffi::c_void;
}

// Corresponds to messages__action__ExecuteMission
pub struct ExecuteMission;

impl rosidl_runtime_rs::Action for ExecuteMission {
  type Goal = crate::action::ExecuteMission_Goal;
  type Result = crate::action::ExecuteMission_Result;
  type Feedback = crate::action::ExecuteMission_Feedback;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_action_type_support_handle__messages__action__ExecuteMission() }
  }
}

impl rosidl_runtime_rs::ActionImpl for ExecuteMission {
  type GoalStatusMessage = action_msgs::msg::rmw::GoalStatusArray;
  type FeedbackMessage = crate::action::rmw::ExecuteMission_FeedbackMessage;

  type SendGoalService = crate::action::rmw::ExecuteMission_SendGoal;
  type CancelGoalService = action_msgs::srv::rmw::CancelGoal;
  type GetResultService = crate::action::rmw::ExecuteMission_GetResult;

  fn create_goal_request(
    goal_id: &[u8; 16],
    goal: crate::action::rmw::ExecuteMission_Goal,
  ) -> crate::action::rmw::ExecuteMission_SendGoal_Request {
    crate::action::rmw::ExecuteMission_SendGoal_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
      goal,
    }
  }

  fn get_goal_request_uuid(
    request: &crate::action::rmw::ExecuteMission_SendGoal_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_goal_response(
    accepted: bool,
    stamp: (i32, u32),
  ) -> crate::action::rmw::ExecuteMission_SendGoal_Response {
    crate::action::rmw::ExecuteMission_SendGoal_Response {
      accepted,
      stamp: builtin_interfaces::msg::rmw::Time {
        sec: stamp.0,
        nanosec: stamp.1,
      },
    }
  }

  fn get_goal_response_accepted(
    response: &crate::action::rmw::ExecuteMission_SendGoal_Response,
  ) -> bool {
    response.accepted
  }

  fn get_goal_response_stamp(
    response: &crate::action::rmw::ExecuteMission_SendGoal_Response,
  ) -> (i32, u32) {
    (response.stamp.sec, response.stamp.nanosec)
  }

  fn create_feedback_message(
    goal_id: &[u8; 16],
    feedback: crate::action::rmw::ExecuteMission_Feedback,
  ) -> crate::action::rmw::ExecuteMission_FeedbackMessage {
    let mut message = crate::action::rmw::ExecuteMission_FeedbackMessage::default();
    message.goal_id.uuid = *goal_id;
    message.feedback = feedback;
    message
  }

  fn get_feedback_message_uuid(
    feedback: &crate::action::rmw::ExecuteMission_FeedbackMessage,
  ) -> &[u8; 16] {
    &feedback.goal_id.uuid
  }

  fn get_feedback_message_feedback(
    feedback: &crate::action::rmw::ExecuteMission_FeedbackMessage,
  ) -> &crate::action::rmw::ExecuteMission_Feedback {
    &feedback.feedback
  }

  fn create_result_request(
    goal_id: &[u8; 16],
  ) -> crate::action::rmw::ExecuteMission_GetResult_Request {
    crate::action::rmw::ExecuteMission_GetResult_Request {
      goal_id: unique_identifier_msgs::msg::rmw::UUID { uuid: *goal_id },
    }
  }

  fn get_result_request_uuid(
    request: &crate::action::rmw::ExecuteMission_GetResult_Request,
  ) -> &[u8; 16] {
    &request.goal_id.uuid
  }

  fn create_result_response(
    status: i8,
    result: crate::action::rmw::ExecuteMission_Result,
  ) -> crate::action::rmw::ExecuteMission_GetResult_Response {
    crate::action::rmw::ExecuteMission_GetResult_Response {
      status,
      result,
    }
  }

  fn get_result_response_result(
    response: &crate::action::rmw::ExecuteMission_GetResult_Response,
  ) -> &crate::action::rmw::ExecuteMission_Result {
    &response.result
  }

  fn get_result_response_status(
    response: &crate::action::rmw::ExecuteMission_GetResult_Response,
  ) -> i8 {
    response.status
  }
}


