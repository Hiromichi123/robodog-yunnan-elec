// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:action/ExecuteMission.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_
#define MESSAGES__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/action/detail/execute_mission__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Goal_timeout_sec
{
public:
  explicit Init_ExecuteMission_Goal_timeout_sec(::messages::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  ::messages::action::ExecuteMission_Goal timeout_sec(::messages::action::ExecuteMission_Goal::_timeout_sec_type arg)
  {
    msg_.timeout_sec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_bt_xml_uri
{
public:
  explicit Init_ExecuteMission_Goal_bt_xml_uri(::messages::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Goal_timeout_sec bt_xml_uri(::messages::action::ExecuteMission_Goal::_bt_xml_uri_type arg)
  {
    msg_.bt_xml_uri = std::move(arg);
    return Init_ExecuteMission_Goal_timeout_sec(msg_);
  }

private:
  ::messages::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_mission_name
{
public:
  explicit Init_ExecuteMission_Goal_mission_name(::messages::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Goal_bt_xml_uri mission_name(::messages::action::ExecuteMission_Goal::_mission_name_type arg)
  {
    msg_.mission_name = std::move(arg);
    return Init_ExecuteMission_Goal_bt_xml_uri(msg_);
  }

private:
  ::messages::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_priority
{
public:
  explicit Init_ExecuteMission_Goal_priority(::messages::action::ExecuteMission_Goal & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Goal_mission_name priority(::messages::action::ExecuteMission_Goal::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return Init_ExecuteMission_Goal_mission_name(msg_);
  }

private:
  ::messages::action::ExecuteMission_Goal msg_;
};

class Init_ExecuteMission_Goal_task_id
{
public:
  Init_ExecuteMission_Goal_task_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Goal_priority task_id(::messages::action::ExecuteMission_Goal::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_ExecuteMission_Goal_priority(msg_);
  }

private:
  ::messages::action::ExecuteMission_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::ExecuteMission_Goal>()
{
  return messages::action::builder::Init_ExecuteMission_Goal_task_id();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Result_failed_node
{
public:
  explicit Init_ExecuteMission_Result_failed_node(::messages::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  ::messages::action::ExecuteMission_Result failed_node(::messages::action::ExecuteMission_Result::_failed_node_type arg)
  {
    msg_.failed_node = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_elapsed_sec
{
public:
  explicit Init_ExecuteMission_Result_elapsed_sec(::messages::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Result_failed_node elapsed_sec(::messages::action::ExecuteMission_Result::_elapsed_sec_type arg)
  {
    msg_.elapsed_sec = std::move(arg);
    return Init_ExecuteMission_Result_failed_node(msg_);
  }

private:
  ::messages::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_message
{
public:
  explicit Init_ExecuteMission_Result_message(::messages::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Result_elapsed_sec message(::messages::action::ExecuteMission_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_ExecuteMission_Result_elapsed_sec(msg_);
  }

private:
  ::messages::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_error_code
{
public:
  explicit Init_ExecuteMission_Result_error_code(::messages::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Result_message error_code(::messages::action::ExecuteMission_Result::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_ExecuteMission_Result_message(msg_);
  }

private:
  ::messages::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_final_state_code
{
public:
  explicit Init_ExecuteMission_Result_final_state_code(::messages::action::ExecuteMission_Result & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Result_error_code final_state_code(::messages::action::ExecuteMission_Result::_final_state_code_type arg)
  {
    msg_.final_state_code = std::move(arg);
    return Init_ExecuteMission_Result_error_code(msg_);
  }

private:
  ::messages::action::ExecuteMission_Result msg_;
};

class Init_ExecuteMission_Result_success
{
public:
  Init_ExecuteMission_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Result_final_state_code success(::messages::action::ExecuteMission_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ExecuteMission_Result_final_state_code(msg_);
  }

private:
  ::messages::action::ExecuteMission_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::ExecuteMission_Result>()
{
  return messages::action::builder::Init_ExecuteMission_Result_success();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_Feedback_current_stage
{
public:
  explicit Init_ExecuteMission_Feedback_current_stage(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  ::messages::action::ExecuteMission_Feedback current_stage(::messages::action::ExecuteMission_Feedback::_current_stage_type arg)
  {
    msg_.current_stage = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_current_node
{
public:
  explicit Init_ExecuteMission_Feedback_current_node(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_current_stage current_node(::messages::action::ExecuteMission_Feedback::_current_node_type arg)
  {
    msg_.current_node = std::move(arg);
    return Init_ExecuteMission_Feedback_current_stage(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_current_twist
{
public:
  explicit Init_ExecuteMission_Feedback_current_twist(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_current_node current_twist(::messages::action::ExecuteMission_Feedback::_current_twist_type arg)
  {
    msg_.current_twist = std::move(arg);
    return Init_ExecuteMission_Feedback_current_node(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_current_pose
{
public:
  explicit Init_ExecuteMission_Feedback_current_pose(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_current_twist current_pose(::messages::action::ExecuteMission_Feedback::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return Init_ExecuteMission_Feedback_current_twist(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_yaw_error
{
public:
  explicit Init_ExecuteMission_Feedback_yaw_error(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_current_pose yaw_error(::messages::action::ExecuteMission_Feedback::_yaw_error_type arg)
  {
    msg_.yaw_error = std::move(arg);
    return Init_ExecuteMission_Feedback_current_pose(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_distance_error
{
public:
  explicit Init_ExecuteMission_Feedback_distance_error(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_yaw_error distance_error(::messages::action::ExecuteMission_Feedback::_distance_error_type arg)
  {
    msg_.distance_error = std::move(arg);
    return Init_ExecuteMission_Feedback_yaw_error(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_progress
{
public:
  explicit Init_ExecuteMission_Feedback_progress(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_distance_error progress(::messages::action::ExecuteMission_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return Init_ExecuteMission_Feedback_distance_error(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_message
{
public:
  explicit Init_ExecuteMission_Feedback_message(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_progress message(::messages::action::ExecuteMission_Feedback::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_ExecuteMission_Feedback_progress(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_error_code
{
public:
  explicit Init_ExecuteMission_Feedback_error_code(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_message error_code(::messages::action::ExecuteMission_Feedback::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_ExecuteMission_Feedback_message(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_state_code
{
public:
  explicit Init_ExecuteMission_Feedback_state_code(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_error_code state_code(::messages::action::ExecuteMission_Feedback::_state_code_type arg)
  {
    msg_.state_code = std::move(arg);
    return Init_ExecuteMission_Feedback_error_code(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_stamp
{
public:
  explicit Init_ExecuteMission_Feedback_stamp(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_state_code stamp(::messages::action::ExecuteMission_Feedback::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_ExecuteMission_Feedback_state_code(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_priority
{
public:
  explicit Init_ExecuteMission_Feedback_priority(::messages::action::ExecuteMission_Feedback & msg)
  : msg_(msg)
  {}
  Init_ExecuteMission_Feedback_stamp priority(::messages::action::ExecuteMission_Feedback::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return Init_ExecuteMission_Feedback_stamp(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

class Init_ExecuteMission_Feedback_task_id
{
public:
  Init_ExecuteMission_Feedback_task_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_Feedback_priority task_id(::messages::action::ExecuteMission_Feedback::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_ExecuteMission_Feedback_priority(msg_);
  }

private:
  ::messages::action::ExecuteMission_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::ExecuteMission_Feedback>()
{
  return messages::action::builder::Init_ExecuteMission_Feedback_task_id();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_SendGoal_Request_goal
{
public:
  explicit Init_ExecuteMission_SendGoal_Request_goal(::messages::action::ExecuteMission_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::messages::action::ExecuteMission_SendGoal_Request goal(::messages::action::ExecuteMission_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::ExecuteMission_SendGoal_Request msg_;
};

class Init_ExecuteMission_SendGoal_Request_goal_id
{
public:
  Init_ExecuteMission_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_SendGoal_Request_goal goal_id(::messages::action::ExecuteMission_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteMission_SendGoal_Request_goal(msg_);
  }

private:
  ::messages::action::ExecuteMission_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::ExecuteMission_SendGoal_Request>()
{
  return messages::action::builder::Init_ExecuteMission_SendGoal_Request_goal_id();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_SendGoal_Response_stamp
{
public:
  explicit Init_ExecuteMission_SendGoal_Response_stamp(::messages::action::ExecuteMission_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::messages::action::ExecuteMission_SendGoal_Response stamp(::messages::action::ExecuteMission_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::ExecuteMission_SendGoal_Response msg_;
};

class Init_ExecuteMission_SendGoal_Response_accepted
{
public:
  Init_ExecuteMission_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_SendGoal_Response_stamp accepted(::messages::action::ExecuteMission_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ExecuteMission_SendGoal_Response_stamp(msg_);
  }

private:
  ::messages::action::ExecuteMission_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::ExecuteMission_SendGoal_Response>()
{
  return messages::action::builder::Init_ExecuteMission_SendGoal_Response_accepted();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_GetResult_Request_goal_id
{
public:
  Init_ExecuteMission_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::messages::action::ExecuteMission_GetResult_Request goal_id(::messages::action::ExecuteMission_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::ExecuteMission_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::ExecuteMission_GetResult_Request>()
{
  return messages::action::builder::Init_ExecuteMission_GetResult_Request_goal_id();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_GetResult_Response_result
{
public:
  explicit Init_ExecuteMission_GetResult_Response_result(::messages::action::ExecuteMission_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::messages::action::ExecuteMission_GetResult_Response result(::messages::action::ExecuteMission_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::ExecuteMission_GetResult_Response msg_;
};

class Init_ExecuteMission_GetResult_Response_status
{
public:
  Init_ExecuteMission_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_GetResult_Response_result status(::messages::action::ExecuteMission_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ExecuteMission_GetResult_Response_result(msg_);
  }

private:
  ::messages::action::ExecuteMission_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::ExecuteMission_GetResult_Response>()
{
  return messages::action::builder::Init_ExecuteMission_GetResult_Response_status();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_ExecuteMission_FeedbackMessage_feedback
{
public:
  explicit Init_ExecuteMission_FeedbackMessage_feedback(::messages::action::ExecuteMission_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::messages::action::ExecuteMission_FeedbackMessage feedback(::messages::action::ExecuteMission_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::ExecuteMission_FeedbackMessage msg_;
};

class Init_ExecuteMission_FeedbackMessage_goal_id
{
public:
  Init_ExecuteMission_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecuteMission_FeedbackMessage_feedback goal_id(::messages::action::ExecuteMission_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ExecuteMission_FeedbackMessage_feedback(msg_);
  }

private:
  ::messages::action::ExecuteMission_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::ExecuteMission_FeedbackMessage>()
{
  return messages::action::builder::Init_ExecuteMission_FeedbackMessage_goal_id();
}

}  // namespace messages

#endif  // MESSAGES__ACTION__DETAIL__EXECUTE_MISSION__BUILDER_HPP_
