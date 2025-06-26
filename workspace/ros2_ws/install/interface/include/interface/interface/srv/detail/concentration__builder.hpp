// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:srv/Concentration.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CONCENTRATION__BUILDER_HPP_
#define INTERFACE__SRV__DETAIL__CONCENTRATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interface/srv/detail/concentration__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interface
{

namespace srv
{

namespace builder
{

class Init_Concentration_Request_t
{
public:
  explicit Init_Concentration_Request_t(::interface::srv::Concentration_Request & msg)
  : msg_(msg)
  {}
  ::interface::srv::Concentration_Request t(::interface::srv::Concentration_Request::_t_type arg)
  {
    msg_.t = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::Concentration_Request msg_;
};

class Init_Concentration_Request_z
{
public:
  explicit Init_Concentration_Request_z(::interface::srv::Concentration_Request & msg)
  : msg_(msg)
  {}
  Init_Concentration_Request_t z(::interface::srv::Concentration_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_Concentration_Request_t(msg_);
  }

private:
  ::interface::srv::Concentration_Request msg_;
};

class Init_Concentration_Request_y
{
public:
  explicit Init_Concentration_Request_y(::interface::srv::Concentration_Request & msg)
  : msg_(msg)
  {}
  Init_Concentration_Request_z y(::interface::srv::Concentration_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Concentration_Request_z(msg_);
  }

private:
  ::interface::srv::Concentration_Request msg_;
};

class Init_Concentration_Request_x
{
public:
  Init_Concentration_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Concentration_Request_y x(::interface::srv::Concentration_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Concentration_Request_y(msg_);
  }

private:
  ::interface::srv::Concentration_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::Concentration_Request>()
{
  return interface::srv::builder::Init_Concentration_Request_x();
}

}  // namespace interface


namespace interface
{

namespace srv
{

namespace builder
{

class Init_Concentration_Response_c
{
public:
  Init_Concentration_Response_c()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interface::srv::Concentration_Response c(::interface::srv::Concentration_Response::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::srv::Concentration_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::srv::Concentration_Response>()
{
  return interface::srv::builder::Init_Concentration_Response_c();
}

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__CONCENTRATION__BUILDER_HPP_
