#include <iostream>
#include <algorithm>
#include <vector>

//sort
//Ĭ�������������
//����˿������򡢶�����Ͳ�������
//Ĭ��ʹ�ÿ�������
//���ݹ����ʱ���л�Ϊ������
//��С���飨�糤��<16��ʹ�ò�������
//�Ƚ������������ϸ�����
//ʱ�临�Ӷ�O(n log n)
//�ռ临�Ӷ�O(log n)
template< class RandomIt >
void sort(RandomIt first, RandomIt last);

template< class RandomIt, class Compare >
void sort(RandomIt first, RandomIt last, Compare comp);


//stable_sort
//����˳�������
//���ù鲢����
//ʱ�临�Ӷ�O(n log n)
//�ռ临�Ӷ�O(n)
template<class RandomIt>
void stable_sort(RandomIt first, RandomIt last);

template<class RandomIt, class Compare>
void stable_sort(RandomIt first, RandomIt last, Compare comp);


//partial_sort
//�ֲ�����
template<class RandomIt>
void partial_sort(RandomIt first, RandomIt middle, RandomIt last);

template<class RandomIt, class Compare>
void partial_sort(RandomIt first, RandomIt middle, RandomIt last, Compare comp);
//ֻ��first - middle
//ʣ�ಿ�ֲ���֤˳��Ҳ������ȫ����
//������ֻ����ǰN�����ݵ����
//ʱ�临�Ӷ�O(n log N)

//nth_element
//ʹ��nС��Ԫ�ؾ�λ
template<class RandomIt>
void nth_element(RandomIt first, RandomIt nth, RandomIt last);

template<class RandomIt, class Compare>
void nth_element(RandomIt first, RandomIt nth, RandomIt last, Compare comp);
//�ҵ���NС���󣩵�Ԫ�أ���������õ���������ȷ��λ�ã�������������е�N��λ�ã�������Ԫ�ص�˳��û����ȫ����
//ʱ�临�Ӷ�O(n)

//is_sorted
//�ж��Ƿ�������
//���ⲻ��Ҫ������
template<class ForwardIt>
bool is_sorted(ForwardIt first, ForwardIt last);

template<class ForwardIt, class Compare>
bool is_sorted(ForwardIt first, ForwardIt last, Compare comp);


//next_permutation
//��һ���ֵ�������
//������һ��������Χ������������Ԫ��������һ�����У�����true����ɹ���������һ�����У�����false����Ѿ������������һ������
template<class BidirectionalIt>
bool next_permutation(BidirectionalIt first, BidirectionalIt last);

template<class BidirectionalIt, class Compare>
bool next_permutation(BidirectionalIt first, BidirectionalIt last, Compare comp);
//����ԭ��
//1.�Ӻ���ǰ����Ԫ�ضԣ������������һ��Ԫ�ؿ�ʼ���ҵ�һ��Ԫ�أ�����������Ԫ��С
//2.����Ԫ�أ��ҵ�һ���������Ԫ�ش����СԪ�ز���������
//3.����˳�򣺽�Ԫ�غ���Ĳ�����������Ϊ��С����������

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
