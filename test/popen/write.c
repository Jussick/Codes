#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	const char *str = "hello";
	write(STDOUT_FILENO, str, strlen(str));
	return 0;
}
