//������
//��һ���ڴ������Եĳ������
//�������û��Զ���STL������η�����ͷ��ڴ�
//��STL�У�ÿ�����������Խ���һ��������������Ϊģ�������Ĭ����std::allocator<T>����ʹ��::operator new �� ::operator delete��������ͷ��ڴ档
#include <iostream>
#include <new>
#include <vector>

template <class T, class Allocator = std::allocator<T>>
class vector;

//allocator������
//1.�����ڴ�ķ������ͷŷ�ʽ
//2.Ϊ�����е�Ԫ�ط���ԭʼ�ڴ棨���������
//3.ʹ��placement new���������ʾ��������
//4.�����Զ�����Ϊ�����ڴ�ء�������Ϣ�������ڴ�ȣ�

//std::allocator<T>�Ļ����ӿ�
//template<typename T>
//struct MyAllocator
//{
//	using value_type = T;
//
//	MyAllocator() = default;
//
//	template<typename U>
//	MyAllocator(const MyAllocator<U>&) {}
//
//	T* allocate(std::size_t n)
//	{
//		return static_cast<T*>(::operator new(n * sizeof(T)));
//	}
//
//	void deallocate(T* p, std::size_t)
//	{
//		::operator delete(p);
//	}
//};
//
//int main()
//{
//	std::vector<int, MyAllocator<int>> vec;
//	vec.push_back(1);
//	vec.push_back(2);
//	return 0;
//}

//struct MyClass
//{
//	MyClass(int x) { std::cout << "Constructor: " << x << "\n"; }
//	~MyClass() { std::cout << "Destructor\n"; }
//};
//
//int main()
//{
//	//����ԭʼ�ڴ�
//	auto raw = ::operator new(sizeof(MyClass));
//
//	//��ָ����ַ�Ϲ������placement new��
//	MyClass* obj = new (raw) MyClass(42);
//
//	//��ʽ����
//	obj->~MyClass();
//
//	//�ͷ��ڴ�
//	::operator delete(raw);
//	return 0;
//}

//::operator new����ʧ��Ĭ���׳�std::bad_alloc�쳣
