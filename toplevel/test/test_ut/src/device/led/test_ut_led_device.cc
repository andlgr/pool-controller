/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 18, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "test_ut/include/device/led/fxt_ut_led_device.h"

using testing::Return;
using testing::Mock;

namespace test_ut {

TEST_F(TestUtLedDevice, Set_Get_State_Success) {
  // Check initial state
  led_state_t led_state = LED_STATE_INVALID;
  ASSERT_EQ(ERROR_NO, led_device_->GetState(&led_state));
  ASSERT_EQ(LED_STATE_OFF, led_state);

  // Test ON
  EXPECT_CALL(*mocked_adapter_, SetPinState(true))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->SetState(LED_STATE_ON));
  ASSERT_EQ(ERROR_NO, led_device_->GetState(&led_state));
  ASSERT_EQ(LED_STATE_ON, led_state);

  // Test OFF
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->SetState(LED_STATE_OFF));
  ASSERT_EQ(ERROR_NO, led_device_->GetState(&led_state));
  ASSERT_EQ(LED_STATE_OFF, led_state);

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtLedDevice, Set_Get_State_ERROR) {
  // Check initial state
  led_state_t led_state = LED_STATE_INVALID;
  ASSERT_EQ(ERROR_NO, led_device_->GetState(&led_state));
  ASSERT_EQ(LED_STATE_OFF, led_state);

  // Test ON
  EXPECT_CALL(*mocked_adapter_, SetPinState(true))
      .WillOnce(Return(ERROR_FAIL));
  ASSERT_EQ(ERROR_FAIL, led_device_->SetState(LED_STATE_ON));
  ASSERT_EQ(ERROR_NO, led_device_->GetState(&led_state));
  ASSERT_EQ(LED_STATE_OFF, led_state);

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtLedDevice, Set_State_Fail) {
  ASSERT_EQ(ERROR_INVALID_INDEX, led_device_->SetState(LED_STATE_INVALID));
  ASSERT_EQ(ERROR_INVALID_INDEX, led_device_->SetState(LED_STATE_MAX));
}

TEST_F(TestUtLedDevice, Set_State_Unimplemented) {
  ASSERT_EQ(ERROR_UNIMPLEMENTED_OPERATION, led_device_->SetState(LED_STATE_BLINK_FAST));
  ASSERT_EQ(ERROR_UNIMPLEMENTED_OPERATION, led_device_->SetState(LED_STATE_BLINK_SLOW));
}

TEST_F(TestUtLedDevice, Get_Id_Success) {
  ASSERT_EQ(LED_ID_1, led_device_->id());
}

TEST_F(TestUtLedDevice, Null_Pointer) {
  ASSERT_EQ(ERROR_INVALID_POINTER, led_device_->GetState(nullptr));
}

TEST_F(TestUtLedDevice, Set_State_Twice) {
  // Check initial state
  led_state_t led_state = LED_STATE_INVALID;
  ASSERT_EQ(ERROR_NO, led_device_->GetState(&led_state));
  ASSERT_EQ(LED_STATE_OFF, led_state);

  // Set OFF again
  ASSERT_EQ(ERROR_ALREADY, led_device_->SetState(LED_STATE_OFF));

  // Set ON
  EXPECT_CALL(*mocked_adapter_, SetPinState(true))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->SetState(LED_STATE_ON));
  ASSERT_EQ(ERROR_NO, led_device_->GetState(&led_state));
  ASSERT_EQ(LED_STATE_ON, led_state);

  // Set ON again
  ASSERT_EQ(ERROR_ALREADY, led_device_->SetState(LED_STATE_ON));

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtLedDevice, Init_Twice) {
  ASSERT_EQ(ERROR_ALREADY, led_device_->Init());
}

TEST_F(TestUtLedDevice, Finish_Twice) {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Finish());

  ASSERT_EQ(ERROR_INIT, led_device_->Finish());

  // Init back, so TearDown() doesn't fail
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Init());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtLedDevice, Set_State_Without_Init) {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Finish());

  ASSERT_EQ(ERROR_INIT, led_device_->SetState(LED_STATE_ON));

  // Init back, so TearDown() doesn't fail
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Init());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtLedDevice, Get_State_Without_Init) {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Finish());

  led_state_t state = LED_STATE_INVALID;
  ASSERT_EQ(ERROR_INIT, led_device_->GetState(&state));

  // Init back, so TearDown() doesn't fail
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Init());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtLedDevice, Init_Adapter_Fail) {
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Finish());

  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_FAIL));
  ASSERT_EQ(ERROR_FAIL, led_device_->Init());

  // Init back, so TearDown() doesn't fail
  EXPECT_CALL(*mocked_adapter_, Init())
      .WillOnce(Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->Init());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtLedDevice, Finish_Adapter_Fail) {
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(testing::Return(ERROR_NO));
  EXPECT_CALL(*mocked_adapter_, Finish())
      .WillOnce(Return(ERROR_FAIL));

  ASSERT_EQ(ERROR_FAIL, led_device_->Finish());

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtLedDevice, Create_Led_Device_With_Null_Adapter) {
  std::shared_ptr<LedDeviceAdapterInterface> adapter(nullptr);
  std::unique_ptr<LedDevice> led_device(new LedDevice(LED_ID_1, adapter));
  ASSERT_EQ(ERROR_INVALID_DEPENDENCY, led_device->Init());
}

}  // namespace test_ut
