#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
硬币选择问题 有 1 3 5 分面额的硬币 给定一个面值11 问组合给定面值所需要的最少得硬币的数量是多少
*/

/*
参数n表示面值 返回值表示组成面值n所需要的最少得硬币数量
*/


#if 0
const int n = 30;
int dp[n + 1] = { 0 };    //组成价值n需要的组合
int cnt = 0;

int func1(int n)
{
	if (dp[n] > 0)
	{
		cnt++;
		//dp[n]这个子问题已经被求解过了
		return dp[n];
	}
	if (n == 1 || n == 3 || n == 5)
	{
		dp[n] = 1;   //代表一个子问题最优解的状态
		return 1;
	}
	else if (n == 2 || n == 4)
	{
		dp[n] = 2;
		return 2;
	}
	else
	{
		int n1 = func1(n - 1) + 1;    //选择了1分硬币
		int n2 = func1(n - 3) + 1;    //选择了3分硬币
		int n3 = func1(n - 5) + 1;	  //选择了5分硬币
		dp[n] = std::min({ n1,n2,n3 });
		return dp[n];
	}

}


int main()
{

	int num = func1(n);
	cout << "num:" << num << endl;
	cout << "cnt:" << cnt << endl;
	return 0;
}

#endif