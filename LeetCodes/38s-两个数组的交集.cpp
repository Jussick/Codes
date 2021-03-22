//C++ file
/***********************************************
#
#      Filename: 1-两个数组的交集.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 寻找性能更好的方法
#        Create: 2020-06-24 16:21:52
#**********************************************/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());

        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), insert_iterator<vector<int> >(res, res.begin()));
        return res;
    }
};

void PrintNums(int num)
{
    cout << num << " ";
}

int main()
{
    Solution ss;

    vector<int> nums1 = {1, 2, 2, -1};
    vector<int> nums2 = {2, 2};

    vector<int> res = ss.intersection(nums1, nums2);
    
    for_each(res.begin(), res.end(), PrintNums);
    cout << endl;

}
