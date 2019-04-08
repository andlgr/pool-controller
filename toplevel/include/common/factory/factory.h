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
          typename ConcreteT,
          typename ... Args>
class Factory : public virtual FactoryInterface<ProductInterfaceT, Args ...> {
 public:
  Factory() {}
  virtual ~Factory() {}

  virtual error_t Create(std::shared_ptr<ProductInterfaceT>& created, Args ... args) {
    created.reset(new ConcreteT(args...));
    if (nullptr == created.get()) {
      return ERROR_MALLOC;
    }
    return ERROR_NO;
  }
};

#endif  // INCLUDE_COMMON_FACTORY_FACTORY_H
