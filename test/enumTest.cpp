//C++ file
/***********************************************
#
#      Filename: enumTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-07-29 13:56:50
#**********************************************/
#include <iostream>
#include <stdio.h>
using namespace std;

enum errno_set { 
    SUCCESS = 200, 
    LACK_PARAS = 1001, 
    DATA_CHECK_NOT_PASS , 
    PARTIAL_SUCCESS , 
    REQUEST_TYPE_IS_NULL , 
    REQUEST_TYPE_NOT_EXIST , 
    DATA_CHECK_ERR ,
    INTERNAL_SERVICE_ERR = 1101,
    IP_ACCESS_NOT_ALLOWED ,
    OVER_ACCESS_MAX_NUM
    
};


int main() {
    errno_set ee;
    ee = DATA_CHECK_ERR;
    cout << ee << endl;
    return 0;
}
