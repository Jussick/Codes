//C file
/***********************************************
#
#      Filename: 09-s斐波那契数列.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 求斐波那契数列的第n项
#        Create: 2018-09-12 10:42:50
#**********************************************/
#include<stdio.h>

long long Fibonacci_recursive(unsigned int n)
{
	int result[2] = {0, 1};
	if (n < 2)	
		return result[n];
	return Fibonacci_recursive(n-1) + Fibonacci_recursive(n-2);
}

long long Fibonacci(unsigned int n)  // 当n在40左右时，效率明显快于递归方法
{
	int result[2] = {0, 1};
	if (n < 2)	
		return result[n];
	long long fibOne = 1;
	long long fibTwo = 0;
	long long fibN = 0;

	unsigned int i;
	for (i = 2; i <= n; ++i)
	{
		fibN = fibOne + fibTwo;
		fibTwo= fibOne;
		fibOne= fibN;
	}
	return fibN;
}

int main()
{
	unsigned int n = 40;
	printf("Fibbonacci[%u] is %lld\n", n + 1, Fibonacci(n));  
	printf("Fibbonacci_recursive[%u] is %lld\n", n + 1, Fibonacci_recursive(n));
	return 0;
}
