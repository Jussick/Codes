//C file
/***********************************************
#
#      Filename: 07-连续整数求和.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 
给定一个正整数 N，试求有多少组连续正整数满足所有数字之和为 N?

示例 1:

输入: 5
输出: 2
解释: 5 = 5 = 2 + 3，共有两组连续整数([5],[2,3])求和后为 5。
示例 2:

输入: 9
输出: 3
解释: 9 = 9 = 4 + 5 = 2 + 3 + 4
示例 3:

输入: 15
输出: 4
解释: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
说明: 1 <= N <= 10 ^ 9
#        Create: 2018-08-01 20:27:57
#**********************************************/
#include<stdio.h>
#include<math.h>

/* 这种解法的问题：暴力破解,时间效率低 */
int consecutiveNumbersSum_overtime(int N) {
	int i, j;
	int base;
	int sumValue;
	int total_num = 0;
	if (N > 10)
	for (i = 1; i < N; i++)
	{
		base = i;
		for (j = i + 1; j < N; j++)
		{
			sumValue = (base+=j);
			if (sumValue < N)
				continue;
			else if (sumValue == N)
			{
				total_num++;
				printf("first_item:%d\tlast_item:%d\n", i, j);	
				break;
			}
			else
				break;
		}
	}
	return total_num + 1;
}

int consecutiveNumbersSum(int N) {
	int total_num = 0;
	double goal = 2 * N;	
	int limit = sqrt(goal) + 1;

	int first_item, last_item;
	for (first_item = 1; first_item <= limit; first_item++)
	{
		for (last_item = first_item + 1; last_item <= N/2; last_item++)
		{
			if ( (first_item + last_item) * (last_item - first_item + 1) == (int)goal )
			{
				printf("first_item:%d\tlast_item:%d\n", first_item, last_item);	
				total_num++;
			}
		}
	}
	return total_num + 1;
}

int consecutiveNumbersSum_right(int N) {
    int ans = 1;
    int x = 2 * N;
    int index = (int)sqrt(x);
	int i;
    for(i = 2;i <= index;i++){
        if(x % i == 0){
            double n2 = (i + x/i - 1)/2;
            double n1 = x / i - n2;
            if(n1 < n2 && (int)n1 == n1 && (int)n2 == n2)
                if ((n1 + n2) * (n2 - n1 + 1) == x) 
                    ans++;
        }
    }
    return ans;
}

int main()
{
	int N;
	int result;
	printf("input N:");
	while( scanf("%d", &N) != EOF)
	{
		result = consecutiveNumbersSum_right(N);
		printf("result is %d\n", result);
		printf("input N:");
	}

	return 0;
}
