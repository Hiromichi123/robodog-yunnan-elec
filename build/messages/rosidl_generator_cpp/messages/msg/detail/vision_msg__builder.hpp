// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/VisionMsg.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__VISION_MSG__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__VISION_MSG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/vision_msg__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_VisionMsg_center_y2_error
{
public:
  explicit Init_VisionMsg_center_y2_error(::messages::msg::VisionMsg & msg)
  : msg_(msg)
  {}
  ::messages::msg::VisionMsg center_y2_error(::messages::msg::VisionMsg::_center_y2_error_type arg)
  {
    msg_.center_y2_error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::VisionMsg msg_;
};

class Init_VisionMsg_center_x2_error
{
public:
  explicit Init_VisionMsg_center_x2_error(::messages::msg::VisionMsg & msg)
  : msg_(msg)
  {}
  Init_VisionMsg_center_y2_error center_x2_error(::messages::msg::VisionMsg::_center_x2_error_type arg)
  {
    msg_.center_x2_error = std::move(arg);
    return Init_VisionMsg_center_y2_error(msg_);
  }

private:
  ::messages::msg::VisionMsg msg_;
};

class Init_VisionMsg_is_circle_detected
{
public:
  explicit Init_VisionMsg_is_circle_detected(::messages::msg::VisionMsg & msg)
  : msg_(msg)
  {}
  Init_VisionMsg_center_x2_error is_circle_detected(::messages::msg::VisionMsg::_is_circle_detected_type arg)
  {
    msg_.is_circle_detected = std::move(arg);
    return Init_VisionMsg_center_x2_error(msg_);
  }

private:
  ::messages::msg::VisionMsg msg_;
};

class Init_VisionMsg_center_y1_error
{
public:
  explicit Init_VisionMsg_center_y1_error(::messages::msg::VisionMsg & msg)
  : msg_(msg)
  {}
  Init_VisionMsg_is_circle_detected center_y1_error(::messages::msg::VisionMsg::_center_y1_error_type arg)
  {
    msg_.center_y1_error = std::move(arg);
    return Init_VisionMsg_is_circle_detected(msg_);
  }

private:
  ::messages::msg::VisionMsg msg_;
};

class Init_VisionMsg_center_x1_error
{
public:
  explicit Init_VisionMsg_center_x1_error(::messages::msg::VisionMsg & msg)
  : msg_(msg)
  {}
  Init_VisionMsg_center_y1_error center_x1_error(::messages::msg::VisionMsg::_center_x1_error_type arg)
  {
    msg_.center_x1_error = std::move(arg);
    return Init_VisionMsg_center_y1_error(msg_);
  }

private:
  ::messages::msg::VisionMsg msg_;
};

class Init_VisionMsg_is_square_detected
{
public:
  explicit Init_VisionMsg_is_square_detected(::messages::msg::VisionMsg & msg)
  : msg_(msg)
  {}
  Init_VisionMsg_center_x1_error is_square_detected(::messages::msg::VisionMsg::_is_square_detected_type arg)
  {
    msg_.is_square_detected = std::move(arg);
    return Init_VisionMsg_center_x1_error(msg_);
  }

private:
  ::messages::msg::VisionMsg msg_;
};

class Init_VisionMsg_angle_error
{
public:
  explicit Init_VisionMsg_angle_error(::messages::msg::VisionMsg & msg)
  : msg_(msg)
  {}
  Init_VisionMsg_is_square_detected angle_error(::messages::msg::VisionMsg::_angle_error_type arg)
  {
    msg_.angle_error = std::move(arg);
    return Init_VisionMsg_is_square_detected(msg_);
  }

private:
  ::messages::msg::VisionMsg msg_;
};

class Init_VisionMsg_lateral_error
{
public:
  explicit Init_VisionMsg_lateral_error(::messages::msg::VisionMsg & msg)
  : msg_(msg)
  {}
  Init_VisionMsg_angle_error lateral_error(::messages::msg::VisionMsg::_lateral_error_type arg)
  {
    msg_.lateral_error = std::move(arg);
    return Init_VisionMsg_angle_error(msg_);
  }

private:
  ::messages::msg::VisionMsg msg_;
};

class Init_VisionMsg_is_line_detected
{
public:
  Init_VisionMsg_is_line_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VisionMsg_lateral_error is_line_detected(::messages::msg::VisionMsg::_is_line_detected_type arg)
  {
    msg_.is_line_detected = std::move(arg);
    return Init_VisionMsg_lateral_error(msg_);
  }

private:
  ::messages::msg::VisionMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::VisionMsg>()
{
  return messages::msg::builder::Init_VisionMsg_is_line_detected();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__VISION_MSG__BUILDER_HPP_
