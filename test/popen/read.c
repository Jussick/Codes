#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char *rrr = (char *)malloc(sizeof(char) * 100);
	read(STDIN_FILENO, rrr, sizeof(rrr));
	puts(rrr);
	free(rrr);
	return 0;
}
