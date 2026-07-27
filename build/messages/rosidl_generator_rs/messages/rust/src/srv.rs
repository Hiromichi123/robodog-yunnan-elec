

#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarCommand_Request {
    pub command: u16,
    pub param1: f32,
    pub param2: f32,
    pub param3: f32,
    pub param4: f32,
}

impl SmartCarCommand_Request {
    pub const SMART_CAR_COMMAND_ENABLE: u16 = 1;
    pub const SMART_CAR_COMMAND_DISABLE: u16 = 2;
    pub const SMART_CAR_COMMAND_STOP: u16 = 3;
    pub const SMART_CAR_COMMAND_RECENTER_SERVO: u16 = 4;
    pub const SMART_CAR_COMMAND_GYRO_CAL: u16 = 5;
    pub const SMART_CAR_COMMAND_CLEAR_FAULTS: u16 = 6;
    pub const SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT: u16 = 7;
    pub const SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT: u16 = 8;
    pub const SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT: u16 = 9;
    pub const SMART_CAR_COMMAND_STOP_CURVATURE_CAL: u16 = 10;
    pub const SMART_CAR_COMMAND_FIREWATER_OFF: u16 = 11;
}


impl Default for SmartCarCommand_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::srv::rmw::SmartCarCommand_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SmartCarCommand_Request {
  type RmwMsg = crate::srv::rmw::SmartCarCommand_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        command: msg.command,
        param1: msg.param1,
        param2: msg.param2,
        param3: msg.param3,
        param4: msg.param4,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      command: msg.command,
      param1: msg.param1,
      param2: msg.param2,
      param3: msg.param3,
      param4: msg.param4,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      command: msg.command,
      param1: msg.param1,
      param2: msg.param2,
      param3: msg.param3,
      param4: msg.param4,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarCommand_Response {
    pub accepted: bool,
    pub message: std::string::String,
}



impl Default for SmartCarCommand_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::srv::rmw::SmartCarCommand_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SmartCarCommand_Response {
  type RmwMsg = crate::srv::rmw::SmartCarCommand_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      message: msg.message.to_string(),
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarActuatorTest_Request {
    pub test_mask: u16,
    pub servo_angle_deg: f32,
    pub servo_pwm_us: u16,
    pub motor1_rpm: i16,
    pub motor2_rpm: i16,
    pub duration_ms: u16,
}

impl SmartCarActuatorTest_Request {
    pub const TEST_SERVO_ANGLE: u16 = 1;
    pub const TEST_SERVO_PWM: u16 = 2;
    pub const TEST_MOTOR_RPM: u16 = 4;
}


impl Default for SmartCarActuatorTest_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::srv::rmw::SmartCarActuatorTest_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SmartCarActuatorTest_Request {
  type RmwMsg = crate::srv::rmw::SmartCarActuatorTest_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        test_mask: msg.test_mask,
        servo_angle_deg: msg.servo_angle_deg,
        servo_pwm_us: msg.servo_pwm_us,
        motor1_rpm: msg.motor1_rpm,
        motor2_rpm: msg.motor2_rpm,
        duration_ms: msg.duration_ms,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      test_mask: msg.test_mask,
      servo_angle_deg: msg.servo_angle_deg,
      servo_pwm_us: msg.servo_pwm_us,
      motor1_rpm: msg.motor1_rpm,
      motor2_rpm: msg.motor2_rpm,
      duration_ms: msg.duration_ms,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      test_mask: msg.test_mask,
      servo_angle_deg: msg.servo_angle_deg,
      servo_pwm_us: msg.servo_pwm_us,
      motor1_rpm: msg.motor1_rpm,
      motor2_rpm: msg.motor2_rpm,
      duration_ms: msg.duration_ms,
    }
  }
}


#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarActuatorTest_Response {
    pub accepted: bool,
    pub message: std::string::String,
}



impl Default for SmartCarActuatorTest_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(crate::srv::rmw::SmartCarActuatorTest_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SmartCarActuatorTest_Response {
  type RmwMsg = crate::srv::rmw::SmartCarActuatorTest_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        accepted: msg.accepted,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      accepted: msg.accepted,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      accepted: msg.accepted,
      message: msg.message.to_string(),
    }
  }
}






