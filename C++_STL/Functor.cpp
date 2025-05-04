#include <functional>
#include <iostream>

//�º���
//STL���ṩ��һЩ���õķº�����������ͷ�ļ�<functional>��

//�º�������
//����Я��״̬����״̬���º������Ա�����������㣩
//���ڷ��ͱ�̣����STL�㷨
//�������ڿ������Ż���Ч�ʸ�

//�ִ�C++������lambda���ʽ������º�������Ϊ��д������ࡣ�����º�����Ȼ��Ҫ���ر����Ķ�STLԴ���ģ���

//�º�����Ϊ�ȽϹ�����������ڲ�Ԫ�ص����򡢲��ҡ����롢ɾ���Ȳ���
//�º�����������Ϊģ��������������������ڲ���洢һ�����ĸ�������Ϊ�Ƚ���Ϊ������
template<
	class Key,
	class Compare = std::less<Key>,//ʹ���Զ���º��������滻
	class Allocator = std::allocator<Key>
> class set;

//ʹ���Զ���º�����ע������
//1.�Զ���º����������ϸ��������㴫���ԡ������Է��Եȣ�������UB
//2.�º���������const��������Ϊ�ڲ��Ƚ�ʱʹ��const���ã���
//3.�º���Ӧ������״̬�ģ�����״̬����������Ϊ���ȶ��ģ���ɿ�����ֻ�����ݣ����º������ڲ������������ã����ǲ��������������ڷ����仯������UB��

int main()
{
	//������º���
	std::plus<int> plus;
	std::minus<int> minus;
	std::multiplies<int> multiplies;
	std::divides<int> divides;
	std::modulus<int> modulus;//ȡģ return _Left % _Right
	std::negate<int> negate;//ȡ�� return -_Left;

	//��ϵ��º���
	std::equal_to<int> equal_to;
	std::not_equal_to<int> not_equal_to;
	std::greater<int> greater;
	std::less<int> less;
	std::greater_equal<int> greater_equal;
	std::less_equal<int> less_equal;

	//�߼���º���
	std::logical_and<int> logical_and;
	std::logical_not<int> logical_not;
	std::logical_or<int> logical_or;
}