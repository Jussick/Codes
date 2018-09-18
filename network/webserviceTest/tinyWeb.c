//C file
/***********************************************
#
#      Filename: simpleWeb.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-31 14:52:32
#**********************************************/
#include "strongIO.h"
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define PORT 8080                       // 服务器监听端口

int main(){
    
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);
    
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    
    listen(server_socket, 5);
    
    int client_socket = accept(server_socket, NULL, NULL);
    
    char buf[1024];
    read(client_socket, buf, 1024);
    
    printf("%s",buf);

    char status[] = "HTTP/1.0 200 OK\r\n";
    char header[] = "Server: DWBServer\r\nContent-Type: text/html;charset=utf-8\r\n\r\n";
	FILE *fp = fopen("./simplistHtml.html", "r");
	char line[1024];
	char body[1024 * 1024];
	while (!feof(fp))
	{
		memset(line, 0, sizeof(line));
		fgets(line, sizeof(line), fp);	
		snprintf(body + strlen(body), strlen(line), "%s", line);
	}
	printf("%s\n", body);
    char body1[] = "<html><head><title>C语言构建小型Web服务器</title></head><body><h2>欢迎</h2><p>Hello，World</p></body></html>";
	printf("%s\n", body1);

    write(client_socket, status, sizeof(status));
    write(client_socket, header, sizeof(header));
    write(client_socket, body, sizeof(body));

    close(client_socket);
    close(server_socket);

    return 0;
}


