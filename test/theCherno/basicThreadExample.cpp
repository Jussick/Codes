//C++ file
/***********************************************
#
#      Filename: basicThreadExample.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-12-28 19:32:43
#**********************************************/
#include <iostream>
#include <thread>
#include <chrono>

static bool work_done = false;


void working()
{
    std::cout << "current thread id:" << std::this_thread::get_id() << std::endl;
    while (!work_done)
    {
        std::cout << "Working..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Finished." << std::endl;
}

int main()
{
    std::thread t1(working);  // child thread start

    std::cin.get();  // main thread block, child thread continue execute
    work_done = true;  // let child thread over

    t1.join();  // wait for child thread complete
    std::cin.get();
    std::cout << "main thread id:" << std::this_thread::get_id() << std::endl;

    return 0;
}

