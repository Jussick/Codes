//C++ file
/***********************************************
#
#      Filename: getMD5.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-02-13 14:30:08
#**********************************************/
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

#define MD5LEN  32
#define MD5FILE "./md5.txt"

string GetMD5(string filePath)
{
    char cmd[128] = {0};
    sprintf(cmd, "%s%s%s%s", "md5sum ", filePath.c_str(), " > ", MD5FILE);
    system(cmd); 

    ifstream fin;
    fin.open(MD5FILE);
    char md5_value[256] = {0};
    fin.getline(md5_value, MD5LEN + 1);
    fin.close();

    remove(MD5FILE);

    return string(md5_value);
}

int main()
{
    string res = GetMD5("./test.cpp");
    std::cout << res << std::endl;
}
