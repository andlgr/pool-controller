/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 14, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_ASSERT_ASSERT_H
#define INCLUDE_COMMON_ASSERT_ASSERT_H

#include <stdio.h>
#include "common/error/error.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define TRACE_ARG_ERROR(msg__, args__...)                           \
do {                                                                \
  fprintf(stderr, ANSI_COLOR_RED                                    \
                  "[%s:%d] "                                        \
                  msg__                                             \
                  ".\n"                                             \
                  ANSI_COLOR_RESET,                                 \
          __FILE__, __LINE__,                                       \
          args__);                                                  \
} while (0);                                                        \

#define TRACE_ARG_WARNING(msg__, args__...)                         \
do {                                                                \
  fprintf(stderr, ANSI_COLOR_YELLOW                                 \
                  "[%s:%d] "                                        \
                  msg__                                             \
                  ".\n"                                             \
                  ANSI_COLOR_RESET,                                 \
          __FILE__, __LINE__,                                       \
          args__);                                                  \
} while (0);                                                        \

#define TRACE_ARG_OK(msg__, args__...)                              \
do {                                                                \
  fprintf(stderr, ANSI_COLOR_GREEN                                  \
                  "[%s:%d] "                                        \
                  msg__                                             \
                  ".\n"                                             \
                  ANSI_COLOR_RESET,                                 \
          __FILE__, __LINE__,                                       \
          args__);                                                  \
} while (0);                                                        \

#define TRACE_ERROR(msg__)                                          \
do {                                                                \
  fprintf(stderr, ANSI_COLOR_RED                                    \
                  "[%s:%d] %s.\n"                                   \
                  ANSI_COLOR_RESET,                                 \
          __FILE__, __LINE__,                                       \
          msg__);                                                   \
} while (0);                                                        \

#define TRACE_WARNING(msg__)                                        \
do {                                                                \
  fprintf(stderr, ANSI_COLOR_YELLOW                                 \
                  "[%s:%d] %s.\n"                                   \
                  ANSI_COLOR_RESET,                                 \
          __FILE__, __LINE__,                                       \
          msg__);                                                   \
} while (0);                                                        \

#define TRACE_OK(msg__)                                             \
do {                                                                \
  fprintf(stderr, ANSI_COLOR_GREEN                                  \
                  "[%s:%d] %s.\n"                                   \
                  ANSI_COLOR_RESET,                                 \
          __FILE__, __LINE__,                                       \
          msg__);                                                   \
} while (0);                                                        \

#define ASSERT_ERROR_NO(fcall__)                                    \
do {                                                                \
  error_t err = fcall__;                                            \
  if (ERROR_NO != err) {                                            \
    fprintf(stderr, ANSI_COLOR_RED                                  \
                    "[%s:%d] Error calling \"%s\": %s.\n"           \
                    ANSI_COLOR_RESET,                               \
            __FILE__, __LINE__,                                     \
            #fcall__, error_to_string(err).c_str());                \
    return err;                                                     \
  }                                                                 \
} while (0);                                                        \

#define ASSERT_ERROR_NO_ALREADY(fcall__)                            \
do {                                                                \
  error_t err = fcall__;                                            \
  if ((ERROR_NO != err) && (ERROR_ALREADY != err)) {                \
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
