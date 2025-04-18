/*STL
* STL����ɣ�
1.containers(����)
����ͨ��������ȡ�����ݴ洢�ռ䣻
���������������ݽṹ����vector��queue��deque, set, map������������ݡ�
��Ϊ����ʽ�����͹���ʽ������ʵ�ֵĽǶ�������һ����ģ�塣

2.algorithms(�㷨)
�㷨ͨ����������ȡ�������ݣ�
�㷨�������ֳ��õ��㷨����sort, search��ʵ�ֵĽǶ�������һ�ַ���ģ��

3.interators(������)
��ʵ�ֵĽǶ���������������һ�ֽ�operator, operator->,operator++,operator-��
ָ����ز����������ص���ģ�壬���е�STL���������Լ��ĵ�������

4.functors(�º���)
�º�������Э���㷨��ɲ�ͬ�Ĳ��Ա仯
��ʵ�ֵĽǶ��������º�����һ��������operator()���������ģ�塣���԰����㷨ʵ�ֲ�ͬ�Ĳ��ԡ�

5.adapters(�����)
���������Ӧ�����������º����͵�����
һ�����������������߷º�����������ӿڵĶ�����

6.allocator(�ռ�������)
����ռ������������ʵ�ֵĽǶ���������������һ��ʵ���˶�̬�ռ����á��ռ�����ռ��ͷŵ���ģ�塣
*/

/*
* containers(����)
1.sequence containers(����ʽ����)��Ԫ�ض��ǿ����(ordered),��δ���������(sorted)
2.associattive containers(����ʽ����)
*/

/*
* �ڴ���� allocator
C++ SGI�����˫�㼶������
��һ��������: _malloc_alloc_template
�ڶ���������: _default_alloc_template
��һ��������ֱ��ʹ�� malloc()�� free() ����ڴ�ķ���ͻ��ա�
�ڶ���������������������Ĵ�Сѡ��ͬ�Ĳ���ִ�С�
���ڵڶ��������������������С���� 128bytes����ֱ��ת�����õ�һ����������ʹ�� malloc()�����ڴ档
���������СС�� 128 bytes���ڶ�����������ά���� 16 �������������� 16 ��С������Ĵ�����������
������С�� 128bytes �������Ҫ��ʱ�����Ȳ鿴����������С����Ӧ���������Ƿ��п��пռ䣬�������ֱ�ӷ��أ�
���û�У������ڴ������������������С���ڴ�ռ䣬�������ɹ���������뵽���������С�
����ڴ����û�пռ䣬��ʹ�� malloc() �Ӷ��н������룬�����뵽�Ĵ�С���������Ķ������������n ����������һ���������ɿռ��У�һ������һ����n�������ڴ���С�
��� malloc()Ҳʧ�ܣ����������ɿռ������Ĵ�Ѱ�ҡ�����δ�����飬�����鹻�󡱵� freelist���ҵ�һ ����ڳ�һ�齻����
�������û�У��Խ��� malloc()������Ϊ malloc()�� out-of-memory ������ƻ����л����ͷ��������ڴ������ã�������Ծͳɹ��� ������оͱ� bad_alloc �쳣��
*/

/*
* ������traits
traits��ȡ������������
value_type, difference_type, pointer, reference, iteratior_category
�Լ�������������Ҫ���Լ��ĵ�������Ҫ�̳�����������ֵ� typedef���������Լ��Ķ�����ԭ����һЩ�㷨�����ݡ�
��������������ͣ�
InputIterator(���������)
OutputIterator(�����������
ForwardIterator��ǰ���������
BidirectionalIterator��˫���������
RandomAccessIterator�������������
����������Ϊ������������Ϊ���㷨�и��� traits ��ȡ���Ĳ�ͬ���������ͣ��ڲ�����д�����Ӹ�Ч���ʵ�ʵ�ֹ��ܵĴ��롣
iterator_traits ������һ����ȡ��������Ҫʲô�������㶪�������ȡ�����������ظ�����Ҫ�Ķ�����
��ȡiterator�����ԣ�ΪʲôҪ������ƣ���Ϊ�㷨Ҫ֪���������㷨�� iterator ��������⣡Ҳ����˵�㷨ͨ���º������������������Ԫ�أ�

*/

/*
* array
array�ǹ̶���С��˳�����������Ǳ�����һ�����ϸ������˳�����е��ض�Ԫ��������Ԫ�ء�
���ڲ���һ�������������������Ԫ��(�����������Ĵ�С������һ��ģ��������ڱ���ʱ�ǹ̶���)
���ⲻ�����κ����ݡ��洢��С�������������﷨([])��������ͨ����һ����Ч�������ֻ��������һ���Ա����
��ȫ�ֺ������������������Ϊ��׼����ʹ�á�
��������׼������ͬ��������й̶��Ĵ�С�����Ҳ�ͨ��������������Ԫ�صķ��䣺�����Ƿ�װ�̶���С����Ԫ��
�ľۺ����͡���ˣ����ǲ��ܶ�̬���������С��
���С����������Ч�ģ��������ǲ�Ӧ�ñ��������(��Ա��ǰ�棬���������)��
���׼����������������ͬ��������������������һ�����Բ��������漰����������Χ�ڵ�����Ԫ�أ���ͨ����
�൱��Ч�Ĳ�������һ���棬����������������������е�Ԫ�ر�����ԭʼ����������
������������һ���������������ǿ��Ա�����Ԫ�����������array��ͷ������get��������������Ԫ�أ�
��������һ��Ԫ�飬�Լ�ר�ŵ�tuple_size��tuple_element���͡�
template <class T, size_t N> class array
*/

/*
* array::begin
����ָ�����������е�һ��Ԫ�صĵ�����
iterator begin() noexcept;
const_iterator begin() const noexcept;
*/

/*
* array::end
����ָ���������������һ��Ԫ��֮�������Ԫ�صĵ�������
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
����ָ���������������һ��Ԫ�صķ��������
reverse_iterator rbegin() noexcept;
const_reverse_iterator rbegin() const noexcept;
*/

/*
* array::rend
����һ�������������ָ�������е�һ��Ԫ��֮ǰ������Ԫ�أ��ⱻ��Ϊ�����ķ��������
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
����ָ�����������е�һ��Ԫ�صĳ���������(const_iterator);����������������Ӻͼ��٣�
���ǲ��������޸���ָ������ݡ�
const_iterator cbegin() const noexcept;
*/

/*
* array::cend
����ָ���������������һ��Ԫ��֮�������Ԫ�صĳ���������(const_iterator)�����������
�������Ӻͼ��٣����ǲ��������޸���ָ������ݡ�
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
����ָ���������������һ��Ԫ�صĳ������������(const_reverse_iterator)
const_reverse_iterator crbegin() const noexcept;
*/

