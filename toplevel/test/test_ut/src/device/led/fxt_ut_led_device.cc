/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 18, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "test_ut/include/device/led/fxt_ut_led_device.h"

using testing::Mock;
using testing::Return;

namespace test_ut {

std::shared_ptr<MockedLedDeviceAdapter> TestUtLedDevice::mocked_adapter_;
std::unique_ptr<LedDevice> TestUtLedDevice::led_device_;

TestUtLedDevice::TestUtLedDevice() {
}

TestUtLedDevice::~TestUtLedDevice() {
}

void TestUtLedDevice::SetUpTestCase() {
  mocked_adapter_.reset(new MockedLedDeviceAdapter());
  led_device_.reset(new LedDevice(LED_ID_1, mocked_adapter_));
}

void TestUtLedDevice::TearDownTestCase() {
  led_device_.reset();
  mocked_adapter_.reset();
}

void TestUtLedDevice::SetUp() {
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Init());
  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

void TestUtLedDevice::TearDown() {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Finish());
  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

}  // namespace test_ut
