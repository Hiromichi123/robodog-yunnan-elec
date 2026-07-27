// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from messages:srv/SmartCarCommand.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__BUILDER_HPP_
#define MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "messages/srv/detail/smart_car_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace messages
{

namespace srv
{

namespace builder
{

class Init_SmartCarCommand_Request_param4
{
public:
  explicit Init_SmartCarCommand_Request_param4(::messages::srv::SmartCarCommand_Request & msg)
  : msg_(msg)
  {}
  ::messages::srv::SmartCarCommand_Request param4(::messages::srv::SmartCarCommand_Request::_param4_type arg)
  {
    msg_.param4 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::srv::SmartCarCommand_Request msg_;
};

class Init_SmartCarCommand_Request_param3
{
public:
  explicit Init_SmartCarCommand_Request_param3(::messages::srv::SmartCarCommand_Request & msg)
  : msg_(msg)
  {}
  Init_SmartCarCommand_Request_param4 param3(::messages::srv::SmartCarCommand_Request::_param3_type arg)
  {
    msg_.param3 = std::move(arg);
    return Init_SmartCarCommand_Request_param4(msg_);
  }

private:
  ::messages::srv::SmartCarCommand_Request msg_;
};

class Init_SmartCarCommand_Request_param2
{
public:
  explicit Init_SmartCarCommand_Request_param2(::messages::srv::SmartCarCommand_Request & msg)
  : msg_(msg)
  {}
  Init_SmartCarCommand_Request_param3 param2(::messages::srv::SmartCarCommand_Request::_param2_type arg)
  {
    msg_.param2 = std::move(arg);
    return Init_SmartCarCommand_Request_param3(msg_);
  }

private:
  ::messages::srv::SmartCarCommand_Request msg_;
};

class Init_SmartCarCommand_Request_param1
{
public:
  explicit Init_SmartCarCommand_Request_param1(::messages::srv::SmartCarCommand_Request & msg)
  : msg_(msg)
  {}
  Init_SmartCarCommand_Request_param2 param1(::messages::srv::SmartCarCommand_Request::_param1_type arg)
  {
    msg_.param1 = std::move(arg);
    return Init_SmartCarCommand_Request_param2(msg_);
  }

private:
  ::messages::srv::SmartCarCommand_Request msg_;
};

class Init_SmartCarCommand_Request_command
{
public:
  Init_SmartCarCommand_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartCarCommand_Request_param1 command(::messages::srv::SmartCarCommand_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_SmartCarCommand_Request_param1(msg_);
  }

private:
  ::messages::srv::SmartCarCommand_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::srv::SmartCarCommand_Request>()
{
  return messages::srv::builder::Init_SmartCarCommand_Request_command();
}

}  // namespace messages


namespace messages
{

namespace srv
{

namespace builder
{

class Init_SmartCarCommand_Response_message
{
public:
  explicit Init_SmartCarCommand_Response_message(::messages::srv::SmartCarCommand_Response & msg)
  : msg_(msg)
  {}
  ::messages::srv::SmartCarCommand_Response message(::messages::srv::SmartCarCommand_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::messages::srv::SmartCarCommand_Response msg_;
};

class Init_SmartCarCommand_Response_accepted
{
public:
  Init_SmartCarCommand_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SmartCarCommand_Response_message accepted(::messages::srv::SmartCarCommand_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_SmartCarCommand_Response_message(msg_);
  }

private:
  ::messages::srv::SmartCarCommand_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::messages::srv::SmartCarCommand_Response>()
{
  return messages::srv::builder::Init_SmartCarCommand_Response_accepted();
}

}  // namespace messages

#endif  // MESSAGES__SRV__DETAIL__SMART_CAR_COMMAND__BUILDER_HPP_
