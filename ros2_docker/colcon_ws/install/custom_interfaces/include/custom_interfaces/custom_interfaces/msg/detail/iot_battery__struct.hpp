// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/IotBattery.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__IOT_BATTERY__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__IOT_BATTERY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__IotBattery __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__IotBattery __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IotBattery_
{
  using Type = IotBattery_<ContainerAllocator>;

  explicit IotBattery_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery_level = 0;
      this->iot_id = 0;
    }
  }

  explicit IotBattery_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery_level = 0;
      this->iot_id = 0;
    }
  }

  // field types and members
  using _battery_level_type =
    int16_t;
  _battery_level_type battery_level;
  using _iot_id_type =
    int16_t;
  _iot_id_type iot_id;

  // setters for named parameter idiom
  Type & set__battery_level(
    const int16_t & _arg)
  {
    this->battery_level = _arg;
    return *this;
  }
  Type & set__iot_id(
    const int16_t & _arg)
  {
    this->iot_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::IotBattery_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::IotBattery_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::IotBattery_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::IotBattery_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::IotBattery_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::IotBattery_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::IotBattery_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::IotBattery_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::IotBattery_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::IotBattery_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__IotBattery
    std::shared_ptr<custom_interfaces::msg::IotBattery_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__IotBattery
    std::shared_ptr<custom_interfaces::msg::IotBattery_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IotBattery_ & other) const
  {
    if (this->battery_level != other.battery_level) {
      return false;
    }
    if (this->iot_id != other.iot_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const IotBattery_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IotBattery_

// alias to use template instance with default allocator
using IotBattery =
  custom_interfaces::msg::IotBattery_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__IOT_BATTERY__STRUCT_HPP_
