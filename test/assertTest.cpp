//C++ file
/***********************************************
#
#      Filename: assertTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: assert宏的测试，不生效测试
#        Create: 2020-10-10 15:35:43
#**********************************************/

// #define NDEBUG  // 若打开这句话assert就不生效了
#include <iostream>
#include <cassert>

using namespace std;

int main()
{
    void *p = NULL;
    assert(p != NULL);
}
