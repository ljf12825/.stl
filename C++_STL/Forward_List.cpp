#include <iostream>
#include <forward_list>
//std::forward_list(C++11)
//��������
//ÿ���ڵ�ֻ��һ��ָ�룺next
//��֧��prev��--it�Ȳ���
//��������������ʡ�ڴ�
//����Ϊ���ֲ�std::list�ռ��˷ѵ����������
//��������Щ�ڴ����ȡ��Բ���˳��Ҫ��ϵ͵ĳ���

//�ײ�ṹ
template<typename T>
struct ForwardNode
{
	T data;
	ForwardNode* next;
};

template<typename T>
class forward_list
{
	ForwardNode<T>* head;//ָ���һ���ڵ�
};
//��ͨ��before_begin()���ʣ������޸ĵ�һ���ڵ�
//forward_listֻ�ܴ�ǰ�������
//�����ɾ��ֻ����before�ĵ���������
//forward_listû��size()����

//��������
std::forward_list<int> fl = { 1, 2, 3, 4 };
void func()
{
	fl.push_front(0);//{0,1,2,3,4}
	fl.pop_front();//{1,2,3,4}
	for (int val : fl) std::cout << val << " ";
	auto it = fl.before_begin();//ͷָ��
	++it;
	fl.insert_after(it, 99);//{1��99��2��3��4}
	fl.erase_after(it);//{1,2,3,4}
}