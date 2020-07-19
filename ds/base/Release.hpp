/*
 * File: Release.h
 * Project: data-struct
 * File Created: Monday, 22nd June 2020 5:55:55 pm
 * Author: Alex
 * -----
 * Last Modified: Monday, 22nd June 2020 5:57:39 pm
 * Modified By: Alex
 * -----
 * Copyright - 2020 oneself
 */

#ifndef DS_BASE_RELEASE_HPP_
#define DS_BASE_RELEASE_HPP_


template <typename T>
struct TraitsHelper {
  static const bool is_pointer = false;
};

template <typename T>
struct TraitsHelper<T*> {
  static const bool is_pointer = true;
};


template <typename T>
void release(T x) {
  if (TraitsHelper<T>::is_pointer) {
    delete x;
  }
}

#endif  // DS_BASE_RELEASE_HPP_
