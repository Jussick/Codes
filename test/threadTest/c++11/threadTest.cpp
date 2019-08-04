//C++ file
/***********************************************
#
#      Filename: threadTest.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-07-28 13:25:41
#**********************************************/
#include <iostream>
#include <thread>

using namespace std;

void sayHello() {
    cout << "hello thread\n";
}

int main() {
    thread *t1 = new thread(sayHello);
    thread *t2 = new thread(sayHello);
    t1->join();
    t2->join();

    return 0;
}
