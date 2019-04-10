//C++ file
/***********************************************
#
#      Filename: ttt.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2019-03-11 18:39:15
#**********************************************/
#include<iostream>
#include<time.h>

using namespace std;


int RandomInRange(int min, int max)
{
    cout << "min: " << min << " max: " << max << endl;
    srand((unsigned int)(time(NULL)));
    int randomNum = rand();
    cout << "randomNum: " << randomNum << endl;
    randomNum %= max;
    cout << "randomNum %= max: " << randomNum << endl;

    return randomNum;

}

int main()
{
    cout << RandomInRange(0,7) << endl;
    return 0;
}
