/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 14, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_ASSERT_ASSERT_H
#define INCLUDE_COMMON_ASSERT_ASSERT_H

#include "common/error/error.h"

#define ASSERT_ERROR_NO(fcall__)                      \
do {                                                  \
  error_t err = ERROR_NO;                             \
  if (ERROR_NO != (err = fcall__)) {                  \
    fprintf(stderr, "Error calling \"%s\": %s\n",     \
            #fcall__, error_to_string(err).c_str());  \
    return err;                                       \
  }                                                   \
} while (0);                                          \

#define ASSERT_VALID_POINTER(ptr__)                   \
do {                                                  \
  if (nullptr == ptr__) {                             \
    fprintf(stderr, "Invalid pointer detected\n");    \
    return ERROR_INVALID_POINTER;                     \
  }                                                   \
} while (0);                                          \

#endif  // INCLUDE_COMMON_ASSERT_ASSERT_H
