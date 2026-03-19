#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#if 0


/*
func1(5)
参数：指定个数的斐波那契数列
*/
int cnt = 0;
int fabnacci(int n,int *dp)
{
	if (dp[n] > 0)
	{
		cnt++;
		return dp[n];
	}
	if (n == 1 || n == 2)
	{
		dp[n] = 1;
		return 1;
	}
	else
	{
		dp[n] = fabnacci(n - 1, dp) + fabnacci(n - 2, dp);
		return dp[n];
	}

}

int main()
{
	/*
	int n = 10;
	int* dp = new int[n + 1]();
	int val = fabnacci(n,dp);
	cout << val << endl;
	cout << cnt << endl;
	*/


	const int  n = 10;
	int dp[n + 1] = { 0 };
	dp[1] = dp[2] = 1;
	for (int i = 3;i <= n;++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;

	return 0;
}

#endif