/*
* array::crend
����ָ�������е�һ��Ԫ��֮ǰ������Ԫ�صĳ������������(const_reverse_iterator),
������Ϊ���䷴�������
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
��������������Ԫ�ص�����
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
�����������������ɵ����Ԫ��������������max_size����sizeһ����
ʼ�յ�������ʵ��������ģ����ĵڶ�������ģ�塣
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
����һ������ֵ��ָʾ���������Ƿ�Ϊ�գ�������size()�Ƿ�Ϊ0��
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
���������е�n��λ�õ�Ԫ�ص����á���array::at���ƣ���array::at��������߽�
��ͨ���׳�һ��out_of_range�쳣���ж�n�Ƿ񳬳���Χ����array::operator[]�����߽硣
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
���������е�n��λ�õ�Ԫ�ص����á���array::operator[]���ƣ���array::at����
����߽粢ͨ���׳�һ��out_of_range�쳣���ж�n�Ƿ񳬳���Χ��
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
���ض����������е�һ��Ԫ�ص����á�array::begin���ص��ǵ�������array::front���ص���ֱ������
�ڿ������ϵ��ô˺����ᵼ��δ�������Ϊ
reference front();
const_reference front() const;
*/

/*
* array::back
���ض��������������һ��Ԫ�ص����á�array::end���ص��ǵ�������array::back���ص���ֱ������
�ڿ������ϵ��ô˺����ᵼ��δ�������Ϊ��
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
//	for (int& x : myarray)//***x��myarray��Χ�ڵ�����***
//	{
//		cout << ' ' << x;
//	}
//	cout << endl;
//	return 0;
//}

/*
* array::data
����ָ����������е�һ��Ԫ�ص�ָ��
���������е�Ԫ�ش洢�������Ĵ洢λ�ã����Լ�������ָ�����ƫ���Է��������е��κ�Ԫ��
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
��val�����������Ԫ�أ���val����Ϊ�������������Ԫ�ص�ֵ��
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
ͨ��x�����ݽ�����������ݣ�������һ����ͬ���͵�������󣨰�����ͬ�Ĵ�С����
�����������Ľ�����Ա������ͬ���˳�Ա����ͨ���ڸ���Ԫ��֮��ִ����������С��ͬ��
��������������������ʱ�����С�
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
���磺std::get<0>(myarray);����һ����������������ָ��λ��Ԫ�ص����á�
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
���磺 arrayA != arrayB�� arrayA > arrayB;
���αȽ�����ÿ��Ԫ�ش�С��ϵ
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
vector�Ǳ�ʾ���Ըı��С���������������
��������һ����vectorΪ���ǵ�Ԫ��ʹ����ϵ�Ĵ洢λ�ã�����ζ�����ǵ�Ԫ��Ҳ����ʹ�õ���Ԫ�صĳ���ָ���ϵ�ƫ�������ʣ�
���Һ�����һ����Ч�����������鲻ͬ���ǣ����ǵĴ�С���Զ�̬�ظı䣬���ǵĴ洢�������Զ�����

���ڲ���vectorʹ��һ����̬������������洢���ǵ�Ԫ�ء�������������Ҫ���·��䣬�Ա��ڲ�����Ԫ��ʱ���Ӵ�С��
����ζ�ŷ���һ�������鲢������Ԫ���ƶ������С��ʹ���ʱ����ԣ�����һ����԰����������Ϊÿ�ν�Ԫ����ӵ�����ʱʸ�����������·��䡣

�෴��vector�������Է���һЩ����Ĵ洢����Ӧ���ܵ���������������������Ծ��б��ϸ���Ҫ������Ԫ�صĴ洢�ռ�����ʵ��������
�����ʵ�ֲ�ͬ�Ĳ��Ե��������ڴ�ʹ�ú����·���֮���ƽ�⣬�����κ�����£��ٷ���Ӧ���ڶ��������ļ�������ߴ磬
ʹ�������������ĩ�˸���Ԫ���Ĳ���������ṩ���ڳ���ʱ�临���ԡ�

��ˣ���������ȣ��������ĸ�����ڴ�����������洢������Ч��ʽ��̬������������

��������̬����������deques, lists, forward_lists)��ȣ�vector�ǳ���Ч�ط�����Ԫ�أ���������һ��),�������Ч�ش�Ԫ��ĩβ��ӻ�ɾ��Ԫ�ء�
�����漰������Ƴ����˽�β֮���λ�õ�Ԫ�صĲ���������ִ�б�����λ�ø���Ĳ��������Ҿ��б��б��forward_lists����һ�µĵ����������ã�

���vector�ĸ��ֳ���������ʱ�临�Ӷȣ�
*�������-O(1)
*��β����ɾԪ��-ƽ̯��amortized��-O(1)
*��ɾԪ��-��vectorβ�������Ծ���O(n)

template <class T, class Alloc = allocator<T> > class vector;
*/

/*
* vector::vector
1.empty�������캯����Ĭ�Ϲ��캯����
����һ���յ�������û��Ԫ��
2.fill���캯��
��n��Ԫ�ع���һ��������ÿ��Ԫ�ض���val�ĸ���
3.��Χ��range��������
ʹ����[range, first, last]��Χ����Ӧ��Ԫ�ع������
4.����(copy)���캯�������÷��������ƣ�
������ͬ��˳����һ������x��ÿ��Ԫ�صĸ���������
5.�ƶ���move)���캯�����ͷ������ƶ���
����һ����ȡxԪ�ص����������ָ����alloc������x�ķ�������ͬ����ôԪ�ؽ����ƶ���
����û�й���Ԫ�أ����ǵ�����Ȩֱ��ת�ƣ���x����δָ������Ч��״̬��
6.��ʼ���б��캯��
����һ�������е�ÿ��Ԫ���е�һ��������IL������ͬ��˳��
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
�������������⽫��ÿ��������Ԫ���ϵ���allocator_traits::destroy,��ʹ����������ͷ���ʸ����������д洢������
~vector();
*/

/*
* vector::operator=
�������ݷ�����������滻�䵱ǰ���ݣ�����Ӧ���޸����С��
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
����vector��Ԫ�ص�����
����vector�б����ʵ�ʶ������������һ��������洢������
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
���ظ�vector�����ɵ�Ԫ�ص����������
������֪��ϵͳ���ʵ�����ƣ������������Դﵽ�����Ǳ�ڴ�С��
�������޷���֤�ܹ��ﵽ�ô�С���ڴﵽ�ô�С֮ǰ���κ�ʱ�䣬��Ȼ�޷�����洢��
size_type max_size() const noexcept;
*/

