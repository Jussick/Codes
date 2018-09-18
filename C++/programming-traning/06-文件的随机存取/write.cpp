//C++ file
/***********************************************
#
#      Filename: write.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: Insert content into binary file "planet.dat"
#        Create: 2018-09-03 11:25:02
#**********************************************/
#include "random.h"
int main()
{
	const char* file = "planet.dat";
	ofstream fout(file, ios_base::out | ios_base::binary);
	if (fout.fail())
	{
		cout << "file: " << file << " open failed!" << endl;
		exit(-1);
	}
	cout << "Input planet name:<exit to exit>" << endl;
	Planet p;
	while (cin.getline(p.name, LIM))
	{
		if (!strcmp(p.name, "exit")) break;
		cout << "Input planet population: ";
		cin >> p.population;
		cout << "Input planet gravity: ";
		cin >> p.g;
		fout.write((char *)&p, sizeof(p));
		memset(p.name, 0, sizeof(p.name));
		cout << "Input planet name:<exit to exit>" << endl;
		eatline();
	}
	fout.close();
#if 1
	cout << "file content:" << endl;
	showBinaryFile(file);
	cout << "Done.\n";
#endif

	return 0;
}
