// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Iotbattery.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__IOTBATTERY__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__IOTBATTERY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/iotbattery__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Iotbattery_iot_id
{
public:
  explicit Init_Iotbattery_iot_id(::custom_interfaces::msg::Iotbattery & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Iotbattery iot_id(::custom_interfaces::msg::Iotbattery::_iot_id_type arg)
  {
    msg_.iot_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Iotbattery msg_;
};

class Init_Iotbattery_battery_level
{
public:
  Init_Iotbattery_battery_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Iotbattery_iot_id battery_level(::custom_interfaces::msg::Iotbattery::_battery_level_type arg)
  {
    msg_.battery_level = std::move(arg);
    return Init_Iotbattery_iot_id(msg_);
  }

private:
  ::custom_interfaces::msg::Iotbattery msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Iotbattery>()
{
  return custom_interfaces::msg::builder::Init_Iotbattery_battery_level();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__IOTBATTERY__BUILDER_HPP_
