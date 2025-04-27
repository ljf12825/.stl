#include <iostream>
#include <unordered_map>
//std::unordered_map
//哈希表容器
//本质上是K到V的映射，但元素是无序的
//插入、查找时间复杂度平均O(1)最坏O(N)
//不允许key重复，重复会覆盖
//自动扩容（rehash）

//unordered_map底层怎么工作
//它是基于哈希表实现的
//1.把key传给哈希函数（std::hash<key>），得到一个数字（哈希值）
//2.根据哈希值，把元素放到内部的某个桶（bucket）里
//3.查找时，用同样的哈希函数直接定位到桶，非常快
//哈希函数(key) -> 得到桶编号 -> 把 key-value 放入对应桶
//如果多个key哈希到同一个桶，就会在桶里形成链表/链式结构（叫做冲突）

//基本操作
//std::unordered_map<std::string, int> umap;
//int main()
//{
//	umap["apple"] = 3;
//	umap["banana"] = 5;
//	umap.insert({ "orange", 7 });
//	auto it = umap.find("banana");
//	if (it != umap.end())
//		std::cout << "banana: " << it->second << std::endl;
//	umap["apple"] == 10;
//	umap.erase("orange");
//	//普通遍历
//	for (auto it = umap.begin(); it != umap.end(); ++it)
//	{
//		std::cout << it->first << it->second << std::endl;
//	}
//	//C++11范围for循环
//	for (const auto& pair : umap)
//	{
//		std::cout << pair.first << pair.second << std::endl;
//	}
//	//C++17结构化绑定
//	for (const auto& [key, value] : umap)
//	{
//		std::cout << key << value << std::endl;
//	}
//}

//负载因子（load factor）
//负载因子 = 元素个数/桶的数量
//负载因子高->冲突多->性能下降
//C++会自动rehash（扩容）以保证性能
//手动管理：
//umap.load_factor()//查看当前负载因子
//umap.max_load_factor()//设置最大负载因子
//umap.rehash(100)//重新分配100个桶

//Rehashing(重新哈希)
//rehash是一种机制，当负载因子过高时，容器会重新分配桶的数量，并计算所有元素的哈希值，以减少哈希冲突，从而提高性能
//触发条件：当负载因子超过某个阈值时，哈希表会自动扩展桶的数量。默认的负载因子阈值是1.0
//执行过程：
//1.计算当前哈希表中元素的数量和桶的数量
//2.根据负载因子和阈值，决定是否需要扩展桶的数量。如果需要扩展，桶的数量通常会扩大为原来的两倍
//3.对现有元素进行重新哈希（重新计算每个元素的哈希值），并将它们分配到新的桶中

//自定义
//自定义类
struct Point
{
	int x, y;
	bool operator==(const Point& other) const
	{
		return x == other.x && y == other.y;
	}
};
//自定义哈希函数
struct PointHash
{
	std::size_t operator()(const Point& p) const
	{
		return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
	}
};
//使用自定义哈希和比较器
std::unordered_map<Point, int, PointHash> pointMap;