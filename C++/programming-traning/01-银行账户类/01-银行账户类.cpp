//C++ file
/***********************************************
#
#      Filename: 01-银行账户类.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-07-05 10:47:25
#**********************************************/

#include "Bank.h"

Bank_Account::Bank_Account()
{
	cout << "Involking default constructor" << endl;
	this->username = "whoamI";
	this->account_num = "000000";
	this->deposit = 0.00;
}
Bank_Account::Bank_Account(string username, string account_num, double deposit)
{
	cout << "Involking default with parameter constructor" << endl;
	this-> username = username;
	this-> account_num = account_num;
	this-> deposit = deposit;
}
Bank_Account::~Bank_Account()
{
	cout << "I'm cute destructor..." << endl;
}
void Bank_Account::showInfo()
{
	cout << "##########################" << endl;
	cout << "Here is " << this-> username << "\'s" << " infomation:" << endl;
	cout << "username: " << this-> username << endl;
	cout << "account_num: " << this-> account_num<< endl;
	cout << "deposit: " << this-> deposit<< endl;
	cout << "--------------------------" << endl;
}
int Bank_Account::addMoney(const double &num)
{
	if (num < 0)
	{
		cout << "No money detected." << endl;
		return -1;
	}
	else
	{
		this-> deposit += num;	
		cout << num << "$ has add into your account." << endl;
		return 0;
	}
}
int Bank_Account::takeMoney(const double &num)
{
	if (num > this-> deposit)
	{
		cout << "Sorry, but there's no money enough~" << endl;
		return -1;
	}
	else
	{
		cout << num << "$ has take away from your account." << endl;
		this-> deposit -= num;
		return 0;
	}
}


int main()
{
	ostream::fmtflags old = cout.flags();  // 备份原始的cout格式
	cout << setiosflags(ios::fixed) << setprecision(2);  // 把cout输出格式变为非科学计数、精度保留小数点后2位
	Bank_Account Lucas("Lucas", "111111", 1200.34);
	Lucas.showInfo();
	Lucas.addMoney(50.56);
	Lucas.takeMoney(1000);
	Lucas.showInfo();
	cout.flags(old);  // 恢复cout原始格式
	Lucas.showInfo();


	return 0;
}
