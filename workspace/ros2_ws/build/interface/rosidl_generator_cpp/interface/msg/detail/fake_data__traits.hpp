// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:msg/FakeData.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__FAKE_DATA__TRAITS_HPP_
#define INTERFACE__MSG__DETAIL__FAKE_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interface/msg/detail/fake_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const FakeData & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: t
  {
    out << "t: ";
    rosidl_generator_traits::value_to_yaml(msg.t, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FakeData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: t
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "t: ";
    rosidl_generator_traits::value_to_yaml(msg.t, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FakeData & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace interface

namespace rosidl_generator_traits
{

[[deprecated("use interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interface::msg::FakeData & msg,
  std::ostream & out, size_t indentation = 0)
{
  interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const interface::msg::FakeData & msg)
{
  return interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interface::msg::FakeData>()
{
  return "interface::msg::FakeData";
}

template<>
inline const char * name<interface::msg::FakeData>()
{
  return "interface/msg/FakeData";
}

template<>
struct has_fixed_size<interface::msg::FakeData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interface::msg::FakeData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interface::msg::FakeData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__MSG__DETAIL__FAKE_DATA__TRAITS_HPP_
