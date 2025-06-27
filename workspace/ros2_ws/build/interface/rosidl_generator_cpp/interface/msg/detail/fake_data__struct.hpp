// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:msg/FakeData.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__FAKE_DATA__STRUCT_HPP_
#define INTERFACE__MSG__DETAIL__FAKE_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interface__msg__FakeData __attribute__((deprecated))
#else
# define DEPRECATED__interface__msg__FakeData __declspec(deprecated)
#endif

namespace interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FakeData_
{
  using Type = FakeData_<ContainerAllocator>;

  explicit FakeData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->t = 0.0;
    }
  }

  explicit FakeData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->z = 0.0;
      this->t = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _z_type =
    double;
  _z_type z;
  using _t_type =
    double;
  _t_type t;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const double & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__t(
    const double & _arg)
  {
    this->t = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::msg::FakeData_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::msg::FakeData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::msg::FakeData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::msg::FakeData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::msg::FakeData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::msg::FakeData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::msg::FakeData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::msg::FakeData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::msg::FakeData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::msg::FakeData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__msg__FakeData
    std::shared_ptr<interface::msg::FakeData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__msg__FakeData
    std::shared_ptr<interface::msg::FakeData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FakeData_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->t != other.t) {
      return false;
    }
    return true;
  }
  bool operator!=(const FakeData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FakeData_

// alias to use template instance with default allocator
using FakeData =
  interface::msg::FakeData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__FAKE_DATA__STRUCT_HPP_
