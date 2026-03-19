#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;


#if 0
//基数排序代码
void RadixSort(int arr[], int size)
{
	int maxData = arr[0];
	for (int i = 1;i < size;i++)
	{
		if (maxData < arr[i])
		{
			maxData = arr[i];
		}
	}

	int len = to_string(maxData).size();

	vector<vector<int>> vecs;
	int mod = 10;
	int dev = 1;

	for (int i = 0;i < len;mod *= 10, dev *= 10, i++)
	{
		vecs.resize(10);

		for (int j = 0;j < size;j++)
		{
			//得到当前元素第i个位置的数字
			int index = arr[j] % mod / dev;
			vecs[index].push_back(arr[j]);

		}
		//依次遍历所有的桶 拷贝元素复位
		int idx = 0;
		for (auto vec : vecs)
		{
			for (int v : vec)
			{
				arr[idx++] = v;
			}
		}

		vecs.clear();
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

	RadixSort(arr, 10);


	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	return 0;

}

#endif