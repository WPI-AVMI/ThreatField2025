// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from interface:msg/FakeData.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__FAKE_DATA__FUNCTIONS_H_
#define INTERFACE__MSG__DETAIL__FAKE_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "interface/msg/rosidl_generator_c__visibility_control.h"

#include "interface/msg/detail/fake_data__struct.h"

/// Initialize msg/FakeData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * interface__msg__FakeData
 * )) before or use
 * interface__msg__FakeData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__FakeData__init(interface__msg__FakeData * msg);

/// Finalize msg/FakeData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
void
interface__msg__FakeData__fini(interface__msg__FakeData * msg);

/// Create msg/FakeData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * interface__msg__FakeData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
interface__msg__FakeData *
interface__msg__FakeData__create();

/// Destroy msg/FakeData message.
/**
 * It calls
 * interface__msg__FakeData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
void
interface__msg__FakeData__destroy(interface__msg__FakeData * msg);

/// Check for msg/FakeData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__FakeData__are_equal(const interface__msg__FakeData * lhs, const interface__msg__FakeData * rhs);

/// Copy a msg/FakeData message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__FakeData__copy(
  const interface__msg__FakeData * input,
  interface__msg__FakeData * output);

/// Initialize array of msg/FakeData messages.
/**
 * It allocates the memory for the number of elements and calls
 * interface__msg__FakeData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__FakeData__Sequence__init(interface__msg__FakeData__Sequence * array, size_t size);

/// Finalize array of msg/FakeData messages.
/**
 * It calls
 * interface__msg__FakeData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
void
interface__msg__FakeData__Sequence__fini(interface__msg__FakeData__Sequence * array);

/// Create array of msg/FakeData messages.
/**
 * It allocates the memory for the array and calls
 * interface__msg__FakeData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
interface__msg__FakeData__Sequence *
interface__msg__FakeData__Sequence__create(size_t size);

/// Destroy array of msg/FakeData messages.
/**
 * It calls
 * interface__msg__FakeData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
void
interface__msg__FakeData__Sequence__destroy(interface__msg__FakeData__Sequence * array);

/// Check for msg/FakeData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__FakeData__Sequence__are_equal(const interface__msg__FakeData__Sequence * lhs, const interface__msg__FakeData__Sequence * rhs);

/// Copy an array of msg/FakeData messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_interface
bool
interface__msg__FakeData__Sequence__copy(
  const interface__msg__FakeData__Sequence * input,
  interface__msg__FakeData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__MSG__DETAIL__FAKE_DATA__FUNCTIONS_H_
