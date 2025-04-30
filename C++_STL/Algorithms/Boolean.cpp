#include <iostream>
#include <algorithm>
#include <vector>

//partition
//将容器分成两部分
//一部分满足条件，另一部分不满足条件
//in-place
//不稳定
template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p);
//first, last：要操作的区间
//p:一元谓词（返回bool的函数或lambda），判断每个元素是否满足条件
//返回值：第一个不满足条件的元素的迭代器（即第二部分的起点）
//int main()
//{
//	std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
//
//	auto it = std::partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
//	//[begin it - 1][it end]//偶数在前
//
//	return 0;
//}
//希望保持稳定可以使用stable_partition

//all_of
//所有元素都满足条件
template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p);
//返回值：如果所有元素都满足条件，返回true，否则返回false
//int main()
//{
//	std::string s = "HELLO";
//
//	bool allUpper = std::all_of(s.begin(), s.end(), [](char c) { return std::isupper(static_cast<unsigned char>(c)); });
//}

//any_of
//至少有一个元素满足条件

//none_of
//没有元素满足条件

//is_partitioned
//是否已经被分成满足/不满足两段
template<class ForwardIt, class UnaryPredicate>
bool is_partitioned(ForwardIt first, ForwardIt last, UnaryPredicate p);