/*
* vector::capacity
���ص�ǰΪvector����Ĵ洢�ռ�Ĵ�С����Ԫ�ر�ʾ��
���capacity��һ������vector��size����������Ȼ���󣬶���Ŀռ�������Ӧ������
������Ҫ���·���ÿ�����롣
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
���������Ĵ�С��ʹ�����n��Ԫ�ء�
���nС�ڵ�ǰ������size�����ݽ�����С��ǰn��Ԫ�أ�������ɾ�������������ǣ�
���n���ڵ�ǰ����size����ͨ����ĩβ���뾡���ܶ��Ԫ���Դﵽ��Сn����չ���ݡ����ָ����val,
����Ԫ�ؽ���ʼ��Ϊval�ĸ��������򽫽���ֵ��ʼ����
���nҲ���ڵ�ǰ��������capacity������Ĵ洢�ռ佫�Զ����·��䡣
ע���������ͨ���������ɾ��Ԫ�ص��������ı�������ʵ�����ݣ�
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
����vector�Ƿ�Ϊ�գ�������size�Ƿ�Ϊ0��
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
//	int sum(0);//***��ʼ���б�***
//	//�б��ʼ���������ͼ�������ת���Ĺ��ܡ������ʼ���б��е�ֵ���Ͳ�ƥ��
//	//�����޷�������ʽ����ת�������������ᱨ��
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
����vector�����������԰���n��Ԫ�أ�
���n���ڵ�ǰvector��������ú���ʹ�������·�����洢�������Ӷ�������������n�����
��������������£��������ò��ᵼ�����·��䣬����vector��������Ӱ�졣
���������vector��Сû��Ӱ�죬Ҳ���ܸı�����Ԫ�ء�
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
//	//size_type ��string���ͺ�vector���Ͷ�������ͣ����Ա�������string����
//	//��vector����ĳ��ȣ���׼�����ͽ�size_type����Ϊunsigned���͡�
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
Ҫ������������capacity����Ӧ��ߴ硣
�������Ƿǰ󶨵ģ���������ʵ�ֿ������ɵؽ����Ż���������capacity������size��vector��
����ܵ������·��䣬����ʸ���Ĵ�Сû��Ӱ�죬���Ҳ��ܸı���Ԫ�ء�
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
�������ݷ����vector���滻�䵱ǰ���ݣ�����Ӧ���޸����С��
�ڷ�Χ�汾��1���У��������Ǵӵ�һ�������һ����Χ�ڵ�ÿ��Ԫ�ذ���ͬ˳�����Ԫ�ء�
�ڳ���汾��2���У���������n��Ԫ�أ�ÿ��Ԫ�ض�����ʼ��Ϊһ��val�ĸ�����
�ڳ�ʼ���б�汾��3���У�������������ͬ˳����Ϊ��ʼ���б��ݵ�ֵ�ĸ���
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
��vector�����һ��Ԫ��֮�����һ����Ԫ�ء�val�����ݱ����ƣ����ƶ������µ�Ԫ��
����Ч�ؽ�����size������һ��������µ�ʸ��size�����˵�ǰvector��capacity��
����������Ĵ洢�ռ��Զ����·��䡣
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
ɾ��vector�е����һ��Ԫ�أ���Ч�ؽ�����size����һ����
���ƻ���ɾ����Ԫ��
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
ͨ����ָ��λ�õ�Ԫ��֮ǰ������Ԫ������չ��vector��ͨ������Ԫ�ص�������Ч������������С��
��ᵼ�·���Ĵ洢�ռ��Զ����·��䣬ֻ�����µ�vector��size������ǰ��vector��capacity������¡�
����vectorʹ��������Ϊ������洢����˳��˽�Ԫ�ز��뵽vectorĩβ֮�󣬻���vector��begin֮ǰ��
����λ�ûᵼ���������¶�λλ��֮�������Ԫ�ص����ǵ���λ�á������������������������list��forward_list)
ִ����ͬ������ȣ���ͨ���ǵ�Ч�Ĳ�����
single element(1)
iterator insert(const_iterator position, const value_type& val);
fill(2)
iterator insert(const_iterator position, size_type n, const value_type& val);
range(3)
template<calss InputIterator>
iterator insert (const_iterator position, InputIterator first, InputIterator last);
move(4)
iterator insert(const_iterator position, value_type& val);
initializer list(5��
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

//һ�ֵ���insert������Ұָ��Ĵ���
/*
int main()
{
	vector<int> v(5, 0);
	vector<int>::iterator vi;

	vi = v.begin();
	v.push_back(10);//��ᵼ�µ�size > capacity ʱ��vector�����Զ�����
	//��������vector�����ƾ�vector����ᵼ��ԭ�������ĵ�����ʧЧ��
	v.insert(vi, 2, 300);
	return 0;
}
*/

/*
* vector::erase
��vector��ɾ������Ԫ�أ�position����һϵ��Ԫ�أ�[first, last]����
����Ч�ؼ����˱�ȥ��Ԫ�ص��������Ӷ��ƻ��������Ĵ�С��
����vectorʹ��һ��������Ϊ��ײ�洢������ɾ��vector����λ��֮�󣬻�vector��begin֮ǰ��Ԫ���⣬
�������������α������������Ԫ�����¶�λ���µ�λ�á������������������������list��forward_list��
ִ����ͬ�����Ĳ�����ȣ���ͨ���ǵ�Ч�Ĳ�����
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
ͨ��x�����ݽ�����Ա�����ݣ�x����һ����ͬ���͵�vector���󡣳ߴ���ܲ�ͬ��
�ڵ��������Ա����֮����������е�Ԫ������Щ�ڵ���֮ǰ��x�е�Ԫ�أ���x��Ԫ���������Ԫ���е�Ԫ��
���е����������ú�ָ��Խ������󱣳���Ч��
��ע�⣬�ǳ�Ա�������ھ�����ͬ���ƵĽ�������ʹ����˳�Ա�������Ƶ��Ż������ظ��㷨��
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
��vector��ɾ������Ԫ�أ������٣�������sizeΪ0��������
����֤���·��䣬�������ڵ��ô˺�����vector��capacity����֤�����仯��
ǿ�����·���ĵ������������ʹ��swap  vector<T>().swap(x);
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
ͨ����positionλ�ô�������Ԫ��args����չ������
�����Ԫ������args��Ϊ�����Ĳ����������ġ�
����Ч��������һ�������Ĵ�С��
����洢�ռ���Զ����·��䷢�����µ�vector��size������ǰvector����������¡�
����vectorʹ��������Ϊ������洢����˳��˽�Ԫ�ز��뵽vectorĩβ֮�󣬻�vector��begin֮ǰ��
����λ�ûᵼ���������¶�λλ��֮�������Ԫ�ص����ǵ���λ�á��������������������ִ����ͬ�����Ĳ�����ȣ���ͨ���ǵ�Ч�Ĳ�����
��Ԫ����ͨ������allocator_traits::construct��ת��args�������ġ�����һ�����Ƶĳ�Ա�����������ж����ƻ��ƶ��������С�
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
��vector��ĩβ����һ���µ�Ԫ�أ������ڵ�ǰ�����һ��Ԫ��֮�������Ԫ������args��Ϊ
���캯���Ĳ���������ġ�
����Ч�ؽ�������С������һ��������µ�vector��С�����˵�ǰ��vector����������������Ĵ洢�ռ��Զ����·��䡣
��Ԫ����ͨ������allocator_traits::construct��ת��args�������ġ�
��push_back��ȣ�emplace_back���Ա��������ƶ��͸��Ʋ�����
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
������vector�����Ĺ���������ĸ���
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
* deallocate��destory�Ĺ�ϵ
deallocateʵ�ֵ�Դ�룺
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
destory����������͵�����������������Ӧ�ڴ��ϵ����ݣ������ٺ��ڴ��ַ�Ա�����

deallocate�����ͷ��ڴ棨��ʱ��Ӧ�ڴ��е�ֵ�ڴ�֮ǰӦ����destory���٣����ڴ��ַ���ظ�ϵͳ�������ⲿ�ֵ�ַʹ������-1��
*/

