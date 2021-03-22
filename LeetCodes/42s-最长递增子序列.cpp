//C++ file
/***********************************************
#
#      Filename: 5-最长递增子序列.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: leetcode,300:最长上升子序列
                 参考：https://github.com/labuladong/fucking-algorithm/blob/master/动态规划系列/动态规划设计：最长递增子序列.md
#        Create: 2020-12-07 15:31:30
#**********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // 初始化dp数组
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); ++i)
        {
            dp[i] = 1;
        }

        // 计算dp数组的每个元素值, dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度(套路)
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        // 返回dp数组中最大的
        auto position = max_element(dp.begin(), dp.end());
        return *position;

    }
};

int main()
{
    vector<int> vec = {1,5,3,4,8,6,7,9};
    Solution ss;
    int res = ss.lengthOfLIS(vec);
    cout << "res: " << res << endl;
}
