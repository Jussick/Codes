//C++ file
/***********************************************
#
#      Filename: chronoTimeTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 利用chrono头文件库实现高精度计时
                 下面两种方法若是用time头文件则看不出区别，因为经过时间都是在微秒级别的
#        Create: 2019-08-14 11:11:21
#**********************************************/
#include <iostream>
#include <chrono>
#include <vector>
#define MAX 10000000

using namespace std;

int main() {
    // 数组构建vec方法
    auto start = chrono::high_resolution_clock::now();
    double *arr = new double[MAX+1];
    for (int i = 0; i < MAX; ++i) {
        arr[i] = i;
    }
    vector<double> vec(arr, arr+MAX);
    auto eclapsed = chrono::high_resolution_clock::now() - start;
    cout << "duration for construct arr: " << chrono::duration_cast<chrono::microseconds>(eclapsed).count() << "us." << endl;

    // 直接push_back方法
    start = chrono::high_resolution_clock::now();
    vector<double> vec2;
    for (int i = 0; i < MAX; ++i) {
        vec2.emplace_back(i); 
 }
    eclapsed = chrono::high_resolution_clock::now() - start;
    cout << "duration for construct vec: " << chrono::duration_cast<chrono::microseconds>(eclapsed).count() << "us." << endl;

    return 0;
}
