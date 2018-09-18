#ifndef RANDOM_H_
#define RNADOM_H_
/* Defination of class Planet, overload << to output Planet object directly  */

//#ifdef __cplusplus
//extern "C" {
//#endif
/* include */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

void eatline()
{
	while (cin.get() != '\n')
		continue;
}

bool IsDigit(char *s)
{
	for (size_t i = 0; s[i] != '\0'; ++i)
	{
		if (!isdigit(s[i]))  // isdigit只能判断一个字符是否是0-9的一个数字
			return false;
	}
	return true;
}

const int LIM = 20;
class Planet {
public:
	char name[LIM];  // name of the planet
	int population;  // its population
	double g;  // its acceleration of gravity
public:
	Planet() { }
	~Planet() { }
	friend ostream &operator<<(ostream &os, const Planet &p);
	friend istream &operator>>(istream &is, Planet &p);
	
};


ostream &operator<<(ostream &os, const Planet &p)
{
	os.flags(ios::left);
	os.setf(ios::fixed);
	os << setw(20) << p.name << setw(12) << 
		p.population << setprecision(2) << setw(12) << 
		p.g << endl;
	return os;
}

istream &operator>>(istream &is, Planet &p)
{
	cout << "Input planet name:" << endl;
	is.getline(p.name, LIM);
	cout << "Input planet population: ";
	cin >> p.population;
	cout << "Input planet gravity: ";
	cin >> p.g;
	return is;
}

int showBinaryFile(const char *file)
{
	Planet p;
	ifstream fin(file, ios_base::in | ios_base::binary);
	int count = 0;
	while(fin.read((char *)&p, sizeof(p)))
	{
		cout << count << ": " << p; 
		++count;
	}
	if (fin.eof())
		fin.clear();
	else
	{
		cout << "Error in reading file " << file << endl;
		exit(EXIT_FAILURE);
	}
	fin.close();
	return count - 1;
}
//#ifdef __cplusplus
//}
//#endif

#endif /* End of RANDOM_H */
