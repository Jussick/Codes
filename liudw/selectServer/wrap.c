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
	if (connect(sockfd, sa, salen) < 0)
		perr_exit("connect", 3);
}

void Listen(int sockfd, int backlog)
{
	if (listen(sockfd, backlog) < 0)
		perr_exit("listen", 4);
}

int Socket(int family, int type, int protocol)
{
	int n;

	if ( (n = socket(family, type, protocol)) < 0)
		perr_exit("socket", 5);
	return n;
}

void Close(int sockfd)
{
	if (close(sockfd) == -1)
		perr_exit("close", 6);
}

ssize_t Read(int fd, void *ptr, size_t nbytes)  // size_t是unsigned long, ssize_t是long
{
	ssize_t n;

again:
	if ( (n = read(fd, ptr, nbytes)) == -1)
	{
		if (errno == EINTR)
			goto again;
		else
			return -1;
	}
	return n;
}

ssize_t Write(int fd, void *ptr, size_t nbytes)
{
	ssize_t n;

again:
	if ( (n = write(fd, ptr, nbytes)) == -1)
	{
		if (errno == EINTR)
			goto again;
		else
			return -1;
	}
	return n;
}

ssize_t Readn(int fd, void *vptr, size_t n)
{
	size_t nleft;
	ssize_t nread;
	char *ptr;

	ptr = vptr;
	nleft = n;
	while (nleft > 0)
	{
		if ( (nread = read(fd, ptr, nleft)) < 0)
		{
			if (errno == EINTR)
				nread = 0;
			else
				return -1;
		}
		else if (nread == 0)
			break;
		nleft -= nread;
		ptr += nread;
	}
	return n - nleft;
}

ssize_t Writen(int fd, void *vptr, size_t n)
{
	size_t nleft;
	ssize_t nwrite;
	char *ptr;

	ptr = vptr;
	nleft = n;
	while (nleft > 0)
	{
		if ( (nwrite = write(fd, ptr, nleft)) <= 0)
		{
			if (nwrite == 0 && errno == EINTR)
				nwrite = 0;
			else
				return -1;
		}
		nleft -= nwrite;
		ptr += nwrite;
	}
	return n;
}

static ssize_t my_read(int fd, char *ptr)
{
	static int read_cnt;	
	static char *read_ptr;
	static char read_buf[100];

	if (read_cnt <= 0)
	{
again:
		if ( (read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0) {
			if (errno == EINTR)
				goto again;
			return -1;
		} else if (read_cnt == 0)
			return 0;
		read_ptr = read_buf;
	}
	read_cnt--;
	*ptr = *read_ptr++;
	return 1;
}		

ssize_t Readline(int fd, void *vptr, size_t maxlen)
{
	ssize_t n, rc;
	char c, *ptr;
	ptr = vptr;
	for (n = 1; n < maxlen; n++) {
		if ( (rc = my_read(fd, &c)) == 1) {
			*ptr++ = c;
			if (c == '\n')
				break;
		} else if (rc == 0) {
			*ptr = 0;
			return n - 1;
		} else
			return -1;
	}
	*ptr = 0;
	return n;
}
