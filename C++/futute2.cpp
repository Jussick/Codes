//C++ file
/***********************************************
#
#      Filename: futute.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-07-21 08:20:33
#**********************************************/
#include <iostream>
#include <thread>
#include <future>
#include <unistd.h>

void product(std::promise<int> &&p, int a, int b)
{
    int i = 3;
    while (i > 0)
    {
        std::cout << "left " << i << " seconds..." << std::endl;
        sleep(1);
        --i;
    }
    p.set_value(a*b);
}

int main()
{
    std::promise<int> promisei;
    std::future<int>  promiseRes = promisei.get_future();
    int a = 10, b = 20;
    std::thread thr(product, std::move(promisei), a, b);

    std::cout << promiseRes.get() << std::endl;
    thr.join();
}