/*
relation operators(vector)

swap(vector)

vector
*/


/*
* deque
deque(˫�˶���)��double-ended queue��һ����������д��
deque�Ǿ��ж�̬��С���������������������ˣ�ǰ�˻��ˣ���չ��������

�ض��Ŀ�����Բ�ͬ�ķ�ʽʵ��deques��ͨ����Ϊĳ����ʽ�Ķ�̬���顣
�������κ�����£����Ƕ�����ͨ��������ʵ�����ֱ�ӷ��ʸ���Ԫ�أ�ͨ��������Ҫ��չ�������������Զ�����洢��

��ˣ������ṩ��������vector�Ĺ��ܣ����������еĿ�ʼ����Ҳ���Ը�Ч�ز����ɾ��Ԫ�أ�
�����������ڽ�β�����ǣ���vector��ͬ��deques������֤��������Ԫ�ش洢�������Ĵ洢λ�ã�
dequeͨ��ƫ��ָ����һ��Ԫ�ص�ָ�����Ԫ�ػᵼ��δ�������Ϊ��

����vector��deques�ṩ��һ���ǳ����ƵĽӿڣ������������Ƶ�Ŀ�ģ����ڲ��Ĺ�����ʽ��ȫ��ͬ��
��Ȼvectorʹ�õ���������Ҫż�����·���������������deque��Ԫ�ؿ��Է�ɢ�ڲ�ͬ�Ŀ��������
�������ڲ������Ҫ����Ϣ���ṩ�����κ�Ԫ�صĳ���ʱ���ͳһ��˳��ӿڣ�ͨ������������ֱ�ӷ��ʡ�
��ˣ�deques���ڲ���vector������һ�㣬������ʹ��������ĳЩ����¸���Ч�������������������·����ø��Ӱ���ĺܳ����е�����¡�

����Ƶ���������ɾ����ʼ�����λ�������Ԫ�صĲ�����deque���ֵĸ���������б��ת���б���ȣ������������õ�һ���Ը��͡�

deque�ϳ��������ĸ����ԣ�Ч�ʣ����£�
�������-O(1)
�ڽ�β��ͷ������Ƴ�Ԫ��-O(1)
������Ƴ�Ԫ��-O(n)
template<class T, class Alloc = allocator<T>> calss deque;
*/

/*
* deque::deque
����һ��deque�������󣬸�����ʹ�õĹ��캯���汾��ʼ����������
*/

//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int main()
//{
//	unsigned int i;
//	//deque�ļ��ֹ��췽ʽ
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
�ڵ�ǰ�����һ��Ԫ��֮����deque������ĩβ���һ����Ԫ�ء�
val���ݱ����ƣ����ƶ������µ�Ԫ�ء�
����Ч��������һ�������Ĵ�С
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
��deque�����Ŀ�ʼλ�ò���һ���µ�Ԫ�أ�λ�ڵ�ǰ�ĵ�һ��Ԫ��֮ǰ��
val�����ݱ����ƣ����ƶ����������Ԫ��
����Ч��������һ�������Ĵ�С
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
ɾ��deque�����е����һ��Ԫ�أ���Ч�ؽ�������С����һ����
���ƻ��˱�ɾ����Ԫ��
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
ɾ��deque�����еĵ�һ��Ԫ�أ���Ч�ؼ�С���С��
���ƻ��˱�ɾ����Ԫ��
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
��deque��ĩβ����һ���µ�Ԫ�أ������ڵ�ǰ�����һ��Ԫ��֮������µ�Ԫ�ص���args��Ϊ�����Ĳ����������ġ�
����Ч��������һ�������Ĵ�С��
��Ԫ����ͨ������allocator_traits::construct��ת��args�������ġ�
����һ�����Ƶĳ�Ա����push_back�������Խ����еĶ����ƻ��ƶ��������С�
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
forward_list���������������������������������е��κεط����к㶨��ʱ�����Ͳ���������

forward_list������������ʵ��Ϊ��������������Խ����ǰ�����ÿ��Ԫ�ش洢�ڲ�ͬ�Ͳ���صĴ洢λ���С�
ͨ����������������һ��Ԫ�ص����ӵ�ÿ��Ԫ������������

forward_list�������б�֮�����Ҫ������������ǵ�һ���ڲ�ֻ����һ������һ��Ԫ�ص����ӣ�
������ÿ��Ԫ�ر����������ӣ�һ��ָ����һ��Ԫ�أ�һ��ָ��ǰһ��Ԫ�أ����������������ϵ���Ч����������ÿ��Ԫ�����Ķ���Ĵ洢�ռ䲢��
������Ƴ�Ԫ����ʱ�俪���Ըߡ���ˣ�forward_list������б����Ч�ʣ���������ֻ����ǰ������

�����������ı�׼����������array, vector��deque����forward_listͨ���ڲ��롢��ȡ���ƶ��������κ�λ�õ�Ԫ�ط���Ч�����á�
���Ҳ�������ܼ�ʹ����ЩԪ�ص��㷨���������㷨��

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
����ָ�������е�һ��Ԫ��֮ǰ��λ�õĵ�����
���صĵ�������Ӧ��������ã�����Ϊ��������Ա�����Ĳ���
emplace_after, insert_after,erase_after,��splice_after��ָ�����У�����ִ�иö�����λ�õĿ�ʼλ��
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
����ָ�������еĵ�һ��Ԫ��֮ǰ��λ�õ�const_iterator
һ����������ָ���������ĵ�����������������������Ӻͼ��٣�����������Ҳ��const��
����forward_list::before_begin���صĵ�����һ���������������޸���ָ�������
���ص�ֵ���ܽ����á�
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
map�ǹ��������������ض�˳��洢��key value����ֵ����mapped value��ӳ��ֵ������γɵ�Ԫ��

��ӳ���У���ֵͨ�����ڶ�Ԫ�ؽ��������Ψһ��ʶ����ӳ��ֵ�Ĵ洢��˼����������ݡ�
�����͵ļ���ӳ���ֵ���ܲ�ͬ�������ڲ������ͱ�������һ��VALUE_TYPE������һ�ֶ����ͽ��
typedef pair<const Key, T> value_type;

