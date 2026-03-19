#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

#if 0

class Queue
{
public:
	Queue(int size = 10) :cap_(size), front_(0),rear_(0)
	{
		pQue_ = new int[cap_];
	}

	~Queue()
	{
		delete[] pQue_;
		pQue_ = nullptr;
	}


public:
	//入队
	void push(int val)
	{
		if(front_ == (rear_+1) % cap_)
		{
			expand(2*cap_);
		}
		pQue_[rear_] = val;
		rear_ = (rear_ + 1) % cap_;
		//size_++;
	}

	//出队
	void pop()
	{
		if (front_ == rear_)
		{
			throw "queue is empty";
		}

		front_ = (front_ + 1) % cap_;
		//size_--;
	}

	//获取队头元素
	int front() const
	{
		if (front_ == rear_)
		{
			throw "queue is empty";
		}
		return pQue_[front_];

	}

	//获取队尾元素
	int rear() const
	{
		if (front_ == rear_)
		{
			throw "queue is empty";
		}
		return pQue_[(rear_ - 1 + cap_) % cap_];
	}


	//判断队空
	bool empty() const
	{
		return front_ == rear_;

	}

	//统计元素个数
	int size() const
	{
		int size = 0;
		for (int i = front_; i != rear_;i = (i + 1) % cap_)
		{
			size++;
		}
		return size;
	}
private:
	int* pQue_;
	int cap_;   //空间容量
	int front_;
	int rear_;
	//int size_;
private:
	void expand(int size)
	{
		int* p = new int[size];
		int i = 0;
		int j = front_;
		for (;j != rear_;i++, j = (j + 1) % cap_)
		{
			p[i] = pQue_[j];
		}
		delete[] pQue_;
		pQue_ = p;
		cap_ = size;
		front_ = 0;
		rear_ = i;
	}
	

};






int main()
{
	int arr[] = { 12,2,5,6,5,34,5646,5 };
	Queue que;
	for (int v : arr)
	{
		que.push(v);
	}

	cout << que.front() << endl;
	cout << que.rear() << endl;
	return 0;
}
#endif