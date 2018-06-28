#include<stdio.h>
#include<stdlib.h>

int main()
{
	printf("Please input something...\n");
	char *str = (char *)malloc(20*sizeof(char));
	gets(str);
	puts(str);
	exit(11);
}
