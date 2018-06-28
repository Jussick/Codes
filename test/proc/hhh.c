#include<stdio.h>
#include<unistd.h>  
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/* 验证内容：
 * fork后面的代码内容就是执行了两次，waitpid也是一样，
 * 只不过当父进程先waitpid后，子进程就结束了，故没执行
 * waitpid，造成只执行一次的现象。
 */
int main()
{
	pid_t pid;
	pid = fork();
	char *str[] = {"test", "test1", (char *)0};
	if (pid == -1)
		printf("error\n");
	if (pid == 0)
	{
		printf("child pid = %d\n", getpid());
		//execv("./test", str);	
	}
	else
	{
		sleep(2);
	}
	if (waitpid(pid, NULL, 0) < 0)
		printf("child wait error\n");
	else
		printf("parent wait success,pid=%d\n", pid);
	exit(0);
}
