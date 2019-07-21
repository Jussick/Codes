//C++ file
/***********************************************
#
#      Filename: threadsTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 创建两个线程，一个joinable，一个detached；同时修改一个变量
#        Create: 2019-07-08 15:58:01
#**********************************************/
#include <iostream>
#include <unistd.h>

using namespace std;

typedef struct {
    int num;
    string msg;
}zuhe;

int i = 0;
pthread_rwlock_t rwlock;

void * threadFunc(void *msg) {
    zuhe * m_zuhe = (zuhe *)msg;
    while (i < m_zuhe->num) {
        cout << "this is " << m_zuhe->msg << endl;
        cout << "num is " << i << endl << endl;
        pthread_rwlock_wrlock(&rwlock);
        ++i;
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}
int main() {
    pthread_rwlock_init(&rwlock, NULL);
    zuhe *zuhe1 = new zuhe;
    zuhe *zuhe2 = new zuhe;
    zuhe1->num = 6;
    zuhe2->num = 9;
    zuhe1->msg = "thread1";
    zuhe2->msg = "thread2";

    pthread_t thread1;
    pthread_t thread2;

    pthread_attr_t thread1Attr;
    pthread_attr_t thread2Attr;

    pthread_attr_init(&thread1Attr);
    pthread_attr_init(&thread2Attr);

    //pthread_attr_setdetachstate(&thread1Attr, PTHREAD_CREATE_DETACHED);
    pthread_attr_setdetachstate(&thread2Attr, PTHREAD_CREATE_DETACHED);

    pthread_create(&thread1, &thread1Attr, threadFunc, (void *)zuhe1);
    pthread_create(&thread2, &thread2Attr, threadFunc, (void *)zuhe2);

    pthread_join(thread1, 0);
    //pthread_join(thread2, 0);

    return 0;
}
