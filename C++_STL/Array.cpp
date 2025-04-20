#include <iostream>
#include <array>
#include <algorithm>
#include <limits>

//std::array(C++11)
//array��ʾһ���̶���С�����飬�ṩ�˱�C����������ȫ�������Ľӿ�

//std::array�Ķ���
template<typename T, std::size_t N>
struct _array_;

//��C style�������
// array<>�� T[]��С���ǹ̶���
// array<>���Կ������ƣ���T[]����
// array<>֧��STL�㷨��T[]��֧��
// array<>������Ϊֵ���ݲ��������˻���T[]����˻�Ϊָ��

//std::array���ó�Ա����
//arr.size() ���ش�С
//arr.front() ��һ��Ԫ��
//arr.back() ���һ��Ԫ��
//arr.empty() �Ƿ�Ϊ��
//arr.at() ��ȫ���ʣ���Խ����
//arr.fill() ȫ������
//arr.swap(other) ����һ��array����

//arrayʹ�ó���
//�̶����������ڴ�������Ч�ʸ�
//������ָ������ڴ�
//ϣ������STL���㷨
//��Ҫ����ȫ�����ɶ��Ĵ������C�������

//std::array<int, 5> arr = {};//{}(C++11)ͳһ��ʼ����{}�ᴥ��array�Ĺ��캯����array�Ĺ��캯��Ĭ�ϳ�ʼ��Ϊ0
//int main()
//{
//	for (const auto& i : arr)
//	{
//		std::cout << i << " ";
//	}
//	return 0;
//}

//C++ԭ������
//template<typename T>
//T arr[];
//û�з�Χ���
//��������ָ����Ԫ�ص�ָ��
//
//��ά����
//int arr_2[3][4];//[��][��]
//����ʱ��ʼ����ͨ��forfor����Ԫ�ظ�ֵ

//��̬����
int* arr_ptr = new int[5];
int main()
{
	//delete arr_ptr;//error
	delete[] arr_ptr;
}

//int main()
//{
//	arr_2 =//C++�е�ԭ�����鲻�Ǹ�ֵ���ݵĶ��󣨲��������std::array,Ҳû������operator=�������Բ���ֱ�Ӹ��������鸳ֵ��
//	{
//		{1, 2, 3, 4},
//		{5, 6, 7, 8},
//		{9, 10, 11, 12}
//	};
//
//	std::array<std::array<int, 4>, 3> arr_3;
//	arr_3 =//std::array����
//	{ {
//		{{1, 2, 3, 4}},
//		{{4, 5, 6, 7}},
//		{{8, 9, 10, 11}}
//	} };
//	return 0;
//}

//practice1���鷴ת
//��дһ������������һ��std::array<int, 5>,�����������ݾ͵ط�ת
std::array<int, 5> arr_1 = { 1, 2, 3, 4, 5 };
std::array<int, 5> reverse(std::array<int, 5> arr)
{
	std::array<int, 5> temp;
	for (int i = 0; i < 5; ++i)
	{
		temp[i] = arr[4 - i];
	}
	return temp;
}
//�Ż�
template<typename T, std::size_t N>
std::array<T, N> reverse(std::array<T, N> arr)
{
	std::array<T, N> temp;
	for (int i = 0; i < N; ++i)
		temp[i] = arr(N - 1 - i);//���䷴ת����д��
	return temp;
}

//practice2���ֵ����Сֵ
//����һ��std::array<int, 6>,�ҳ��������ֵ����Сֵ�����
std::array<int, 6> arr_2 = { 3, 7, 1, 9, 4, 2 };
void Max_Min(std::array<int, 6> arr)
{
	int max = 0;
	int min = INT_MAX;
	for (auto i : arr)
	{
		if (max < i) max = i;
		if (min > i) min = i;
	}
	std::cout << max << " " << min << std::endl;
}
//�Ż�
template<typename T, std::size_t N>
void Max_Min(const std::array<T, N>& arr)
{
	//���Ͱ�ȫ
	T max = std::numeric_limits<T>::lowest();//���ص���T�����ܱ�ʾ����Сֵ
	T min = std::numeric_limits<T>::max();//���ص���T�����ܱ�ʾ�����ֵ
	for (const auto& i : arr)
	{
		if (i > max) max = i;
		if (i < min) min = i;
	}
}