#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__srv__SmartCarCommand() -> *const std::ffi::c_void;
}

// Corresponds to messages__srv__SmartCarCommand
pub struct SmartCarCommand;

impl rosidl_runtime_rs::Service for SmartCarCommand {
  type Request = crate::srv::SmartCarCommand_Request;
  type Response = crate::srv::SmartCarCommand_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__srv__SmartCarCommand() }
  }
}




#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__messages__srv__SmartCarActuatorTest() -> *const std::ffi::c_void;
}

// Corresponds to messages__srv__SmartCarActuatorTest
pub struct SmartCarActuatorTest;

impl rosidl_runtime_rs::Service for SmartCarActuatorTest {
  type Request = crate::srv::SmartCarActuatorTest_Request;
  type Response = crate::srv::SmartCarActuatorTest_Response;

  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__srv__SmartCarActuatorTest() }
  }
}




pub mod rmw {

#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};

#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__srv__SmartCarCommand_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__srv__SmartCarCommand_Request__init(msg: *mut SmartCarCommand_Request) -> bool;
    fn messages__srv__SmartCarCommand_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartCarCommand_Request>, size: usize) -> bool;
    fn messages__srv__SmartCarCommand_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartCarCommand_Request>);
    fn messages__srv__SmartCarCommand_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartCarCommand_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartCarCommand_Request>) -> bool;
}

// Corresponds to messages__srv__SmartCarCommand_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarCommand_Request {
    pub command: u16,
    pub param1: f32,
    pub param2: f32,
    pub param3: f32,
    pub param4: f32,
}

impl SmartCarCommand_Request {
    pub const SMART_CAR_COMMAND_ENABLE: u16 = 1;
    pub const SMART_CAR_COMMAND_DISABLE: u16 = 2;
    pub const SMART_CAR_COMMAND_STOP: u16 = 3;
    pub const SMART_CAR_COMMAND_RECENTER_SERVO: u16 = 4;
    pub const SMART_CAR_COMMAND_GYRO_CAL: u16 = 5;
    pub const SMART_CAR_COMMAND_CLEAR_FAULTS: u16 = 6;
    pub const SMART_CAR_COMMAND_START_CURVATURE_CAL_POINT: u16 = 7;
    pub const SMART_CAR_COMMAND_START_CURVATURE_CAL_LEFT: u16 = 8;
    pub const SMART_CAR_COMMAND_START_CURVATURE_CAL_RIGHT: u16 = 9;
    pub const SMART_CAR_COMMAND_STOP_CURVATURE_CAL: u16 = 10;
    pub const SMART_CAR_COMMAND_FIREWATER_OFF: u16 = 11;
}


impl Default for SmartCarCommand_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__srv__SmartCarCommand_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__srv__SmartCarCommand_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartCarCommand_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarCommand_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarCommand_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarCommand_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartCarCommand_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartCarCommand_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/srv/SmartCarCommand_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__srv__SmartCarCommand_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__srv__SmartCarCommand_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__srv__SmartCarCommand_Response__init(msg: *mut SmartCarCommand_Response) -> bool;
    fn messages__srv__SmartCarCommand_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartCarCommand_Response>, size: usize) -> bool;
    fn messages__srv__SmartCarCommand_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartCarCommand_Response>);
    fn messages__srv__SmartCarCommand_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartCarCommand_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartCarCommand_Response>) -> bool;
}

// Corresponds to messages__srv__SmartCarCommand_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarCommand_Response {
    pub accepted: bool,
    pub message: rosidl_runtime_rs::String,
}



impl Default for SmartCarCommand_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__srv__SmartCarCommand_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__srv__SmartCarCommand_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartCarCommand_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarCommand_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarCommand_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarCommand_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartCarCommand_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartCarCommand_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/srv/SmartCarCommand_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__srv__SmartCarCommand_Response() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__srv__SmartCarActuatorTest_Request() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__srv__SmartCarActuatorTest_Request__init(msg: *mut SmartCarActuatorTest_Request) -> bool;
    fn messages__srv__SmartCarActuatorTest_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartCarActuatorTest_Request>, size: usize) -> bool;
    fn messages__srv__SmartCarActuatorTest_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartCarActuatorTest_Request>);
    fn messages__srv__SmartCarActuatorTest_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartCarActuatorTest_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartCarActuatorTest_Request>) -> bool;
}

