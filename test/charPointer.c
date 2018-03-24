#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main1()
{
	const char *str = "KingsLanding";
	char ddd[] = "KingsLanding";
	//str[0] = 'Q';
	printf("KingsLanding\'s addr:%p\n", "KingsLanding");
	printf("str\'s addr:%p\n", str);
	printf("ddd \'s addr:%p\n", ddd);

	return 0;
}

int main2()
{
	int i = 0;
	const char *result;
	const char *str[] = {"one", "two", "three", NULL}; // 可以给字符串数组的最后一个元素赋为NULL，用以判断结束

	for(i = 0; str[i] != NULL; i++)
		printf("str[%d] = %s\n", i, str[i]);

	result = (str[3] == NULL)?"null":"not null";
	printf("result: %s\n", result);
	return 0;
}

int main()
{
	char *str = "KingsLanding";
	char *p1 = str;
	printf("str addr:%p\n", str);
	printf("*p1->addr:%p\n", p1);
	const char *p11 = str;
	printf("*p11->addr:%p\n", p11);

	char *p2 = strdup(str);
	printf("*p2->addr:%p\n", p2);

	return 0;
}
