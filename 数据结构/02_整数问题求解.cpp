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
#include <stack>
#include  <cmath>
using namespace std;

/*
整数选择问题：给定一组整数 从里面挑选出一组整数 让选择的整数的和 和剩下的整数的和的差最小
*/

#if 0
int arr[] = { 12,6,7,11,16,3,9 };
const int length = sizeof(arr) / sizeof(arr[0]);
int x[length] = { 0 };   //子集数辅助数组
int bestx[length] = { 0 };  //记录最优解
unsigned int min1 = 0xffffffff;   //记录最小的差值
int sum = 0;   //记录所选子集数字的总和
int r = 0;     //记录未选择数字的和



void func(int i)
{
	if (i == length)   //访问到了子集数的一个叶子节点
	{
		int result = abs(sum - r);
		if (result < min1)
		{
			min1 = result;
			//需要记录一下差值最小的子集
			for (int j = 0; j < length; ++j)
			{
				bestx[j] = x[j]; 
			}
		}
	}
	else
	{
		r -= arr[i];
		sum += arr[i];
		x[i] = 1;
		func(i + 1);    //选择i节点
		sum -= arr[i];
		r += arr[i];


		x[i] = 0;
		func(i + 1);	//不选择i节点
	}
}


int main()
{
	for (int v : arr)
	{
		r += v;
	}

	func(0);
	
	for (int i = 0;i < length;++i)
	{
		if (bestx[i] == 1)
		{
			cout << arr[i] << " ";
		}
	}
	cout << endl;
	cout << "min:" << min1 << endl;
	return 0;
}

#endif