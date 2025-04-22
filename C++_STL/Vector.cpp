#include <iostream>
#include <vector>
#include <algorithm>

//std::vector
//特点
//内存连续动态扩容数组
//支持随机访问（O(1)）
//尾插快（O(1)）头插慢（O(n)）
//扩容机制：指数式扩容策略，通常是1.5~2倍
//迭代器：RandomAccessIterator

//基本结构
template <typename T>
class _vector_
{
	T* data; //指向元素数组的指针
	size_t size; //当前元素个数
	size_t capacity; //当前分配的内存容量（能容纳多少个元素）
	//vector的扩容核心操作
	void push_back(const T& value)
	{
		if (size == capacity)
		{
			reserve(capacity == 0 ? 1 : capacity * 2);//分配新空间
			//如果尚未分配空间，则初始化空间为1，如果分配过则扩容
		}
		data[size++] = value; //复制或移动值
	}
	//reserve实现
	void reserve(size_t newCap)
	{
		if (newCap <= capacity) return;
		T* newData = new T[newCap];
		for (size_t i = 0; i < size; ++i)
			newData[i] = std::move(data[i]);//移动构造
		delete[] data;
		data = newData;
		capacity = newCap;
	}
};
//vector底层是一个连续的内存块，类似T[]数组，但支持动态扩展

//摊还复杂度（Amortized Complexity）是指：
//某个操作在大多数情况下很快，只有偶尔慢，但是把多次操作的总时间摊开来看，每次操作的平均时间仍然是很小的；
//换句话说就是：看长远，总体是高效的。

//构造
std::vector<int> v1; //NULL
std::vector<int> v2(5); //5个0
std::vector<int> v3(5, 10); //5个10
std::vector<int> v4 = { 1, 2 ,3 ,4 }; //列表初始化

//遍历
void func_vector_test()
{
	for (int i = 0; i < v4.size(); ++i) std::cout << v4[i] << ' ';
	
	for (auto x : v4) std::cout << x << " ";

	for (auto it = v4.begin(); it != v4.end(); ++it) std::cout << *it << ' ';
}

//指针、引用失效
//当vector扩容时，它会新建更大的内存并复制旧数据，此时原来的元素指针、引用、迭代器都会失效


//常用操作
//push_back  时间复杂度：O(1)摊还  扩容时为O(n) 尾插
//pop_back   O(1)				尾删
//insert(pos, val)	O(n)		定插
//erase(pos)	O(n)			定删
//[i]/at(i)		O(1)			随机访问
//clear()		O(n)			析构每个元素，不释放内存
//reserve(n)	O(n)			提前分配内存，防止频繁扩容
//shrink_to_fit O(n)			把capacit缩小到size

//拷贝&移动
//std::vector在扩容或复制时：
//优先使用移动构造（如果元素支持移动），否则会调用拷贝构造
//所以当存放复杂对象时，建议实现移动构造和移动复制，可以加速扩容和插入

//vector适用场景
//1.索引访问O(1)
//用于存储大量数据并频繁读取的场景，例如图像像素、顶点数组、地图格子等。
//2.动态增长
//3.读多写少
//4.可以拿到底层裸指针
//5.希望使用STL算法库
//不适合的场景
//1.频繁在中间插入、删除
//2.需要保持插入顺序或快速查找
//3.元素数量频繁增减，且大小变化极大
//4.多线程并发修改

//practice1:整数集合类
//使用std::vector实现一个简单的整数集合类IntSet，支持以下操作：
//添加整数，删除指定整数，打印所有元素，返回所有整数的和
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
//practice2.用vector实现栈
//要求：实现一个Stack类，支持push，pop, top, empty
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

//practice3 vector模拟学生信息系统
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

