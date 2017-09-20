/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 12, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#include <map>
#include "common/mutex/mutex.h"
#include "common/assert/assert.h"
#include "mediator/water_pump/water_pump_mediator.h"

struct WaterPumpMediator::Impl {
  Impl()
      : active_pump_(WATER_PUMP_ID_NONE),
        water_pumps_(),
        recursive_mutex_() {
  };
  typedef std::map<water_pump_id_t, std::shared_ptr<WaterPumpDeviceInterface>> water_pump_t;
  typedef std::map<water_pump_id_t, std::shared_ptr<WaterPumpDeviceInterface>>::iterator water_pump_map_iterator_t;
  water_pump_id_t active_pump_;
  water_pump_t water_pumps_;
  std::recursive_timed_mutex recursive_mutex_;
};

WaterPumpMediator::WaterPumpMediator()
    : impl_(new WaterPumpMediator::Impl()) {
}

WaterPumpMediator::~WaterPumpMediator() {
  delete impl_;
}

error_t WaterPumpMediator::Activate(water_pump_id_t id) {
  recursive_lock(impl_->recursive_mutex_);

  if (id == impl_->active_pump_) {
    return ERROR_ALREADY;
  }

  ASSERT_ERROR_NO_ALREADY(this->Deactivate());

  Impl::water_pump_map_iterator_t it;

  it = impl_->water_pumps_.find(id);

  if (impl_->water_pumps_.end() == it) {
    return ERROR_INVALID_INDEX;
  }

  ASSERT_VALID_POINTER(it->second);
  ASSERT_ERROR_NO(it->second->TurnOn());

  impl_->active_pump_ = id;

  return ERROR_NO;
}

error_t WaterPumpMediator::Deactivate() {
  recursive_lock(impl_->recursive_mutex_);

  if (WATER_PUMP_ID_NONE == impl_->active_pump_) {
    return ERROR_ALREADY;
  }

  Impl::water_pump_map_iterator_t it;

  it = impl_->water_pumps_.find(impl_->active_pump_);

  if (impl_->water_pumps_.end() == it) {
    return ERROR_INVALID_INDEX;
  }

  ASSERT_VALID_POINTER(it->second);
  ASSERT_ERROR_NO(it->second->TurnOff());
  impl_->active_pump_ = WATER_PUMP_ID_NONE;

  return ERROR_NO;
}

error_t WaterPumpMediator::GetActive(water_pump_id_t *active_id) {
  ASSERT_VALID_POINTER(active_id);
  recursive_lock(impl_->recursive_mutex_);
  *active_id = impl_->active_pump_;
  return ERROR_NO;
}

error_t WaterPumpMediator::RegisterWaterPumpDevice(std::shared_ptr<WaterPumpDeviceInterface> water_pump_device) {
  ASSERT_VALID_POINTER(water_pump_device.get());

  recursive_lock(impl_->recursive_mutex_);

  Impl::water_pump_map_iterator_t it;

  it = impl_->water_pumps_.find(water_pump_device->id());

  if (impl_->water_pumps_.end() != it) {
    return ERROR_BUSY;
  }

  ASSERT_ERROR_NO(water_pump_device->Init());

  impl_->water_pumps_[water_pump_device->id()] = water_pump_device;

  return ERROR_NO;
}

error_t WaterPumpMediator::UnregisterWaterPumpDevice(water_pump_id_t id) {
  recursive_lock(impl_->recursive_mutex_);

  Impl::water_pump_map_iterator_t it;

  it = impl_->water_pumps_.find(id);

  if (impl_->water_pumps_.end() == it) {
    return ERROR_INVALID_INDEX;
  }

  ASSERT_VALID_POINTER(it->second);
  ASSERT_ERROR_NO(it->second->Finish());

  impl_->water_pumps_.erase(it);

  if (id == impl_->active_pump_) {
    impl_->active_pump_ = WATER_PUMP_ID_NONE;
  }

  return ERROR_NO;
}
