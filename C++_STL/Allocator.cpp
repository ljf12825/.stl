//分配器
//是一种内存分配策略的抽象机制
//它允许用户自定义STL容器如何分配和释放内存
//在STL中，每个容器都可以接收一个分配器类型作为模板参数，默认是std::allocator<T>，它使用::operator new 和 ::operator delete来分配和释放内存。
#include <iostream>
#include <new>
#include <vector>

template <class T, class Allocator = std::allocator<T>>
class vector;

//allocator的作用
//1.控制内存的分配与释放方式
//2.为容器中的元素分配原始内存（不构造对象）
//3.使用placement new构造对象，显示析构对象
//4.可以自定义行为（如内存池、调试信息、共享内存等）

//std::allocator<T>的基本接口
//template<typename T>
//struct MyAllocator
//{
//	using value_type = T;
//
//	MyAllocator() = default;
//
//	template<typename U>
//	MyAllocator(const MyAllocator<U>&) {}
//
//	T* allocate(std::size_t n)
//	{
//		return static_cast<T*>(::operator new(n * sizeof(T)));
//	}
//
//	void deallocate(T* p, std::size_t)
//	{
//		::operator delete(p);
//	}
//};
//
//int main()
//{
//	std::vector<int, MyAllocator<int>> vec;
//	vec.push_back(1);
//	vec.push_back(2);
//	return 0;
//}

//struct MyClass
//{
//	MyClass(int x) { std::cout << "Constructor: " << x << "\n"; }
//	~MyClass() { std::cout << "Destructor\n"; }
//};
//
//int main()
//{
//	//分配原始内存
//	auto raw = ::operator new(sizeof(MyClass));
//
//	//在指定地址上构造对象（placement new）
//	MyClass* obj = new (raw) MyClass(42);
//
//	//显式析构
//	obj->~MyClass();
//
//	//释放内存
//	::operator delete(raw);
//	return 0;
//}

//::operator new分配失败默认抛出std::bad_alloc异常
