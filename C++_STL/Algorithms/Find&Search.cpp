#include <iostream>
#include <algorithm>

//find
//���ҵ���ĳֵ��Ԫ��
template<class InputIt, class T>
InputIt find(InputIt first, InputIt last, const T& value);
//[first, last)
//value:Ŀ��ֵ
//����ֵ��ָ���һ��ƥ��Ԫ�صĵ�����������Ҳ����ͷ���last
//O(n)

//find_if
//��������ĳ�����ĵ�һ��Ԫ��
template<class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p);
//����ֵ��ָ���һ������������Ԫ�صĵ����������û�ҵ�������last

//find_if_not
//���ҵ�һ��������ĳ������Ԫ��

//search
//�������в���������
template<class ForwardIt1, class ForwardIt2>
ForwardIt1 search(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2, ForwardIt2 last2);
//first1, last1:������
//first2, last2:������
//����ֵ��ָ�������е�һ�γ��ֵ�λ�õ��������������û���ҵ�������last
//���Զ����ж����
template<class ForwardIt1, class ForwardIt2, class BinaryPredicate>
ForwardIt1 search(ForwardIt1 first1, ForwardIt1 last1, ForwardIt2 first2, ForwardIt2 last2, BinaryPredicate p);

//binary_search
//�ж������������Ƿ����ĳ��ֵ
//ʹ�ö��ֲ����ж�һ��ֵ�Ƿ������һ������������
//�����ҵķ�Χ������������ģ�����򰴶�����򣩣�������δ����
//O(log n)
template<class ForwardIt, class T>
bool binary_search(ForwardIt first, ForwardIt last, const T& value);
//����
//�����Զ���Ƚ���
template<class ForwardIt, class T, class Compare>
bool binary_search(ForwardIt first, ForwardIt last, const T& value, Compare comp);