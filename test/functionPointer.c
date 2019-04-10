#include<stdio.h>
#include<stdlib.h>

typedef void (*func) (int *, int);

void print(int *arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
		if (i == len - 1)
			printf("\n");
	}
}
int main()
{
	/* 方法一: 直接定义 */
	void (*pf) (int *, int) = print;	
	int arr[3] = {1,2,3};
	(*pf)(arr, 3);

	/* 方法二: 用typedef定义一个函数指针 */
	func ff = print;
	ff(arr, 4);

	return 0;
}
