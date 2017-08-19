/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 18, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#include "test/include/device/led/fxt_device_led.h"

using testing::Mock;

std::shared_ptr<MockedLedDeviceAdapter> TestUtDeviceLed::mocked_adapter_ = nullptr;
LedDevice *TestUtDeviceLed::led_device_ = nullptr;

TestUtDeviceLed::TestUtDeviceLed() {
}

TestUtDeviceLed::~TestUtDeviceLed() {
}

void TestUtDeviceLed::SetUpTestCase() {
  mocked_adapter_.reset(new MockedLedDeviceAdapter());
  led_device_ = new LedDevice(LED_ID_1, mocked_adapter_);
}

void TestUtDeviceLed::TearDownTestCase() {
  delete led_device_;
  mocked_adapter_.reset();
}

void TestUtDeviceLed::SetUp() {
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Init());
  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

void TestUtDeviceLed::TearDown() {
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Finish());
  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}
