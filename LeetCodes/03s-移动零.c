#include<stdio.h>
/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/
void printArray(int *arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void moveZeroes(int* nums, int numsSize) {
	int i = 0, j;
	while (i < numsSize)
	{
		printf("numsSize=%d\n", numsSize);
		printf("num[%d]=%d\n", i, nums[i]);
		if (*(nums+i) == 0)
		{
			printf("i = %d\n", i);
			for (j = i; j < numsSize-1; j++)
			{
				*(nums+j) = *(nums+j+1);
			}
			*(nums+j) = 0;
			numsSize--;
			i = 0;  // 重点!!!
		}
		else
			++i;
	}
}

int main()
{
	int nums[10] = {0, 0, 1};	
	int numsSize = 3;
	moveZeroes(nums, numsSize);

	printArray(nums, numsSize);

	return 0;
}


