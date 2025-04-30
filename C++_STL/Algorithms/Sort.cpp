#include <iostream>
#include <algorithm>
#include <vector>

//sort
//默认升序快速排序
//混合了快速排序、堆排序和插入排序
//默认使用快速排序
//当递归过深时，切换为堆排序
//对小数组（如长度<16）使用插入排序
//比较器必须满足严格弱序
//时间复杂度O(n log n)
//空间复杂度O(log n)
template< class RandomIt >
void sort(RandomIt first, RandomIt last);

template< class RandomIt, class Compare >
void sort(RandomIt first, RandomIt last, Compare comp);


//stable_sort
//保留顺序的排序
//采用归并排序
//时间复杂度O(n log n)
//空间复杂度O(n)
template<class RandomIt>
void stable_sort(RandomIt first, RandomIt last);

template<class RandomIt, class Compare>
void stable_sort(RandomIt first, RandomIt last, Compare comp);


//partial_sort
//局部排序
template<class RandomIt>
void partial_sort(RandomIt first, RandomIt middle, RandomIt last);

template<class RandomIt, class Compare>
void partial_sort(RandomIt first, RandomIt middle, RandomIt last, Compare comp);
//只排first - middle
//剩余部分不保证顺序，也不会完全排序
//适用于只关心前N个数据的情况
//时间复杂度O(n log N)

//nth_element
//使第n小的元素就位
template<class RandomIt>
void nth_element(RandomIt first, RandomIt nth, RandomIt last);

template<class RandomIt, class Compare>
void nth_element(RandomIt first, RandomIt nth, RandomIt last, Compare comp);
//找到第N小（大）的元素，并将其放置到容器中正确的位置（即排序后容器中第N个位置），其他元素的顺序并没有完全排序
//时间复杂度O(n)

//is_sorted
//判断是否已排序
//避免不必要的排序
template<class ForwardIt>
bool is_sorted(ForwardIt first, ForwardIt last);

template<class ForwardIt, class Compare>
bool is_sorted(ForwardIt first, ForwardIt last, Compare comp);


//next_permutation
//下一个字典序排列
//它接受一个容器范围，并重新排列元素生成下一个排列，返回true如果成功生成了下一个排列，或者false如果已经是容器的最后一个排列
template<class BidirectionalIt>
bool next_permutation(BidirectionalIt first, BidirectionalIt last);

template<class BidirectionalIt, class Compare>
bool next_permutation(BidirectionalIt first, BidirectionalIt last, Compare comp);
//工作原理
//1.从后向前查找元素对：从容器的最后一个元素开始，找到一个元素，它比其后面的元素小
//2.交换元素：找到一个比其后面元素大的最小元素并交换它们
//3.调整顺序：将元素后面的部分重新排列为最小的升序排列

int main()
{
	std::vector<int> vec = { 1, 2, 3, 4 };
	do
	{
		for (auto it : vec)
		{
			std::cout << it << " ";
		}

		std::cout << "\n";
	} while (std::next_permutation(vec.begin(), vec.end()));

	return 0;
}