// Corresponds to messages__srv__SmartCarActuatorTest_Request
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarActuatorTest_Request {
    pub test_mask: u16,
    pub servo_angle_deg: f32,
    pub servo_pwm_us: u16,
    pub motor1_rpm: i16,
    pub motor2_rpm: i16,
    pub duration_ms: u16,
}

impl SmartCarActuatorTest_Request {
    pub const TEST_SERVO_ANGLE: u16 = 1;
    pub const TEST_SERVO_PWM: u16 = 2;
    pub const TEST_MOTOR_RPM: u16 = 4;
}


impl Default for SmartCarActuatorTest_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__srv__SmartCarActuatorTest_Request__init(&mut msg as *mut _) {
        panic!("Call to messages__srv__SmartCarActuatorTest_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartCarActuatorTest_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarActuatorTest_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarActuatorTest_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarActuatorTest_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartCarActuatorTest_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartCarActuatorTest_Request where Self: Sized {
  const TYPE_NAME: &'static str = "messages/srv/SmartCarActuatorTest_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__srv__SmartCarActuatorTest_Request() }
  }
}


#[link(name = "messages__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__messages__srv__SmartCarActuatorTest_Response() -> *const std::ffi::c_void;
}

#[link(name = "messages__rosidl_generator_c")]
extern "C" {
    fn messages__srv__SmartCarActuatorTest_Response__init(msg: *mut SmartCarActuatorTest_Response) -> bool;
    fn messages__srv__SmartCarActuatorTest_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SmartCarActuatorTest_Response>, size: usize) -> bool;
    fn messages__srv__SmartCarActuatorTest_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SmartCarActuatorTest_Response>);
    fn messages__srv__SmartCarActuatorTest_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SmartCarActuatorTest_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SmartCarActuatorTest_Response>) -> bool;
}

// Corresponds to messages__srv__SmartCarActuatorTest_Response
#[repr(C)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SmartCarActuatorTest_Response {
    pub accepted: bool,
    pub message: rosidl_runtime_rs::String,
}



impl Default for SmartCarActuatorTest_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !messages__srv__SmartCarActuatorTest_Response__init(&mut msg as *mut _) {
        panic!("Call to messages__srv__SmartCarActuatorTest_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SmartCarActuatorTest_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarActuatorTest_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarActuatorTest_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { messages__srv__SmartCarActuatorTest_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SmartCarActuatorTest_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SmartCarActuatorTest_Response where Self: Sized {
  const TYPE_NAME: &'static str = "messages/srv/SmartCarActuatorTest_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__messages__srv__SmartCarActuatorTest_Response() }
  }
}






  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__srv__SmartCarCommand() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__srv__SmartCarCommand
  pub struct SmartCarCommand;

  impl rosidl_runtime_rs::Service for SmartCarCommand {
    type Request = crate::srv::rmw::SmartCarCommand_Request;
    type Response = crate::srv::rmw::SmartCarCommand_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__srv__SmartCarCommand() }
    }
  }




  #[link(name = "messages__rosidl_typesupport_c")]
  extern "C" {
      fn rosidl_typesupport_c__get_service_type_support_handle__messages__srv__SmartCarActuatorTest() -> *const std::ffi::c_void;
  }

  // Corresponds to messages__srv__SmartCarActuatorTest
  pub struct SmartCarActuatorTest;

  impl rosidl_runtime_rs::Service for SmartCarActuatorTest {
    type Request = crate::srv::rmw::SmartCarActuatorTest_Request;
    type Response = crate::srv::rmw::SmartCarActuatorTest_Response;

    fn get_type_support() -> *const std::ffi::c_void {
      // SAFETY: No preconditions for this function.
      unsafe { rosidl_typesupport_c__get_service_type_support_handle__messages__srv__SmartCarActuatorTest() }
    }
  }


}  // mod rmw
