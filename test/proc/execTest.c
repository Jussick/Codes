#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
	pid_t pid;
	int status;
	char *str[] = {"putsArgs", "hello", "world", (char *)0};
	if ((pid = fork()) < 0)
		printf("fork error\n");
	else if (pid == 0)
	{
		//sleep(1);
		//execl("./test", "test", "hello", "world",  (char *)0);
		execv("./putsArgs", str);
		exit(2);
	}

	waitpid(pid, &status, 0);
	printf("status=%d\n", status);
	exit(0);
}

int main2 (void)
{
	pid_t pid;
	if ((pid = fork()) < 0)
		printf("fork error\n");
	else if (pid == 0)
	{
		execl("/root/codes/test/proc/test", "test", "test1", (char *)0);
		exit(0);
	}
	waitpid(pid, NULL, 0);

	exit(0);
}

