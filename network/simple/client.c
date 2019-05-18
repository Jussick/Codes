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
	int    sockfd, n;
	char   recvline[MAXLINE], sendline[MAXLINE];
	struct sockaddr_in    servaddr;

	if( argc != 2){
		printf("usage: ./client <ipaddress>\n");
		exit(0);
	}


	if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		printf("create socket error: %s(errno: %d)\n", strerror(errno),errno);
		exit(0);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(6666);
	if( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
		printf("inet_pton error for %s\n",argv[1]);
		exit(0);
	}

	if( connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0){
		printf("connect error: %s(errno: %d)\n",strerror(errno),errno);
		exit(0);
	}

	while(1){
		printf("\nsend msg to server: <bye to exit> \n");
		fgets(sendline, MAXLINE, stdin);  // 注意：用fgets得到的字符串结尾包含'\n'
		if( send(sockfd, sendline, strlen(sendline)-1, 0) < 0)  // 发送的长度减一是为了去掉结尾的'\n'
		{
			printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
			exit(0);
		}
		// 若输入bye，则结束
		if (!strncmp(sendline, "bye", strlen(sendline)-1))  break;
		char recvBuf[MAXLINE];
		recv(sockfd, recvBuf, sizeof(recvBuf), 0);
		printf("----Echo from server----\n");
		printf("%s\n", recvBuf);
		memset(sendline, 0, MAXLINE);
		memset(recvline, 0, MAXLINE);

	}
	close(sockfd);
	exit(0);
}
