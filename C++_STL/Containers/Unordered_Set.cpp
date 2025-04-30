#include <iostream>
#include <unordered_set>
//std::unordered_set
//关联容器
//底层哈希表
//key不允许重复
//无序
//自动扩容（rehash）
//int main()
//{
//	std::unordered_set<int> uset = { 1, 2, 3, 4, 5 };
//	uset.insert(6);
//	for (const int& elem : uset)
//		std::cout << elem << " ";
//	return 0;
//}
//如果你需要快速查找、插入和删除元素，且不关心元素的顺序，unordered_set是一个非常合适的选择