#include <iostream>
#include <map>
//std::map
//std::map是STL中的一个关联容器
//它存储K-V pairs，每个元素由一个唯一的键和与之关联的值组成
//std::map会根据键的大小关系自动对其元素进行排序
//主要特点：
//键唯一：每个键只能出现一次，不允许重复键。如果你试图插入一个已存在的键，它会更新对应的值。
//自动排序：默认情况下，元素根据键的大小进行排序（默认<）。你可以通过自定义比较器来改变排序方式
//基于红黑树实现：std::map是一个平衡二叉搜索树，插入、删除、查找的时间复杂度平均为O(log n)
//int main()
//{
//	std::map<int, std::string> myMap;
//
//	myMap[1] = "Apple";
//	myMap[2] = "Banana";
//	myMap[3] = "Cherry";
//	myMap.insert(std::make_pair(4, "Date"));
//
//	auto it = myMap.find(2);
//	if (it != myMap.end())
//		std::cout << "Found key 2 with value : " << it->second << std::endl;
//
//	for (const auto& pair : myMap)
//	{
//		std::cout << pair.first << pair.second << std::endl;
//	}
//
//	myMap.erase(3);
//}
//
//基本操作
//insert返回一个pair
//pair.first是一个迭代器，指向新插入的元素（或者已经存在的元素，如果键已经存在的话）
//pair.second是一个布尔值，表示插入是否成功。如果键已存在则返回false，否则返回true
//begin返回第一个元素的迭代器
//end返回指向map末尾的迭代器
//find用于查找特定的键并返回一个指向该元素的迭代器。如果键不存在，则返回map.end()
//erase(key)/erase(it.begin it.end)
//std::map默认使用operator<运算符来比较键，但你也可以指定自定义的比较函数
//std::map<int, std::string, std::greater<int>> reverseMap;
//count检查是否存在某个键
//count返回一个整数，表示指定键是否存在。在std::map中，由于键是唯一的，返回值要么是0（不存在）要么是1（存在）

//底层实现
template<
	class Key, 
	class T, 
	class Compare = std::less<Key>, 
	class Allocator = std::allocator<std::pair<const Key, T>>>
class map;

//C++17
namespace pmr
{
	template<
		class Key,
		class T,
		class Compare = std::less<Key>
	>using map = std::map<Key, T, Compare,
		std::pmr::polymorphic_allocator<std::pair<const Key, T>>>;
}