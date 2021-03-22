//C++ file
/***********************************************
#
#      Filename: singleton.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 单例模式的现代实现方法，源自微信公众号上的一篇文章：https://mp.weixin.qq.com/s/3TcOcBOddHySBC0TVkpU9A
#        Create: 2020-10-10 13:44:16
#**********************************************/
#include <iostream>

using namespace std;

template <typename T>
class Singleton{
public:
    static T& GetInstance() {
        static T obj;
        return obj;
    }
    Singleton(const Singleton &other)  = delete;
    Singleton& operator=(const Singleton &other) = delete;

protected:
    Singleton() = default;
    ~Singleton() = default;

};

class Test:public Singleton<Test>{
public:
    void TestPrint() {
        cout << "hello" << endl;
    }
    Test() = default;
    ~Test() = default;
};

int main()
{
    Test::GetInstance().TestPrint();
    return 0;
}
