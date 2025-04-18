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

6.allocator(空间配置器)
负责空间配置与管理，从实现的角度来讲，配置器是一个实现了动态空间配置、空间管理、空间释放的类模板。
*/

/*
* containers(容器)
1.sequence containers(序列式容器)：元素都是可序的(ordered),但未必是有序的(sorted)
2.associattive containers(关联式容器)
*/

/*
* 内存管理 allocator
C++ SGI设计了双层级配置器
第一级配置器: _malloc_alloc_template
第二级配置器: _default_alloc_template
第一级配置器直接使用 malloc()和 free() 完成内存的分配和回收。
第二级配置器则根据需求量的大小选择不同的策略执行。
对于第二级配置器，如果需求块大小大于 128bytes，则直接转而调用第一级配置器，使用 malloc()分配内存。
如果需求块大小小于 128 bytes，第二级配置器中维护了 16 个自由链表，负责 16 种小型区块的次配置能力。
即当有小于 128bytes 的需求块要求时，首先查看所需需求块大小所对应的链表中是否有空闲空间，如果有则直接返回，
如果没有，则向内存池中申请所需需求块大小的内存空间，如果申请成功，则将其加入到自由链表中。
如果内存池中没有空间，则使用 malloc() 从堆中进行申请，且申请到的大小是需求量的二倍（或二倍＋n 附加量），一倍放在自由空间中，一倍（或一倍＋n）放入内存池中。
如果 malloc()也失败，则会遍历自由空间链表，四处寻找“尚有未用区块，且区块够大”的 freelist，找到一 块就挖出一块交出。
如果还是没有，仍交由 malloc()处理，因为 malloc()有 out-of-memory 处理机制或许有机会释放其他的内存拿来用，如果可以就成功， 如果不行就报 bad_alloc 异常。
*/

/*
* 迭代器traits
traits萃取迭代器的性质
value_type, difference_type, pointer, reference, iteratior_category
自己开发的容器，要有自己的迭代器，要继承有这五个部分的 typedef，才能是自己的定义与原来的一些算法更兼容。
迭代器有五个类型：
InputIterator(输入迭代器)
OutputIterator(输出迭代器）
ForwardIterator（前向迭代器）
BidirectionalIterator（双向迭代器）
RandomAccessIterator（随机迭代器）
将迭代器分为几种类型是因为在算法中根据 traits 萃取出的不同迭代器类型，内部可以写出更加高效合适的实现功能的代码。
iterator_traits 就像是一种萃取机，你想要什么东西，你丢给这个萃取机器，它返回给你想要的东西。
萃取iterator的特性（为什么要这样设计？因为算法要知道，这是算法给 iterator 提出的问题！也就是说算法通过仿函数来处理容器里面的元素）

*/

/*
* array
array是固定大小的顺序容器，它们保存了一个以严格的线性顺序排列的特定元素数量的元素。
在内部，一个数组除了它所包含的元素(甚至不是它的大小，它是一个模板参数，在编译时是固定的)
以外不保存任何数据。存储大小与用语言括号语法([])声明的普通数组一样高效。这个类只是增加了一层成员函数
和全局函数，所以数组可以作为标准容器使用。
与其他标准容器不同，数组具有固定的大小，并且不通过分配器管理其元素的分配：它们是封装固定大小数组元素
的聚合类型。因此，他们不能动态地扩大或缩小。
零大小的数组是有效的，但是它们不应该被解除引用(成员的前面，后面和数据)。
与标准库中其他的容器不同，交换两个数组容器是一种线性操作，它涉及单独交换范围内的所有元素，这通常是
相当低效的操作。另一方面，这允许迭代器在两个容器中的元素保持其原始容器关联。
数组容器的另一个独特特性是它们可以被当作元组对象来处理：array的头部重载get函数来访问数组元素，
就像它是一个元组，以及专门的tuple_size和tuple_element类型。
template <class T, size_t N> class array
*/

/*
* array::begin
返回指向数组容器中第一个元素的迭代器
iterator begin() noexcept;
const_iterator begin() const noexcept;
*/

/*
* array::end
返回指向数组容器中最后一个元素之后的理论元素的迭代器；
iterator end() noexcept;
const_interator end() const noexcept;
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 5> myarray = { 2, 16, 77, 34, 50 };
//	cout << "myarray contains: ";
//	for (auto it = myarray.begin(); it != myarray.end(); ++it)
//	{
//		cout << ' ' << *it;
//	}
//	cout << endl;
//	return 0;
//}

/*
* array::rbegin
返回指向数组容器中最后一个元素的反向迭代器
reverse_iterator rbegin() noexcept;
const_reverse_iterator rbegin() const noexcept;
*/

/*
* array::rend
返回一个反向迭代器，指向数组中第一个元素之前的理论元素（这被认为是它的反向结束）
reverse_iterator rend() noexcept;
const_reverse_iterator rend() const noexcept;
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 4> myarray = { 4, 26, 80, 14 };
//	for (auto rit = myarray.rbegin(); rit < myarray.rend(); rit++)
//	{
//		cout << ' ' << *rit;
//	}
//	cout << endl;
//	return 0;
//}

/*
* array::cbegin
返回指向数组容器中第一个元素的常量迭代器(const_iterator);这个迭代器可以增加和减少，
但是不能用来修改它指向的内容。
const_iterator cbegin() const noexcept;
*/

/*
* array::cend
返回指向数组容器中最后一个元素之后的理论元素的常量迭代器(const_iterator)。这个迭代器
可以增加和减少，但是不能用来修改它指向的内容。
const_iterator cend() const noexcept;
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 5> myarray = { 15, 720, 801, 1002, 3502 };
//	cout << "myarray contains: ";
//	for (auto it = myarray.cbegin(); it != myarray.cend(); it++)
//	{
//		cout << ' ' << *it;
//	}
//	cout << endl;
//	return 0;
//}

/*
* array::crbegin
返回指向数组容器中最后一个元素的常量反向迭代器(const_reverse_iterator)
const_reverse_iterator crbegin() const noexcept;
*/

/*
* array::crend
返回指向数组中第一个元素之前的理论元素的常量反向迭代器(const_reverse_iterator),
它被认为是其反向结束。
const_reverse_iterator crend() const noexcept;
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 6> myarray = { 10, 20, 30, 40, 50, 60 };
//	cout << "myarray backwards: ";
//	for (auto rit = myarray.crbegin(); rit < myarray.crend(); rit++)
//	{
//		cout << ' ' << *rit;
//	}
//	cout << endl;
//	return 0;
// }

/*
* array::size
返回数组容器中元素的数量
constexpr size_type size() noexcept;
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 5> myints;
//	cout << "size of myints: " << myints.size() << endl;
//	cout << "sizeof(myints):" << sizeof(myints) << endl;
//
//	return 0;
//}

/*
* array::max_size
返回数组容器可容纳的最大元素数。数组对象的max_size与其size一样，
始终等于用于实例化数组模板类的第二个参数模板。
constexper size_type max_size() noexcept;
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 10> myints;
//	cout << " max_size of myints: " << myints.max_size();
//	return 0;
//}

/*
* array::empty
返回一个布尔值，指示数组容器是否为空，即它的size()是否为0。
constexpr bool empty() noexcept;
*/

//#include <iostream>
//#include <array>
//
//int main()
//{
//	std::array<int, 0> first;
//	std::array<int, 5> second;
//	std::cout << "first " << (first.empty() ? "is empty" : "is not empty");
//	std::cout << "second " << (second.empty() ? "is empty" : "is not empty");
//	return 0;
//}

/*
* array::operator[]
返回数组中第n个位置的元素的引用。与array::at相似，但array::at会检查数组边界
并通过抛出一个out_of_range异常来判断n是否超出范围，而array::operator[]不检查边界。
reference operator[] (size_type n);
const_reference operator[] (size_type n) const;
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 10> myarray;
//	unsigned int i;
//
//	for (i = 0; i < 10; i++)
//	{
//		myarray[i] = i;
//	}
//
//	cout << "myarray contains: ";
//	for (i = 0; i < 10; i++)
//	{
//		cout << ' ' << myarray[i];
//	}
//	cout << endl;
//	return 0;
//}

/*
* array::at
返回数组中第n个位置的元素的引用。与array::operator[]相似，但array::at会检查
数组边界并通过抛出一个out_of_range异常来判断n是否超出范围。
reference at (size_type n);
const_reference att(size_type n) const;
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 10> myarray;
//	unsigned int i;
//
//	for (i = 0; i < 10; i++)
//	{
//		myarray[i] = i;
//	}
//	cout << "myarray contains: ";
//	for (i = 0; i < 10; i++)
//	{
//		cout << ' ' << myarray.at(i);
//	}
//	cout << endl;
//	return 0;
//}

/*
* array::front
返回对数组容器中第一个元素的引用。array::begin返回的是迭代器，array::front返回的是直接引用
在空容器上调用此函数会导致未定义的行为
reference front();
const_reference front() const;
*/

/*
* array::back
返回对数组容器中最后一个元素的引用。array::end返回的是迭代器，array::back返回的是直接引用
在空容器上调用此函数会导致未定义的行为。
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 3> myarray = { 2, 16, 77 };
//	cout << "front is " << myarray.front() << endl;
//	cout << "back is " << myarray.back() << endl;
//
//	myarray.front() = 100;
//	myarray.back() = 50;
//
//	cout << "myarray now contains: ";
//	for (int& x : myarray)//***x在myarray范围内的自增***
//	{
//		cout << ' ' << x;
//	}
//	cout << endl;
//	return 0;
//}

/*
* array::data
返回指向数组对象中第一个元素的指针
对于数组中的元素存储在连续的存储位置，所以检索到的指针可以偏移以访问数组中的任何元素
value_type* data() noexcept;
const value_type* data() const noexcept;
*/

//#include <iostream>
//#include <array>
//#include <cstring>
//
//using namespace std;
//
//int main()
//{
//	const char* cstr = "Test string";
//	array<char, 12> charry;
//
//	memcpy(charry.data(), cstr, 12);
//	cout << charry.data() << endl;
//
//	return 0;
//}

/*
* array::fill
用val填充数组所有元素，将val设置为数组对象中所有元素的值。
void fill(const value_type& val);
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 6> myarray;
//
//	myarray.fill(5);
//
//	cout << "myarray contains: ";
//	for (int& x : myarray)
//		cout << ' ' << x;
//	cout << endl;
//}

/*
* array:swap
通过x的内容交换数组的内容，这是另一个相同类型的数组对象（包括相同的大小）。
与其他容器的交换成员函数不同，此成员函数通过在各个元素之间执行与其他大小相同的
单独交换操作，以线性时间运行。
void swap(array& x) noexcept(noexcept(swap(declval<value_type&>(), declval<value_type&>())));
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 5> first = { 10, 20, 30, 40, 50 };
//	array<int, 5> second = { 11, 22 ,33 ,44 ,55 };
//	
//	first.swap(second);
//
//	cout << "first: ";
//	for (int& x : first)
//		cout << ' ' << x;
//	cout << endl;
//
//	cout << "second: ";
//	for (int& x : second)
//		cout << ' ' << x;
//	cout << endl;
//	
//	return 0;
//}

/*
* get(array)
形如：std::get<0>(myarray);传入一个数组容器，返回指定位置元素的引用。
template <size_t I, class T, size_t N> T& get(array <T, N>&arr) noexcept;
template <size_t I, class T, size_t N> T& get(array < T, N>& arr) noexcept;
template <size_t I, class T, size_t N> const T& get(const array <T, N>&arr) noexcept;
*/

//#include <iostream>
//#include <array>
//#include <tuple>
//
//using namespace std;
//int main()
//{
//	array<int, 3> myarray = { 10, 20, 30 };
//	tuple<int, int, int> mytuple(10, 20, 30);
//	tuple_element<0, decltype(myarray)>::type myelement;
//
//	myelement = get<2>(myarray);
//	get<2>(myarray) = get<0>(myarray);
//	get<0>(myarray) = myelement;
//
//	cout << "first element in myarray: " << get<0>(myarray) << endl;
//	cout << "first element in mytuple: " << get<0>(mytuple) << endl;
//
//	return 0;
//}

/*
* relational operators(array)
形如： arrayA != arrayB、 arrayA > arrayB;
依次比较数组每个元素大小关系
template <class T, size_T N>
	bool operator == (const array <T, N>&lhs, const array <T, N>&rhs);

template <class T, size_T N>
	bool operator != (const array <T, N>&lhs, const array <T, N>&rhs);

template <class T, size_T N>
	bool operator < (const array <T, N>&lhs, const array <T, N>&rhs);

template <class T, size_T N>
	bool operator <= (const array <T, N>&lhs, const array <T, N>&rhs);

template <class T, size_T N>
	bool operator > (const array <T, N>&lhs, const array <T, N>&rhs);

template <class T, size_T N>
	bool operator >= (const array <T, N>&lhs, const array <T, N>&rhs);
*/

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 5> a = { 10, 20, 30, 40, 50 };
//	array<int, 5> b = { 10, 20, 30, 40, 50 };
//	array<int, 5> c = { 50, 40, 30, 20, 10 };
//
//	if (a == b)
//		cout << "a == b" << endl;
//	if (b != c)
//		cout << "b != c" << endl;
//	if (b < c)
//		cout << "b < c" << endl;
//	if (c > b)
//		cout << "c > b" << endl;
//	if (a <= b)
//		cout << "a <= b" << endl;
//	if (a >= b)
//		cout << "a >= b" << endl;
//	return 0;
//}

/*
* vector
vector是表示可以改变大小的数组的序列容器
就像数组一样，vector为它们的元素使用联系的存储位置，这意味着它们的元素也可以使用到其元素的常规指针上的偏移来访问，
而且和数组一样高效。但是与数组不同的是，它们的大小可以动态地改变，它们的存储由容器自动处理。

在内部，vector使用一个动态分配的数组来存储它们的元素。这个数组可能需要重新分配，以便在插入新元素时增加大小，
这意味着分配一个新数组并将所有元素移动到其中。就处理时间而言，这是一个相对昂贵的任务，因为每次将元素添加到容器时矢量都不会重新分配。

相反，vector容器可以分配一些额外的存储以适应可能的增长，并且因此容器可以具有比严格需要包含其元素的存储空间更大的实际容量。
库可以实现不同的策略的增长到内存使用和重新分配之间的平衡，但在任何情况下，再分配应仅在对数生长的间隔发生尺寸，
使得在所述载体的末端各个元件的插入可以与提供分期常量时间复杂性。

因此，与数组相比，载体消耗更多的内存来交换管理存储和以有效方式动态增长额能力。

与其他动态序列容器（deques, lists, forward_lists)相比，vector非常有效地访问其元素（就像数组一样),并相对有效地从元素末尾添加或删除元素。
对于涉及插入或移除除了结尾之外的位置的元素的操作，它们执行比其他位置更差的操作，并且具有比列表和forward_lists更不一致的迭代器和引用，

针对vector的各种常见操作的时间复杂度：
*随机访问-O(1)
*在尾部增删元素-平摊（amortized）-O(1)
*增删元素-至vector尾部的线性距离O(n)

template <class T, class Alloc = allocator<T> > class vector;
*/

/*
* vector::vector
1.empty容器构造函数（默认构造函数）
构造一个空的容器，没有元素
2.fill构造函数
用n个元素构造一个容器。每个元素都是val的副本
3.范围（range）构造器
使用与[range, first, last]范围内相应的元素构造而成
4.复制(copy)构造函数（并用分配器复制）
按照相同的顺序构造一个包含x中每个元素的副本的容器
5.移动（move)构造函数（和分配器移动）
构造一个获取x元素的容器。如果指定了alloc并且与x的分配器不同，那么元素将被移动。
否则，没有构建元素（他们的所有权直接转移）。x保持未指定但有效的状态。
6.初始化列表构造函数
构造一个容器中的每个元件中的一个拷贝的IL，以相同的顺序
*/

/*
default(1)
explicit vector (const allocator_type& alloc = allocator_type());
fill(2)
explicit vector (size_type n);
vector (size_type n, const value_type& val. cons allocator_type& alloc = allocator_type());
range (3)
template <class InputIterator>
vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type());
copy (4)
vector (const vector& x);
vector (const vector& x, const allocator_type& alloc);
move (5)
vector (vector&& x);
vector (vector&& x, const allocator_type& alloc);
initializer list (6)
vector (initializer_list<value_type> il,const allocator_type& alloc = allocator_type());
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;;
//
//int main()
//{
//	vector<int> first;
//	vector<int> second(4, 100);
//	vector<int> third(second.begin(), second.end());
//	vector<int> forth(third);
//
//	int myints[] = { 16, 2, 77, 29 };
//	vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
//
//	cout << "The contents of fifth are: ";
//	for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//		cout << ' ' << *it;
//	cout << endl;
//
//	return 0;
//}

/*
* vector::~vector
销毁容器对象。这将在每个包含的元素上调用allocator_traits::destroy,并使用其分配器释放由矢量分配的所有存储容量。
~vector();
*/

/*
* vector::operator=
将新内容分配给容器，替换其当前内容，并相应地修改其大小。
*/

/*
copy(1)
vector& operator = (const vector& x);
move(2)
vector& operator = (vector& x);
initializer list(3)
vector& operator = (initializer_list<value_type> il);
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//int main()
//{
//	vector<int> foo(3, 0);
//	vector<int> bar(5, 0);
//
//	bar = foo;
//	foo = vector<int>();
//
//	cout << "size of foo: " << int(foo.size()) << endl;
//	cout << "size of bar: " << int(bar.size()) << endl;
//	return 0;
//}

/*
* vector::begin
* vector::end
* vector::rbegin
* vector::rend
* vector::cbegin
* vector::cend
* vector::rcbegin
* vector::rcend
*/

/*
* vector::size
返回vector中元素的数量
这是vector中保存的实际对象的数量，不一定等于其存储容量。
size_type size() const noexcept;
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> myints;
//	cout << "0.size: " << myints.size() << endl;
//
//	for (int i = 0; i < 10; i++)
//	{
//		myints.push_back(i);
//	}
//	cout << "1.size: " << myints.size() << endl;
//
//	myints.insert(myints.end(), 10, 100);
//	cout << "2.size: " << myints.size() << endl;
//
//	myints.pop_back();
//	cout << "3.size: " << myints.size() << endl;
//	
//	return 0;
//}

/*
* vector::max_size
返回该vector可容纳的元素的最大数量。
由于已知的系统或库实现限制，这是容器可以达到的最大潜在大小，
但容器无法保证能够达到该大小；在达到该大小之前的任何时间，任然无法分配存储。
size_type max_size() const noexcept;
*/

/*
* vector::capacity
返回当前为vector分配的存储空间的大小，用元素表示。
这个capacity不一定等于vector的size，它可以相等或更大，额外的空间允许适应增长，
而不需要重新分配每个插入。
size_type capacity() const noexcept;
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> myvector;
//	for (int i = 0; i < 100; i++)
//	{
//		myvector.push_back(i);
//	}
//	cout << "size: " << myvector.size() << endl;
//	cout << "capacity: " << myvector.capacity() << endl;
//	cout << "max_size: " << myvector.max_size() << endl;
//	return 0;
//}

/*
* vector::resize
调整容器的大小，使其包含n个元素。
如果n小于当前容器的size，内容将被缩小到前n个元素，并将其删除（并销毁它们）
如果n大于当前容器size，则通过在末尾插入尽可能多的元素以达到大小n来扩展内容。如果指定了val,
则新元素将初始化为val的副本，否则将进行值初始化。
如果n也大于当前的容器的capacity，分配的存储空间将自动重新分配。
注意这个函数通过插入或者删除元素的内容来改变容器的实际内容，
void resize(size_type n);
void resize(size_type n, const value_type& val);
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//int main()
//{
//	vector<int> myvector;
//
//	for (int i = 0; i < 10; i++)
//	{
//		myvector.push_back(i);
//	}
//
//	myvector.resize(5);
//	myvector.resize(8, 100);
//	myvector.resize(12);
//
//	cout << "myvector contains: ";
//	for (int& x : myvector)
//		cout << ' ' << x;
//	cout << endl;
//
//	return 0;
//}

/*
* vector::empty
返回vector是否为空，即它的size是否为0；
bool empty() const noexcept;
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> myvector;
//	int sum(0);//***初始化列表***
//	//列表初始化具有类型检查和类型转换的功能。如果初始化列表中的值类型不匹配
//	//或者无法进行隐式类型转换，编译器将会报错。
//	for (int i = 0; i <= 10; i++)
//	{
//		myvector.push_back(i);
//	}
//
//	while (!myvector.empty())
//	{
//		sum += myvector.back();
//		myvector.pop_back();
//	}
//	cout << "total: " << sum << endl;
//	return 0;
//
//}

/*
* vector::reserve
请求vector容量至少足以包含n个元素；
如果n大于当前vector容量，则该函数使容器重新分配其存储容量，从而将其容量增大到n或更大。
在所有其他情况下，函数调用不会导致重新分配，并且vector容量不受影响。
这个函数对vector大小没有影响，也不能改变它的元素。
void reserve(size_t n);
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int>::size_type sz;
//	//size_type 由string类型和vector类型定义的类型，用以保存任意string对象
//	//或vector对象的长度，标准库类型将size_type定义为unsigned类型。
//
//	vector<int> foo;
//	sz = foo.capacity();
//	cout << "making foo grow" << endl;
//	for (int i = 0; i < 100; i++)
//	{
//		foo.push_back(i);
//		if (sz != foo.capacity())
//		{
//			sz = foo.capacity();
//			cout << "capacity changed: " << sz << endl;
//		}
//	}
//
//	vector<int> bar;
//	sz = bar.capacity();
//	bar.reserve(100);
//	cout << "making bar grow: " << endl;
//	for (int i = 0; i < 100; i++)
//	{
//		bar.push_back(i);
//		if (sz != bar.capacity())
//		{
//			sz = bar.capacity();
//			cout << "capacity change: " << sz << endl;
//		}
//	}
//	return 0;
//}

/*
* vector::shrink_to_fit
要求容器减少其capacity以适应其尺寸。
该请求是非绑定的，并且容器实现可以自由地进行优化，并保持capacity大于其size的vector。
这可能导致重新分配，但对矢量的大小没有影响，并且不能改变其元素。
void shrink_to_fit()
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> myvector(100);
//	cout << "1. capacity of myvector: " << myvector.capacity() << endl;
//
//	myvector.resize(10);
//	cout << "2. capacity of myvector: " << myvector.capacity() << endl;
//
//	myvector.shrink_to_fit();
//	cout << "3. capacity of myvector: " << myvector.capacity() << endl;
//
//	return 0;
//}

/*
* vector::operator[]
* vector::at
* vector::front
* vector::back
* vector::data
*/

/*
* vector::assign
将新内容分配给vector，替换其当前内容，并相应地修改其大小。
在范围版本（1）中，新内容是从第一个和最后一个范围内的每个元素按相同顺序构造的元素。
在充填版本（2）中，新内容是n个元素，每个元素都被初始化为一个val的副本。
在初始化列表版本（3）中，新内容是以相同顺序作为初始化列表传递的值的副本
range(1)
template <class InputIterator>
	void assign(InputerIterator first, InputIterator last);
fill(2)
void assigh(size_type n, const value_type& val)
initializer list(3)
void assign(initializer_list<value_type> il);
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> first;
//	vector<int> second;
//	vector<int> third;
//
//	first.assign(7, 100);
//
//	vector<int>::iterator it;
//	it = first.begin() + 1;
//
//	second.assign(it, first.end() - 1);
//
//	int myints[] = { 1776, 7, 4 };
//	third.assign(myints, myints + 3);
//
//	cout << "size of first: " << int(first.size()) << endl;
//	cout << "size of second:" << int(second.size()) << endl;
//	cout << "size of third: " << int(third.size()) << endl;
//
//	return 0;
//}
/*
* vector::push_back
在vector的最后一个元素之后添加一个新元素。val的内容被复制（或移动）到新的元素
这有效地将容器size增加了一个，如果新的矢量size超过了当前vector的capacity，
则导致所分配的存储空间自动重新分配。
void push_back (const value_type& val);
void push_back (value_type&& val);
*/

//#include <iostream>
//#include <vector>
//
//int main()
//{
//	std::vector<int> myvector;
//	int myint;
//
//	std::cout << "Please enter some integers (enter 0 to end):\n";
//
//	do {
//		std::cin >> myint;
//		myvector.push_back(myint);
//	} while (myint);
//
//	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
//
//	return 0;
//}

/*
* vector::pop_back
删除vector中的最后一个元素，有效地将容器size减少一个。
这破坏了删除的元素
void pop_back();
*/

//#include <iostream>
//#include <vector>
//
//int main()
//{
//	std::vector<int> myvector;
//	int sum(0);
//	myvector.push_back(100);
//	myvector.push_back(200);
//	myvector.push_back(300);
//
//	while (!myvector.empty())
//	{
//		sum += myvector.back();
//		myvector.pop_back();
//	}
//
//	std::cout << "The elements of myvector add up to " << sum << '\n';
//
//	return 0;
//}

/*
* vector::insert
通过在指定位置的元素之前插入新元素来扩展该vector，通过插入元素的数量有效地增加容器大小。
这会导致分配的存储空间自动重新分配，只有在新的vector的size超过当前的vector的capacity的情况下。
由于vector使用数组作为其基础存储，因此除了将元素插入到vector末尾之后，或者vector的begin之前，
其他位置会导致容器重新定位位置之后的所有元素到它们的新位置。与其他种类的序列容器（如list或forward_list)
执行相同操作相比，这通常是低效的操作。
single element(1)
iterator insert(const_iterator position, const value_type& val);
fill(2)
iterator insert(const_iterator position, size_type n, const value_type& val);
range(3)
template<calss InputIterator>
iterator insert (const_iterator position, InputIterator first, InputIterator last);
move(4)
iterator insert(const_iterator position, value_type& val);
initializer list(5）
iterator insert(const_iterator positon, initializer_list<value_type> il);
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> myvector(3, 100);
//	vector<int>::iterator it;
//
//	it = myvector.begin();
//	it = myvector.insert(it, 200);
//
//	myvector.insert(it, 2, 300);
//
//	it = myvector.begin();
//
//	vector<int> anothervector(2, 400);
//	myvector.insert(it + 2, anothervector.begin(), anothervector.end());
//
//	int myarray[] = { 501, 502, 503 };
//	myvector.insert(myvector.begin(), myarray, myarray + 3);
//
//	cout << "myvector contains: ";
//	for (it = myvector.begin(); it < myvector.end(); it++)
//	{
//		cout << ' ' << *it;
//	}
//	cout << endl;
//	return 0;
//}

//一种导致insert迭代器野指针的错误
/*
int main()
{
	vector<int> v(5, 0);
	vector<int>::iterator vi;

	vi = v.begin();
	v.push_back(10);//这会导致当size > capacity 时，vector进行自动扩容
	//即创建新vector，复制旧vector，这会导致原先声明的迭代器失效。
	v.insert(vi, 2, 300);
	return 0;
}
*/

/*
* vector::erase
从vector中删除单个元素（position）或一系列元素（[first, last]）。
这有效地减少了被去除元素的数量，从而破坏了容器的大小。
由于vector使用一个数组作为其底层存储，所以删除vector结束位置之后，或vector的begin之前的元素外，
将导致容器将段被擦除后的所有元素重新定位的新的位置。与其他种类的序列容器（如list或forward_list）
执行相同操作的操作相比，这通常是低效的操作。
iterator erase(const_iterator position);
iterator erase(const_iterator first, const_iterator last);
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//int main()
//{
//	vector<int> myvector;
//
//	for (int i = 0; i < 10; i++)
//	{
//		myvector.push_back(i);
//	}
//	myvector.erase(myvector.begin() + 5);
//
//	myvector.erase(myvector.begin(), myvector.begin() + 3);
//
//	cout << "myvector contains: ";
//	for (unsigned i = 0; i < myvector.size(); i++)
//	{
//		cout << ' ' << myvector[i];
//	}
//	cout << endl;
//	return 0;
//}

/*
* vector::swap
通过x的内容交换成员的内容，x是另一个相同类型的vector对象。尺寸可能不同。
在调用这个成员函数之后，这个容器中的元素是那些在调用之前在x中的元素，而x的元素是在这个元素中的元素
所有迭代器，引用和指针对交换对象保持有效。
请注意，非成员函数存在具有相同名称的交换，并使用与此成员函数相似的优化来重载该算法。
void swap(vector& x)
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> foo(3, 100);
//	vector<int> bar(5, 200);
//
//	foo.swap(bar);
//
//	cout << "foo contains: ";
//	for (unsigned i = 0; i < foo.size(); i++)
//	{
//		cout << ' ' << foo[i];
//	}
//	cout << endl;
//
//	cout << "bar contains: ";
//	for (unsigned i = 0; i < bar.size(); i++)
//	{
//		cout << ' ' << bar[i];
//	}
//	cout << endl;
//
//	return 0;
//}

/*
* vector::clear
从vector中删除所有元素（被销毁），留下size为0的容器。
不保证重新分配，并且由于调用此函数，vector的capacity不保证发生变化。
强制重新分配的典型替代方法是使用swap  vector<T>().swap(x);
void clear() noexcept;
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void printVector(const vector<int>& v)
//{
//	for (auto it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << ' ';
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vector<int> v1(5, 50);
//
//	printVector(v1);
//	cout << "v1 size = " << v1.size() << endl;
//	cout << "v1.capacity = " << v1.capacity() << endl;
//
//	v1.clear();
//
//	printVector(v1);
//	cout << "v1 size = " << v1.size() << endl;
//	cout << "v1 capacity = " << v1.capacity() << endl;
//
//	v1.push_back(11);
//	v1.push_back(22);
//
//	printVector(v1);
//	cout << "v1 size = " << v1.size() << endl;
//	cout << "v1 capacity = " << v1.capacity() << endl;
//
//	return 0;
//}

/*
* vector::emplace
通过在position位置处插入新元素args来扩展容器。
这个新元素是用args作为构建的参数来构建的。
这有效地增加了一个容器的大小。
分配存储空间的自动重新分配发生在新的vector的size超过当前vector容量的情况下。
由于vector使用数组作为其基础存储，因此除了将元素插入到vector末尾之后，或vector的begin之前，
其他位置会导致容器重新定位位置之后的所有元素到他们的新位置。与其他种类的序列容器执行相同操作的操作相比，这通常是低效的操作。
该元素是通过调用allocator_traits::construct来转换args来创建的。插入一个类似的成员函数，将现有对象复制或移动到容器中。
template<class...Args>
iterator emplace(const_iterator position, Args&&... args);
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> myvector = { 10, 20, 30 };
//
//	auto it = myvector.emplace(myvector.begin() + 1, 100);
//	myvector.emplace(it, 200);
//	myvector.emplace(myvector.end(), 300);
//
//	cout << "myvectorr contains: ";
//	for (auto& x : myvector)
//	{
//		cout << ' ' << x;
//	}
//	cout << endl;
//
//	return 0;
//}

/*
* vector::emplace_back
在vector的末尾插入一个新的元素，紧跟在当前的最后一个元素之后。这个新元素是用args作为
构造函数的参数来构造的。
这有效地将容器大小增加了一个，如果新的vector大小超过了当前的vector容量，则导致所分配的存储空间自动重新分配。
该元素是通过调用allocator_traits::construct来转换args来创建的。
与push_back相比，emplace_back可以避免额外的移动和复制操作。
template<class...Args>
	void emplace_back(Args&...args);
*/

//#include <vector>
//#include <string>
//#include <iostream>
//
//struct President
//{
//    std::string name;
//    std::string country;
//    int year;
//
//    President(std::string p_name, std::string p_country, int p_year)
//        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
//    {
//        std::cout << "I am being constructed.\n";
//    }
//    President(President&& other)
//        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
//    {
//        std::cout << "I am being moved.\n";
//    }
//    President& operator=(const President& other) = default;
//};
//
//int main()
//{
//    std::vector<President> elections;
//    std::cout << "emplace_back:\n";
//    elections.emplace_back("Nelson Mandela", "South Africa", 1994);
//
//    std::vector<President> reElections;
//    std::cout << "\npush_back:\n";
//    reElections.push_back(President("Franklin Delano Roosevelt", "the USA", 1936));
//
//    std::cout << "\nContents:\n";
//    for (President const& president : elections) {
//        std::cout << president.name << " was elected president of "
//            << president.country << " in " << president.year << ".\n";
//    }
//    for (President const& president : reElections) {
//        std::cout << president.name << " was re-elected president of "
//            << president.country << " in " << president.year << ".\n";
//    }
//}

/*
* vector::get_allocator
返回与vector关联的构造器对象的副本
allocator_type get_allocator() const noexcept;
*/

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	vector<int> myvector;
//	int* p;
//	unsigned int i;
//
//	p = myvector.get_allocator().allocate(5);
//
//	for (i = 0; i < 5; i++)
//	{
//		myvector.get_allocator().construct(&p[i], i);
//	}
//	cout << "The allocated array contains: ";
//	for (i = 0; i < 5; i++)
//	{
//		cout << ' ' << p[i];
//	}
//	cout << endl;
//	for (i = 0; i < 5; i++)
//	{
//		myvector.get_allocator().destroy(&p[i]);
//	}
//	myvector.get_allocator().deallocate(p, 5);
//
//	return 0;
//}
/*
* deallocate和destory的关系
deallocate实现的源码：
template <class T>
inline void _deallocate(T* buffer)
{
	::operator delete(buffer);
}

destory:
template <class T>
inline void _destory(T* ptr)
{
	ptr->~T();
}
*/
/*
destory负责调用类型的析构函数，销毁相应内存上的内容（但销毁后内存地址仍保留）

deallocate负责释放内存（此时相应内存中的值在此之前应调用destory销毁，将内存地址返回给系统，代表这部分地址使用引用-1）
*/

/*
relation operators(vector)

swap(vector)

vector
*/


/*
* deque
deque(双端队列)是double-ended queue的一个不规则缩写。
deque是具有动态大小的序列容器，可以在两端（前端或后端）扩展或收缩。

特定的库可以以不同的方式实现deques，通常作为某种形式的动态数组。
但是在任何情况下，它们都允许通过随机访问迭代器直接访问各个元素，通过根据需要扩展和收缩容器来自动处理存储。

因此，它们提供了类似于vector的功能，但是在序列的开始部分也可以高效地插入和删除元素，
而不仅仅是在结尾。但是，与vector不同，deques并不保证将其所有元素存储在连续的存储位置：
deque通过偏移指向另一个元素的指针访问元素会导致未定义的行为。

两个vector和deques提供了一个非常相似的接口，可以用于类似的目的，但内部的工作方式完全不同。
虽然vector使用单个数组需要偶尔重新分配以增长，但是deque的元素可以分散在不同的块的容器，
容器在内部保存必要的信息以提供对其任何元素的持续时间和统一的顺序接口（通过迭代器）的直接访问。
因此，deques在内部比vector更复杂一点，但是这使得他们在某些情况下更有效地增长，尤其是在重新分配变得更加昂贵的很长序列的情况下。

对于频繁插入或者删除开始或结束位置以外的元素的操作，deque表现的更差，并且与列表和转发列表相比，迭代器和引用的一致性更低。

deque上常见操作的复杂性（效率）如下：
随机访问-O(1)
在结尾或开头插入或移除元素-O(1)
出入或移除元素-O(n)
template<class T, class Alloc = allocator<T>> calss deque;
*/

/*
* deque::deque
构造一个deque容器对象，根据所使用的构造函数版本初始化它的内容
*/

//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int main()
//{
//	unsigned int i;
//	//deque的几种构造方式
//	deque<int> first;
//	deque<int> second(4, 100);
//	deque<int> third(second.begin(), second.end());
//	deque<int> fourth(third);
//
//	int myints[] = { 16, 2, 77, 29 };
//	deque<int> fifth(myints, myints + sizeof(myints) / sizeof(myints[0]));
//
//	cout << "The contents of fifth are: ";
//	for (deque<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
//		cout << ' ' << *it;
//	cout << endl;
//
//	return 0;
//}

/*
* deque::push_back
在当前的最后一个元素之后，在deque容器的末尾添加一个新元素。
val内容被复制（或移动）到新的元素。
这有效地增加了一个容器的大小
void push_back(const value_type& val);
void push_back(value_type& val);
*/

//#include <iostream>
//#include <deque>
//
//int main()
//{
//	std::deque<int> mydeque;
//	int myint;
//
//	std::cout << "Please enter some integers (enter 0 to end):\n";
//
//	do {
//		std::cin >> myint;
//		mydeque.push_back(myint);
//	} while (myint);
//
//	std::cout << "mydeque stores " << (int)mydeque.size() << " numbers.\n";
//
//	return 0;
//}

/*
* deque::push_front
在deque容器的开始位置插入一个新的元素，位于当前的第一个元素之前。
val的内容被复制（或移动）到插入的元素
这有效地增加了一个容器的大小
void push_front(const val_type& val)
void push_front(value_type& val)
*/

//#include <iostream>
//#include <deque>
//
//int main()
//{
//	std::deque<int> mydeque(2, 100);
//	mydeque.push_front(200);
//	mydeque.push_front(300);
//
//	std::cout << "mydeque contains:";
//	for (std::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	return 0;
//}

/*
* deque::pop_back
删除deque容器中的最后一个元素，有效地将容器大小减少一个。
这破坏了被删除的元素
void pop_back();
*/

//#include <iostream>
//#include <deque>
//
//int main()
//{
//	std::deque<int> mydeque;
//	int sum(0);
//	mydeque.push_back(10);
//	mydeque.push_back(20);
//	mydeque.push_back(30);
//
//	while (!mydeque.empty())
//	{
//		sum += mydeque.back();
//		mydeque.pop_back();
//	}
//
//	std::cout << "The elements of mydeque add up to " << sum << '\n';
//
//	return 0;
//}

/*
* deque::pop_front
删除deque容器中的第一个元素，有效地减小其大小。
这破坏了被删除的元素
void pop_front();
*/

//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int main()
//{
//	std::deque<int> mydeque;
//
//	mydeque.push_back(100);
//	mydeque.push_back(200);
//	mydeque.push_back(300);
//
//	std::cout << "Popping out the elements in mydeque:";
//	while (!mydeque.empty())
//	{
//		std::cout << ' ' << mydeque.front();
//		mydeque.pop_front();
//	}
//
//	std::cout << "\nThe final size of mydeque is " << int(mydeque.size()) << '\n';
//
//	return 0;
//}

/*
* deque::emplace_back
在deque的末尾插入一个新的元素，紧跟在当前的最后一个元素之后。这个新的元素的用args作为构建的参数来构建的。
这有效地增加了一个容器的大小。
该元素是通过调用allocator_traits::construct来转换args来创建的。
存在一个类似的成员函数push_back，它可以将现有的对象复制或移动到容器中。
template<class...Args>
	void emplace_back(Args&...args);
*/

//#include <iostream>
//#include <deque>
//
//int main()
//{
//	std::deque<int> mydeque = { 10,20,30 };
//
//	mydeque.emplace_back(100);
//	mydeque.emplace_back(200);
//
//	std::cout << "mydeque contains:";
//	for (auto& x : mydeque)
//		std::cout << ' ' << x;
//	std::cout << '\n';
//
//	return 0;
//}

/*
* forward_list
forward_list（单向链表）是序列容器，允许在序列中的任何地方进行恒定的时间插入和擦除操作。

forward_list（单向链表）被实现为单链表；单链表可以将它们包含的每个元素存储在不同和不相关的存储位置中。
通过关联到序列中下一个元素的链接的每个元素来保留排序。

forward_list容器和列表之间的主要设计区别容器是第一个内部只保留一个到下一个元素的链接，
而后者每个元素保留两个链接：一个指向下一个元素，一个指向前一个元素，允许在两个方向上的有效迭代，但是每个元素消耗额外的存储空间并且
插入和移除元件的时间开销略高。因此，forward_list对象比列表更有效率，尽管它们只能向前迭代。

与其他基本的标准序列容器（array, vector和deque），forward_list通常在插入、提取和移动容器内任何位置的元素方面效果更好。
因此也适用于密集使用这些元素的算法，如排序算法。

default (1)
explicit forward_list (const allocator_type& alloc = allocator_type());
fill (2)
explicit forward_list (size_type n);
explicit forward_list (size_type n, const value_type& val,
						const allocator_type& alloc = allocator_type());
range (3)
template <class InputIterator>
  forward_list (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type());
copy (4)
forward_list (const forward_list& fwdlst);
forward_list (const forward_list& fwdlst, const allocator_type& alloc);
move (5)
forward_list (forward_list&& fwdlst);
forward_list (forward_list&& fwdlst, const allocator_type& alloc);
initializer list (6)
forward_list (initializer_list<value_type> il,
			  const allocator_type& alloc = allocator_type());
*/

//#include <iostream>
//#include <forward_list>
//
//using namespace std;
//
//int main()
//{
//	forward_list<int> first;
//	forward_list<int> second(3, 77);
//	forward_list<int> third(second.begin(), second.end());
//	forward_list<int> fourth(third);
//	forward_list<int> fifth(move(fourth));
//	forward_list<int> sixth = { 3, 52, 25, 90 };
//
//	std::cout << "first:"; for (int& x : first)  std::cout << " " << x; std::cout << '\n';
//	std::cout << "second:"; for (int& x : second) std::cout << " " << x; std::cout << '\n';
//	std::cout << "third:";  for (int& x : third)  std::cout << " " << x; std::cout << '\n';
//	std::cout << "fourth:"; for (int& x : fourth) std::cout << " " << x; std::cout << '\n';
//	std::cout << "fifth:";  for (int& x : fifth)  std::cout << " " << x; std::cout << '\n';
//	std::cout << "sixth:";  for (int& x : sixth)  std::cout << " " << x; std::cout << '\n';
//
//	return 0;
//}

/*
* forward_list::~forward_list
*/

/*
* forward_list::before_begin
返回指向容器中第一个元素之前的位置的迭代器
返回的迭代器不应被解除引用：它是为了用作成员函数的参数
emplace_after, insert_after,erase_after,或splice_after，指定序列，其中执行该动作的位置的开始位置
iterator before_begin()noexcept;
const_iterator before_begin()const noexcept;
*/

//#include <iostream>
//#include <forward_list>
//
//using namespace std;
//
//int main()
//{
//	forward_list<int> mylist = { 20, 30, 40, 50 };
//	
//	mylist.insert_after(mylist.before_begin(), 11);
//
//	cout << "mylist contains: ";
//	for (int& x : mylist)
//		cout << ' ' << x;
//	cout << endl;
//
//	return 0;
//}

/*
* forward_list::cbefore_begin
返回指向容器中的第一个元素之前的位置的const_iterator
一个常量性是指向常量容器的迭代器。这个迭代器可以增加和减少（除非它本身也是const）
就像forward_list::before_begin返回的迭代器一样，但不能用来修改它指向的内容
返回的值不能解引用。
const_iterator cbefore_begin()xonst noexcept;
*/

//#include <iostream>
//#include <forward_list>
//
//int main()
//{
//	std::forward_list<int> mylist = { 77, 2, 16 };
//
//	mylist.insert_after(mylist.cbefore_begin(), 19);
//
//	std::cout << "mylist contains:";
//	for (int& x : mylist) std::cout << ' ' << x;
//	std::cout << '\n';
//
//	return 0;
//}

/*
* list
*/

/*
* stack
*/

/*
* queue
*/

/*
* priority_queue
*/

/*
* set
*/

/*
* multiset
*/

/*
* map
map是关联容器，按照特定顺序存储由key value（键值）和mapped value（映射值）组合形成的元素

在映射中，键值通常用于对元素进行排序和唯一标识，而映射值的存储与此键关联的内容。
该类型的键和映射的值可能不同，并且在部件类型被分组在一起VALUE_TYPE，这是一种对类型结合
typedef pair<const Key, T> value_type;

在内部，映射中的元素总是按照由其内部比较对象（比较类型）指示的特定的严格弱排序标准按键排序。
映射容器通常比unordered_map容器慢，以通过它们的键来访问各个元素，但是它们允许基于它们的顺序对子集进行直接迭代。
在该映射值地图可以直接通过使用其相应的键来访问括号运算符([])。

template<class Key,
		 class T,
		 class Compare = less<key>
		 class Alloc = allocator<pair<const Key, T> >
		 >class map;
*/

/*
* map::map
构造一个映射容器对象，根据所使用的构造器版本初始化其内容：
（1）空容器构造函数（默认构造函数）

构造一个空的容器，没有元素。

（2）范围构造函数

构造具有一样多的元素的范围内的容器[第一，最后一个），其中每个元件布设构造的从在该范围内它的相应的元件。

（3）复制构造函数（并用分配器复制）

使用x中的每个元素的副本构造一个容器。

（4）移动构造函数（并与分配器一起移动）

构造一个获取x元素的容器。 如果指定了alloc并且与x的分配器不同，那么元素将被移动。否则，没有构建元素（他们的所有权直接转移）。 x保持未指定但有效的状态。

（5）初始化列表构造函数

用il中的每个元素的副本构造一个容器。

empty (1)
explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
explicit map (const allocator_type& alloc);
range (2)
template <class InputIterator>
  map (InputIterator first, InputIterator last,
	   const key_compare& comp = key_compare(),const allocator_type& = allocator_type());
copy (3)
map (const map& x);
map (const map& x, const allocator_type& alloc);
move (4)
map (map&& x);
map (map&& x, const allocator_type& alloc);
initializer list (5)
map (initializer_list<value_type> il,const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
*/

//#include <iostream>
//#include <map>
//
//bool fncomp(char lhs, char rhs) { return lhs < rhs; }
//
//struct classcomp {
//	bool operator() (const char& lhs, const char& rhs) const
//	{
//		return lhs < rhs;
//	}
//};
//
//int main()
//{
//	std::map<char, int> first;
//
//	first['a'] = 10;
//	first['b'] = 30;
//	first['c'] = 50;
//	first['d'] = 70;
//
//	std::map<char, int> second(first.begin(), first.end());
//
//	std::map<char, int> third(second);
//
//	std::map<char, int, classcomp> fourth;                 // class as Compare
//
//	bool(*fn_pt)(char, char) = fncomp;
//	std::map<char, int, bool(*)(char, char)> fifth(fn_pt); // function pointer as Compare
//
//	return 0;
//}

/*
* map::begin
返回引用map容器中第一个元素的迭代器
由于map容器始终保持其元素的顺序，所以开始指向遵循容器排序标准的元素。
如果容器是空的，则返回的迭代器不应被解除引用。
iterator begin() noexcept;
const_iterator begin()const noexcpet;
*/

//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	map<char, int> mymap;
//
//	mymap['b'] = 100;
//	mymap['a'] = 200;
//	mymap['c'] = 300;
//
//	for (map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
//		cout << it->first << " => " << it->second << endl;
//
//	return 0;
//}

