#include <iostream>
#include <set>
//std::set
//��������
//�ײ�����
//�Զ�����Ĭ��ʹ��<�Ƚϣ�
//Ԫ��Ψһ
//���롢���ҡ�ɾ����ʱ�临�Ӷ�ΪO(log n)
std::set<int> s = { 3, 1, 4, 2 };//�ڲ����Զ��ų�1234
//set���ڵ�����
//ȥ�� + ���� + ���ٲ���

//�ײ�ʵ��
template <typename Key, typename Compare = std::less<Key>, typename Alloc = std::allocator<Key>>
class set;