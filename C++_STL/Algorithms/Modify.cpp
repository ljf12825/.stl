#include <iostream>
#include <algorithm>
#include <vector>

//copy
//拷贝元素
template<class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt d_first);
//[first, last)
//d_first:表示目标区域的起始位置
//返回值：指向目标区域中最后一个被复制的元素之后的位置
//std::copy_n 拷贝前n个
//std::copy_if拷贝满足条件的元素

//move
//移动元素

//remove
//移除某值，需配合erase
//它并不真正删除元素，而是将不需要的元素移到末尾，并返回新逻辑末尾的迭代器
template<class ForwardIt, class T>
ForwardIt remove(ForwardIt first, ForwardIt last, const T& value);
//返回一个迭代器，指向移除后的“新逻辑末尾”

//replace
//替换某值为新值
template<class ForwardIt, class T>
void replace(ForwardIt first, ForwardIt last, const T& old_value, const T& new_value);

//transform
//按规则修改所有元素
//将一个范围内的元素逐个转换成新值，并写入另一个范围（可以是原地，也可以是新容器）
//一元版本
template<class InputIt, class OutputIt, class UnaryOperation>
OutputIt transform(InputIt first, InputIt last, OutputIt d_first, UnaryOperation unary_op);
//UnaryOperation是一个函数，接受一个参数，返回变换结果
//std::vector<int> vec_1 = { 1, 2 , 3 , 4 , 5 };
//std::vector<int> vec_2(vec_1.size());
//
//int main()
//{
//	std::transform(vec_1.begin(), vec_1.end(), vec_2.begin(), [](int x) { return x * 2; });
//
//	return 0;
//}

//二元版本
template<class InputIt1, class InputIt2, class OutputIt, class BinaryOperation>
OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryOperation binary_op);
//用于分两个容器逐个元素组合成新结果
//std::vector<int> result(vec_1.size());
//int main()
//{
//	std::transform(vec_1.begin(), vec_1.end(), vec_2.begin(), result.begin(), [](int x, int y) { return x + y; });
//	return 0;
//}

//fill
//全填某个值
template<class ForwardIt, class T>
void fill(ForwardIt first, ForwardIt last, const T& value);

//generate
//用函数生成内容
template<class ForwardIt, class Generator>
void gernerate(ForwardIt first, ForwardIt last, Generator g);
//g:无参数的函数或lambda，每次调用生成一个新值
//int main()
//{
//	std::vector<int> v(5);
//	int n = 0;
//
//	std::generate(v.begin(), v.end(), [&n]() { return n++; });
//
//	return 0;
//}