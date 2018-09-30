//C file
/***********************************************
#
#      Filename: writeProcess.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 通过共享内存的方式进行进程间的通信
#        Create: 2018-09-26 11:12:12
#**********************************************/
#include "shared.h"

int main(int argc, char *argv[])
{
	STU *mm;
	int fd, i = 0;

	if (argc != 2)
	{
		printf("Usage: %s [filename]\n", argv[0]);
		exit(1);
	}

	if ((fd = open(argv[1], O_RDWR | O_CREAT), 0700) < 0)
		sysErr("open", 1);	
	if (lseek(fd, MAPLEN - 1, SEEK_SET) < 0)
		sysErr("lseek", 2);
	if (write(fd, "\0", 1) < 0)
		sysErr("write", 3);

	mm = mmap(NULL, MAPLEN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if (mm == MAP_FAILED)
		sysErr("mmap", 4);

	close(fd);

	while (1)
	{
		mm-> id = i;
		sprintf(mm-> name, "Lu-%d", i);
		if (i % 2 == 0)
			mm-> sex = 'f';
		else
			mm-> sex = 'm';
		++i;
		sleep(1);
	}

	munmap(mm, MAPLEN);
	return 0;
}
