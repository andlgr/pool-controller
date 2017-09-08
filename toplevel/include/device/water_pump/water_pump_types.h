/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 7, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_TYPES_H
#define INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_TYPES_H

typedef enum {
  WATER_PUMP_ID_INVALID = 0,
  WATER_PUMP_NONE,
  WATER_PUMP_FILTER,
  WATER_PUMP_HEATER,
  WATER_PUMP_ID_MAX
} water_pump_id_t;

#endif  // INCLUDE_DEVICE_WATER_PUMP_WATER_PUMP_TYPES_H
