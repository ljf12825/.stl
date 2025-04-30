#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <stdexcept>
//priority_queue(���ȶ���)
std::priority_queue<int> pq;
//std::priority_queue��STL��һ������������
//�����ص��ǣ���ʵ�ֵ���һ�����ѣ�Ĭ������£���������ÿ�η��ʻ��Ƴ��Ķ��ǵ�ǰ�����ȼ���ߡ���Ԫ��

//��������
//push() ����һ��Ԫ�� O(log n)
//pop() ɾ������Ԫ�� O(log n)
//top() ���ض���Ԫ�� O(1)
//empty()
//size()

//�ײ�ʵ��
template <class T, class Container = std::vector<T>, class Compare = std::less<typename Container::value_type>>
class priority_queue;
//T��������
//Container�ײ�������Ĭ��Ϊstd::vector<T>
//Compare�Ƚ�����Ĭ��Ϊstd::less<T>(������)
//����ͨ������std::greater<T>��������С��
//�ײ����������Ҫ�����¼�����
//std::make_heap ����
//std::push_head ����Ԫ�غ��ϸ�
//std::pop_head �Ƴ��Ѷ�Ԫ�ز��³�
//std::sort_heap �����
