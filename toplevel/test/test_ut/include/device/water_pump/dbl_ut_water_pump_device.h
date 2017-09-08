/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 8, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef TEST_UT_INCLUDE_DEVICE_WATER_PUMP_DBL_UT_DEVICE_WATER_PUMP_H
#define TEST_UT_INCLUDE_DEVICE_WATER_PUMP_DBL_UT_DEVICE_WATER_PUMP_H

#include "gmock/gmock.h"
#include "device/water_pump/water_pump_device_adapter_interface.h"

namespace test_ut {

class MockedWaterPumpDeviceAdapter : public WaterPumpDeviceAdapterInterface {
 public:
  MOCK_METHOD0(Init, error_t());
  MOCK_METHOD0(Finish, error_t());
  MOCK_METHOD1(SetPinState, error_t(bool state));
  MOCK_METHOD1(GetPinState, error_t(bool *state));
};

}  // namespace test_ut

#endif  // TEST_UT_INCLUDE_DEVICE_WATER_PUMP_DBL_UT_DEVICE_WATER_PUMP_H
