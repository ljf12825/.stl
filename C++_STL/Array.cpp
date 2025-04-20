#include <iostream>
#include <array>
#include <algorithm>
#include <limits>

//std::array(C++11)
//array表示一个固定大小的数组，提供了比C风格数组更安全、更灵活的接口

//std::array的定义
template<typename T, std::size_t N>
struct _array_;

//与C style数组相比
// array<>和 T[]大小都是固定的
// array<>可以拷贝复制，而T[]不能
// array<>支持STL算法，T[]不支持
// array<>可以作为值传递参数不会退化，T[]则会退化为指针

//std::array常用成员函数
//arr.size() 返回大小
//arr.front() 第一个元素
//arr.back() 最后一个元素
//arr.empty() 是否为空
//arr.at() 安全访问，有越界检查
//arr.fill() 全部充填
//arr.swap(other) 与另一个array交换

//array使用场景
//固定的容器，内存连续，效率高
//不想用指针管理内存
//希望利用STL的算法
//想要更安全、更可读的代码替代C风格数组

//std::array<int, 5> arr = {};//{}(C++11)统一初始化，{}会触发array的构造函数，array的构造函数默认初始化为0
//int main()
//{
//	for (const auto& i : arr)
//	{
//		std::cout << i << " ";
//	}
//	return 0;
//}

//C++原生数组
//template<typename T>
//T arr[];
//没有范围检查
//数组名是指向首元素的指针
//
//二维数组
//int arr_2[3][4];//[行][列]
//定义时初始化，通过forfor单个元素赋值

//动态数组
int* arr_ptr = new int[5];
int main()
{
	//delete arr_ptr;//error
	delete[] arr_ptr;
}

//int main()
//{
//	arr_2 =//C++中的原生数组不是赋值兼容的对象（不像类或者std::array,也没有重载operator=），所以不能直接给整个数组赋值。
//	{
//		{1, 2, 3, 4},
//		{5, 6, 7, 8},
//		{9, 10, 11, 12}
//	};
//
//	std::array<std::array<int, 4>, 3> arr_3;
//	arr_3 =//std::array可以
//	{ {
//		{{1, 2, 3, 4}},
//		{{4, 5, 6, 7}},
//		{{8, 9, 10, 11}}
//	} };
//	return 0;
//}

//practice1数组反转
//编写一个函数，接受一个std::array<int, 5>,并将它的内容就地反转
std::array<int, 5> arr_1 = { 1, 2, 3, 4, 5 };
std::array<int, 5> reverse(std::array<int, 5> arr)
{
	std::array<int, 5> temp;
	for (int i = 0; i < 5; ++i)
	{
		temp[i] = arr[4 - i];
	}
	return temp;
}
//优化
template<typename T, std::size_t N>
std::array<T, N> reverse(std::array<T, N> arr)
{
	std::array<T, N> temp;
	for (int i = 0; i < N; ++i)
		temp[i] = arr(N - 1 - i);//经典反转索引写法
	return temp;
}

//practice2最大值与最小值
//给定一个std::array<int, 6>,找出其中最大值与最小值并输出
std::array<int, 6> arr_2 = { 3, 7, 1, 9, 4, 2 };
void Max_Min(std::array<int, 6> arr)
{
	int max = 0;
	int min = INT_MAX;
	for (auto i : arr)
	{
		if (max < i) max = i;
		if (min > i) min = i;
	}
	std::cout << max << " " << min << std::endl;
}
//优化
template<typename T, std::size_t N>
void Max_Min(const std::array<T, N>& arr)
{
	//泛型安全
	T max = std::numeric_limits<T>::lowest();//返回的是T类型能表示的最小值
	T min = std::numeric_limits<T>::max();//返回的是T类型能表示的最大值
	for (const auto& i : arr)
	{
		if (i > max) max = i;
		if (i < min) min = i;
	}
}

