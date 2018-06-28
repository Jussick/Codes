#include<sys/time.h>
#include<stdio.h>
#include<unistd.h>


int main()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	printf("second:%ld\n", tv.tv_sec);
	printf("msecond:%ld\n", tv.tv_sec*1000 + tv.tv_usec/1000);
	printf("usecond:%ld\n", tv.tv_sec*1000000 + tv.tv_usec);

	sleep(2);

	gettimeofday(&tv, NULL);
	printf("second:%ld\n", tv.tv_sec);
	printf("msecond:%ld\n", tv.tv_sec*1000 + tv.tv_usec/1000);
	printf("usecond:%ld\n", tv.tv_sec*1000000 + tv.tv_usec);
	
	return 0;
}
