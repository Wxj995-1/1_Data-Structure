#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Node
{
	Node(int data = 0) :data_(data), next_(nullptr) {}
	int data_;
	Node* next_;
};



class Clink
{
public:
	Clink()
	{
		head_ = new Node();
	}
	~Clink()
	{
		Node* p = head_;
		while(p!=nullptr)
		{
			head_ = head_->next_;
			delete p;
			p = head_;
		}
		head_ = nullptr;
	}

	//尾差法	O(n)
	void InsertTail(int val)
	{
		// 先找到当前链表的末尾节点
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			p = p->next_;
		}

		// 生成新节点
		Node* node = new Node(val);
		// 把新节点挂在尾节点的后面
		p->next_ = node;
	}


	//链表的头插法	O(1)
	void InsertHeat(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;
	}

	//链表节点的删除
	void Remove(int val)
	{
		Node* q = head_;
		Node* p = head_->next_;

		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				q->next_ = p->next_;
				delete p;
				return;
			}
			else
			{
				q = p;
				p = p->next_;
			}

		}
	}

	void RemoveAll(int val)
	{
		Node* q = head_;
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{ 
				q->next_ = p->next_;
				delete p;
				//对指针p进行重置
				p = q->next_;

			}
			else
			{
				q = p;
				p = p->next_;
			}



		}


	}

	//搜索
	bool Find(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				return true;
			}
			else
			{
				p = p->next_;
			}
		} 
		return false;

	}


	void show()
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			cout << p->data_ << " ";
			p = p->next_;
		}
		cout << endl;
	}

private:
	Node* head_;  //指向链表的头节点
	friend void ReverseLink(Clink& head);
	friend bool GetLaskNode(Clink& link, int k, int& val);
	friend void MergeLink(Clink& link1, Clink& link2);


};

//单链表逆序
void ReverseLink(Clink  &link)
{
	Node* head = link.head_;
	Node* p = head->next_;
	if (p == nullptr)
	{
		return;
	}
	head->next_ = nullptr;

	while (p != nullptr)
	{
		Node* q = p->next_;

		//p指针指向的节点进行头插
		p->next_ = head->next_;
		head->next_ = p;
		p = q;
	}

}

//求倒数第k个节点的值
bool GetLaskNode(Clink& link,int k,int &val)
{
	Node* head = link.head_;
	Node* pre = head;
	Node* p = head;
	
	if (k < 1)
	{
		return false;
	}
	
	for (int i = 0; i < k; i++)
	{
		p = p->next_;
		if (p == nullptr)
		{
			return false;
		}
	}
	//pre在头结点 p在整数第k个节点
	while (p != nullptr)
	{
		pre = pre->next_;
		p = p->next_;
	}

	val = pre->data_;
	return true;
}
    

void MergeLink(Clink& link1, Clink& link2)
{
	Node* p = link1.head_->next_;
	Node* q = link2.head_->next_;
	Node* last = link1.head_;
	link2.head_->next_ = nullptr;
	while (p != nullptr && q != nullptr)
	{
		if (p->data_ < q->data_)
		{
			last->next_ = p;
			p = p->next_;
			last = last->next_;
		}
		else
		{
			last->next_ = q;
			q = q->next_;
			last = last->next_;
		}
	}
	if (p != nullptr)
	{
		last->next_ = p;
	}
	else
	{
		last->next_ = q;
	}


}

//判断单链表是否存在环 存在返回环的入口节点
bool IsLinkHasCircle(Node * head,int &val)
{
	// 空链表直接返回无环
	if (head == nullptr) {
		return false;
	}
	
	Node* fast = head;
	Node* slow = head;

	while (fast != nullptr && fast->next_ != nullptr)
	{
		slow = slow->next_;
		fast = fast->next_->next_;

		if (slow == fast)
		{
			//链表存在环
			fast = head;
			while (fast != slow)
			{
				slow  = slow->next_;
				fast = fast->next_;
			}
			val = slow->data_;
			return true;
		}
	}
	return false;


}

bool IsLinkHasMerge(Node* head1, Node* head2, int& val)
{
	int cnt1 = 0;
	int cnt2 = 0;
	Node* p = head1->next_;
	Node* q = head2->next_;

	while (p != nullptr)
	{
		cnt1++;
		p = p->next_;
	}

	while (q!= nullptr)
	{
		cnt2++;
		q = q->next_;
	}
	p = head1;
	q = head2;
	if (cnt1 > cnt2)
	{
		int offset = cnt1 - cnt2;

		while (offset-- > 0)
		{
			p = p->next_;
		}
	}
	else
	{
		int offset = cnt2 - cnt1;

		while (offset-- > 0)
		{
			q = q->next_;
		}
	}
	while (p != nullptr && q != nullptr)
	{
		if (p == q)
		{
			val = p->data_;
			return true;
		}
		q = q->next_;
		p = p->next_;
	}

	return false;

}

#if 0
int main()
{
	Node head;
	Node n1(25), n2(67), n3(32), n4(18);
	head.next_ = &n1;
	n1.next_ = &n2;
	n2.next_ = &n3;
	n3.next_ = &n4;
	n4.next_ = &n2;

	int val;
	if (IsLinkHasCircle(&head, val))
	{
		cout << "存在环" << endl;
		cout << "节点是：" << val << endl;
	}


}





int main()
{
	int arr1[] = { 25,37,52,78,88,92,98,108 };
	int arr2[] = { 13,23,40,56,62,77,109 };
	Clink link1;
	Clink link2;

	for (int v : arr1)
	{
		link1.InsertTail(v);
	}
	for (int v1 : arr2)
	{
		link2.InsertTail(v1);
	}

	link1.show();
	link2.show();

	MergeLink(link1, link2);
	link1.show();
	link2.show();
}





int main()
{
	Clink link;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int val = rand() % 100;
		link.InsertTail(val);
		cout << val << " ";
	}
	cout << endl;

	ReverseLink(link);
	link.show();

	int kval;
	if (GetLaskNode(link, 0, kval))
	{
		cout << "倒数第1个的值为：" << kval << endl;
	}


}



int main()
{
	Clink link;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int val = rand() % 100;
		link.InsertTail(val);
		cout << val << " ";
	}
	cout << endl;

	link.show();

	link.InsertTail(200);
	link.InsertHeat(30);
	link.InsertHeat(200);
	link.InsertHeat(200);
	link.show(); 

	cout << link.Find(300) << endl;
	link.RemoveAll(200);
	link.show();
	return 0;
}
#endif