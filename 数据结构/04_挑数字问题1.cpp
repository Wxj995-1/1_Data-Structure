#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
挑选数字：有一组整数 请挑选出一组数字 让他们的和等于指定的值 存在解打印 不存在打印
*/


#if 0
int arr[] = { 4,8,12,16,7,9,3 };
int length = sizeof(arr) / sizeof(arr[0]);
int number = 18;          // 目标和
vector<int> x;            // 记录当前选择的数字
int sum = 0;              // 当前选择数字的和
int cnt = 0;              // 记录遍历的完整子集个数（测试用）
int r = 0;                // 记录未处理数字的和
bool has_solution = false;// 标记是否找到有效解

void func(int i)
{
    if (i == length)
    {
        cnt++; // 统计遍历到的完整子集数（叶子节点）
        if (sum == number)
        {
            has_solution = true;
            // 打印找到的解
            for (int v : x)
            {
                cout << v << " ";
            }
            cout << endl;
        }
        return; // 终止递归
    }

    // 核心：先更新未处理和r（第i个元素从“未处理”变为“处理中”）
    r -= arr[i];

    // 左分支：选择第i个元素（剪枝：选了之后和不超过目标值）
    if (sum + arr[i] <= number)
    {
        sum += arr[i];
        x.push_back(arr[i]);
        func(i + 1); // 递归处理下一个元素
        // 回溯：恢复状态
        x.pop_back();
        sum -= arr[i];
    }

    // 右分支：不选择第i个元素（剪枝：当前和 + 剩余未处理和 >= 目标值，才有希望找到解）
    if (sum + r >= number)
    {
        func(i + 1); // 递归处理下一个元素
    }

    // 回溯：恢复未处理和r（第i个元素处理完毕，回到“未处理”）
    r += arr[i];
}

int main()
{
    // 第一步：先初始化r为数组总和（未处理元素的和）
    for (int v : arr)
    {
        r += v;
    }
    // 第二步：调用递归函数
    func(0);

    // 第三步：处理输出逻辑（存在解/不存在解）
    if (!has_solution)
    {
        cout << "不存在和为" << number << "的数字组合" << endl;
    }
    // 打印遍历的子集数（测试用）
    cout << "遍历的完整子集数：" << cnt << endl;

    return 0;
}

#endif