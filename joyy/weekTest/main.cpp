//C++ file
/***********************************************
#
#      Filename: main.cpp
#
#        Author: luhg - luhengguang@joyy.com
#   Description: ---
#        Create: 2021-12-14 20:06:33
#**********************************************/
#include <iostream>
#include "partition_date.h"

using namespace std;
using namespace cim;

int main()
{
    time_t timenow = time(NULL);
    common::Week week(timenow);
    std::string pdate = week.GetPartitionDate();

    cout << pdate << endl;
}
