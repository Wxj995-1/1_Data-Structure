#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


#if 0

//对数时间求中位数
double middleValue(vector<int>& nums1, int length1, vector<int>& nums2, int length2)
{
	if (length1 > length2)
	{
		//在短的数组中求解合适的i和j
		return middleValue(nums2, length2, nums1, length1);
	}
	int i = 0;
	int j = 0;
	int begin = 0;
	int end = length1;
	int k = (length1 + length2 + 1) / 2;
	while (begin <= end)
	{
		//二分搜索算法思想   对数时间
		i = (begin + end) / 2;
		j = k - i;
		if (i > 0 && j < length2 && nums1[i - 1] > nums2[j])
		{
			end = i - 1;
		}
		else if (j > 0 && i < length1 &&nums2[j - 1] > nums1[i])
		{
			begin = i + 1;
		}
		else
		{
			break;
		}
	}

	int left = 0;

	//nums1特别短  而且nums1的数组的元素的值都特别大
	if (i == 0)
	{
		//中位数肯定在nums2这个数组当中
		left = nums2[j - 1];
	}
	else if (j == 0)
	{
		//nums2的数组太短了
		left  = nums1[i - 1];
	}
	else
	{
		left = std::max(nums1[i - 1], nums2[j - 1]);
	}

	int right = 0;
	if (i == length1)
	{
		//nums1数组元素太小 而且值都特别小
		right = nums2[j];
	}
	else if (j == length2)
	{
		//中位数肯定都在nums1这个数字当中
		right = nums1[i];
	}
	else
	{
		right = std::min(nums1[i], nums2[j]);
	}


	//找到了合适的i和j
	if ((length1 + length2) % 2 == 0)   //偶数长度
	{
		return (left + right) * 1.0 / 2;
	}
	else
	{
		return left;
	}

}




int main()
{
	vector<int> vec1;
	vector<int> vec2;

	for (int i = 0;i < 10;++i)
	{
		vec1.push_back(rand() % 100);
	}
	for (int i = 0;i < 10;++i)
	{
		vec2.push_back(rand() % 100);
	}
	
	vector<int> vec = vec1;
	for (int v : vec2)
	{
		vec.push_back(v);
	}
	sort(vec.begin(), vec.end());
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;


	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	double midval = middleValue(vec1, vec1.size(), vec2, vec2.size());
	cout << "midval:" << midval << endl;


	return 0;
}
#endif