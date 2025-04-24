#include <iostream>
#include <stack>
//std::stack��C++��׼���е�һ�����������������ṩ��ջ���ݽṹ�Ľṹ����LIFO

std::stack<int> s;
//��������
//push() / pop()
//top() ����ջ��Ԫ��
//empty() / size()
//emplace(args) ԭ�ع���һ��Ԫ��
//swap()

//std::stack������һ�����������������ǻ�������������������װ������
//Ĭ�ϵײ�������std::deque
//����дstd::stack<int> s;
//��ʵ�൱��д��
//std::stack<int, std::deque<int>> s;//����һ��int���͵�ջ����deque������
//Ҳ����˵��std::stack�ڲ�Ĭ��ʹ��std::deque���洢Ԫ��
//��Ҳ����ʹ��������׼������Ϊ�ײ� std::stack<int, std::vector<int>> s;
//��������
//�������������������������ײ㣬ֻ������һ�������������ſ���
//������֧����Щ������
//back() ��ȡջ��Ԫ��
//push_back() push()
//pop_back() pop()
//empty()
//size()

//�ײ�ԭ��
//std::stack<T>�����Լ������ݣ�����ί�еײ�����ȥ�������ݣ���ֻ���ṩ�ˡ�ջ���Ľӿ�
template<class T, class Container = std::deque<T>>
class stack
{
protected:
	Container c; //ʵ�����ݴ洢λ��

public:
	//���Ͷ���
	using value_type = typename Container::value_type;
	using reference = typename Container::reference;
	using const_reference = typename Container::const_reference;
	using size_type = typename Container::size_type;
	//���캯��
	stack() = default;

	//ջ����
	bool empty() const { return c.empty(); }
	size_type size() const { return c.size(); }
	reference top() { return c.back(); }
	const_reference top() const { return c.back(); }
	void push(const value_type& value) { c.push_back(value); }
	void push(value_type&& value) { c.push_back(std::move(value)); }
	void pop() { c.pop_back(); }
	void swap(stack& other) noexcept(noexcept(std::swap(c, other.c))) { std::swap(c, other.c); }
};
//����԰�std::stack�����ǶԵײ�������һ�֡���Ϊ���ơ�
//����ǡ�������������������εײ�������������ֻ��¶������Ҫ�Ľӿ�
