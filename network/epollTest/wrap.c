//C file
/***********************************************
#
#      Filename: wrap.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: some enhanced socket API
#        Create: 2018-10-11 14:37:56
#**********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/socket.h>
#include<sys/epoll.h>
#include<unistd.h>

void perr_exit(const char *s, int exit_num)
{
    perror(s);
    exit(exit_num);
}

int Accept(int sockfd, struct sockaddr *sa, socklen_t *salenptr)
{
    int n;

again:
    if ( (n = accept(sockfd, sa, salenptr)) < 0 )
    {
        if (errno == ECONNABORTED || errno == EINTR)  // EINTR中断信号
            goto again;
        else
            perr_exit("accept", 1);
    }
    return n;
}

void Bind(int sockfd, const struct sockaddr *sa, socklen_t salen)
{
    if (bind(sockfd, sa, salen) < 0)
        perr_exit("bind", 2);
}

void Connect(int sockfd, const struct sockaddr *sa, socklen_t salen)
{
    if (connect(sockfd, sa, sa