/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 7, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_DEVICE_ADAPTER_INTERFACE_H
#define INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_DEVICE_ADAPTER_INTERFACE_H

#include "common/adapter/gpio/gpio_adapter_interface.h"

class WaterPumpDeviceAdapterInterface : public virtual GpioAdapterInterface {
};

#endif  // INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_DEVICE_ADAPTER_INTERFACE_H