���ڲ���ӳ���е�Ԫ�����ǰ��������ڲ��Ƚ϶��󣨱Ƚ����ͣ�ָʾ���ض����ϸ��������׼��������
ӳ������ͨ����unordered_map����������ͨ�����ǵļ������ʸ���Ԫ�أ�������������������ǵ�˳����Ӽ�����ֱ�ӵ�����
�ڸ�ӳ��ֵ��ͼ����ֱ��ͨ��ʹ������Ӧ�ļ����������������([])��

template<class Key,
		 class T,
		 class Compare = less<key>
		 class Alloc = allocator<pair<const Key, T> >
		 >class map;
*/

/*
* map::map
����һ��ӳ���������󣬸�����ʹ�õĹ������汾��ʼ�������ݣ�
��1�����������캯����Ĭ�Ϲ��캯����

����һ���յ�������û��Ԫ�ء�

��2����Χ���캯��

�������һ�����Ԫ�صķ�Χ�ڵ�����[��һ�����һ����������ÿ��Ԫ�����蹹��Ĵ��ڸ÷�Χ��������Ӧ��Ԫ����

��3�����ƹ��캯�������÷��������ƣ�

ʹ��x�е�ÿ��Ԫ�صĸ�������һ��������

��4���ƶ����캯�������������һ���ƶ���

����һ����ȡxԪ�ص������� ���ָ����alloc������x�ķ�������ͬ����ôԪ�ؽ����ƶ�������û�й���Ԫ�أ����ǵ�����Ȩֱ��ת�ƣ��� x����δָ������Ч��״̬��

��5����ʼ���б��캯��

��il�е�ÿ��Ԫ�صĸ�������һ��������

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
��������map�����е�һ��Ԫ�صĵ�����
����map����ʼ�ձ�����Ԫ�ص�˳�����Կ�ʼָ����ѭ���������׼��Ԫ�ء�
��������ǿյģ��򷵻صĵ�������Ӧ��������á�
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
�����������ڱȽϼ��ıȽ϶���ĸ���
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
���ؿ����ڱȽ�����Ԫ�صıȽ϶����Ի�ȡ��һ��Ԫ�صļ��Ƿ��ڵڶ���Ԫ��֮ǰ
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
���������������е���k�ļ���Ԫ�أ�����ҵ��򷵻�һ�������������򷵻�map::end�ĵ�����
��������ıȽ϶����Է��ط��ؼ٣�������Ԫ����Ϊ�������ݵ�˳�򣩣�������key����Ϊ�ǵ�ͬ�ġ�
��һ����Ա����map::count�����������һ���ض��ļ��Ƿ���ڡ�
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
���������������е���k�ļ���Ԫ�أ�������ƥ���������
����map�����е�����Ԫ�ض���Ψһ�ģ���˸ú���ֻ�ܷ���1������ҵ�����0��δ�ҵ���
��������ıȽ϶����Է��ط��ش��󣨼������ܰ�����Ϊ�������ݵ�˳�򣩣�������������Ϊ�ǵ�ͬ�ġ�
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
�����������ص�����
����ָ�������е�һ��Ԫ�صĵ���������Ԫ�صļ�������k֮ǰ���֣��������ǵȼ۵Ļ��������
�ú���ʹ�����ڲ��Ƚ϶���key_comp����ȷ����һ�㣬�����������ص�key_comp(element_key, k)
������false�ĵ�һ��Ԫ��
���map����Ĭ�ϵıȽ�����(less)ʵ��������������һ������������һ��Ԫ�أ������С��k��
һ�����Ƶĳ�Ա����upper_bound������ͬ����Ϊ������ӳ�����һ��keyֵ����k��Ԫ�أ�
����������£�lower_bound����ָ���Ԫ�صĵ���������upper_bound����ָ����һ��Ԫ�صĵ�������

iterator lower_bound(const key_type& k);
const iterator lower_bound(const key_type& k) const;
*/

/*
* map::upper_bound
�����������ص�����
����һ��ָ�������е�һ��Ԫ�صĵ����������Ĺؼ��ֱ���Ϊ����k֮��
�ú���ʹ�����ڲ��Ƚ϶���key_comp)��ȷ����һ�㣬�����������ص�key_comp(k, element_key)
������true�ĵ�һ��Ԫ��
���map����Ĭ�ϵıȽ�����(less)ʵ��������������һ������������һ��Ԫ�أ��������k��
���Ƶĳ�Ա����lower_bound����upper_bound��ͬ����Ϊ������map����һ��Ԫ�أ����ֵ����k��
����������£�lower_bound����ָ���Ԫ�صĵ���������upper_bound����ָ����һ��Ԫ�صĵ�������
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
��ȡ��ͬԪ�صķ�Χ
���ذ������������о�����k�ȼ۵ļ���Ԫ�صķ�Χ�߽硣
����map�����е�Ԫ�ؾ���Ψһ�������Է��صķ�Χ���ֻ����һ��Ԫ�ء�
���û���ҵ�ƥ�䣬�򷵻صķ�Χ������ĳ��ȣ�������������ָ����п���ȥ��һ����Կ��
������һԪ��k�����������ڲ��Ƚ϶���key_comp)
��������ıȽ϶��󷵻�false��������������Ϊ�ǵȼ۵ġ�
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
* ����������Unordered Container��
* unordered_set
* unordered_multiset
* unordered_map
* unordered_multimap
* �����Թ�ϣ��ʵ�ֵġ�
*/

/*
* tuple
Ԫ����һ���ܹ�����Ԫ�ؼ��ϵĶ���ÿ��Ԫ�ؿ����ǲ�ͬ������
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
����һ��tuple����
���漰����������Ԫ�أ���ʼ��ȡ���ڵ��õĹ��캯����ʽ��
��1��Ĭ�ϵĹ��캯��
����һ�� Ԫ������Ԫ��ֵ��ʼ����

��2������/�ƶ����캯��
�ö���ʹ��tpl�����ݽ��г�ʼ��Ԫ��Ŀ�ġ�tpl ����ӦԪ�ر����ݸ�ÿ��Ԫ�صĹ��캯����

��3����ʽת�����캯��
ͬ�ϡ�tpl�е� �������Ͷ�����������ת��Ϊ���������Ǹ���Ԫ�ص�����Ԫ�� Ŀ�ġ�

��4����ʼ�����캯�� ��elems�е���ӦԪ�س�ʼ��ÿ��Ԫ�ء�elems ����ӦԪ�ر����ݸ�ÿ��Ԫ�صĹ��캯����

��5����ת�����캯��
�ö�����������Ӧ��pr.first�͵�Ԫ��pr.second��PR�е��������Ͷ�Ӧ��������ת��Ϊ���и���Ԫ�ص�����Ԫ�� Ŀ�ġ�

��6���������汾
������İ汾һ��������ÿ��Ԫ�ض���ʹ��allocator alloc����ġ�

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
������һ��ֵ��values�������һ����Щֵ�����ǲ�ͬ�����ͣ�T1��T2)��
ÿ��ֵ���Ա����еĳ�Ա����first��second����
pair��tuple��һ������
pair��ʵ����һ���ṹ�壬��Ҫ��������Ա������first��second
��Ϊ��ʹ��struct������class�����Կ���ֱ��ʹ��pair�ĳ�Ա������
Ӧ�ã�
���Խ���������������ϳ�һ����map<key, value>
��ĳ��������Ҫ��������ֵʱ
template<class T1, class T2> struct pair;
*/

