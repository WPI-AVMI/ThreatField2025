// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:srv/Concentration.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CONCENTRATION__STRUCT_HPP_
#define INTERFACE__SRV__DETAIL__CONCENTRATION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interface__srv__Concentration_Request __attribute__((deprecated))
#else
# define DEPRECATED__interface__srv__Concentration_Request __declspec(deprecated)
#endif

namespace interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Concentration_Request_
{
  using Type = Concentration_Request_<ContainerAllocator>;

  explicit Concentration_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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

  explicit Concentration_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    interface::srv::Concentration_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::srv::Concentration_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::srv::Concentration_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::srv::Concentration_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::srv::Concentration_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::srv::Concentration_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::srv::Concentration_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::srv::Concentration_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::srv::Concentration_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::srv::Concentration_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__srv__Concentration_Request
    std::shared_ptr<interface::srv::Concentration_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__srv__Concentration_Request
    std::shared_ptr<interface::srv::Concentration_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Concentration_Request_ & other) const
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
  bool operator!=(const Concentration_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Concentration_Request_

// alias to use template instance with default allocator
using Concentration_Request =
  interface::srv::Concentration_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interface


#ifndef _WIN32
# define DEPRECATED__interface__srv__Concentration_Response __attribute__((deprecated))
#else
# define DEPRECATED__interface__srv__Concentration_Response __declspec(deprecated)
#endif

namespace interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Concentration_Response_
{
  using Type = Concentration_Response_<ContainerAllocator>;

  explicit Concentration_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->c = 0.0;
    }
  }

  explicit Concentration_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->c = 0.0;
    }
  }

  // field types and members
  using _c_type =
    double;
  _c_type c;

  // setters for named parameter idiom
  Type & set__c(
    const double & _arg)
  {
    this->c = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::srv::Concentration_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::srv::Concentration_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::srv::Concentration_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::srv::Concentration_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::srv::Concentration_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::srv::Concentration_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::srv::Concentration_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::srv::Concentration_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::srv::Concentration_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::srv::Concentration_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__srv__Concentration_Response
    std::shared_ptr<interface::srv::Concentration_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__srv__Concentration_Response
    std::shared_ptr<interface::srv::Concentration_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Concentration_Response_ & other) const
  {
    if (this->c != other.c) {
      return false;
    }
    return true;
  }
  bool operator!=(const Concentration_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Concentration_Response_

// alias to use template instance with default allocator
using Concentration_Response =
  interface::srv::Concentration_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interface

namespace interface
{

namespace srv
{

struct Concentration
{
  using Request = interface::srv::Concentration_Request;
  using Response = interface::srv::Concentration_Response;
};

}  // namespace srv

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__CONCENTRATION__STRUCT_HPP_
