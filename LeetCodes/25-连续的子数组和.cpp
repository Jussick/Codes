//C++ file
/***********************************************
#
#      Filename: 25-连续的子数组和.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 给定一个包含非负数的数组和一个目标整数 k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。

示例 1:

输入: [23,2,4,6,7], k = 6
输出: True
解释: [2,4] 是一个大小为 2 的子数组，并且和为 6。
示例 2:

输入: [23,2,6,4,7], k = 6
输出: True
解释: [23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
说明:

数组的长度不会超过10,000。
你可以认为所有数字总和在 32 位有符号整数范围内。
#        Create: 2019-03-25 14:39:07
#**********************************************/
#include<iostream>
#include<vector>
#include <unistd.h>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
		size_t size = nums.size();
		// 输入有效性校验
		if (size == 0 || k <= 0) {
			return false;
		}

		size_t i, j, cur;
		int sum = 0;
		vector< vector<int> > temp(size);  // 保存中间值的二维数组	

		// 把中间量二维数组全部初始化为-1
		for (i = 0; i < nums.size(); ++i) { 
			temp[i].resize(size); 
			for (j = 0; j < size; ++j) {
				temp[i][j] = -1;
			}
		}
		
		// 计算求和并判断是否符合条件
		for (i = 0; i < size - 1; ++i) {
			sum = nums[i];
			for (j = i + 1; j < size; ++j) {
				sum += nums[j];
				temp[i][j] = sum;
				if (sum == k || sum % k == 0) {
					cout << "bingo situation: i=" << i << ", j=" << j << 
						", sum:" << sum << endl;
					return true;
				}
			}
		} 	

		return false;
    }
};


int main() {

	vector<int> vec{21, 2, 4, 6, 7};

	for (int i: vec) cout << i << " ";
	cout << endl;

	Solution s;
	bool res = s.checkSubarraySum(vec, 6);

	cout << "res: " << (res == true?"true":"false") << endl;
	return 0;
}
