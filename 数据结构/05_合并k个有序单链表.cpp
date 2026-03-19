#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


#if 0
struct ListNode
{
    ListNode(int x) :val(x), next(nullptr)
    {
    }

    int val;
    ListNode* next;
};

ListNode* init_link(initializer_list<int> list)
{
    ListNode* head = nullptr;
    ListNode* p = nullptr;
    for (int v : list)
    {
        if (head == nullptr)
        {
            head = new ListNode(v);
            p = head;
        }
        else
        {
            p->next = new ListNode(v);
            p = p->next;
        }
    }
    return head;
}

ListNode* mergeTwoLink(ListNode* p1, ListNode* p2)
{
    // 修正：空链表判断逻辑
    if (p1 == nullptr)
    {
        return p2; // p1为空，直接返回p2
    }
    if (p2 == nullptr)
    {
        return p1; // p2为空，直接返回p1
    }

    ListNode* head = nullptr;
    if (p1->val > p2->val)
    {
        head = p2;
        p2 = p2->next;
    }
    else
    {
        head = p1;
        p1 = p1->next;
    }

    ListNode* p = head;
    while (p1 != nullptr && p2 != nullptr)
    {
        if (p1->val > p2->val)
        {
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }
        else
        {
            p->next = p1;
            p = p1;
            p1 = p1->next;
        }
    }

    if (p1 != nullptr)
    {
        p->next = p1;
    }
    if (p2 != nullptr)
    {
        p->next = p2;
    }

    return head;
}

ListNode* mergeLink(vector<ListNode*>& vlink, int i, int j)
{
    if (i >= j)
    {
        return vlink[i];
    }

    int mid = (i + j) / 2;
    ListNode* left = mergeLink(vlink, i, mid);
    ListNode* right = mergeLink(vlink, mid + 1, j);

    return mergeTwoLink(left, right);
}

// 新增：释放链表内存（避免内存泄漏）
void freeLink(ListNode* head) {
    ListNode* tmp = nullptr;
    while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main()
{
    ListNode* p1 = init_link({ 1,3,5,7 });
    ListNode* p2 = init_link({ 1,2,4,6 ,8 });

    vector<ListNode*>vlink;
    vlink.push_back(p1);
    vlink.push_back(p2);
    ListNode* p = mergeLink(vlink, 0, vlink.size() - 1);

    // 修正：打印节点的val，而非next指针
    cout << "合并后的链表值：";
    for (ListNode* c = p;c != nullptr; c = c->next)
    {
        cout << c->val << " "; //输出节点存储的数值
    }
    cout << endl;

    // 释放内存（避免内存泄漏）
    freeLink(p);
    return 0;
}

#endif