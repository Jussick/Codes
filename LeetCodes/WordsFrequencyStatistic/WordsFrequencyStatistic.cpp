//C++ file
/***********************************************
#
#      Filename: WordsFrequencyStatistic.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 找出一段英文文本中每个单词出现的频次
#        Create: 2020-05-13 00:34:51
#**********************************************/
#include <iostream>
#include <fstream>

using namespace std;

void showContentOfFile(const char *filename)
{
    ifstream fin;
    fin.open(filename);
    char line[256];
    cout << "file content is: " << endl;
    while (fin.getline(line, 256))
        cout << line;
    fin.close();
}


int main()
{
    FILE *fp = fopen("./English.txt", "r");
    char line[1024] = {0};
    while (!feof(fp))
    {
        fgets(line, sizeof(line), fp);
        cout << line;
    }
    fclose(fp);

    return 0;

}
