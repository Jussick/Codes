//C file
/***********************************************
#
#      Filename: nonBlockWrite.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 若把输出重定向到文件中，write还是会阻塞直到输出结束:
						./a.out < /etc/servives > temp.file 
				 但若不改变标准输出，让其输出至终端，而把错误流重定向到文件中，则会出现非阻塞的情况
				 		./a.out < /etc/services 2>stderr.out
						注意重定向0,1,2时，数字和<之间不能有空格
#        Create: 2018-10-11 17:26:02
#**********************************************/
#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

/* 设置文件flag标志 */
void set_fl(int fd, int flag)  
{
	int flags = fcntl(fd, F_GETFL);
	flags |= flag;
	fcntl(fd, F_SETFL, flags);
}

/* 取消文件flag标志 */
void clr_fl(int fd, int flag)
{
	int flags = fcntl(fd, F_GETFL);
	flags &= ~flag;
	fcntl(fd, F_SETFL, flags);
}

char buf[500000];

int
main(void)
{
	int ntowrite, nwrite;
	char *ptr;

	ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
	fprintf(stderr, "read %d bytes.\n", ntowrite);

	set_fl(STDOUT_FILENO, O_NONBLOCK);

	ptr = buf;
	while (ntowrite > 0)
	{
		errno = 0;
		nwrite = write(STDOUT_FILENO, ptr, ntowrite);
		fprintf(stderr, "errno: %d, nwrite: %d\n", errno, nwrite);

		if (nwrite > 0)
		{
			ntowrite -= nwrite;
			ptr += nwrite;
		}
	}

	clr_fl(STDOUT_FILENO, O_NONBLOCK);
	exit(0);
}
