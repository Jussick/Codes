//C++ file
/***********************************************
#
#      Filename: random.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 对二进制文件随机读写的例子
#        Create: 2018-08-31 11:27:37
#**********************************************/
#include "random.h"

int main()
{
	Planet p;
	const char* file = "planet.dat";
	fstream finout(file, ios_base::in | ios_base::out | ios_base::binary);

	cout << "Here is the content of file:" << endl;
	int total_num = showBinaryFile(file);

	cout << "Enter the sequence number you want to modify:";
	char sequence_num[5];
	cin >> sequence_num;
	cout << IsDigit(sequence_num) << endl;
	while (!IsDigit(sequence_num) ||  atoi(sequence_num) > total_num || atoi(sequence_num) < 0)
	{
		//eatline();
		cout << "Input number invalid, please input again." << endl;
		//sleep(1);
		cout << "Enter the sequence number you want to modify:";
		cin >> sequence_num;
	}
	streampos place = atoi(sequence_num) * sizeof(p);
	finout.seekg(place);  // 读文件流设置文件指针
	memset(p.name, 0, sizeof(p.name));
	finout.read((char *)&p, sizeof(p));
	cout << "Your selection: " << p;

	eatline();
	cin >> p;
	finout.seekp(place);  // 写文件流设置文件指针
	finout.write((char *)&p, sizeof(p));

	finout.close();
	cout << "Here is the file conten after modify: " << endl;
	showBinaryFile(file);
	cout << "Done." << endl;

	return 0;
}
