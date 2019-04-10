//C file
/***********************************************
#
#      Filename: restrictTest.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 此程序编译要用-std=c99, 因为restrict是在c99中的
#        Create: 2018-10-12 10:34:03
#**********************************************/
#include<stdio.h>

int foo(int * restrict a, int * restrict b)
{
	*a = 5;
	*b = 6;
	return *a + *b;
}

int main()
{
	int i;
	printf("%d\n", foo(&i, &i));
	printf("%d\n", i);
	return 0;
}
