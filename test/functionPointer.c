#include<stdio.h>
#include<stdlib.h>

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
	void (*pf) (int *, int) = print;	
	int arr[3] = {1,2,3};
	(*pf)(arr, 3);

	return 0;
}
