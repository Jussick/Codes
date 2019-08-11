//C++ file
/***********************************************
#
#      Filename: lambdaTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: lambda函数的使用方法
#        Create: 2019-08-08 11:07:50
#**********************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 随机生成10个10以内的vector元素
    vector<int> vv(10);
    srand(time(0));
    std::generate(vv.begin(), vv.end(), std::rand);
    for (auto it = vv.begin(); it != vv.end(); ++it) {
        *it %= 100;
    }
    for (int i: vv) { cout << i << " "; }
    cout << endl;

    // 计算能被二整除的元素个数
    int count = count_if(vv.begin(), vv.end(), [](int n) { return n % 2 == 0; });  // 最后一个参数的写法就是lambda函数，[]表示自动推断返回类型，这里是bool
    cout << "count: " << count << endl;

    // 第二种写法，在[]中括号里写上想要访问的变量
    // 直接用变量名表示值访问，加&表示引用访问；[=]表示所有都用值访问；[&]表示所有都用引用访问；[&, num]表示除num之外用值访问，其他都用引用访问；[=, &num]同理
    int count_2 = 0;
    for_each(vv.begin(), vv.end(), [&count_2](int n) { count_2 += n % 2 == 0; });
    cout << "count_2: " << count_2 << endl;

    // 通过上面这种技术，可以在一次遍历过程中同时计算可被2和3整除的元素个数
    int count2 = 0;
    int count3 = 0;

    for_each(vv.begin(), vv.end(), [&count2, &count3](int n) { count2 += n % 2 == 0; count3 += n % 3 == 0; });
    cout << "count2: " << count2 << "\tcount3: " << count3 << endl;
}
