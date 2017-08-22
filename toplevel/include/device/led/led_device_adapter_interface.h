/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 14, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_DEVICE_LED_LED_DEVICE_ADAPTER_INTERFACE_H
#define INCLUDE_DEVICE_LED_LED_DEVICE_ADAPTER_INTERFACE_H

#include "common/adapter/gpio/gpio_adapter_interface.h"

class LedDeviceAdapterInterface : public virtual GpioAdapterInterface {
};

#endif  // INCLUDE_DEVICE_LED_LED_DEVICE_ADAPTER_INTERFACE_H
