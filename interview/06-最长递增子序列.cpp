//C++ file
/***********************************************
#
#      Filename: 06-最长递增子序列.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 给定一个数组，找出其最长递增的子序列
                如输入：1，4，3，5，4
                则最长子序列长度为3，子序列为1，3，5或1，3，4
                首先实现一个求长度的方法，再实现一个求出有哪些子序列的方法
#        Create: 2021-06-27 17:53:16
#**********************************************/
#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;

int Max(int *arr, int len)
{
    int max = 0;
    cout << "dp:\t";
    for (int i = 0; i < len; ++i)
    {
        cout << arr[i] << " ";
        if (arr[i] > max) max = arr[i];
    }
    cout << endl;
    return max;
}

// 返回最长递增子序列的长度
// 思路：动归。dp[i]的含义是：以第i个数结尾的最长递增子序列的长度。
//     状态转移方程式：如知道了dp[4]求dp[5]，即先找出输入数组arr下标为4之前的比arr[5]值小的下标j，选出最大的dp[j],
//     然后就有了转移表达式：dp[5] = dp[j]+1（如果没有比当前的arr[i]还小的值在前面，那么dp[5]=1），以此就可延伸到求dp[i]的情况了
int LengthOfLongestIncreaseSubsequence(const vector<int> &arr)
{
    if (arr.size() == 0) return 0;

    int length = 1;
    int vecLen = arr.size();
    int *dp = new int[vecLen];
    int maxDp;

    cout << "arr:\t";
    for (int i = 0; i < vecLen; ++i)
    {
        maxDp = 1; 
        cout << arr[i] << " ";
        if (i == 0) 
        {
            dp[i] = 1;
            continue;
        }
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])  // 找出值比当前遍历到的数字小的位置j
            {
                if (maxDp < dp[j]+1)  // 需要最大的dp值
                    maxDp = dp[j] + 1;
            }
        }
        dp[i] = maxDp;
    }
    cout << endl;

    length = Max(dp, vecLen);

    delete []dp;
    return length;
}

int main()
{
    vector<int> vec = { 1,4,3,5,4,5 };
    int len = LengthOfLongestIncreaseSubsequence(vec);
    cout << len << endl;


}