/*
* map::key_comp
返回容器用于比较键的比较对象的副本
key_compare key_comp() const;
*/

//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	map<char, int> mymap;
//	map<char, int>::key_compare mycomp = mymap.key_comp();
//
//	mymap['a'] = 100;
//	mymap['b'] = 200;
//	mymap['c'] = 300;
//
//	cout << "mymap contains: " << endl;
//
//	char highest = mymap.rbegin()->first;
//
//	map<char, int>::iterator it = mymap.begin();
//	do
//	{
//		cout << it->first << " => " << it->second << endl;
//	} while (mycomp((*it++).first, highest));
//	cout << endl;
//	return 0;
//}

/*
* map::value_comp
返回可用于比较两个元素的比较对象，以获取第一个元素的键是否在第二个元素之前
*/

//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	map<char, int> mymap;
//
//	mymap['x'] = 1001;
//	mymap['y'] = 2002;
//	mymap['z'] = 3003;
//
//	cout << "mymap contains: " << endl;
//
//	pair<char, int> highest = *mymap.rbegin();
//	map<char, int>::iterator it = mymap.begin();
//
//	do
//	{
//		cout << it->first << " => " << it->second << endl;
//	} while (mymap.value_comp()(*it++, highest));
//
//	return 0;
//}

/*
* map::find
在容器中搜索具有等于k的键的元素，如果找到则返回一个迭代器，否则返回map::end的迭代器
如果容器的比较对象自反地返回假（即不管元素作为参数传递的顺序），则两个key被认为是等同的。
另一个成员函数map::count可以用来检查一个特定的键是否存在。
iterator find(const key_type& k);
const_iterator find(const key_type& k) const;
*/

//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	map<char, int> mymap;
//	map<char, int>::iterator it;
//
//	mymap['a'] = 50;
//	mymap['b'] = 100;
//	mymap['c'] = 150;
//	mymap['d'] = 200;
//
//	it = mymap.find('b');
//	if (it != mymap.end())
//	{
//		mymap.erase(it);
//	}
//
//	cout << "element in mymap: " << endl;
//	cout << "a => " << mymap.find('a')->second << endl;
//	cout << "c => " << mymap.find('c')->second << endl;
//	cout << "d => " << mymap.find('d')->second << endl;
//}

/*
* map::count
在容器中搜索具有等于k的键的元素，并返回匹配的数量。
由于map容器中的所有元素都是唯一的，因此该函数只能返回1（如果找到）或0（未找到）
如果容器的比较对象自反地返回错误（即，不管按键作为参数传递的顺序），则两个键被认为是等同的。
size_type count(const key_type& k)const;
*/

//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	map<char, int> mymap;
//	char c;
//
//	mymap['a'] = 101;
//	mymap['c'] = 202;
//	mymap['f'] = 303;
//
//	for (c = 'a'; c < 'h'; c++)
//	{
//		cout << c;
//		if (mymap.count(c) > 0)
//		{
//			cout << " is an element of mymap" << endl;
//		}
//		else
//		{
//			cout << " is not an element of mymap" << endl;
//		}
//
//	}
//	return 0;
//}

/*
* map::lower_bound
将迭代器返回到下限
返回指向容器中第一个元素的迭代器，该元素的键不会在k之前出现（即，它是等价的或者在其后）
该函数使用其内部比较对象（key_comp）来确定这一点，将迭代器返回到key_comp(element_key, k)
将返回false的第一个元素
如果map类用默认的比较类型(less)实例化，则函数返回一个迭代器到第一个元素，其键不小于k。
一个类似的成员函数upper_bound具有相同的行为，除非映射包含一个key值等于k的元素：
在这种情况下，lower_bound返回指向该元素的迭代器，而upper_bound返回指向下一个元素的迭代器。

iterator lower_bound(const key_type& k);
const iterator lower_bound(const key_type& k) const;
*/

/*
* map::upper_bound
将迭代器返回到上限
返回一个指向容器中第一个元素的迭代器，它的关键字被认为是在k之后。
该函数使用其内部比较对象（key_comp)来确定这一点，将迭代器返回到key_comp(k, element_key)
将返回true的第一个元素
如果map类用默认的比较类型(less)实例化，则函数返回一个迭代器到第一个元素，其键大于k。
类似的成员函数lower_bound具有upper_bound相同的行为，除了map包含一个元素，其键值等于k：
在这种情况下，lower_bound返回指向该元素的迭代器，而upper_bound返回指向下一个元素的迭代器。
iterator upper_bound(const key_type& k);
const_iterator upper_bound(const key_type& k) const;
*/

//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	map<char, int> mymap;
//	map<char, int>::iterator itlow, itup;
//
//	mymap['a'] = 20;
//	mymap['b'] = 40;
//	mymap['c'] = 60;
//	mymap['d'] = 80;
//	mymap['e'] = 100;
//
//	itlow = mymap.lower_bound('b');
//	itup = mymap.upper_bound('d');
//
//	mymap.erase(itlow, itup);
//
//	for (map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
//		cout << it->first << " => " << it->second << endl;
//
//	return 0;
//}

/*
* map::equal_range
获取相同元素的范围
返回包含容器中所有具有与k等价的键的元素的范围边界。
由于map容器中的元素具有唯一键，所以返回的范围最多只包含一个元素。
如果没有找到匹配，则返回的范围具有零的长度，与两个迭代器指向具有考虑去后一个密钥对
所述第一元件k根据容器的内部比较对象（key_comp)
如果容器的比较对象返回false，则两个键被认为是等价的。
pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
pair<iterator, iterator> equal_range(const key_type& k);
*/

//#include <iostream>
//#include <map>
//
//using namespace std;
//
//int main()
//{
//	map<char, int> mymap;
//
//	mymap['a'] = 10;
//	mymap['b'] = 20;
//	mymap['c'] = 30;
//
//	pair<map<char, int>::iterator, map<char, int>::iterator> ret;
//	ret = mymap.equal_range('b');
//
//	cout << "lower bound points to: ";
//	cout << ret.first->first << " => " << ret.first->second << endl;
//
//	cout << "upper bound points to: ";
//	cout << ret.second->first << " => " << ret.second->second << endl;
//
//	return 0;
//}

/*
* multimap
*/

/*
* 无序容器（Unordered Container）
* unordered_set
* unordered_multiset
* unordered_map
* unordered_multimap
* 都是以哈希表实现的。
*/

/*
* tuple
元组是一个能够容纳元素集合的对象。每个元素可以是不同的类型
template<class...Types> class tuple;
*/

//#include <iostream>
//#include <tuple>
//
//using namespace std;
//
//int main()
//{
//	tuple<int, char> foo(10, 'x');
//	auto bar = make_tuple("test", 3.1, 14, 'y');
//
//	get<2>(bar) = 100;
//
//	int myint;
//	char mychar;
//
//	tie(myint, mychar) = foo;
//	tie(ignore, ignore, myint, mychar) = bar;
//
//	mychar = get<3>(bar);
//
//	get<0>(foo) = get<2>(bar);
//	get<1>(foo) = mychar;
//
//	cout << "foo contains: ";
//	cout << get<0>(foo) << ' ';
//	cout << get<1>(foo) << endl;
//	return 0;
//}

/*
* tuple::tuple
构建一个tuple对象
这涉及单独构建其元素，初始化取决于调用的构造函数形式：
（1）默认的构造函数
构建一个 元组对象的元素值初始化。

（2）复制/移动构造函数
该对象使用tpl的内容进行初始化元组目的。tpl 的相应元素被传递给每个元素的构造函数。

（3）隐式转换构造函数
同上。tpl中的 所有类型都可以隐含地转换为构造中它们各自元素的类型元组 目的。

（4）初始化构造函数 用elems中的相应元素初始化每个元素。elems 的相应元素被传递给每个元素的构造函数。

（5）对转换构造函数
该对象有两个对应于pr.first和的元素pr.second。PR中的所有类型都应该隐含地转换为其中各自元素的类型元组 目的。

（6）分配器版本
和上面的版本一样，除了每个元素都是使用allocator alloc构造的。

default (1)
constexpr tuple();
copy / move (2)
tuple (const tuple& tpl) = default;
tuple (tuple&& tpl) = default;
implicit conversion (3)
template <class... UTypes>
  tuple (const tuple<UTypes...>& tpl);
template <class... UTypes>
  tuple (tuple<UTypes...>&& tpl);
initialization (4)
explicit tuple (const Types&... elems);
template <class... UTypes>
  explicit tuple (UTypes&&... elems);
conversion from pair (5)
template <class U1, class U2>
  tuple (const pair<U1,U2>& pr);
template <class U1, class U2>
  tuple (pair<U1,U2>&& pr);
allocator (6)
template<class Alloc>
  tuple (allocator_arg_t aa, const Alloc& alloc);
template<class Alloc>
  tuple (allocator_arg_t aa, const Alloc& alloc, const tuple& tpl);
template<class Alloc>
  tuple (allocator_arg_t aa, const Alloc& alloc, tuple&& tpl);
template<class Alloc,class... UTypes>
  tuple (allocator_arg_t aa, const Alloc& alloc, const tuple<UTypes...>& tpl);
template<class Alloc, class... UTypes>
  tuple (allocator_arg_t aa, const Alloc& alloc, tuple<UTypes...>&& tpl);
template<class Alloc>
  tuple (allocator_arg_t aa, const Alloc& alloc, const Types&... elems);
template<class Alloc, class... UTypes>
  tuple (allocator_arg_t aa, const Alloc& alloc, UTypes&&... elems);
template<class Alloc, class U1, class U2>
  tuple (allocator_arg_t aa, const Alloc& alloc, const pair<U1,U2>& pr);
template<class Alloc, class U1, class U2>
  tuple (allocator_arg_t aa, const Alloc& alloc, pair<U1,U2>&& pr);
*/

