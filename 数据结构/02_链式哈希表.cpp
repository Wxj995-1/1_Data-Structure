#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <functional>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;


#if 0
class HashTable
{
public:
    HashTable(int size = primes_[0], double loadFactor = 0.75)
        : useBucketNum_(0)
        , loadFactor_(loadFactor)
        , primeIdx_(0)
    {
        if (size != primes_[0])
        {
            for (; primeIdx_ < PRIME_SIZE; primeIdx_++)
            {
                if (primes_[primeIdx_] >= size)
                {
                    break;
                }
            }

            if (primeIdx_ == PRIME_SIZE)
            {
                primeIdx_--;
            }
        }

        table_.resize(primes_[primeIdx_]);
    }

public:
    // 增加元素 不能重复插入元素
    void insert(int key)
    {
        // 判断扩容
        double factor = useBucketNum_ * 1.0 / table_.size();
        cout << "factor: " << factor << endl;
        if (factor > loadFactor_)
        {
            expand();
        }
        int idx = key % table_.size();

        // 修复1：统一逻辑，先查key是否存在（无需分empty/else）
        auto it = ::find(table_[idx].begin(), table_[idx].end(), key);
        if (it == table_[idx].end()) // 没找到key，才插入
        {
            if (table_[idx].empty())
            {
                useBucketNum_++; // 空桶插入，桶数+1
            }
            table_[idx].emplace_front(key); // 头插元素
        }
        // 找到key则不做任何操作（避免重复插入）
    }

    // 删除元素
    void erase(int key)
    {
        int idx = key % table_.size();

        auto it = ::find(table_[idx].begin(), table_[idx].end(), key);
        if (it != table_[idx].end())
        {
            table_[idx].erase(it);
            if (table_[idx].empty())
            {
                useBucketNum_--; // 桶空了，桶数-1
            }
        }
    }

    // 搜索元素
    bool find(int key)
    {
        int idx = key % table_.size();
        auto it = ::find(table_[idx].begin(), table_[idx].end(), key);
        // 修复2：统一返回，找到返回true，否则返回false
        return it != table_[idx].end();
    }

private:
    void expand()
    {
        if (primeIdx_ + 1 == PRIME_SIZE)
        {
            throw "hashtable can not expand anymore!";
        }

        primeIdx_++;
        useBucketNum_ = 0;
        vector<list<int>> oldtable;
        table_.swap(oldtable);
        table_.resize(primes_[primeIdx_]);

        // 修复3：用引用遍历，避免链表值拷贝
        for (auto& list : oldtable)
        {
            for (auto key : list)
            {
                int idx = key % table_.size();
                if (table_[idx].empty())
                {
                    useBucketNum_++;
                }
                table_[idx].emplace_front(key);
            }
        }
    }

private:
    vector<list<int>> table_;      // 拉链法核心结构：vector存list
    int useBucketNum_;             // 已使用的桶个数（非空链表数）
    double loadFactor_;            // 装载因子

    static const int PRIME_SIZE = 10; // 素数表大小
    static int primes_[PRIME_SIZE];
    int primeIdx_;                 // 当前使用的素数下标
};

int HashTable::primes_[PRIME_SIZE] = { 3,7,23,47,97,251,443,911,1471,42773 };

int main()
{
    HashTable htable;
    htable.insert(21);
    htable.insert(32);
    htable.insert(14);
    htable.insert(15);
    htable.insert(22);
    htable.insert(21); // 测试重复插入（应被拒绝）

    cout << "查找21：" << boolalpha << htable.find(21) << endl; // 输出true

    htable.erase(21);
    cout << "删除后查找21：" << boolalpha << htable.find(21) << endl; // 输出false

    return 0;
}

#endif