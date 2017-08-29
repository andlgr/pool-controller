/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 28, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef TEST_UT_INCLUDE_CONTROLLER_LED_FXT_UT_LED_CONTROLLER_H
#define TEST_UT_INCLUDE_CONTROLLER_LED_FXT_UT_LED_CONTROLLER_H

#include "gtest/gtest.h"
#include "test_ut/include/device/led/dbl_ut_led_device.h"
#include "device/led/led_device.h"
#include "controller/led/led_controller.h"

namespace test_ut {

class TestUtLedController : public testing::Test {
 public:
  TestUtLedController();
  ~TestUtLedController();

  static void SetUpTestCase();
  static void TearDownTestCase();

  virtual void SetUp();
  virtual void TearDown();

 protected:
  std::unique_ptr<LedControllerInterface> led_controller_;
};

}  // namespace test_ut

#endif  // TEST_UT_INCLUDE_CONTROLLER_LED_FXT_UT_LED_CONTROLLER_H
