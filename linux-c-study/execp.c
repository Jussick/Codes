//C file
/***********************************************
#
#      Filename: execp.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-09-27 09:21:04
#**********************************************/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
	printf("start execlp...\n");
	if (execlp("ls", "ls", (char *)0) < 0)  // 从exec函数后，若成功执行便不会执行接下来的内容了
	{
		perror("exec");
		exit(0);
	}
	printf("this one you will never seen\n");
	exit(0);
}
