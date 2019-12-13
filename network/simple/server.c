#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 4096

int main(int argc, char** argv)
{
    int    listenfd, connfd;
    struct sockaddr_in servaddr;
    char    buff[MAXLINE];
    int     n;

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
    printf("create socket error: %s(errno: %d)\n",strerror(errno),errno);
    exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(6666);

    // 设置套接字选项避免地址使用错误
    // 该错误是由socket断开后TIME_WAIT状态引起的，在套接字关闭后仍保留2-4分钟，可以通过设置套接字状态来解决
	int opt = 1;
	if((setsockopt(listenfd ,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) < 0)
	{
		perror("setsockopt failed");
		exit(EXIT_FAILURE);
	}

    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
    printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
    exit(0);
    }

    if( listen(listenfd, 10) == -1){
    printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
    exit(0);
    }

    /* varibles for client address print */
    struct sockaddr_in clientAddr;
    socklen_t cliAddrLen = sizeof(clientAddr);

    printf("======waiting for client's request======\n");
	if( (connfd = accept(listenfd, (struct sockaddr*)&clientAddr, &cliAddrLen)) == -1){  // 要想获得client的地址信息，在accept时要传入地址结构和其长度
		printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
	}

    /* print client's IP and port */
    char clientIP[128] = {0};
    inet_ntop(AF_INET, &clientAddr.sin_addr, clientIP, cliAddrLen);
    int clientPort = ntohs(clientAddr.sin_port);
    printf("clientIP:%s:%d\n", clientIP, clientPort);

    while(1){
		n = recv(connfd, buff, MAXLINE, 0);
		// 若收到bye，则结束
		if (!strncmp(buff, "bye", strlen(buff) - 1)) break;
		printf("recv msg from client: %s\n", buff);   
		printf("---send it back to client---\n\n");
		send(connfd, buff, MAXLINE, 0);
		memset(buff, 0, MAXLINE);
    }

	close(connfd);
    close(listenfd);
}



