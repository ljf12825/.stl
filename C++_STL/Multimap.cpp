#include <iostream>
#include <map>
//std::multimap
//关联容器
//类似map
//K-V
//元素自动按键值排序，默认<排序，可以自定义比较器
//允许有重复的键
//底层是红黑树
int main()
{
	std::multimap<int, std::string> m;
	m.insert({ 1, "apple" });
	m.insert({ 2, "banana" });
	m.insert({ 1, "avocado" });

	for (const auto& [key, value] : m)
		std::cout << key << " " << value << std::endl;
	return 0;
	//1 apple
	//1 avocado
	//1 banana
}
//multimap没有operator[]
//multimap底层红黑树对重复键处理，把新的节点插在已有节点的右边
//原因：
//1.保证顺序稳定
//2.保持中序遍历是正确排序
//中序遍历multimap，总是按key排序 + 按插入顺序返回
//3.树平衡更容易维护