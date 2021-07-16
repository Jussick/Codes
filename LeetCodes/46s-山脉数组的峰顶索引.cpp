//C++ file
/***********************************************
#
#      Filename: 46-山脉数组的峰顶索引.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 符合下列属性的数组 arr 称为 山脉数组 ：
            arr.length >= 3
            存在 i（0 < i < arr.length - 1）使得：
            arr[0] < arr[1] < ... arr[i-1] < arr[i]
            arr[i] > arr[i+1] > ... > arr[arr.length - 1]
            给你由整数组成的山脉数组 arr ，返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。
#        Create: 2021-06-15 22:43:08
#**********************************************/
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

class Solution {  // O(1)的解法
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int index = 0;
       int max = arr[0];

       for (int i = 1; i < arr.size(); ++i)
       {
           if (arr[i] > max)
           {
               max = arr[i];
               index = i;
           }
       }
       return index;
    }
};

class Solution2 {  // O(logn)的解法
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int ans = 0;
       int len = arr.size();
       int left = 1, right = len-2;

       while (left <= right)
       {
            int mid = (left+right)/2;
            if (arr[mid] > arr[mid+1])
            {
                ans = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
       }
       return ans;
    }
};

int main()
{
    Solution2 ss;
    vector<int> arr = {1,3,5,8,5,4,3,2,1};
    int index = ss.peakIndexInMountainArray(arr);
    cout << index << endl;
}
