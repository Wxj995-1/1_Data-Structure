#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;


#if 0
int cnt = 0;
string str1 = "helloworld";
string str2 = "hlweord";
int** dp = nullptr;

int LCS01(string X, int n, string Y, int m)
{
	if (n < 0 || m < 0)
	{
		return 0;
	}

	if (dp[n][m] > 0)
	{
		return dp[n][m];
	}


	cnt++;
	
	if (X[n] == Y[m])
	{
		dp[n][m] =  LCS01(X, n - 1, Y, m - 1) + 1;
		return dp[n][m];
	}
	else {
		int len1 = LCS01(X, n, Y, m - 1);
		int len2 = LCS01(X, n - 1, Y, m);
		if (len1 >= len2)
		{
			dp[n][m] = len1;
		}
		else
		{
			dp[n][m] = len2;
		}

		return dp[n][m];
	}

}

int main()
{
	int n = str1.size();
	int m = str2.size();
	//dp是一个n行m列的二维数组
	dp = new int*[n];     //n行
	for (int i = 0;i < n;++i)
	{
		dp[i] = new int[m];    //m列
		for (int j = 0;j < m;j++)
		{
			dp[i][j] = -1;
		}
	}
	int size = LCS01(str1, n - 1, str2, m - 1);
	cout << "LCS length:" << size << endl;
	cout << "cnt:" << cnt << endl;
	return 0;
}

#endif