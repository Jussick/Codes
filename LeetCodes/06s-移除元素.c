#include<stdio.h>
/**
* 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
* 
* 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
* 
* 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
* 
* 示例 1:
* 
* 给定 nums = [3,2,2,3], val = 3,
* 
* 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
* 
* 你不需要考虑数组中超出新长度后面的元素。
* 示例 2:
* 
* 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
* 
* 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
* 
* 注意这五个元素可为任意顺序。
* 
* 你不需要考虑数组中超出新长度后面的元素。
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
int removeElement(int* nums, int numsSize, int val) {
	BubbleSort(nums, numsSize);
	int i ,count = 0, start;
	for (i = 0; i < numsSize; i++) printf("%d ", nums[i]); printf("\n");
	for (i = 0; i < numsSize; i++) if (nums[i] == val) { start = i; break; }
	for (i = 0; i < numsSize; i++) if (nums[i] == val) count++;

	for (i = start; i < numsSize-count; i++)
	{
		nums[i] = nums[i+count];
	}

	return numsSize - count;
}

int main()
{
	int nums[13] = {0,4,4,0,4,4,4,0,2,5,6,6};
	int val = 0;
	int numsSize = 12;
	int returnSize = removeElement(nums, numsSize, val);
	int i;
	for (i = 0; i < returnSize; i++) printf("nums[%d] = %d\n", i, nums[i]);

	return 0;
}
