#include <iostream>
#include <vector>

//std::vector
//�ص�
//�ڴ�������̬��������
//֧��������ʣ�O(1)��
//β��죨O(1)��ͷ������O(n)��
//���ݻ��ƣ�ָ��ʽ���ݲ��ԣ�ͨ����1.5~2��
//��������RandomAccessIterator

//�����ṹ
template <typename T>
class _vector_
{
	T* data; //ָ��Ԫ�������ָ��
	size_t size; //��ǰԪ�ظ���
	size_t capacity; //��ǰ������ڴ������������ɶ��ٸ�Ԫ�أ�
	//vector�����ݺ��Ĳ���
	void push_back(const T& value)
	{
		if (size == capacity)
		{
			reserve(capacity == 0 ? 1 : capacity * 2)//�����¿ռ�
			//�����δ����ռ䣬���ʼ���ռ�Ϊ1����������������
		}
		data[size++] = value; //���ƻ��ƶ�ֵ
	}
	//reserveʵ��
	void reserve(size_t newCap)
	{
		if (newCap <= capacity) return;
		T* newData = new T[newCap];
		for (size_t i = 0; i < size; ++i)
			newData[i] = std::move(data[i]);//�ƶ�����
		delete[] data;
		data = newData;
		capacity = newCap;
	}
};
//vector�ײ���һ���������ڴ�飬����T[]���飬��֧�ֶ�̬��չ

//̯�����Ӷȣ�Amortized Complexity����ָ��
//ĳ�������ڴ��������ºܿ죬ֻ��ż���������ǰѶ�β�������ʱ��̯��������ÿ�β�����ƽ��ʱ����Ȼ�Ǻ�С�ģ�
//���仰˵���ǣ�����Զ�������Ǹ�Ч�ġ�


//���ò���
//push_back  ʱ�临�Ӷȣ�O(1)̯��  ����ʱΪO(n)β��
//pop_back   O(1)				βɾ
//insert(pos, val)	O(n)		����
//erase(pos)	O(n)			��ɾ
//[i]/at(i)		O(1)			�������
//clear()		O(n)			����ÿ��Ԫ�أ����ͷ��ڴ�
//reserve(n)	O(n)			��ǰ�����ڴ棬��ֹƵ������
//shrink_to_fit O(n)			��capacit��С��size

//����&�ƶ�
//std::vector�����ݻ���ʱ��
//����ʹ���ƶ����죨���Ԫ��֧���ƶ������������ÿ�������
//���Ե���Ÿ��Ӷ���ʱ������ʵ���ƶ�������ƶ����ƣ����Լ������ݺͲ���

//vector���ó���

