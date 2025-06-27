// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:msg/FakeData.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__FAKE_DATA__STRUCT_H_
#define INTERFACE__MSG__DETAIL__FAKE_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FakeData in the package interface.
typedef struct interface__msg__FakeData
{
  double x;
  double y;
  double z;
  double t;
} interface__msg__FakeData;

// Struct for a sequence of interface__msg__FakeData.
typedef struct interface__msg__FakeData__Sequence
{
  interface__msg__FakeData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__msg__FakeData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__MSG__DETAIL__FAKE_DATA__STRUCT_H_
