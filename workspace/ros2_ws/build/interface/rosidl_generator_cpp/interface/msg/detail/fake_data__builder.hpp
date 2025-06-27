// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:msg/FakeData.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__FAKE_DATA__BUILDER_HPP_
#define INTERFACE__MSG__DETAIL__FAKE_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interface/msg/detail/fake_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interface
{

namespace msg
{

namespace builder
{

class Init_FakeData_t
{
public:
  explicit Init_FakeData_t(::interface::msg::FakeData & msg)
  : msg_(msg)
  {}
  ::interface::msg::FakeData t(::interface::msg::FakeData::_t_type arg)
  {
    msg_.t = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::FakeData msg_;
};

class Init_FakeData_z
{
public:
  explicit Init_FakeData_z(::interface::msg::FakeData & msg)
  : msg_(msg)
  {}
  Init_FakeData_t z(::interface::msg::FakeData::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_FakeData_t(msg_);
  }

private:
  ::interface::msg::FakeData msg_;
};

class Init_FakeData_y
{
public:
  explicit Init_FakeData_y(::interface::msg::FakeData & msg)
  : msg_(msg)
  {}
  Init_FakeData_z y(::interface::msg::FakeData::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_FakeData_z(msg_);
  }

private:
  ::interface::msg::FakeData msg_;
};

class Init_FakeData_x
{
public:
  Init_FakeData_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FakeData_y x(::interface::msg::FakeData::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_FakeData_y(msg_);
  }

private:
  ::interface::msg::FakeData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::msg::FakeData>()
{
  return interface::msg::builder::Init_FakeData_x();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__FAKE_DATA__BUILDER_HPP_
