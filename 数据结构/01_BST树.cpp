#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <functional>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include <queue>
#include <stack>
#include  <cmath>
using namespace std;

#if 0
template<typename T,typename Compare = less<T>>
class BSTree
{
public:
	BSTree(Compare comp= Compare())
		: root_(nullptr)
		, comp_(comp)
	{

	}
	~BSTree()
	{
		if (root_ != nullptr)
		{
			queue<Node*>s;
			s.push(root_);
			while (!s.empty())
			{
				Node* front = s.front();
				s.pop();

				if (front->left_ != nullptr)
				{
					s.push(front->left_);
				}

				if (front->right_ != nullptr)
				{
					s.push(front->right_);
				}
				delete front;
			}
		}
	}

	//递归插入操作
	void insert(const T& val)
	{
		root_ = insert(root_, val);
	}

	//非递归插入操作
	void n_insert(const T& val)
	{
		//树为空 生成根节点
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return;
		}
		//搜索合适的插入位置 记录父节点位置
		Node* parent = nullptr;
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (!comp_(cur->data_, val))
			{
				parent = cur;
				cur = cur->left_;
			}
			else if (comp_(cur->data_, val))
			{
				parent = cur;
				cur = cur->right_;
			}
			else
			{
				//不插入元素相同的值
				return;
			}

		}

		// 修复：比较val和parent->data_，而非cur（cur已为null）
		if (comp_(val, parent->data_))
		{
			parent->left_ = new Node(val);
		}
		else
		{
			parent->right_ = new Node(val);
		}


	}

	//非递归删除操作
	void n_erase(const T& val)
	{
		if (root_ == nullptr)
		{
			return;
		}

		Node* parent = nullptr;
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (comp_(val, cur->data_)) // 修正：val < cur->data_ → 往左找
			{
				parent = cur;
				cur = cur->left_;
			}
			else if (comp_(cur->data_, val)) // 修正：val > cur->data_ → 往右找
			{
				parent = cur;
				cur = cur->right_;
			}
			else
			{
				break;   // 找到待删除节点，正常触发
			}
		}
		//没找到待删除的节点
		if (cur == nullptr)
		{
			return;
		}
		//情况3：双孩子节点
		if (cur->left_ != nullptr && cur->right_ != nullptr)
		{
			Node* pre_parent = cur; // 修正：用新变量存前驱的父，避免覆盖原parent
			Node* pre = cur->left_;
			while (pre->right_ != nullptr)
			{
				pre_parent = pre;
				pre = pre->right_;
			}
			cur->data_ = pre->data_;
			parent = pre_parent; // 修正：parent指向前驱的父
			cur = pre;   //让cur指向前驱节点   转化成情况1或者2
		}

		//统一处理cur指向的节点 情况1或者情况2
		Node* child = cur->left_;
		if (child == nullptr)
		{
			child = cur->right_;
		}

		if (parent == nullptr)
		{
			root_ = child;
		}
		else
		{
			if (parent->left_ == cur)
			{
				parent->left_ = child;
			}
			else
			{
				parent->right_ = child;
			}
		}

		delete cur;
		cur = nullptr; // 修正：置空野指针
	}

	//非递归查询操作
	bool n_query(const T& val)
	{
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ == val)
			{
				return true;
			}
			else if (comp_(cur->data_, val))
			{
				cur = cur->right_;
			}
			else
			{
				cur = cur->left_;
			}
		}

		return false;
	}

	//递归前序遍历
	void preOrder()
	{
		cout << "[递归]前序遍历：";
		preOrder(root_);
		cout << endl;
	}

	//非递归前序遍历
	void n_preOrder()
	{
		cout << "[非递归]前序遍历：";
		if (root_ == nullptr)
		{
			return;
		}
		stack<Node*> s;
		s.push(root_);
		while (!s.empty())
		{
			Node* top = s.top();
			s.pop();
			cout << top->data_ << " ";

			if (top->right_ != nullptr)
				s.push(top->right_);
			if (top->left_ != nullptr)
				s.push(top->left_);
		}

		cout << endl;
	}

	//递归中序遍历
	void inOrder()
	{
		cout << "[递归]中序遍历：";
		inOrder(root_);
		cout << endl;

	}

	//非递归中序遍历
	void n_inOrder()
	{
		cout << "[非递归]中序遍历：";

		if (root_ == nullptr)
		{
			return;
		}

		stack<Node*> s;
		Node* cur = root_;
		// 核心修复：合并为一个循环，统一处理“左节点入栈+出栈访问+右子树处理”
		while (cur != nullptr || !s.empty())
		{
			// 第一步：把当前节点的所有左节点入栈（包括自身）
			while (cur != nullptr)
			{
				s.push(cur);
				cur = cur->left_;
			}

			// 第二步：出栈访问节点（根）
			Node* top = s.top();
			s.pop();
			cout << top->data_ << " ";

			// 第三步：处理右子树（核心修复：指向右节点，而非直接压栈）
			cur = top->right_;
		}

		cout << endl;
	}

	//递归后序遍历
	void postOrder()
	{
		cout << "[递归]后序遍历：";
		postOrder(root_);
		cout << endl;

	}

	//非递归后序遍历 
	void n_postOrder()
	{
		cout << "[非递归]后序遍历：";
		if (root_ == nullptr)
		{
			return;
		}
		stack<Node*> s1;
		stack<Node*> s2;
		s1.push(root_);
		while (!s1.empty())
		{
			Node* top = s1.top();
			s1.pop();
			s2.push(top);
			if (top->left_ != nullptr)
			{
				s1.push(top->left_);
			}
			if (top->right_ != nullptr)
			{
				s1.push(top->right_);
			}

		}
		while (!s2.empty())
		{
			cout << (s2.top())->data_ << " ";
			s2.pop();
		}

		cout << endl;

	}

	//非递归层序遍历
	void n_levelOrder()
	{
		cout << "[非递归]层序遍历：";
		n_levelOrder(root_);
		cout << endl;
	}

	//递归层序遍历
	void levelOrder()
	{
		cout << "[递归]层序遍历：";
		int h = high();
		for (int i = 0; i < h; i++)
		{
			levelOrder(root_, i);
		}
		levelOrder(root_);
		cout << endl;
	}
	
	//递归求二叉树层数
	int high()
	{
		return high(root_);
	}

	//递归求二叉树节点个数
	int number()
	{
		return number(root_);
	}


	//递归查询操作
	bool query(const T& val)
	{
		return nullptr != query(root_, val);
	}

	//递归删除操作
	void remove(const T& val)
	{
		root_ = remove(root_, val);
	}

	//求满足区间的元素值[i,j]
	void findValues(vector<T>& vec, int i, int j)
	{
		findValues(root_, vec, i, j);

	}

	//判断二叉树是否是BST树
	bool isBSTree()
	{
		Node* pre = nullptr;
		return isBSTree(root_, pre);
	}

	//判断子树问题
	bool isChildTree(BSTree<T, Compare>& child)
	{
		//在当前二叉树上找child的根节点
		if (child.root_ == nullptr)
		{
			return true;
		}
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ == child.root_->data_)
			{
				break;
			}
			else if (comp_(cur->data_, child.root_->data_))
			{
				cur = cur->right_;
			}
			else
			{
				cur = cur->left_;
			}

		}

		if (cur == nullptr)
		{
			return false;
		}
		return isChildTree(cur,child.root_);

	}

	//最近公共祖先节点
	int getLCA(int val1, int val2)
	{
		Node* node =  getLCA(root_, val1, val2);
		if (node == nullptr)
			throw "no LCA";
		else
			return node->data_;
	}

	//镜像翻转问题
	void mirror01()
	{
		mirror01(root_);
	}

	//镜像对称问题
	bool mirror02()
	{
		if (root_ == nullptr)
			return true;
		return mirror02(root_->left_,root_->right_);
	}
 
	//判断平衡树
	bool isBalance()
	{
		int l = 0;
		bool flag = true;
		return isBalance02(root_, l, flag);
		return flag;
	}

	//求中序倒数第k个节点
	int getVal(int k)
	{
		int i = 0;
		Node* node = getVal(root_,k,i);
		if (node == nullptr)
		{
			throw "no No.k";
		}
		else
		{
			return node->data_;
		}
	}



