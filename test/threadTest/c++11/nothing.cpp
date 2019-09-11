//C++ file
/***********************************************
#
#      Filename: conditionThread_order.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 条件变量的使用。（自定义顺序执行）
                 三个线程，线程1等待线程2的信号，线程2等待线程3的信号，线程3执行完后，线程2和线程1再继续执行
                 这里由于三个线程是按照1,2,3的顺序执行的，故本程序能如预期执行，但如果切换了线程的启动顺序，如先执行线程3，就会使程序陷入死锁；
                 解决方法是添加两个线程是否执行过的标志位，在wait之前增加一步判断。
#        Create: 2019-08-13 19:15:06
#**********************************************/
#include <iostream>
#include <thread>
#include <condition_variable>
#include <future>

using namespace std;

mutex mtx;  // 互斥锁
condition_variable cv;  // 条件变量
condition_variable cv2;  // 条件变量

void func1(const string &threadName) {
    unique_lock<mutex> locker(mtx);
    cout << threadName << ": wait for func2 to notify\n";
    cv.wait(locker);
    cout << threadName << ": got pass from func2!\n";
}

void func2(const string &threadName) {
    unique_lock<mutex> locker(mtx);
    cout << threadName << ": wait for func3 to notify\n";
    cv2.wait(locker);
    cout << threadName << ": Got pass from func3, send pass signal to func1 in 2 secs\n";
    this_thread::sleep_for(chrono::seconds(2));
    cv.notify_one();
}

void func3(const string &threadName) {
    unique_lock<mutex> locker(mtx);
    cout << threadName << ": send pass signal in 1 sec\n"; 
    this_thread::sleep_for(chrono::seconds(1));
    cv2.notify_one();
}

int main() {

    // 可代替下面的写法
    auto f1 = async(launch::async, func1, "Thread1");
    auto f2 = async(launch::async, func2, "Thread2");
    auto f3 = async(launch::async, func3, "THread3");

    // thread t1(func1, "thread1");  
    // thread t2(func2, "thread2");  
    // thread t3(func3, "thread3");
    // t1.join();
    // t2.join();
    // t3.join();
}
