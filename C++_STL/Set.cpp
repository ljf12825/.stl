#include <iostream>
#include <set>
//std::set
//关联容器
//底层红黑树
//自动排序（默认使用<比较）
//元素唯一
//插入、查找、删除的时间复杂度为O(log n)
std::set<int> s = { 3, 1, 4, 2 };//内部会自动排成1234
//set存在的意义
//去重 + 排序 + 快速查找

//底层实现
template <typename Key, typename Compare = std::less<Key>, typename Alloc = std::allocator<Key>>
class set;