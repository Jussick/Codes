//C file
/***********************************************
#
#      Filename: strongIO.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-31 14:10:09
#**********************************************/
#include "strongIO.h"
int main()
{
	int fd;
	char buf[256] = {0};
	rio_readn(STDIN_FILENO, buf, 256);
	//char *buf1 = "hello";
	rio_writen(STDOUT_FILENO, buf, strlen(buf));
	return 0;
}
