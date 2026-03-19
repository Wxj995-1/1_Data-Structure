#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;


#if 0
//≤Â»Î≈≈–ÚÀ„∑®
void InsertSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int val = arr[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (arr[j] <= val)
			{
				break;
			}
			arr[j + 1] = arr[j];
		}
		//val -> j +1;
		arr[j + 1] = val;

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

	InsertSort(arr, 10);


	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	return 0;
}

#endif