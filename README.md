# STL
STL提供了常用的模板类和算法
STL的核心组件有：容器（Containers）、算法（Algorithms）、迭代器（Iterators）、函数对象（Function Object）、适配器（Adapter）

STL
|_________容器（Containers）
|                |_____顺序容器
|                |             |_____vector
|                |             |_____list
|                |             |_____deque
|                |             |_____array
|                |             |_____string
|                |
|                |_____关联容器
|                |             |_____set
|                |             |_____map
|                |             |_____multiset
|                |             |_____multimap
|                |
|                |_____无序关联容器
|                |             |_____unordered_set
|                |             |_____unordered_map
|                |             |_____unordered_multiset
|                |             |_____unordered_multimap
|                |
|                |_____适配器容器
|                              |_____stack
|                              |_____queue
|                              |_____priority_queue
|
|
|_________算法（Algorithms）
|                |_____排序
|                |          |_____sort
|                |          |_____stable_search
|                |          |_____partial_sort
|                |
|                |_____查找
|                |          |_____find
|                |          |_____binary_search
|                |          |_____lower_bound
|                |          |_____upper_bound
|                |
|                |_____修改
|                |          |_____reverse
|                |          |_____rotate
|                |          |_____fill
|                |
|                |_____遍历
|                |          |_____for_each
|                |          |_____transform
|                |
|                |_____操作
|                           |_____count
|                           |_____accumulate
|                           |_____remove_if
|
|__________迭代器（Iterators）
|                |_____普通迭代器：用于遍历容器
|                |_____反向迭代器：rbegin(), rend()
|                |_____常量迭代器：不能修改容器的元素
|
|__________函数对象（Function Object）
|              函数对象（或称为仿函数）是可以像函数一样调用的对象。STL中的一些算法，如sort，允许用户传入函数对象来进行自定义排序规则。
|
|__________适配器（Adapters）
|                |_____容器适配器
|                |               |_____stack
|                |               |_____queue
|                |               |_____priority_queue
|                |               
|                |_____迭代器适配器
|                |               |_____reverse_iterator
|                |               |_____ostream_iterator
|                |      
|                |_____函数对象适配器
|                                |_____not1
|                                |_____not2
|                                |_____bind1st
|                                |_____bind2nd
|
|__________智能指针
                 |_____unique_ptr
                 |_____shared_ptr
                 |_____weak_ptr

