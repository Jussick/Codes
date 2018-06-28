#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
 	char *path = "/tmp";
	system("pwd");
	chdir(path);
	system("pwd");
	return 0;
}
