/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 28, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "test_ut/include/controller/led/fxt_ut_led_controller.h"

namespace test_ut {

TestUtLedController::TestUtLedController() {
}

TestUtLedController::~TestUtLedController() {
}

void TestUtLedController::SetUpTestCase() {
}

void TestUtLedController::TearDownTestCase() {
}

void TestUtLedController::SetUp() {
  led_controller_.reset(new LedController());
}

void TestUtLedController::TearDown() {
  led_controller_.reset();
}

}  // namespace test_ut
