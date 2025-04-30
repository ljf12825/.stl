#include <iostream>
#include <list>
//std::list<T>��һ��˫����������
//ÿ��Ԫ�ض��洢��ǰ������ָ�룬ָ��ǰ���ͺ��
//��֧���������
//���롢ɾ��Ч�ʺܸߣ�����Ҫ�ƶ�Ԫ��

//��������
//push_back(val) //β��
//push_front(val) //ͷ��
//pop_back() / pop_front() //��ͷ/β
//insert(it, val) //��itλ��ǰ����
//erase(it) //ɾ��itλ�õ�Ԫ��
//clear() //����б�
//size() // ��ȡ��С
//empty() //�п�
//front() / back() //����ͷ/βԪ��

//std::list<int> l = { 10, 20, 30 };
//auto it = l.begin();
//void func()
//{
//	++it;
//	l.insert(it, 15);//10 15 20 30
//}

//����Ķ��в�����splice()
//std::list<int> a = { 1, 2, 3 };
//std::list<int> b = { 4, 5 };
//
//auto it = a.begin();
//void func()
//{
//	std::advance(it, 2);// it += 2;
//	a.splice(it, b); //��b������Ԫ�ز��뵽a��it��ָԪ��ǰ
//	// 1 2 4 5 3
//}

//���ó���
//�ʺϣ�
//������λ��Ƶ������/ɾ��
//ʵ�ֶ��С�����ȳ���ṹ

//���ʺϣ�
//������ʷǳ�Ƶ��
//Ԫ���١�ֻ��β������ʱ

//practice
//void func(std::list<int> list)
//{
//	for (auto it = list.begin(); it != list.end(); )
//	{
//		//��������erase���Ѿ�ʧЧ��
//		if (*it % 2 == 0) it = list.erase(it);//list.erase(it)�᷵�ء�ɾ������һ����Ч�ĵ�������
//		else ++it;
//	}
//	for (auto it : list)
//		std::cout << it << " ";
//	std::cout << "\n";
//}

//std::list���ʵ��
//std::list��һ��˫�������ײ㱾�ʾ�����һ��ṹ��ڵ���ɵģ��˴�֮��ͨ��ǰ��ָ��ͺ��ָ����������

//�򻯰�ײ�ṹ
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
//���������ʵ��
template<typename T>
class ListIterator
{
	ListNode<T>* ptr;

	T& operator*() const { return ptr->data; }
	ListIterator& operator++() { ptr = ptr->next; return *this; }
	ListIterator& operator--() { ptr = ptr->prev; return *this; }
	bool operator!=(const ListIterator& other) const { return ptr != other.ptr; }
};
//��Ҳ����Ϊʲôlist��֧��������ʣ�it + 5������Ϊ��ֻ��һ������ǰ/����

//erase(it)����ʲô
//����itָ���м�Ľڵ�
//it->prev->next = it->next;
//it->next->prev = it->prev;
//delete it;