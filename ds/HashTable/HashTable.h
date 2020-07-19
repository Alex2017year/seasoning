/*
 * File: HashTable.h
 * Project: data-struct
 * File Created: Monday, 22nd June 2020 5:55:55 pm
 * Author: Alex
 * -----
 * Last Modified: Monday, 22nd June 2020 5:57:39 pm
 * Modified By: Alex
 * -----
 * Copyright - 2020 oneself
 */

#ifndef DS_HASHTABLE_HASHTABLE_H_
#define DS_HASHTABLE_HASHTABLE_H_

#include <vector>
#include "Dictionary.h"
#include "Entry.h"

/**
 * 1. C++ stl sgi-stl v3.3 实现中，采用了开链策略来实现hash碰撞规避
 * 
 * 2. java 实现的方法：也是采用开链策略实现 hashtable
 * 
 * demo: 
 * 散列的要点：
 *  评价标准：
 *  1. 确定性：同一关键码总是被映射到同一地址
 *  2. 快速：期望 O(1)
 *  3. 满射：尽可能充分地覆盖整个散列空间
 *  4. 均匀： 关键码映射到散列表各个位置的概率尽量接近，可有效避免聚集(clustering)现象
 * A. 散列函数的设计
 *  a. 除余法 (key % M), M必须为素数 【对于理想随机的序列，表长是否为素数，无关紧要】，避免聚集
 *  b. MAD [ hash(key) = (a*key + b)%M, M prime, a>1, b>0 ]
 *  c. 更多散列函数：
 *    数字分析
 *    平方取中
 *    折叠法
 *    位异或法
 *    伪随机数发生器 -- 可移植性差
 *    多项式法 == 字符串的hash法
 * 
 * B. 散列表的设计 & 如何解决散列中的冲突
 *  a. 开放散列
 *    开辟物理地址连续的桶数组，散列表不断扩张，其冲突解决方案如下：
 *    a1. 多槽位法（有效空间）
 *      也就是每一条词条，放置有限的空间。
 *      [ ][ ][ ][ ][ ][ ][ ][ ]
 *      [ ][ ][ ][ ][ ][ ][ ][ ]
 *      [0][1][2][3][4][5][6][7]
 *      每个索引处还有一组有效的空间，一旦发生冲突，就在后面继续添加。这种做法很局限，一般采用vector
 *    a2. 独立链法
 *      [ ][ ][ ][ ][ ][ ][ ][ ]
 *     p11 p21 p31 p41 p51 p61 p71
 *      [ ][ ][ ][ ][ ][ ][ ][ ]
 *      p1 p2 p2 p3 p4 p5 p6 p7
 *      [0][1][2][3][4][5][6][7]
 *      与多槽位法不同之处在于，使用了链表来解决冲突问题 -- Java/C++ 库采用这种方法
 *    a3. 公共溢出区法
 *     原始散列：[ ][ ][ ][ ][ ][ ][ ][ ]
 *     overflow：[ ][ ][ ][ ]
 *     将溢出的散列依次放入overflow中
 *  b. 闭合散列（开放散列定址法）
 *    也就是散列表空间足够大，填充因子一般<0.5(也不是绝对的，取决于采用什么样的冲突解决方法)
 *    b1. 线性试探 -- 数据堆积现象严重，但是数据局部性良好
 *    b2. 平方试探法 -- 解决数据堆积现象而发明的，（装载因子<0.5）M为素数 - M为散列表的容量
 *    b3. 双向平方试探法（M为素数，且满足 m=4*k+3）
 *    b4. 再散列
 * 
 * 采用闭散列策略，且使用了线性试探法完成
*/
template<typename K, typename V>
class HashTable : public Dictionary {
 public:
  explicit HashTable(int initialCapacity = 11);  // refer to java default value of capacity
  ~HashTable();

  int size() const override;
  bool put(K key, V value) override;
  V* get(K key) override;
  bool remove(K key) override;

 protected:
  void rehash();
  int probe4Hit(const K& key);
  int probe4Free(const K& key);

 private:
  bool lazilyRemoved();

 private:
  Entry<K, V>** buckets_;  // save data bucket, two dimensional array
  int capacity_;  // capacity of buckets
  int count_;  // The total number of entries in the hash table
  std::vector<bool> lazyRemoval_;  // marked as deleted elements
};

#endif  // DS_HASHTABLE_HASHTABLE_H_
