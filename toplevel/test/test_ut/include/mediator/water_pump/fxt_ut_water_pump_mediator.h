/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 13, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef TEST_UT_INCLUDE_MEDIATOR_WATER_PUMP_FXT_UT_WATER_PUMP_MEDIATOR_H
#define TEST_UT_INCLUDE_MEDIATOR_WATER_PUMP_FXT_UT_WATER_PUMP_MEDIATOR_H

#include "gtest/gtest.h"
#include "test_ut/include/device/water_pump/dbl_ut_water_pump_device.h"
#include "device/water_pump/water_pump_device.h"
#include "mediator/water_pump/water_pump_mediator.h"

namespace test_ut {

class TestUtWaterPumpMediator : public testing::Test {
 public:
  TestUtWaterPumpMediator();
  ~TestUtWaterPumpMediator();

  static void SetUpTestCase();
  static void TearDownTestCase();

  virtual void SetUp();
  virtual void TearDown();

 protected:
  std::unique_ptr<WaterPumpMediatorInterface> water_pump_mediator_;
};

}  // namespace test_ut

#endif  // TEST_UT_INCLUDE_MEDIATOR_WATER_PUMP_FXT_UT_WATER_PUMP_MEDIATOR_H
