#include <iostream>
#include <numeric>
#include <vector>

//accumulate
//累加(聚合任意运算)
template<class InputIt, class T, class BinaryOperation>
T accumulate(InputIt first, InputIt last, T init, BinaryOperation op);
//[first, last)
//init:初始值，计算时会先用init初始化
//op：二元操作（如加法，乘法等），会对容器中的每个元素与当前结果做运算
//返回最终计算结果
//缺省形式（加法）
template<class InputIt, class T>
T accumulate(InputIt first, InputIt last, T init);

//int main()
//{
//	std::vector<int> vec = { 1, 2, 3, 4, 5 };
//	auto i = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
//	std::cout << i << std::endl;
//}

//inner_product
//求内积
//缺省形式：init += a * b
template<class InputIt1, class InputIt2, class T>
T inner_product(InputIt1 first1, InputIt1 last1, InputIt2 first2, T init);
//int main()
//{
//	std::vector<int> a = { 1, 2, 3 };
//	std::vector<int> b = { 4, 5, 6 };
//
//	int result = std::inner_product(a.begin(), a.end(), b.begin(), 0);
//	//0 + 1 * 4 + 2 * 5 + 3 * 6；
//}

//自定义乘法和加法形式
template<class InputIt1, class InputIt2, class T, class BinaryOp1, class BinaryOp2>
T inner_product(InputIt1 first1, InputIt1 last1, InputIt2 first2, T init, BinaryOp1 op_add, BinaryOp2 op_mult);
//int main()
//{
//	std::vector<int> a = { 1, 2, 3 };
//	std::vector<int> b = { 4, 5, 6 };
//	int result = std::inner_product(a.begin(), a.end(), b.begin(), 0, std::minus<int>(), std::multiplies<int>());
//	//0 - 1 * 4 - 2 * 5 - 3 * 6
//}

//partial_sum
//局部和
//缺省形式（加法）
template<class InputIt, class OutputIt>
OutputIt partial_sum(InputIt first, InputIt last, OutputIt d_first);
//i1, (i1 + i2), (i1 + i2 + i3), ...
template<class InputIt, class OutputIt, class BinaryOperation>
OutputIt partial_sum(InputIt first, InputIt last, OutputIt d_first, BinaryOperation op);

//adjacent_difference
//相邻元素差
template<class InputIt, class OutputIt>
OutputIt adjacent_difference(InputIt first, InputIt last, OutputIt d_first);
//i1, i2 - i1, i3 - i2, ...

template<class InputIt, class OutputIt, class BinaryOperation>
OutputIt adjacent_difference(InputIt first, InputIt last, OutputIt d_first, BinaryOperation op);