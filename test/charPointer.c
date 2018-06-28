#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

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
	char *(*str[10]) = {NULL};
	str = (char **)malloc(2*3*sizeof(char *));
		

	free(str);

	return 0;
}
