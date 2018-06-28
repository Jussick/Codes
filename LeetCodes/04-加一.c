#include<stdio.h>
#include<stdlib.h>
/**
*   加一
* 
* 给定一个非负整数组成的非空数组，在该数的基础上加一，返回一个新的数组。
* 
* 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
* 
* 你可以假设除了整数 0 之外，这个整数不会以零开头。
* 
* 示例 1:
* 
* 输入: [1,2,3]
* 输出: [1,2,4]
* 解释: 输入数组表示数字 123。
* 示例 2:
* 
* 输入: [4,3,2,1]
* 输出: [4,3,2,2]
* 解释: 输入数组表示数字 4321。
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int power(int num, int powNum) // added by luhg
{
    int n = 1;
    int result = 1;
    while(n<=powNum){
        result *= num;
        n++;
    }
    return result;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	long long int digitValue = 0;
	int i;
	// transfrom array to num
	for (i = 0; i < digitsSize; i++)
	{
		digitValue += *(digits+i) * power(10, (digitsSize-i-1));	
	}
	digitValue++;
	printf("digitValue=%lld\n", digitValue);

	// get num size after +1
	if ((digitValue/power(10, digitsSize-1)) >= 10)
	{
		printf("enter if\n");
		printf("digitsSize=%d\n", digitsSize);
		*returnSize = digitsSize+1;
	}
	else 
	{
		printf("enter else\n");
		printf("digitsSize=%d\n", digitsSize);
		*returnSize = digitsSize;
	}
	printf("returnSize=%d\n", *returnSize);

	//transform num into array
	int *returnArr = (int *)calloc(*returnSize, sizeof(int));
	for (i = *returnSize - 1; i > 0; i--)
	{
		*(returnArr+i) = digitValue % 10;
		digitValue /= 10;
	}
	*(returnArr+i) = digitValue;

	return returnArr;

}

int main()
{
	int arr[13] = {9,9,9,7};	
	int arrsize = 4;
	int trueSize;

	int *returnArray = plusOne(arr, arrsize, &trueSize);
	
	int i;
	for (i = 0; i < trueSize; ++i)
	{
		printf("arr[%d] = %d\t", i, returnArray[i]);
	}
	printf("\n");

	return 0;

}

// 问题:大数就会失效
