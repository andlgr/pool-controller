/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 18, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef TEST_UT_INCLUDE_DEVICE_LED_FXT_UT_DEVICE_LED_H
#define TEST_UT_INCLUDE_DEVICE_LED_FXT_UT_DEVICE_LED_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "test_ut/include/device/led/dbl_ut_device_led.h"
#include "device/led/led_device.h"

class TestUtDeviceLed : public testing::Test {
 public:
  TestUtDeviceLed();
  ~TestUtDeviceLed();

  static void SetUpTestCase();
  static void TearDownTestCase();

  virtual void SetUp();
  virtual void TearDown();

 protected:
  static std::shared_ptr<MockedLedDeviceAdapter> mocked_adapter_;
  static std::unique_ptr<LedDevice> led_device_;
};

#endif  // TEST_UT_INCLUDE_DEVICE_LED_FXT_UT_DEVICE_LED_H
