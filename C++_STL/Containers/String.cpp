#include <iostream>
#include <cstring>
//std::string
//string的定义
//using std::string = std::basic_string<char>;
//也就是说，std::string本质上时一个以char为单位的字符串类模板实例，就是std::basic_string的特化版本，string是伪容器
//string并不是C++中的内建类型（primitive type）


//构造函数
static std::string s1;//空字符串
static std::string s2("hello");//从C字符串构造
static std::string s3 = "world";//隐式构造
static std::string s4(5, 'A');
static std::string s5(s2);//拷贝构造
static std::string s6 = s2 + s3;//拼接

//std::string的操作
//基本操作
//size()/length() 返回字符串的长度
//empty() 判空
//clear() 清理
//resize(n) 改变字符串长度，默认充填\0
//resize(n, c) 长度扩展时使用字符c充填
//at() 安全访问，越界抛出异常
//operator[] 不做越界检查
//front() 返回首字符，相当于str[0]
//back() str[str.size() - 1]
//operator+ 拼接
//operator+= 追加
//append(str) +=str
//append(str, pos, len) 追加str的字串str.substr(pos, len)
//insert(pos, str)
//erase(pos, len)
//replace(pos, len, str)
//find(str) 返回str第一次出现的位置，找不到返回std::string::npos
//find(str, pos) 从pos开始查找str
//rfind(str) 从右往左找
//find_first_of(str) 查找任一字符在字符串中首次出现的位置
//find_last_of(str) 最后一次出现的位置
//find_first_not_of(str) 找到第一个不属于str的字符位置
//find_last_not_of(str) 找到最后一个不属于str的字符位置
//substr(pos, len) 提取从pos开始的len个字符字串
//compare(str) 返回0表示相等， <0表示小于， >0表示大于
//compare(pos1, len1, str) 比较当前字符串的字串与str
//std::to_string(val) 数值转字符串
//std::stoi(str) string to int
//std::stol(str) string to long
//std::stoll(str)
//std::stof(str)
//std::stod(str)
//std::getline(cin, str) 从cin输入整行
//str.c_str() 返回const char* 返回C风格字符串（null结尾）,返回的字符串是只读的
//swap(str2)
//shrink_to_fit()
//capacity()
//reserve(n)

//字符串比较
//字符串比较的是两个字符串的字典序（lexicographical order)
//字典序
//比较首字母，首字母相同比较长度，大写字母的ASCII码值小于小写

//字符串的内存结构
static class string
{
private:
	char* _data;//指向实际字符数组（以\0结尾）
	size_t _size;//当前字符串长度（不含\0）
	size_t _capacity;//分配的总容量
};
//SSO(Small String Optimization)
//几乎所有现代实现都使用了SSO(小字符串优化)
//当字符串很短的时候（通常 <= 15个字节），它直接存在std::string对象本身的内部缓冲区中，不去堆上new内存
//这时候不会触发堆内存分配，字符串就直接存放在string对象内部的一个char[15]或类似结构中，性能极佳

//"\0"
//"\0"是空字符，也叫null字符
//它的值是0，类型是char
//在ASCII表中就是：NULL，编码为0
static char ch = '\0'; //等价于 char ch = 0
//在C语言中（以及C++的char*字符串）中：
//字符串的结尾由"\0"来标识，而不是用长度
static char str[] = "hello";
//实际上在内存中 'h' 'e' 'l' 'l' 'o' '\0'
//也可写作 char str[] = {'h', 'e', 'l', 'l', 'o', '\0'}
static char s[5] = { 'h', 'e', 'l', 'l', 'o' };
//int main()
//{
//	std::cout << s << std::endl;//UB
//}
//
//std::string内部会自动维护"\0"结尾

//1.字符串反转
//给定一个字符串，编写函数将其反转
//不使用std::reverse
std::string reverseString(const std::string& str)
{
	std::string temp(str);
	for (int i = 0; i < str.size(); ++i)
	{
		temp.at(i) = str.at(str.size() - i - 1);
	}
	return temp;
}
//优化
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

//2.判断回文字符串
//编写一个函数，判断一个字符串是否是回文（正读和反读一样）
//忽略空格和标点符号，只考虑字母和数字
bool isPalindrome(const std::string& str)
{
	std::string temp = reverseString(str);
	return temp == str;
}
//优化，原地双指针比较
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

//3.查找字符串中的第一个不重复字符
//编写一个函数，返回字符串中第一个不重复的字符。如果没有返回-1
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
