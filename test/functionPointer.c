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
int main1()
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


/* -------------------------------------------------------------------- */
/* 下面来看一个函数指针在实际中的应用，把函数指针当作参数传入到qsort快排函数中，qsort回调传入的函数，根据其行为对数组排序 */
int compare(const void *a, const void *b)
{
    int A = *((int *)a);    // typecast a to int* and get value
    int B = *((int *)b);    // typecast b to int* and get value

    // 按照数的绝对值比较
    if (abs(A) > abs(B)) 
        return 1;  // return 的值大于0时交换条件成立
    else       
        return -1;
}

int main()
{
    int a[6] = {-30, 25, -56, 5, 9, 2};

    qsort(a, 6, sizeof(int), compare);  // qsort能比较任何类型的数组，不光是数字

    int i;
    for (i = 0; i < 6; ++i)
        printf("%d ", a[i]);
}
