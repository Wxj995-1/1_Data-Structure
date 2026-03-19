#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
有一组物品 重量分别为w1 w2 wn 价值分别是v1 v2 v3 
现在有一个背包 容量是C 问怎么把物品装入背包 能够使背包的价值最大化
*/

#if 0
int w[] = { 12,5,8,9,6 };   //物品的重量
int v[] = { 9,11,4,7,8 };	//物品的价值
const int length = sizeof(w) / sizeof(w[0]);
vector<int> x;  //选择的物品
vector<int> bestx;  //记录最优选择的物品
int c = 20;    //背包的容量
int cw = 0;	   //已选择物品的重量
int cv = 0;	   //已选择物品的价值 
int bestv = 0;  //记录装入的背包的物品的最大价值
int r = 0;		//未处理物品的总价值

void func(int i)
{
	r -= v[i];
	if (i == length)
	{
		if (bestv < cv)
		{
			bestv = cv;
			bestx = x;
		}
	}
	else
	{
		if (cw + w[i] <= c)   //已选择的物品重量 + 即将选择的物品的重量
		{
			cw += w[i];
			cv += v[i];
			x.push_back(w[i]);
			func(i + 1);
			cw -= w[i];
			cv -= v[i];

			x.pop_back();
		}
		
		//bestv cv + [i + 1 ,i + 2,i + n] > bestv
		if (cv + r > bestv)
		{
			func(i + 1);
		}
		r += v[i];
	}

}

int main()
{
	for (int val : v)
	{
		r += val;
	}
	func(0);

	for (int w : bestx)
	{
		cout << w << " ";
	}
	cout << endl;
	return 0;
}

#endif