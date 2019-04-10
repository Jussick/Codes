//C++ file
/***********************************************
#
#      Filename: 31-连续子数组的最大和.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: O(n)的方法只需遍历一遍数组，从头加到尾，每次相加的前后进行判断
#        Create: 2019-03-25 10:40:43
#**********************************************/
#include<iostream>
#include<vector>

using namespace std;

int findMaxSumOfSubArray(vector<int> &vec) {
	if (!vec.size()) {
		cout << "input error" << endl;
		return -1;
	}

	int curSum = 0;
	int maxSum = 0;
	for (size_t i = 0; i < vec.size(); ++i) {
		if (curSum < 0) { curSum = 0; }

		curSum += vec[i];	
		if (i == 0) {maxSum = curSum; }
		if (curSum > maxSum) { maxSum = curSum; }

	}	
	return maxSum;
}

int main() {
	vector<int> vec = {1, -2, 3, 10, -4, 7, 2, -5};
	//vector<int> vec = {-1, -1, -1};
	int maxsum = findMaxSumOfSubArray(vec);
	cout << maxsum << endl;

	return 0;
	
}
