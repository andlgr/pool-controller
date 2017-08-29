/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 24, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_CONTROLLER_LED_LED_CONTROLLER_INTERFACE_H
#define INCLUDE_CONTROLLER_LED_LED_CONTROLLER_INTERFACE_H

#include <memory>
#include "common/error/error.h"
#include "device/led/led_types.h"
#include "device/led/led_device_interface.h"

class LedControllerInterface {
 public:
  virtual ~LedControllerInterface() {}

  virtual error_t SetState(led_id_t id, led_state_t state) = 0;
  virtual error_t GetState(led_id_t id, led_state_t *state) = 0;

  virtual error_t RegisterLedDevice(std::shared_ptr<LedDeviceInterface> led_device) = 0;
  virtual error_t UnregisterLedDevice(led_id_t id) = 0;
};

#endif  // INCLUDE_CONTROLLER_LED_LED_CONTROLLER_INTERFACE_H
