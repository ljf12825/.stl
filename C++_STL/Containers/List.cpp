#include <iostream>
#include <list>
//std::list<T>是一个双向链表容器
//每个元素都存储了前后两个指针，指向前驱和后继
//不支持随机访问
//插入、删除效率很高，不需要移动元素

//基本操作
//push_back(val) //尾插
//push_front(val) //头插
//pop_back() / pop_front() //弹头/尾
//insert(it, val) //在it位置前插入
//erase(it) //删除it位置的元素
//clear() //清空列表
//size() // 获取大小
//empty() //判空
//front() / back() //访问头/尾元素

//std::list<int> l = { 10, 20, 30 };
//auto it = l.begin();
//void func()
//{
//	++it;
//	l.insert(it, 15);//10 15 20 30
//}

//链表的独有操作：splice()
//std::list<int> a = { 1, 2, 3 };
//std::list<int> b = { 4, 5 };
//
//auto it = a.begin();
//void func()
//{
//	std::advance(it, 2);// it += 2;
//	a.splice(it, b); //把b中所有元素插入到a中it所指元素前
//	// 1 2 4 5 3
//}

//适用场景
//适合：
//在任意位置频繁插入/删除
//实现队列、链表等抽象结构

//不适合：
//随机访问非常频繁
//元素少、只做尾部操作时

//practice
//void func(std::list<int> list)
//{
//	for (auto it = list.begin(); it != list.end(); )
//	{
//		//迭代器被erase后已经失效了
//		if (*it % 2 == 0) it = list.erase(it);//list.erase(it)会返回“删除后下一个有效的迭代器”
//		else ++it;
//	}
//	for (auto it : list)
//		std::cout << it << " ";
//	std::cout << "\n";
//}

//std::list如何实现
//std::list是一个双向链表，底层本质就是由一组结构体节点组成的，彼此之间通过前驱指针和后继指针连接起来

//简化版底层结构
template<typename T>
struct ListNode
{
	T data;
	ListNode* prev;
	ListNode* next;
};
template<typename T>
class List
{
	ListNode<T>* head;
	ListNode<T>* tail;
};
//迭代器如何实现
template<typename T>
class ListIterator
{
	ListNode<T>* ptr;

	T& operator*() const { return ptr->data; }
	ListIterator& operator++() { ptr = ptr->next; return *this; }
	ListIterator& operator--() { ptr = ptr->prev; return *this; }
	bool operator!=(const ListIterator& other) const { return ptr != other.ptr; }
};
//这也就是为什么list不支持随机访问（it + 5），因为它只能一步步往前/后跳

//erase(it)做了什么
//假设it指向中间的节点
//it->prev->next = it->next;
//it->next->prev = it->prev;
//delete it;