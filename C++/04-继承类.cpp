//C++ file
/***********************************************
#
#      Filename: 04-继承类.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: ---
#        Create: 2018-08-02 09:22:09
#**********************************************/
#include <iostream>
#include <string>
using namespace std;

class TableTennisPlayer {
private:
	string firstname;
	string lastname;
	bool hastable;
public:
	TableTennisPlayer(const string &fn = "none", const string &ln = "none", bool hastable = false);
	void Name() const;
	bool hasTable() const { return hastable; }
	void resetTable(bool hastable) { this->hastable = hastable; }
};

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool hastable)
	:firstname(fn),lastname(ln),hastable(hastable) { }

void TableTennisPlayer::Name() const {
	cout << firstname << " " << lastname;
}


class RatedPlayer : public TableTennisPlayer {
private:
	int rate;
public:
	/* 两种派生列构造函数的写法，但每一种都要调用基类的构造函数 */
	RatedPlayer(int rate, const string &fn, const string &ln, bool hastable);
	RatedPlayer(int rate, const TableTennisPlayer &tp):rate(rate), TableTennisPlayer(tp) { }
	void Name() const;  // 多态
	int Rate() const;
	void ResetRating(int rate) { this->rate = rate; }
};

RatedPlayer::RatedPlayer(int rate, const string &fn, const string &ln, bool hastable)
	:TableTennisPlayer(fn,ln,hastable) { this->rate = rate; }

int RatedPlayer::Rate() const {
	return rate;
}
void RatedPlayer::Name() const{
	cout << "Rated player: ";
	this->TableTennisPlayer::Name();
}

int main()
{
	TableTennisPlayer lucas("Edward", "Lucas", true);
	lucas.Name();
	if (lucas.hasTable())
		cout << " has a table." << endl;
	else
		cout << " has not a table." << endl;
	lucas.resetTable(false);
	lucas.Name();
	if (lucas.hasTable())
		cout << " has a table." << endl;
	else
		cout << " has not a table." << endl;

	RatedPlayer lu(10, "hengguang", "LU", true);
	RatedPlayer lu2(20, lucas);
	lu.Name();
	cout << "'s class is " << lu.Rate() << endl;
	lu2.Name();
	cout << "'s class is " << lu2.Rate() << endl;


	return 0;
}




