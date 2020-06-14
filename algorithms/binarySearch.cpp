//C++ file
/***********************************************
#
#      Filename: binarySearch.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 实现了二分查找的三种情况：正常、左边界、右边界
                 讲解文章：https://github.com/labuladong/fucking-algorithm
#        Create: 2020-03-19 14:09:05
#**********************************************/
#include <iostream>
#include <vector>

using namespace std;

/* 标准的二分查找(有序数组)，找到返回元素下表，找不到返回-1 */
/* 缺点：若数组中有重复元素，无法定位到左侧边界或右侧边界 */
int binarySearch(vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)  // 搜索区间：[left, right]
    {
        int mid = left + (right - left) / 2;  // 和left+right/2效果一样，不过可以防止溢出
        // cout << "left " << left << ", right " << right << ", mid " << mid << endl;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
    }
    return -1;
}

/* 二分查找目标所在的左边界 */
int left_bound(vector<int> arr, int target)
{
    int left = 0, right = arr.size()-1;

    while (left <= right)  // 搜索区间：[left, right]
    {
        int mid = (left + right) / 2;
        cout << "left " << left << ", right " << right << ", mid " << mid << endl;
        if (arr[mid] == target)
        {
            right = mid - 1;  // 注意：此时不着急返回，而是缩小搜索区间，让结果向左缩小(这里由于搜索区间是左闭右闭，故要减一)
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; 
        }
    }
    // 搜索不到时
    if (left >= arr.size() || arr[left] != target)   // 第一个判断是防止当target大于数组中所有数字时，第二个判断越界
    {
        return -1;
    }
    return left;  // 注意,return的是左边界。返回的是target的左边界，同时可以看成是数组中有几个数字小于target。如target=3，left=2，意思即数组中有两个数字小于3
}


/* 二分查找目标所在的右边界 */
int right_bound(vector<int> arr, int target)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            left = mid + 1;
        }
        else if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
    }
    if (right < 0 || arr[right] != target)  // 当target比数组所有数字小时，right会向左越界，故再此要做判断
    {
        return -1;
    }
    return right;
}

int main()
{
    int arr[10] = {1,2,3,6,6,6,7,8,9,0};  // 二分查找的数组要是增序的
    vector<int> vv(arr, arr+10);

    int index = binarySearch(vv, 6);
    int index_left = left_bound(vv, 6);
    int index_right = right_bound(vv, 6);

    cout << "binarySearch index of target: " << index << endl;
    cout << "left_bound index of target  : " << index_left << endl;
    cout << "right_bound index of target : " << index_right << endl;


    return 0;
}
