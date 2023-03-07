// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/IotDeviceRequest.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__IOT_DEVICE_REQUEST__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__IOT_DEVICE_REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/iot_device_request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_IotDeviceRequest_iot_id
{
public:
  Init_IotDeviceRequest_iot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::msg::IotDeviceRequest iot_id(::custom_interfaces::msg::IotDeviceRequest::_iot_id_type arg)
  {
    msg_.iot_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::IotDeviceRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::IotDeviceRequest>()
{
  return custom_interfaces::msg::builder::Init_IotDeviceRequest_iot_id();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__IOT_DEVICE_REQUEST__BUILDER_HPP_
