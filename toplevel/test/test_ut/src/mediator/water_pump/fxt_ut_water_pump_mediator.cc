/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 13, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "test_ut/include/mediator/water_pump/fxt_ut_water_pump_mediator.h"

namespace test_ut {

TestUtWaterPumpMediator::TestUtWaterPumpMediator() {
}

TestUtWaterPumpMediator::~TestUtWaterPumpMediator() {
}

void TestUtWaterPumpMediator::SetUpTestCase() {
}

void TestUtWaterPumpMediator::TearDownTestCase() {
}

void TestUtWaterPumpMediator::SetUp() {
  water_pump_mediator_.reset(new WaterPumpMediator());
}

void TestUtWaterPumpMediator::TearDown() {
  water_pump_mediator_.reset();
}

}  // namespace test_ut
