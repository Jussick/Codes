//C file
/***********************************************
#
#      Filename: perrorTest.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-09-25 11:24:19
#**********************************************/
#include<stdio.h>

int main()
{
	FILE *fd;
	fd = fopen("asdas.txt", "r");
	if (fd == NULL)
	{
		perror("Error");
		return -1;
	}
	fclose(fd);

	return 0;
}
