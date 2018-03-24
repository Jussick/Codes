#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

#define VA_END "1"

void vaList(char *arg, ...)
{
	int i = 0;
	va_list va;
	va_start(va, arg);
	char *str = va_arg(va, char*);

	while(strcmp(str, VA_END))
	{
		printf("str[%d] = %s\n", i, str);
		str = va_arg(va, char*);
		++i;
	}

	va_end(va);

}

void vaList_two(char *arg[], ...)
{
	int i;
	va_list va;
	va_start(va, arg);
	char *str = va_arg(va, char*);
	for (i = 0; strcmp(str, VA_END); i++)
	{
		arg[i] = strdup(str); // strdup是复制字符串，用完空间要自己释放
		str = va_arg(va, char*);
	}	
	arg[i] = NULL;
}

int main()
{
	int i;
	char *str[10] = {NULL};

	vaList_two(str, "one", "two", "three", "four", VA_END);
	for (i = 0; str[i] != NULL; i++)
		printf("str[%d] = %s\n", i, str[i]);
	for (i = 0; str[i] != NULL; i++)
		free(str[i]);
	//vaList("begin", "one", "two", "three", VA_END);
	return 0;
}
