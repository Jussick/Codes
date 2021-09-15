//C file
/***********************************************
#
#      Filename: socketPairTest.c
#
#        Author: luhg - luhengguang@joyy.sg
#   Description: socketpair的使用
#        Create: 2021-09-14 10:29:44
#**********************************************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <error.h>
#include <errno.h>
#include <sys/socket.h>
#include <stdlib.h>

const char *str = "SOCKET PAIR TEST";

int main()
{

    char buf[1024] = {0};
    int fds[2];

    if (socketpair(AF_LOCAL, SOCK_STREAM, 0, fds) == -1)   // 创建一对相互连接的套接字，一个收一个发
    {
        printf("Error, socketpair create failed, error(%d): %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
    int size = write(fds[0], str, strlen(str));

    read(fds[1], buf, size);

    printf("fd[1] recv: \"%s\"\n", buf);

    return 0;
}
