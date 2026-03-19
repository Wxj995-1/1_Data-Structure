#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
LIS问题：求序列的最长非降子序列的长度
*/

#if 0
int main()
{
	int ar[] = { 5,3,4,1,8,7,9 };
	const int n = sizeof(ar) / sizeof(ar[0]);
	int dp[n] = { 0 };
	int maxval = 0;
	for (int i = 0;i < n;i++)
	{
		dp[i] = 1;
		for (int j = 0;j < i;++j)
		{
			if (ar[j] < ar[i] && 1 + dp[j] > dp[i])
			{
				dp[i] = 1 + dp[j];
			}
		}

		if (dp[i] > maxval)
			maxval = dp[i];

	}


	cout << maxval << endl;

	return 0;
}

#endif