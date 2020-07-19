/*
 * File: HashTable.cpp
 * Project: data-struct
 * File Created: Monday, 22nd June 2020 5:55:55 pm
 * Author: Alex
 * -----
 * Last Modified: Monday, 22nd June 2020 5:57:39 pm
 * Modified By: Alex
 * -----
 * Copyright - 2020 oneself
 */

#include <memory>
#include "HashTable.h"
#include "HashTableFunc.hpp"
#include "base/Release.hpp"

template<typename K, typename V>
HashTable<K, V>::HashTable(int initialCapacity)
  : capacity_(initialCapacity)
  , lazyRemoval_(initialCapacity, false) {
  // here we do guarantee capacity_ is a prime
  buckets_ = new HashTable<K, V>*[capacity_];
  count_ = 0;
  memset(buckets_, 0, sizeof(Entry<K, V>*) * M);
}

template<typename K, typename V>
int HashTable<K, V>::size() const {
  return count_;
}

template<typename K, typename V>
bool HashTable<K, V>::put(K key, V value) {
  if (buckets_[probe4Hit(key)] != nullptr) {
    return false;
  }
  int index = probe4Free(key);
  buckets_[index] = new Entry(key, value);
  ++count_;
  if (count_*2 > capacity_) {
    rehash();
  }
  return true;
}

template<typename K, typename V>
V* HashTable<K, V>::get(K key) {
  int index = probe4Hit(key);
  return buckets_[index] == nullptr ? nullptr : &buckets[index]->value;
}

template<typename K, typename V>
bool HashTable<K, V>::remove(K key) {
  int index = probe4Hit(key);
  if (buckets_[index] == nullptr) return false;
  release(buckets_[index]);
  buckets_[index] = nullptr;
  --count_;
  lazyRemoval_[index] = true;
  return true;
}

template<typename K, typename V>
void HashTable<K, V>::rehash() {
  int oldCapacity = capacity_;
  Entry<K, V>** oldBuckets = buckets_;
  capacity_ = getNearestPrime(2*capacity_);
  memset(buckets_, 0, sizeof(Entry<K, V>*) * capacity_);
  lazyRemoval_.clear();
  lazyRemoval_.resize(capacity_, false);
  for (int i = 0; i < oldCapacity; ++i) {
    if (oldCapacity[i]) {
      put(oldCapacity[i]->key, oldCapacity[i]->value);
    }
  }
  release(oldCapacity);
}

// follow the key-value
// liner-probe
template<typename K, typename V>
int HashTable<K, V>::probe4Hit(const K& key) {
  int index = hashCode(key) % capacity_;
  while ((buckets_[index] && (key != bucket_[index]->Key)) || (!buckets_[index] && lazyRemoval_[index])) {
    index = (index + 1) % M;
  }
  return index;
}

template<typename K, typename V>
int HashTable<K, V>::probe4Free(const K& key) {
  int index = hashCode(key) % capacity_;
  while (!buckets_[index]) {
    index = (index + 1) % capacity_;
  }
  return index;
}

