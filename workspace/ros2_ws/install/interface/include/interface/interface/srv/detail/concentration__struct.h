// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:srv/Concentration.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CONCENTRATION__STRUCT_H_
#define INTERFACE__SRV__DETAIL__CONCENTRATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Concentration in the package interface.
typedef struct interface__srv__Concentration_Request
{
  double x;
  double y;
  double z;
  double t;
} interface__srv__Concentration_Request;

// Struct for a sequence of interface__srv__Concentration_Request.
typedef struct interface__srv__Concentration_Request__Sequence
{
  interface__srv__Concentration_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__srv__Concentration_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Concentration in the package interface.
typedef struct interface__srv__Concentration_Response
{
  double c;
} interface__srv__Concentration_Response;

// Struct for a sequence of interface__srv__Concentration_Response.
typedef struct interface__srv__Concentration_Response__Sequence
{
  interface__srv__Concentration_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__srv__Concentration_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__SRV__DETAIL__CONCENTRATION__STRUCT_H_
