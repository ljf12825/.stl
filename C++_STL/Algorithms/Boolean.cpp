#include <iostream>
#include <algorithm>
#include <vector>

//partition
//�������ֳ�������
//һ����������������һ���ֲ���������
//in-place
//���ȶ�
template<class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p);
//first, last��Ҫ����������
//p:һԪν�ʣ�����bool�ĺ�����lambda�����ж�ÿ��Ԫ���Ƿ���������
//����ֵ����һ��������������Ԫ�صĵ����������ڶ����ֵ���㣩
//int main()
//{
//	std::vector<int> v = { 1, 2, 3, 4, 5, 6 };
//
//	auto it = std::partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
//	//[begin it - 1][it end]//ż����ǰ
//
//	return 0;
//}
//ϣ�������ȶ�����ʹ��stable_partition

//all_of
//����Ԫ�ض���������
template<class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p);
//����ֵ���������Ԫ�ض���������������true�����򷵻�false
//int main()
//{
//	std::string s = "HELLO";
//
//	bool allUpper = std::all_of(s.begin(), s.end(), [](char c) { return std::isupper(static_cast<unsigned char>(c)); });
//}

//any_of
//������һ��Ԫ����������

//none_of
//û��Ԫ����������

//is_partitioned
//�Ƿ��Ѿ����ֳ�����/����������
template<class ForwardIt, class UnaryPredicate>
bool is_partitioned(ForwardIt first, ForwardIt last, UnaryPredicate p);