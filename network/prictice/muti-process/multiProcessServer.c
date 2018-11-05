//C file
/***********************************************
#
#      Filename: multiProcessServer.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-10-25 10:19:57
#**********************************************/
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
#include "../../strongAPI/wrap.h"
#define MAXLINE 80
#define SERV_PORT 8000

void do_sigchild(int num)
{
	waitpid(0, NULL, WNOHANG);
}

int main(void)
{
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int listenfd, connfd;
	char buf[MAXLINE] = {0};
	char str[INET_ADDRSTRLEN] = {0};
	int i, n;
	pid_t pid;

	struct sigaction newact;
	newact.sa_handler = do_sigchild;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGCHLD, &newact, NULL);

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	Listen(listenfd, 20);

	printf("Accepting connections...\n");

	while(1)
	{
		cliaddr_len = sizeof(cliaddr);
		connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);

		pid = fork();
		if (pid == 0)
		{
			Close(listenfd);
			while (1)
			{
				n = Read(connfd, buf, MAXLINE);
				if (n == 0)
				{
					printf("the other side has been closed.\n");
					break;
				}
				printf("received from %s at PORT %d\n",
						inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)),
						ntohs(cliaddr.sin_port));
				for (i = 0; i < n; ++i)
					buf[i] = toupper(buf[i]);
				Write(connfd, buf, n);
			}
			Close(connfd);
			return 0;
		}
		else if (pid > 0)
			Close(connfd);
		else
			perror("fork");
	}
}
