//C++ file
/***********************************************
#
#      Filename: 24-计数二进制字符串.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。

重复出现的子串要计算它们出现的次数。

示例 1 :

输入: "00110011"
输出: 6
解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。

请注意，一些重复出现的子串要计算它们出现的次数。

另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
示例 2 :

输入: "10101"
输出: 4
解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
注意：

s.length 在1到50,000之间。
s 只包含“0”或“1”字符。
#        Create: 2019-03-22 14:16:48
#**********************************************/
#include<iostream>

using namespace std;

// 这种方法能实现功能，但是时间超限了
#if 0
class Solution {
private:
	bool isContinued(string s) {
		int len = s.length();
		bool result = true;
		int flag = 0;
		if (len == 0) result = false;

		int diff_pos = 0;
		for (int i = 0; i < len - 1; ++i) {
			if (diff_pos != 0 && s[diff_pos] != s[i]) {
				result = false;
				break;
			}

			if (s[i] != s[i+1] && flag == 0) {
				diff_pos = i+1;	
				flag = 1;
				//cout << "diff_pos: " << diff_pos << endl;
			}
		}

		return result;
	}

public:
    int countBinarySubstrings(string s) {

		int len = s.length();
		if (len == 0) return 0;

		int match_count = 0;  // 返回的变量
		int num_0, num_1;


		for (int i = 0; i < len - 1; ++i) {
			num_0 = 0;
			num_1 = 0;
			for (int j = i; j < len; ++j) {
				if (s[j] == '0') num_0++;
				if (s[j] == '1') num_1++;

				// 判断0和1是否连续
				if (num_0 == num_1) {
					//cout << s.substr(i, j-i+1) << endl;
					if (this->isContinued(s.substr(i, j-i+1))) {
						match_count++;
						break;
					}
				}
			}	
		}

		return match_count;
    }
};
#endif

// 大神的解法，开始没看懂
class Solution {
public:
	// 一个简单的思路：用last来记录之前一种数字的个数， cur来记录当前数字的个数； 当last >= cur的时候， res ++; 
    int countBinarySubstrings(string s) {
        int last, cur, res; last = res = 0; cur = 1;
        for(size_t i=1; i<s.size(); i++){
            if(s[i] == s[i-1]) cur ++;
            else{last = cur; cur = 1;}
            if(last >= cur) res++;  // 这里为什么要这么判断呢？想不明白啊，看明白了！原来是通过连续相同的1和0的个数的组合来计算个数，如：
									// 0011，共有两种组合符合条件，01和0011，当last>=cur时，结果数加一的意思就是这个。实在是6，佩服佩服。
        }
        return res;
    }
};


int main() {
	Solution ss;
	string s = "00110011";
	int n = ss.countBinarySubstrings(s);
	cout << "n: " << n << endl;

	return 0;
}
