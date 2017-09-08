/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 7, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include "device/water_pump/water_pump_device.h"
#include "common/assert/assert.h"

struct WaterPumpDevice::Impl {
  Impl(water_pump_id_t id, std::shared_ptr<WaterPumpDeviceAdapterInterface> adapter)
      : adapter_(adapter),
        id_(id),
        state_(false),
        initialized_(false) {
  }
  std::shared_ptr<WaterPumpDeviceAdapterInterface> adapter_;
  water_pump_id_t id_;
  bool state_;
  bool initialized_;
};

WaterPumpDevice::WaterPumpDevice(water_pump_id_t id, std::shared_ptr<WaterPumpDeviceAdapterInterface> adapter)
    : impl_(new WaterPumpDevice::Impl(id, adapter)) {
}

WaterPumpDevice::~WaterPumpDevice() {
  delete impl_;
}

error_t WaterPumpDevice::Init() {
  if (impl_->initialized_) {
    return ERROR_ALREADY;
  }

  if (nullptr == impl_->adapter_) {
    return ERROR_INVALID_DEPENDENCY;
  }

  ASSERT_ERROR_NO(impl_->adapter_->Init());

  ASSERT_ERROR_NO(impl_->adapter_->SetPinState(false));
  impl_->state_ = false;

  impl_->initialized_ = true;

  return ERROR_NO;
}

error_t WaterPumpDevice::Finish() {
  if (!impl_->initialized_) {
    return ERROR_INIT;
  }

  ASSERT_ERROR_NO(impl_->adapter_->SetPinState(false));
  impl_->state_ = false;

  ASSERT_ERROR_NO(impl_->adapter_->Finish());

  impl_->initialized_ = false;

  return ERROR_NO;
}

error_t WaterPumpDevice::TurnOn() {
  if (!impl_->initialized_) {
    return ERROR_INIT;
  }

  if (true == impl_->state_) {
    return ERROR_ALREADY;
  }

  ASSERT_ERROR_NO(impl_->adapter_->SetPinState(true));

  impl_->state_ = true;

  return ERROR_NO;
}

error_t WaterPumpDevice::TurnOff() {
  if (!impl_->initialized_) {
    return ERROR_INIT;
  }

  if (false == impl_->state_) {
    return ERROR_ALREADY;
  }

  ASSERT_ERROR_NO(impl_->adapter_->SetPinState(false));

  impl_->state_ = false;

  return ERROR_NO;
}

error_t WaterPumpDevice::GetState(bool *is_on) {
  if (!impl_->initialized_) {
      return ERROR_INIT;
  }

  ASSERT_VALID_POINTER(is_on);
  *is_on = impl_->state_;
  return ERROR_NO;
}

const water_pump_id_t& WaterPumpDevice::id() {
  return impl_->id_;
}
