//C++ file
/***********************************************
#
#      Filename: 02-列表初始化.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-10-12 11:24:59
#**********************************************/
#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

template <class T>
struct S {
    std::vector<T> v;
    S(std::initializer_list<T> l):v(l) {
        cout << "constructed with a " << l.size() << " element list!" << endl;
    }


    void append(std::initializer_list<T> l) {
        v.insert(v.end(), l.begin(), l.end());
    }

    void print() {
        for (auto item : v) {
            cout << item << " ";
        }
        cout << endl;
    }

}; 

int main()
{
    S<int> ss{1,2,3};
    ss.print();
    ss.append({4,5,6});
    ss.print();
}
