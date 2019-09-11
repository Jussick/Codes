//C++ file
/***********************************************
#
#      Filename: asyncTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: async的用法, 大型计算利用多线程加速
#        Create: 2019-08-08 16:37:59
#**********************************************/
#include <iostream>
#include <numeric>  // added for accumulate
#include <vector>
#include <thread>
#include <future>
#include <time.h>  // 用来计时

using namespace std;
#define MAX 1000000000

double accum(double *bgn, double *end, double init) {
    // accumulate是STL中算法，包含在<numeric>中, 用于计算累加和
    return accumulate(bgn, end, init);  // 前两个参数是容器区间，最后参数为初始值
}

int main() {
    clock_t start;
    clock_t end;

    // 构建大向量
    cout << "construct big vector...\n";
    double *arr = (double *)calloc(MAX + 1, sizeof(double));  // 此处用new会导致下面赋值时出现段错误，原因未知
    for (int i = 0; i < MAX; ++i) {
        arr[i] = i;
    }
    vector<double> vec(arr, arr+MAX);
    cout << "Big vector construct success." << endl << endl;;
    this_thread::sleep_for(chrono::seconds(1));  // 休眠


// 单线程计算
    cout << "Not using multithread: " << endl;
    start = clock();
    double sum = accumulate(vec.begin(), vec.end(), 0.0);
    end = clock();
    cout << "sum: " << sum << endl;
    cout << "time consume: " << (double)((end - start) / CLOCKS_PER_SEC) << "s." << endl << endl;

    this_thread::sleep_for(chrono::seconds(1));  // 休眠
    
    cout << "Using multithread: " << endl;
    // 多线程计算，加速效果明显
    /*
     * async第一个参数是线程的创建策略，有两个：
     *     * std::launch::async：在调用async就开始创建线程。
     *     * std::launch::deferred：延迟加载方式创建线程。调用async时不创建线程，直到调用了future的get或者wait时才创建线程。
     * 第二个参数是线程函数，往后的参数是线程函数的参数。
     */
    start = clock();
    double *begin = &vec[0];
    auto size = vec.size();
    auto f0 = async(accum, begin, begin + size/4, 0.0);  // 这里用了4个线程并行计算，如果数据更大可以起更多的线程
    auto f1 = async(accum, begin + size/4, begin + size/2, 0.0);
    auto f2 = async(accum, begin + size/2, begin + size*3/4, 0.0);
    auto f3 = async(accum, begin + size*3/4, begin + size, 0.0);

    sum = f0.get()+f1.get()+f2.get()+f3.get();  // get方法获取线程返回结果
    end = clock();

    cout << "sum: " << sum << endl;
    cout << "time consume: " << (double)((end - start) / CLOCKS_PER_SEC) << "s." << endl << endl;

    return 0;
}