//#include <iostream>
//#include <utility>
//#include <tuple>
//
//using namespace std;
//
//int main()
//{
//	tuple<int, char> first;
//	tuple<int, char> second(first);
//	tuple<int, char> third(make_tuple(20, 'b'));
//	tuple<long, char> fourth(third);
//	tuple<int ,char> fifth(10, 'a');
//	tuple<int, char> sixth(make_pair(30, 'c'));
//
//	cout << "sixth contains: " << get<0>(sixth);
//	cout << " and " << get<1>(sixth) << endl;
//
//	return 0;
//}

/*
* pair
这个类把一对值（values）结合在一起，这些值可能是不同的类型（T1和T2)。
每个值可以被公有的成员变量first、second访问
pair是tuple的一个特例
pair的实现是一个结构体，主要的两个成员变量是first，second
因为是使用struct而不是class，所以可以直接使用pair的成员变量。
应用：
可以将两个数据类型组合成一个如map<key, value>
当某个函数需要两个返回值时
template<class T1, class T2> struct pair;
*/

/*
* pair::pair
构建一个pair对象。

这涉及到单独构建它的两个组件对象，初始化依赖于调用的构造器形式：

（1）默认的构造函数

构建一个pair，对象的元素值初始化。

（2）复制/移动构造函数（和隐式转换）

该对象被初始化为pr的内容 对目的。pr的相应成员被传递给每个成员的构造函数。

（3）初始化构造函数

（4）分段构造

构造成员 first 和 second 到位，传递元素first_args 作为参数的构造函数 first，和元素 second_args 到的构造函数 second 。

default (1)
constexpr pair();
copy / move (2)
template<class U, class V> pair (const pair<U,V>& pr);
template<class U, class V> pair (pair<U,V>&& pr);
pair (const pair& pr) = default;
pair (pair&& pr) = default;
initialization (3)
pair (const first_type& a, const second_type& b);
template<class U, class V> pair (U&& a, V&& b);
piecewise (4)
template <class... Args1, class... Args2>
  pair (piecewise_construct_t pwc, tuple<Args1...> first_args,
								   tuple<Args2...> second_args);
*/

//#include <utility>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	pair<string, double> product1;
//	pair<string, double> product2("tomatoes", 2.30);
//	pair<string, double> product3(product2);
//
//	product1 = make_pair(string("lightbulbs"), 0.99);
//	product2.first = "shoes";
//	product3.second = 39.90;
//
//	cout << "The price of " << product1.first << " is $" << product1.second << endl;
//	cout << "The price of " << product2.first << " is $" << product2.second << endl;
//	cout << "The price of " << product3.first << " is $" << product3.second << endl;
//	return 0;
//}

