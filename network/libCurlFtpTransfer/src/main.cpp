//C++ file
/***********************************************
#
#      Filename: test.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 可断点续传的使用libcurl的ftp传输例子. 在ubuntu14.04上编译通过
#        Create: 2020-04-15 10:48:17
#**********************************************/
#include <iostream>
#include "FTPTransfer.h"
#include <unistd.h>
#include <sstream>

using namespace std;

int main()
{
    FTPTransfer client;
    client.FtpOptionInfoSet("gosunyun", "gsy2017");
    string upload_path = "ftp://192.168.42.18/offlineData/Makefile";

    // get curruent absolute path
    char curPath[128] = {0};
    getcwd(curPath, 128);

    // set upload file path
    stringstream ss;
    ss << curPath << "/Makefile";
    string upload_file_path = ss.str();
    cout << upload_file_path << endl;

    
    int ret = client.FtpUpload(upload_path.c_str(), upload_file_path.c_str(), 10);
    ret==1?cout << "上传成功" << endl:cout << "上传失败" << endl;
}

