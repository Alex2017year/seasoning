/*
 * File: Dictionary.h
 * Project: data-struct
 * File Created: Monday, 22nd June 2020 5:55:55 pm
 * Author: Alex
 * -----
 * Last Modified: Monday, 22nd June 2020 5:57:39 pm
 * Modified By: Alex
 * -----
 * Copyright - 2020 oneself
 */

#ifndef DS_HASHTABLE_DICTIONARY_H_
#define DS_HASHTABLE_DICTIONARY_H_

template<typename K, typename V>
struct Dictionary {
  virtual int size() const = 0;
  virtual bool put(K key, V value) = 0;
  virtual V* get(K key) = 0;
  virtual bool remove(K key) = 0;
};

#endif  // DS_HASHTABLE_DICTIONARY_H_
