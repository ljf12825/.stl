#include <iostream>
#include <map>
//std::multimap
//��������
//����map
//K-V
//Ԫ���Զ�����ֵ����Ĭ��<���򣬿����Զ���Ƚ���
//�������ظ��ļ�
//�ײ��Ǻ����
int main()
{
	std::multimap<int, std::string> m;
	m.insert({ 1, "apple" });
	m.insert({ 2, "banana" });
	m.insert({ 1, "avocado" });

	for (const auto& [key, value] : m)
		std::cout << key << " " << value << std::endl;
	return 0;
	//1 apple
	//1 avocado
	//1 banana
}
//multimapû��operator[]
//multimap�ײ��������ظ����������µĽڵ�������нڵ���ұ�
//ԭ��
//1.��֤˳���ȶ�
//2.���������������ȷ����
//�������multimap�����ǰ�key���� + ������˳�򷵻�
//3.��ƽ�������ά��