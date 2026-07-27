// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:msg/Vision.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__DETAIL__VISION__BUILDER_HPP_
#define MESSAGES__MSG__DETAIL__VISION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/msg/detail/vision__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace msg
{

namespace builder
{

class Init_Vision_label
{
public:
  explicit Init_Vision_label(::messages::msg::Vision & msg)
  : msg_(msg)
  {}
  ::messages::msg::Vision label(::messages::msg::Vision::_label_type arg)
  {
    msg_.label = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::msg::Vision msg_;
};

class Init_Vision_center_x1_error
{
public:
  explicit Init_Vision_center_x1_error(::messages::msg::Vision & msg)
  : msg_(msg)
  {}
  Init_Vision_label center_x1_error(::messages::msg::Vision::_center_x1_error_type arg)
  {
    msg_.center_x1_error = std::move(arg);
    return Init_Vision_label(msg_);
  }

private:
  ::messages::msg::Vision msg_;
};

class Init_Vision_center_y
{
public:
  explicit Init_Vision_center_y(::messages::msg::Vision & msg)
  : msg_(msg)
  {}
  Init_Vision_center_x1_error center_y(::messages::msg::Vision::_center_y_type arg)
  {
    msg_.center_y = std::move(arg);
    return Init_Vision_center_x1_error(msg_);
  }

private:
  ::messages::msg::Vision msg_;
};

class Init_Vision_center_x
{
public:
  explicit Init_Vision_center_x(::messages::msg::Vision & msg)
  : msg_(msg)
  {}
  Init_Vision_center_y center_x(::messages::msg::Vision::_center_x_type arg)
  {
    msg_.center_x = std::move(arg);
    return Init_Vision_center_y(msg_);
  }

private:
  ::messages::msg::Vision msg_;
};

class Init_Vision_is_detected
{
public:
  Init_Vision_is_detected()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Vision_center_x is_detected(::messages::msg::Vision::_is_detected_type arg)
  {
    msg_.is_detected = std::move(arg);
    return Init_Vision_center_x(msg_);
  }

private:
  ::messages::msg::Vision msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::msg::Vision>()
{
  return messages::msg::builder::Init_Vision_is_detected();
}

}  // namespace messages

#endif  // MESSAGES__MSG__DETAIL__VISION__BUILDER_HPP_
