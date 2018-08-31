//C++ file
/***********************************************
#
#      Filename: 13-文件的输入输出.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-30 11:22:04
#**********************************************/
#include <cstring>
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
		cout << line << endl;
	fin.close();
}

// defined for next function
typedef struct {
	char name[20];
	//string name;  不能用string代替char*，因为在写入二进制文件时，string只会把地址写进去!!!!!!
	int age;
}Person;

// 二进制文件的读写
void writeAndReadBinaryFile()
{
	// 以二进制方式把结构体写入文件
	Person p;
	p.age = 24;
	strcpy(p.name, "Edward");
	ofstream fout("./things/binary.dat", ios_base::out | ios_base::binary);
	fout.write((char *)&p, sizeof(p));
	fout.close();

	// 读二进制文件
	ifstream fin("./things/binary.dat", ios_base::in | ios_base::binary);	
	Person p1;
	fin.read((char *)&p1, sizeof(p1));
	cout << "read from binary.dat:" << endl;
	cout << "p1.age: " << p1.age << endl;
	cout << "p1.name: " << p1.name<< endl;
	fin.close();
}

int main()
{
#if 0
	string filename = "./things/testfile";
	// 创建写文件流, 第二个参数指明打开方式，ofstream默认是ios_base::out('w')
	ofstream fout(filename.c_str(), ios_base::app);  // 注意文件名要传入C风格字符串
	/* 或者用下面这种方式创建 */
	// ofstream fout;
	// fout.open(filename.c_str());

	if (fout.fail())  // 打开文件状态判断
	{
		cout << "write stream open failed." << endl;
		fout.clear();  // not necessary, but harmless.
		return -1;
	}
	// 向文件中写内容
	fout << "This is a write test." << endl;
	fout << "This is a write test2." << endl;
	fout.close();

	// 创建读文件流，第二个参数指明打开方式，ifstream默认是ios_base::in('r')
	ifstream fin(filename.c_str());
	if (!fin.is_open())  // 这种判断文件流是否创建成功方式更优
	{
		cout << "read stream open failed." << endl;
		fin.clear();
		return -1;
	}
	// 读取文件内容
	showContentOfFile("./things/testfile");
#endif
	writeAndReadBinaryFile();

	return 0;
}
