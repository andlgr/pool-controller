/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 14, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#include "common/assert/assert.h"
#include "device/led/led_device.h"

struct LedDevice::Impl {
  Impl(led_id_t id, std::shared_ptr<LedDeviceAdapterInterface> adapter)
      : adapter_(adapter),
        id_(id),
        state_(LED_STATE_OFF),
        initialized_(false) {
  }
  std::shared_ptr<LedDeviceAdapterInterface> adapter_;
  led_id_t id_;
  led_state_t state_;
  bool initialized_;
};

LedDevice::LedDevice(led_id_t id, std::shared_ptr<LedDeviceAdapterInterface> adapter)
    : impl_(new LedDevice::Impl(id, adapter)) {
}

LedDevice::~LedDevice() {
  delete impl_;
}

error_t LedDevice::Init() {
  if (impl_->initialized_) {
    return ERROR_ALREADY;
  }

  if (nullptr == impl_->adapter_) {
    return ERROR_INVALID_DEPENDENCY;
  }

  ASSERT_ERROR_NO(impl_->adapter_->SetPinState(false));
  impl_->state_ = LED_STATE_OFF;

  impl_->initialized_ = true;

  return ERROR_NO;
}

error_t LedDevice::Finish() {
  if (!impl_->initialized_) {
    return ERROR_INIT;
  }

  ASSERT_ERROR_NO(impl_->adapter_->SetPinState(false));
  impl_->state_ = LED_STATE_OFF;

  impl_->initialized_ = false;

  return ERROR_NO;
}

error_t LedDevice::SetState(led_state_t state) {
  if (!impl_->initialized_) {
    return ERROR_INIT;
  }

  if (state == impl_->state_) {
    return ERROR_ALREADY;
  }

  switch (state) {
    case LED_STATE_BLINK_FAST:
    case LED_STATE_BLINK_SLOW:
      return ERROR_UNIMPLEMENTED_OPERATION;
    case LED_STATE_ON:
      ASSERT_ERROR_NO(impl_->adapter_->SetPinState(true));
      break;
    case LED_STATE_OFF:
      ASSERT_ERROR_NO(impl_->adapter_->SetPinState(false));
      break;
    default:
      return ERROR_INVALID_INDEX;
  }

  impl_->state_ = state;

  return ERROR_NO;
}

error_t LedDevice::GetState(led_state_t *state) {
  if (!impl_->initialized_) {
      return ERROR_INIT;
  }

  ASSERT_VALID_POINTER(state);
  *state = impl_->state_;
  return ERROR_NO;
}

const led_id_t& LedDevice::id() {
  return impl_->id_;
}
