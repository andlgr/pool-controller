/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 8, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef TEST_UT_INCLUDE_DEVICE_WATER_PUMP_FXT_UT_DEVICE_WATER_PUMP_H
#define TEST_UT_INCLUDE_DEVICE_WATER_PUMP_FXT_UT_DEVICE_WATER_PUMP_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "device/water_pump/water_pump_device.h"

#include "dbl_ut_water_pump_device.h"

namespace test_ut {

class TestUtWaterPumpDevice : public testing::Test {
 public:
  TestUtWaterPumpDevice();
  ~TestUtWaterPumpDevice();

  static void SetUpTestCase();
  static void TearDownTestCase();

  virtual void SetUp();
  virtual void TearDown();

 protected:
  static std::shared_ptr<MockedWaterPumpDeviceAdapter> mocked_adapter_;
  static std::unique_ptr<WaterPumpDevice> water_pump_device_;
};

}  // namespace test_ut

#endif  // TEST_UT_INCLUDE_DEVICE_WATER_PUMP_FXT_UT_DEVICE_WATER_PUMP_H
