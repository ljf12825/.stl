#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

//shuffle
//随机打乱序列
template< class RandomIt, class URBG >
void shuffle(RandomIt first, RandomIt last, URBG&& g);
//g:随机数生成器（符合uniformRandomBitGenerator概念）

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