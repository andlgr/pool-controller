/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 18, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#include "test/include/device/led/fxt_device_led.h"

using testing::Return;

TEST_F(TestDeviceLed, Set_State_Test) {
  EXPECT_CALL(*mocked_adapter_, SetPinState(true))
      .WillOnce(Return(ERROR_NO));
  ASSERT_EQ(ERROR_NO, led_device_->SetState(LED_STATE_ON));
}
