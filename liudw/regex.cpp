//C++ file
/***********************************************
#
#      Filename: regex.cpp
#
#        Author: luhg - luhengguang@joyy.com
#   Description: 正则匹配的使用
#        Create: 2021-11-26 17:03:38
#**********************************************/
#include <iostream>

using namespace std;
#include <sys/types.h>
#include <regex.h>
#include <stdio.h>

int main(int argc, char ** argv)
{
    if (argc != 3) {
        printf("Usage: %s RegexString Text\n", argv[0]);
        return 1;
    }
    const char * pregexstr = argv[1];
    const char * ptext = argv[2];
    regex_t oregex;
    int nerrcode = 0;
    char szerrmsg[1024] = {0};
    size_t unerrmsglen = 0;
    if ((nerrcode = regcomp(&oregex, pregexstr, REG_EXTENDED|REG_NOSUB)) == 0) {
        if ((nerrcode = regexec(&oregex, ptext, 0, NULL, 0)) == 0)    {
            printf("%s matches %s\n", ptext, pregexstr);
            regfree(&oregex);
            return 0;
        }
    }
    unerrmsglen = regerror(nerrcode, &oregex, szerrmsg, sizeof(szerrmsg));
    unerrmsglen = unerrmsglen < sizeof(szerrmsg) ? unerrmsglen : sizeof(szerrmsg) - 1;
    szerrmsg[unerrmsglen] = '\0';
    printf("ErrMsg: %s\n", szerrmsg);
    regfree(&oregex);

    return 1;
}

// 示例输入输出
/* ./a.out "^[a-zA-Z0-9]+@[a-zA-Z0-9]+.[a-zA-Z0-9]+" "ldw@itcast.com"
ldw@itcast.com matches ^[a-zA-Z0-9]+@[a-zA-Z0-9]+.[a-zA-Z0-9]+

./a.out "^[a-zA-Z0-9]+@[a-zA-Z0-9]+.[a-zA-Z0-9]+" "ldwitcast.com"
ErrMsg: No match */
