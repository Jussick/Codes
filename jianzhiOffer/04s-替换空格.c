//C file
/***********************************************
#
#      Filename: 04-替换空格.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 把一个字符串中的空格都替换成其ASCII码%32, 原地替换
				 从后往前替换的效率高
#        Create: 2018-08-28 10:35:09
#**********************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void replaceBlank(char *str, int len)
{
	if (str == NULL || len <= 0)
		return;

	// 首先遍历字符串，求出空格个数
	int i;
	int blankNum = 0;
	for (i = 0; i <= len; i++)
	{
		if (isspace(str[i]))
			blankNum++;
	}

	char *p1 = str + len; // p1指向原始字符串的结尾
	len += 2 * blankNum;	
	char *p2 = str + len;  // p2指向替换后字符串的结尾

	// 当两指针不相等时，说明还有空格没被替换
	while (p1 != p2)
	{
		if (!isspace(*p1))  // 不是空格，则按位从p1拷贝到p2
		{
			*p2 = *p1;
			p1--;
			p2--;
		}
		else  // 是空格，则把其替换为%32，注意：p2要向前移动三次，p1只需向前移动一次
		{
			*p2 = '2';
			p2--;
			*p2 = '3';
			p2--;
			*p2 = '%';
			p2--;
			p1--;
		}
	}

}

int main()
{
	char str[50] = "we are the world wowow.";
	replaceBlank(str, strlen(str)+1);  // 加一是为了算上结尾的\0符
	printf("%s\n", str);
	return 0;
}
