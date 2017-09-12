/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 14, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_ADAPTER_GPIO_GPIO_ADAPTER_INTERFACE_H
#define INCLUDE_COMMON_ADAPTER_GPIO_GPIO_ADAPTER_INTERFACE_H

#include "common/error/error.h"
#include "common/init/init_interface.h"

class GpioAdapterInterface : public virtual InitInterface {
 public:
  virtual ~GpioAdapterInterface() {}
  virtual error_t SetPinState(bool state) = 0;
  virtual error_t GetPinState(bool *state) = 0;
};

#endif  // INCLUDE_COMMON_ADAPTER_GPIO_GPIO_ADAPTER_INTERFACE_H
