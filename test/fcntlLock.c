#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/file.h>
#include<fcntl.h>


int main()
{
	struct flock f;
	memset(&f, 0, sizeof(f));
	f.l_type = F_WRLCK;
	f.l_whence = SEEK_SET;
	f.l_start = 0;
	f.l_len = 0;
	int fd = open("./id_rsa1524648325lululu2_2708", O_WRONLY);

	if ( fcntl(fd, F_SETLK, &f) < 0 )
		printf("lock fd failed.\n");
	else
		printf("lock fd success.\n");

	printf("press anykey to unlock.\n");
	getchar();

	f.l_type = F_UNLCK;
	if ( fcntl(fd, F_SETLK, &f) < 0 )
		printf("unlock fd failed.\n");

	close(fd);

	return 0;
}
