/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 18, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "device/led/led_device.h"

class MockedLedDeviceAdapter : public LedDeviceAdapterInterface {
 public:
  MOCK_METHOD1(SetPinState, error_t(bool state));
  MOCK_METHOD1(GetPinState, error_t(bool *state));
};

class TestDeviceLed : public testing::Test {
 public:
  TestDeviceLed();
  ~TestDeviceLed();

  static void SetUpTestCase();
  static void TearDownTestCase();

  virtual void SetUp();
  virtual void TearDown();

 protected:
  std::shared_ptr<MockedLedDeviceAdapter> mocked_adapter_;
  LedDevice *led_device_;
};
