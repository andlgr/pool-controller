/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 18, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_DEVICE_TEMPERATURE_SENSOR_TEMPERATURE_SENSOR_DEVICE_INTERFACE_H
#define INCLUDE_DEVICE_TEMPERATURE_SENSOR_TEMPERATURE_SENSOR_DEVICE_INTERFACE_H

#include "device/temperature_sensor/temperature_sensor_types.h"
#include "common/error/error.h"
#include "common/init/init_interface.h"

class TemperatureSensorDeviceInterface : public virtual InitInterface {
 public:
  virtual ~TemperatureSensorDeviceInterface() {}
  virtual error_t GetTemperature(float *temp) = 0;
  virtual const temperature_sensor_id_t& id() = 0;
};

#endif  // INCLUDE_DEVICE_TEMPERATURE_SENSOR_TEMPERATURE_SENSOR_DEVICE_INTERFACE_H
