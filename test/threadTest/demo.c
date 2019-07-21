//C++ file
/***********************************************
#
#      Filename: demo.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-06-20 14:47:18
#**********************************************/
#include <stdio.h>
#include <pthread.h>


void *t_func(void *args) {
    printf("child pthread: %lu\n", pthread_self());
}

int main() {
    pthread_t pid;
    pthread_create(&pid, NULL, t_func, NULL);
    sleep(1);
    printf("main pthread: %lu\n", pthread_self());

    return 0;
}
