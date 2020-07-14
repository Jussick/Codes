//C++ file
/***********************************************
#
#      Filename: 34-最大子序和.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

      Create: 2020-06-24 00:00:03
#**********************************************/
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// 此方法的思路：当数组中上一个元素大于0时，就把当前元素加上上一个元素
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i-1] > 0)
            {
                nums[i] += nums[i-1];
            }
        }
        auto maxPosition = max_element(nums.begin(), nums.end());
        return *maxPosition;
    }
};

// 尝试用更多方法！！！！

// 动态规划法
// 对数组进行遍历：当前最大子序和为sum，结果为ans
// 如果sum<=0说明其对结果没有增益效果，需要舍弃，则将sum更新为当前遍历的数字
// 如果sum>0说明其对结果有增益效果，则将sum加上当前遍历的数字
// 每次循环比较ans和sum的值，取最大值，最后返回ans
class Solution2 {
    public:
        int maxSubArray(vector<int> &nums)
        {
            int sum = 0;
            int ans = nums[0];

            for (int num : nums)
            {
                if (sum <= 0)
                {
                    sum = num;
                }
                else
                {
                    sum += num;
                }
                ans = max(ans, sum);
            }
            return ans;
        }

};

int main()
{
    Solution2 ss2;

    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int ret = ss2.maxSubArray(nums);


    cout << ret << endl;
}

