/*STL
* STL的组成：
1.containers(容器)
容器通过配置器取得数据存储空间；
容器包括各种数据结构，如vector，queue，deque, set, map，用来存放数据。
分为序列式容器和关联式容器，实现的角度来讲是一种类模板。

2.algorithms(算法)
算法通过迭代器存取容器内容；
算法包括各种常用的算法，如sort, search从实现的角度来讲是一种方法模板

3.interators(迭代器)
从实现的角度来讲，迭代器是一种将operator, operator->,operator++,operator-等
指针相关操作赋予重载的类模板，所有的STL容器都有自己的迭代器。

4.functors(仿函数)
仿函数可以协助算法完成不同的策略变化
从实现的角度来看，仿函数是一种重载了operator()的类或者类模板。可以帮助算法实现不同的策略。

5.adapters(配接器)
配接器可以应用于容器、仿函数和迭代器
一种用来修饰容器或者仿函数或迭代器接口的东西。

6.allocator(分配器)
负责空间配置与管理，从实现的角度来讲，配置器是一个实现了动态空间配置、空间管理、空间释放的类模板。
*/

//容器
//容器分类
//顺序容器 vector deque list forward_list array string
// vector动态数组，支持随机访问，适合频繁尾部操作
// deque双端队列，支持头尾快速插入/删除
// list双向链表，任意位置插入/删除效率高，但不支持随机访问
// forward_list单向链表，内存开销小，但只能单向遍历
// array固定大小数组，大小在编译时确定，支持随机访问
// string特化的字符容器，本质上是vector<char>
//关联容器 set map multiset mltimap
//无序容器 unordered_set unordered_map
//容器适配器 stack queue priority_queue 基于底层容器封装

//算法
//排序类：sort, stable_sort, partial_sort
//查找类：find, binary_search, count, find_if
//修改类：copy, replace, remove, fill, transform
//数值算法：accumulate, inner_product等<numeric>

//迭代器
//普通迭代器：iterator, const_iterator
//反向迭代器：reverse_iterator
//插入迭代器：back_inserter, inserter
//流迭代器：istream_iterator, ostream_iterator

//套用侯捷先生的话：STL的学习境界划分为三个阶段：会用、明理、能扩展


