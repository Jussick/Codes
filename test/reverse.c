#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *reverse(char *str)
{
	unsigned long int i,j;
	char *ret_val = (char *)malloc(sizeof(char)*50);
	for (i = 0, j = strlen(str)-1; i < strlen(str); ++i, --j)
	{
		ret_val[j] = str[i];
	}
	return ret_val;
}

int main()
{
	char str[50];
	puts("Input the string you want to reverse:");
	scanf("%s", str);
	char *result = reverse(str);
	puts(result);
	free(result);

	return 0;
}
