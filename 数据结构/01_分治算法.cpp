#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#if 0
bool binary_Search(vector<int>& vec, int i, int j, int val)
{
	if (i > j)
		return false;
	int mid = (i + j) / 2;
	if (vec[mid] == val)
	{
		return true;
	}
	else if (vec[mid] > val)
	{
		binary_Search(vec, i, mid - 1, val);
	}
	else
	{
		binary_Search(vec, mid + 1, j, val);
	}

}



int main()
{
	vector<int> vec;
	for (int i = 0;i < 11;++i)
	{
		vec.push_back(rand() % 100);
	}
	sort(vec.begin(), vec.end());

	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << endl;

	bool result = binary_Search(vec, 0, vec.size() - 1,34);
	cout << "result:" << result << endl;



	return 0;
}



#endif