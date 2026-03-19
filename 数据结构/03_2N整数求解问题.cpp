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


#if 0
/*
整数选择问题：给定2N个整数 从里面挑选出N个整数 让选择的整数的和 和剩下的整数的和的差最小
*/

int arr[] = { 12,6,7,11,16,3,8,4 };
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int> x;   //记录子集中选择的元素
vector<int> bestx;  //记录最优解
int sum = 0;    //记录子集中所选数字的和
int r = 0;		//记录未选择数字的和
unsigned int min1 = 0xffffffff;   //记录最小差值
int cnt = 0;    // 记录遍历的子集的个数 用于测试
int left1 = length;   //未处理的数字的个数


void func(int i)
{
	if (i == length)
	{
		cnt++;
		if (x.size() != length / 2)
		{
			return;
		}
		
		
		//得到子集树的一个解 对应一个叶子节点
		int result = abs(sum - r);
		if (result < min1)
		{
			min1 = result;
			bestx = x;
		}
	}
	else
	{
		left1--;   //表示处理了一个节点 表示剩余的未处理的元素的个数
		if (x.size() < length / 2)    //剪左树枝 提高算法效率 选择数字的前提：还未选择够n个整数
		{
			sum += arr[i];
			r -= arr[i];
			x.push_back(arr[i]);
			func(i + 1);     //遍历i的左孩子 表示选择i号位元素
			sum -= arr[i];
			r += arr[i];
			x.pop_back();
		}

		//这里右树枝也可以剪枝 已选择的个数 + 未来能选择的所有的数字的个数 >= n个元素
		if (x.size() + left1 >= length / 2)
		{
			func(i + 1);	 //遍历i的右孩子 表示不选择i号位元素
		}

		//当前i节点已经处理完成 回溯到父亲节
		left1++;
	}
}


int main()
{
	for (int v : arr)
	{
		r += v;
	}
	func(0);

	for (int v : bestx)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << "min:" << min1 << endl;
	cout << "cnt:" << cnt << endl;
	return 0;
}

#endif