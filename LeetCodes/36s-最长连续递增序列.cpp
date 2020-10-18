//C++ file
/***********************************************
#
#      Filename: 36-最长连续递增序列.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 

给定一个未经排序的整数数组，找到最长且连续的的递增序列，并返回该序列的长度。

 

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#        Create: 2020-10-07 16:52:53
#**********************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }

        int tempLen = 1;
        int maxLen = 1;
        for (size_t i = 0; i < nums.size()-1; ++i)
        {
            if (nums[i+1] > nums[i]) 
            {
                tempLen++;
            }
            else
            {
                tempLen = 1;
            }
            if (maxLen < tempLen)
                maxLen = tempLen;
        }
        return maxLen;
    }
};

int main()
{
    Solution ss;
    vector<int> vv = {1, 2, 5, 4, 7, 8, 9, 10};
    int len = ss.findLengthOfLCIS(vv);
    cout << len << endl;
}
