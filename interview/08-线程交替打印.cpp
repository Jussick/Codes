//C++ file
/***********************************************
#
#      Filename: main.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 百度面试题：两个线程，第一个打印A，第二个打印1，要求按顺序打印A1A1A1A1.....
                 不许使用sleep，usleep函数
#        Create: 2021-08-05 20:37:12
#**********************************************/
#include <iostream>
#include <thread>
#include <mutex>

std::mutex my_lock;
std::condition_variable c_v;
int flag = 0;

void fun1()
{
    while (1)
    {
        std::unique_lock<std::mutex> lck(my_lock);    
        while (flag == 1)
        {
            c_v.wait(lck);
        }
        std::cout << "A";
        flag = 1;
        c_v.notify_all();
    }
}

void fun2()
{
    while (1)
    {
        std::unique_lock<std::mutex> lck(my_lock);    
        while (flag == 0)
        {
            c_v.wait(lck);
        }
        std::cout << "1";
        flag = 0;
        c_v.notify_all();
    }
}

int main()
{
    std::thread t1(fun1);
    std::thread t2(fun2);

    t1.join(); 
    t2.join(); 

    return 0;
}

