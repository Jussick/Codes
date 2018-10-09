//C++ file
/***********************************************
#
#      Filename: 11-实现strstr.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 实现 strStr() 函数。

		给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

		示例 1:

		输入: haystack = "hello", needle = "ll"
		输出: 2
		示例 2:

		输入: haystack = "aaaaa", needle = "bba"
		输出: -1
		说明:

		当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

		对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。 
#        Create: 2018-09-30 14:30:56
#**********************************************/
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int strStr(char* haystack, char* needle) 
{
	if (needle == NULL || !strlen(needle))
		return 0;	
	if (strlen(needle) > strlen(haystack))  // 子串长度大于原始串的情况直接返回
		return -1;
	char *pBase = haystack;  // 指向原始串的头指针
	char *pSearch = needle;  // 指向查找串的头指针
	int tempPos = 0;  // 第一处相等的位置
	int complete = 0;  // 子串与原始串比较完成的标志
	int pos = -1;  // 最后返回的位置
	unsigned long pBaseLen = strlen(pBase);
	unsigned long pSearchLen = strlen(pSearch);

	for (unsigned long i = 0; i < pBaseLen; ++i)
	{
		for (unsigned long j = 0; j < pSearchLen; ++j, ++i)
		{
			if (pBase[i] != pSearch[j])
				break;
			else
			{
				if (j == 0)
				{
					tempPos = i;		
				}
				if (j == pSearchLen - 1)
				{
					complete = 1;
					break;
				}
			}
		}
		if (complete)
		{
			pos = tempPos;
			break;	
		}
	}
	return pos;
}

int main()
{
	char a[20] = {0}; 
	char b[20] = {0};
	cout << "input original and search: " << endl;
	scanf("%s%s", a, b);
	cout << "Your inputs:" << endl << a << " " << b << endl;
	int result = strStr(a,b);
	cout << result << endl;
	return 0;
}
