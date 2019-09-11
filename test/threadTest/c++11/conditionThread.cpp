//C++ file
/***********************************************
#
#      Filename: conditionThread.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 网上条件变量的例子
#        Create: 2019-08-13 11:22:47
#**********************************************/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;  // 全局互斥锁
std::condition_variable cv;  // 全局条件变量
bool ready = false;  // 全局标识位

void print_id(int id) {
    std::unique_lock<std::mutex> locker(mtx);
    while (!ready) {
        cv.wait(locker);
    }
    std::cout << "thread" << std::this_thread::get_id() << std::endl;
}

void go() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::unique_lock<std::mutex> locker(mtx);
    ready = true;
    cv.notify_all();
}

int main() {
    std::thread threads[10];
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(print_id, i);
    }

    std::cout << "There are 10 threads about to run..." << std::endl;
    int n = std::thread::hardware_concurrency();
    std::cout << "There are " << n << " cores to execute tasks." << std::endl;

    go();

    for (auto &th: threads)
        th.join();

    return 0;
}
