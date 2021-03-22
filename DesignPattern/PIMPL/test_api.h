#ifndef _TEST_API_H
#define _TEST_API_H

class TestApi{
    public:
        TestApi(int num);
        // ~TestApi(){}
        void TestPrint(int toNum);
    private:
        class TestImpl;
        TestImpl *m_test_impl;
        // int m_start = 0;
};


#endif
