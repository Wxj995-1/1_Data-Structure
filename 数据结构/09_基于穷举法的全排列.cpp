#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;




#if 0
int main()
{
	vector<int> vec;
	for (int i = 0;i < 11;++i)
	{
		vec.push_back(rand() % 100);
	}
	sort(vec.begin(),vec.end());

	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

#endif