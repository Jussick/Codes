//C++ file
/***********************************************
#
#      Filename: 32-从1到n整数中1出现的次数.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-03-26 13:56:10
#**********************************************/
#include<iostream>

using namespace std;

int numberOf1Between1Andn(int num) {
    if (num == 0) return 0;

	// 通过对每个数字对10取余判断个位是不是1，如果该数大于10，除以10再进行余10操作。
    int res = 0;
    for (int i = 0; i <= num; ++i) {
        int temp_i = i;
        if (temp_i % 10 == 1) { cout << i << " "; res++; }

        while ( temp_i >= 10) {
            temp_i /= 10;
            if (temp_i % 10 == 1) {
                cout << i << " ";
                res++;
            }
        }
    }
    return res;
}

int main() {

    int num = 22;
    int res = numberOf1Between1Andn(num);
    cout << "res:" << res << endl;

    return 0;
}
