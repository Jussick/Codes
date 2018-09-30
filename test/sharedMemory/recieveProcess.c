//C file
/***********************************************
#
#      Filename: recieveProcess.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-09-26 15:05:48
#**********************************************/
#include"shared.h"

int main(int argc, char *argv[])
{
	STU *mm;
	int fd, i = 0;

	if (argc != 2)
	{
		printf("Usage: %s [filename]\n", argv[0]);
		exit(1);
	}

	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		sysErr("open", 1);

	mm = mmap(NULL, MAPLEN, PROT_READ, MAP_SHARED, fd, 0);
	if (mm == MAP_FAILED)
		sysErr("mmap", 2);

	close(fd);
	unlink(argv[1]);

	while (1)
	{
		printf("%d\n", mm-> id);
		printf("%s\n", mm-> name);
		printf("%c\n", mm-> sex);
		printf("-------------------\n");
		sleep(1);
	}

	munmap(mm, MAPLEN);
	return 0;
}
