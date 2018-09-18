//C file
/***********************************************
#
#      Filename: 10s-位运算.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 求一个整数的二进制表示有几个1
#        Create: 2018-09-13 14:15:27
#**********************************************/
#include<stdio.h>
#include<stdlib.h>


/* 第一种方法 (不正确)
 * 		让num和1做与运算，若结果为1说明最右面的一位是1；
 * 		再把输入的数字右移一位(1100右移一位结果是0110)，再和1做与运算，直到num为0为止
 * 缺陷：
 * 		1、num有多少位2进制，循环就要进行多少次
 * 		2、当num为负数时，会陷入死循环, 因为负数的二进制表示首位是1，右移
 * 		   操作时为保证移位后仍是负数，移位后最高为会设成1，故会死循环。
 * */
int NumOf1_bad(int num)
{
	int count = 0;
	while (num)
	{
		if ((num & 1) == 1)
			++count;
		num >>= 1;  // 右移一位
	}
	return count;
}

/* 第二种方法 (常规方法)
 * 		为防止输入负数陷入死循环，不对输入的num进行右移，
 * 		而对另一个数flag进行左移，每次和num相与作比较即可；
 * 缺陷：
 * 		循环次数等于二进制的位数
 * */
int NumOf1_normal(int num)
{
	int count = 0;
	int flag = 1;
	while (flag)
	{
		if (flag & num)
			++ count;
		flag <<= 1;  // flag左移一位
	}
	return count;
}


/* 第三种方法 (好方法)
 * 	前提：
 * 		把一个整数减去一，再和原整数做与运算，就会把该
 * 		整数的最右面一位1变成0
 * 	方法：
 * 		即用上面的前提，减少了循环的次数
 * 		当输入为负数时不会死循环
 * 	优点：循环次数是1的个数
 * */
int NumOf1_good(int num)
{
	int count = 0;
	while (num)
	{
		++ count;
		num = num & (num - 1);
	}
	return count;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s %s\n", argv[0], "[num]");
		return -1;
	}
	printf("%d\n", NumOf1_good(atoi(argv[1])));	
	printf("%d\n", NumOf1_normal(atoi(argv[1])));	
	//printf("%d\n", NumOf1_bad(atoi(argv[1])));	
	return 0;
}
