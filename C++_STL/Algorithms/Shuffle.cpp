#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

//shuffle
//�����������
template< class RandomIt, class URBG >
void shuffle(RandomIt first, RandomIt last, URBG&& g);
//g:�����������������uniformRandomBitGenerator���

//int main()
//{
//	std::vector<int> vec = { 1, 2, 3, 4, 5 };
//	
//	std::random_device rd;
//	std::mt19937 g(rd());
//
//	std::shuffle(vec.begin(), vec.end(), g);
//
//	for (int n : vec)
//		std::cout << n << " ";
//	
//	return 0;
//}