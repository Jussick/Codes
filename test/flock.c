//C file
/***********************************************
#
#      Filename: flock.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-07-27 10:00:18
#**********************************************/
#include <sys/file.h>
#include <stdio.h>

int main()
{
	int fd = open("./a.txt", O_WRONLY);
	if (flock(fd, LOCK_EX) < 0)
		printf("lock failed!\n");
	else
		printf("lock success!\n");
	
	printf("Enter to unlock:\n");
	getchar();
	
	if (flock(fd, LOCK_UN) < 0)
		printf("unlock failed!\n");
	else
		printf("unlock success!\n");

	return 0;
}
