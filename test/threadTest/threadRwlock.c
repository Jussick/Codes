//C file
/***********************************************
#
#      Filename: threadRwlock.c
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 例子流程和mutex的一样, 只不过把mutex加锁方式换成了读写锁，演示读写锁的使用方法。
#        Create: 2019-06-20 16:59:23
#**********************************************/
#include <stdio.h>
#include <pthread.h>

int sharei = 0;  // 共享变量
pthread_rwlock_t rwlock;

void *increaseNum(void *str) {
    int i;
    printf("Thread %s is changing...\n", (char *)str);

    // 因为要修改共享变量的值，所以要上写锁
    pthread_rwlock_wrlock(&rwlock);

    for (i = 0; i < 10000000; ++i) {
        sharei++;
    }

    // 释放写锁
    pthread_rwlock_unlock(&rwlock);
}

int main() {
    // 读写锁初始化
    pthread_rwlock_init(&rwlock, NULL);

    pthread_t t1,t2,t3;

    char *msg1 = "Thread1";
    char *msg2 = "Thread2";
    char *msg3 = "Thread3";

    // 线程创建
    pthread_create(&t1, NULL, increaseNum, (void *)msg1);
    pthread_create(&t2, NULL, increaseNum, (void *)msg2);
     pthread_create(&t3, NULL, increaseNum, (void *)msg3);

    // 主线程等待线程执行完毕
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("sharei: %d\n", sharei);

    // 销毁读写锁
    pthread_rwlock_destroy(&rwlock);

    return 0;
}
