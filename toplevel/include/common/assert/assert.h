/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 14, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_ASSERT_ASSERT_H
#define INCLUDE_COMMON_ASSERT_ASSERT_H

#include "common/error/error.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define ASSERT_ERROR_NO(fcall__)                                    \
do {                                                                \
  error_t err = ERROR_NO;                                           \
  if (ERROR_NO != (err = fcall__)) {                                \
    fprintf(stderr, ANSI_COLOR_RED                                  \
                    "[%s:%d] Error calling \"%s\": %s.\n"           \
                    ANSI_COLOR_RESET,                               \
            __FILE__, __LINE__,                                     \
            #fcall__, error_to_string(err).c_str());                \
    return err;                                                     \
  }                                                                 \
} while (0);                                                        \

#define ASSERT_VALID_POINTER(ptr__)                                 \
do {                                                                \
  if (nullptr == ptr__) {                                           \
    fprintf(stderr, ANSI_COLOR_RED                                  \
                    "[%s:%d] Invalid pointer detected at \"%s\".\n" \
                    ANSI_COLOR_RESET,                               \
            __FILE__, __LINE__,                                     \
            #ptr__);                                                \
    return ERROR_INVALID_POINTER;                                   \
  }                                                                 \
} while (0);                                                        \

#define ARG_FUTURE_USE(arg__)                                       \
do {                                                                \
  (void)arg__;                                                      \
} while (0);                                                        \

#endif  // INCLUDE_COMMON_ASSERT_ASSERT_H
