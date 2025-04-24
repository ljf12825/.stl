#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <stdexcept>
//priority_queue(优先队列)
std::priority_queue<int> pq;
//std::priority_queue是STL中一个容器适配器
//它的特点是：它实现的是一个最大堆（默认情况下），即：你每次访问或移除的都是当前“优先级最高”的元素

//基本操作
//push() 插入一个元素 O(log n)
//pop() 删除队首元素 O(log n)
//top() 返回队首元素 O(1)
//empty()
//size()

//底层实现
template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
class priority_queue;
//T数据类型
//Container底层容器，默认为std::vector<T>
//Compare比较器，默认为std::less<T>(即最大堆)
//可以通过传入std::greater<T>来构建最小堆
//底层操作函数主要是以下几个：
//std::make_heap 建堆
//std::push_head 插入元素后上浮
//std::pop_head 移除堆顶元素并下沉
//std::sort_heap 排序堆
