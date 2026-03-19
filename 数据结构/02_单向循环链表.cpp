#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
#if 0
struct Node
{
	Node(int data = 0) :data_(data), next_(nullptr) {}
	int data_;
	Node* next_;
};

// 约瑟夫环问题 ---- 不带头结点的循环链表
void Joseph(Node* head, int k, int m)
{
	// 边界防护：空链表直接返回
	if (head == nullptr) {
		return;
	}

	Node* p = head;  // 当前报数节点
	Node* q = head;  // p的前驱节点（初始指向尾节点，避免空指针）

	// 步骤1：先让q指向尾节点（循环链表尾节点的next是head）
	while (q->next_ != head) {
		q = q->next_;
	}

	// 步骤2：定位到第k个起始报数节点（修正：移动k-1步）
	for (int i = 1; i < k; i++) {
		q = p;
		p = p->next_;
	}

	// 步骤3：循环删除节点，直到只剩最后一个
	while (p->next_ != p) { // 只剩一个节点时（p->next=p）终止循环
		for (int i = 1; i < m; i++) {
			q = p;
			p = p->next_;
		}

		// 步骤3.2：输出出列节点，删除p指向的节点
		cout << p->data_ << " ";
		q->next_ = p->next_; // 前驱节点跳过当前节点
		delete p;            // 释放内存
		p = q->next_;        // 重置p为下一个起始节点
	}

	// 步骤4：输出最后一个节点，释放内存
	cout << p->data_ << endl;
	delete p;
	p = nullptr;
}

int main()
{
	// 修正1：正确构建循环链表（1→2→3→4→5→6→7→8→1）
	Node* head = new Node(1);
	Node* n1 = new Node(2);
	Node* n2 = new Node(3);
	Node* n3 = new Node(4);
	Node* n4 = new Node(5);
	Node* n5 = new Node(6);
	Node* n6 = new Node(7);
	Node* n7 = new Node(8);

	head->next_ = n1;
	n1->next_ = n2;
	n2->next_ = n3;
	n3->next_ = n4;
	n4->next_ = n5;
	n5->next_ = n6;
	n6->next_ = n7;
	n7->next_ = head; // 尾节点指向头，形成循环

	// 调用：从第1个人开始，报数3次出列
	Joseph(head, 1, 3);

	return 0;
}





class CircleLink
{
public:
	CircleLink()
	{
		head_ = new Node();
		tail_ = head_;
		head_->next_ = head_;
	}

	~CircleLink()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_->next_ = p->next_;
			delete p;
			p = head_->next_;
		}
		delete head_;
	}

public:
	//尾差法
	void InsertTail(int val)
	{
		Node* node = new Node(val);
		node->next_ = tail_->next_;
		tail_->next_ = node;
		tail_ = node;   //更新tail指向尾节点
	}

	//头插法
	void InsertHead(int  val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;
		if (node->next_ == head_)
		{
			tail_ = node;
		}
	}

	//删除节点
	void Remove(int val)
	{
		Node* q = head_;
		Node* p = head_->next_;

		while (p != head_)
		{
			if (p->data_ == val)
			{
				//找到要删除的节点
				q->next_ = p->next_;
				delete p;
				if (q->next_ == head_)
				{
					tail_ = q;
				}
				return;
			}
			else
			{
				q = p;
				p = p->next_;
			}
		}

	}

	//查询
	bool Find(int val) const
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->data_ == val)
				return true;
			else
			{
				p = p->next_;
			}
			
		}
		return false;

	}

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



private:
	struct Node
	{
		Node(int data = 0) :data_(data), next_(nullptr) {}
		int data_;
		Node* next_;

	};
	
	Node* head_;
	Node* tail_;


};




int main()
{
	CircleLink clink;

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		clink.InsertHead(rand() % 100);
	}

	clink.show();


	clink.InsertHead(8);
	cout << clink.Find(8) << endl;
	clink.show();


	clink.Remove(8);
	cout << clink.Find(8) << endl;
	clink.show();

	return 0;
}

#endif