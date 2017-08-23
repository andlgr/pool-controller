/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 22, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef TEST_UT_INCLUDE_COMMON_FACTORY_DBL_UT_FACTORY_H
#define TEST_UT_INCLUDE_COMMON_FACTORY_DBL_UT_FACTORY_H

class ProductInterface0Arg {
 public:
  virtual ~ProductInterface0Arg() {}
};

class Product0Arg : public ProductInterface0Arg {
 public:
  virtual ~Product0Arg() {}
};

class ProductInterface1Arg {
 public:
  virtual ~ProductInterface1Arg() {}
};

class Product1Arg : public ProductInterface1Arg {
 public:
  Product1Arg(int arg1) : arg1_(arg1) {};
  virtual ~Product1Arg() {}
  int arg1_;
};

class ProductInterface2Arg {
 public:
  virtual ~ProductInterface2Arg() {}
};

class Product2Arg : public ProductInterface2Arg {
 public:
  Product2Arg(int arg1, int arg2) : arg1_(arg1),
                                    arg2_(arg2) {};
  virtual ~Product2Arg() {}
  int arg1_;
  int arg2_;
};

#endif  // TEST_UT_INCLUDE_COMMON_FACTORY_DBL_UT_FACTORY_H
