/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 22, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_FACTORY_FACTORY_INTERFACE_H
#define INCLUDE_COMMON_FACTORY_FACTORY_INTERFACE_H

#include <memory>
#include "common/error/error.h"

template <typename ProductInterfaceT, typename ... Args>
class FactoryInterface {
 public:
  virtual ~FactoryInterface() {}
  virtual error_t Create(std::shared_ptr<ProductInterfaceT>& created, Args ... args) = 0;
};

#endif  // INCLUDE_COMMON_FACTORY_FACTORY_INTERFACE_H
