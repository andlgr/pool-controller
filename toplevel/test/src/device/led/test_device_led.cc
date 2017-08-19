/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 18, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#include "test/include/device/led/fxt_device_led.h"

using testing::Return;
using testing::Mock;

TEST_F(TestUtDeviceLed, Set_Get_State_Success) {
  // Check initial state
  led_state_t led_state = LED_STATE_INVALID;
  ASSERT_EQ(ERROR_NO, led_device_->GetState(&led_state));
  ASSERT_EQ(LED_STATE_OFF, led_state);

  // Test ON
  EXPECT_CALL(*mocked_adapter_, SetPinState(true))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->SetState(LED_STATE_ON));

  // Test OFF
  EXPECT_CALL(*mocked_adapter_, SetPinState(false))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->SetState(LED_STATE_OFF));

  Mock::VerifyAndClearExpectations(mocked_adapter_.get());
}

TEST_F(TestUtDeviceLed, Set_State_Fail) {
  ASSERT_EQ(ERROR_INVALID_INDEX, led_device_->SetState(LED_STATE_INVALID));
  ASSERT_EQ(ERROR_INVALID_INDEX, led_device_->SetState(LED_STATE_MAX));
}

TEST_F(TestUtDeviceLed, Set_State_Unimplemented) {
  ASSERT_EQ(ERROR_UNIMPLEMENTED_OPERATION, led_device_->SetState(LED_STATE_BLINK_FAST));
  ASSERT_EQ(ERROR_UNIMPLEMENTED_OPERATION, led_device_->SetState(LED_STATE_BLINK_SLOW));
}

TEST_F(TestUtDeviceLed, Get_Id_Success) {
  ASSERT_EQ(LED_ID_1, led_device_->id());
}

TEST_F(TestUtDeviceLed, Null_Pointer) {
  ASSERT_EQ(ERROR_INVALID_POINTER, led_device_->GetState(nullptr));
}
