#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;



#if 0
struct Node
{
	Node(int data = 0) 
		:data_(data)
		, next_(nullptr)
		, pre_(nullptr) 
	{}

	int data_;
	Node* next_;
	Node* pre_;
};

//双向链表
class DoubleLink
{
public:
	DoubleLink()
	{
		head_ = new Node();
	}
	~DoubleLink()
	{
		Node* p = head_;
		while( p != nullptr)
		{
			head_ = head_->next_;
			delete p;
			p = head_;
		
		}
	}

public:
	//头插法
	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		node->pre_ = head_;
		if (head_->next_ != nullptr)
		{
			head_->next_->pre_ = node;
		}
		head_->next_ = node;
	}

	//尾插法
	void InsertTail(int val)
	{
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			p = p->next_;
		}
		
		Node* node = new Node(val);
		node->pre_ = p;
		p->next_ = node;

	}

	//链表输出函数
	void show() const
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			cout << p->data_ << " ";
			p = p->next_;
		}
		cout << endl;
	}
	

	//节点删除
	void Remove(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				p->pre_->next_ = p->next_;
				if (p->next_ != nullptr)
				{
					p->next_->pre_ = p->pre_;
				}
				//Node* next = p->next_;
				delete p;
				//p = next;
				return;

			}
			else
			{
				p = p->next_;
			}
		}



	}

	//查询
	bool Find(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				return true;
			}
			p = p->next_;
		}
		return false;
	}


private:

	Node* head_;

};


int main()
{
	DoubleLink dlink;
	dlink.InsertTail(15);
	dlink.InsertTail(12);
	dlink.InsertTail(153);
	dlink.InsertTail(152);
	dlink.InsertTail(1545);

	dlink.InsertHead(1545);
	dlink.show();


	dlink.Remove(153);
	dlink.show();

	cout << dlink.Find(1552) << endl;
	return 0;
}

#endif