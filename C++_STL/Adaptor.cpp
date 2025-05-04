//适配器
//适配器是一种包装器，它把一个已有的组件，适配成另一个接口或行为，使得它可以在不同场景下复用
//在STL中，适配器本质上是通过模板封装已有对象，重新定义其部分接口，用来适配新的用途

//容器适配器
//通过封装已有容器，隐藏它的大部分成员函数，只暴露特定接口，来构造新容器


//迭代器适配器
//通过更改标准迭代器的行为，使其具有不同的访问方式或数据方向，常用于算法或流操作中
//迭代器适配器的本质是类模板，内部保存一个原始迭代器，通过重新定义operator操作符来适配行为

//std::reverse_iterator
template <typename Iterator>
class reverse_iterator
{
protected:
	Iterator current;//原始迭代器

public:
	explicit reverse_iterator(Iterator it) : current(it) {}

	//解引用，返回迭代器指向的元素
	typename Iterator::reference operator*() const
	//Iterator::reference 
	//std::container<T>::iterator
	//using reference = T&
	{
		Iterator temp = current;
		return *--temp;//从.end()前移一位
	}

	//迭代器前进，实际是current后退
	reverse_iterator& operator++()
	{
		--current;
		return *this;
	}

	//后置++
	//语义为返回操作前的“旧值”副本，而不是当前对象
	reverse_iterator operator++(int)//int为语法标记，唯一作用是让编译期区分前置和后置运算符重载
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

	// 重载赋值运算符：将值插入容器，核心操作
	back_insert_iterator& operator=(const typename Container::value_type& value) {
		container->push_back(value);
		return *this;
	}

	// 所有操作符都返回自身，适配算法接口，不是核心，没有任何作用
	back_insert_iterator& operator*() { return *this; }
	back_insert_iterator& operator++() { return *this; }
	back_insert_iterator operator++(int) { return *this; }
};

//函数适配器
//函数适配器用于修改函数或仿函数的行为或接口，特别是在泛型算法中
//它能把已有的函数、函数对象、成员函数等，包装成另一个具有特定行为的新仿函数对象
//std::bind 通用绑定器
//std::mem_fn 成员函数适配器
//std::function 通用函数对象封装器

//std::bind
#include <functional>
#include <algorithm>
#include <iostream>

//bool greater_than(int x, int y)
//{
//	return x > y;
//}
//
//auto f = std::bind(greater_than, std::placeholders::_1, 10); //等价于 f(x) = x > 10
//
//std::vector<int> v = { 5, 15, 8, 20 };
//auto it = std::find_if(v.begin(), v.end(), f);


