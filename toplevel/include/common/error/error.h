/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Aug 10, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_ERROR_ERROR_H
#define INCLUDE_COMMON_ERROR_ERROR_H

#include <errno.h>
#include <string>

typedef int error_t;

#define ERROR_NO                      (-0)
#define ERROR_FAIL                    (-1)
#define ERROR_INIT                    (-2)
#define ERROR_MALLOC                  (-3)
#define ERROR_INVALID_POINTER         (-4)
#define ERROR_ALREADY                 (-5)
#define ERROR_INVALID_DEPENDENCY      (-6)
#define ERROR_UNIMPLEMENTED_OPERATION (-7)
#define ERROR_INVALID_INDEX           (-8)
#define ERROR_BUSY                    (-9)

static __attribute__((unused)) std::string error_to_string(error_t err) {
  switch (err) {
    case ERROR_NO:                      return std::string("ERROR_NO");
    case ERROR_FAIL:                    return std::string("ERROR_FAIL");
    case ERROR_INIT:                    return std::string("ERROR_INIT");
    case ERROR_MALLOC:                  return std::string("ERROR_MALLOC");
    case ERROR_INVALID_POINTER:         return std::string("ERROR_INVALID_POINTER");
    case ERROR_ALREADY:                 return std::string("ERROR_ALREADY");
    case ERROR_INVALID_DEPENDENCY:      return std::string("ERROR_INVALID_DEPENDENCY");
    case ERROR_UNIMPLEMENTED_OPERATION: return std::string("ERROR_UNIMPLEMENTED_OPERATION");
    case ERROR_INVALID_INDEX:           return std::string("ERROR_INVALID_INDEX");
    case ERROR_BUSY:                    return std::string("ERROR_BUSY");
    default:                            return std::string("Unknown error");
  }
}

#endif  // INCLUDE_COMMON_ERROR_ERROR_H
