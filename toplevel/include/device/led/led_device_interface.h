/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 10, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_DEVICE_LED_LED_DEVICE_INTERFACE_H
#define INCLUDE_DEVICE_LED_LED_DEVICE_INTERFACE_H

#include "common/error/error.h"
#include "common/init/init_interface.h"
#include "device/led/led_types.h"

class LedDeviceInterface : public virtual InitInterface {
 public:
  virtual ~LedDeviceInterface() {}
  virtual error_t SetState(led_state_t state) = 0;
  virtual error_t GetState(led_state_t *state) = 0;
  virtual const led_id_t& id() = 0;
};

#endif  // INCLUDE_DEVICE_LED_LED_DEVICE_INTERFACE_H
