//C++ file
/***********************************************
#
#      Filename: 29-数组中出现次数超过一半的数字.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-03-06 14:51:14
#**********************************************/
#include<iostream>

using namespace std;
bool checkIfMoreThanHalf(int *arr, int length, int val);


/* 自己的解法：先排序，再找出中间的数字 */
template <class T>
T swap(T *a, T *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

template <typename NumType>
void printArr(NumType *arr, int len)
{
    int i;
    if (len == 0) return;
    for (i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
        if (i == len-1) cout << endl;
    }
}

template <typename NumType>
void BubbleSort(NumType *arr, int arrSize) /* 冒泡 */
{
    int i, j;
    for (i = 0; i < arrSize-1; i++)
    {
        for (j = 0; j < arrSize-i-1; j++)
        {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);

        }
    }
}

int beyondAHalf(int *arr, int size) {
	BubbleSort(arr, size);
	printArr(arr, size);
	int val = arr[size / 2];
	if (!checkIfMoreThanHalf(arr, size, val))
		val = 0;
	return val;
}
/* 自己解法结束 */

/* 检查一个数是否在数组中出现次数超过一半 */
bool checkIfMoreThanHalf(int *arr, int length, int val) {
	bool isMoreThanHalf = true;
	int times = 0;
	for (int i = 0; i < length; ++i) {
		if (arr[i] == val)
			times ++;
	}
	if (times * 2 <= length)
		isMoreThanHalf = false;
	return isMoreThanHalf;
}

/* jianzhioffer中O(n)的解法:
 * 遍历数组，保存两个值：数组中的一个数，和该数出现的次数。
 * 当遍历下一个数时，若与前一个数相同，就把次数加一，否则减一，次数为0时，保存数组的下一个数，并把次数置为一，最后保存的数字就是出现次数超过一半的数字。
 */
int moreThanAHalf(int *arr, int length) {
	int result = arr[0];
	int times = 1;
	for (int i = 1; i < length; ++i) {
		if (arr[i] == result)
			times += 1;

		if (arr[i] != result)
			times -= 1;

		if (times == 0) {
			result = arr[i];
			times = 1;
		}
	}	
	if (!checkIfMoreThanHalf(arr, length, result))
		result = 0;
	return result;
}


int main() 
{
	int arr[10] = {1,1,2,3,2,2,4,2,2,9};
	//int val = beyondAHalf(arr, 10);
	int val = moreThanAHalf(arr, 10);
	cout << "The value is " << val << endl;
	return 0;
}
