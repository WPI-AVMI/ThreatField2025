// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:msg/Sensor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__SENSOR__STRUCT_H_
#define INTERFACE__MSG__DETAIL__SENSOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Sensor in the package interface.
typedef struct interface__msg__Sensor
{
  double dx;
  double dy;
  double dz;
  double dt;
} interface__msg__Sensor;

// Struct for a sequence of interface__msg__Sensor.
typedef struct interface__msg__Sensor__Sequence
{
  interface__msg__Sensor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__msg__Sensor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__MSG__DETAIL__SENSOR__STRUCT_H_
