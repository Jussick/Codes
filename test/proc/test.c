//C file
/***********************************************
#
#      Filename: test.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-04-01 11:26:37
#**********************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>


void testSignal() {
	pid_t pid = fork();
	signal(SIGCHLD, SIG_IGN);  //注释一
	if (pid == 0) {
		int ret = system("ls");
		printf("ret=%d\n", WEXITSTATUS(ret));
		printf("ret=%d\n", ret>>8);
	}
	exit(100);	



}

int main()
{
    signal(SIGCHLD, SIG_IGN);  //注释一
    //signal(SIGCHLD, SIG_DFL);  //注释一
    //printf("before fork pid: %d\n", getpid());
	int ret_outside = -100;
    int status = 110;
    pid_t childPid = fork();
    if (childPid == 0)
    {
		//signal(SIGCHLD, SIG_IGN);  //注释一
        printf("I'm child...pid=%d\n", getpid());
		ret_outside = system("ls");
		printf("ret_outside = %d\n", ret_outside);
		exit(250);
		//testSignal();
    }
    else
    {
        //printf("I'm father...pid=%d\n", getpid());
        //sleep(25);
        int wait_res = waitpid(childPid, &status, 0);

		if (wait_res == childPid)
			printf("child status:%d\n", WEXITSTATUS(status));
		else if (wait_res != EINTR)
			printf("waitpid res is not EINTR nor childpid, system return -1\n");
		printf("wait_res:%d\n", wait_res);
		printf("errno:%d\n", errno);
    }

}

