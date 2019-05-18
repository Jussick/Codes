//C file
/***********************************************
#
#      Filename: 03-是否为子序列.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 判断target串是否为src串的子序列
#        Create: 2019-04-20 00:20:02
#**********************************************/
#include <stdio.h>
#include <unistd.h>
#include <string.h>


/***********************************************
#      函数名称: isSubSequence
#
#   Description: 判断一个字符串是否为另一个字符串的子序列
#     parameter: 
				src: 源串
				target: 目标串
#   returnValue: 
				0: 不是子序列
				1：是子序列
#   	 Author: luhg
#        Create: 2019-04-20 12:59:19
#**********************************************/
int isSubSequence(const char *src, const char *target) {
	// 有效性校验
	if (src == NULL) { return 0; }
	if (target == NULL) {return 1; }

	int src_len = strlen(src);
	int target_len = strlen(target);
	if (src_len == 0) {return 0;}
	if (target_len == 0) {return 1;}

	int result = 0, pos = 0;   // result是返回的结果，pos指向比较到的src串的位置
	int i, j; 

	for (i = 0; i < target_len; ++i) {
		for (j = pos; j < src_len; ++j) {
			if (src[j] == target[i]) {
				pos = j;
				break;
			}
		}

		if (j == src_len)   // 比较到源串的末尾，break
			break;
	}

	// 如果两者比较完毕后，子串的指针指向了最后，说明都找到了
	if (i == target_len) result = 1;

	return result;

}

int main() {
	char src[100], target[100];
	printf("Input src:");	
	scanf("%s", src);
	printf("\nInput target:");	
	scanf("%s", target);
	int result = isSubSequence(src, target);

	printf("%s\n", result == 1?"yes":"no");
	return 0;
}
