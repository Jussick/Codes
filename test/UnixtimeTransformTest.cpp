//C++ file
/***********************************************
#
#      Filename: UnixtimeTransformTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 把标准时间(YYYY-mm-dd HH:MM:SS)转换成unix时间戳的方法 
#        Create: 2021-03-29 16:49:52
#**********************************************/
#include <iostream>
#include <time.h>

using namespace std;

int TransformToUnixTimeStamp(string standardTime)
{
    struct tm *tmp_time = (struct tm*)malloc(sizeof(struct tm));
    strptime(standardTime.c_str(), "%Y-%m-%d %H:%M:%S", tmp_time);
    time_t timestamp = mktime(tmp_time);
    free(tmp_time);
    return (int)timestamp;
}

int main()
{
    string standardTime = "2021-3-29 17:08:23";
    int unixTimestamp = TransformToUnixTimeStamp(standardTime);
    cout << "before transform: " << standardTime << endl;
    cout << "after transform: " << unixTimestamp << endl;
}
