//C++ file
/***********************************************
#
#      Filename: main.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: PIMPL是pointer to implementation 的缩写，即由指针指向类的实现细节，可以降低耦合，提高程序的可维护性
#        Create: 2020-10-09 16:20:23
#**********************************************/
#include <iostream>
#include "test_api.h"

using namespace std;


int main()
{
    TestApi testapi(3);
    testapi.TestPrint(5);
}
