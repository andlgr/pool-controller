/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 19, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_INIT_INIT_INTERFACE_H
#define INCLUDE_COMMON_INIT_INIT_INTERFACE_H

#include "common/error/error.h"

class InitInterface {
 public:
  virtual ~InitInterface() {};
  virtual error_t Init() = 0;
  virtual error_t Finish() = 0;
};

#endif  // INCLUDE_COMMON_INIT_INIT_INTERFACE_H
