#include <functional>
#include <iostream>

//仿函数
//STL中提供了一些常用的仿函数，定义在头文件<functional>中

//仿函数优势
//可以携带状态（有状态，仿函数类成员变量参与运算）
//用于泛型编程，配合STL算法
//编译期内可内联优化，效率高

//现代C++更常用lambda表达式来替代仿函数，因为它写法更简洁。但理解仿函数仍然重要，特别是阅读STL源码和模板库

//仿函数作为比较规则参与容器内部元素的排序、查找、插入、删除等操作
//仿函数的类型作为模板参数传给容器，容器内部会存储一份它的副本，作为比较行为的依据
template<
	class Key,
	class Compare = std::less<Key>,//使用自定义仿函数进行替换
	class Allocator = std::allocator<Key>
> class set;

//使用自定义仿函数的注意事项
//1.自定义仿函数必须是严格弱序（满足传递性、不可自反性等），否则UB
//2.仿函数必须是const函数（因为内部比较时使用const引用）；
//3.仿函数应该是无状态的，或者状态对于排序行为是稳定的（如可拷贝的只读数据）（仿函数类内参数可以起作用，但是不能在容器副本内发生变化，否则UB）

int main()
{
	//算术类仿函数
	std::plus<int> plus;
	std::minus<int> minus;
	std::multiplies<int> multiplies;
	std::divides<int> divides;
	std::modulus<int> modulus;//取模 return _Left % _Right
	std::negate<int> negate;//取反 return -_Left;

	//关系类仿函数
	std::equal_to<int> equal_to;
	std::not_equal_to<int> not_equal_to;
	std::greater<int> greater;
	std::less<int> less;
	std::greater_equal<int> greater_equal;
	std::less_equal<int> less_equal;

	//逻辑类仿函数
	std::logical_and<int> logical_and;
	std::logical_not<int> logical_not;
	std::logical_or<int> logical_or;
}