#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;


#if 0
//快排分割处理函数
int Partation(int arr[], int l, int r)
{
	//记录基准数
	int val = arr[l];
	while (l < r)
	{
		while (l< r && arr[r] > val)
		{
			r--;
		}
		if (l < r)
		{
			arr[l] = arr[r];
			l++;
		}
		 
		while (l < r && arr[l] < val)
		{
			l++;
		}

		if (l < r)
		{
			arr[r] = arr[l];
			r--;
		}
	}

	//l == r 的位置 放基准数的位置
	arr[l] = val;
	return l;
}



//快排递归
void QuickSort(int arr[], int begin, int end)
{
	if (begin > end)
	{
		return;
	}

	//优化一 元素小到一定数量 采用插入排序
	//if ((end - begin) <= 50)
	//{
	//	InsertSort(arr, begin, end);
	//	return;
	//}


	//在[begin,end]做一次快排分割处理
	int pos = Partation(arr, begin, end);

	//对基准数的左边和右边的序列 再分别应用快速分割处理
	QuickSort(arr,begin,pos-1);
	QuickSort(arr, pos+1, end);

}



void QuickSort(int arr[], int size)
{
	return QuickSort(arr, 0, size - 1);
}




int main()
{
	int arr[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	QuickSort(arr, 10);


	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	return 0;
}

#endif