//C++ file
/***********************************************
#
#      Filename: LCS.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: Longest Common SubSequence (最长公共子序列)
#        Create: 2018-11-28 10:45:47
#**********************************************/
#include <iostream>
#include <string>

using namespace std;



/***********************************************
#      函数名称: helper(not dynamic programming)
#
#   Description: LCS的辅助函数, 不使用动态规划
#     parameter: i1, i2是比较的起始位置，从（0，0）开始
#   returnValue: longest common subsequence
#   	 Author: luhg
#        Create: 2018-11-28 11:02:45
#**********************************************/
string helper(string s1, string s2, unsigned long int i1, unsigned long int i2)
{
	cout << "i1=" << i1 << " i2=" << i2 << endl;
	if (s1.length() == i1 || s2.length() == i2) {
		cout << "exceed length" << endl;
		return "";
	}


	// 如果比较的第一个字母相同，递归返回第一个字母加后面剩余的最长公共子序列
	if (s1[i1] == s2[i2]) {
		return s1[i1] + helper(s1, s2, i1 + 1, i2 + 1);
	}

	// 如果不同，返回下面两种结果中较长的一个
	string result;
	string resultA = helper(s1, s2, i1 + 1, i2);
	string resultB = helper(s1, s2, i1, i2 + 1);
	cout << "resultA: " << resultA << "\tresultB: " << resultB << endl;
	if (resultA.length() >= resultB.length()) 
		result = resultA;
	else
		result = resultB;
	return result;
}

/***********************************************
#      函数名称: helper_DP (use dynamic programming)
#
#   Description: LCS的辅助函数, 使用动态规划
#     parameter: i1, i2是比较的起始位置，从（0，0）开始, memo是记录LCS子问题结果的二维字符串数组
#   returnValue: longest common subsequence
#   	 Author: luhg
#        Create: 2018-12-04 19:42:41
#**********************************************/
string helper_DP(string s1, string s2, unsigned long int i1, unsigned long int i2, string **memo)
{
	if (s1.length() == i1 || s2.length() == i2) {
		return "";
	}

	// 如果结果已经在memo中，无需再次计算，直接返回
	if (!memo[i1][i2].empty())
		return memo[i1][i2];

	// 如果比较的第一个字母相同，递归返回第一个字母加后面剩余的最长公共子序列
	if (s1[i1] == s2[i2]) {
		memo[i1][i2] = s1[i1] + helper_DP(s1, s2, i1 + 1, i2 + 1, memo); 
		return memo[i1][i2];
	}

	// 如果不同，返回下面两种结果中较长的一个
	string result;
	string resultA = helper_DP(s1, s2, i1 + 1, i2, memo);
	string resultB = helper_DP(s1, s2, i1, i2 + 1, memo);
	if (resultA.length() >= resultB.length()) 
		result = resultA;
	else
		result = resultB;
	memo[i1][i2] = result;
	return result;
}
/***********************************************
#      函数名称: LCS
#
#   Description: 寻找最长公共子序列
#     parameter: s1, s2: 输入字符串
#   returnValue: 两者最长公共子序列
#   	 Author: luhg
#        Create: 2018-11-28 10:49:55
#**********************************************/
string LCS(string s1, string s2)
{
	// 初始化一个二维string数组 
	string **memo = new string*[s1.length()]; 
	for (unsigned long i = 0; i < s1.length(); ++i)
		memo[i] = new string[s2.length()];

	string lcs = helper_DP(s1, s2, 0, 0, memo);
	return lcs;  // 之前一直有illegal instruction报错就是因为这里TM的没返回字符串！
}

int main()
{
#if 1
	string one = "I've been waiting for you for too long";
    string two = "I was waiting for you for so long";

	string lcs = LCS(one, two);
	cout << "It's " << lcs << endl;
#endif

	return 0;
}
