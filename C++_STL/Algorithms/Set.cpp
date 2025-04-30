#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//set_union
//并集
//要求输入序列必须有序
//O(n + m)
//允许重复，取最高次数
//必须通过输出迭代器写入容器
template<class InputIt1, class InputIt2, class OutputIt>
OutputIt set_union(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first);

//自定义比较器版本
//如果是自定义类型（如结构体）或降序容器，可使用带比较器的版本
template<class InputIt1, class InputIt2, class OutputIt, class Compare>
OutputIt set_union(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first, Compare comp);

//struct Person
//{
//	std::string name;
//	int age;
//};
//
//bool compareByName(const Person& a, const Person& b)
//{
//	return a.name < b.name;
//}
//
//void print(const std::vector<Person>& people)
//{
//	for (const auto& p : people)
//		std::cout << p.name << "(" << p.age << ") ";
//	std::cout << "\n";
//}
//
//int main()
//{
//	std::vector<Person> group1 = { {"Alice", 30}, {"Charlie", 28} };
//	std::vector<Person> group2 = { {"Bob", 25}, {"Charlie", 35} };
//
//	std::sort(group1.begin(), group2.end(), compareByName);
//	std::sort(group2.begin(), group2.end(), compareByName);
//
//	std::vector<Person> result;
//
//	std::set_union(group1.begin(), group1.end(), group2.begin(), group2.end(), std::back_inserter(result), compareByName);
//
//	print(result);
//
//	return 0;
//}

//set_intersection
//交集
template<class InputIt1, class InputIt2, class OutputIt>
OutputIt set_intersection(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first);

template<class InputIt1, class InputIt2, class OutputIt, class Compare>
OutputIt set_intersection(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first,
    Compare comp);
//要求：输入两个序列必须是已排序的，且按相同规则排序
//如果元素重复，按最少重复集合中的元素数量输出

//set_difference
//差集
template<class InputIt1, class InputIt2, class OutputIt>
OutputIt set_difference(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first);

template<class InputIt1, class InputIt2, class OutputIt, class Compare>
OutputIt set_difference(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first,
    Compare comp);
//要求：两个输入返回都是已排序的
//A中有B中没有的元素即A - B

//set_symmetric_difference
//对称差
template<class InputIt1, class InputIt2, class OutputIt>
OutputIt set_symmetric_difference(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first);

template<class InputIt1, class InputIt2, class OutputIt, class Compare>
OutputIt set_symmetric_difference(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first,
    Compare comp);
//要求：输入数列必须是已排序的，并且排序规则一致
//(A∪B) - (A∩B)