/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 7, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_DEVICE_INTERFACE_H
#define INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_DEVICE_INTERFACE_H

#include "device/water_pump/water_pump_types.h"
#include "common/error/error.h"
#include "common/init/init_interface.h"

class WaterPumpDeviceInterface : public virtual InitInterface {
 public:
  virtual ~WaterPumpDeviceInterface() {};
  virtual error_t TurnOn() = 0;
  virtual error_t TurnOff() = 0;
  virtual error_t GetState(bool *is_on) = 0;
  virtual const water_pump_id_t& id() = 0;
};

#endif  // INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_DEVICE_INTERFACE_H
