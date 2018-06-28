#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str[100], str1[100];
	fgets(str, 100, stdin);
	printf("str=%slength(str): %ld\n", str, strlen(str)); 

	if ((strcmp(str,"haha\n") == 0))
		printf("strcmp~~~\n");
	if ((strncmp(str, "haha", strlen(str)-1) == 0))
		printf("strncmp!!!\n");

	return 0;
}
