//C file
/***********************************************
#
#      Filename: rotateString.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 在牛客网上的题 
对于一个字符串，和字符串中的某一位置，请设计一个算法，将包括i位置在内的左侧部分移动到右边，将右侧部分移动到左边。
给定字符串A和它的长度n以及特定位置p，请返回旋转后的结果。

测试样例：
"ABCDEFGH",8,4
返回："FGHABCDE"

#        Create: 2019-03-21 17:29:28
#**********************************************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXLEN 1024 


void RotateString(char *str, int len, int pos) {
	// 先做有效性校验
	if (str == NULL || len <= 0 || pos > len || pos < 0)
		return;

	char *substr1 = (char *)calloc(1, len);	
	char *substr2 = (char *)calloc(1, len);	
	char *p = str;
	int i;

	// 分别把两部分放到两个字符串中，再合成结果
	for (i = 0; i < len; ++i) {
		if (i <= pos) {
			memcpy(substr2 + i, p, 1);
		}
		else
			memcpy(substr1 + i - pos - 1, p, 1);
		++p;
	}

	//printf("str1:%s\nstr2:%s\n", substr1, substr2);

	sprintf(str, "%s%s", substr1, substr2);

	free(substr1);
	free(substr2);

}


int main() {
	char *str = (char *)calloc(1, MAXLEN);
	strcpy(str, "ABCDEFGH");

	int len = strlen(str);	
	int pos = 0;

	RotateString(str, len, pos);
	printf("result:%s\n", str);

	free(str);
	return 0;
}
