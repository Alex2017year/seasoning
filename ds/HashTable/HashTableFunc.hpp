/*
 * File: HashTableFunc.hpp
 * Project: data-struct
 * File Created: Monday, 22nd June 2020 5:55:55 pm
 * Author: Alex
 * -----
 * Last Modified: Monday, 22nd June 2020 5:57:39 pm
 * Modified By: Alex
 * -----
 * Copyright - 2020 oneself
 */

#ifndef DS_HASHTABLE_HASHTABLEFUNC_HPP_
#define DS_HASHTABLE_HASHTABLEFUNC_HPP_

#include <algorithm>
#include <cstring>

// just a demo, must add size of array
enum { MAX_PRIME_SZIE = 14 };
static const unsigned _stl_prime_list[MAX_PRIME_SZIE] = {
  53,         97,         193,       389,       769,
  1543,       3079,       6151,      12289,     24593,
  49157,      98317,      196613,    393241
};


inline unsigned getNearestPrime(unsigned x) {
  const unsigned *first = _stl_prime_list;
  auto result = std::lower_bound(first, first+MAX_PRIME_SZIE, x);
  return result == first+MAX_PRIME_SZIE ? *(first+MAX_PRIME_SZIE-1) : *result;
}

static size_t hashCode(char c) {
  return static_cast<size_t>(c);
}

static size_t hashCode(int k) {
  return static_cast<size_t>(k);
}

static size_t hashCode(long long i) {
  return static_cast<size_t>(i >> 32 + static_cast<size_t>(i));
}

static size_t hashCode(char s[]) {
  unsigned int h = 0;
  for (size_t n = strlen(s), i = 0; i < n; ++i) {
    h = (h << 5) | (h >> 27);
    h += static_cast<unsigned int>(s[i]);
  }
  return static_cast<size_t>(h);
}

#endif  // DS_HASHTABLE_HASHTABLEFUNC_HPP_
