//C++ file
/***********************************************
#
#      Filename: 22-按奇偶排序数组.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 
				给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。

				你可以返回满足此条件的任何数组作为答案。
				
				 
				
				示例：
				
				输入：[3,1,2,4]
				输出：[2,4,3,1]
				输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
				 
				
				提示：
				
				1 <= A.length <= 5000
				0 <= A[i] <= 5000
#        Create: 2019-01-21 10:57:30
#**********************************************/
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<time.h>

using namespace std;

bool isEven(int num) {
	//return num == 0 || (num %= 2) == 0;
	return (num & 1) == 0;  // 利用这种判断奇偶的方式能够提升效率
}


template <class T> 
void swap(T *a, T *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}
vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

class Solution {
public:
	/* slow, only beyond 3.91% */
    vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> even_vec;
		vector<int> odd_vec;
		for (size_t i = 0; i < A.size(); ++i) {
			if (isEven(A[i])) 
				even_vec.push_back(A[i]);	
			else
				odd_vec.push_back(A[i]);
		}	
		vector<int> final_vec;
		for (size_t i = 0; i < even_vec.size(); ++i) 
			final_vec.push_back(even_vec[i]);
		for (size_t i = 0; i < odd_vec.size(); ++i) 
			final_vec.push_back(odd_vec[i]);

		return final_vec;
    }

    vector<int> sortArrayByParity2(vector<int>& A) {
		size_t i = 0;
		for (size_t j = 0; j < A.size(); ++j) {
			if (isEven(A[j])) {
				if (i != j) {  					
					cout << "exchange between A[" << i << "] and A[" << j << "]" << endl;
					swap(&A[i], &A[j]);
					i++;
				}
				else  // 自己和自己无需交换,仅将指针指向下一位即可。
					i++;
			}
		}
		return A;
	}
};


int main() {
#ifndef TEST
	// 正式代码
	string ss;
	while (getline(cin, ss)) {
		vector<int> test = stringToIntegerVector(ss);
		Solution ss;
		clock_t start = clock();
		vector<int> fff = ss.sortArrayByParity2(test);
		clock_t end = clock();
		double time_consume  = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "time consume is " << time_consume << endl;
		for (auto iter = fff.begin(); iter != fff.end(); ++iter) {
			cout << *iter << " ";
		}
		cout << endl;
	}
#else
	// 测试代码
	string ss;
	cin >> ss;
	vector<int> vv = stringToIntegerVector(ss);
	for (auto iter = vv.begin(); iter != vv.end(); ++iter) {
		cout << *iter << " ";
	}

#endif
	return 0;
}
