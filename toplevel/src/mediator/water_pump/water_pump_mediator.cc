/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 12, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "common/assert/assert.h"
#include "mediator/water_pump/water_pump_mediator.h"

struct WaterPumpMediator::Impl {
  Impl()
      : initialized_(false) {
  };
  bool initialized_;
};

WaterPumpMediator::WaterPumpMediator()
    : impl_(new WaterPumpMediator::Impl()) {
}

WaterPumpMediator::~WaterPumpMediator() {
  delete impl_;
}

error_t WaterPumpMediator::Init() {
  return ERROR_UNIMPLEMENTED_OPERATION;
}

error_t WaterPumpMediator::Finish() {
  return ERROR_UNIMPLEMENTED_OPERATION;
}

error_t WaterPumpMediator::Activate(water_pump_id_t id) {
  ARG_FUTURE_USE(id);
  return ERROR_UNIMPLEMENTED_OPERATION;
}

error_t WaterPumpMediator::Deactivate() {
  return ERROR_UNIMPLEMENTED_OPERATION;
}

error_t WaterPumpMediator::GetActive(water_pump_id_t *active_id) {
  ARG_FUTURE_USE(active_id);
  return ERROR_UNIMPLEMENTED_OPERATION;
}

error_t WaterPumpMediator::RegisterWaterPumpDevice(std::shared_ptr<WaterPumpDeviceInterface> water_pump_device) {
  ARG_FUTURE_USE(water_pump_device);
  return ERROR_UNIMPLEMENTED_OPERATION;
}

error_t WaterPumpMediator::UnregisterWaterPumpDevice(water_pump_id_t id) {
  ARG_FUTURE_USE(id);
  return ERROR_UNIMPLEMENTED_OPERATION;
}
