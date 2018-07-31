#ifndef BANK_H
#define BANK_H

#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class Bank_Account{
	string username;
	string account_num;
	double deposit;

public:
	Bank_Account();  // default constructor
	Bank_Account(string username, string account_num, double deposit);
	~Bank_Account();
	void showInfo();
	int addMoney(const double & num);
	int takeMoney(const double & num);
};


#endif
