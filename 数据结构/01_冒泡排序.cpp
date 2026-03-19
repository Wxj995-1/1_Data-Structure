#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;


#if 0
//冒泡排序
void BubbleSort(int arr[], int size)
{
	for (int j = 0; j < size - 1; j++)
	{
		bool flag = false;
		//一趟处理 如果没有做任何的数据交换 那么说明数据已经有序了
		for (int i = 0; i < size - 1 - j;i++)
		{
			if(arr[i] > arr [i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = true;
			}
		}
		if (!flag)
		{
			//如果没有做任何的数据交换 那么说明数据已经处理完成了
			return;
		}


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

	for(int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	BubbleSort(arr,10);


	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	return 0;
}

#endif