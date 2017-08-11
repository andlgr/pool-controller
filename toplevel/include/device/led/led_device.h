/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 14, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_DEVICE_LED_LED_DEVICE_H
#define INCLUDE_DEVICE_LED_LED_DEVICE_H

#include <memory>

#include "include/device/led/led_device_interface.h"
#include "include/common/adapter/gpio/gpio_adapter_interface.h"

class LedDeviceAdapterInterface : public virtual GpioAdapterInterface {
};

class LedDevice : public LedDeviceInterface {
 public:
  explicit LedDevice(led_id_t id, std::shared_ptr<LedDeviceAdapterInterface> adapter);
  virtual ~LedDevice();

 public:
  virtual error_t SetState(led_state_t state);
  virtual error_t GetState(led_state_t *state);
  virtual const led_id_t& id();

 private:
  struct Impl;
  Impl *impl_;
};

#endif  // INCLUDE_DEVICE_LED_LED_DEVICE_H
