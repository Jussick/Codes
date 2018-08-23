//C++ file
/***********************************************
#
#      Filename: 09-验证回文串.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-22 21:03:39
#**********************************************/
/*
 *给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 *
 *说明：本题中，我们将空字符串定义为有效的回文串。
 *
 *示例 1:
 *
 *输入: "A man, a plan, a canal: Panama"
 *输出: true
 *示例 2:
 *
 *输入: "race a car"
 *输出: false
 */
#include<iostream>
#include<cctype>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	string str_ori;
	vector<char> str_vec;
	getline(cin, str_ori);
	// 全变为小写，去掉标点符号和空格
	for (size_t i = 0; i < str_ori.length(); i++)
	{
		str_ori[i] = tolower(str_ori[i]);
		if (!ispunct(str_ori[i]) && !isblank(str_ori[i]))
			str_vec.push_back(str_ori[i]);
	}
	for (size_t i = 0; i < str_vec.size(); i++)
		cout << str_vec[i] << " ";
	cout << endl;

	int	len = str_vec.size();
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

	if (equal)
		cout << "yes\n";
	else
		cout << "no" << endl;

	return 0;
}
