/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 10, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_DEVICE_LED_LED_TYPE_H
#define INCLUDE_DEVICE_LED_LED_TYPE_H

typedef enum {
  LED_ID_INVALID = 0,
  LED_ID_1,
  LED_ID_2,
  LED_ID_3,
  LED_ID_4,
  LED_ID_MAX
} led_id_t;

typedef enum {
  LED_STATE_INVALID,
  LED_STATE_ON,
  LED_STATE_BLINK_FAST,
  LED_STATE_BLINK_SLOW,
  LED_STATE_OFF,
  LED_STATE_MAX
} led_state_t;

#endif  // INCLUDE_DEVICE_LED_LED_TYPE_H
