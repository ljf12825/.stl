#include <iostream>
#include <queue>
//std::queue��STL�е�һ����������������ʵ���˶���FIFO���ݽṹ
//std::queue�����ڵײ��������Ĭ��Ϊstd::deque�����洢���ݡ�
std::queue<int> q;
//��������
//push() //β�����
//pop() //ͷ������
//front() //���ض�ͷԪ��
//back() //���ض�βԪ��
//empty()/size()

//std::queue����Ӧ�ó���
//1.������ȣ�2.�������������BFS��3.������

//�ײ�ʵ��
template<class T, class Container = std::deque<T>>
class queue
{
protected:
	Container c;
public:
	void push(const T& value) { c.push_back(value); }
	void pop() { c.pop_front(); }
	T& front() { return c.front(); }
	const T& front() const { return c.front; }
	T& back() { return c.back(); }
	const T& back() const { return c.back(); }
	bool empty() { return c.empty(); }
	size_t size() { return c.size(); }
};