#include <iostream>
#include <cstring>
//std::string
//string�Ķ���
//using std::string = std::basic_string<char>;
//Ҳ����˵��std::string������ʱһ����charΪ��λ���ַ�����ģ��ʵ��������std::basic_string���ػ��汾��string��α����
//string������C++�е��ڽ����ͣ�primitive type��


//���캯��
static std::string s1;//���ַ���
static std::string s2("hello");//��C�ַ�������
static std::string s3 = "world";//��ʽ����
static std::string s4(5, 'A');
static std::string s5(s2);//��������
static std::string s6 = s2 + s3;//ƴ��

//std::string�Ĳ���
//��������
//size()/length() �����ַ����ĳ���
//empty() �п�
//clear() ����
//resize(n) �ı��ַ������ȣ�Ĭ�ϳ���\0
//resize(n, c) ������չʱʹ���ַ�c����
//at() ��ȫ���ʣ�Խ���׳��쳣
//operator[] ����Խ����
//front() �������ַ����൱��str[0]
//back() str[str.size() - 1]
//operator+ ƴ��
//operator+= ׷��
//append(str) +=str
//append(str, pos, len) ׷��str���ִ�str.substr(pos, len)
//insert(pos, str)
//erase(pos, len)
//replace(pos, len, str)
//find(str) ����str��һ�γ��ֵ�λ�ã��Ҳ�������std::string::npos
//find(str, pos) ��pos��ʼ����str
//rfind(str) ����������
//find_first_of(str) ������һ�ַ����ַ������״γ��ֵ�λ��
//find_last_of(str) ���һ�γ��ֵ�λ��
//find_first_not_of(str) �ҵ���һ��������str���ַ�λ��
//find_last_not_of(str) �ҵ����һ��������str���ַ�λ��
//substr(pos, len) ��ȡ��pos��ʼ��len���ַ��ִ�
//compare(str) ����0��ʾ��ȣ� <0��ʾС�ڣ� >0��ʾ����
//compare(pos1, len1, str) �Ƚϵ�ǰ�ַ������ִ���str
//std::to_string(val) ��ֵת�ַ���
//std::stoi(str) string to int
//std::stol(str) string to long
//std::stoll(str)
//std::stof(str)
//std::stod(str)
//std::getline(cin, str) ��cin��������
//str.c_str() ����const char* ����C����ַ�����null��β��,���ص��ַ�����ֻ����
//swap(str2)
//shrink_to_fit()
//capacity()
//reserve(n)

//�ַ����Ƚ�
//�ַ����Ƚϵ��������ַ������ֵ���lexicographical order)
//�ֵ���
//�Ƚ�����ĸ������ĸ��ͬ�Ƚϳ��ȣ���д��ĸ��ASCII��ֵС��Сд

//�ַ������ڴ�ṹ
static class string
{
private:
	char* _data;//ָ��ʵ���ַ����飨��\0��β��
	size_t _size;//��ǰ�ַ������ȣ�����\0��
	size_t _capacity;//�����������
};
//SSO(Small String Optimization)
//���������ִ�ʵ�ֶ�ʹ����SSO(С�ַ����Ż�)
//���ַ����̵ܶ�ʱ��ͨ�� <= 15���ֽڣ�����ֱ�Ӵ���std::string��������ڲ��������У���ȥ����new�ڴ�
//��ʱ�򲻻ᴥ�����ڴ���䣬�ַ�����ֱ�Ӵ����string�����ڲ���һ��char[15]�����ƽṹ�У����ܼ���

//"\0"
//"\0"�ǿ��ַ���Ҳ��null�ַ�
//����ֵ��0��������char
//��ASCII���о��ǣ�NULL������Ϊ0
static char ch = '\0'; //�ȼ��� char ch = 0
//��C�����У��Լ�C++��char*�ַ������У�
//�ַ����Ľ�β��"\0"����ʶ���������ó���
static char str[] = "hello";
//ʵ�������ڴ��� 'h' 'e' 'l' 'l' 'o' '\0'
//Ҳ��д�� char str[] = {'h', 'e', 'l', 'l', 'o', '\0'}
static char s[5] = { 'h', 'e', 'l', 'l', 'o' };
//int main()
//{
//	std::cout << s << std::endl;//UB
//}
//
//std::string�ڲ����Զ�ά��"\0"��β

//1.�ַ�����ת
//����һ���ַ�������д�������䷴ת
//��ʹ��std::reverse
std::string reverseString(const std::string& str)
{
	std::string temp(str);
	for (int i = 0; i < str.size(); ++i)
	{
		temp.at(i) = str.at(str.size() - i - 1);
	}
	return temp;
}
//�Ż�
std::string reverseString_(const std::string& str)
{
	std::string temp(str);
	int left = 0, right = temp.size() - 1;
	while (left < right)
	{
		std::swap(temp[left], temp[right]);
		++left;
		--right;
	}
	return temp;
}

//2.�жϻ����ַ���
//��дһ���������ж�һ���ַ����Ƿ��ǻ��ģ������ͷ���һ����
//���Կո�ͱ����ţ�ֻ������ĸ������
bool isPalindrome(const std::string& str)
{
	std::string temp = reverseString(str);
	return temp == str;
}
//�Ż���ԭ��˫ָ��Ƚ�
bool isPalindrome_(const std::string& str)
{
	int left = 0;
	int right = str.size() - 1;
	while (left < right)
	{
		if (str[left] != str[right])
			return false;
		++left;
		++right;
	}
	return true;
}

//3.�����ַ����еĵ�һ�����ظ��ַ�
//��дһ�������������ַ����е�һ�����ظ����ַ������û�з���-1
char firstNonRepeatingChar(const std::string& str)
{
	auto temp = str.at(1);
	for (int i = 0; i < str.size(); ++i)
	{
		temp = str[i];
		bool flag = 0;
		for (int j = 0; j < str.size(); ++j)
		{
			if (temp == str[j] && i != j)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0) return temp;
	}
	return '-1';
}
