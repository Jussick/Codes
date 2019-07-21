//C++ file
/***********************************************
#
#      Filename: stringRotate.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 左旋字符串，要求：空间复杂度O(!),即原地旋转; 时间复杂度O(n)
#        Create: 2019-06-21 11:24:59
#**********************************************/
#include <iostream>
#include <string>

using namespace std;

/* 反转字符串 */
void reverseAString(string &str,size_t from, size_t to) {
    while (from < to) {
        char temp = str[from];
        str[from++] = str[to];
        str[to--] = temp;
    } 
}
/* 左旋字符串
 *
 * 参数：str 输入字符串
 *       pos 旋转到的位置
 * 方法：三部旋转法，如要把abc123左旋成123abc，分三步：
 *       1、abc -> cba
 *       2、123 -> 321
 *       3、cba321 -> 123abc
 * 详见：https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.01.md
 */
void leftRotateString(string &str, size_t pos) {
    size_t len = str.length();
    if (len == 0 || pos == len) return;
    if (pos > len) { cout << "Invalid position." << endl; return; }

    reverseAString(str, 0, pos - 1);
    reverseAString(str, pos, str.length() - 1);
    reverseAString(str, 0, str.length() - 1);
}

int main() {
    string str = "abcd";
    cout <<"str_original:" << str << endl;
    leftRotateString(str, 2);

    cout << "str_converse:" << str << endl;

    return 0;
}
