//C++ file
/***********************************************
#
#      Filename: 2-递归练习.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-09-07 14:36:21
#**********************************************/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

/* 递归反向打印字符串 */
void ReverseString(const char *str)
{
    if (!*str)
    {
        return;
    }
    ReverseString(str + 1);
    putchar(*str);
}


/* O(1)额外空间递归反转字符串 */
void helper(int beg, int end, char *s)
{
    if (beg > end)
        return;

    char temp = s[beg];
    s[beg] = s[end];
    s[end] = temp;

    helper(beg+1, end-1, s);
}
void ReverseStringRecur(char *str)
{
    int length = strlen(str);
    helper(0, length-1, str);
}



/* 迭代法反转字符串 */
void swap(int beg, int end, char *s)
{
    char temp = *(s+beg);
    *(s+beg) = *(s+end);
    *(s+end) = temp;
}
void ReverseStringIter(char *str)
{
    int length = strlen(str); 
    int beg = 0;
    int end = length - 1;
    while (beg < end)
    {
        swap(beg, end, str);
        beg++;
        end--;
    }
}

int main()
{

    char str[5] = "abcd";
    ReverseStringIter(str);
    ReverseStringRecur(str);
    cout << str << endl;
}