private:
	//节点定义 
	struct Node
	{
		Node(T data = T())
			: data_(data)
			, left_(nullptr)
			, right_(nullptr)
		{

		}
		T data_;
		Node* left_;
		Node* right_;
	};

	Node* root_;   //BST树根节点
	Compare comp_;


	//递归前序遍历的实现
	void preOrder(Node* node)
	{
		if (node != nullptr)
		{
			cout << node->data_ << " ";
			preOrder(node->left_);
			preOrder(node->right_);
		}

	}

	//递归中序遍历
	void inOrder(Node* node)
	{
		if (node != nullptr)
		{
			inOrder(node->left_);
			cout << node->data_ << " ";
			inOrder(node->right_);

		}
	}

	//递归后序遍历
	void postOrder(Node* node)
	{
		if (node != nullptr)
		{
			postOrder(node->left_);
			postOrder(node->right_);
			cout << node->data_ << " ";
		}

	}

	//非递归层序遍历
	void n_levelOrder(Node* node)
	{
		if (root_ == nullptr)
			return;
		queue<Node*> q;

		q.push(root_);
		while (!q.empty())
		{
			// 1. 队头元素出队
			Node* node = q.front();
			q.pop();
			// 2. 遍历
			cout << node->data_ << " ";
			// 3. 检查左右子树
			if (node->left_)
				q.push(node->left_);
			if (node->right_)
				q.push(node->right_);
		}

	}

	//递归插入操作
	Node* insert(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			// 递归结束：找到插入位置，生成新节点并返回
			return new Node(val);
		}

		if (node->data_ == val)
		{
			// 不插入重复值，返回当前节点
			return node;
		}
		// 修复1：递归调用传参改为node->right_/node->left_（Node*类型）
		// 修复2：比较逻辑改为comp_(val, node->data_)（语义更直观）
		else if (comp_(val, node->data_))
		{
			// val < node->data_ → 往左子树插入，更新左孩子指针
			node->left_ = insert(node->left_, val);
		}
		else
		{
			// val > node->data_ → 往右子树插入，更新右孩子指针
			node->right_ = insert(node->right_, val);
		}
		// 返回当前节点（保证父节点能正确更新子指针）
		return node;
	}

	//递归查询操作
	Node* query(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->data_ == val)
		{
			return node;
		}
		else if (comp_(node->data_, val))
		{
			return query(node->right_, val);
		}
		else if (comp_(val, node->data_))
		{
			return query(node->left_, val);
		}
		return node;

	}

	//递归删除操作
	Node* remove(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (node->data_ == val)   //找到删除节点
		{
			//情况3
			if (node->left_ != nullptr && node->right_ != nullptr)
			{
				Node* pre = node->left_;
				while (pre->right_ != nullptr)
				{
					pre = pre->right_;
				}
				node->data_ = pre->data_;
				//通过递归直接删除前驱节点
				node->left_ = remove(node->left_, pre->data_);

			}
			//情况1 和 情况2
			else
			{
				if (node->left_ != nullptr)
				{
					Node* left = node->left_;
					delete node->left_;
					return left;

				}
				else if (node->right_ != nullptr)
				{
					Node* right = node->right_;
					delete node->right_;
					return right;
				}
				//删除叶子节点
				else
				{
					delete node;
					return nullptr;
				}
			}



		}
		else if (comp_(node->data_, val))
		{
			node->right_ = remove(node->right_, val);
		}
		else if (comp_(val, node->data_))
		{
			node->left_ = remove(node->left_, val);
		}
		return node;    //更新父节点相应的地址域
	}

	//递归求二叉树层数
	int high(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int left = high(node->left_);
		int right = high(node->right_);
		return left > right ? left + 1 : right + 1;
	}

	//递归求二叉树节点个数 以node为根节点节点总数
	int number(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int left = number(node->left_);
		int right = number(node->right_);
		return left + right + 1;

	}

	//递归层序遍历
	void levelOrder(Node* node, int i)
	{
		if (node == nullptr)
		{
			return;
		}
		if (i == 0)
		{
			cout << node->data_ << " ";
			return;
		}


		levelOrder(node->left_,i -1);
		levelOrder(node->right_, i -1);
	}

	//求满足区间的元素值[i,j]
	void findValues(Node* node, vector<T>& vec, int i, int j)
	{
		if (node != nullptr)
		{
			//在当前左子树搜索
			if (node->data_ > i)
				findValues(node->left_, vec, i, j);
			//v
			if (node->data_ >= i && node->data_ <= j)
			{
				vec.push_back(node->data_);   //存储满足区间元素的值
			}
			//在当前右子树搜索
			if(node->data_ < j)
				findValues(node->right_, vec, i, j);

		}
	}


	/*
	bool isBSTree(Node* node)
	{
		if (node == nullptr)
		{
			return true; 
		}

		if (node->left_ != nullptr && comp_(node->data_, node->left_->data_))
		{
			return false;
		}
		if (node->right_ != nullptr && comp_(node->right_->data_, node->data_))
		{
			return false;
		}

		if (!isBSTree(node->left_))
		{
			return false;
		}

		return isBSTree(node->right_);
		//if (!isBSTree(node->right_))
		//{
		//	return false;
		//}
		//return true;
	}
	*/
	//判断二叉树是否是BST树 //利用中序遍历升序的特点
	bool isBSTree(Node* node,Node *&pre)
	{
		if (node == nullptr)
		{
			return true;
		}

		if (!isBSTree(node->left_, pre))
			return false;

		if (pre != nullptr)
		{
			if (comp_(node->data_, pre->data_))    //主要判断使递归结束的条件
			{
				return false;
			}
		}
		pre = node; //更新中序遍历的前驱节点

		return isBSTree(node->right_, pre); //R
	}

	//判断字数问题实现
	bool isChildTree(Node* father, Node* child)
	{
		if (father == nullptr && child = nullptr)
		{
			return true;
		}
		if (father == nullptr)
		{
			return false;
		}
		if (child == nullptr)
		{
			return true;
		}
		//判断值不相同
		if (father->data_ == child->data_)
		{
			return false;
		}
		return isChildTree(father->left_, child->left_) && isChildTree(father->right_, child->right_);
	}

	//最近公共祖先实现
	Node* getLCA(Node* node, int val1, int val2)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		if (comp_(node->data_, val1) && comp_(node->data_, val2))
		{
			return getLCA(node->right_, val1, val2);
		}
		else if (comp_(val1, node->data_) && comp_(val2, node->data_))
		{
			return getLCA(node->left_, val1, val2);
		}
		return node;
	}

	//镜像翻转问题
	void mirror01(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		//v
		Node* tmp = node->left_;
		node->left_ = node->right_;
		node->right_ = tmp;

		mirror01(node->left_);   //L
		mirror01(node->right_);  //R

	}

	//镜像对称实现
	bool mirror02(Node* node1, Node* node2)
	{
		if (node1 == nullptr && node2 == nullptr)
		{
			return true;
		}

		if (node1 == nullptr || node2 == nullptr)
		{
			return false;
		}

		if (node1->data_ != node2->data_)
		{
			return false;
		}
		return mirror02(node1->left_, node2->right_) && mirror02(node1->right_, node2->left_);

	}

	//判断平衡树实现  效率低
	bool isBalance(Node *node)
	{
		if (node == nullptr)
			return true;
		if (!isBalance(node->left_))
			return false;
		if (!isBalance(node->right_))
			return false;

		int left = high(node->left_);
		int right = high(node->right_);

		return (abs(left - right) <= 1);
	}

	//判断平衡树实现 记录节点高度值 返回节点高度值
	int isBalance02(Node* node, int l, bool& flag)
	{
		if (node == nullptr)
		{
			return l;
		}
		int left = isBalance02(node->left_,l+1,flag);
		if (!flag)
		{
			return left;
		}
		int right = isBalance02(node->right_, l + 1, flag);
		if (!flag)
		{
			return right;
		}

		if (abs(left - right) > 1)
		{
			flag = false;
		}
		return max(left,right);
	}

	//求中序倒数第k个节点
	Node* getVal(Node* node, int k, int i)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		Node* left = getVal(node->right_, k, i + 1);
		if (left != nullptr)
		{
			return left;
		}
		//V
		if (i == k)   // 在VRL的顺序下 找到整数第k个元素
		{
			return node;
		}

		return getVal(node->left, k, i + 1);
	}



};

void test03()
{
	int arr[] = { 58,24,67,0,34,62,69,5,41,64,78 };
	BSTree<int> bst;

	for (int v : arr)
	{
		bst.insert(v);
	}

	bst.n_insert(12);

	cout << bst.getLCA(41,64) << endl;
	 
}


int main()
{


	return 0;
}


#endif