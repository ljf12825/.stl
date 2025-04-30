#include <iostream>
#include <map>
//std::map
//std::map��STL�е�һ����������
//���洢K-V pairs��ÿ��Ԫ����һ��Ψһ�ļ�����֮������ֵ���
//std::map����ݼ��Ĵ�С��ϵ�Զ�����Ԫ�ؽ�������
//��Ҫ�ص㣺
//��Ψһ��ÿ����ֻ�ܳ���һ�Σ��������ظ������������ͼ����һ���Ѵ��ڵļ���������¶�Ӧ��ֵ��
//�Զ�����Ĭ������£�Ԫ�ظ��ݼ��Ĵ�С��������Ĭ��<���������ͨ���Զ���Ƚ������ı�����ʽ
//���ں����ʵ�֣�std::map��һ��ƽ����������������롢ɾ�������ҵ�ʱ�临�Ӷ�ƽ��ΪO(log n)
//int main()
//{
//	std::map<int, std::string> myMap;
//
//	myMap[1] = "Apple";
//	myMap[2] = "Banana";
//	myMap[3] = "Cherry";
//	myMap.insert(std::make_pair(4, "Date"));
//
//	auto it = myMap.find(2);
//	if (it != myMap.end())
//		std::cout << "Found key 2 with value : " << it->second << std::endl;
//
//	for (const auto& pair : myMap)
//	{
//		std::cout << pair.first << pair.second << std::endl;
//	}
//
//	myMap.erase(3);
//}
//
//��������
//insert����һ��pair
//pair.first��һ����������ָ���²����Ԫ�أ������Ѿ����ڵ�Ԫ�أ�������Ѿ����ڵĻ���
//pair.second��һ������ֵ����ʾ�����Ƿ�ɹ���������Ѵ����򷵻�false�����򷵻�true
//begin���ص�һ��Ԫ�صĵ�����
//end����ָ��mapĩβ�ĵ�����
//find���ڲ����ض��ļ�������һ��ָ���Ԫ�صĵ�����������������ڣ��򷵻�map.end()
//erase(key)/erase(it.begin it.end)
//std::mapĬ��ʹ��operator<��������Ƚϼ�������Ҳ����ָ���Զ���ıȽϺ���
//std::map<int, std::string, std::greater<int>> reverseMap;
//count����Ƿ����ĳ����
//count����һ����������ʾָ�����Ƿ���ڡ���std::map�У����ڼ���Ψһ�ģ�����ֵҪô��0�������ڣ�Ҫô��1�����ڣ�

//�ײ�ʵ��
template<
	class Key, 
	class T, 
	class Compare = std::less<Key>, 
	class Allocator = std::allocator<std::pair<const Key, T>>>
class map;

//C++17
namespace pmr
{
	template<
		class Key,
		class T,
		class Compare = std::less<Key>
	>using map = std::map<Key, T, Compare,
		std::pmr::polymorphic_allocator<std::pair<const Key, T>>>;
}