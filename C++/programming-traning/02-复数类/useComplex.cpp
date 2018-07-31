//C++ file
/***********************************************
#
#      Filename: useComplex.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-07-06 09:58:27
#**********************************************/
#include "complex0.h"

int main() {
	Complex a(3.0, 4.0);
	Complex b = a;
	Complex c;
	cout << "Enter a complex number (real,imaginary) (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "b=a is " << b << endl;
		cout << "a+c is " << a + c << endl;
		cout << "a-c is " << a - c << endl;
		cout << "a*c is " << a * c << endl;
		cout << "2 * c is" << 2 * c << endl;
		cout << "Enter a complex number (real,imaginary) (q to quit):\n";
	}
	cout << "Done!" << endl;
	return 0;

}
