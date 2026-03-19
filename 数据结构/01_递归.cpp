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
void func(int* arr, int i, int length,int *x)
{
	if (i == length)
	{
		for (int j = 0;j < length;++j)
		{
			if (x[j] == 1)
			{
				cout << arr[j] << " ";
			}
		}
		cout << endl;

	}
	else
	{
		/*
		x[i] = 1;
		func(arr, i + 1, length, x);   //遍历i的左孩子
		x[i] = 0;
		func(arr, i + 1, length, x);   //遍历i的右孩子
		*/
	
		for (inr k = 1;k >= 0;--k)
		{
			x[i] = k;
			func(arr, i + 1, length, x);
		}

	}


}



int main()
{
	int  arr[] = { 1,2,3 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int x[3] = { 0 };
	func(arr, 0, length,x);

	return 0;
}

#endif