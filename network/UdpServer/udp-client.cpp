//C++ file
/***********************************************
#
#      Filename: udp-client.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2021-07-13 14:48:50
#**********************************************/
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
    char buffer[MAXLINE] = {0};
    const char *hello = "hello from client!";
    struct sockaddr_in servAddr;
    

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    memset(&servAddr, 0, sizeof(servAddr));

    // fill in server infomation
    servAddr.sin_family      = AF_INET;  // ipV4
    servAddr.sin_port        = htons(PORT);
    servAddr.sin_addr.s_addr = INADDR_ANY;
    
    unsigned int len, n;

    sendto(sockfd, (const char *)hello, strlen(hello),
           MSG_CONFIRM, (const struct sockaddr *)&servAddr, 
             sizeof(servAddr));
    cout << "hello msg sent!\n";

    n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                MSG_WAITALL, (struct sockaddr *) &servAddr,
                            &len);
    // buffer[n] = '\0';
    cout << "Recieve from server: " << buffer << endl;

    close(sockfd);
    return 0;
}
