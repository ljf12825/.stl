#include <span>
#include <iostream>
#include <vector>

//std::span��C++20�����һ����������ͼ���������ڲ�ӵ�����ݵ�������ͼ��
//����һ��ֻ�����д��ָ�� + ���ȣ�����������ȫ�ط������顢std::vector������

template<
	class T,
	std::size_t Extent = std::dynamic_extent
> class span;

//void print(std::span<int> s)
//{
//	for (int x : s)
//		std::cout << x << " ";
//	std::cout << "\n";
//}
//
//int main()
//{
//	std::vector<int> v = { 1, 2, 3, 4, 5 };
//	print(v);
//
//	int arr[] = { 6, 7, 8 };
//	print(arr);
//
//	print(std::span<int>(v.begin(), 3));
//
//	return 0;
//}

//���ù���
int arr[5] = { 1, 2, 3, 4, 5 };
std::span<int> s1(arr);
std::span<int> s2(arr, 3);
std::span<int> s3 = std::span{ arr };

//��������ͼ
auto sub = s1.subspan(1, 3);

//spanû�����ݸ��Ƴɱ���ֻ��һ���������Ӵ�
//spanͳһ�˺����������������Ľӿ�
//span�߽簲ȫ��֧��at��debug��飬���ڵ���ģʽ�´����߽�Խ�����
//span���Խ���������Ƭ
//span֧�ַ�Χfor