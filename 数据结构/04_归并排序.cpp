#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#if 0

//合并
void merge(vector<int>& vec, int low, int high, int mid)
{
	//定义额额外的辅助空间  存储的合并的子问题的有序数组
	vector<int> tmp;
	tmp.reserve(high - low + 1);
	int i = low;    //[low ,mid]
	int j = mid + 1;   //[mid + 1,high]

	while (i <= mid && j <= high)
	{
		if (vec[i] > vec[j])
		{
			tmp.push_back(vec[j++]);
		}
		else
		{
			tmp.push_back(vec[i++]);
		}
	}
	while (i <= mid)
	{
		tmp.push_back(vec[i++]);
	}

	while (j <= high)
	{
		tmp.push_back(vec[j++]);
	}

	for (int k = low;k <= high;++k)
	{
		vec[k] = tmp[k - low];
	}

}

//归并排序
void mergeSort(vector<int>& vec, int i, int j)
{
	if (i == j)   //子问题划分到一个元素
	{
		return;
	}
	int mid = (i + j) / 2;
	//先划分子问题 降低问题规模
	mergeSort(vec, i, mid);
	mergeSort(vec, mid+1, j);

	//向上回溯 回溯的过程中合并子问题的解
	merge(vec, i, j, mid);

}

int main()
{
	vector<int> vec;
	for (int i = 0;i < 20;++i)
	{
		vec.push_back(rand() % 100);
	}


	mergeSort(vec, 0, vec.size() - 1);
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
	return 0; 
}

#endif