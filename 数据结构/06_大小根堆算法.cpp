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
#include <queue>
using namespace std;


#if 0
int main()
{
	vector<int> vec;
	srand(time(NULL));
	for (int i = 0; i < 1000;i++)
	{
		vec.push_back(rand() % 10000);

	}
	//for (auto key : vec)
	//{
	//	cout << key << " ";
	//}
	//cout << endl;

	priority_queue<int> maxheap;

	int k = 5;
	//由前k个元素构建一个大根堆
	for (int i = 0;i < 5;i++)
	{
		maxheap.push(vec[i]);
	}

	//遍历剩余的元素直到最后
	for (int i = 5;i < vec.size();i++)
	{
		if (maxheap.top() > vec[i])
		{
			maxheap.pop();
			maxheap.push(vec[i]);
		}
	}

	while(!maxheap.empty())
	{
		cout << maxheap.top() << " ";
		maxheap.pop();
	}

	cout << endl;
	return 0;
}
#endif





#if 0
//查重和top k问题综合起来了
int main()
{
	vector<int> vec;
	srand(time(NULL));
	for (int i = 0; i < 10000;i++)
	{
		vec.push_back(rand() % 1000);

	}

	//统计重复次数最小的前三个数字
	unordered_map<int, int> map;
	for (auto key : vec)
	{
		auto it = map.find(key);
		if (it == map.end())
		{
			map.emplace(key,1);
		}
		else
		{
			it->second += 1;
		}
	}
	//放入大根堆的时候 需要放key-value键值对
	using Type = pair<int, int>;
	using Comp = function<bool(Type&, Type&)>;
	priority_queue<Type, vector<Type>, Comp> maxheap([](Type& a, Type& b)->bool {return a.second < b.second;});


	auto it = map.begin();
	for (int i = 0;i < 3;i++,++it)
	{
		maxheap.push(*it);
	}
	for (;it != map.end();++it)
	{
		if (maxheap.top().second > it->second)
		{
			maxheap.pop();
			maxheap.push(*it);
		}

	}

	while (!maxheap.empty())
	{
		cout << "key :" << maxheap.top().first << "cnt: " << maxheap.top().second;
		maxheap.pop();
 	}
	//统计重复次数最大的前三个数字
	return 0;
}
#endif