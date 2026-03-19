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
using namespace std;


#if 0

int main()
{
	//模拟问题 vector中放原始数据
	vector<int> vec;
	srand(time(NULL));

	for (int i = 0;i < 10000; i++)
	{
		vec.push_back(rand() % 10000);
	}

	//找第一个出现重复的数字
	//找所有重复出现的数字
#if 0
	unordered_set<int> s1;
	for (auto key : vec)
	{
		auto it = s1.find(key);
		if(it == s1.end())
		{
			s1.insert(key);
			break;
		}
		else
		{
			cout << "key:" << key << endl;
			break;
		}
	}
#endif


#if 0
	//统计重复数字以及出现的次数
	unordered_map<int, int> m1;
	for (int key : vec)
	{
		//auto it = m1.find(key);
		//if (it == m1.end())
		//{
		//	m1.emplace(key,1);
		//}
		//else
		//{
		//	it->second += 1;
		//}
		m1[key]++;
	}

	for (auto pair : m1)
	{
		if (pair.second > 1)
		{
			cout << "key:" << pair.first << " cnt:" << pair.second << endl;
		}
	}

#endif
	//一组数据有些数字是重复的 把重复的数字过滤掉 每个数字只出现一次

	unordered_set<int> s1;
	for (auto key : vec)
	{
		s1.emplace(key);
	}


	return 0;
}

#endif


#if 0
int main()
{
	string src = "aabbcc";

	unordered_map<int, int> m1;

	for (char ch : src)
	{
		auto it = m1.find(ch);
		if (it == m1.end())
		{
			m1.emplace(ch, 1);
		}
		else
		{
			it->second += 1;
		}
		//[ch]++;
	}

	for(char ch:src)
	{
		if (m1[ch] == 1)
		{
			cout << "第一个没有重复出现的字符是：" << ch << endl;
			return 0;
		}
	}

	cout << "所有字符都有重复出现过！" << endl;
	return 0;
}


#endif

