//C++ file
/***********************************************
#
#      Filename: promiseFutureTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: promise, future和packaged_task的使用
#        Create: 2019-08-14 16:39:03
#**********************************************/
#include <iostream>
#include <future>
#include <exception>
#include <thread>

using namespace std;

int ff(int i) {
    if (i) return i;
    throw runtime_error("ff(0)");
}

int main() {
    packaged_task<int(int)> pt1{ff};  // 将ff保存在pt1中
    packaged_task<int(int)> pt2{ff};  // 将ff保存在pt2中

    pt1(1);  // 让pt1调用ff(1)
    pt2(0);  // 让ptr调用ff(0)
    // 此时什么反应也没有

    auto f1 = pt1.get_future();
    auto f2 = pt2.get_future();

    try {
        cout << f1.get() << endl;  // 打印
        cout << f2.get() << endl;  // 抛出异常
    }
    catch(exception &e) {
        cout << "exception: " << e.what() << endl;
    }
}
