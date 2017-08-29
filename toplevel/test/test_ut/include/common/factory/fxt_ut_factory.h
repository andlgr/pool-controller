/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 22, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef TEST_UT_INCLUDE_COMMON_FACTORY_FXT_UT_FACTORY_H
#define TEST_UT_INCLUDE_COMMON_FACTORY_FXT_UT_FACTORY_H

#include "gtest/gtest.h"
#include "test_ut/include/common/factory/dbl_ut_factory.h"
#include "common/factory/factory.h"

namespace test_ut {

class TestUtFactory : public testing::Test {
 public:
  TestUtFactory();
  ~TestUtFactory();

  static void SetUpTestCase();
  static void TearDownTestCase();

  virtual void SetUp();
  virtual void TearDown();
};

}  // namespace test_ut

#endif  // TEST_UT_INCLUDE_COMMON_FACTORY_FXT_UT_FACTORY_H
