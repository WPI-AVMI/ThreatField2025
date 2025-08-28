// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interface:msg/Sensor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__SENSOR__BUILDER_HPP_
#define INTERFACE__MSG__DETAIL__SENSOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interface/msg/detail/sensor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interface
{

namespace msg
{

namespace builder
{

class Init_Sensor_dt
{
public:
  explicit Init_Sensor_dt(::interface::msg::Sensor & msg)
  : msg_(msg)
  {}
  ::interface::msg::Sensor dt(::interface::msg::Sensor::_dt_type arg)
  {
    msg_.dt = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interface::msg::Sensor msg_;
};

class Init_Sensor_dz
{
public:
  explicit Init_Sensor_dz(::interface::msg::Sensor & msg)
  : msg_(msg)
  {}
  Init_Sensor_dt dz(::interface::msg::Sensor::_dz_type arg)
  {
    msg_.dz = std::move(arg);
    return Init_Sensor_dt(msg_);
  }

private:
  ::interface::msg::Sensor msg_;
};

class Init_Sensor_dy
{
public:
  explicit Init_Sensor_dy(::interface::msg::Sensor & msg)
  : msg_(msg)
  {}
  Init_Sensor_dz dy(::interface::msg::Sensor::_dy_type arg)
  {
    msg_.dy = std::move(arg);
    return Init_Sensor_dz(msg_);
  }

private:
  ::interface::msg::Sensor msg_;
};

class Init_Sensor_dx
{
public:
  Init_Sensor_dx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Sensor_dy dx(::interface::msg::Sensor::_dx_type arg)
  {
    msg_.dx = std::move(arg);
    return Init_Sensor_dy(msg_);
  }

private:
  ::interface::msg::Sensor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interface::msg::Sensor>()
{
  return interface::msg::builder::Init_Sensor_dx();
}

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__SENSOR__BUILDER_HPP_
