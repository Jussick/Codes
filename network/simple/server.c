#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

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

    if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
    printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
    exit(0);
    }

    if( listen(listenfd, 10) == -1){
    printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
    exit(0);
    }

    printf("======waiting for client's request======\n");
	if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
		printf("accept socket error: %s(errno: %d)",strerror(errno),errno);
		//continue;
	}
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


