//construct
//array隐式构造

//destruct
//array隐式析构

//operator=
//array隐式替换

//assign 清空原内容，插入新的元素

//begin 返回首元素的迭代器，如果为空，返回end()

//cbegin 返回第一个元素的const_iterator

//end return past the last element iterator

//cend

//rbegin 返回尾元素的迭代器，如果为空，返回rend()

//crbegin

//rend return prevent the first element iterator

//crend

//at 返回位于指定位置的元素的引用，有边界检查，越界抛出std::out_of_range

//operator[] 无边界检查，越界UB

//data 返回指向作为元素存储工作的底层数组首元素的地址，int* p = arr

//#include <iostream>
//#include <array>
//
//std::array<int, 3> a_1 = { 1, 2, 3 };
//int a_2[3] = { 1, 3, 4 };
//
//int main()
//{
//	auto p = a_1;
//	auto q = &a_1;
//	auto r = &a_1[0];
//	auto s = a_1.data();
//
//	std::cout << r << " " << s << std::endl;
//
//	auto a = a_2;//退化为指针
//	//退化原因
//	//1.历史兼容性，在C/C++语言的最初设计中，数组不是第一等对象，不能整体赋值、传参或返回，而是通过指针模拟
//	//2.效率，传指针效率高
//	//3.简化运算，C/C++中数组和指针共享大量语法
//	//退化场景
//	//1.函数传参
//	//2.表达式求值
//	//不会退化的情况
//	//1.sizeof
//	//2.decltype/template明确保持里欸行
//	//3.取地址
//	auto b = &a_2;//整个数组
//	auto c = &a_2[0];
//
//	std::cout << **b << std::endl;
//	return 0;
//}

//front 返回到容器首元素的引用 front = *begin

//back 返回到容器最后一个元素的引用 back = *std::prev(end())

//empty

//size

//max_size 返回容器根据系统或库实现限制而可保有的元素的最大数量，即最大容器容量

//resize 重设大小

//capacity 返回容器当前已为之分配空间的元素数

//reserve 扩容

//shrink_to_fit 请求移除未使用的容量

//clear

//insert 前插，需要预先创建对象，涉及拷贝移动

//insert_or_assign 如果键不存在，就插入一个新的键值对。如果键已存在，则更新该键对应的值

//emplace 前插，直接在容器内部构造对象，避免额外开销
//template <class...Args>
//std::pair<iterator, bool> emplace(Args&&...args);
//iterator指向新插入的元素，bool表示是否成功插入

//emplace_hint 在关联容器中提供一个提示（建议）位置，帮助容器更高效地插入元素

//try_emplace 尝试插入给定的键值或元素，如果容器中存在，则指向已存在元素。比卖你不必要的修改

//erase 

//push_front 

//emplace_front

//pop_front

//push_back

//emplace_back

//pop_back

//swap

//merge 将另一个同类型的容器的元素合并到当前容器中，保持容器的有序性，同时不会丢失任何元素

//extract 从有序关联容器中提取一个元素，将其从容器中移除，返回一个node_type表示容器内元素的封装

//splice 将一个list中的元素移动到另一个list中，保持它们的顺序，通过指针操作，避免拷贝

//remove 移除一个元素，返回移除的元素数量（C++20起）

//remove_if 移除所有满足特定标准的元素，返回移除元素的数量（C++20起）

//reverse 反转

//unique 移除容器中所有相继的重复元素，只留下相等元素组中的第一个元素。

//sort stable

//bucket_count 返回桶的数量

//max_bucket_count 返回容器最大桶数

//bucket_size 返回索引为n的桶中的元素数

//bucket 返回键key的桶的索引

//load_factor 返回平均每桶元素数

//max_load_factor 返回最大加载因子，设置最大加载因子

//rehash 调整底层桶数量，重新组织容器中的元素以优化哈希表结构

//count 返回拥有与指定实参比较等价的键的元素数

//find

//contains 检查容器中是否有元素的键等于key

//lower_bound 返回首个不小于key的元素的迭代器

//upper_bound 返回首个大于key的元素的迭代器

//equal_range 返回容器中所有拥有给定键的元素的范围[lower_bound(key), upper_bound(key))

//key_comp 返回用于比较键的函数对象（比较器），它是此容器构造函数实参comp的副本

//value_comp 返回比较值的函数对象（比较器）

//hash_function 返回对键计算散列的函数

//key_equal 返回比较键相等性的函数

//get_allocator 返回分配器