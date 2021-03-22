//C++ file
/***********************************************
#
#      Filename: 8-多数元素.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

            你可以假设数组是非空的，并且给定的数组总是存在多数元素。

            示例 1：

            输入：[3,2,3]
            输出：3


            示例 2：

            输入：[2,2,1,1,1,2,2]
            输出：2

            链接：https://leetcode-cn.com/leetbook/read/top-interview-questions/xm77tm/
#        Create: 2021-03-02 14:05:54
#**********************************************/
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];  // 由于多数元素数量大于n/2，故排序后位于中间的元素必是多数元素，就无需下面繁琐的操作了
        // int majority = nums.size() / 2;
        // int maxCount = 1;
        // int lastNum = nums[0];
        // int retVal = 0;
        // for (int i = 1; i < nums.size(); ++i)
        // {
            // if (nums[i] == lastNum) 
            // {
                // maxCount++;
                // if (maxCount > majority)
                // {
                    // retVal = nums[i]; 
                    // break;
                // }
            // }
            // else
            // {
                // maxCount = 1;
            // }
            // lastNum = nums[i];
        // }
        // return retVal;
    }
};

int main()
{
    Solution ss;
    vector<int> vec{ 2,2,1,1,1,2,2 };
    cout << "majority is : " << ss.majorityElement(vec) << endl;
}
