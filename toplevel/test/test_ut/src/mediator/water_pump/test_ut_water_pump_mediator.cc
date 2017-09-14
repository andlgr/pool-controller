/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 13, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "test_ut/include/mediator/water_pump/fxt_ut_water_pump_mediator.h"

using testing::NiceMock;

namespace test_ut {

TEST_F(TestUtWaterPumpMediator, Activate_Deactivate_Success) {
  water_pump_id_t active_pump = WATER_PUMP_ID_INVALID;
  bool state = false;

  // Prepare Mediator
  std::shared_ptr<WaterPumpDeviceAdapterInterface> adapter_heater(new NiceMock<MockedWaterPumpDeviceAdapter>);
  std::shared_ptr<WaterPumpDeviceInterface> water_pump_heater(new WaterPumpDevice(WATER_PUMP_HEATER, adapter_heater));

  std::shared_ptr<WaterPumpDeviceAdapterInterface> adapter_filter(new NiceMock<MockedWaterPumpDeviceAdapter>);
  std::shared_ptr<WaterPumpDeviceInterface> water_pump_filter(new WaterPumpDevice(WATER_PUMP_FILTER, adapter_filter));

  ASSERT_EQ(ERROR_NO, water_pump_mediator_->RegisterWaterPumpDevice(water_pump_heater));
  ASSERT_EQ(ERROR_NO, water_pump_mediator_->RegisterWaterPumpDevice(water_pump_filter));

  // Perform the test
  ASSERT_EQ(ERROR_NO, water_pump_mediator_->Activate(WATER_PUMP_HEATER));
  ASSERT_EQ(ERROR_NO, water_pump_mediator_->GetActive(&active_pump));
  ASSERT_EQ(WATER_PUMP_HEATER, active_pump);

  // Check mediator letting only one pump active at time
  state = false;
  ASSERT_EQ(ERROR_NO, water_pump_heater->GetState(&state));  // Must be ON
  ASSERT_TRUE(state);
  ASSERT_EQ(ERROR_NO, water_pump_filter->GetState(&state));  // Must be OFF
  ASSERT_FALSE(state);

  // Test activation uniqueness
  ASSERT_EQ(ERROR_NO, water_pump_mediator_->Activate(WATER_PUMP_FILTER));
  ASSERT_EQ(ERROR_NO, water_pump_mediator_->GetActive(&active_pump));
  ASSERT_EQ(WATER_PUMP_FILTER, active_pump);

  // Check mediator letting only one pump active at time
  state = true;
  ASSERT_EQ(ERROR_NO, water_pump_heater->GetState(&state));  // Must be OFF
  ASSERT_FALSE(state);
  ASSERT_EQ(ERROR_NO, water_pump_filter->GetState(&state));  // Must be ON
  ASSERT_TRUE(state);

  // Test deactivation
  ASSERT_EQ(ERROR_NO, water_pump_mediator_->Deactivate());

  // Check all pumps OFF
  state = true;
  ASSERT_EQ(ERROR_NO, water_pump_heater->GetState(&state));  // Must be OFF
  ASSERT_FALSE(state);
  state = true;
  ASSERT_EQ(ERROR_NO, water_pump_filter->GetState(&state));  // Must be OFF
  ASSERT_FALSE(state);

  // Unregister WaterPump Devices
  ASSERT_EQ(ERROR_NO, water_pump_mediator_->UnregisterWaterPumpDevice(WATER_PUMP_HEATER));
  ASSERT_EQ(ERROR_NO, water_pump_mediator_->UnregisterWaterPumpDevice(WATER_PUMP_FILTER));
}

TEST_F(TestUtWaterPumpMediator, Activate_Invalid_Index) {
  ASSERT_EQ(ERROR_INVALID_INDEX, water_pump_mediator_->Activate(WATER_PUMP_FILTER));
}

TEST_F(TestUtWaterPumpMediator, Null_Pointer) {
  ASSERT_EQ(ERROR_INVALID_POINTER, water_pump_mediator_->RegisterWaterPumpDevice(std::shared_ptr<WaterPumpDeviceInterface>(nullptr)));
  ASSERT_EQ(ERROR_INVALID_POINTER, water_pump_mediator_->GetActive(nullptr));
}

TEST_F(TestUtWaterPumpMediator, Register_Unregister_Water_Pump_Device_Success) {
  std::shared_ptr<WaterPumpDeviceAdapterInterface> adapter1(new NiceMock<MockedWaterPumpDeviceAdapter>);
  std::shared_ptr<WaterPumpDeviceInterface> water_pump1(new WaterPumpDevice(WATER_PUMP_FILTER, adapter1));

  ASSERT_EQ(ERROR_NO, water_pump_mediator_->RegisterWaterPumpDevice(water_pump1));
  ASSERT_EQ(ERROR_NO, water_pump_mediator_->UnregisterWaterPumpDevice(WATER_PUMP_FILTER));
}

TEST_F(TestUtWaterPumpMediator, Register_Water_Pump_Device_Twice) {
  std::shared_ptr<WaterPumpDeviceAdapterInterface> adapter1(new NiceMock<MockedWaterPumpDeviceAdapter>);
  std::shared_ptr<WaterPumpDeviceInterface> water_pump1(new WaterPumpDevice(WATER_PUMP_FILTER, adapter1));

  ASSERT_EQ(ERROR_NO, water_pump_mediator_->RegisterWaterPumpDevice(water_pump1));
  ASSERT_EQ(ERROR_BUSY, water_pump_mediator_->RegisterWaterPumpDevice(water_pump1));
}

TEST_F(TestUtWaterPumpMediator, Unregister_Water_Pump_Device_Twice) {
  std::shared_ptr<WaterPumpDeviceAdapterInterface> adapter1(new NiceMock<MockedWaterPumpDeviceAdapter>);
  std::shared_ptr<WaterPumpDeviceInterface> water_pump1(new WaterPumpDevice(WATER_PUMP_FILTER, adapter1));
  ASSERT_EQ(ERROR_NO, water_pump_mediator_->RegisterWaterPumpDevice(water_pump1));

  ASSERT_EQ(ERROR_NO, water_pump_mediator_->UnregisterWaterPumpDevice(WATER_PUMP_FILTER));
  ASSERT_EQ(ERROR_INVALID_INDEX, water_pump_mediator_->UnregisterWaterPumpDevice(WATER_PUMP_FILTER));
}

}  // namespace test_ut
