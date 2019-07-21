//C++ file
/***********************************************
#
#      Filename: bindTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-07-05 09:24:16
#**********************************************/
#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;

typedef function<void (int, int)> functional;

// 定义一个普通函数
void printAandB(int a, int b)
{
    cout << a << " " << b << endl;
}

// 定义一个简单的类
class Test{
public:
    Test() {}
    ~Test() {}
    int foo(int i) { return i; }
};
int main()
{
    /* 1、普通函数的绑定 */

    // func1绑定了printAandB函数并把两个参数传递位置调换了
    functional func1 = bind(printAandB, _2, _1);  // 此处的functional也可用auto代替
    cout << "最普通的函数绑定: " << endl;
    func1(1, 2);

    // func2绑定了printAandB并把第一个参数固定了 
    function<void (int)> func2 = bind(printAandB, 111, _1);  // 开头的类型亦可用auto代替
    cout << "普通函数的固定参数绑定:" << endl;
    func2(2);



    /* 2、类成员函数的绑定 */
    Test testobj;
    function<int (int)> func3 = bind(&Test::foo, testobj, _1);  // 绑定类成员函数时，bind的第二个参数是绑定的类对象
    cout << "类成员函数绑定：" << endl;
    cout << func3(333) << endl; 

    return 0;
}
