#include <iostream>
#include <set>
//std::multiset
//��������
//����Ԫ���ظ�
//�ײ�����
//Ĭ��<
//���Ĭ���Ҳ�
//int main() {
//    std::multiset<int> ms;
//
//    // ����һЩԪ��
//    ms.insert(1);
//    ms.insert(3);
//    ms.insert(3);
//    ms.insert(5);
//    ms.insert(3);
//    ms.insert(7);
//
//    // ��ӡ multiset ����Ԫ��
//    std::cout << "����Ԫ��: ";
//    for (auto v : ms)
//        std::cout << v << " ";
//    std::cout << std::endl;
//
//    // ʹ�� equal_range �ҳ�����ֵΪ3��Ԫ��
//    auto range = ms.equal_range(3);
//
//    std::cout << "ֵΪ3��Ԫ����: ";
//    for (auto it = range.first; it != range.second; ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}
//equal_range(x) = {lower_bound(x), upper_bound(x)}
//lower_bound(x)����һ����������ָ���һ����С��x��Ԫ��
//���x���ڣ��᷵��x����λ�ã���������ڣ��򷵻ش���x�ĵ�һ��Ԫ�ص�λ��
//upper_bound(x)����һ����������ָ���һ������x��Ԫ��
//���x���ڣ����ش���x�ĵ�һ��Ԫ��λ�ã���������ڣ����ش���x�ĵ�һ��Ԫ��
//���û�д���x�����x��Ԫ�أ�����end()