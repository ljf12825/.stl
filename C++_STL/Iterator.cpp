//�������Ƿ���������Ԫ�ص�һ����Ҫ���ߡ�����Ϊ�����ṩ��һ��ͳһ�ķ�ʽ��������ͬ�����е�Ԫ�أ�������Ҫ֪�������ĵײ�ʵ��
//��������һ���࣬���ṩ�˷�������Ԫ�صĽӿڡ�
//������������ָ��һ���ƶ��������á��Ƚϵ�
//�����ṩ��һ������㣬ʹ���ܹ�����ͬ�ķ�ʽ����ͬ������

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

//std::vector<int> vec = { 1, 2, 3, 4, 5 };
//std::vector<int>::iterator it;
//
//int main()
//{
//	for (it = vec.begin(); it != vec.end(); ++it)
//	{
//		std::cout << *it << " ";
//	}
//	return 0;
//}

//������������(ȡ������������)
//1.�����������ֻ�ܵ��������������ȡԪ�أ�������ֻ������
//2.�����������ֻ�ܵ������������д��Ԫ�أ�������ֻд����
//3.ǰ���������֧�ֵ���������������ܹ���ζ�ȡ��ͬ��Ԫ�أ������ڴ����������֧�ֶ�д����
//4.˫���������֧��˫�����������������ǰ������ƶ���������std::list��һЩ��������
//5.������ʵ�������֧����ָ��һ��������λ�÷��ʣ��ܹ�֧�ּӷ������������㣻������std::vector��std::deque������

//�������ĳ��ò���
//++, --, *, ->, ==, !=

//begin() ����ָ��������һ��Ԫ�صĵ�����
//end() ����ָ������ĩβ��Ԫ�صĵ�����
//cbegin() ���س����汾��begin
//cend() ���س����汾��end
//rbegin() �����������ָ�����һ��Ԫ��
//rend() �����������ĩβǰԪ��
//crbegin() ��������begin
//crend() ��������end

//��������������<iterator>
//std::advanced(it, n) �ѵ�����itǰ��n��
//std::next(it, n) ����itǰ��n������µ�����
//std::prev(it, n) ����it����n������µ�����
//std::distance(it1, it2) ����it1��it2�ľ���

//������������
//���ǲ���ԭ�������������ǡ�α�����������������ִ��*it = valueʱ�������value���뵽������
//std::back_inserter(container) ����һ��back�����������Ҫ��������push_back����
std::vector<int> src = { 1,2,3 };
std::vector<int> dest;
std::vector<int> destination = { 10, 20 };
//int main()
//{
//	std::copy(src.begin(), src.end(), std::back_inserter(dest));
//	//dest = {1, 2, 3}
//	return 0;
//}

//std::front_inserter(container) ����front��������
//dest = {3, 2, 1}

//std::inserter(container, pos) ��ָ��λ�ò���
//int main()
//{
//	std::copy(src.begin(), src.end(), std::inserter(destination, destination.begin()));//��������е�����ʼ��ָ��10
//	for (auto i : destination)
//		std::cout << i << " ";
//	std::cout << "\n";
//	return 0;
//}

//����/�����������<iterator>
//std::istream_iterator<T> ���������ж�ȡ����ΪT������
//std::ostream_iterator<T> ���������д��T��������

//int main()
//{
//	std::istream_iterator<int> in(std::cin), eof;
//	//in��һ������������������std::cin�ж�ȡint���͵����ݣ�eof��Ĭ�Ϲ���ĵ���������ʾ�����������־��
//	//std::istream_iterator�ѱ�׼����std::cin����һ�����������е�����ȡ����
//	std::vector<int> nums(in, eof);//�����������ݴ���nums��
//
//	std::sort(nums.begin(), nums.end());
//
//	std::ostream_iterator<int> out(std::cout, " ");//out�������������������������std::coutд������
//	std::copy(nums.begin(), nums.end(), out);//��nums�е�����д��std::cout��
//
//	return 0;
//}

//����������(const_iterator)
//������ͨ���������޸�Ԫ��
std::vector<int> vec = { 1, 2, 3, 4, 5 };
std::vector<int>::const_iterator it = vec.begin();

//���������(reverse_iterator)
std::vector<int>::reverse_iterator rit = vec.rbegin();

//������ʧЧ
//�������ṹ�����ı�ʱ��ԭ��ָ��������ĵ��������ܱ����Ч
//��ʱ������ʹ����Щ�������ᵼ��UB

//��α��������ʧЧ
//�޸�����ǰ����Ԫ��ֵ�������������������
//ʹ��auto it = container.erase(it);���ַ����µ������ķ�ʽ��������
//���������ڱ����������޸������ṹ
//ʹ��list/map����������ȶ��Ըߵ����������������ʧЧ����

//example
std::vector<int> v = { 1, 2, 3, 4, 5 };
//int main()
//{
//	for (auto it = v.begin(); it != v.end(); )
//	{
//		//if (*it == 3) v.erase(it);//it��erase�ˣ�����++it��UB
//		if (*it == 3) it = v.erase(it);//�����µ�����
//		else ++it;
//	}
//	return 0;
//}