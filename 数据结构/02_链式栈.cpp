#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;


#if 0
//Ë³ÐòÕ»  C++ÈÝÆ÷ÊÊÅäÆ÷ stack
class LinkStack
{
public:
	LinkStack()
	{
		head_ = new Node;
	}
	~LinkStack()
	{
		Node* p = head_;
		while (p != nullptr)
		{
			head_ = p->next_;
			delete p;
			p = head_;
		}
	}

public:
	//ÈëÕ»²Ù×÷
	void push(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;

	}
	//³öÕ»²Ù×÷
	void pop()
	{
		if (head_->next_ == nullptr)
		{
			throw "stack is empty!";
		}
		Node* p = head_->next_;
		head_->next_ = p->next_;
		delete p;
	}

	//»ñÈ¡Õ»¶¥ÔªËØ
	int top() const
	{
		if (head_->next_ == nullptr)
			throw "stack is empty!";
		return head_->next_->data_;
	}

	bool empty() const
	{
		return head_->next_ == nullptr;
	}



private:

	struct Node
	{
		Node(int data = 0)
			:data_(data)
			, next_(nullptr)
		{
		}
		int data_;
		Node* next_;
	};

	Node* head_;
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