//C file
/***********************************************
#
#      Filename: test.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-04-28 20:00:39
#**********************************************/
#include "mysock.h"

int main() {

	int dec;
	char hex[32];

	printf("input a decimal: ");
	scanf("%d", &dec);

	memcpy(hex, "0x", 2);
	snprintf(hex+2, 5, "%04X", dec);  // snprintf的第二个参数赋值的位数，包含了最后的'\0'，故要在想转换的位数上+1

	printf("convert to hex: %s\n", hex);

	long int res = strtol(hex+2, NULL, 16);
	printf("convert back to decimal: %ld\n", res);

	//int i;
	//for (i = 0; i < res; ++i)
	//	printf("i=%d\n", i);


	return 0;
}
