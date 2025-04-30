#include <iostream>
#include <algorithm>

//count
//ͳ��ĳ��ֵ������
template <class InputIt, class T>
typename std::iterator_traits<InputIt>::difference_type
count(InputIt first, InputIt last, const T& value);

//count_if
//ͳ������ĳ����������
template <class InputIt, class UnaryPredicate>
typename std::iterator_traits<InputIt>::difference_type
count_if(InputIt first, InputIt last, UnaryPredicate p);
//p:һԪν�ʣ�����true��ʾ��Ԫ��Ӧ��ͳ��

//min_element
//����СԪ��
template <class ForwardIt>
ForwardIt min_element(ForwardIt first, ForwardIt last);

template <class ForwardIt, class Compare>
ForwardIt min_element(ForwardIt first, ForwardIt last, Compare comp);


//max_element
//�����Ԫ��
template <class ForwardIt>
ForwardIt max_element(ForwardIt first, ForwardIt last);

template <class ForwardIt, class Compare>
ForwardIt max_element(ForwardIt first, ForwardIt last, Compare comp);


//equal
//�ж����������Ƿ����
//��Ԫ�����
// �汾 1���Ƚ�������Χ��ÿ��Ԫ���Ƿ����
template <class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2);

// �汾 2���Զ���ȽϷ�ʽ
template <class InputIt1, class InputIt2, class BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p);
