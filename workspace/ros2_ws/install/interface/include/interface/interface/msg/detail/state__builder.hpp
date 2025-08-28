// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:msg/State.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__STATE__BUILDER_HPP_
#define INTERFACE__MSG__DETAIL__STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interface/msg/detail/state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interface
{

namespace msg
{

namespace builder
{

class Init_State_c
{
public:
  explicit Init_State_c(::interface::msg::State & msg)
  : msg_(msg)
  {}
  ::interface::msg::State c(::interface::msg::State::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_t
{
public:
  explicit Init_State_t(::interface::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_c t(::interface::msg::State::_t_type arg)
  {
    msg_.t = std::move(arg);
    return Init_State_c(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_z
{
public:
  explicit Init_State_z(::interface::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_t z(::interface::msg::State::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_State_t(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_y
{
public:
  explicit Init_State_y(::interface::msg::State & msg)
  : msg_(msg)
  {}
  Init_State_z y(::interface::msg::State::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_State_z(msg_);
  }

private:
  ::interface::msg::State msg_;
};

class Init_State_x
{
public:
  Init_State_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_State_y x(::interface::msg::State::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_State_y(msg_);
  }

private:
  ::interface::msg::State msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::msg::State>()
{
  return interface::msg::builder::Init_State_x();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__STATE__BUILDER_HPP_
