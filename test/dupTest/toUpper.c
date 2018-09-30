//C file
/***********************************************
#
#      Filename: toUpper.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-09-25 14:03:07
#**********************************************/
#include<stdio.h>
#include<ctype.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		putchar(toupper(c));	
	}
	exit(0);
}
