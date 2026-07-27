// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:action/GoToTarget.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__ACTION__DETAIL__GO_TO_TARGET__BUILDER_HPP_
#define MESSAGES__ACTION__DETAIL__GO_TO_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/action/detail/go_to_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace action
{

namespace builder
{

class Init_GoToTarget_Goal_stable_time_sec
{
public:
  explicit Init_GoToTarget_Goal_stable_time_sec(::messages::action::GoToTarget_Goal & msg)
  : msg_(msg)
  {}
  ::messages::action::GoToTarget_Goal stable_time_sec(::messages::action::GoToTarget_Goal::_stable_time_sec_type arg)
  {
    msg_.stable_time_sec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::GoToTarget_Goal msg_;
};

class Init_GoToTarget_Goal_timeout_sec
{
public:
  explicit Init_GoToTarget_Goal_timeout_sec(::messages::action::GoToTarget_Goal & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Goal_stable_time_sec timeout_sec(::messages::action::GoToTarget_Goal::_timeout_sec_type arg)
  {
    msg_.timeout_sec = std::move(arg);
    return Init_GoToTarget_Goal_stable_time_sec(msg_);
  }

private:
  ::messages::action::GoToTarget_Goal msg_;
};

class Init_GoToTarget_Goal_yaw
{
public:
  explicit Init_GoToTarget_Goal_yaw(::messages::action::GoToTarget_Goal & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Goal_timeout_sec yaw(::messages::action::GoToTarget_Goal::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_GoToTarget_Goal_timeout_sec(msg_);
  }

private:
  ::messages::action::GoToTarget_Goal msg_;
};

class Init_GoToTarget_Goal_z
{
public:
  explicit Init_GoToTarget_Goal_z(::messages::action::GoToTarget_Goal & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Goal_yaw z(::messages::action::GoToTarget_Goal::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_GoToTarget_Goal_yaw(msg_);
  }

private:
  ::messages::action::GoToTarget_Goal msg_;
};

class Init_GoToTarget_Goal_y
{
public:
  explicit Init_GoToTarget_Goal_y(::messages::action::GoToTarget_Goal & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Goal_z y(::messages::action::GoToTarget_Goal::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_GoToTarget_Goal_z(msg_);
  }

private:
  ::messages::action::GoToTarget_Goal msg_;
};

class Init_GoToTarget_Goal_x
{
public:
  explicit Init_GoToTarget_Goal_x(::messages::action::GoToTarget_Goal & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Goal_y x(::messages::action::GoToTarget_Goal::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_GoToTarget_Goal_y(msg_);
  }

private:
  ::messages::action::GoToTarget_Goal msg_;
};

class Init_GoToTarget_Goal_priority
{
public:
  explicit Init_GoToTarget_Goal_priority(::messages::action::GoToTarget_Goal & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Goal_x priority(::messages::action::GoToTarget_Goal::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return Init_GoToTarget_Goal_x(msg_);
  }

private:
  ::messages::action::GoToTarget_Goal msg_;
};

class Init_GoToTarget_Goal_task_id
{
public:
  Init_GoToTarget_Goal_task_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToTarget_Goal_priority task_id(::messages::action::GoToTarget_Goal::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_GoToTarget_Goal_priority(msg_);
  }

private:
  ::messages::action::GoToTarget_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::GoToTarget_Goal>()
{
  return messages::action::builder::Init_GoToTarget_Goal_task_id();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_GoToTarget_Result_elapsed_sec
{
public:
  explicit Init_GoToTarget_Result_elapsed_sec(::messages::action::GoToTarget_Result & msg)
  : msg_(msg)
  {}
  ::messages::action::GoToTarget_Result elapsed_sec(::messages::action::GoToTarget_Result::_elapsed_sec_type arg)
  {
    msg_.elapsed_sec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::GoToTarget_Result msg_;
};

class Init_GoToTarget_Result_message
{
public:
  explicit Init_GoToTarget_Result_message(::messages::action::GoToTarget_Result & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Result_elapsed_sec message(::messages::action::GoToTarget_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GoToTarget_Result_elapsed_sec(msg_);
  }

private:
  ::messages::action::GoToTarget_Result msg_;
};

class Init_GoToTarget_Result_error_code
{
public:
  explicit Init_GoToTarget_Result_error_code(::messages::action::GoToTarget_Result & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Result_message error_code(::messages::action::GoToTarget_Result::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_GoToTarget_Result_message(msg_);
  }

private:
  ::messages::action::GoToTarget_Result msg_;
};

class Init_GoToTarget_Result_final_state_code
{
public:
  explicit Init_GoToTarget_Result_final_state_code(::messages::action::GoToTarget_Result & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Result_error_code final_state_code(::messages::action::GoToTarget_Result::_final_state_code_type arg)
  {
    msg_.final_state_code = std::move(arg);
    return Init_GoToTarget_Result_error_code(msg_);
  }

private:
  ::messages::action::GoToTarget_Result msg_;
};

class Init_GoToTarget_Result_success
{
public:
  Init_GoToTarget_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToTarget_Result_final_state_code success(::messages::action::GoToTarget_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GoToTarget_Result_final_state_code(msg_);
  }

private:
  ::messages::action::GoToTarget_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::GoToTarget_Result>()
{
  return messages::action::builder::Init_GoToTarget_Result_success();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_GoToTarget_Feedback_current_twist
{
public:
  explicit Init_GoToTarget_Feedback_current_twist(::messages::action::GoToTarget_Feedback & msg)
  : msg_(msg)
  {}
  ::messages::action::GoToTarget_Feedback current_twist(::messages::action::GoToTarget_Feedback::_current_twist_type arg)
  {
    msg_.current_twist = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

class Init_GoToTarget_Feedback_current_pose
{
public:
  explicit Init_GoToTarget_Feedback_current_pose(::messages::action::GoToTarget_Feedback & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Feedback_current_twist current_pose(::messages::action::GoToTarget_Feedback::_current_pose_type arg)
  {
    msg_.current_pose = std::move(arg);
    return Init_GoToTarget_Feedback_current_twist(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

class Init_GoToTarget_Feedback_yaw_error
{
public:
  explicit Init_GoToTarget_Feedback_yaw_error(::messages::action::GoToTarget_Feedback & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Feedback_current_pose yaw_error(::messages::action::GoToTarget_Feedback::_yaw_error_type arg)
  {
    msg_.yaw_error = std::move(arg);
    return Init_GoToTarget_Feedback_current_pose(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

class Init_GoToTarget_Feedback_distance_error
{
public:
  explicit Init_GoToTarget_Feedback_distance_error(::messages::action::GoToTarget_Feedback & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Feedback_yaw_error distance_error(::messages::action::GoToTarget_Feedback::_distance_error_type arg)
  {
    msg_.distance_error = std::move(arg);
    return Init_GoToTarget_Feedback_yaw_error(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

class Init_GoToTarget_Feedback_progress
{
public:
  explicit Init_GoToTarget_Feedback_progress(::messages::action::GoToTarget_Feedback & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Feedback_distance_error progress(::messages::action::GoToTarget_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return Init_GoToTarget_Feedback_distance_error(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

class Init_GoToTarget_Feedback_message
{
public:
  explicit Init_GoToTarget_Feedback_message(::messages::action::GoToTarget_Feedback & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Feedback_progress message(::messages::action::GoToTarget_Feedback::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GoToTarget_Feedback_progress(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

class Init_GoToTarget_Feedback_error_code
{
public:
  explicit Init_GoToTarget_Feedback_error_code(::messages::action::GoToTarget_Feedback & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Feedback_message error_code(::messages::action::GoToTarget_Feedback::_error_code_type arg)
  {
    msg_.error_code = std::move(arg);
    return Init_GoToTarget_Feedback_message(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

class Init_GoToTarget_Feedback_state_code
{
public:
  explicit Init_GoToTarget_Feedback_state_code(::messages::action::GoToTarget_Feedback & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Feedback_error_code state_code(::messages::action::GoToTarget_Feedback::_state_code_type arg)
  {
    msg_.state_code = std::move(arg);
    return Init_GoToTarget_Feedback_error_code(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

class Init_GoToTarget_Feedback_stamp
{
public:
  explicit Init_GoToTarget_Feedback_stamp(::messages::action::GoToTarget_Feedback & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Feedback_state_code stamp(::messages::action::GoToTarget_Feedback::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_GoToTarget_Feedback_state_code(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

class Init_GoToTarget_Feedback_priority
{
public:
  explicit Init_GoToTarget_Feedback_priority(::messages::action::GoToTarget_Feedback & msg)
  : msg_(msg)
  {}
  Init_GoToTarget_Feedback_stamp priority(::messages::action::GoToTarget_Feedback::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return Init_GoToTarget_Feedback_stamp(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

class Init_GoToTarget_Feedback_task_id
{
public:
  Init_GoToTarget_Feedback_task_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToTarget_Feedback_priority task_id(::messages::action::GoToTarget_Feedback::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_GoToTarget_Feedback_priority(msg_);
  }

private:
  ::messages::action::GoToTarget_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::GoToTarget_Feedback>()
{
  return messages::action::builder::Init_GoToTarget_Feedback_task_id();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_GoToTarget_SendGoal_Request_goal
{
public:
  explicit Init_GoToTarget_SendGoal_Request_goal(::messages::action::GoToTarget_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::messages::action::GoToTarget_SendGoal_Request goal(::messages::action::GoToTarget_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::GoToTarget_SendGoal_Request msg_;
};

class Init_GoToTarget_SendGoal_Request_goal_id
{
public:
  Init_GoToTarget_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToTarget_SendGoal_Request_goal goal_id(::messages::action::GoToTarget_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_GoToTarget_SendGoal_Request_goal(msg_);
  }

private:
  ::messages::action::GoToTarget_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::GoToTarget_SendGoal_Request>()
{
  return messages::action::builder::Init_GoToTarget_SendGoal_Request_goal_id();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_GoToTarget_SendGoal_Response_stamp
{
public:
  explicit Init_GoToTarget_SendGoal_Response_stamp(::messages::action::GoToTarget_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::messages::action::GoToTarget_SendGoal_Response stamp(::messages::action::GoToTarget_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::GoToTarget_SendGoal_Response msg_;
};

class Init_GoToTarget_SendGoal_Response_accepted
{
public:
  Init_GoToTarget_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToTarget_SendGoal_Response_stamp accepted(::messages::action::GoToTarget_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_GoToTarget_SendGoal_Response_stamp(msg_);
  }

private:
  ::messages::action::GoToTarget_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::GoToTarget_SendGoal_Response>()
{
  return messages::action::builder::Init_GoToTarget_SendGoal_Response_accepted();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_GoToTarget_GetResult_Request_goal_id
{
public:
  Init_GoToTarget_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::messages::action::GoToTarget_GetResult_Request goal_id(::messages::action::GoToTarget_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::GoToTarget_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::GoToTarget_GetResult_Request>()
{
  return messages::action::builder::Init_GoToTarget_GetResult_Request_goal_id();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_GoToTarget_GetResult_Response_result
{
public:
  explicit Init_GoToTarget_GetResult_Response_result(::messages::action::GoToTarget_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::messages::action::GoToTarget_GetResult_Response result(::messages::action::GoToTarget_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::GoToTarget_GetResult_Response msg_;
};

class Init_GoToTarget_GetResult_Response_status
{
public:
  Init_GoToTarget_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToTarget_GetResult_Response_result status(::messages::action::GoToTarget_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GoToTarget_GetResult_Response_result(msg_);
  }

private:
  ::messages::action::GoToTarget_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::GoToTarget_GetResult_Response>()
{
  return messages::action::builder::Init_GoToTarget_GetResult_Response_status();
}

}  // namespace messages


namespace messages
{

namespace action
{

namespace builder
{

class Init_GoToTarget_FeedbackMessage_feedback
{
public:
  explicit Init_GoToTarget_FeedbackMessage_feedback(::messages::action::GoToTarget_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::messages::action::GoToTarget_FeedbackMessage feedback(::messages::action::GoToTarget_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::action::GoToTarget_FeedbackMessage msg_;
};

class Init_GoToTarget_FeedbackMessage_goal_id
{
public:
  Init_GoToTarget_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoToTarget_FeedbackMessage_feedback goal_id(::messages::action::GoToTarget_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_GoToTarget_FeedbackMessage_feedback(msg_);
  }

private:
  ::messages::action::GoToTarget_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::action::GoToTarget_FeedbackMessage>()
{
  return messages::action::builder::Init_GoToTarget_FeedbackMessage_goal_id();
}

}  // namespace messages

#endif  // MESSAGES__ACTION__DETAIL__GO_TO_TARGET__BUILDER_HPP_
