//C++ file
/***********************************************
#
#      Filename: udp-server.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2021-07-13 14:18:01
#**********************************************/

// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>

#define PORT     8080
#define MAXLINE 1024

using namespace std;

int main()
{
    int sockfd;
    struct sockaddr_in servAddr, cliAddr;
    char buffer[MAXLINE] = {0};
    const char *reply = "reply from server";

    memset(&servAddr, 0, sizeof(servAddr));
    memset(&cliAddr, 0, sizeof(cliAddr));

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("init socket failed!");
        exit(EXIT_FAILURE);
    }

    // filling server infomation
    servAddr.sin_family      = AF_INET;  // ipV4
    servAddr.sin_addr.s_addr = INADDR_ANY;
    servAddr.sin_port        = htons(PORT);

    // bind socket with server address
    if (bind(sockfd, (const struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
    {
        perror("bind error!");
        exit(EXIT_FAILURE);
    }

    unsigned int len, n;     
    len = sizeof(cliAddr);

    n = recvfrom(sockfd, (char *)buffer, MAXLINE, 
            MSG_WAITALL, (struct sockaddr *)&cliAddr, &len);

    // buffer[n] = '\0';
    cout << "Recieve from client: " << buffer << endl;

    sendto(sockfd, (const char*)reply, strlen(reply), 
            MSG_CONFIRM, (struct sockaddr *)&cliAddr, len);

    cout << "Server reply sent!" << endl;

    close(sockfd);
    return 0;
}
