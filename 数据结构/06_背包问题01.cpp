#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

/*
有一组物品 重量分别为w1 w2 wn 价值分别是v1 v2 v3
现在有一个背包 容量是C 问怎么把物品装入背包 能够使背包的价值最大化
*/


#if 0
void backStrace(int* w, int* v, int n, int c, int** dp)
{
	int bestv = 0;
	for (int i = 0;i < n; ++i)
	{
		if (dp[i][c] != dp[i + 1][c])
		{
			//选择了第i个物品
			cout << w[i] << " ";
			bestv += v[i]; 
			c -= w[i];
		}
	}
	//单独处理最后一行
	if (dp[n][c] > 0)
	{
		bestv += v[n];
		cout << w[n] << " ";
	}

	cout << endl;
	cout << "背包的最大价值为:" << bestv << endl;
}
int main()
{
	int w[] = { 8,6,4,2,5 };
	int n = sizeof(w) / sizeof(w[0]) - 1;
	int v[] = { 6,4,7,8,6 };
	int c = 12;
	//定义dp数组记录子问题的解
	int** dp = nullptr;
	dp = new int* [n + 1];
	for (int i = 0;i < n + 1;++i)
	{      
		dp[i] = new int[c + 1]();
	}

	//先填写初始状态的值  填写dp二维数组的最后一行 物品n
	for (int j = 1;j <= c;j++)     
	{
		if (w[n] > j)      //第n个物品的重量大于背包剩余容量
		{
			dp[n][j] = 0;
		}
		else
		{
			//第n个物品的重量小于等于背包剩余容量
			dp[n][j] = v[n];
		}
	}

	//从n-1行开始到0行  表示所选择的物品是i,i+1,...,n
	for (int i = n - 1;i >= 0;--i)
	{
		for (int j = 1;j <= c;++j)
		{
			if (w[i] > j)
			{
				//第i个物品无法装入背包
				dp[i][j] = dp[i + 1][j];
			}
			else
			{
				dp[i][j] = std::max(dp[i + 1][j], v[i] + dp[i + 1][j - w[i]]); 
			}
		}
	}
	/*
	//打印dp数组
	for (int i = 0;i <= n;++i)
	{
		for (int j = 1;j <= c;++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/

	backStrace(w,v,c,n,dp);


	//释放dp数组的内存
	for (int i = 0;i < n;++i)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return 0;
}

#endif