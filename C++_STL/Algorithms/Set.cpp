#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

//set_union
//����
//Ҫ���������б�������
//O(n + m)
//�����ظ���ȡ��ߴ���
//����ͨ�����������д������
template<class InputIt1, class InputIt2, class OutputIt>
OutputIt set_union(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, OutputIt d_first);

//�Զ���Ƚ����汾
//������Զ������ͣ���ṹ�壩������������ʹ�ô��Ƚ����İ汾
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
//����
template<class InputIt1, class InputIt2, class OutputIt>
OutputIt set_intersection(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first);

template<class InputIt1, class InputIt2, class OutputIt, class Compare>
OutputIt set_intersection(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first,
    Compare comp);
//Ҫ�������������б�����������ģ��Ұ���ͬ��������
//���Ԫ���ظ����������ظ������е�Ԫ���������

//set_difference
//�
template<class InputIt1, class InputIt2, class OutputIt>
OutputIt set_difference(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first);

template<class InputIt1, class InputIt2, class OutputIt, class Compare>
OutputIt set_difference(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first,
    Compare comp);
//Ҫ���������뷵�ض����������
//A����B��û�е�Ԫ�ؼ�A - B

//set_symmetric_difference
//�ԳƲ�
template<class InputIt1, class InputIt2, class OutputIt>
OutputIt set_symmetric_difference(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first);

template<class InputIt1, class InputIt2, class OutputIt, class Compare>
OutputIt set_symmetric_difference(InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2,
    OutputIt d_first,
    Compare comp);
//Ҫ���������б�����������ģ������������һ��
//(A��B) - (A��B)