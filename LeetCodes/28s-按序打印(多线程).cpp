//C++ file
/***********************************************
#
#      Filename: 01-按序打印.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: leetcode：1114
我们提供了一个类：

public class Foo {
  public void one() { print("one"); }
  public void two() { print("two"); }
  public void three() { print("three"); }
}
三个不同的线程将会共用一个 Foo 实例。

线程 A 将会调用 one() 方法
线程 B 将会调用 two() 方法
线程 C 将会调用 three() 方法
请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。

示例 1:

输入: [1,2,3]
输出: "onetwothree"
解释: 
有三个线程会被异步启动。
输入 [1,2,3] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用 three() 方法。
正确的输出是 "onetwothree"。
示例 2:

输入: [1,3,2]
输出: "onetwothree"
解释: 
输入 [1,3,2] 表示线程 A 将会调用 one() 方法，线程 B 将会调用 three() 方法，线程 C 将会调用 two() 方法。
正确的输出是 "onetwothree"。
 
注意:

尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。

你看到的输入格式主要是为了确保测试的全面性。

****解题思路****
利用两个全局标识位和两个条件变量来实现

#        Create: 2019-09-06 17:26:48
#**********************************************/
#include "leetcode.h"

using namespace std;
#define BIND_1(a) bind(a, this, placeholders::_1);

void one() {
    cout << "one";
}
void two() {
    cout << "two";
}
void three() {
    cout << "three" << endl;
}

class Foo {
    mutex mtx1;
    condition_variable cv1, cv2;
    bool one_run = false, two_run = false;
public:
Foo() {
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        unique_lock<mutex> locker(mtx1);
        //cv1.wait(locker);
        printFirst();
        one_run = true;
        cv1.notify_one();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> locker(mtx1);
        // printSecond() outputs "second". Do not change or remove this line.
        if (!one_run)
            cv1.wait(locker);
        printSecond();
        two_run = true;
        cv2.notify_one();
    }
 void third(function<void()> printThird) {
        unique_lock<mutex> locker(mtx1);
        // printThird() outputs "third". Do not change or remove this line.
        if (!two_run)
            cv2.wait(locker);
        printThird();
    }

    void _start() {

        string line;
        Foo foo;
        while (getline(cin, line)) 
        {
            vector<int> nums = stringToIntegerVector(line);
            for (int i : nums) 
            {
                switch (i) 
                {
                    case 1:
                       async((BIND_1(first)), one);
                    case 2:
                       async((BIND_1(second)), two);
                    case 3:
                       async((BIND_1(third)), three);

                }
            }                            
        }
    }
};

int main() {
    Foo foo;
    foo._start();
    return 0;
}