//practice3Ԫ�ز���
//��дһ���������ж�һ�����������Ƿ�����������У����������������±�
std::array<int, 5> arr_3 = { 10, 20, 30, 40, 50 };
int target = 30;
void match(std::array<int, 5> arr)
{
	int index = 0;
	for (auto i : arr)
	{
		if (target == i) break;
		index++;
	}
	std::cout << "Found at index " << index << std::endl;
}
//�Ż�
void match(const std::array<int, 5>& arr, int target)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == target)
		{
			std::cout << i << std::endl;
			return;
		}
	}
	std::cout << "Not found" << std::endl;
}
//�Ż�2
void match(const std::array<int, 5>& arr, int target)
{
	auto it = std::find(arr.begin(), arr.end(), target);//����ҵ��ˣ�itָ���Ԫ�ص�λ�ã����û�ҵ���itָ��.end()
	if (it != arr.end())
	{
		std::cout << std::distance(arr.begin(), it) << std::endl;//����Ԫ��λ��
	}
	else
	{
		std::cout << "Not found" << std::endl;
	}
}

//practice4ͳ��ż������
//��д������ͳ��std::array<int, 10>���ж��ٸ�ż��
int Evennum(std::array<int, 10> arr)
{
	int flag = 0;
	for (auto i : arr)
	{
		if (i % 2 == 0) flag++;
	}
	return flag;
}
//�Ż�
template<typename T, std::size_t N>
int Evennum(const std::array<T, N>& arr)
{
	int flag = 0;
	for (auto i : arr)
	{
		if (i % 2 == 0) flag++;
	}
	return flag;
}

//practice5ʹ��std::sort�����ַ�������
//����һ���ַ������飬����ĸ��˳����������
std::array<std::string, 4> names = { "Zoe", "Alice", "Eve", "Bob" };
std::array<std::string, 4> sortname(std::array<std::string, 4> arr)
{
	std::sort(arr.begin(), arr.end(), [](std::string a, std::string b) {
		char A = std::tolower(a[0]);
		char B = std::tolower(b[0]);
		return A < B;
		});
	return arr;
}
//�Ż�
template<std::size_t N>
std::array<std::string, N> sortname(std::array<std::string, N> arr)
{
	std::sort(arr.begin(), arr.end(), [](const std::string& a, const std::string& b) {
		return std::tolower(static_cast<unsigned char>(a[0])) < std::tolower(static_cast<unsigned char>(b[0]);
		});
	//ʹ��std::tolower��ȷ��char��unsigned char����ֹUB��
	return arr;
}

//AddOnģ�����Ԫ��
//std::array���й̶���С���������㲻�������Ԫ�ء���������취������һ��Ԫ�ء������Ѻ��������Ųλ���𣿼��������У�
//std::array<int, 5> arr = {1, 2, 3, 4, 0}//���һλ�ճ���
//��Ҫ������99���뵽�±�2��1�� 2�� 99�� 4�� 0��
std::array<int, 5> arr_4 = { 1, 2, 3, 4, 0 };//���һλ�ճ���
std::array<int, 6> insert(std::array<int, 5> arr, int position, int number)
{
	std::array<int, 6> temp;
	temp.fill(0);
	if (position == 0)
	{
		temp[position] = number;
		for (int i = 0; i < arr.size(); i++)
		{
			temp[i + 1] = arr[i];
		}
	}
	else if (position == 6)
	{
		for (auto i : arr)
		{
			temp[i] = arr[i];//error
		}
		temp[position] = number;
	}
	else if(position > 0 && position < 6)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (i < position)
			{
				temp[i] = arr[i];
			}
			if (i == position)
			{
				temp[position] = number;
			}
			if (i > position)
			{
				temp[i] = arr[i - 1];
			}
		}

	}
	return temp;
}
//�Ż�
std::array<int, 6> insert(const std::array<int, 5>& arr, int position, int number)
{
	std::array<int, 6> temp;
	temp.fill(0);

	if (position < 0 || position > 5)
	{
		std::cerr << "Invalid position" << std::endl;
		return temp;
	}

	for (int i = 0; i < position; ++i)
	{
		temp[i] = arr[i];
	}
	temp[position] = number;
	for (int i = position; i < 5; ++i)
	{
		temp[i + 1] = arr[i];
	}
	return temp;
}
