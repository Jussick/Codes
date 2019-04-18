//C file
/***********************************************
#
#      Filename: 01-父进程杀死超时子进程.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-04-16 10:15:59
#**********************************************/
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#define TIMEOUT 5


int main() {
	pid_t pid;

	pid = fork();

	if (pid > 0) {  // 父进程
		int count = 0;

		while (1) {

			int result =  waitpid(pid, &result, WNOHANG);

			if (result == 0) {
				printf("time left to kill child process: %ds\n", TIMEOUT - count);
				count ++;
				if (count >= TIMEOUT)
					kill(pid, 9);
			}
			else if(result == pid) {
				printf("child exited.\n");
				break;
			}
			else {
				printf("result: %d\n", result);
				break;
			}
			sleep(1);
		}
	}

	else if (pid == 0) { // 子进程
		execv("./child", NULL);	
		_exit(1);
	}

	else {
		perror("fork");
		return -1;
	}

	return 0;
}
