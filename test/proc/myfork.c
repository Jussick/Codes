#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include<signal.h>
#include<wait.h>

int main1()
{
    pid_t pid;
    char *message;
    int n;

    printf("fork program starting\n");
    pid = fork();
    switch(pid) 
    {
    case -1:
        perror("fork failed");
		exit(-1);
    case 0:
        message = "This is the child";
        n = 5;
        break;
    default:
        message = "This is the parent";
        n = 3;
        break;
    }

    for(; n > 0; n--) {
        puts(message);
        sleep(1);
    }

	return 0;
}	

int main2()
{
	char *msg = NULL;
	int  num = 0;
	int status;

	pid_t pid = fork();

	if (pid == 0)
	{
		msg = "I'm child...";
		num = 6;
	}
	else
	{
		msg = "I'm father...";
		num = 3;
		waitpid(pid, &status, 0);
		printf("child exitStatus:%d\n", status);
	}

	int i;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", msg);
		sleep(1);
	}

	exit(0);

}


int main()
{
	signal(SIGCHLD, SIG_IGN);
	printf("before fork pid: %d\n", getpid());
	int status;
	pid_t childPid = fork();
	if (childPid == 0)
	{
		printf("I'm child...pid=%d\n", getpid());
		exit(0);
	}
	else
	{
		printf("I'm father...pid=%d\n", getpid());
		sleep(25);
		//waitpid(childPid, &status, 0);
		//printf("child result:%d\n", status);
	}

}
