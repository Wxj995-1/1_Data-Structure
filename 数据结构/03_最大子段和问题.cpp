#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


#if 0
int main()
{
	int ar[] = { -2,11,-4,13,-5,-2 };
	
	const int n = sizeof(ar) / sizeof(ar[0]);
	int dp[n] = {0};
	dp[0] = ar[0] < 0 ? 0 : ar[0];
	int maxval = dp[0];

	for (int i = 1;i < n;i++)
	{
		dp[i] = ar[i] + dp[i - 1];
		if (dp[i] < 0)
			dp[i] = 0;
		if (dp[i] > maxval)
			maxval = dp[i];

	}

	cout << maxval << endl;
	return 0;
}

#endif