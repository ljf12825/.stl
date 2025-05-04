//������
//��������һ�ְ�װ��������һ�����е�������������һ���ӿڻ���Ϊ��ʹ���������ڲ�ͬ�����¸���
//��STL�У���������������ͨ��ģ���װ���ж������¶����䲿�ֽӿڣ����������µ���;

//����������
//ͨ����װ�����������������Ĵ󲿷ֳ�Ա������ֻ��¶�ض��ӿڣ�������������


//������������
//ͨ�����ı�׼����������Ϊ��ʹ����в�ͬ�ķ��ʷ�ʽ�����ݷ��򣬳������㷨����������
//�������������ı�������ģ�壬�ڲ�����һ��ԭʼ��������ͨ�����¶���operator��������������Ϊ

//std::reverse_iterator
template <typename Iterator>
class reverse_iterator
{
protected:
	Iterator current;//ԭʼ������

public:
	explicit reverse_iterator(Iterator it) : current(it) {}

	//�����ã����ص�����ָ���Ԫ��
	typename Iterator::reference operator*() const
	//Iterator::reference 
	//std::container<T>::iterator
	//using reference = T&
	{
		Iterator temp = current;
		return *--temp;//��.end()ǰ��һλ
	}

	//������ǰ����ʵ����current����
	reverse_iterator& operator++()
	{
		--current;
		return *this;
	}

	//����++
	//����Ϊ���ز���ǰ�ġ���ֵ�������������ǵ�ǰ����
	reverse_iterator operator++(int)//intΪ�﷨��ǣ�Ψһ�������ñ���������ǰ�úͺ������������
	{
		reverse_iterator tmp = *this;
		--current;
		return tmp;
	}
};

//std::back_insert_iterator
template <typename Container>
class back_insert_iterator {
protected:
	Container* container;

public:
	explicit back_insert_iterator(Container& c) : container(&c) {}

	// ���ظ�ֵ���������ֵ�������������Ĳ���
	back_insert_iterator& operator=(const typename Container::value_type& value) {
		container->push_back(value);
		return *this;
	}

	// ���в��������������������㷨�ӿڣ����Ǻ��ģ�û���κ�����
	back_insert_iterator& operator*() { return *this; }
	back_insert_iterator& operator++() { return *this; }
	back_insert_iterator operator++(int) { return *this; }
};

//����������
//���������������޸ĺ�����º�������Ϊ��ӿڣ��ر����ڷ����㷨��
//���ܰ����еĺ������������󡢳�Ա�����ȣ���װ����һ�������ض���Ϊ���·º�������
//std::bind ͨ�ð���
//std::mem_fn ��Ա����������
//std::function ͨ�ú��������װ��

//std::bind
#include <functional>
#include <algorithm>
#include <iostream>

//bool greater_than(int x, int y)
//{
//	return x > y;
//}
//
//auto f = std::bind(greater_than, std::placeholders::_1, 10); //�ȼ��� f(x) = x > 10
//
//std::vector<int> v = { 5, 15, 8, 20 };
//auto it = std::find_if(v.begin(), v.end(), f);


