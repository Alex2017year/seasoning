/*
 * File: utils.h
 * Project: utils
 * File Created: Monday, 22nd June 2020 10:48:24 am
 * Author: Alex
 * -----
 * Last Modified: Monday, 22nd June 2020 12:08:51 pm
 * Modified By: Alex
 * -----
 * Copyright - 2020 oneself
 */

#ifndef UTIL_UTILS_HPP_
#define UTIL_UTILS_HPP_

#include <random>
std::default_random_engine& global_urng() {
  static std::default_random_engine u{};
  return u;
}

int randomize(int low, int high) {
  static std::uniform_int_distribution<> d{};
  using parm_t = decltype(d)::param_type;
  return d(global_urng(), parm_t{low, high});
}



#endif  // UTIL_UTILS_HPP_
