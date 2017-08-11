/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 14, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_ADAPTER_GPIO_GPIO_ADAPTER_INTERFACE_H
#define INCLUDE_COMMON_ADAPTER_GPIO_GPIO_ADAPTER_INTERFACE_H

#include "include/common/error/error.h"

class GpioAdapterInterface {
 public:
  virtual ~GpioAdapterInterface() {};
  virtual error_t SetPinState(bool state) = 0;
  virtual error_t GetPinState(bool *state) = 0;
};

#endif  // INCLUDE_COMMON_ADAPTER_GPIO_GPIO_ADAPTER_INTERFACE_H
