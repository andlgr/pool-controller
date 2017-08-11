/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 14, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#include "include/common/assert/assert.h"
#include "include/device/led/led_device.h"

struct LedDevice::Impl {
  Impl(led_id_t id, std::shared_ptr<LedDeviceAdapterInterface> adapter)
      : adapter_(adapter),
        id_(id),
        state_(LED_STATE_OFF) {
  }
  std::shared_ptr<LedDeviceAdapterInterface> adapter_;
  led_id_t id_;
  led_state_t state_;
};

LedDevice::LedDevice(led_id_t id, std::shared_ptr<LedDeviceAdapterInterface> adapter)
    : impl_(new LedDevice::Impl(id, adapter)) {
  // Initialize device, so we can rely on cache value
  impl_->adapter_->SetPinState(LED_STATE_OFF == impl_->state_ ? false : true);
}

LedDevice::~LedDevice() {
  delete impl_;
}

error_t LedDevice::SetState(led_state_t state) {
  // TODO(areis): Implement blink states
  ASSERT_ERROR_NO(impl_->adapter_->SetPinState(LED_STATE_OFF == state ? false : true));
  impl_->state_ = state;
  return ERROR_NO;
}

error_t LedDevice::GetState(led_state_t *state) {
  ASSERT_VALID_POINTER(state);
  *state = impl_->state_;
  return ERROR_NO;
}

const led_id_t& LedDevice::id() {
  return impl_->id_;
}
