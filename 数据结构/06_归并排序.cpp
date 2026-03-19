#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;



#if 0
//归并过程函数
void Merge(int arr[],int l,int m,int r)
{
	int* p = new int[r - l + 1];
	int idx = 0; 
	int i = l;
	int j = m + 1;

	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			p[idx++] = arr[i++];
		}
		else
		{
			p[idx++] = arr[j++];
		}
	}

	while(i <= m)
	{
		p[idx++] = arr[i++];
	}

	while (j <= r)
	{
		p[idx++] = arr[j++];
	}

	//再把合并好的拷贝到原始数组arr中
	for (i = l, j = 0;i <= r;i++, j++)
	{
		arr[i] = p[j];
	}

	delete[] p;
}


void MergeSort(int arr[], int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	int mid = (begin + end) / 2; 
	//先递
	MergeSort(arr,begin,mid);
	MergeSort(arr, mid + 1, end);
	//再归并 [begin, mid] [mid + 1, end]把两个小段有序的序列 合并为大段

	Merge(arr,begin,mid,end);

}


void MergeSort(int arr[], int size)
{
	MergeSort(arr, 0, size - 1);
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

	MergeSort(arr, 10);


	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	return 0;
}

#endif