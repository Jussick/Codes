#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sharei = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increaseNum(void *ptr)
{
	printf("%s is changing...\n", (char *)ptr);
	long i;
	// 在这里执行对共享数据的加解锁操作，若不加锁则会因线程同时运行，访问相同变量导致结果错误.
	pthread_mutex_lock(&mutex);
	for (i = 0; i < 10000000; i++)
		sharei++;
	// 解锁
	pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t thd1, thd2, thd3;
	const char * msg1 = "thread1";
	const char * msg2 = "thread2";
	const char * msg3 = "thread3";

	pthread_create(&thd1, NULL, increaseNum, (void *)msg1);
	pthread_create(&thd2, NULL, increaseNum, (void *)msg2);
	pthread_create(&thd3, NULL, increaseNum, (void *)msg3);

	pthread_join(thd1, NULL);
	pthread_join(thd2, NULL);
	pthread_join(thd3, NULL);

	printf("sharei=%d\n", sharei);

	return 0;
}
