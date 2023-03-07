// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_interfaces:msg/IotDeviceRequest.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__IOT_DEVICE_REQUEST__TRAITS_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__IOT_DEVICE_REQUEST__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_interfaces/msg/detail/iot_device_request__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const IotDeviceRequest & msg,
  std::ostream & out)
{
  out << "{";
  // member: iot_id
  {
    out << "iot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.iot_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const IotDeviceRequest & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: iot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "iot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.iot_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const IotDeviceRequest & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use custom_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_interfaces::msg::IotDeviceRequest & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_interfaces::msg::IotDeviceRequest & msg)
{
  return custom_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_interfaces::msg::IotDeviceRequest>()
{
  return "custom_interfaces::msg::IotDeviceRequest";
}

template<>
inline const char * name<custom_interfaces::msg::IotDeviceRequest>()
{
  return "custom_interfaces/msg/IotDeviceRequest";
}

template<>
struct has_fixed_size<custom_interfaces::msg::IotDeviceRequest>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_interfaces::msg::IotDeviceRequest>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_interfaces::msg::IotDeviceRequest>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__IOT_DEVICE_REQUEST__TRAITS_HPP_
