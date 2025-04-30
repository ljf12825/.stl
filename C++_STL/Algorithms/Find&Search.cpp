#include <iostream>
#include <algorithm>

//find
//查找等于某值的元素
template<class InputIt, class T>
InputIt find(InputIt first, InputIt last, const T& value);
//[first, last)
//value:目标值
//返回值：指向第一个匹配元素的迭代器，如果找不到就返回last
//O(n)

//find_if
//查找满足某条件的第一个元素
template<class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p);
//返回值：指向第一个满足条件的元素的迭代器，如果没找到，返回last

//find_if_not
//查找第一个不满足某条件的元素

//search
//在序列中查找子序列
template<class ForwardIt1, class ForwardIt2>
ForwardIt1 search(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2, ForwardIt2 last2);
//first1, last1:主序列
//first2, last2:子序列
//返回值：指向子序列第一次出现的位置的起点迭代器，如果没有找到，返回last
//可自定义判断相等
template<class ForwardIt1, class ForwardIt2, class BinaryPredicate>
ForwardIt1 search(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2, ForwardIt2 last2, BinaryPredicate p);

//binary_search
//判断已排序序列是否包含某个值
//使用二分查找判断一个值是否存在于一个有序序列中
//被查找的范围必须是已排序的（升序或按定义规则），否则结果未定义
//O(log n)
template<class ForwardIt, class T>
bool binary_search(ForwardIt first, ForwardIt last, const T& value);
//重载
//传入自定义比较器
template<class ForwardIt, class T, class Compare>
bool binary_search(ForwardIt first, ForwardIt last, const T& value, Compare comp);