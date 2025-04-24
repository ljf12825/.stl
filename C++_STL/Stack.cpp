#include <iostream>
#include <stack>
//std::stack是C++标准库中的一个容器适配器，它提供了栈数据结构的结构，即LIFO

std::stack<int> s;
//基本操作
//push() / pop()
//top() 返回栈顶元素
//empty() / size()
//emplace(args) 原地构造一个元素
//swap()

//std::stack并不是一个完整的容器，它是基于其他真正的容器封装出来的
//默认底层容器是std::deque
//当你写std::stack<int> s;
//其实相当于写：
//std::stack<int, std::deque<int>> s;//创建一个int类型的栈，用deque存数据
//也就是说，std::stack内部默认使用std::deque来存储元素
//你也可以使用其他标准容器作为底层 std::stack<int, std::vector<int>> s;
//限制条件
//并不是所有容器都能用来当底层，只有满足一下条件的容器才可以
//它必须支持这些操作：
//back() 获取栈顶元素
//push_back() push()
//pop_back() pop()
//empty()
//size()

//底层原理
//std::stack<T>并不自己存数据，而是委托底层容器去管理数据，它只是提供了“栈”的接口
template<class T, class Container = std::deque<T>>
class stack
{
protected:
	Container c; //实际数据存储位置

public:
	//类型定义
	using value_type = typename Container::value_type;
	using reference = typename Container::reference;
	using const_reference = typename Container::const_reference;
	using size_type = typename Container::size_type;
	//构造函数
	stack() = default;

	//栈操作
	bool empty() const { return c.empty(); }
	size_type size() const { return c.size(); }
	reference top() { return c.back(); }
	const_reference top() const { return c.back(); }
	void push(const value_type& value) { c.push_back(value); }
	void push(value_type&& value) { c.push_back(std::move(value)); }
	void pop() { c.pop_back(); }
	void swap(stack& other) noexcept(noexcept(std::swap(c, other.c))) { std::swap(c, other.c); }
};
//你可以把std::stack看作是对底层容器的一种“行为限制”
//这就是“容器适配器”概念：屏蔽底层容器的能力，只暴露我们需要的接口
