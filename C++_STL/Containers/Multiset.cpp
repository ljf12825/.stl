#include <iostream>
#include <set>
//std::multiset
//关联容器
//允许元素重复
//底层红黑树
//默认<
//相等默认右插
//int main() {
//    std::multiset<int> ms;
//
//    // 插入一些元素
//    ms.insert(1);
//    ms.insert(3);
//    ms.insert(3);
//    ms.insert(5);
//    ms.insert(3);
//    ms.insert(7);
//
//    // 打印 multiset 所有元素
//    std::cout << "所有元素: ";
//    for (auto v : ms)
//        std::cout << v << " ";
//    std::cout << std::endl;
//
//    // 使用 equal_range 找出所有值为3的元素
//    auto range = ms.equal_range(3);
//
//    std::cout << "值为3的元素有: ";
//    for (auto it = range.first; it != range.second; ++it) {
//        std::cout << *it << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}
//equal_range(x) = {lower_bound(x), upper_bound(x)}
//lower_bound(x)返回一个迭代器，指向第一个不小于x的元素
//如果x存在，会返回x所在位置；如果不存在，则返回大于x的第一个元素的位置
//upper_bound(x)返回一个迭代器，指向第一个大于x的元素
//如果x存在，返回大于x的第一个元素位置；如果不存在，返回大于x的第一个元素
//如果没有大于x或等于x的元素，返回end()