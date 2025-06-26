// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interface:srv/Concentration.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CONCENTRATION__TRAITS_HPP_
#define INTERFACE__SRV__DETAIL__CONCENTRATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interface/srv/detail/concentration__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Concentration_Request & msg,
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
  const Concentration_Request & msg,
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

inline std::string to_yaml(const Concentration_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interface

namespace rosidl_generator_traits
{

[[deprecated("use interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interface::srv::Concentration_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const interface::srv::Concentration_Request & msg)
{
  return interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interface::srv::Concentration_Request>()
{
  return "interface::srv::Concentration_Request";
}

template<>
inline const char * name<interface::srv::Concentration_Request>()
{
  return "interface/srv/Concentration_Request";
}

template<>
struct has_fixed_size<interface::srv::Concentration_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interface::srv::Concentration_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interface::srv::Concentration_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Concentration_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: c
  {
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Concentration_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Concentration_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interface

namespace rosidl_generator_traits
{

[[deprecated("use interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interface::srv::Concentration_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const interface::srv::Concentration_Response & msg)
{
  return interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interface::srv::Concentration_Response>()
{
  return "interface::srv::Concentration_Response";
}

template<>
inline const char * name<interface::srv::Concentration_Response>()
{
  return "interface/srv/Concentration_Response";
}

template<>
struct has_fixed_size<interface::srv::Concentration_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interface::srv::Concentration_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interface::srv::Concentration_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interface::srv::Concentration>()
{
  return "interface::srv::Concentration";
}

template<>
inline const char * name<interface::srv::Concentration>()
{
  return "interface/srv/Concentration";
}

template<>
struct has_fixed_size<interface::srv::Concentration>
  : std::integral_constant<
    bool,
    has_fixed_size<interface::srv::Concentration_Request>::value &&
    has_fixed_size<interface::srv::Concentration_Response>::value
  >
{
};

template<>
struct has_bounded_size<interface::srv::Concentration>
  : std::integral_constant<
    bool,
    has_bounded_size<interface::srv::Concentration_Request>::value &&
    has_bounded_size<interface::srv::Concentration_Response>::value
  >
{
};

template<>
struct is_service<interface::srv::Concentration>
  : std::true_type
{
};

template<>
struct is_service_request<interface::srv::Concentration_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interface::srv::Concentration_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACE__SRV__DETAIL__CONCENTRATION__TRAITS_HPP_
