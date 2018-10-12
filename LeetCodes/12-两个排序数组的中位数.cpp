//C++ file
/***********************************************
#
#      Filename: 12-两个排序数组的中位数.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-10-12 16:54:14
#**********************************************/
#include<iostream>
#include<vector>

using namespace std;

void MergeTwoVectorInOrder(const vector<int>& nums1, const vector<int>& nums2)
{
	vector<int> merged;
	auto it1 = nums1.begin(); 
	auto it2 = nums2.begin();

	while (it1 != nums1.end() || it2 != nums2.end())
	{
		if (*it1 <= *it2)
		{
			merged.push_back(*it1);
			++it1;
		}
		else
		{
			merged.push_back(*it2);
			++it2;
		}
	}
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if ((num1.size() + nums2.size()) % 2 != 0)  // 奇数个情况       
		{
			
		}
    }
};


