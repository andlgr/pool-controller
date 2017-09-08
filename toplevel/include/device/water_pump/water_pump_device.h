/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 7, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_DEVICE_H
#define INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_DEVICE_H

#include "device/water_pump/water_pump_device_adapter_interface.h"
#include "device/water_pump/water_pump_device_interface.h"
#include <memory>


class WaterPumpDevice : public WaterPumpDeviceInterface {
 public:
  explicit WaterPumpDevice(water_pump_id_t id, std::shared_ptr<WaterPumpDeviceAdapterInterface> adapter);
  virtual ~WaterPumpDevice();

 public:
  /* Inherited from InitInterface */
  virtual error_t Init();
  virtual error_t Finish();

  /* Inherited from WaterPumpDeviceInterface */
  virtual error_t TurnOn();
  virtual error_t TurnOff();
  virtual error_t GetState(bool *is_on);
  virtual const water_pump_id_t& id();

 private:
  struct Impl;
  Impl *impl_;
};

#endif  // INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_DEVICE_H
