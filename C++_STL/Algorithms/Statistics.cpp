#include <iostream>
#include <algorithm>

//count
//统计某个值的数量
template <class InputIt, class T>
typename std::iterator_traits<InputIt>::difference_type
count(InputIt first, InputIt last, const T& value);

//count_if
//统计满足某条件的数量
template <class InputIt, class UnaryPredicate>
typename std::iterator_traits<InputIt>::difference_type
count_if(InputIt first, InputIt last, UnaryPredicate p);
//p:一元谓词，返回true表示该元素应被统计

//min_element
//找最小元素
template <class ForwardIt>
ForwardIt min_element(ForwardIt first, ForwardIt last);

template <class ForwardIt, class Compare>
ForwardIt min_element(ForwardIt first, ForwardIt last, Compare comp);


//max_element
//找最大元素
template <class ForwardIt>
ForwardIt max_element(ForwardIt first, ForwardIt last);

template <class ForwardIt, class Compare>
ForwardIt max_element(ForwardIt first, ForwardIt last, Compare comp);


//equal
//判断两个区间是否相等
//逐元素相等
// 版本 1：比较两个范围的每个元素是否相等
template <class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);

// 版本 2：自定义比较方式
template <class InputIt1, class InputIt2, class BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p);
