/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 8, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "test_ut/include/device/water_pump/fxt_ut_water_pump_device.h"

using testing::Mock;
using testing::Return;

namespace test_ut {

std::shared_ptr<MockedWaterPumpDeviceAdapter> TestUtWaterPumpDevice::mocked_adapter_;
std::unique_ptr<WaterPumpDevice> TestUtWaterPumpDevice::water_pump_device_;

TestUtWaterPumpDevice::TestUtWaterPumpDevice() {
}

TestUtWaterPumpDevice::~TestUtWaterPumpDevice() {
}

void TestUtWaterPumpDevice::SetUpTestCase() {
  mocked_adapter_.reset(new MockedWaterPumpDeviceAdapter());
  water_pump_device_.reset(new WaterPumpDevice(WATER_PUMP_FILTER, mocked_adapter_));
}

void TestUtWaterPumpDevice::TearDownTestCase() {
  water_pump_device_.reset();
  mocked_adapter_.reset();
}

void TestUtWaterPumpDevice::SetUp() {
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->Init());
  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

void TestUtWaterPumpDevice::TearDown() {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->Finish());
  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

}  // namespace test_ut
