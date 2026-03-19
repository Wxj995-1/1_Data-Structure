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
/*
插入结点的叔叔是红色:   ----->>>>>>     叔父爷变色，爷爷变插入结点
插入结点的叔叔是黑色：  ----->>>>>>     (LL,RR,LR,RL)旋转，然后变色

插入结点是根结点:		----->>>>>>      直接变黑
*/


#if 0
template <typename T>
class RBTree
{
public:
	RBTree() :root_(nullptr) {}

	//插入操作
	void insert(const T& val)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return;
		}
		//节点不为空
		Node* parent = nullptr;
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ > val)
			{
				parent = cur;
				cur = cur->left_;
			}
			else if (cur->data_ < val)
			{
				parent = cur;
				cur = cur->right_;
			}
			else
			{
				return;
			}
		}
		//设置当前节点的red和parent
		Node* node = new Node(val, parent, nullptr, nullptr, RED);
		if (parent->data_ > val)
		{
			parent->left_ = node;
		}
		else
		{
			parent->right_ = node;
		}

		//父节点也是红色 进行插入调整操作
		if (RED == color(parent))
		{
			fixAfterInsert(node);
		}
	}



private:
	//节点颜色
	enum Color
	{
		BLACK,
		RED
	};
	
	//节点类型
	struct Node
	{
		Node(T data = T(), Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr, Color color = BLACK)
			:data_(data)
			, left_(left)
			, right_(right)
			, parent_(parent)
			, color_(color)
		{
		}
		T data_;
		Node* left_;
		Node* right_;
		Node* parent_;   //指向当前节点的父节点
		Color color_;	 //节点的颜色
	};

	//返回节点的颜色
	Color color(Node* node)
	{
		return node = nullptr ? BLACK : node->color_;
	}

	//设置节点颜色
	void setColor(Node* node, Color color)
	{
		node->color_ = color;
	}

	//返回节点的左孩子
	Node* left(Node* node)
	{
		return node->left_;
	}

	//返回节点的右孩子
	Node* right(Node* node)
	{
		return node->right_;
	}

	//返回节点的父亲
	Node* parent(Node* node)
	{
		return node->parent_;
	}

	//左旋转
	void leftRotate(Node* node)
	{
		Node* child = node->right_;
		child->parent_ = node->parent_;
		if (node->parent_ == nullptr)
		{
			//node本身就是根节点
			root_ = child;
		}
		else
		{
			if (node->parent_->left_ == node)
			{
				//node在父节点的左孩子
				node->parent_->left_ = child;
			}
			else
			{
				node->parent_->right_ = child;
			}
		}
		node->right_ = child->left_;
		if (child->left_ != nullptr)
		{
			child->left_->parent_ = node;
		}

		child->left_ = node;
		node->parent_ = child;
	}

	//右旋转
	void rightRotate(Node* node)
	{
		Node* child = node->left_;
		child->parent_ = node->parent_;
		if (node->parent_ == nullptr)
		{
			//node原来就是root节点
			root_ = child;
		}
		else
		{
			if (node->parent_->left_ == node)
			{
				//node在父节点的左边
				node->parent_->left_ = child;
			}
			else
			{
				node->parent_->right_ = child;
			}
		}

		node->left_ = child->right_;
		if (child->right_ != nullptr)
		{
			child->right_->parent_ = node;
		}

		child->right_ = node;
		node->parent_ = child;
	}

	//红黑树的插入调整操作
	void fixAfterInsert(Node* node)
	{
		//如果当前红色节点的父节点也是红色 继续调整
		while (color(parent(node)) == RED)
		{
			if (left(parent(patent(node))) == parent(node))
			{
				//插入的节点在左子树当中
				Node* uncle = right(parent(parent(node)));
				if (RED == color(uncle))
				{
					setColor(parent(node), BLACK);
					setColor(uncle, BLACK);
					setColor(parent(parent(node)), BLACK);
					node = parent(parent(node));   //指向爷爷继续调整
				}
				else
				{
					//先处理情况3
					if (right(parent(node)) == node)
					{
						node = parent(node);
						leftRotate(parent(node));
					}

					//统一处理情况2
					setColor(parent(node), BLACK);
					setColor(parent(parent(node)), RED);
					rightRotate(parent(parent(node)));
					break;   //调整已经完成
				}

			}
			else
			{
				//插入的节点在右子树当中
								//插入的节点在左子树当中
				Node* uncle = left(parent(parent(node)));
				if (RED == color(uncle))
				{
					setColor(parent(node), BLACK);
					setColor(uncle, BLACK);
					setColor(parent(parent(node)), BLACK);
					node = parent(parent(node));   //指向爷爷继续调整
				}
				else
				{
					//先处理情况3
					if (left(parent(node)) == node)
					{
						node = parent(node);
						rightRotate(parent(node));
					}

					//统一处理情况2
					setColor(parent(node), BLACK);
					setColor(parent(parent(node)), RED);
					leftRotate(parent(parent(node)));
					break;   //调整已经完成
				}
			}

		}

		//此处强制root为黑色节点
		setColor(root_, BLACK);

	}



	Node* root_;   //指向红黑树的根节点
};


int main()
{


	return 0;
}

#endif