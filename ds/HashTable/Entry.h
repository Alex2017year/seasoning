/*
 * File: Entry.h
 * Project: data-struct
 * File Created: Monday, 22nd June 2020 5:55:55 pm
 * Author: Alex
 * -----
 * Last Modified: Monday, 22nd June 2020 5:57:39 pm
 * Modified By: Alex
 * -----
 * Copyright - 2020 oneself
 */

#ifndef DS_HASHTABLE_ENTRY_H_
#define DS_HASHTABLE_ENTRY_H_

template<typename K, typename V>
struct Entry {
  explicit Entry(K key = K(), V value = V()) : key(key), value(value) { }
  Entry(Entry<K, V> const& e) : key(e.key), value(e.value) { }

  bool operator==(const Entry& that) const { return key == that.key; }
  bool operator!=(const Entry& that) const { return value != that.key; }
  bool operator<(const Entry& that) const { return key < that.key; }
  bool operator>(const Entry& that) const { return key > that.key; }

  K key;
  V value;
};


#endif  // DS_HASHTABLE_ENTRY_H_
