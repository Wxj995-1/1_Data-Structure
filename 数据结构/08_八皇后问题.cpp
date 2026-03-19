#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#if 0
int cnt = 0;
bool judge(int ar[], int i)   //i表示当前放置皇后棋子的位置
{
	for (int j = 0; j < i;++j)
	{
		if (i == j || ar[i] == ar[j] || abs(i - j) == abs(ar[i] - ar[j]))
		{
			return false;
		}
	}
	return true;
}


void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

}


void func(int ar[], int i, int length)
{
	if (i == length)
	{
		cnt++;
		for (int j = 0;j < length;++j)
		{
			cout << ar[j] << " ";
		}
		cout << endl;
	}
	else
	{
		for (int k = i;k < length; ++k)
		{
			swap(ar,i, k);
			if (judge(ar, i))   //判断第i个位置的元素 是否满足8皇后的条件
				func(ar, i + 1, length);   //生成孩子几点
			swap(ar,i, k);
		}

	}

}




int main()
{
	int ar[] = { 1,2,3,4,5,6,7,8 };
	int n = 8;
	func(ar, 0, n);
	cout << "cnt:" << cnt << endl;

	return 0;
}

#endif