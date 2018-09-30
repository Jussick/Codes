//C file
/***********************************************
#
#      Filename: deamon.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 创建一个守护进程，使其成为一个回话的首进程，并脱离控制终端的控制，用ps带x的参数才能看到
#        Create: 2018-09-29 14:55:56
#**********************************************/
#include<stdio.h>
#include<sys/prctl.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<string.h>
#include<time.h>

#define DATESIZE 128

void deamonize()
{
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("exit");
		exit(EXIT_FAILURE);
	}
	else if (pid != 0)  // parent
		exit(0);

	setsid(); // creates a session and sets the process group ID
	prctl(PR_SET_NAME, "Edward", NULL, NULL, NULL);

	/* 
	 * 改变当前工作目录到/下
	 */
	if (chdir("/") < 0)
	{
		perror("chdir");
		exit(1);
	}
	/* 设置umask为0 */
	umask(0);
	/* 
	 * 重定向0,1,2的文件描述符到/dev/null, 因为已经失去控制终端，再操作0,1,2没意义
	 */
	close(0);
	open("/dev/null", O_RDWR);
	dup2(0, 1);
	dup2(0, 2);
}

void handle(int haha)
{
	printf("ohohoh\n");
	exit(0);
}

void GetCurTime(char *cur_time)
{
	const time_t t = time(NULL);	
	strcpy(cur_time , ctime(&t));
	char *temp = strdup(cur_time);
	sprintf(cur_time, "%s\n", temp);
	free(temp);
}

int main()
{
	deamonize();
	//unlink("/tmp/linux-c-study/deamon.log");
	int fd;
	char now[DATESIZE] = {0};
	while(1)  /* 此循环里实现守护进程的核心操作 */
	{
		// 每10s向/tmp/linux-c-study/deamon.log中写一次当前时间 	
		GetCurTime(now);	
		fd = open("/tmp/linux-c-study/deamon.log", O_RDWR | O_CREAT | O_APPEND);
		write(fd, now, strlen(now));
		memset(now, 0, DATESIZE);
		sleep(1);
	}
	exit(0);
}
