#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;


#if 0
//¶þ·ÖËÑË÷µÝ¹é´úÂë
int BinarySearch(int arr[], int i, int j, int val)
{
	if (i > j)
	{
		return -1;
	}
	int mid = (i + j) / 2;
	if (arr[mid] == val)
		return mid;
	else if (arr[mid] > val)
		return BinarySearch(arr, i, mid -1, val);
	else
		return BinarySearch(arr, mid + 1, j, val);
}

int BinarySearch(int arr[], int size, int val)
{
	return BinarySearch(arr, 0, size - 1, val);
	
	/*
	int first = 0;
	int last = size - 1;

	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (arr[mid] == val)
		{
			return mid;
		}
		else if (arr[mid] > val)
		{
			last = mid - 1;
		}
		else
			first = mid + 1;
	}

	return -1;
	*/
}



int main()
{
	int arr[] = { 12,15,34,39,45,57,63,78,82,96,100 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << BinarySearch(arr,size,100) << endl;

}

#endif