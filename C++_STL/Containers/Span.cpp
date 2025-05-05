#include <span>
#include <iostream>
#include <vector>

//std::span是C++20引入的一个轻量级视图容器，用于不拥有数据的数组视图。
//它像一个只读或读写的指针 + 长度，可以用来安全地访问数组、std::vector等序列

template<
	class T,
	std::size_t Extent = std::dynamic_extent
> class span;

//void print(std::span<int> s)
//{
//	for (int x : s)
//		std::cout << x << " ";
//	std::cout << "\n";
//}
//
//int main()
//{
//	std::vector<int> v = { 1, 2, 3, 4, 5 };
//	print(v);
//
//	int arr[] = { 6, 7, 8 };
//	print(arr);
//
//	print(std::span<int>(v.begin(), 3));
//
//	return 0;
//}

//常用构造
int arr[5] = { 1, 2, 3, 4, 5 };
std::span<int> s1(arr);
std::span<int> s2(arr, 3);
std::span<int> s3 = std::span{ arr };

//创建子视图
auto sub = s1.subspan(1, 3);

//span没有数据复制成本，只是一块连续的视窗
//span统一了函数传递容器参数的接口
//span边界安全，支持at、debug检查，可在调试模式下触发边界越界断言
//span可以进行数据切片
//span支持范围for