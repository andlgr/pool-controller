/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 28, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "test_ut/include/controller/led/fxt_ut_led_controller.h"

using testing::NiceMock;

namespace test_ut {

TEST_F(TestUtLedController, Set_Get_State_Success) {
  led_state_t state = LED_STATE_INVALID;

  // Prepare Controller
  std::shared_ptr<LedDeviceAdapterInterface> adapter1(new NiceMock<MockedLedDeviceAdapter>);
  std::shared_ptr<LedDeviceInterface> led1(new LedDevice(LED_ID_1, adapter1));

  std::shared_ptr<LedDeviceAdapterInterface> adapter2(new NiceMock<MockedLedDeviceAdapter>);
  std::shared_ptr<LedDeviceInterface> led2(new LedDevice(LED_ID_2, adapter2));

  ASSERT_EQ(ERROR_NO, led_controller_->RegisterLedDevice(led1));
  ASSERT_EQ(ERROR_NO, led_controller_->RegisterLedDevice(led2));

  // Perform the test
  ASSERT_EQ(ERROR_NO, led_controller_->SetState(LED_ID_1, LED_STATE_ON));
  ASSERT_EQ(ERROR_NO, led_controller_->GetState(LED_ID_1, &state));
  ASSERT_EQ(LED_STATE_ON, state);

  // Check independence
  state = LED_STATE_INVALID;
  ASSERT_EQ(ERROR_NO, led_controller_->GetState(LED_ID_2, &state));
  ASSERT_EQ(LED_STATE_OFF, state);

  // Test another
  ASSERT_EQ(ERROR_NO, led_controller_->SetState(LED_ID_2, LED_STATE_ON));
  ASSERT_EQ(ERROR_NO, led_controller_->GetState(LED_ID_2, &state));
  ASSERT_EQ(LED_STATE_ON, state);

  // Check independence
  state = LED_STATE_INVALID;
  ASSERT_EQ(ERROR_NO, led_controller_->GetState(LED_ID_1, &state));
  ASSERT_EQ(LED_STATE_ON, state);

  // Unregister Led Devices
  ASSERT_EQ(ERROR_NO, led_controller_->UnregisterLedDevice(LED_ID_1));
  ASSERT_EQ(ERROR_NO, led_controller_->UnregisterLedDevice(LED_ID_2));
}

TEST_F(TestUtLedController, Set_Get_State_Invalid_Index) {
  led_state_t state = LED_STATE_INVALID;
  ASSERT_EQ(ERROR_INVALID_INDEX, led_controller_->SetState(LED_ID_1, LED_STATE_ON));
  ASSERT_EQ(ERROR_INVALID_INDEX, led_controller_->GetState(LED_ID_1, &state));
}

TEST_F(TestUtLedController, Null_Pointer) {
  ASSERT_EQ(ERROR_INVALID_POINTER, led_controller_->RegisterLedDevice(std::shared_ptr<LedDeviceInterface>(nullptr)));
  ASSERT_EQ(ERROR_INVALID_POINTER, led_controller_->GetState(LED_ID_1, nullptr));
}

TEST_F(TestUtLedController, Register_Unregister_Led_Device_Success) {
  std::shared_ptr<LedDeviceAdapterInterface> adapter1(new NiceMock<MockedLedDeviceAdapter>);
  std::shared_ptr<LedDeviceInterface> led1(new LedDevice(LED_ID_1, adapter1));

  ASSERT_EQ(ERROR_NO, led_controller_->RegisterLedDevice(led1));
  ASSERT_EQ(ERROR_NO, led_controller_->UnregisterLedDevice(LED_ID_1));
}

TEST_F(TestUtLedController, Register_Led_Device_Twice) {
  std::shared_ptr<LedDeviceAdapterInterface> adapter1(new NiceMock<MockedLedDeviceAdapter>);
  std::shared_ptr<LedDeviceInterface> led1(new LedDevice(LED_ID_1, adapter1));

  ASSERT_EQ(ERROR_NO, led_controller_->RegisterLedDevice(led1));
  ASSERT_EQ(ERROR_BUSY, led_controller_->RegisterLedDevice(led1));
}

TEST_F(TestUtLedController, Unregister_Led_Device_Twice) {
  std::shared_ptr<LedDeviceAdapterInterface> adapter1(new NiceMock<MockedLedDeviceAdapter>);
  std::shared_ptr<LedDeviceInterface> led1(new LedDevice(LED_ID_1, adapter1));
  ASSERT_EQ(ERROR_NO, led_controller_->RegisterLedDevice(led1));

  ASSERT_EQ(ERROR_NO, led_controller_->UnregisterLedDevice(LED_ID_1));
  ASSERT_EQ(ERROR_INVALID_INDEX, led_controller_->UnregisterLedDevice(LED_ID_1));
}

}  // namespace test_ut
