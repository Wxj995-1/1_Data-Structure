#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <functional>
using namespace std;

#if 0
enum State
{
    STATE_UNUSE,
    STATE_USING,
    STATE_DEL,
};

struct Bucket
{
    // 修复1：构造函数正确初始化key_，参数名避免和成员重名
    Bucket(int key = 0, State state = STATE_UNUSE)
        : key_(key)
        , State_(state)
    {
    }
    int key_;
    State State_;
};

// 线性探测哈希表类型
class HashTable
{
public:
    HashTable(int size = primes_[0], double loadFactor = 0.75)
        : useBucketNum_(0)
        , loadFactor_(loadFactor)
        , primeIdx_(0)
    {
        // 把用户传入的size调整到最近的比较大的素数上
        if (size != primes_[0])
        {
            // 修复2：循环增量改为primeIdx_++，避免无限循环
            for (; primeIdx_ < PRIME_SIZE; primeIdx_++)
            {
                if (primes_[primeIdx_] > size)
                {
                    break;
                }
            }
            if (primeIdx_ == PRIME_SIZE)
            {
                // 越界，取最后一个素数
                primeIdx_--;
            }
        }
        tableSize_ = primes_[primeIdx_];
        table_ = new Bucket[tableSize_]; // 默认构造，State_=STATE_UNUSE
    }

    ~HashTable()
    {
        delete[] table_;
        table_ = nullptr;
    }

public:
    // 插入元素
    bool insert(int key)
    {
        // 考虑扩容
        double factor = useBucketNum_ * 1.0 / tableSize_;
        cout << "factor:" << factor << endl;
        if (factor > loadFactor_)
        {
            // 哈希表开始扩容
            expand();
        }

        int idx = key % tableSize_;
        int i = idx;
        do
        {
            if (table_[i].State_ != STATE_USING)
            {
                table_[i].State_ = STATE_USING;
                // 修复3：正确赋值key_，而非直接赋值Bucket对象
                table_[i].key_ = key;
                useBucketNum_++;
                return true;
            }
            i = (i + 1) % tableSize_; // 简化：线性探测，每次+1取模
        } while (i != idx); // 遍历完整个表仍无空位，插入失败

        return false;
    }

    // 删除操作
    bool erase(int key)
    {
        int idx = key % tableSize_;
        int i = idx;
        do
        {
            if (table_[i].State_ == STATE_USING && table_[i].key_ == key)
            {
                table_[i].State_ = STATE_DEL;
                useBucketNum_--;
                // 修复4：找到后立即返回，终止循环
                return true;
            }
            i = (i + 1) % tableSize_;
        } while (i != idx); // 修复5：遍历整个表，直到回到起始位置

        // 未找到目标key
        return false;
    }

    // 查询
    bool find(int key)
    {
        int idx = key % tableSize_;
        int i = idx;
        do
        {
            if (table_[i].State_ == STATE_USING && table_[i].key_ == key)
            {
                return true;
            }
            i = (i + 1) % tableSize_;
        } while (i != idx); // 修复6：遍历整个表，直到回到起始位置

        return false;
    }

private:
    void expand()
    {
        ++primeIdx_;
        if (primeIdx_ == PRIME_SIZE)
        {
            throw "hashtable is too large! can not expand anymore!";
        }

        int newSize = primes_[primeIdx_];
        Bucket* newTable = new Bucket[newSize];

        // 遍历旧表，迁移有效数据
        for (int i = 0; i < tableSize_; i++)
        {
            if (table_[i].State_ == STATE_USING) // 旧表有效的数据
            {
                int key = table_[i].key_;
                int idx = key % newSize;
                int k = idx;
                do
                {
                    if (newTable[k].State_ != STATE_USING)
                    {
                        // 修复7：赋值运算符改为=，正确设置状态
                        newTable[k].State_ = STATE_USING;
                        newTable[k].key_ = key;
                        break;
                    }
                    // 修复8：更新k的值，避免死循环
                    k = (k + 1) % newSize;
                } while (k != idx);
            }
        }

        // 释放旧表，切换到新表
        delete[] table_;
        table_ = newTable;
        tableSize_ = newSize;
    }

private:
    Bucket* table_;          // 指向动态开辟的哈希表
    int tableSize_;          // 哈希表总长度
    int useBucketNum_;       // 已经使用的桶的个数
    double loadFactor_;      // 哈希表装载因子

    static const int PRIME_SIZE = 10; // 素数表大小
    static int primes_[PRIME_SIZE];
    int primeIdx_;           // 当前使用的素数下标
};

int HashTable::primes_[PRIME_SIZE] = { 3,7,23,47,97,251,443,911,1471,42773 };

// 测试代码
int main()
{
    HashTable htable;
    cout << "插入21：" << boolalpha << htable.insert(21) << endl;
    cout << "插入32：" << boolalpha << htable.insert(32) << endl;
    cout << "插入14：" << boolalpha << htable.insert(14) << endl;
    cout << "插入15：" << boolalpha << htable.insert(15) << endl;

    cout << "查找14：" << boolalpha << htable.find(14) << endl;
    cout << "删除14：" << boolalpha << htable.erase(14) << endl;
    cout << "查找14：" << boolalpha << htable.find(14) << endl;

    return 0;
}

#endif