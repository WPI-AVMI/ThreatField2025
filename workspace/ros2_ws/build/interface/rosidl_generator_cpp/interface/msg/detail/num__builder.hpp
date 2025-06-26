// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_
#define INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interface/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interface
{

namespace msg
{

namespace builder
{

class Init_Num_num
{
public:
  Init_Num_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interface::msg::Num num(::interface::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::msg::Num>()
{
  return interface::msg::builder::Init_Num_num();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_
