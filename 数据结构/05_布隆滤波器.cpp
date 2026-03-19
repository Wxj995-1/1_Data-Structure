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
using namespace std;

#if 0
class BloomFilter {
public:
    BloomFilter(int bitSize, int hashNum)
        : bitSize_(bitSize), hashNum_(hashNum), bits_(bitSize, 0) {
    }

    // 插入元素
    void insert(const string& key) {
        for (int i = 0; i < hashNum_; ++i) {
            size_t idx = hashFunc(key, i) % bitSize_;
            bits_[idx] = 1;
        }
    }

    // 查询元素是否可能存在
    bool contains(const string& key) {
        for (int i = 0; i < hashNum_; ++i) {
            size_t idx = hashFunc(key, i) % bitSize_;
            if (!bits_[idx]) {
                return false; // 有一个bit为0，一定不存在
            }
        }
        return true; // 所有bit为1，可能存在
    }

private:
    // 自定义多哈希函数：通过seed生成不同的哈希值
    size_t hashFunc(const string& key, int seed) {
        hash<string> hasher;
        return hasher(key + to_string(seed)); // 拼接seed生成不同哈希值
    }

    int bitSize_;       // 位数组长度
    int hashNum_;       // 哈希函数数量
    vector<bool> bits_; // 二进制位数组
};

int main() {
    BloomFilter bf(10000, 7); // 10000位，7个哈希函数
    bf.insert("apple");
    bf.insert("banana");

    cout << "apple是否存在：" << boolalpha << bf.contains("apple") << endl; // true
    cout << "orange是否存在：" << boolalpha << bf.contains("orange") << endl; // false
    return 0;
}

#endif