/*
* pair::pair
����һ��pair����

���漰������������������������󣬳�ʼ�������ڵ��õĹ�������ʽ��

��1��Ĭ�ϵĹ��캯��

����һ��pair�������Ԫ��ֵ��ʼ����

��2������/�ƶ����캯��������ʽת����

�ö��󱻳�ʼ��Ϊpr������ ��Ŀ�ġ�pr����Ӧ��Ա�����ݸ�ÿ����Ա�Ĺ��캯����

��3����ʼ�����캯��

��4���ֶι���

�����Ա first �� second ��λ������Ԫ��first_args ��Ϊ�����Ĺ��캯�� first����Ԫ�� second_args ���Ĺ��캯�� second ��

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
// �򵥲����㷨��Ҫ�������������input iterator��
find(beg, end, val); // ����һ����������ָ�����������е�һ������ val ��Ԫ�أ�δ�ҵ����� end
find_if(beg, end, unaryPred); // ����һ����������ָ���һ������ unaryPred ��Ԫ�أ�δ�ҵ����� end
find_if_not(beg, end, unaryPred); // ����һ����������ָ���һ���� unaryPred Ϊ false ��Ԫ�أ�δ�ҵ����� end
count(beg, end, val); // ����һ����������ָ�� val �����˶��ٴ�
count_if(beg, end, unaryPred); // ͳ���ж��ٸ�Ԫ������ unaryPred
all_of(beg, end, unaryPred); // ����һ�� bool ֵ���ж��Ƿ�����Ԫ�ض����� unaryPred
any_of(beg, end, unaryPred); // ����һ�� bool ֵ���ж��Ƿ����⣨���ڣ�һ��Ԫ������ unaryPred
none_of(beg, end, unaryPred); // ����һ�� bool ֵ���ж��Ƿ�����Ԫ�ض������� unaryPred

// �����ظ�ֵ���㷨��������ǰ��������forward iterator��
adjacent_find(beg, end); // ����ָ���һ�������ظ�Ԫ�صĵ�������������Ԫ���򷵻� end
adjacent_find(beg, end, binaryPred); // ����ָ���һ�������ظ�Ԫ�صĵ�������������Ԫ���򷵻� end
search_n(beg, end, count, val); // ����һ�����������Ӵ�λ�ÿ�ʼ�� count �����Ԫ�أ��������򷵻� end
search_n(beg, end, count, val, binaryPred); // ����һ�����������Ӵ�λ�ÿ�ʼ�� count �����Ԫ�أ��������򷵻� end

// �����������㷨���� find_first_of��ǰ���������������������ǰ��������� �⣬��Ҫ������ǰ�������
search(beg1, end1, beg2, end2); // ���صڶ������뷶Χ�������У��ڵ�һ�����뷶Χ�е�һ�γ��ֵ�λ�ã�δ�ҵ��򷵻� end1
search(beg1, end1, beg2, end2, binaryPred); // ���صڶ������뷶Χ�������У��ڵ�һ�����뷶Χ�е�һ�γ��ֵ�λ�ã�δ�ҵ��򷵻� end1
find_first_of(beg1, end1, beg2, end2); // ����һ����������ָ��ڶ������뷶Χ������Ԫ���ڵ�һ����Χ���״γ��ֵ�λ�ã�δ�ҵ��򷵻�end1
find_first_of(beg1, end1, beg2, end2, binaryPred); // ����һ����������ָ��ڶ������뷶Χ������Ԫ���ڵ�һ����Χ���״γ��ֵ�λ�ã�δ�ҵ��򷵻�end1
find_end(beg1, end1, beg2, end2); // ���� search�������ص����һ�γ��ֵ�λ�á�����ڶ������뷶ΧΪ�գ������ڵ�һ�����뷶ΧΪ�գ������ڵ�һ�����뷶Χ��δ�ҵ������򷵻� end1
find_end(beg1, end1, beg2, end2, binaryPred); // ���� search�������ص����һ�γ��ֵ�λ�á�����ڶ������뷶ΧΪ�գ������ڵ�һ�����뷶ΧΪ�գ������ڵ�һ�����뷶Χ��δ�ҵ������򷵻� end1

// ����ֻ���㷨���������������
for_each(beg, end, unaryOp); // �����������е�ÿ��Ԫ��Ӧ�ÿɵ��ö��� unaryOp��unaryOp �ķ���ֵ������
mismatch(beg1, end1, beg2); // �Ƚ����������е�Ԫ�ء�����һ���������� pair����ʾ���������е�һ����ƥ���Ԫ��
mismatch(beg1, end1, beg2, binaryPred); // �Ƚ����������е�Ԫ�ء�����һ���������� pair����ʾ���������е�һ����ƥ���Ԫ��
equal(beg1, end1, beg2); // �Ƚ�ÿ��Ԫ�أ�ȷ�����������Ƿ���ȡ�
equal(beg1, end1, beg2, binaryPred); // �Ƚ�ÿ��Ԫ�أ�ȷ�����������Ƿ���ȡ�

// ���������㷨������ǰ���������������ʵ�������random-access iterator����Ҫ�������е�Ԫ���Ѿ�������ġ�ͨ��С���������<���� comp �Ƚϲ���ʵ�ֱȽϡ�
lower_bound(beg, end, val); // ����һ���ǵݼ����� [beg, end) �еĵ�һ�����ڵ���ֵ val ��λ�õĵ��������������򷵻� end
lower_bound(beg, end, val, comp); // ����һ���ǵݼ����� [beg, end) �еĵ�һ�����ڵ���ֵ val ��λ�õĵ��������������򷵻� end
upper_bound(beg, end, val); // ����һ���ǵݼ����� [beg, end) �е�һ������ val ��λ�õĵ��������������򷵻� end
upper_bound(beg, end, val, comp); // ����һ���ǵݼ����� [beg, end) �е�һ������ val ��λ�õĵ��������������򷵻� end
equal_range(beg, end, val); // ����һ�� pair���� first ��Ա�� lower_bound ���صĵ��������� second ��Ա�� upper_bound ���صĵ�����
binary_search(beg, end, val); // ����һ�� bool ֵ��ָ���������Ƿ�������� val ��Ԫ�ء���������ֵ x �� y���� x ��С�� y �� y Ҳ��С�� x ʱ����Ϊ������ȡ�

// ֻд�����㷨��Ҫ�������������output iterator��
fill(beg, end, val); // �� val ����ÿ��Ԫ�أ����� void
fill_n(beg, cnt, val); // �� val ���� cnt ��Ԫ�أ�����ָ��д�뵽�����������һ��Ԫ��֮��λ�õĵ�����
genetate(beg, end, Gen); // ÿ�ε��� Gen() ���ɲ�ͬ��ֵ����ÿ�����У����� void
genetate_n(beg, cnt, Gen); // ÿ�ε��� Gen() ���ɲ�ͬ��ֵ���� cnt �����У�����ָ��д�뵽�����������һ��Ԫ��֮��λ�õĵ�����

// ʹ�������������д�㷨����ȡһ���������У���ֵд�뵽һ��������У�dest����
copy(beg, end, dest); // �����뷶Χ��Ԫ�ؿ�������Ԫ�ص� dest ָ������Ŀ������
copy_if(beg, end, dest, unaryPred); // �����뷶Χ��Ԫ�ؿ������� unaryPred ��Ԫ�ص� dest ָ������Ŀ������
copy_n(beg, n, dest); // �����뷶Χ��Ԫ�ؿ���ǰ n ��Ԫ�ص� dest ָ������Ŀ������
move(beg, end, dest); // �����������е�ÿ��Ԫ�ص��� std::move�������ƶ��������� dest ��ʼʼ��������
transform(beg, end, dest, unaryOp); // ���ø���������һԪ���������������д��dest��
transform(beg, end, beg2, dest, binaryOp); // ���ø�����������Ԫ���������������д��dest��
replace_copy(beg, end, dest, old_val, new_val); // ��ÿ��Ԫ�ؿ����� dest�������� old_val �ĵ�Ԫ���滻Ϊ new_val
replace_copy_if(beg, end, dest, unaryPred, new_val); // ��ÿ��Ԫ�ؿ����� dest�������� unaryPred �ĵ�Ԫ���滻Ϊ new_val
merge(beg1, end1, beg2, end2, dest); // �����������б��붼������ģ��� < ��������ϲ��������д�뵽 dest ��
merge(beg1, end1, beg2, end2, dest, comp); // �����������б��붼������ģ�ʹ�ø����ıȽϲ�����comp�����ϲ��������д�뵽 dest ��

// ʹ��ǰ���������д�㷨��Ҫ��ǰ�������
iter_swap(iter1, iter2); // ���� iter1 �� iter2 ����ʾ��Ԫ�أ����� void
swap_ranges(beg1, end1, beg2); // �����뷶Χ������Ԫ���� beg2 ��ʼ�ĵڶ�������������Ԫ�ؽ��н��������ص�����ĵ� beg2��ָ�����һ������Ԫ��֮���λ�á�
replace(beg, end, old_val, new_val); // �� new_val �滻���� old_val ��ÿ��ƥ��Ԫ��
replace_if(beg, end, unaryPred, new_val); // �� new_val �滻���� unaryPred ��ÿ��ƥ��Ԫ��

// ʹ��˫���������д�㷨��Ҫ��˫��ѡ������bidirectional iterator��
copy_backward(beg, end, dest); // �����뷶Χ�п���Ԫ�ص�ָ��Ŀ��λ�á������ΧΪ��,�򷵻�ֵΪ dest�����򣬷���ֵ��ʾ�� *beg �п������ƶ���Ԫ�ء�
move_backward(beg, end, dest);  // �����뷶Χ���ƶ�Ԫ�ص�ָ��Ŀ��λ�á������ΧΪ��,�򷵻�ֵΪ dest������,����ֵ��ʾ�� *beg �п������ƶ���Ԫ�ء�
inplace_merge(beg, mid, end); // ��ͬһ�������е��������������кϲ�Ϊ��һ���������С�beg �� mid ��������к� mid �� end ��������б��ϲ�������д�뵽ԭ�����С�ʹ�� < �Ƚ�Ԫ�ء�
inplace_merge(beg, mid, end, comp); // ��ͬһ�������е��������������кϲ�Ϊ��һ���������С�beg �� mid ��������к� mid �� end ��������б��ϲ�������д�뵽ԭ�����С�ʹ�ø����� comp ������

// �����㷨��Ҫ��˫��ѡ������bidirectional iterator��
is_partitioned(beg, end, unaryPred); // �����������ν�� unaryPred ��Ԫ�ض��ڲ����� unarypred ��Ԫ��֮ǰ���򷵻� true��������Ϊ�գ�Ҳ���� true
partition_copy(beg, end, dest1, dest2, unaryPred); // ������ unaryPred ��Ԫ�ؿ������� dest1������������ unaryPred ��Ԫ�ؿ������� dest2������һ�������� pair���� first ��Ա��ʾ������ dest1 �ĵ�Ԫ�ص�ĩβ��second ��ʾ������ dest2 ��Ԫ�ص�ĩβ��
partitioned_point(beg, end, unaryPred); // �������б������Ѿ��� unaryPred ���ֹ��ġ���������  unaryPred �ķ�Χ��β���������������صĵ��������� end������ָ���Ԫ�ؼ�����Ԫ�ر��붼������ unaryPred
stable_partition(beg, end, unaryPred); // ʹ�� unaryPred �����������С����� unaryPred ��Ԫ�ط��������п�ʼ���������Ԫ�ط�������β��������һ����������ָ�����һ������ unaryPred ��Ԫ��֮���λ���������Ԫ�ض������� unaryPred���򷵻� beg
partition(beg, end, unaryPred); // ʹ�� unaryPred �����������С����� unaryPred ��Ԫ�ط��������п�ʼ���������Ԫ�ط�������β��������һ����������ָ�����һ������ unaryPred ��Ԫ��֮���λ���������Ԫ�ض������� unaryPred���򷵻� beg

// �����㷨��Ҫ��������ʵ�������random-access iterator��
sort(beg, end); // ����������Χ
stable_sort(beg, end); // ����������Χ���ȶ�����
sort(beg, end, comp); // ����������Χ
stable_sort(beg, end, comp); // ����������Χ���ȶ�����
is_sorted(beg, end); // ����һ�� bool ֵ��ָ���������������Ƿ�����
is_sorted(beg, end, comp); // ����һ�� bool ֵ��ָ���������������Ƿ�����
is_sorted_until(beg, end); // �����������Ж������ʼ���������У������������е�β�������
is_sorted_until(beg, end, comp); // �����������Ж������ʼ���������У������������е�β�������
partial_sort(beg, mid, end); // ���� mid-beg ��Ԫ�ء�������� mid-beg ���� 42����˺�����ֵ��С�� 42 ��Ԫ�������������ǰ 42 ��λ��
partial_sort(beg, mid, end, comp); // ���� mid-beg ��Ԫ�ء�������� mid-beg ���� 42����˺�����ֵ��С�� 42 ��Ԫ�������������ǰ 42 ��λ��
partial_sort_copy(beg, end, destBeg, destEnd); // �������뷶Χ�е�Ԫ�أ������㹻���������Ԫ�طŵ� destBeg �� destEnd ��ָʾ��������
partial_sort_copy(beg, end, destBeg, destEnd, comp); // �������뷶Χ�е�Ԫ�أ������㹻���������Ԫ�طŵ� destBeg �� destEnd ��ָʾ��������
nth_element(beg, nth, end); // nth ��һ����������ָ�����������е� n ���Ԫ�ء�nth ֮ǰ��Ԫ�ض�С�ڵ���������֮���Ԫ�ض����ڵ�����
nth_element(beg, nth, end, comp); // nth ��һ����������ָ�����������е� n ���Ԫ�ء�nth ֮ǰ��Ԫ�ض�С�ڵ���������֮���Ԫ�ض����ڵ�����

// ʹ��ǰ��������������㷨����ͨ�汾���������������ڲ�����Ԫ�أ�_copy �汾������ĺ�д�뵽ָ��Ŀ�������У������ı���������
remove(beg, end, val); // ͨ���ñ�����Ԫ�ظ���Ҫɾ����Ԫ��ʵ��ɾ�� ==val ��Ԫ�أ�����һ��ָ�����һ��ɾ��Ԫ�ص�β��λ�õĵ�����
remove_if(beg, end, unaryPred); // ͨ���ñ�����Ԫ�ظ���Ҫɾ����Ԫ��ʵ��ɾ������ unaryPred ��Ԫ�أ�����һ��ָ�����һ��ɾ��Ԫ�ص�β��λ�õĵ�����
remove_copy(beg, end, dest, val); // ͨ���ñ�����Ԫ�ظ���Ҫɾ����Ԫ��ʵ��ɾ�� ==val ��Ԫ�أ�����һ��ָ�����һ��ɾ��Ԫ�ص�β��λ�õĵ�����
remove_copy_if(beg, end, dest, unaryPred); // ͨ���ñ�����Ԫ�ظ���Ҫɾ����Ԫ��ʵ��ɾ������ unaryPred ��Ԫ�أ�����һ��ָ�����һ��ɾ��Ԫ�ص�β��λ�õĵ�����
unique(beg, end); // ͨ���Ը������ڵ��ظ�Ԫ�أ��� == ȷ���Ƿ���ͬ��ʵ���������С�����һ����������ָ���ظ�Ԫ�ص�β��λ��
unique (beg, end, binaryPred); // ͨ���Ը������ڵ��ظ�Ԫ�أ��� binaryPred ȷ���Ƿ���ͬ��ʵ���������С�����һ����������ָ���ظ�Ԫ�ص�β��λ��
unique_copy(beg, end, dest); // ͨ���Ը������ڵ��ظ�Ԫ�أ��� == ȷ���Ƿ���ͬ��ʵ���������С�����һ����������ָ���ظ�Ԫ�ص�β��λ��
unique_copy_if(beg, end, dest, binaryPred); // ͨ���Ը������ڵ��ظ�Ԫ�أ��� binaryPred ȷ���Ƿ���ͬ��ʵ���������С�����һ����������ָ���ظ�Ԫ�ص�β��λ��
rotate(beg, mid, end); // Χ�� mid ָ���Ԫ�ؽ���Ԫ��ת����Ԫ�� mid ��ΪΪ��Ԫ�أ������ mid+1 ���� end ֮ǰ��Ԫ�أ��ٽ����� beg �� mid ֮ǰ��Ԫ�ء�����һ����������ָ��ԭ���� beg λ�õ�Ԫ��
rotate_copy(beg, mid, end, dest); // Χ�� mid ָ���Ԫ�ؽ���Ԫ��ת����Ԫ�� mid ��ΪΪ��Ԫ�أ������ mid+1 ���� end ֮ǰ��Ԫ�أ��ٽ����� beg �� mid ֮ǰ��Ԫ�ء�����һ����������ָ��ԭ���� beg λ�õ�Ԫ��

// ʹ��˫��������������㷨
reverse(beg, end); // ��ת�����е�Ԫ�أ����� void
reverse_copy(beg, end, dest);; // ��ת�����е�Ԫ�أ�����һ����������ָ�򿽱���Ŀ�����е�Ԫ�ص�β��λ��

// ʹ��������ʵ������������㷨
random_shuffle(beg, end); // ��ϴ���������е�Ԫ�أ����� void
random_shuffle(beg, end, rand); // ��ϴ���������е�Ԫ�أ�rand ����һ����������������󣬷��� void
shuffle(beg, end, Uniform_rand); // ��ϴ���������е�Ԫ�أ�Uniform_rand ����������ȷֲ��������������Ҫ�󣬷��� void

// ��Сֵ�����ֵ��ʹ�� < �����������ıȽϲ��� comp ���бȽ�
min(val1, va12); // ���� val1 �� val2 �е���Сֵ������ʵ�ε����ͱ�����ȫһ�¡������ͷ������Ͷ��� const�������ã���ζ�Ŷ��󲻻ᱻ����������
min(val1, val2, comp);
min(init_list);
min(init_list, comp);
max(val1, val2);
max(val1, val2, comp);
max(init_list);
max(init_list, comp);
minmax(val1, val2); // ����һ�� pair���� first ��ԱΪ�ṩ��ֵ�еĽ�С�ߣ�second ��ԱΪ�ϴ��ߡ�����
minmax(vall, val2, comp);
minmax(init_list);
minmax(init_list, comp);
min_element(beg, end); // ����ָ��������������СԪ�صĵ�����
min_element(beg, end, comp); // ����ָ��������������СԪ�صĵ�����
max_element(beg, end); // ����ָ���������������Ԫ�صĵ�����
max_element(beg, end, comp); // ����ָ���������������Ԫ�صĵ�����
minmax_element(beg, end); // ����һ�� pair������ first ��ԱΪ��СԪ�أ�second ��ԱΪ���Ԫ��
minmax_element(beg, end, comp); // ����һ�� pair������ first ��ԱΪ��СԪ�أ�second ��ԱΪ���Ԫ��

// �ֵ���Ƚϣ����ݵ�һ�Բ���ȵ�Ԫ�ص���Դ�С�����ؽ���������һ���������ֵ�����С�ڵڶ������У��򷵻� true�����򣬷��� fa1se����������б���һ���̣�������Ԫ�ض���ϳ����еĶ�ӦԪ����ȣ���϶��������ֵ����и�С��������г�����ȣ��Ҷ�ӦԪ�ض���ȣ������ֵ������κ�һ��������������һ����
lexicographical_compare(beg1, end1, beg2, end2);
lexicographical_compare(beg1, end1, beg2, end2, comp);
*/