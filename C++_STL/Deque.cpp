//std::deque（double ended queue）双端队列
//特点：可以在头部和尾部都快速插入/删除元素，支持随机访问
//deque在物理上是不连续的内存，而是分块的内存结构（块表 + 指针）

#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
//声明
std::deque<int> dq;

//std::deque的底层实现原理
//底层结构：分段连续内存 + 指针数组
//控制中心（map数组）--->指向多个固定大小的内存块（block）：
//┌─────┐
//│ ptr ├───►[block1]
//├─────┤
//│ ptr ├───►[block2]
//├─────┤
//│ ... │
//└─────┘
//控制结构的动态增长机制
//当deque的头或尾增长超过了当前map的范围，它会
//1.分配新的map指针数组（通常是原来的两倍）
//2.把旧的指针搬进去
//3.在前面或后面空出更多空间用于扩展


//基本操作
//push_back(1) //尾插
//push_front(2) //头插
//pop_back() //尾删
//pop_front() //头删

//deque的应用
//滑动窗口最大值（单调队列）
//给定一个整数数组nums和一个窗口大小k，从左到右滑动这个窗口，每次移动一格，输出窗口中的最大值
//输入: nums = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
//输出 : [3, 3, 5, 5, 6, 7]
//Solution1 暴力解法 O(nk) （nums或k很大时容易超时）
std::vector<int> maxSlidingWindow_brute(const std::vector<int>& nums, int k)
{
	std::vector<int> result;
	for (int i = 0; i <= nums.size() - k; ++i)
	{
		int maxVal = nums[i];
		for (int j = i + 1; j < i + k; ++j)
		{
			maxVal = std::max(maxVal, nums[j]);
		}
		result.push_back(maxVal);
	}
	return result;
}

//Solution2 单调队列
//核心思想：维护一个“单调递减的双端队列”，队列里存的是下标索引，它能快速找到当前窗口的最大值，并快速滑动窗口。
//单调队列维护规则：
//从队尾弹出小于当前元素的下标（保持递减）
//队首元素是否过期（即下标已经滑出窗口范围）？是的话就弹出；
//队首就是当前滑动窗口最大值的下标

std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k)
{
	std::deque<int> dq;//存下标
	std::vector<int> result;

	for (int i = 0; i < nums.size(); ++i)
	{
		//1.保证队尾单调递减
		while (!dq.empty() && nums[dq.back()] <= nums[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);

		//2.如果队首元素已经滑出窗口，弹出它
		if (dq.front() <= i - k) dq.pop_front();

		//3.当窗口形成，记录最大值（队首）
		if (i >= k - 1) result.push_back(nums[dq.front()]);
	}
	return result;
}

//Solution3 排序输出
int getElementBySlidingCount(std::vector<int> nums, int k)
{
	if (k <= 0 || k > nums.size())
	{
		std::cerr << "非法窗口大小\n";
		return -1;
	}
	int slideCount = nums.size() - k + 1;
	std::sort(nums.begin(), nums.end());
	
	if (slideCount > nums.size())
	{
		std::cerr << "滑动次数超过数组长度\n";
		return -1;
	}
	return nums[slideCount - 1];
}


//deque模拟一个任务调度队列，用户可以插入高优先任务（前面）或低优先任务（后面）
class TaskList
{
private:
	struct Task
	{
		bool priority;
		int task;
	};
	std::deque<Task> dq;
public:
	std::deque<int> insert(Task task)
	{
		if (task.priority) dq.push_front(task);
		else dq.push_back(task);
	}
};

//模拟一个“浏览器历史记录系统”，能前进、后退
class Browser
{
private:
	std::deque<std::string> history;
	int currentIndex = -1;
public:
	void visit(const std::string& url)
	{
		//如果访问顺序：A->B->C
		//如果退回A后再新打开网址D
		//A->D,B和C被清除，你的新的行为改变了时间线
		while ((int)history.size() > currentIndex + 1) history.pop_back();
		history.push_back(url);
		currentIndex++;
		std::cout << "访问网页： " << url << "\n";
	}
	//后退
	void back()
	{
		if (currentIndex > 0)
		{
			currentIndex--;
			std::cout << "后退到： " << history[currentIndex] << "\n";
		}
		else std::cout << "已经在最早页面，无法后退。\n";
	}
	//前进
	void forward()
	{
		if (currentIndex + 1 < (int)history.size())
		{
			currentIndex++;
			std::cout << "前进到： " << history[currentIndex] << "\n";
		}
		else std::cout << "已经在最新页面，无法前进。\n";
	}
	//当前页面
	void current() const
	{
		if (currentIndex >= 0 && currentIndex < (int)history.size())
			std::cout << "当前页面： " << history[currentIndex] << "\n";
		else std::cout << "当前没有任何页面。\n";
	}
};

//实现一个LRU Cache（最少使用缓存淘汰）
//当容量已满时，淘汰最久未使用的数据项
class LRUCache
{
private:
	std::deque<std::pair<int, int>> cache;//{k, v}
	int capacity;
public:
	LRUCache(int capacity) : capacity(capacity) {};
	void put(int key, int value)
	{
		for (auto it = cache.begin(); it != cache.end(); ++it)
		{
			if (it->first == key)//插入相同的key，相当于增加该key的热值
			{
				cache.erase(it);//前置该key
				break;
			}
		}
		if ((int)cache.size() >= capacity) cache.pop_back();
		cache.push_front({ key, value });
	}
	int get(int key)
	{
		for (auto it = cache.begin(); it != cache.end(); ++it)
		{
			if (it->first == key)
			{
				int value = it->second;
				cache.erase(it);
				cache.push_front({ key, value });
				return value;

			}
		}
		return -1;
	}
	void print() const
	{
		std::cout << "缓存： ";
		for (const auto& [k, v] : cache) std::cout << "[" << k << ":" << v << "]";
		std::cout << "\n";
	}
};