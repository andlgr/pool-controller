/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 18, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef TEST_UT_INCLUDE_DEVICE_LED_FXT_UT_DEVICE_LED_H
#define TEST_UT_INCLUDE_DEVICE_LED_FXT_UT_DEVICE_LED_H

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "device/led/led_device.h"
#include "dbl_ut_led_device.h"

namespace test_ut {

class TestUtLedDevice : public testing::Test {
 public:
  TestUtLedDevice();
  ~TestUtLedDevice();

  static void SetUpTestCase();
  static void TearDownTestCase();

  virtual void SetUp();
  virtual void TearDown();

 protected:
  static std::shared_ptr<MockedLedDeviceAdapter> mocked_adapter_;
  static std::unique_ptr<LedDevice> led_device_;
};

}  // namespace test_ut

#endif  // TEST_UT_INCLUDE_DEVICE_LED_FXT_UT_DEVICE_LED_H
