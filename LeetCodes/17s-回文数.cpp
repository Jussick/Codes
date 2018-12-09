//C++ file
/***********************************************
#
#      Filename: 17-回文数.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-11-13 10:26:10
#**********************************************/
#include<iostream>
#include<ctype.h>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
	bool isPhraseString(string &str_ori)
	{
		vector<char> str_vec;
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
		return equal;
	}

    bool isPalindrome(int x) {
		if (x < 0)
			return false;
    	string temp = to_string(x);    
		if (isPhraseString(temp))
			return true;
		else
			return false;
    }

	/* 不转换成字符串的判断方法 */
	bool isPalindrome_better(int x) {
		// 当数字小于0时不是回文的；而当其最后一位为0时，如果这个数不是0，也不是回文数
		if (x < 0 || (x % 10 == 0 && x != 0))
			return false;
		int remain = x;
		int reverse = 0;

		while (reverse < remain)
		{
			reverse = (reverse * 10) + (remain % 10);
			remain /= 10;
		}

		// 如遇数字长度为奇数时，如12321，最后的reverse是123，remain是12，这时需要去掉中间的数字3，即简单的/10去掉即可。
		return remain == reverse || remain == reverse / 10;
		
	}
};

int main()
{
	int a = 12321;	
	Solution s;
	if (s.isPalindrome_better(a))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}
