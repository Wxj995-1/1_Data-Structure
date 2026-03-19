#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

#if 0

//顺序栈  C++容器适配器 stack
class SeqStack
{
public:
	SeqStack(int size = 10)
		:mtop(0)
		,mcap(size)
	{
		mpstack = new int[mcap];
	}

	~SeqStack()
	{
		delete[] mpstack;
		mpstack = nullptr;
	}

public:
	void push(int val)
	{
		if (mtop == mcap)
		{
			//栈需要进行扩容
			expand(2 * mcap);
		}
		mpstack[mtop++] = val;

	}

	void pop()
	{
		if (mtop == 0)
		{
			return;
		}
		mtop--;
	}

	int top() const
	{
		if (mtop == 0)
		{
			throw "stack is empty!";
		}
		return mpstack[mtop-1 ];
	}


	//判断栈空
	bool empty() const
	{
		return mtop == 0;
	}

	//栈元素个数
	int size() const
	{
		return mtop;
	}

private:
	void expand(int size)
	{
		int* p = new int[size];
		memcpy(p, mpstack, mtop * sizeof(int));
		delete[]mpstack;
		mpstack = p;
		mcap = size;
	}
private:
	int* mpstack;
	int mtop;		//栈顶位置
	int mcap;		//栈空间大小

};





int main()
{
	SeqStack s;
	int arr[] = { 12,2,5,6,5,34,5646,5 };

	for (int v : arr)
	{
		s.push(v);
	}

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0; 
}

#endif