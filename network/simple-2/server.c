#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include "unp.h"
#include "mysock.h"

#define MAXLINE 4096

typedef void *(sigFunc)(int);

void connectHandle(int connfd);  // real handle
void sig_child(int signo);  // SIGCHLD信号处理函数

int main(int argc, char** argv)
{
	pid_t pid;
	int    listenfd, connfd;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t len;  // 存放客户端地址的长度
	char temp[64];  // 保存客户端IP地址

	if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
		printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
	}

	//memset(&servaddr, 0, sizeof(servaddr));
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(9999);

	if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
		printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
	}

	if( listen(listenfd, 10) == -1){
		printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
	}

	//signal(SIGCHLD, SIG_IGN);
	signal(SIGCHLD, sig_child);
	printf("======waiting for client's request======\n");
	for ( ; ; ) {  // 此循环的目的是: 能让一个客户端连接断开后，其他的还可以连进来。

		len = sizeof(cliaddr);
		if( (connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len)) == -1) {
			if (errno == EINTR) 
				continue;  /* 系统中断要重启accept */
			else
				printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
		}

		if ( (pid = fork()) == 0) {
			close(listenfd);
			// 打印客户端的IP和端口
			printf("connection from IP:%s, port:%d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, temp, sizeof(temp)), 
					ntohs(cliaddr.sin_port));
			
			// 收发报文处理逻辑
			connectHandle(connfd);
			exit(0);
		}

		close(connfd);
	}

	close(listenfd);
	return 0;
}


void connectHandle(int connfd) {

	char buff[MAXLINE];  // 收发信息的内容
	unsigned long msgLen;  // 报文总长度
	int bytes = 0;  // 收发信息的长度

	while (1) {  // 此循环的目的是：收发多条报文，知道收到“bye”字符串才结束。

		// 先接收报文的总长度
		memcpy(buff, "0x", 2);
		if ((bytes = read(connfd, buff+2, 4)) < 0)
			break;
		msgLen = strtol(buff, NULL, 16);
		printf("tatol len: %ld,  ", msgLen);

		// 接收报文内容
		memset(buff, 0, MAXLINE);
		bytes = recv(connfd, buff, msgLen, 0);

		
		if (bytes == 0) {  // 处理错误情况
			printf("Connection closed by client.\n");
			break;
		}
        else if (bytes == -1) {
			printf("Connection error: %s\n", strerror(errno));
			break;
        }


		// 若收到bye，则结束
		//if (strlen(buff) == 3 && !strncmp(buff, "bye", 3)) break;
		printf("recv msg from client: %s, len:%ld\n", buff, strlen(buff));   
		printf("---send it back to client---\n\n");
		send(connfd, buff, strlen(buff), 0);
		memset(buff, 0, MAXLINE);
	}
	close(connfd);
}

void sig_child(int signo) {
	pid_t pid;
	int stat;

	while((pid = waitpid(-1, &stat, WNOHANG)) > 0) {
		printf("child terminated: pid[%d]\n", pid);
	}
}

