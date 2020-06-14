//C++ file
/***********************************************
#
#      Filename: 18-future.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-05-22 08:37:46
#**********************************************/
#include <iostream>
#include <future>
#include <chrono>

/* 素数 */
bool is_prime(int x)
{
    for (int i = 2; i < x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    std::future<bool> fut = std::async(is_prime, 444444443);

    std::cout << "checking... please wait..." << std::endl;
    
    std::chrono::milliseconds span(100);
    while (fut.wait_for(span) == std::future_status::timeout)
    {
        std::cout << ".\n";
    }

    bool res = fut.get();
    std::cout << "res: " << res << std::endl;
}
