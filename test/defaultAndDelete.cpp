//C++ file
/***********************************************
#
#      Filename: defaultAndDelete.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: =default和=delete的使用例子
#        Create: 2019-07-30 20:08:00
#**********************************************/
#include <iostream>

using namespace std;

class Student {
public:
    Student() = default;
    Student(int a, int b):m_a(a), m_b(b) {}

    // Student(const Student &) = delete;
    // Student& operator=(const Student &) = delete;

private:
    int m_a;
    int m_b;
    
    
};

int main() {
    //Student A(1,2);

    cout << is_pod<Student>::value << endl;

    // Student B(A);
    // Student C = A;

    return 0;
}
