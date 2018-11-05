//C++ file
/***********************************************
#
#      Filename: 14-使奇数位于偶数前.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 还可以在解藕上做优化，如把交换的判断条件封装成一个函数，这样以后在增加要求时就无须再对reorderEvenAndOdd（）做变动，达到解藕的效果。 
#        Create: 2018-10-31 19:14:35
#**********************************************/
#include<iostream>
#include<cmath>

using namespace std;

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

template <class T> 
void swap(T *a, T *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

bool isOdd(int x)
{
	if (x == 0)
		return false;
	else
		return abs(x % 2) == 1 ? true : false;
}

bool isEven(int x)
{
	if (x == 0)
		return true;
	else
		return abs(x % 2) == 1 ? false : true;
}

void reorderEvenAndOdd(int *arr, unsigned int length)
{
	if (arr == NULL || length == 0)
		return;
	int *head = arr;
	int *tail = &arr[length - 1];

	while (tail > head)
	{
		// head向右移直到指向偶数
		while (head < tail && isOdd(*head))
			head ++;
		// tail向前移直到指向奇数
		while (tail > head && isEven(*tail))
			tail --;
		if (head < tail)
			swap(head, tail);	
		else 
			break;
	}
}

int main()
{
	int arr[5] = {-2,-3,-6,-8,-9};
	reorderEvenAndOdd(arr, 5);
	printArr(arr, 5);
		return 0;
}
