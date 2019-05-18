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

void clientHandle(int sockfd);

int main(int argc, char** argv)
{
	int    sockfd;
	struct sockaddr_in    servaddr;

	if( argc != 2){
		printf("usage: ./client <ipaddress>\n");
		exit(0);
	}

	if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
		exit(0);
	}

	//memset(&servaddr, 0, sizeof(servaddr));
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(9999);
	if( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
		printf("inet_pton error for %s\n",argv[1]);
		exit(0);
	}

	if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
		printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
	}

	clientHandle(sockfd);

	//close(sockfd);
	exit(0);
}


void clientHandle(int sockfd) {

	char   recvline[MAXLINE], sendline[MAXLINE];
	unsigned long msgLen = 0;
	char msgHexLen[6] = {0};
	memset(sendline, 0, MAXLINE);
	memset(recvline, 0, MAXLINE);
	
	while(1){

		printf("\nsend msg to server: <bye to exit> \n");
		scanf("%s", sendline);

		// 计算报文长度并发送
		msgLen = strlen(sendline);	
		decToHex(msgLen, 4, msgHexLen);
		write(sockfd, msgHexLen, 4);



		if( send(sockfd, sendline, msgLen, 0) < 0)  // 发送的长度减一是为了去掉结尾的'\n'
		{
			printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
			exit(0);
		}
		// 若输入bye，则结束
		//if (strlen(sendline) == 3 && !strncmp(sendline, "bye", 3))  break;
		printf("----Echo from server----\n");
		int bytes = recv(sockfd, recvline, sizeof(recvline), 0);
		if (bytes == 0) {  // 处理错误情况
			printf("Connection closed by server.\n");
			break;
		}
		else if (bytes == -1) {
			printf("Connection error: %s\n", strerror(errno));
			break;
		}
		printf("%s\n", recvline);
		memset(sendline, 0, MAXLINE);
		memset(recvline, 0, MAXLINE);

	}
}
