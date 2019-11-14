//C file
/***********************************************
#
#      Filename: selectTest.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-11-05 22:48:14
#**********************************************/
#include <sys/select.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    fd_set fds;
    int nready = 0;

    FD_ZERO(&fds);

    int fd1 = fileno(stdin);
    int maxfd = fd1;
    char readbuf[1024] = {0};

    struct timeval tv;
    tv.tv_sec = 3;
    tv.tv_usec = 0;

    while (1)
    {
        FD_SET(fd1, &fds);
        // nready = select(maxfd + 1, &fds, &fds, NULL, NULL);
        printf("wait for input:\n");
        nready = select(maxfd + 1, &fds, NULL, NULL, &tv);
        printf("wait over, nready: %d\n", nready);

        if (nready == 0) continue;
        
        if (FD_ISSET(fd1, &fds))
        {
            int i = read(fd1, readbuf, sizeof(readbuf));
            if (i > 0)
            {
                printf("STDIN buf: %s\n", readbuf);
            }
            memset(readbuf, 0, sizeof(readbuf));
        }

    }
}

