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
	{
	}

	int data_;
	Node* next_;
	Node* pre_;
};

//双向链表
class DoubleCircleLink
{
public:
	DoubleCircleLink()
	{
		head_ = new Node();
		head_->next_ = head_;
		head_->pre_ = head_;
	}
	~DoubleCircleLink()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_->next_ = p->next_;
			p->next_->pre_ = head_;
			delete p;
			p = head_->next_;  //让p重新指向下一个待删节点
		}
		delete head_;
		head_ = nullptr;
	}

public:
	//头插法
	void InsertHead(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		node->pre_ = head_;
		head_->next_->pre_ = node;
		head_->next_ = node;
	}

	//尾插法
	void InsertTail(int val)
	{
		Node* p = head_->pre_;

		Node* node = new Node(val);
		node->pre_ = p;
		p->next_ = node;
		node->next_ = head_;
		head_->pre_ = node;

	}

	//链表输出函数
	void show() const
	{
		Node* p = head_->next_;
		while (p != head_)
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
		while (p != head_)
		{
			if (p->data_ == val)
			{
				p->pre_->next_ = p->next_;

				p->next_->pre_ = p->pre_;

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
		while (p != head_)
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

	return 0;
}


#endif