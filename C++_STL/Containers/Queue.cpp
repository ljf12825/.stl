#include <iostream>
#include <queue>
//std::queue是STL中的一个容器适配器，它实现了队列FIFO数据结构
//std::queue依赖于底层的容器（默认为std::deque）来存储数据。
std::queue<int> q;
//基本操作
//push() //尾部入队
//pop() //头部出队
//front() //返回队头元素
//back() //返回队尾元素
//empty()/size()

//std::queue常见应用场景
//1.任务调度，2.宽度优先搜索（BFS）3.缓冲区

//底层实现
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