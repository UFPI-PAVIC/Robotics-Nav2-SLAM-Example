// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:msg/IotBattery.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__IOT_BATTERY__STRUCT_H_
#define CUSTOM_INTERFACES__MSG__DETAIL__IOT_BATTERY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/IotBattery in the package custom_interfaces.
typedef struct custom_interfaces__msg__IotBattery
{
  int16_t battery_level;
  int16_t iot_id;
} custom_interfaces__msg__IotBattery;

// Struct for a sequence of custom_interfaces__msg__IotBattery.
typedef struct custom_interfaces__msg__IotBattery__Sequence
{
  custom_interfaces__msg__IotBattery * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__msg__IotBattery__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__IOT_BATTERY__STRUCT_H_
