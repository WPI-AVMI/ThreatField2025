// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:msg/Sensor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__SENSOR__STRUCT_HPP_
#define INTERFACE__MSG__DETAIL__SENSOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interface__msg__Sensor __attribute__((deprecated))
#else
# define DEPRECATED__interface__msg__Sensor __declspec(deprecated)
#endif

namespace interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Sensor_
{
  using Type = Sensor_<ContainerAllocator>;

  explicit Sensor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dx = 0.0;
      this->dy = 0.0;
      this->dz = 0.0;
      this->dt = 0.0;
    }
  }

  explicit Sensor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dx = 0.0;
      this->dy = 0.0;
      this->dz = 0.0;
      this->dt = 0.0;
    }
  }

  // field types and members
  using _dx_type =
    double;
  _dx_type dx;
  using _dy_type =
    double;
  _dy_type dy;
  using _dz_type =
    double;
  _dz_type dz;
  using _dt_type =
    double;
  _dt_type dt;

  // setters for named parameter idiom
  Type & set__dx(
    const double & _arg)
  {
    this->dx = _arg;
    return *this;
  }
  Type & set__dy(
    const double & _arg)
  {
    this->dy = _arg;
    return *this;
  }
  Type & set__dz(
    const double & _arg)
  {
    this->dz = _arg;
    return *this;
  }
  Type & set__dt(
    const double & _arg)
  {
    this->dt = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::msg::Sensor_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::msg::Sensor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::msg::Sensor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::msg::Sensor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::msg::Sensor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::msg::Sensor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::msg::Sensor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::msg::Sensor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::msg::Sensor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::msg::Sensor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__msg__Sensor
    std::shared_ptr<interface::msg::Sensor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__msg__Sensor
    std::shared_ptr<interface::msg::Sensor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Sensor_ & other) const
  {
    if (this->dx != other.dx) {
      return false;
    }
    if (this->dy != other.dy) {
      return false;
    }
    if (this->dz != other.dz) {
      return false;
    }
    if (this->dt != other.dt) {
      return false;
    }
    return true;
  }
  bool operator!=(const Sensor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Sensor_

// alias to use template instance with default allocator
using Sensor =
  interface::msg::Sensor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interface

#endif  // INTERFACE__MSG__DETAIL__SENSOR__STRUCT_HPP_
