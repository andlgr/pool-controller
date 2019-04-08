/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 8, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "test_ut/include/device/water_pump/fxt_ut_water_pump_device.h"

using testing::Return;
using testing::Mock;

namespace test_ut {

TEST_F(TestUtWaterPumpDevice, Set_Get_State_Success) {
  // Check initial state
  bool water_pump_state = false;
  ASSERT_EQ(ERROR_NO, water_pump_device_->GetState(&water_pump_state));
  ASSERT_FALSE(water_pump_state);

  // Test ON
  EXPECT_CALL(*mocked_adapter_, SetPinState(true))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->TurnOn());
  ASSERT_EQ(ERROR_NO, water_pump_device_->GetState(&water_pump_state));
  ASSERT_TRUE(water_pump_state);

  // Test OFF
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->TurnOff());
  ASSERT_EQ(ERROR_NO, water_pump_device_->GetState(&water_pump_state));
  ASSERT_FALSE(water_pump_state);

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtWaterPumpDevice, Set_Get_State_ERROR) {
  // Check initial state
  bool water_pump_state = false;
  ASSERT_EQ(ERROR_NO, water_pump_device_->GetState(&water_pump_state));
  ASSERT_FALSE(water_pump_state);

  // Test ON
  EXPECT_CALL(*mocked_adapter_, SetPinState(true))
      .WillOnce(Return(ERROR_FAIL));
  ASSERT_EQ(ERROR_FAIL, water_pump_device_->TurnOn());
  ASSERT_EQ(ERROR_NO, water_pump_device_->GetState(&water_pump_state));
  ASSERT_FALSE(water_pump_state);

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtWaterPumpDevice, Get_Id_Success) {
  ASSERT_EQ(WATER_PUMP_ID_FILTER, water_pump_device_->id());
}

TEST_F(TestUtWaterPumpDevice, Null_Pointer) {
  ASSERT_EQ(ERROR_INVALID_POINTER, water_pump_device_->GetState(nullptr));
}

TEST_F(TestUtWaterPumpDevice, Set_State_Twice) {
  // Check initial state
  bool water_pump_state = false;
  ASSERT_EQ(ERROR_NO, water_pump_device_->GetState(&water_pump_state));
  ASSERT_FALSE(water_pump_state);

  // Set OFF again
  ASSERT_EQ(ERROR_ALREADY, water_pump_device_->TurnOff());

  // Set ON
  EXPECT_CALL(*mocked_adapter_, SetPinState(true))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->TurnOn());
  ASSERT_EQ(ERROR_NO, water_pump_device_->GetState(&water_pump_state));
  ASSERT_TRUE(water_pump_state);

  // Set ON again
  ASSERT_EQ(ERROR_ALREADY, water_pump_device_->TurnOn());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtWaterPumpDevice, Init_Twice) {
  ASSERT_EQ(ERROR_ALREADY, water_pump_device_->Init());
}

TEST_F(TestUtWaterPumpDevice, Finish_Twice) {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->Finish());

  ASSERT_EQ(ERROR_INIT, water_pump_device_->Finish());

  // Init back, so TearDown() doesn't fail
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->Init());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtWaterPumpDevice, Set_State_Without_Init) {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->Finish());

  ASSERT_EQ(ERROR_INIT, water_pump_device_->TurnOn());

  // Init back, so TearDown() doesn't fail
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->Init());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtWaterPumpDevice, Get_State_Without_Init) {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->Finish());

  bool state = false;
  ASSERT_EQ(ERROR_INIT, water_pump_device_->GetState(&state));

  // Init back, so TearDown() doesn't fail
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->Init());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtWaterPumpDevice, Init_Adapter_Fail) {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->Finish());

  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_FAIL));
  ASSERT_EQ(ERROR_FAIL, water_pump_device_->Init());

  // Init back, so TearDown() doesn't fail
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, water_pump_device_->Init());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtWaterPumpDevice, Finish_Adapter_Fail) {
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_FAIL));

  ASSERT_EQ(ERROR_FAIL, water_pump_device_->Finish());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtWaterPumpDevice, Create_WaterPump_Device_With_Null_Adapter) {
  std::shared_ptr<WaterPumpDeviceAdapterInterface> adapter(nullptr);
  std::unique_ptr<WaterPumpDevice> water_pump_device(new WaterPumpDevice(WATER_PUMP_ID_FILTER, adapter));
  ASSERT_EQ(ERROR_INVALID_DEPENDENCY, water_pump_device->Init());
}

}  // namespace test_ut
