#include <iostream>
#include <numeric>
#include <vector>

//accumulate
//�ۼ�(�ۺ���������)
template<class InputIt, class T, class BinaryOperation>
T accumulate(InputIt first, InputIt last, T init, BinaryOperation op);
//[first, last)
//init:��ʼֵ������ʱ������init��ʼ��
//op����Ԫ��������ӷ����˷��ȣ�����������е�ÿ��Ԫ���뵱ǰ���������
//�������ռ�����
//ȱʡ��ʽ���ӷ���
template<class InputIt, class T>
T accumulate(InputIt first, InputIt last, T init);

//int main()
//{
//	std::vector<int> vec = { 1, 2, 3, 4, 5 };
//	auto i = std::accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>());
//	std::cout << i << std::endl;
//}

//inner_product
//���ڻ�
//ȱʡ��ʽ��init += a * b
template<class InputIt1, class InputIt2, class T>
T inner_product(InputIt1 first1, InputIt1 last1, InputIt2 first2, T init);
//int main()
//{
//	std::vector<int> a = { 1, 2, 3 };
//	std::vector<int> b = { 4, 5, 6 };
//
//	int result = std::inner_product(a.begin(), a.end(), b.begin(), 0);
//	//0 + 1 * 4 + 2 * 5 + 3 * 6��
//}

//�Զ���˷��ͼӷ���ʽ
template<class InputIt1, class InputIt2, class T, class BinaryOp1, class BinaryOp2>
T inner_product(InputIt1 first1, InputIt1 last1, InputIt2 first2, T init, BinaryOp1 op_add, BinaryOp2 op_mult);
//int main()
//{
//	std::vector<int> a = { 1, 2, 3 };
//	std::vector<int> b = { 4, 5, 6 };
//	int result = std::inner_product(a.begin(), a.end(), b.begin(), 0, std::minus<int>(), std::multiplies<int>());
//	//0 - 1 * 4 - 2 * 5 - 3 * 6
//}

//partial_sum
//�ֲ���
//ȱʡ��ʽ���ӷ���
template<class InputIt, class OutputIt>
OutputIt partial_sum(InputIt first, InputIt last, OutputIt d_first);
//i1, (i1 + i2), (i1 + i2 + i3), ...
template<class InputIt, class OutputIt, class BinaryOperation>
OutputIt partial_sum(InputIt first, InputIt last, OutputIt d_first, BinaryOperation op);

//adjacent_difference
//����Ԫ�ز�
template<class InputIt, class OutputIt>
OutputIt adjacent_difference(InputIt first, InputIt last, OutputIt d_first);
//i1, i2 - i1, i3 - i2, ...

template<class InputIt, class OutputIt, class BinaryOperation>
OutputIt adjacent_difference(InputIt first, InputIt last, OutputIt d_first, BinaryOperation op);