/*
* algorithms
// 简单查找算法，要求输入迭代器（input iterator）
find(beg, end, val); // 返回一个迭代器，指向输入序列中第一个等于 val 的元素，未找到返回 end
find_if(beg, end, unaryPred); // 返回一个迭代器，指向第一个满足 unaryPred 的元素，未找到返回 end
find_if_not(beg, end, unaryPred); // 返回一个迭代器，指向第一个令 unaryPred 为 false 的元素，未找到返回 end
count(beg, end, val); // 返回一个计数器，指出 val 出现了多少次
count_if(beg, end, unaryPred); // 统计有多少个元素满足 unaryPred
all_of(beg, end, unaryPred); // 返回一个 bool 值，判断是否所有元素都满足 unaryPred
any_of(beg, end, unaryPred); // 返回一个 bool 值，判断是否任意（存在）一个元素满足 unaryPred
none_of(beg, end, unaryPred); // 返回一个 bool 值，判断是否所有元素都不满足 unaryPred

// 查找重复值的算法，传入向前迭代器（forward iterator）
adjacent_find(beg, end); // 返回指向第一对相邻重复元素的迭代器，无相邻元素则返回 end
adjacent_find(beg, end, binaryPred); // 返回指向第一对相邻重复元素的迭代器，无相邻元素则返回 end
search_n(beg, end, count, val); // 返回一个迭代器，从此位置开始有 count 个相等元素，不存在则返回 end
search_n(beg, end, count, val, binaryPred); // 返回一个迭代器，从此位置开始有 count 个相等元素，不存在则返回 end

// 查找子序列算法，除 find_first_of（前两个输入迭代器，后两个前向迭代器） 外，都要求两个前向迭代器
search(beg1, end1, beg2, end2); // 返回第二个输入范围（子序列）在爹一个输入范围中第一次出现的位置，未找到则返回 end1
search(beg1, end1, beg2, end2, binaryPred); // 返回第二个输入范围（子序列）在爹一个输入范围中第一次出现的位置，未找到则返回 end1
find_first_of(beg1, end1, beg2, end2); // 返回一个迭代器，指向第二个输入范围中任意元素在第一个范围中首次出现的位置，未找到则返回end1
find_first_of(beg1, end1, beg2, end2, binaryPred); // 返回一个迭代器，指向第二个输入范围中任意元素在第一个范围中首次出现的位置，未找到则返回end1
find_end(beg1, end1, beg2, end2); // 类似 search，但返回的最后一次出现的位置。如果第二个输入范围为空，或者在第一个输入范围为空，或者在第一个输入范围中未找到它，则返回 end1
find_end(beg1, end1, beg2, end2, binaryPred); // 类似 search，但返回的最后一次出现的位置。如果第二个输入范围为空，或者在第一个输入范围为空，或者在第一个输入范围中未找到它，则返回 end1

// 其他只读算法，传入输入迭代器
for_each(beg, end, unaryOp); // 对输入序列中的每个元素应用可调用对象 unaryOp，unaryOp 的返回值被忽略
mismatch(beg1, end1, beg2); // 比较两个序列中的元素。返回一个迭代器的 pair，表示两个序列中第一个不匹配的元素
mismatch(beg1, end1, beg2, binaryPred); // 比较两个序列中的元素。返回一个迭代器的 pair，表示两个序列中第一个不匹配的元素
equal(beg1, end1, beg2); // 比较每个元素，确定两个序列是否相等。
equal(beg1, end1, beg2, binaryPred); // 比较每个元素，确定两个序列是否相等。

// 二分搜索算法，传入前向迭代器或随机访问迭代器（random-access iterator），要求序列中的元素已经是有序的。通过小于运算符（<）或 comp 比较操作实现比较。
lower_bound(beg, end, val); // 返回一个非递减序列 [beg, end) 中的第一个大于等于值 val 的位置的迭代器，不存在则返回 end
lower_bound(beg, end, val, comp); // 返回一个非递减序列 [beg, end) 中的第一个大于等于值 val 的位置的迭代器，不存在则返回 end
upper_bound(beg, end, val); // 返回一个非递减序列 [beg, end) 中第一个大于 val 的位置的迭代器，不存在则返回 end
upper_bound(beg, end, val, comp); // 返回一个非递减序列 [beg, end) 中第一个大于 val 的位置的迭代器，不存在则返回 end
equal_range(beg, end, val); // 返回一个 pair，其 first 成员是 lower_bound 返回的迭代器，其 second 成员是 upper_bound 返回的迭代器
binary_search(beg, end, val); // 返回一个 bool 值，指出序列中是否包含等于 val 的元素。对于两个值 x 和 y，当 x 不小于 y 且 y 也不小于 x 时，认为它们相等。

// 只写不读算法，要求输出迭代器（output iterator）
fill(beg, end, val); // 将 val 赋予每个元素，返回 void
fill_n(beg, cnt, val); // 将 val 赋予 cnt 个元素，返回指向写入到输出序列最有一个元素之后位置的迭代器
genetate(beg, end, Gen); // 每次调用 Gen() 生成不同的值赋予每个序列，返回 void
genetate_n(beg, cnt, Gen); // 每次调用 Gen() 生成不同的值赋予 cnt 个序列，返回指向写入到输出序列最有一个元素之后位置的迭代器

// 使用输入迭代器的写算法，读取一个输入序列，将值写入到一个输出序列（dest）中
copy(beg, end, dest); // 从输入范围将元素拷贝所有元素到 dest 指定定的目的序列
copy_if(beg, end, dest, unaryPred); // 从输入范围将元素拷贝满足 unaryPred 的元素到 dest 指定定的目的序列
copy_n(beg, n, dest); // 从输入范围将元素拷贝前 n 个元素到 dest 指定定的目的序列
move(beg, end, dest); // 对输入序列中的每个元素调用 std::move，将其移动到迭代器 dest 开始始的序列中
transform(beg, end, dest, unaryOp); // 调用给定操作（一元操作），并将结果写到dest中
transform(beg, end, beg2, dest, binaryOp); // 调用给定操作（二元操作），并将结果写到dest中
replace_copy(beg, end, dest, old_val, new_val); // 将每个元素拷贝到 dest，将等于 old_val 的的元素替换为 new_val
replace_copy_if(beg, end, dest, unaryPred, new_val); // 将每个元素拷贝到 dest，将满足 unaryPred 的的元素替换为 new_val
merge(beg1, end1, beg2, end2, dest); // 两个输入序列必须都是有序的，用 < 运算符将合并后的序列写入到 dest 中
merge(beg1, end1, beg2, end2, dest, comp); // 两个输入序列必须都是有序的，使用给定的比较操作（comp）将合并后的序列写入到 dest 中

// 使用前向迭代器的写算法，要求前向迭代器
iter_swap(iter1, iter2); // 交换 iter1 和 iter2 所表示的元素，返回 void
swap_ranges(beg1, end1, beg2); // 将输入范围中所有元素与 beg2 开始的第二个序列中所有元素进行交换。返回递增后的的 beg2，指向最后一个交换元素之后的位置。
replace(beg, end, old_val, new_val); // 用 new_val 替换等于 old_val 的每个匹配元素
replace_if(beg, end, unaryPred, new_val); // 用 new_val 替换满足 unaryPred 的每个匹配元素

// 使用双向迭代器的写算法，要求双向选代器（bidirectional iterator）
copy_backward(beg, end, dest); // 从输入范围中拷贝元素到指定目的位置。如果范围为空,则返回值为 dest；否则，返回值表示从 *beg 中拷贝或移动的元素。
move_backward(beg, end, dest);  // 从输入范围中移动元素到指定目的位置。如果范围为空,则返回值为 dest；否则,返回值表示从 *beg 中拷贝或移动的元素。
inplace_merge(beg, mid, end); // 将同一个序列中的两个有序子序列合并为单一的有序序列。beg 到 mid 间的子序列和 mid 到 end 间的子序列被合并，并被写入到原序列中。使用 < 比较元素。
inplace_merge(beg, mid, end, comp); // 将同一个序列中的两个有序子序列合并为单一的有序序列。beg 到 mid 间的子序列和 mid 到 end 间的子序列被合并，并被写入到原序列中。使用给定的 comp 操作。

// 划分算法，要求双向选代器（bidirectional iterator）
is_partitioned(beg, end, unaryPred); // 如果所有满足谓词 unaryPred 的元素都在不满足 unarypred 的元素之前，则返回 true。若序列为空，也返回 true
partition_copy(beg, end, dest1, dest2, unaryPred); // 将满足 unaryPred 的元素拷贝到到 dest1，并将不满足 unaryPred 的元素拷贝到到 dest2。返回一个迭代器 pair，其 first 成员表示拷贝到 dest1 的的元素的末尾，second 表示拷贝到 dest2 的元素的末尾。
partitioned_point(beg, end, unaryPred); // 输入序列必须是已经用 unaryPred 划分过的。返回满足  unaryPred 的范围的尾后迭代器。如果返回的迭代器不是 end，则它指向的元素及其后的元素必须都不满足 unaryPred
stable_partition(beg, end, unaryPred); // 使用 unaryPred 划分输入序列。满足 unaryPred 的元素放置在序列开始，不满足的元素放在序列尾部。返回一个迭代器，指向最后一个满足 unaryPred 的元素之后的位置如果所有元素都不满足 unaryPred，则返回 beg
partition(beg, end, unaryPred); // 使用 unaryPred 划分输入序列。满足 unaryPred 的元素放置在序列开始，不满足的元素放在序列尾部。返回一个迭代器，指向最后一个满足 unaryPred 的元素之后的位置如果所有元素都不满足 unaryPred，则返回 beg

// 排序算法，要求随机访问迭代器（random-access iterator）
sort(beg, end); // 排序整个范围
stable_sort(beg, end); // 排序整个范围（稳定排序）
sort(beg, end, comp); // 排序整个范围
stable_sort(beg, end, comp); // 排序整个范围（稳定排序）
is_sorted(beg, end); // 返回一个 bool 值，指出整个输入序列是否有序
is_sorted(beg, end, comp); // 返回一个 bool 值，指出整个输入序列是否有序
is_sorted_until(beg, end); // 在输入序列中査找最长初始有序子序列，并返回子序列的尾后迭代器
is_sorted_until(beg, end, comp); // 在输入序列中査找最长初始有序子序列，并返回子序列的尾后迭代器
partial_sort(beg, mid, end); // 排序 mid-beg 个元素。即，如果 mid-beg 等于 42，则此函数将值最小的 42 个元素有序放在序列前 42 个位置
partial_sort(beg, mid, end, comp); // 排序 mid-beg 个元素。即，如果 mid-beg 等于 42，则此函数将值最小的 42 个元素有序放在序列前 42 个位置
partial_sort_copy(beg, end, destBeg, destEnd); // 排序输入范围中的元素，并将足够多的已排序元素放到 destBeg 和 destEnd 所指示的序列中
partial_sort_copy(beg, end, destBeg, destEnd, comp); // 排序输入范围中的元素，并将足够多的已排序元素放到 destBeg 和 destEnd 所指示的序列中
nth_element(beg, nth, end); // nth 是一个迭代器，指向输入序列中第 n 大的元素。nth 之前的元素都小于等于它，而之后的元素都大于等于它
nth_element(beg, nth, end, comp); // nth 是一个迭代器，指向输入序列中第 n 大的元素。nth 之前的元素都小于等于它，而之后的元素都大于等于它

// 使用前向迭代器的重排算法。普通版本在输入序列自身内部重拍元素，_copy 版本完成重拍后写入到指定目的序列中，而不改变输入序列
remove(beg, end, val); // 通过用保留的元素覆盖要删除的元素实现删除 ==val 的元素，返回一个指向最后一个删除元素的尾后位置的迭代器
remove_if(beg, end, unaryPred); // 通过用保留的元素覆盖要删除的元素实现删除满足 unaryPred 的元素，返回一个指向最后一个删除元素的尾后位置的迭代器
remove_copy(beg, end, dest, val); // 通过用保留的元素覆盖要删除的元素实现删除 ==val 的元素，返回一个指向最后一个删除元素的尾后位置的迭代器
remove_copy_if(beg, end, dest, unaryPred); // 通过用保留的元素覆盖要删除的元素实现删除满足 unaryPred 的元素，返回一个指向最后一个删除元素的尾后位置的迭代器
unique(beg, end); // 通过对覆盖相邻的重复元素（用 == 确定是否相同）实现重排序列。返回一个迭代器，指向不重复元素的尾后位置
unique (beg, end, binaryPred); // 通过对覆盖相邻的重复元素（用 binaryPred 确定是否相同）实现重排序列。返回一个迭代器，指向不重复元素的尾后位置
unique_copy(beg, end, dest); // 通过对覆盖相邻的重复元素（用 == 确定是否相同）实现重排序列。返回一个迭代器，指向不重复元素的尾后位置
unique_copy_if(beg, end, dest, binaryPred); // 通过对覆盖相邻的重复元素（用 binaryPred 确定是否相同）实现重排序列。返回一个迭代器，指向不重复元素的尾后位置
rotate(beg, mid, end); // 围绕 mid 指向的元素进行元素转动。元素 mid 成为为首元素，随后是 mid+1 到到 end 之前的元素，再接着是 beg 到 mid 之前的元素。返回一个迭代器，指向原来在 beg 位置的元素
rotate_copy(beg, mid, end, dest); // 围绕 mid 指向的元素进行元素转动。元素 mid 成为为首元素，随后是 mid+1 到到 end 之前的元素，再接着是 beg 到 mid 之前的元素。返回一个迭代器，指向原来在 beg 位置的元素

// 使用双向迭代器的重排算法
reverse(beg, end); // 翻转序列中的元素，返回 void
reverse_copy(beg, end, dest);; // 翻转序列中的元素，返回一个迭代器，指向拷贝到目的序列的元素的尾后位置

// 使用随机访问迭代器的重排算法
random_shuffle(beg, end); // 混洗输入序列中的元素，返回 void
random_shuffle(beg, end, rand); // 混洗输入序列中的元素，rand 接受一个正整数的随机对象，返回 void
shuffle(beg, end, Uniform_rand); // 混洗输入序列中的元素，Uniform_rand 必须满足均匀分布随机数生成器的要求，返回 void

// 最小值和最大值，使用 < 运算符或给定的比较操作 comp 进行比较
min(val1, va12); // 返回 val1 和 val2 中的最小值，两个实参的类型必须完全一致。参数和返回类型都是 const的引引用，意味着对象不会被拷贝。下略
min(val1, val2, comp);
min(init_list);
min(init_list, comp);
max(val1, val2);
max(val1, val2, comp);
max(init_list);
max(init_list, comp);
minmax(val1, val2); // 返回一个 pair，其 first 成员为提供的值中的较小者，second 成员为较大者。下略
minmax(vall, val2, comp);
minmax(init_list);
minmax(init_list, comp);
min_element(beg, end); // 返回指向输入序列中最小元素的迭代器
min_element(beg, end, comp); // 返回指向输入序列中最小元素的迭代器
max_element(beg, end); // 返回指向输入序列中最大元素的迭代器
max_element(beg, end, comp); // 返回指向输入序列中最大元素的迭代器
minmax_element(beg, end); // 返回一个 pair，其中 first 成员为最小元素，second 成员为最大元素
minmax_element(beg, end, comp); // 返回一个 pair，其中 first 成员为最小元素，second 成员为最大元素

// 字典序比较，根据第一对不相等的元素的相对大小来返回结果。如果第一个序列在字典序中小于第二个序列，则返回 true。否则，返回 fa1se。如果个序列比另一个短，且所有元素都与较长序列的对应元素相等，则较短序列在字典序中更小。如果序列长度相等，且对应元素都相等，则在字典序中任何一个都不大于另外一个。
lexicographical_compare(beg1, end1, beg2, end2);
lexicographical_compare(beg1, end1, beg2, end2, comp);
*/