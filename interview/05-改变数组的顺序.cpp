//C++ file
/***********************************************
#
#      Filename: 05-改变数组的顺序.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 字节一面题:
            // 输入：奇数位是升序，偶数位是降序
            // 输出：总体升序的数组
            void sort(vector<int> &nums) {
            }
            示例输入1: vector<int> nums1 = {30,80,60,20,90};
            示例输入2: vector<int> nums2 = {1,100,2,99,3,98,4,0};
#        Create: 2021-06-02 00:06:47
#**********************************************/
#include <iostream>
#include <vector>
using namespace std;

void printVec(const vector<int> &vec)
{
    for (int num : vec)
        cout << num << " ";
    cout << endl;
}

void sort(vector<int> &nums) {
    if (nums.size() == 0) return;

    vector<int> tempOdd;
    vector<int> tempOu;
    vector<int> temp;
    for (int i = 0; i < nums.size(); ++i)
    {
        if ((i+1) % 2 == 0)
        {
            temp.push_back(nums[i]);
        }
        else
        {
            tempOdd.push_back(nums[i]);
        }
    }

    for (int i = temp.size()-1; i >= 0; --i)
    {
        tempOu.push_back(temp[i]);
    }

    printVec(tempOu);
    printVec(tempOdd);

    int oddSize = tempOdd.size();  // 3
    int ouSize = tempOu.size();  //2
    int minLen = oddSize<=ouSize?oddSize:ouSize;

    int i = 0, j = 0;
    int pos;
    for (; ;)
    {
        if (i == oddSize || j == ouSize) break;

        if (tempOdd[i] <= tempOu[j])
        {
            nums[i+j] = tempOdd[i];
            i++;
        }
        else 
        {
            nums[i+j] = tempOu[j]; 
            j++;
        }
    }
    pos = i+j;
    if (i != oddSize)
    {
        for (int k = i; k < oddSize; ++k)
        {
            nums[pos++] = tempOdd[k];
        }
    }
    if (j != ouSize)
    {
        for (int k = j; k < ouSize; ++k)
        {
            nums[pos++] = tempOu[k];
        }
    }
}

int main() {
    vector<int> nums1 = {30,80,60,20,90};
    sort(nums1);
    printVec(nums1);
}
