//C++ file
/***********************************************
#
#      Filename: competeCondition.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 多线程资源竞争产生的线程安全问题的简单例子
#        Create: 2019-07-30 16:27:27
#**********************************************/
#include <iostream>
#include <thread>
#include <time.h>

#define THREAD_NUM 100000
using namespace std;

int count = 0;
void addCount() {
    ++count;
    cout << count << endl;
}

int count1 = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void addCount1() {
    pthread_mutex_lock(&mutex);
    ++count1;
    cout << count1 << endl;
    pthread_mutex_unlock(&mutex);
}

int main() {
    for (int i = 0; i < 10000; ++i) {
        thread th(addCount);
        th.detach();
    }
    getchar();
    cout << "count: " << count << endl;  // 期待输出count为10000，但结果并不能尽如人意，原因是count是竞争资源。
    getchar();

    // 解决方法是给共享操作加锁，以达到同步的功能
    for (int i = 0; i < THREAD_NUM; ++i) {
        try {  // 此处若不加try，catch程序因为线程数过多而停止
            thread th(addCount1);
            th.detach();
        } 
        catch(...) {
            --i;
            continue;
        }
    }
    getchar();
    cout << "count1: " << count1 << endl;
    getchar();

    return 0;
}
