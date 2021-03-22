//C++ file
/***********************************************
#
#      Filename: test_api.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-10-09 16:21:09
#**********************************************/
#include <iostream>
#include "test_api.h"

using namespace std;

class TestApi::TestImpl{
    public:
        TestImpl(int num):m_start(num){}
        ~TestImpl(){}
        void TestPrint(int toNum);
    private:
        int m_start = 0;
};

void TestApi::TestImpl::TestPrint(int toNum)
{
    if (toNum < m_start)
    {
        cout << "end number is less than start" << endl;
        return;
    }
    for (int i = m_start; i <= toNum; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
    return;
}

TestApi::TestApi(int num)
{
    m_test_impl = new TestImpl(num);
}


void TestApi::TestPrint(int toNum)
{
    m_test_impl->TestPrint(toNum); 
}
