/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 18, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#include "test/include/device/led/fxt_device_led.h"

TestDeviceLed::TestDeviceLed() {
  mocked_adapter_.reset(new MockedLedDeviceAdapter());
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  led_device_ = new LedDevice(LED_ID_1, mocked_adapter_);
}

TestDeviceLed::~TestDeviceLed() {
  delete led_device_;
}

void TestDeviceLed::SetUpTestCase() {
}

void TestDeviceLed::TearDownTestCase() {
}

void TestDeviceLed::SetUp() {
}

void TestDeviceLed::TearDown() {
}
