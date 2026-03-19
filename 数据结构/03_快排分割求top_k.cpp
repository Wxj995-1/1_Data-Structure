#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#if 0
//快排划分函数
int partation(vector<int >& vec, int i, int j)
{
	int val = vec[i];
	int l = i;
	int r = j;
	while (l < r)
	{
		while (l <r && vec[r] > val)   //右往左 找第一个比val小的数
		{
			r--;
		}
		if (l < r)
		{
			vec[l++] = vec[r];
		}
		while (l < r && vec[l] <= val) //左到右 找第一个比val小的
		{
			l++;
		}
		if (l < r)
		{
			vec[r--] = vec[l];
		}
	}

	vec[r] = val;   //放置基准数

	return l;		//放回基准数的下标
}

void quickSort(vector<int >& vec, int i, int j)
{
	if (i >= j)
	{
		return;
	}

	int pos = partation(vec, i, j);
	quickSort(vec, i, pos - 1);
	quickSort(vec, pos + 1, j);

}

//找第k大的 vec.size() - k 小的 下标
int max_selectTopK(vector<int>& vec, int i, int j,int k)
{
	int pos = partation(vec, i, j);     //pos表示基准数的位置
	if (pos == vec.size() - k)  //基准数的位置和top k的位置相同了
	{
		return vec[pos];
	}

	else if (pos < vec.size() - k)   //top  k 落在了基准数的右边
	{
		return max_selectTopK(vec, pos + 1, j, k);
	}
	else
	{
		return max_selectTopK(vec, i, pos - 1, k);
	}
}



int main()
{
	vector<int> vec;
	for (int i = 0;i < 20;++i)
	{
		vec.push_back(rand() % 100);
	}
	//求第top 10大的元素
	int val = max_selectTopK(vec, 0, vec.size() - 1,10);

	cout << val << endl;

	quickSort(vec, 0, vec.size() - 1);
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
}


#endif