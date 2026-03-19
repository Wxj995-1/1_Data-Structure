#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <functional>
using namespace std;


#if 0
//堆的下沉调整
void siftDown(int arr[], int i, int size)
{
	int val = arr[i];
	//最后一个非叶子节点
	while (i < size / 2)
	{
		int child = 2 * i + 1;
		if (child + 1 < size && arr[child + 1] > arr[child])
		{
			child = child + 1;
		}
		if (arr[child] > val)
		{
			arr[i] = arr[child];
			i = child;   //i继续指向他的孩子 继续调整
		}
		else
		{
			break;
		}
	}
	arr[i] = val;
}



//堆排序
void HeadSort(int arr[], int size)
{
	int n = size - 1;
	//从第一个非叶子节点进行大根堆
	for (int i = (n - 1) / 2; i >= 0; i--)
	{
		siftDown(arr, i, size);
	}

	//把堆顶元素的和末尾元素进行交换  从堆顶开始进行下沉操作
	for(int i = n; i > 0; i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		siftDown(arr, 0, i);

	}

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

	HeadSort(arr, 10);


	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	return 0;
}

#endif