//C++ file
/***********************************************
#
#      Filename: copyFile.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 利用文件流的方法实现文件拷贝
#        Create: 2019-07-31 15:01:26
#**********************************************/
#include <iostream>
#include <fstream>


using namespace std;

int main() {
    fstream infile("1.txt", ios::in);
    if (!infile.is_open()) {
        cout << "源文件打开失败" << endl;
        return 0;
    }

    fstream outfile("2.txt", ios::out);
    if (!outfile.is_open()) {
        cout << "目标文件打开失败" << endl;
        return 0;
    }

    outfile << infile.rdbuf();

    infile.close();
    outfile.close();

    return 0;
}
