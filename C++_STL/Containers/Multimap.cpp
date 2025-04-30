#include <iostream>
#include <map>
//std::multimap
//关联容器
//类似map
//K-V
//元素自动按键值排序，默认<排序，可以自定义比较器
//允许有重复的键
//底层是红黑树
//int main()
//{
//	std::multimap<int, std::string> m;
//	m.insert({ 1, "apple" });
//	m.insert({ 2, "banana" });
//	m.insert({ 1, "avocado" });
//
//	for (const auto& [key, value] : m)
//		std::cout << key << " " << value << std::endl;
//	return 0;
//	//1 apple
//	//1 avocado
//	//2 banana
//}
// 
// equal_range(x)可以拿到所有key值相同的元素
//equal_range返回一个pair，包含两个迭代器：
//first:指向第一个匹配的元素，second:指向第一个大于该key的元素
//int main() {
//    std::multimap<int, std::string> mmap;
//
//    // 插入一些键值对
//    mmap.insert({ 3, "apple" });
//    mmap.insert({ 3, "banana" });
//    mmap.insert({ 5, "cherry" });
//    mmap.insert({ 3, "date" });
//    mmap.insert({ 7, "elderberry" });
//    mmap.insert({ 5, "fig" });
//
//    // 打印 multimap 所有元素
//    std::cout << "所有元素: ";
//    for (const auto& pair : mmap)
//        std::cout << "(" << pair.first << ", " << pair.second << ") ";
//    std::cout << std::endl;
//
//    // 使用 equal_range 查找所有 key 为 3 的元素
//    auto range = mmap.equal_range(3);
//
//    std::cout << "key 为 3 的所有元素: ";
//    for (auto it = range.first; it != range.second; ++it) {
//        std::cout << "(" << it->first << ", " << it->second << ") ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}


//multimap没有operator[]
//multimap底层红黑树对重复键处理，把新的节点插在已有节点的右边
//原因：
//1.保证顺序稳定
//2.保持中序遍历是正确排序
//中序遍历multimap，总是按key排序 + 按插入顺序返回
//3.树平衡更容易维护