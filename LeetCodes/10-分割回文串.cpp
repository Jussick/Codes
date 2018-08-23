//C++ file
/***********************************************
#
#      Filename: 10-分割回文串.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-23 14:07:05
#**********************************************/
/* 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

 *返回 s 所有可能的分割方案。
 *
 *示例:
 *
 *输入: "aab"
 *输出:
 *[
 *  ["aa","b"],
 *  ["a","a","b"]
 *]
 */
#include "my.h"

/* 判断是否是回文串 */
bool isPalindrome(string str_ori) {
	vector<char> str_vec;
	// 全变为小写，去掉标点符号
	for (size_t i = 0; i < str_ori.length(); i++)                            
	{   
		str_ori[i] = tolower(str_ori[i]);                                    
		if (!ispunct(str_ori[i]) && !isblank(str_ori[i]))
			str_vec.push_back(str_ori[i]);                                   
	}
	for (size_t i = 0; i < str_vec.size(); i++)                              
		cout << str_vec[i] << " ";                                           
	cout << endl;                                                            

	int len = str_vec.size();                                                
	bool equal = true;                                                       
	// 判断是否为回文
	int lim = len / 2;
	for (int i = 0; i < lim; i++)                                            
	{   
		if (str_vec[i] != str_vec[len-i-1])                                  
		{   
			equal = false;                                                   
			break;                                                           
		}                                                                    
	}
	return equal;
}

vector<vector<string>> partition(string &s) {
	vector<vector<string> > retVec;
	vector<string> tempVec;
	// 先把字符串分成单个的字符，插入到retVec第一个元素中,因为单个字符的字符串必是回文
	for (size_t i = 0; i < s.length(); i++)
	{
		//cout << "in partition i=" << i << endl;
		char singleStr[2] = {s[i], 0};
		tempVec.push_back(singleStr);
	}
	retVec.push_back(tempVec);
	return retVec;
}

int main()
{
	string str = "aab";
	vector<vector<string> > partition_vec = partition(str);
	for (size_t i = 0; i < partition_vec.size(); i++)
	{
		for (size_t j = 0; j < partition_vec[i].size(); j++)
			cout << partition_vec[i][j] << " ";
		cout << endl;
	}

	return 0;	
}
