/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 28, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include <map>
#include "common/mutex/mutex.h"
#include "common/assert/assert.h"
#include "controller/led/led_controller.h"

struct LedController::Impl {
  Impl()
      : leds_(),
        mutex_() {
  }
  typedef std::map<led_id_t, std::shared_ptr<LedDeviceInterface>> led_map_t;
  typedef std::map<led_id_t, std::shared_ptr<LedDeviceInterface>>::iterator led_map_iterator_t;
  led_map_t leds_;
  std::shared_timed_mutex mutex_;
};

LedController::LedController()
    : impl_(new LedController::Impl()) {
}

LedController::~LedController() {
  delete impl_;
}

error_t LedController::SetState(led_id_t id, led_state_t state) {
  write_lock(impl_->mutex_);

  Impl::led_map_iterator_t it;

  it = impl_->leds_.find(id);

  if (impl_->leds_.end() == it) {
    return ERROR_INVALID_INDEX;
  }

  ASSERT_VALID_POINTER(it->second);
  ASSERT_ERROR_NO(it->second->SetState(state));

  return ERROR_NO;
}

error_t LedController::GetState(led_id_t id, led_state_t *state) {
  ASSERT_VALID_POINTER(state);

  read_lock(impl_->mutex_);

  Impl::led_map_iterator_t it;

  it = impl_->leds_.find(id);

  if (impl_->leds_.end() == it) {
    return ERROR_INVALID_INDEX;
  }

  ASSERT_VALID_POINTER(it->second);
  ASSERT_ERROR_NO(it->second->GetState(state));

  return ERROR_NO;
}

error_t LedController::RegisterLedDevice(std::shared_ptr<LedDeviceInterface> led_device) {
  ASSERT_VALID_POINTER(led_device.get());

  write_lock(impl_->mutex_);

  Impl::led_map_iterator_t it;

  it = impl_->leds_.find(led_device->id());

  if (impl_->leds_.end() != it) {
    return ERROR_BUSY;
  }

  ASSERT_ERROR_NO(led_device->Init());

  impl_->leds_[led_device->id()] = led_device;

  return ERROR_NO;
}

error_t LedController::UnregisterLedDevice(led_id_t id) {
  write_lock(impl_->mutex_);

  Impl::led_map_iterator_t it;

  it = impl_->leds_.find(id);

  if (impl_->leds_.end() == it) {
    return ERROR_INVALID_INDEX;
  }

  ASSERT_VALID_POINTER(it->second);
  ASSERT_ERROR_NO(it->second->Finish());

  impl_->leds_.erase(it);

  return ERROR_NO;
}
