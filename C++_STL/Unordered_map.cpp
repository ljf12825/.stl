#include <iostream>
#include <unordered_map>
//std::unordered_map
//��ϣ������
//��������K��V��ӳ�䣬��Ԫ���������
//���롢����ʱ�临�Ӷ�ƽ��O(1)�O(N)
//������key�ظ����ظ��Ḳ��
//�Զ����ݣ�rehash��

//unordered_map�ײ���ô����
//���ǻ��ڹ�ϣ��ʵ�ֵ�
//1.��key������ϣ������std::hash<key>�����õ�һ�����֣���ϣֵ��
//2.���ݹ�ϣֵ����Ԫ�طŵ��ڲ���ĳ��Ͱ��bucket����
//3.����ʱ����ͬ���Ĺ�ϣ����ֱ�Ӷ�λ��Ͱ���ǳ���
//��ϣ����(key) -> �õ�Ͱ��� -> �� key-value �����ӦͰ
//������key��ϣ��ͬһ��Ͱ���ͻ���Ͱ���γ�����/��ʽ�ṹ��������ͻ��

//��������
//std::unordered_map<std::string, int> umap;
//int main()
//{
//	umap["apple"] = 3;
//	umap["banana"] = 5;
//	umap.insert({ "orange", 7 });
//	auto it = umap.find("banana");
//	if (it != umap.end())
//		std::cout << "banana: " << it->second << std::endl;
//	umap["apple"] == 10;
//	umap.erase("orange");
//	//��ͨ����
//	for (auto it = umap.begin(); it != umap.end(); ++it)
//	{
//		std::cout << it->first << it->second << std::endl;
//	}
//	//C++11��Χforѭ��
//	for (const auto& pair : umap)
//	{
//		std::cout << pair.first << pair.second << std::endl;
//	}
//	//C++17�ṹ����
//	for (const auto& [key, value] : umap)
//	{
//		std::cout << key << value << std::endl;
//	}
//}

//�������ӣ�load factor��
//�������� = Ԫ�ظ���/Ͱ������
//�������Ӹ�->��ͻ��->�����½�
//C++���Զ�rehash�����ݣ��Ա�֤����
//�ֶ�����
//umap.load_factor()//�鿴��ǰ��������
//umap.max_load_factor()//�������������
//umap.rehash(100)//���·���100��Ͱ

//Rehashing(���¹�ϣ)
//rehash��һ�ֻ��ƣ����������ӹ���ʱ�����������·���Ͱ������������������Ԫ�صĹ�ϣֵ���Լ��ٹ�ϣ��ͻ���Ӷ��������
//�������������������ӳ���ĳ����ֵʱ����ϣ����Զ���չͰ��������Ĭ�ϵĸ���������ֵ��1.0
//ִ�й��̣�
//1.���㵱ǰ��ϣ����Ԫ�ص�������Ͱ������
//2.���ݸ������Ӻ���ֵ�������Ƿ���Ҫ��չͰ�������������Ҫ��չ��Ͱ������ͨ��������Ϊԭ��������
//3.������Ԫ�ؽ������¹�ϣ�����¼���ÿ��Ԫ�صĹ�ϣֵ�����������Ƿ��䵽�µ�Ͱ��

//�Զ���
//�Զ�����
struct Point
{
	int x, y;
	bool operator==(const Point& other) const
	{
		return x == other.x && y == other.y;
	}
};
//�Զ����ϣ����
struct PointHash
{
	std::size_t operator()(const Point& p) const
	{
		return std::hash<int>()(p.x) ^ (std::hash<int>()(p.y) << 1);
	}
};
//ʹ���Զ����ϣ�ͱȽ���
std::unordered_map<Point, int, PointHash> pointMap;