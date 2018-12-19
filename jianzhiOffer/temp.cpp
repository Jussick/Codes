#include<iostream>
#include<ctime>
#include "include/list.h"

using namespace std;



long int Fibbonacci(int n, int *memo)
{
	if (n <= 1)
		return n;
	else
	{
		long int x, y;
		if (memo[n-1] != -1)
			x = memo[n-1];
		else
		{
			x = Fibbonacci(n-1, memo);
			memo[n-1] = x;
		}
		if (memo[n-2] != -1)
			y = memo[n-2];
		else
		{
			y = Fibbonacci(n-2, memo);
			memo[n-2] = x;
		}

		return x + y;
	}
}

long int enhanced_version(int n)
{
	int *memo = (int *)calloc(1000, sizeof(int));
	memo[0] = 0, memo[1] = 1;
	for (int i = 2; i < 1001; ++i)
		memo[i] = -1;
	long int result = Fibbonacci(n, memo);
	free(memo);
	return result;
}

int main()
{
	int N = 40;
	clock_t recur_fib_start_time = clock();
	long int result = enhanced_version(N);
	clock_t recur_fib_end_time = clock();
	cout << result << endl;
	printf("time consume: %f\n", (double)(recur_fib_end_time - recur_fib_start_time) / CLOCKS_PER_SEC);
	return 0;
}
