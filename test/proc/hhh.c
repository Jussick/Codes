#include <stdio.h>
#include <unistd.h>  
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/* 验证内容：
 * fork后面的代码内容就是执行了两次，waitpid也是一样，
 * 只不过当父进程先waitpid后，子进程就结束了，故没执行
 * waitpid，造成只执行一次的现象。
 */
int main()
{
	int status = -200;
	signal(SIGCHLD, SIG_DFL);
	pid_t pid;
	pid = fork();
	char *str[] = {"./putsArgs", "test", "test1", (char *)0};
	if (pid == -1)
		printf("error\n");
#if 0
	if (pid == 0)
	{
		printf("[child]pid = %d\n", getpid());
		//execv("./putsArgs", str);	
	}
	else
	{
		printf("[parent]pid = %d\n", getpid());
	}
#endif
	// 为什么顺序会是parent，child，child，parent呢？因为开始随机到了parent，之后parent便进入了wait的挂起状态，等待child执行完，故是这个顺序。
	// 如果先随机到了child，那么顺序将是：child，child，parent，parent
	printf("[%s]pid:%d\n", pid==0?"child":"parent", pid);    

	waitpid(pid, &status, 0);
	printf("[%s]status:%d\n",pid==0?"child":"parent", status); 

#if 0
	if (waitpid(pid, &status, 0) < 0)
		//printf("child wait error\n");
		perror("error:");
	else if (WIFEXITED(status))
		printf("parent wait success,pid=%d\nchild exit code:%d\n", pid, WEXITSTATUS(status));
#endif
	exit(0);
}
