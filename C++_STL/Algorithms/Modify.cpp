#include <iostream>
#include <algorithm>
#include <vector>

//copy
//����Ԫ��
template<class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt d_first);
//[first, last)
//d_first:��ʾĿ���������ʼλ��
//����ֵ��ָ��Ŀ�����������һ�������Ƶ�Ԫ��֮���λ��
//std::copy_n ����ǰn��
//std::copy_if��������������Ԫ��

//move
//�ƶ�Ԫ��

//remove
//�Ƴ�ĳֵ�������erase
//����������ɾ��Ԫ�أ����ǽ�����Ҫ��Ԫ���Ƶ�ĩβ�����������߼�ĩβ�ĵ�����
template<class ForwardIt, class T>
ForwardIt remove(ForwardIt first, ForwardIt last, const T& value);
//����һ����������ָ���Ƴ���ġ����߼�ĩβ��

//replace
//�滻ĳֵΪ��ֵ
template<class ForwardIt, class T>
void replace(ForwardIt first, ForwardIt last, const T& old_value, const T& new_value);

//transform
//�������޸�����Ԫ��
//��һ����Χ�ڵ�Ԫ�����ת������ֵ����д����һ����Χ��������ԭ�أ�Ҳ��������������
//һԪ�汾
template<class InputIt, class OutputIt, class UnaryOperation>
OutputIt transform(InputIt first, InputIt last, OutputIt d_first, UnaryOperation unary_op);
//UnaryOperation��һ������������һ�����������ر任���
//std::vector<int> vec_1 = { 1, 2 , 3 , 4 , 5 };
//std::vector<int> vec_2(vec_1.size());
//
//int main()
//{
//	std::transform(vec_1.begin(), vec_1.end(), vec_2.begin(), [](int x) { return x * 2; });
//
//	return 0;
//}

//��Ԫ�汾
template<class InputIt1, class InputIt2, class OutputIt, class BinaryOperation>
OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryOperation binary_op);
//���ڷ������������Ԫ����ϳ��½��
//std::vector<int> result(vec_1.size());
//int main()
//{
//	std::transform(vec_1.begin(), vec_1.end(), vec_2.begin(), result.begin(), [](int x, int y) { return x + y; });
//	return 0;
//}

//fill
//ȫ��ĳ��ֵ
template<class ForwardIt, class T>
void fill(ForwardIt first, ForwardIt last, const T& value);

//generate
//�ú�����������
template<class ForwardIt, class Generator>
void gernerate(ForwardIt first, ForwardIt last, Generator g);
//g:�޲����ĺ�����lambda��ÿ�ε�������һ����ֵ
//int main()
//{
//	std::vector<int> v(5);
//	int n = 0;
//
//	std::generate(v.begin(), v.end(), [&n]() { return n++; });
//
//	return 0;
//}