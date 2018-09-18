//C file
/***********************************************
#
#      Filename: 08-旋转数组的最小数字.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-09-04 16:52:58
#**********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int MinInOrder(int *arr, int length)
{
	if (arr == NULL || length <= 0)
		return -1;
	if (length == 1) return arr[0];
	int i;
	int min = arr[0];
	for (i = 1; i < length; ++i)
	{
		if (min > arr[i])	
			min = arr[i];
	}
	return min;
}

int Min(int *arr, int length)
{
	if (arr == NULL || length <= 0)
		return -1;

	int begin = 0;
	int end = length - 1;
	int mid = (begin + end) / 2;  // 中间值下标

	/* 特殊情况判断 */
	if (length == 1)  // 数组长度为1时
		return arr[0];
	if (arr[begin] < arr[end])  // 排序数组本身
		return arr[begin];
	if (arr[begin] == arr[end]   // 三个数相等, 此时无法判断中间元素处于哪个子数组, 只能用顺序方法查找最小值
			&& arr[mid] == arr[begin])
		return MinInOrder(arr, length);
	while ( (end - begin) > 1)
	{
		printf("begin=%d\tend=%d\tmid=%d\t\n", begin, end, mid);
		if (arr[mid] >= arr[begin])
			begin = mid;
		else if (arr[mid] <= arr[end])
			end = mid;
		mid = (begin + end) / 2;
		//sleep(1);
	}
	return arr[end];
}

int main()
{
	int arr[5] = {1,2,3,4,5};		
	int arr2[10] = {6,7,8,9,9,1,2,3,4,5};
	int arr3[1] = {3};
	int arr4[5] = {1,0,1,1,1};  // begin，end，mid相等的情况
	printf("Min: %d\n", Min(arr, 5));
	printf("Min: %d\n", Min(arr2, 10));
	printf("Min: %d\n", Min(arr3, 1));
	printf("Min: %d\n", Min(arr4, 5));
	return 0;
}
