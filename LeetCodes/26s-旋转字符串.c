//C file
/***********************************************
#
#      Filename: 26-旋转字符串.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 给定两个字符串, A 和 B。

A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。如果在若干次旋转操作之后，A 能变成B，那么返回True。

示例 1:
输入: A = 'abcde', B = 'cdeab'
输出: true

示例 2:
输入: A = 'abcde', B = 'abced'
输出: false
注意：

A 和 B 长度不超过 100。
#        Create: 2019-03-28 11:28:16
#**********************************************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXLEN 1024


/* 自己的解法，根据之前已有旋转字符串的方法而成 */

/***********************************************
#      函数名称: RotateString
#
#   Description: 旋转字符串
#     parameter: 
			len: 字符串长度
			pos: 要旋转的位置（包括该位置都移动到字符串最后）
#   returnValue: 
			str: 传出参数，原地旋转后的字符串
#   	 Author: luhg
#        Create: 2019-03-28 14:05:08
#**********************************************/
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

bool rotateString(char* A, char* B) {
	bool res = false;
	if (strlen(A) != strlen(B))
		return res;
	else if(A == NULL || strlen(A) == 0)
		res = true;

	int len = strlen(A);
	int i;

	for (i = 0; i < len; ++i) {
		RotateString(A, len, 0);
		if (!strcmp(A, B)) {
			res = true;
			break;
		}
	}
	return res;
}
/* 自己的方法结束 */


/* 另一种简洁的思路 
 *	判断两者长度是否相等，以及A+A中是否包含B
 * */
bool rotateString_better(char *A, char *B) {

	bool res = false;
	if (strlen(A) != strlen(B)) return res;

	char double_A[MAXLEN] = {0};
	sprintf(double_A, "%s%s", A, A);

	if (strstr(double_A, B)) { res = true; }

	return res;

	
}




int main() {
	char *A= (char *)calloc(1, MAXLEN);
	char *B= (char *)calloc(1, MAXLEN);
	strcpy(A, "abcde");
	strcpy(B, "cdeab");
	printf("%s\n", (rotateString_better(A, B)==true?"True":"False"));

	return 0;
}


