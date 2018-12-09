//C file
/***********************************************
#
#      Filename: signal.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-11-12 16:07:34
#**********************************************/
#include<stdio.h>
#include "my.h"

void ding(int signum)
{
	puts("ding!~~~");
}

int main()
{
	signal(SIGALRM, ding);
	puts("before alarm");
	alarm(5);
	pause();
	puts("after alarm");
	
	return 0;
}
