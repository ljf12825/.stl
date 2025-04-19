#include <iostream>
#include <vector>

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
			reserve(capacity == 0 ? 1 : capacity * 2)//分配新空间
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


//常用操作
//push_back  时间复杂度：O(1)摊还  扩容时为O(n)尾插
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

