//C++ file
/***********************************************
#
#      Filename: fileStatTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: linuxC获取文件的创建时间，最后修改时间和最后访问时间的方法
#        Create: 2021-03-30 15:50:12
#**********************************************/
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


using namespace std;

int main()
{
    string file = "./result.txt";
    struct stat buf;
    int result = stat(file.c_str(), &buf);

    cout << "file: " << file << endl;
    /* cout << "createTime: " << ctime(&buf.st_ctime) << endl;
    cout << "modifyTime: " << ctime(&buf.st_mtime) << endl;
    cout << "accessTime: " << ctime(&buf.st_atime) << endl;
    cout << "fileSize: "   << buf.st_size << endl; */

    cout << "createTime: " << buf.st_ctime << endl;
    cout << "modifyTime: " << buf.st_mtime << endl;
    cout << "accessTime: " << buf.st_atime << endl;
}