//practice3元素查找
//编写一个函数，判断一个给定数字是否存在于数组中，如果存在则输出其下标
std::array<int, 5> arr_3 = { 10, 20, 30, 40, 50 };
int target = 30;
void match(std::array<int, 5> arr)
{
	int index = 0;
	for (auto i : arr)
	{
		if (target == i) break;
		index++;
	}
	std::cout << "Found at index " << index << std::endl;
}
//优化
void match(const std::array<int, 5>& arr, int target)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == target)
		{
			std::cout << i << std::endl;
			return;
		}
	}
	std::cout << "Not found" << std::endl;
}
//优化2
void match(const std::array<int, 5>& arr, int target)
{
	auto it = std::find(arr.begin(), arr.end(), target);//如果找到了，it指向该元素的位置；如果没找到，it指向.end()
	if (it != arr.end())
	{
		std::cout << std::distance(arr.begin(), it) << std::endl;//计算元素位置
	}
	else
	{
		std::cout << "Not found" << std::endl;
	}
}

//practice4统计偶数个数
//编写函数，统计std::array<int, 10>中有多少个偶数
int Evennum(std::array<int, 10> arr)
{
	int flag = 0;
	for (auto i : arr)
	{
		if (i % 2 == 0) flag++;
	}
	return flag;
}
//优化
template<typename T, std::size_t N>
int Evennum(const std::array<T, N>& arr)
{
	int flag = 0;
	for (auto i : arr)
	{
		if (i % 2 == 0) flag++;
	}
	return flag;
}

//practice5使用std::sort排序字符串数组
//给定一个字符串数组，按字母表顺序升序排序
std::array<std::string, 4> names = { "Zoe", "Alice", "Eve", "Bob" };
std::array<std::string, 4> sortname(std::array<std::string, 4> arr)
{
	std::sort(arr.begin(), arr.end(), [](std::string a, std::string b) {
		char A = std::tolower(a[0]);
		char B = std::tolower(b[0]);
		return A < B;
		});
	return arr;
}
//优化
template<std::size_t N>
std::array<std::string, N> sortname(std::array<std::string, N> arr)
{
	std::sort(arr.begin(), arr.end(), [](const std::string& a, const std::string& b) {
		return std::tolower(static_cast<unsigned char>(a[0])) < std::tolower(static_cast<unsigned char>(b[0]);
		});
	//使用std::tolower并确保char是unsigned char，防止UB；
	return arr;
}

//AddOn模拟插入元素
//std::array是有固定大小的容器，你不能添加新元素。但你能想办法“插入一个元素”，并把后面的往后挪位置吗？假设我们有：
//std::array<int, 5> arr = {1, 2, 3, 4, 0}//最后一位空出来
//你要把数字99插入到下标2：1， 2， 99， 4， 0；
std::array<int, 5> arr_4 = { 1, 2, 3, 4, 0 };//最后一位空出来
std::array<int, 6> insert(std::array<int, 5> arr, int position, int number)
{
	std::array<int, 6> temp;
	temp.fill(0);
	if (position == 0)
	{
		temp[position] = number;
		for (int i = 0; i < arr.size(); i++)
		{
			temp[i + 1] = arr[i];
		}
	}
	else if (position == 6)
	{
		for (auto i : arr)
		{
			temp[i] = arr[i];//error
		}
		temp[position] = number;
	}
	else if(position > 0 && position < 6)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (i < position)
			{
				temp[i] = arr[i];
			}
			if (i == position)
			{
				temp[position] = number;
			}
			if (i > position)
			{
				temp[i] = arr[i - 1];
			}
		}

	}
	return temp;
}
//优化
std::array<int, 6> insert(const std::array<int, 5>& arr, int position, int number)
{
	std::array<int, 6> temp;
	temp.fill(0);

	if (position < 0 || position > 5)
	{
		std::cerr << "Invalid position" << std::endl;
		return temp;
	}

	for (int i = 0; i < position; ++i)
	{
		temp[i] = arr[i];
	}
	temp[position] = number;
	for (int i = position; i < 5; ++i)
	{
		temp[i + 1] = arr[i];
	}
	return temp;
}
