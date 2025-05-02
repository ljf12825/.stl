//迭代器是访问容器中元素的一个重要工具。它们为程序提供了一种统一的方式来遍历不同容器中的元素，而不需要知道容器的底层实现
//迭代器是一个类，它提供了访问容器元素的接口。
//迭代器可以像指针一样移动、解引用、比较等
//它们提供了一个抽象层，使你能够以相同的方式处理不同的容器

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

//std::vector<int> vec = { 1, 2, 3, 4, 5 };
//std::vector<int>::iterator it;
//
//int main()
//{
//	for (it = vec.begin(); it != vec.end(); ++it)
//	{
//		std::cout << *it << " ";
//	}
//	return 0;
//}

//迭代器的类型(取决于容器特性)
//1.输入迭代器：只能单向遍历容器，读取元素；适用于只读操作
//2.输出迭代器：只能单向遍历容器，写入元素；适用于只写操作
//3.前向迭代器：支持单向遍历容器，且能够多次读取相同的元素，适用于大多数容器，支持读写操作
//4.双向迭代器：支持双向遍历容器，可以向前和向后移动；适用于std::list和一些其他容器
//5.随机访问迭代器：支持像指针一样的任意位置访问，能够支持加法、减法等运算；适用于std::vector和std::deque等容器

//迭代器的常用操作
//++, --, *, ->, ==, !=

//begin() 返回指向容器第一个元素的迭代器
//end() 返回指向容器末尾后元素的迭代器
//cbegin() 返回常量版本的begin
//cend() 返回常量版本的end
//rbegin() 反向迭代器，指向最后一个元素
//rend() 反向迭代器的末尾前元素
//crbegin() 常量反向begin
//crend() 常量反向end

//迭代器辅助函数<iterator>
//std::advanced(it, n) 把迭代器it前进n步
//std::next(it, n) 返回it前进n步后的新迭代器
//std::prev(it, n) 返回it后退n步后的新迭代器
//std::distance(it1, it2) 返回it1到it2的距离

//迭代器适配器
//它们不是原生迭代器，而是“伪迭代器”，当你对它执行*it = value时，它会把value插入到容器中
//std::back_inserter(container) 返回一个back插入迭代器，要求容器有push_back方法
std::vector<int> src = { 1,2,3 };
std::vector<int> dest;
std::vector<int> destination = { 10, 20 };
//int main()
//{
//	std::copy(src.begin(), src.end(), std::back_inserter(dest));
//	//dest = {1, 2, 3}
//	return 0;
//}

//std::front_inserter(container) 用于front插入容器
//dest = {3, 2, 1}

//std::inserter(container, pos) 向指定位置插入
//int main()
//{
//	std::copy(src.begin(), src.end(), std::inserter(destination, destination.begin()));//插入过程中迭代器始终指向10
//	for (auto i : destination)
//		std::cout << i << " ";
//	std::cout << "\n";
//	return 0;
//}

//输入/输出流迭代器<iterator>
//std::istream_iterator<T> 从输入流中读取类型为T的数据
//std::ostream_iterator<T> 向输出流中写入T类型数据

//int main()
//{
//	std::istream_iterator<int> in(std::cin), eof;
//	//in是一个输入流迭代器，从std::cin中读取int类型的数据，eof是默认构造的迭代器，表示“输入结束标志”
//	//std::istream_iterator把标准输入std::cin当作一个容器，从中迭代读取数据
//	std::vector<int> nums(in, eof);//将读到的数据存入nums中
//
//	std::sort(nums.begin(), nums.end());
//
//	std::ostream_iterator<int> out(std::cout, " ");//out是输出流迭代器，可以用来向std::cout写入数据
//	std::copy(nums.begin(), nums.end(), out);//将nums中的内容写道std::cout中
//
//	return 0;
//}

//常量迭代器(const_iterator)
//不允许通过迭代器修改元素
std::vector<int> vec = { 1, 2, 3, 4, 5 };
std::vector<int>::const_iterator it = vec.begin();

//逆向迭代器(reverse_iterator)
std::vector<int>::reverse_iterator rit = vec.rbegin();

//迭代器失效
//当容器结构发生改变时，原先指向该容器的迭代器可能变得无效
//此时，继续使用这些迭代器会导致UB

//如何避免迭代器失效
//修改容器前保存元素值或索引，不保存迭代器
//使用auto it = container.erase(it);这种返回新迭代器的方式继续操作
//尽量避免在遍历过程中修改容器结构
//使用list/map这类迭代器稳定性高的容器，避免迭代器失效问题

//example
std::vector<int> v = { 1, 2, 3, 4, 5 };
//int main()
//{
//	for (auto it = v.begin(); it != v.end(); )
//	{
//		//if (*it == 3) v.erase(it);//it被erase了，继续++it是UB
//		if (*it == 3) it = v.erase(it);//返回新迭代器
//		else ++it;
//	}
//	return 0;
//}