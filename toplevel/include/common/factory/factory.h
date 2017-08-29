/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 22, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_FACTORY_FACTORY_H
#define INCLUDE_COMMON_FACTORY_FACTORY_H

#include "common/factory/factory_interface.h"

template <typename ProductInterfaceT,
          typename ConcreteT>
class Factory0Arg : public virtual FactoryInterface0Arg<ProductInterfaceT> {
 public:
  Factory0Arg() {}
  virtual ~Factory0Arg() {}

  virtual error_t Create(std::shared_ptr<ProductInterfaceT>& created) {
    created.reset(new ConcreteT());
    if (nullptr == created.get()) {
      return ERROR_MALLOC;
    }
    return ERROR_NO;
  }
};

template <typename ProductInterfaceT,
          typename ConcreteT,
          typename Arg1T>
class Factory1Arg : public virtual FactoryInterface1Arg<ProductInterfaceT, Arg1T> {
 public:
  Factory1Arg() {}
  virtual ~Factory1Arg() {}

  virtual error_t Create(std::shared_ptr<ProductInterfaceT>& created, Arg1T arg1) {
    created.reset(new ConcreteT(arg1));
    if (nullptr == created.get()) {
      return ERROR_MALLOC;
    }
    return ERROR_NO;
  }
};

template <typename ProductInterfaceT,
          typename ConcreteT,
          typename Arg1T,
          typename Arg2T>
class Factory2Arg : public virtual FactoryInterface2Arg<ProductInterfaceT, Arg1T, Arg2T> {
 public:
  Factory2Arg() {}
  virtual ~Factory2Arg() {}

  virtual error_t Create(std::shared_ptr<ProductInterfaceT>& created, Arg1T arg1, Arg2T arg2) {
    created.reset(new ConcreteT(arg1, arg2));
    if (nullptr == created.get()) {
      return ERROR_MALLOC;
    }
    return ERROR_NO;
  }
};

#endif  // INCLUDE_COMMON_FACTORY_FACTORY_H
