#include <iostream>
#include <map>
//std::multimap
//��������
//����map
//K-V
//Ԫ���Զ�����ֵ����Ĭ��<���򣬿����Զ���Ƚ���
//�������ظ��ļ�
//�ײ��Ǻ����
//int main()
//{
//	std::multimap<int, std::string> m;
//	m.insert({ 1, "apple" });
//	m.insert({ 2, "banana" });
//	m.insert({ 1, "avocado" });
//
//	for (const auto& [key, value] : m)
//		std::cout << key << " " << value << std::endl;
//	return 0;
//	//1 apple
//	//1 avocado
//	//2 banana
//}
// 
// equal_range(x)�����õ�����keyֵ��ͬ��Ԫ��
//equal_range����һ��pair������������������
//first:ָ���һ��ƥ���Ԫ�أ�second:ָ���һ�����ڸ�key��Ԫ��
//int main() {
//    std::multimap<int, std::string> mmap;
//
//    // ����һЩ��ֵ��
//    mmap.insert({ 3, "apple" });
//    mmap.insert({ 3, "banana" });
//    mmap.insert({ 5, "cherry" });
//    mmap.insert({ 3, "date" });
//    mmap.insert({ 7, "elderberry" });
//    mmap.insert({ 5, "fig" });
//
//    // ��ӡ multimap ����Ԫ��
//    std::cout << "����Ԫ��: ";
//    for (const auto& pair : mmap)
//        std::cout << "(" << pair.first << ", " << pair.second << ") ";
//    std::cout << std::endl;
//
//    // ʹ�� equal_range �������� key Ϊ 3 ��Ԫ��
//    auto range = mmap.equal_range(3);
//
//    std::cout << "key Ϊ 3 ������Ԫ��: ";
//    for (auto it = range.first; it != range.second; ++it) {
//        std::cout << "(" << it->first << ", " << it->second << ") ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}


//multimapû��operator[]
//multimap�ײ��������ظ����������µĽڵ�������нڵ���ұ�
//ԭ��
//1.��֤˳���ȶ�
//2.���������������ȷ����
//�������multimap�����ǰ�key���� + ������˳�򷵻�
//3.��ƽ�������ά��