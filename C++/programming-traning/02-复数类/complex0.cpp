//C++ file
/***********************************************
#
#      Filename: complex0.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: Realize complex member functions.
#        Create: 2018-07-06 09:49:29
#**********************************************/
#include "complex0.h"

Complex::Complex() {
	A = B = 0;	
}

Complex::Complex(double a, double b) {
	A = a;
	B = b;
}
Complex::~Complex() { }


Complex Complex::operator~() {
	Complex result;
	result.A = this-> A;
	result.B = -this-> B;
	return result;
}

Complex Complex::operator+(const Complex &cnum) const {
	Complex result;
	result.A = this-> A + cnum.A;
	result.B = this-> B + cnum.B;
	return result;
}

Complex Complex::operator-(const Complex &cnum) const {
	//cout << "a.A=" << this->A << " a.B=" << this->B;
	//cout << " c.A=" << cnum.A << " c.B=" << cnum.B << endl;
	Complex result;
	result.A = this-> A - cnum.A;
	result.B = this-> B - cnum.B;
	return result;
}

// 复数相乘
Complex Complex::operator*(const Complex &cnum) const {
	Complex result;
	result.A = this-> A * cnum.A - this-> B * cnum.B;
	result.B = this-> A * cnum.B + this-> B * cnum.A;
	return result;
}

// 复数和实数相乘
Complex Complex::operator*(double num) const {
	Complex result;
	result.A = num * this->A;
	result.B = num * this->B;
	return result;
}

// 实数和复数相乘
Complex operator*(double num, const Complex &cnum) {
	return cnum * num;
}

ostream &operator<<(ostream &os, const Complex &cnum) {
	os << "(" << cnum.A << ", " << cnum.B << "i)" << endl;	
	return os;
}

istream &operator>>(istream &in, Complex &cnum) {
	in >> cnum.A >> cnum.B;
	return in;
}

// 重载赋值运算符, 由于复数在构造函数中没有用到静态变化的类成员，故重载赋值运算符意义不大
#if 0
Complex &Complex::operator=(const Complex &cnum)
{
	if (this == &cnum)
		return *this;
	this-> A = cnum.A;
	this-> B = cnum.B;
	return *this;
}
#endif
