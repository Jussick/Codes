//C++ file
/***********************************************
#
#      Filename: ShowDirFilesTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2021-03-30 11:22:04
#**********************************************/
#include <iostream>
#include <dirent.h>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

void FindFiles(string root ,vector<string> &files){
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (root.c_str())) != NULL) {

        while ((ent = readdir (dir)) != NULL) {
            if(!strcmp(ent->d_name,".")||!strcmp(ent->d_name,".."))
                continue;
            files.push_back(ent->d_name);

        }
        closedir (dir);
    }
}

int main()
{
    vector<string> fileList;
    FindFiles(".", fileList);

    for (auto file : fileList)
    {
        cout << file << ", ";
    }
    cout << endl;
}
