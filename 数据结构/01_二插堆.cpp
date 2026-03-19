#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <functional>
using namespace std;


#if 0
//优先级队列实现
class PriorityQueue
{
public:
	using Comp = function<bool(int, int)>;
	PriorityQueue(int cap = 20,Comp comp = greater<int>())
		:size_(0)
		,cap_(cap)
		,comp_(comp)
	{
		que_ = new int[cap_];
	}

	PriorityQueue(Comp comp)
		:size_(0)
		, cap_(20)
		, comp_(comp)
	{
		que_ = new int[cap_];
	}

	~PriorityQueue()
	{
		delete[] que_;
		que_ = nullptr;
	}

public:
	//入堆操作
	void push(int val)
	{
		//判断扩容
		if (size_ == cap_)
		{
			int* p = new int[2 * size_];
			memcpy(p, que_, cap_ * sizeof(int));
			delete[] que_;
			que_ = p;
			cap_ *= 2;
		}
		if (size_ == 0)
		{
			//只有一个元素 不需要上浮调整
			que_[size_] = val;
		}
		else
		{
			//堆里面有多个元素 需要上浮调整
			siftUp(size_, val);
		}
		size_++;
	}

	void pop()
	{
		if (size_ == 0)
		{
			throw "error! empty!";
		}
		//先保存最后一个元素，再递减size_（仅减一次）
		int lastVal = que_[size_ - 1];
		size_--;
		if (size_ > 0)
		{
			// 下沉调整：将最后一个元素放到堆顶（i=0）
			siftDown(0, lastVal);
		}
	}

	bool empty() const
	{
		return size_ == 0;
	}

	int top() const
	{
		if (size_ == 0)
		{
			throw "error! empty!";
		}
		return que_[0];
	}

	int size() const
	{
		return size_;
	}
private:
	int* que_;  //指向动态扩容的数组
	int size_;  //数组元素的大小
	int cap_;	//数组的总空间大小
	Comp comp_; //比较器

private:
	//入堆上浮操作
	void siftUp(int i, int val)
	{
		while (i > 0)
		{
			int father = (i - 1) / 2;
			if (comp_(val, que_[father]))
			{
				que_[i] = que_[father];
				i = father;
			}
			else
			{
				break;
			}

		}
		que_[i] = val; 
	}

	//出堆下沉操作
	void siftDown(int i,int val)
	{
		//i下沉不能超过最后一个有孩子的节点
		while (i <= size_ / 2)
		{
			int child = 2 * i + 1;    //左孩子
			if(child + 1 < size_ && comp_(que_[child + 1],que_[child]))
			{
				child = child + 1;
			}
			if (comp_(que_[child], val))
			{
				que_[i] = que_[child];
				i = child;
			}
			else
			{
				break;
			}
		}
		que_[i] = val;
	}



};

int main()
{
	//PriorityQueue que;
	PriorityQueue que([](int a, int b) {return a < b;});
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		que.push(rand() % 100);
	}

	while (!que.empty())
	{
		cout << que.top() << " ";
		que.pop();
	}
	cout << endl;
}

#endif