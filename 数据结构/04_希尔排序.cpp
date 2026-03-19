#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Ï£¶ûÅÅÐò
void ShellSort(int arr[], int size)
{
	for (int gap = size / 2;gap > 0;gap /= 2)
	{
		for (int i = gap; i < size;i++)
		{
			int val = arr[i];
			int j = i - gap;
			for (; j >= 0; j-=gap)
			{
				if (arr[j] <= val)
				{ 
					break;
				}
				arr[j + gap] = arr[j];
			}
			arr[j + gap] =val;

		}

	}
	
}
#if 0

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

	ShellSort(arr, 10);


	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	return 0;
}

#endif