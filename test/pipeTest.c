//C file
/***********************************************
#
#      Filename: pipeTest.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-09-26 16:16:10
#**********************************************/
#include<stdio.h>

int main()
{
	//printf("file:%s func:%s line:%d\n", __FILE__, __func__, __LINE__);
	pid_t pid;
	int fd[2];
	char line[64] = {0};
	
	pipe(fd);
	if ( (pid = fork()) > 0)
	{
		close(fd[0]);
		strcpy(line, "Hello Edward!\n");
		write(fd[1], line, strlen(line));
	}
	else if (pid == 0)
	{
		close(fd[1]);
		char buf[64];
		memset(buf, 0, sizeof(buf));
		read(fd[0], buf, sizeof(buf));
		write(STDOUT_FILENO, buf, strlen(buf));
	}
	int status;
	waitpid(pid, &status, 0);
	return 0;
}
