#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <functional>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <memory>
using namespace std;

/*
有一亿个整数 最大值不超过一亿 有哪些元素重复了 谁是第一个重复 谁是而一个不重复的
*/
#if 0
int main()
{
	vector<int> vec{ 12,78,90,123,8,9,12,78 };

	//定义位图数组  O(n)
	int max = vec[0];
	for (int i = 1;i < vec.size();i++)
	{
		if (vec[i] > max)
		{
			max = vec[i];
		}
	}
	//cout << max << endl;

	int* bitmap = new int[max / 32 + 1]();
	unique_ptr<int> ptr(bitmap);


	//找第一个重复出现的数字
	for (auto key : vec)
	{
		int index = key / 32;
		int offset = key % 32;

		//取key对应为的值
		if (0 == (bitmap[index] & (1 << offset)))
		{
			//表示key没有出现过
			bitmap[index] |= (1 << offset);
		}
		else
		{
			cout << key << "是重复出现的数字" << endl;
			//return 0;
		}


	}



	return 0;
}

#endif