//C++ file
/***********************************************
#
#      Filename: 12-两个排序数组的中位数.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 
			给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

			请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

			你可以假设 nums1 和 nums2 不同时为空。

			示例 1:

			nums1 = [1, 3]
			nums2 = [2]

			中位数是 2.0
			示例 2:

			nums1 = [1, 2]
			nums2 = [3, 4]

			中位数是 (2 + 3)/2 = 2.5
#        Create: 2018-10-12 16:54:14
#**********************************************/
#include<iostream>
#include<vector>

using namespace std;

// 打印矢量
void PrintVector(vector<int> &vec)
{
	for(auto it = vec.begin(); it != vec.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

// 升序合并两个vector
vector<int> MergeTwoVectorInOrder(const vector<int>& nums1, const vector<int>& nums2)
{
	vector<int> merged;
	auto it1 = nums1.begin(); 
	auto it2 = nums2.begin();

	while (1)
	{
		if (it1 == nums1.end() || it2 == nums2.end())
			break;
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
	if (it1 == nums1.end() && it2 != nums2.end())
		for (; it2 != nums2.end(); ++it2)
			merged.push_back(*it2);
	else if (it1 != nums1.end() && it2 == nums2.end())
		for (; it1 != nums1.end(); ++it1)
			merged.push_back(*it1);
	PrintVector(merged);
	return merged;
}


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> merged = MergeTwoVectorInOrder(nums1, nums2);
		int size = merged.size();
		if (size > 1)
		{
			if (size % 2 != 0)  // 奇数个情况       
			{
				int pos = size / 2;
				return merged[pos];					
			}
			else if (size % 2 == 0)
			{
				int pos1 = size / 2;	
				int pos2 = size / 2 - 1;	
				cout << merged[pos1] << " " << merged[pos2] << endl;
				double median = ((merged[pos1]*1.0) + (merged[pos2]*1.0)) / 2;  // int乘以1.0后自动变成double
				return median;
			}
		}
		else  // 只有一个数的情况
		{
			return merged[0];
		}
    }
};

int main()
{
	vector<int> vec1{1,2,5};
	vector<int> vec2{3,4,6};
	Solution ss;
	double ret = ss.findMedianSortedArrays(vec1, vec2);
	cout << ret << endl;

	return 0;
}
