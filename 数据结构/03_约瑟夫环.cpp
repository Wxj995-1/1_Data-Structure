#include <iostream>
using namespace std;


#if 0
// 节点结构体（包含头结点，头结点data_可设为0）
struct Node {
    int data_;   // 有效节点存1~n，头结点存0
    Node* next_;
    Node(int data = 0) : data_(data), next_(nullptr) {}
};

// 构建带头结点的循环链表（生成1~n的有效节点）
Node* CreateCircularList(int n) {
    // 1. 创建头结点（哑节点）
    Node* dummy = new Node(0);
    // 空链表：头结点next指向自身
    if (n <= 0) {
        dummy->next_ = dummy;
        return dummy;
    }

    // 2. 构建有效节点链
    Node* cur = dummy;  // 前驱节点（初始指向头结点）
    for (int i = 1; i <= n; ++i) {
        Node* new_node = new Node(i);
        cur->next_ = new_node;
        cur = new_node;
    }
    // 3. 尾节点next指向头结点，形成循环
    cur->next_ = dummy;

    return dummy;
}

// 约瑟夫环核心逻辑（带头结点）
// 参数：dummy-头结点；k-起始报数位置（从1开始）；m-报数m次出列
void Joseph(Node* dummy, int k, int m) {
    // 边界防护：空链表（无有效节点）直接返回
    if (dummy == nullptr || dummy->next_ == dummy) {
        cout << "链表为空！" << endl;
        return;
    }

    // 初始化指针：
    Node* pre = dummy;       // 前驱节点（初始指向头结点）
    Node* cur = dummy->next_;// 当前报数节点（第一个有效节点）

    // 步骤1：定位到第k个起始报数节点（移动k-1步）
    for (int i = 0; i < k - 1; ++i) {
        pre = cur;
        cur = cur->next_;
        // 跳过头结点（避免定位到哑节点）
        if (cur == dummy) {
            pre = cur;
            cur = cur->next_;
        }
    }

    // 步骤2：循环删除节点，直到只剩最后一个有效节点
    while (cur->next_ != cur && cur->next_ != dummy) { // 只剩一个有效节点时终止
        // 报数m次：移动m-1步（数1是cur自己，数m需移m-1步）
        for (int i = 0; i < m - 1; ++i) {
            pre = cur;
            cur = cur->next_;
            // 跳过头结点
            if (cur == dummy) {
                pre = cur;
                cur = cur->next_;
            }
        }

        // 输出出列节点，删除cur指向的节点
        cout << cur->data_ << " ";
        pre->next_ = cur->next_; // 前驱节点跳过当前节点
        delete cur;              // 释放内存
        cur = pre->next_;        // 重置cur为下一个起始节点
        // 跳过头结点
        if (cur == dummy) {
            pre = cur;
            cur = cur->next_;
        }
    }

    // 步骤3：输出最后一个节点，释放内存
    cout << cur->data_ << endl;
    delete cur;
    cur = nullptr;

    // 释放头结点
    delete dummy;
    dummy = nullptr;
}

int main() {
    // 构建带头结点的循环链表（8个有效节点：1~8）
    Node* dummy = CreateCircularList(8);
    // 调用约瑟夫环：从第1个节点开始，报数3次出列
    Joseph(dummy, 1, 3);

    return 0;
}

#endif