#ifndef RIO_H_
#define RIO_H_
 
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#define RIO_BUFSIZE 8192
 
typedef struct
{
	int rio_fd;
	int rio_cnt;
	char *rio_pbuf;
	char rio_buf[RIO_BUFSIZE];
}rio_t;
 
//无缓冲输入输出
ssize_t rio_readn(int fd, void *usrbuf, size_t n);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);
//带缓冲输入
void rio_readinitb(rio_t *pr, int fd);
ssize_t rio_read(rio_t *pr, char *usrbuf, size_t n);
ssize_t rio_readnb(rio_t *pr, void *usrbuf, size_t n);
ssize_t rio_readlineb(rio_t *pr, void *usrbuf, size_t maxlen);
 
//无缓冲输入函数
//成功返回输入的字节数，若EOF返回0，出错返回－1
ssize_t rio_readn(int fd, void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nread;
	char *pbuf = usrbuf;
	while(nleft > 0)
	{
		//在某些系统中，当处理程序捕捉到一个信号时，被中断的慢系统调用(read, write, accept)
		//在信号处理程序返回时不再继续，而是立即返回给客户一个错误条件，并将errno设置成为EINTR
		if((nread = read(fd, pbuf, nleft)) < 0)
		{
			if(errno == EINTR)
				nread = 0;    //中断造成的,再次调用read
			else
				return -1;    //出错
		}
		else if(nread == 0)   //到了文件末尾
			break;
		nleft -= nread;
		pbuf += nread;
	}
	return n - nleft;
}
//无缓冲输出函数
//成功返回输出的字节数，出错返回－1
ssize_t rio_writen(int fd, void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nwritten;
	char *pbuf = usrbuf;
	while(nleft > 0)
	{
		//注意这里是小于等于，磁盘已满或超过一个给定进程的文件长度限制就出错了
		if((nwritten = write(fd, pbuf, nleft)) <= 0)
		{
			if(errno == EINTR)
				nwritten = 0;
			else
				return -1;
		}
		nleft -= nwritten;
		pbuf += nwritten;
	}
	return n; //注意与输入的区别，write不会返回不足值
}
 
//初始化rio_t结构
void rio_readinitb(rio_t *pr, int fd)
{
	pr->rio_fd = fd;
	pr->rio_cnt = 0;
	pr->rio_pbuf = pr->rio_buf;
}
//带缓存函数 供内部调用
ssize_t rio_read(rio_t *pr, char *usrbuf, size_t n)
{
	int cnt;
	while(pr->rio_cnt <= 0) //内部缓冲空了，进行重填
	{
		pr->rio_cnt = read(pr->rio_fd, pr->rio_buf, sizeof(pr->rio_buf)); //读到内部缓冲中
		if(pr->rio_cnt < 0) 
		{
			if(errno != EINTR) //出错返回
				return -1;
		}
		else if(pr->rio_cnt == 0) //到文件末尾
			return 0;
		else
			pr->rio_pbuf = pr->rio_buf; //重置指针位置
	}
	//从内部缓冲拷贝数据到用户缓冲中
	cnt = (pr->rio_cnt < n)? pr->rio_cnt: n; //取两者之间的小的
	memcpy(usrbuf, pr->rio_pbuf, cnt);
	pr->rio_pbuf += cnt;
	pr->rio_cnt -= cnt;
	return cnt;
}
//带缓冲输入函数
ssize_t rio_readnb(rio_t *pr, void *usrbuf, size_t n)
{
	size_t nleft = n;
	ssize_t nread;
	char *pbuf = usrbuf;
	while(nleft > 0)
	{
		//与无缓冲的区别在于这里调用的是rio_read而不是read
		if((nread = rio_read(pr, pbuf, nleft)) < 0)
		{
			if(errno == EINTR)
				nread = 0;    //中断造成的,再次调用read
			else
				return -1;    //出错
		}
		else if(nread == 0)   //到了文件末尾
			break;
		nleft -= nread;
		pbuf += nread;
	}
	return n - nleft;
}
//带缓冲输入函数，每次输入一行
ssize_t rio_readlineb(rio_t *pr, void *usrbuf, size_t maxlen)
{
	int i, n;
	char c, *pbuf = usrbuf;
	for(i = 1; i < maxlen; i++)
	{
		if((n = rio_read(pr, &c, 1)) == 1) //读一个字符
		{
			*pbuf++ = c;
			if(c == '\n') //读到换行符
				break;
		}
		else if(n == 0)
		{
			if(i == 1) //空文件
				return 0;
			else       //读到了部分数据
				break;
		}
		else  //出错
			return -1;
	}
	*pbuf = 0; //添加字符串结束符
	return i;
}
 
#endif /* RIO_H_ */

