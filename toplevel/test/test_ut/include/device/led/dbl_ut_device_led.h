/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 18, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef TEST_UT_INCLUDE_DEVICE_LED_DBL_UT_DEVICE_LED_H
#define TEST_UT_INCLUDE_DEVICE_LED_DBL_UT_DEVICE_LED_H

#include "gmock/gmock.h"
#include "device/led/led_device_adapter_interface.h"

class MockedLedDeviceAdapter : public LedDeviceAdapterInterface {
 public:
  MOCK_METHOD0(Init, error_t());
  MOCK_METHOD0(Finish, error_t());
  MOCK_METHOD1(SetPinState, error_t(bool state));
  MOCK_METHOD1(GetPinState, error_t(bool *state));
};

#endif  // TEST_UT_INCLUDE_DEVICE_LED_DBL_UT_DEVICE_LED_H
