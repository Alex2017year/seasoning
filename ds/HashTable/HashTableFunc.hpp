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



#endif  // DS_HASHTABLE_HASHTABLEFUNC_HPP_
