/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 22, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_FACTORY_FACTORY_INTERFACE_H
#define INCLUDE_COMMON_FACTORY_FACTORY_INTERFACE_H

#include "common/error/error.h"

template <typename ProductInterfaceT>
class FactoryInterface0Arg {
 public:
  virtual ~FactoryInterface0Arg() {}
  virtual error_t Create(std::shared_ptr<ProductInterfaceT>& created) = 0;
};

template <typename ProductInterfaceT,
          typename Arg1T>
class FactoryInterface1Arg {
 public:
  virtual ~FactoryInterface1Arg() {}
  virtual error_t Create(std::shared_ptr<ProductInterfaceT>& created, Arg1T arg1) = 0;
};

template <typename ProductInterfaceT,
          typename Arg1T,
          typename Arg2T>
class FactoryInterface2Arg {
 public:
  virtual ~FactoryInterface2Arg() {}
  virtual error_t Create(std::shared_ptr<ProductInterfaceT>& created, Arg1T arg1, Arg2T arg2) = 0;
};

#endif  // INCLUDE_COMMON_FACTORY_FACTORY_INTERFACE_H
