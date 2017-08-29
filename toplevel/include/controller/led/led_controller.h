/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 28, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_CONTROLLER_LED_LED_CONTROLLER_H
#define INCLUDE_CONTROLLER_LED_LED_CONTROLLER_H

#include "controller/led/led_controller_interface.h"

class LedController : public virtual LedControllerInterface {
 public:
  LedController();
  virtual ~LedController();

  /* Inherited from LedControllerInterface */
  virtual error_t SetState(led_id_t id, led_state_t state);
  virtual error_t GetState(led_id_t id, led_state_t *state);

  virtual error_t RegisterLedDevice(std::shared_ptr<LedDeviceInterface> led_device);
  virtual error_t UnregisterLedDevice(led_id_t id);

 private:
  struct Impl;
  Impl *impl_;
};

#endif  // INCLUDE_CONTROLLER_LED_LED_CONTROLLER_H
