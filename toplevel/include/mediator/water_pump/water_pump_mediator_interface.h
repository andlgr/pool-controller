/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 11, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_MEDIATOR_WATER_PUMP_WATER_PUMP_MEDIATOR_INTERFACE_H
#define INCLUDE_MEDIATOR_WATER_PUMP_WATER_PUMP_MEDIATOR_INTERFACE_H

#include <memory>
#include "common/error/error.h"
#include "common/init/init_interface.h"
#include "device/water_pump/water_pump_types.h"
#include "device/water_pump/water_pump_device_interface.h"

class WaterPumpMediatorInterface : public virtual InitInterface {
 public:
  virtual ~WaterPumpMediatorInterface() {}

  virtual error_t Activate(water_pump_id_t id) = 0;
  virtual error_t Deactivate() = 0;
  virtual error_t GetActive(water_pump_id_t *active_id) = 0;
  virtual error_t RegisterWaterPumpDevice(std::shared_ptr<WaterPumpDeviceInterface> water_pump_device) = 0;
  virtual error_t UnregisterWaterPumpDevice(water_pump_id_t id) = 0;
};

#endif  // INCLUDE_MEDIATOR_WATER_PUMP_WATER_PUMP_MEDIATOR_INTERFACE_H
