/**
 * MIT License
 * Copyright (c) 2017 Andre Reis
 *
 * Created on: Aug 10, 2017
 *     Author: Andre Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_ERROR_ERROR_H
#define INCLUDE_COMMON_ERROR_ERROR_H

#include <string>

typedef enum {
  ERROR_NO = 0,
  ERROR_FAIL,
  ERROR_INVALID_POINTER,
  ERROR_ALREADY,
  ERROR_INVALID_DEPENDENCY,
} error_t;

static std::string error_to_string(error_t err) {
  switch (err) {
    case ERROR_NO:                 return std::string("ERROR_NO");
    case ERROR_FAIL:               return std::string("ERROR_FAIL");
    case ERROR_INVALID_POINTER:    return std::string("ERROR_INVALID_POINTER");
    case ERROR_ALREADY:            return std::string("ERROR_ALREADY");
    case ERROR_INVALID_DEPENDENCY: return std::string("ERROR_INVALID_DEPENDENCY");
    default:                       return std::string("Unknown error");
  }
}

#endif  // INCLUDE_COMMON_ERROR_ERROR_H
