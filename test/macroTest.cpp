//C++ file
/***********************************************
#
#      Filename: macroTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 宏定义中的#和##的作用
                    #是把宏参数转换为字符串
#                   ##是分隔符
#        Create: 2021-10-08 10:08:32
#**********************************************/
#include <iostream>

#define TEST(a, b) a##_##haha_##b
#define P(A) cout<<#A<<": "<<(A)<<endl;

using namespace std;

int main()
{
    char *aaa_haha_bbb = "wow";
    cout << TEST(aaa, bbb) << endl;  // wow

    int num = 123;
    P(num);  // num: 123

    return 0;
}
