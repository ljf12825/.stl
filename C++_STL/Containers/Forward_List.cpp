#include <iostream>
#include <forward_list>
//std::forward_list(C++11)
//单向链表
//每个节点只有一个指针：next
//不支持prev或--it等操作
//更加轻量、更节省内存
//它是为了弥补std::list空间浪费的问题引入的
//适用于那些内存首先、对操作顺序要求较低的场景

//底层结构
template<typename T>
struct ForwardNode
{
	T data;
	ForwardNode* next;
};

template<typename T>
class forward_list
{
	ForwardNode<T>* head;//指向第一个节点
};
//可通过before_begin()访问，用于修改第一个节点
//forward_list只能从前往后遍历
//插入和删除只能用before的迭代器操作
//forward_list没有size()方法

//基本操作
std::forward_list<int> fl = { 1, 2, 3, 4 };
void func()
{
	fl.push_front(0);//{0,1,2,3,4}
	fl.pop_front();//{1,2,3,4}
	for (int val : fl) std::cout << val << " ";
	auto it = fl.before_begin();//头指针
	++it;
	fl.insert_after(it, 99);//{1，99，2，3，4}
	fl.erase_after(it);//{1,2,3,4}
}