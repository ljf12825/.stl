#include <iostream>
#include <vector>
#include <algorithm>

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
			reserve(capacity == 0 ? 1 : capacity * 2);//�����¿ռ�
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

//����
std::vector<int> v1; //NULL
std::vector<int> v2(5); //5��0
std::vector<int> v3(5, 10); //5��10
std::vector<int> v4 = { 1, 2 ,3 ,4 }; //�б��ʼ��

//����
void func_vector_test()
{
	for (int i = 0; i < v4.size(); ++i) std::cout << v4[i] << ' ';
	
	for (auto x : v4) std::cout << x << " ";

	for (auto it = v4.begin(); it != v4.end(); ++it) std::cout << *it << ' ';
}

//ָ�롢����ʧЧ
//��vector����ʱ�������½�������ڴ沢���ƾ����ݣ���ʱԭ����Ԫ��ָ�롢���á�����������ʧЧ


//���ò���
//push_back  ʱ�临�Ӷȣ�O(1)̯��  ����ʱΪO(n) β��
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
//1.��������O(1)
//���ڴ洢�������ݲ�Ƶ����ȡ�ĳ���������ͼ�����ء��������顢��ͼ���ӵȡ�
//2.��̬����
//3.����д��
//4.�����õ��ײ���ָ��
//5.ϣ��ʹ��STL�㷨��
//���ʺϵĳ���
//1.Ƶ�����м���롢ɾ��
//2.��Ҫ���ֲ���˳�����ٲ���
//3.Ԫ������Ƶ���������Ҵ�С�仯����
//4.���̲߳����޸�

//practice1:����������
//ʹ��std::vectorʵ��һ���򵥵�����������IntSet��֧�����²�����
//���������ɾ��ָ����������ӡ����Ԫ�أ��������������ĺ�
class IntSet
{
private:
	std::vector<int> data;
public:
	void add(int value)
	{
		data.push_back(value);
	}
	void remove(int value)
	{
		auto it = std::remove(data.begin(), data.end(), value);
		data.erase(it, data.end());
	}
	int sum() const
	{
		int s = 0;
		for (int val : data) s += val;
		return s;
	}
	void print() const
	{
		for (int val : data)
			std::cout << val << " ";
		std::cout << "\n";
	}
};
//practice2.��vectorʵ��ջ
//Ҫ��ʵ��һ��Stack�֧࣬��push��pop, top, empty
class Stack
{
private:
	std::vector<int> vec;
public:
	void push(int value)
	{
		vec.push_back(value);
	}
	int pop()
	{
		if (vec.empty())
			throw std::out_of_range("Stack is empty");
		int temp = vec.back();
		vec.pop_back();
		return temp;
	}
	int top()
	{
		if (vec.empty())
			throw std::out_of_range("Stack is empty");
		return vec.back();
	}
	bool empty()
	{
		return vec.empty();
	}
};

//practice3 vectorģ��ѧ����Ϣϵͳ
class StudentSystem
{
private:
	struct Student
	{
		std::string name;
		int age;
		float score;
	};
	std::vector<Student> vec;
public:
	void Add(Student student)
	{
		vec.push_back(student);
	}
	void Delete(std::string name)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec[i].name == name)
			{
				vec.erase(vec.begin() + i);
				return;
			}
		}
		std::cout << "Not Found!" << std::endl;
	}
	void print()
	{
		for (auto student : vec)
		{
			std::cout << student.name << " " << student.age << " " << student.score << std::endl;
		}
	}
};

