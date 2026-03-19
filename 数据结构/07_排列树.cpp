#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
解空间 排列数
*/

#if 0
void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;

}


void func(int arr[], int i, int length)
{
	if (i == length)
	{
		// 普通for循环遍历
		for (int idx = 0; idx < length; ++idx)
		{
			cout << arr[idx] << " ";
		}
		cout << endl;
	}
	else
	{
		//生成i节点的所有孩子节点
		for (int k = i;k < length;++k)
		{
			//i k 交换
			swap(arr,i, k);
			func(arr, i + 1, length);
			swap(arr, i, k);
		}
	}

}


int main()
{
	int arr[] = { 1,2,3,4 };
	int length = sizeof(arr) / sizeof(arr[0]);

	func(arr,0,length);
	return 0;
}

#endif