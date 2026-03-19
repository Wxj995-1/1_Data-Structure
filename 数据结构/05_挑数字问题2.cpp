#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
挑选数字：有一组整数 请挑选出一组数字 让他们的和等于指定的值 存在解打印 不存在打印
*/


#if 0
int arr[] = { 4,8,12,16,7,9,3 };
int length = sizeof(arr) / sizeof(arr[0]);
int number = 18;          // 目标和
vector<int> vec;   //存放选择的数字

void func(int i, int number)
{
	if (number == 0)
	{
		for (int v : vec)
		{
			cout << v << " ";
		}
		cout << endl;
	}
	else
	{
		//以当前节点开始 把剩余元素的孩子节点生成
		for (int k = i;k < length;++k)
		{
			if (number >= arr[k])
			{
				vec.push_back(arr[k]);
				func(k+1, number - arr[k]);   //遍历孩子节点 arr[k]的孩子节点
				vec.pop_back();

			}
		}
	}

}



int main()
{
	func(0, number);


	return 0;
}

#endif