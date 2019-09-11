//C++ file
/***********************************************
#
#      Filename: repeatThread.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-08-02 13:48:25
#**********************************************/
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

void hello() {
    cout << "hello world\n";
}

int main() {
    while (1) {
        thread td(hello);
        td.detach();
        sleep(1);
    }

    return 0;
}
