//C++ file
/***********************************************
#
#      Filename: hub.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-07-08 18:39:57
#**********************************************/
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;



/*
 * 获取时间戳
 */
string getTimeStamp() {
    time_t tnow;
    // 获取时间
    time(&tnow);
    struct tm * tmnow = localtime(&tnow);
    char cTime[32] = { 0 };
    sprintf(cTime,"%04d%02d%02d%02d%02d%02d",tmnow->tm_year + 1900,tmnow->tm_mon + 1,tmnow->tm_mday,tmnow->tm_hour,tmnow->tm_min,tmnow->tm_sec);
    string strTime;
    strTime.assign(cTime);
    return strTime;
}
/*
 * 无敌类型转换（利用stringstream实现任何类型间的转换）
 * 用法：
        typeA A;
        typeB B;
        A = convert<typeB, typeA>(B); 
 */
template <typename old_type, typename new_type>
new_type convert(old_type &data) {
    stringstream ss;
    ss << data;
    new_type out_data;
    ss >> out_data;

    return out_data;
}

int main() {
    string timenow = getTimeStamp();
    cout << timenow << endl;
    return 0;
}

