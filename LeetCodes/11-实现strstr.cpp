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

using namespace std;

int strStr(char* haystack, char* needle) 
{
	if (needle == NULL)
	{
		cout << "substring is null" << endl;
		return 0;	
	}
	char *pBase = haystack;  // 指向串的指针
	char *pSearch = needle;  // 指向查找串的指针

	for (int i = 0; pBase[i] != '\0'; ++i)
	{
		
	}
}

int main()
{
			
}
