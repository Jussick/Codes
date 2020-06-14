//C++ file
/***********************************************
#
#      Filename: 32-搜索插入位置.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

                你可以假设数组中无重复元素。

                示例 1:

                输入: [1,3,5,6], 5
                输出: 2
                示例 2:

                输入: [1,3,5,6], 2
                输出: 1
                示例 3:

                输入: [1,3,5,6], 7
                输出: 4
                示例 4:

                输入: [1,3,5,6], 0
                输出: 0
#        Create: 2020-05-03 09:06:14
#**********************************************/
#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int i;
        for (i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= target)
                return i;
        }
        return i;
    }
};

static void printVec(std::vector<int> &vec)
{
    std::cout << "vec is: ";
    for ( auto item : vec )
        std::cout << item << " ";
    std::cout << std::endl;
}

int main()
{
    Solution obj;
    std::vector<int> vec{1,3,5,7};
    printVec(vec);
    std::cout << "Insert 8, pos: ";
    std::cout << obj.searchInsert(vec, 8) << std::endl;
    std::cout << "Insert 4, pos: ";
    std::cout << obj.searchInsert(vec, 4) << std::endl;


}
