#ifndef COMPLEX0_H
#define COMPLEX0_H

#include<iostream>
#include<string>
using namespace std;

class Complex {
	private:
		double A;  // 实部
		double B;  // 虚部
	public:
		// default constructor && destructor
		Complex();
		Complex(double A, double B);
		~Complex();

		// operator overload
		Complex operator+(const Complex &cnum) const;
		Complex operator-(const Complex &cnum) const;
		Complex operator*(const Complex &cnum) const;
		Complex operator*(double num) const;
		Complex operator~();
		//Complex &operator=(const Complex &cnum);
		// friend function
		friend ostream &operator<<(ostream &os, const Complex &cnum);
		friend istream &operator>>(istream &os, Complex &num);
		friend Complex operator*(double num, const Complex &cnum);
};


#endif
