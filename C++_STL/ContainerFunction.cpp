//construct
//array��ʽ����

//destruct
//array��ʽ����

//operator=
//array��ʽ�滻

//assign ���ԭ���ݣ������µ�Ԫ��

//begin ������Ԫ�صĵ����������Ϊ�գ�����end()

//cbegin ���ص�һ��Ԫ�ص�const_iterator

//end return past the last element iterator

//cend

//rbegin ����βԪ�صĵ����������Ϊ�գ�����rend()

//crbegin

//rend return prevent the first element iterator

//crend

//at ����λ��ָ��λ�õ�Ԫ�ص����ã��б߽��飬Խ���׳�std::out_of_range

//operator[] �ޱ߽��飬Խ��UB

//data ����ָ����ΪԪ�ش洢�����ĵײ�������Ԫ�صĵ�ַ��int* p = arr

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
//	auto a = a_2;//�˻�Ϊָ��
//	//�˻�ԭ��
//	//1.��ʷ�����ԣ���C/C++���Ե��������У����鲻�ǵ�һ�ȶ��󣬲������帳ֵ�����λ򷵻أ�����ͨ��ָ��ģ��
//	//2.Ч�ʣ���ָ��Ч�ʸ�
//	//3.�����㣬C/C++�������ָ�빲������﷨
//	//�˻�����
//	//1.��������
//	//2.���ʽ��ֵ
//	//�����˻������
//	//1.sizeof
//	//2.decltype/template��ȷ������G��
//	//3.ȡ��ַ
//	auto b = &a_2;//��������
//	auto c = &a_2[0];
//
//	std::cout << **b << std::endl;
//	return 0;
//}

//front ���ص�������Ԫ�ص����� front = *begin

//back ���ص��������һ��Ԫ�ص����� back = *std::prev(end())

//empty

//size

//max_size ������������ϵͳ���ʵ�����ƶ��ɱ��е�Ԫ�ص�����������������������

//resize �����С

//capacity ����������ǰ��Ϊ֮����ռ��Ԫ����

//reserve ����

//shrink_to_fit �����Ƴ�δʹ�õ�����

//clear

//insert ǰ�壬��ҪԤ�ȴ��������漰�����ƶ�

//insert_or_assign ����������ڣ��Ͳ���һ���µļ�ֵ�ԡ�������Ѵ��ڣ�����¸ü���Ӧ��ֵ

//emplace ǰ�壬ֱ���������ڲ�������󣬱�����⿪��
//template <class...Args>
//std::pair<iterator, bool> emplace(Args&&...args);
//iteratorָ���²����Ԫ�أ�bool��ʾ�Ƿ�ɹ�����

//emplace_hint �ڹ����������ṩһ����ʾ�����飩λ�ã�������������Ч�ز���Ԫ��

//try_emplace ���Բ�������ļ�ֵ��Ԫ�أ���������д��ڣ���ָ���Ѵ���Ԫ�ء������㲻��Ҫ���޸�

//erase 

//push_front 

//emplace_front

//pop_front

//push_back

//emplace_back

//pop_back

//swap

//merge ����һ��ͬ���͵�������Ԫ�غϲ�����ǰ�����У����������������ԣ�ͬʱ���ᶪʧ�κ�Ԫ��

//extract �����������������ȡһ��Ԫ�أ�������������Ƴ�������һ��node_type��ʾ������Ԫ�صķ�װ

//splice ��һ��list�е�Ԫ���ƶ�����һ��list�У��������ǵ�˳��ͨ��ָ����������⿽��

//remove �Ƴ�һ��Ԫ�أ������Ƴ���Ԫ��������C++20��

//remove_if �Ƴ����������ض���׼��Ԫ�أ������Ƴ�Ԫ�ص�������C++20��

//reverse ��ת

//unique �Ƴ�������������̵��ظ�Ԫ�أ�ֻ�������Ԫ�����еĵ�һ��Ԫ�ء�

//sort stable

//bucket_count ����Ͱ������

//max_bucket_count �����������Ͱ��

//bucket_size ��������Ϊn��Ͱ�е�Ԫ����

//bucket ���ؼ�key��Ͱ������

//load_factor ����ƽ��ÿͰԪ����

//max_load_factor �������������ӣ���������������

//rehash �����ײ�Ͱ������������֯�����е�Ԫ�����Ż���ϣ��ṹ

//count ����ӵ����ָ��ʵ�αȽϵȼ۵ļ���Ԫ����

//find

//contains ����������Ƿ���Ԫ�صļ�����key

//lower_bound �����׸���С��key��Ԫ�صĵ�����

//upper_bound �����׸�����key��Ԫ�صĵ�����

//equal_range ��������������ӵ�и�������Ԫ�صķ�Χ[lower_bound(key), upper_bound(key))

//key_comp �������ڱȽϼ��ĺ������󣨱Ƚ����������Ǵ��������캯��ʵ��comp�ĸ���

//value_comp ���رȽ�ֵ�ĺ������󣨱Ƚ�����

//hash_function ���ضԼ�����ɢ�еĺ���

//key_equal ���رȽϼ�����Եĺ���

//get_allocator ���ط�����