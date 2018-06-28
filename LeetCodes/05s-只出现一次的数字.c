#include<stdio.h>
#include<stdlib.h>

/*
* 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
* 
* 说明：
* 
* 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
* 
* 示例 1:
* 
* 输入: [2,2,1]
* 输出: 1
* 示例 2:
* 
* 输入: [4,1,2,1,2]
* 输出: 4
 */

void BubbleSort(int *arr, int arrSize)
{
	int i, j;	
	for (i = 0; i < arrSize-1; i++)
	{
		for (j = 0; j < arrSize-i-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				arr[j] = arr[j] ^ arr[j+1];
				arr[j+1] = arr[j] ^ arr[j+1];
				arr[j] = arr[j] ^ arr[j+1];
			}

		}
	}
}
int singleNumber(int* nums, int numsSize) {
    int i;
	int theOne;
	// Judge special case first.
	if (numsSize == 1) return nums[0];
	if (nums[0] != nums[1]) theOne = nums[0]; 
	if (nums[numsSize-1] != nums[numsSize-2]) theOne = nums[numsSize-1];
	else
	{
		printf("enter else\n");
		for (i = 1; i < numsSize-1; i++)
		{
			printf("nums[%d]=%d\n", i-1, nums[i-1]);
			printf("nums[%d]=%d\n", i, nums[i]);
			printf("nums[%d]=%d\n\n", i+1, nums[i+1]);
			if ((nums[i] != nums[i-1]) && (nums[i] != nums[i+1]))
			{
				theOne = nums[i];
				break;
			}
		}
	}
	return theOne;
}

int main()
{
	int arr[10] = {3,2,3,4,5,5,2,3,3};	
	int size = 9;
	BubbleSort(arr, size);
	int goal = singleNumber(arr, size); 	
	printf("goal = %d\n", goal);

	return 0;
}
