#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

#if 0
//选择排序
void ChoiceSort(int arr[],int size)
{
	for (int i = 0;i < size - 1;i++)
	{
		int min = arr[i];
		int k = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				k = j;
			}
		}

		//找到后面序列中的最小值 并进行交换
		if (k != i)
		{
			//min = min ^ arr[k];
			//arr[k] = min ^ arr[k];
			//min = min ^ arr[k];
			int tmp = arr[i];
			arr[i] = arr[k];
			arr[k] = tmp;
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

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	ChoiceSort(arr, 10);


	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	return 0;
}

#endif