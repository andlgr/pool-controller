/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 12, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_MEDIATOR_WATER_PUMP_WATER_PUMP_MEDIATOR_H
#define INCLUDE_MEDIATOR_WATER_PUMP_WATER_PUMP_MEDIATOR_H

#include "mediator/water_pump/water_pump_mediator_interface.h"

class WaterPumpMediator : public WaterPumpMediatorInterface {
 public:
  explicit WaterPumpMediator();
  virtual ~WaterPumpMediator();

  /* Inherited from WaterPumpMediatorInterface */
  virtual error_t Activate(water_pump_id_t id);
  virtual error_t Deactivate();
  virtual error_t GetActive(water_pump_id_t *active_id);
  virtual error_t RegisterWaterPumpDevice(std::shared_ptr<WaterPumpDeviceInterface> water_pump_device);
  virtual error_t UnregisterWaterPumpDevice(water_pump_id_t id);

 private:
  struct Impl;
  Impl *impl_;
};

#endif  // INCLUDE_MEDIATOR_WATER_PUMP_WATER_PUMP_MEDIATOR_H
