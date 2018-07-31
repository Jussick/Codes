#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sharei = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increaseNum(void *ptr)
{
	printf("%s is changing...\n", (char *)ptr);
	long i;
	pthread_mutex_lock(&mutex);
	for (i = 0; i < 10000000; i++)
		sharei++;
	pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t thd1, thd2, thd3;
	char * msg1 = "thread1";
	char * msg2 = "thread2";
	char * msg3 = "thread3";

	pthread_create(&thd1, NULL, increaseNum, (void *)msg1);
	pthread_create(&thd2, NULL, increaseNum, (void *)msg2);
	pthread_create(&thd3, NULL, increaseNum, (void *)msg3);

	pthread_join(thd1, NULL);
	pthread_join(thd2, NULL);
	pthread_join(thd3, NULL);

	printf("sharei=%d\n", sharei);

	return 0;
}
