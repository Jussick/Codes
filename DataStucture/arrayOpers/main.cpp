#include"my.h"
#include<stdio.h>
#include<stdlib.h>
//#include<windows.system.h>

int main()
{
	struct data data1;
	int arr[] = { 1, 2, 3, 2, 3 };
	init(&data1);
	addOneElement(&data1, 10);
	addOneElement(&data1, 12);
	addOneElement(&data1, 14);
	addOneArray(&data1,arr,5);
	addOneElement(&data1, 10);

	sort(&data1, 1);
	printf("data1.status=%d\n", data1.status);
	printfall(&data1);
	//deleteone(&data1, 111);
	//update(&data1, 10, 100);
	//insert(&data1, 3, 90, 1);
	//deleteall(&data1, 3);
	//deleteall(&data1, 2);

	findaddr addr=findall(&data1, 10);
	for (int i = 0; i < addr.n; i++)
	{
		printf("%d\n", *addr.p[i]);
	}

	deleteall(&data1, 10);
	printfall(&data1);
	
	/*printf("data1.p=%d\n", data1.p);
	printf("data1.p++=%d\n", *(data1.p+1));*/
	//find(&data1, 14);
	//printf("max is:%d\n", max(&data1));
	//printf("min is:%d\n", min(&data1));
	system("pause");
	return 0;
}