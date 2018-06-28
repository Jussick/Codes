#include<stdio.h>
#include<stdlib.h>
/*两数之和
	给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

	你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:

	给定 nums = [2, 7, 11, 15], target = 9

	因为 nums[0] + nums[1] = 2 + 7 = 9
	所以返回 [0, 1]
*/

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
int* twoSum(int* nums, int numsSize, int target) {
	int i, j;	    
	int flag = 0;
	int *returnArr = (int *)malloc(sizeof(int) * 2);
	printf("target=%d\n", target);
	for (i = 0; i < numsSize -1; i++)
	{
		if (flag == 1) break;
		for (j = i+1; j <= numsSize -1; j++)
		{
			printf("----i=%d\tj=%d-----\n", i, j);
			printf("nums[i]=%d\tnums[j]=%d\n", *(nums+i), *(nums+j));
			if ((*(nums+i) + *(nums+j)) == target)
			{
				printf("equal!\n");
				returnArr[0] = i;
				returnArr[1] = j;
				flag = 1;
				break;
			}
		}
	}
	//printf("%d\t%d\n", returnArr[0], returnArr[1]);
	return returnArr;
}


int main()
{
	int nums[10] = {2,7,11,15, 2, 1};
	//int *result = (int *)malloc(sizeof(int) * 2);
	int target = 12;
	int *result = twoSum(nums, 6, target);	
	printf("nums[%d] + nums[%d] = %d\n",result[0], result[1], target);
	free(result);

	return 0;
}
