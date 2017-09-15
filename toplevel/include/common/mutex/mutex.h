/**
 * MIT License
 * Copyright (c) 2017 André Reis
 *
 * Created on: Sep 14, 2017
 *     Author: André Reis <andre.lgr@gmail.com>
 */

#ifndef INCLUDE_COMMON_MUTEX_MUTEX_H
#define INCLUDE_COMMON_MUTEX_MUTEX_H

#include <shared_mutex>
#include <mutex>

#define write_lock(mutex__)     std::lock_guard<std::shared_timed_mutex>    lock(mutex__)
#define read_lock(mutex__)      std::shared_lock<std::shared_timed_mutex>   lock(mutex__)
#define unique_lock(mutex__)    std::unique_lock<std::shared_timed_mutex>   lock(mutex__)
#define recursive_lock(mutex__) std::lock_guard<std::recursive_timed_mutex> lock(mutex__)

#endif  // INCLUDE_COMMON_MUTEX_MUTEX_H
