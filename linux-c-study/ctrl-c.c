//C file
/***********************************************
#
#      Filename: ctrl-c.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-09-26 19:48:07
#**********************************************/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void orch(int sig)
{
	char buf[1024] = {0};
	sprintf(buf, "Oh my God, you recieve a signal: %d\n", sig);
	write(STDOUT_FILENO, buf, sizeof(buf));
	//printf("Oh my God, you recieve a signal %d\n", sig);
	(void)signal(SIGINT, SIG_DFL);
}

int main()
{
	char buf[1024] = {0};
	strcpy(buf, "first ctrl-c will be catched\n");
	write(STDOUT_FILENO, buf, sizeof(buf));
	//printf("first ctrl-c will be catched\n");
	(void)signal(SIGINT, orch);
	pause();

	while(1)
	{
		printf("hiya\n");
		sleep(1);
	}

	exit(0);
}
