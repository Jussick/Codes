//C file
/***********************************************
#
#      Filename: 09-s斐波那契数列.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 求斐波那契数列的第n项
				 三种方法：
				 	1、迭代法
					2、递归法
					3、动态规划法
				并比较三种的计算时间
#        Create: 2018-09-12 10:42:50
#**********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long long int helper(int n, int *memo)
{
	if (n <= 1)
		return n;
	else
	{
		long long int x, y;
		if (memo[n-1] != -1)
			x = memo[n-1];
		else
		{
			x = helper(n-1, memo);
			memo[n-1] = x;
		}
		if (memo[n-2] != -1)
			y = memo[n-2];
		else
		{
			y = helper(n-2, memo);
			memo[n-2] = x;
		}

		return x + y;
	}
}

/* 动态规划方法 */
long long int Fibonacci_DP(int n)
{
	int *memo = (int *)calloc(n + 1, sizeof(int));
	memo[0] = 0, memo[1] = 1;
	for (int i = 2; i < 1001; ++i)
		memo[i] = -1;
	long int result = helper(n, memo);
	free(memo);
	return result;
}


/* 递归方法 */
long long Fibonacci_recursive(unsigned int n)
{
	int result[2] = {0, 1};
	if (n < 2)	
		return result[n];
	return Fibonacci_recursive(n-1) + Fibonacci_recursive(n-2);
}

/* 迭代方法 */
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
	unsigned int n = 41;

	clock_t iter_start_time = clock();
	printf("Fibonacci[%u] is %lld\n", n, Fibonacci(n));  
	clock_t iter_end_time = clock();
	printf("Fibonacci_iter time consume: %f\n\n", (double)(iter_end_time - iter_start_time) / CLOCKS_PER_SEC);

	clock_t DP_start_time = clock();
	printf("Fibonacci_DP[%u] is %lld\n", n, Fibonacci_DP(n));
	clock_t DP_end_time = clock();
	printf("Fibonacci_DP time consume: %f\n\n", (double)(DP_end_time - DP_start_time) / CLOCKS_PER_SEC);

	clock_t recur_start_time = clock();
	printf("Fibonacci_recursive[%u] is %lld\n", n, Fibonacci_recursive(n));
	clock_t recur_end_time = clock();
	printf("Fibonacci_recursive time consume: %f\n\n", (double)(recur_end_time - recur_start_time) / CLOCKS_PER_SEC);

	return 0;
}
