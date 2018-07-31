//C++ file
/***********************************************
#
#      Filename: 02-函数返回引用.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-06-29 12:36:19
#**********************************************/
#include<iostream>
#include<string>

using namespace std;

struct myType{
	string name;
	string sex;
};
myType &modify(myType &aaa)  // 此处的函数返回值定义为引用，即直接把aaa在下面赋值给bbb了，效率较高；
							 // 若改为直接返回myType类型的值，则在返回时会创建一个临时myType类型的变量，并把此变量赋值给bbb。
{
	aaa.name = "Lucas";
	aaa.sex = "man";
	return aaa;
}
int main()
{
	myType aaa, bbb;
	bbb = modify(aaa);
	cout << "aaa.name = " << aaa.name << ", aaa.sex = " << aaa.sex << endl;
	cout << "bbb.name = " << bbb.name << ", bbb.sex = " << bbb.sex << endl;

}
