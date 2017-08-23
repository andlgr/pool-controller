/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 18, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#include "test_ut/include/device/led/fxt_ut_device_led.h"

using testing::Mock;
using testing::Return;

std::shared_ptr<MockedLedDeviceAdapter> TestUtDeviceLed::mocked_adapter_;
std::unique_ptr<LedDevice> TestUtDeviceLed::led_device_;

TestUtDeviceLed::TestUtDeviceLed() {
}

TestUtDeviceLed::~TestUtDeviceLed() {
}

void TestUtDeviceLed::SetUpTestCase() {
  mocked_adapter_.reset(new MockedLedDeviceAdapter());
  led_device_.reset(new LedDevice(LED_ID_1, mocked_adapter_));
}

void TestUtDeviceLed::TearDownTestCase() {
  led_device_.reset();
  mocked_adapter_.reset();
}

void TestUtDeviceLed::SetUp() {
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Init());
  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

void TestUtDeviceLed::TearDown() {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Finish());
  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}
