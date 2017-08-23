/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 22, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef TEST_UT_INCLUDE_COMMON_FACTORY_FXT_UT_FACTORY_H
#define TEST_UT_INCLUDE_COMMON_FACTORY_FXT_UT_FACTORY_H

#include "gtest/gtest.h"
#include "test_ut/include/common/factory/dbl_ut_factory.h"
#include "common/factory/factory.h"

class TestUtFactory : public testing::Test {
 public:
  TestUtFactory();
  ~TestUtFactory();

  static void SetUpTestCase();
  static void TearDownTestCase();

  virtual void SetUp();
  virtual void TearDown();
};

#endif  // TEST_UT_INCLUDE_COMMON_FACTORY_FXT_UT_FACTORY_H
