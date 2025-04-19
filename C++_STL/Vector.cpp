#include <iostream>
#include <vector>

//std::vector
//连续动态数组
//支持随机访问（O(1)）
//尾插快（O(1)）头插慢（O(n)）
//扩容机制：成倍增长，通常是1.5~2倍
//迭代器：RandomAccessIterator