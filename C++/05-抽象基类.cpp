//C file
/***********************************************
#
#      Filename: 05-抽象基类.c
#
#        Author: luhg - luhg@keyou.cn
#   Description: 抽象基类是圆和椭圆的基类，要包含纯虚函数
#        Create: 2018-08-02 15:12:47
#**********************************************/

#include<iostream>
using namespace std;
#define PY 3.14

// ABC definition
class EllipseBase {
private:
	double x;
	double y;
public:
	EllipseBase(double x, double y):x(x), y(y) { }
	//virtual ~EllipseBase();
	void move(double a, double b);
	double getX() const { return x; }
	double getY() const { return y; }
	void setX(double x) ;
	void setY(double y) ;
	virtual double Area() const = 0;  // pure virtual function, make this class an ABC(abstract base class)
};

// Ellipse definition
class Ellipse : public EllipseBase{
private:
	double semimajor;
	double semiminor;
public:
	Ellipse(double l, double s, double x, double y);
	virtual double Area() const;
};

// Round definition
class Round : public EllipseBase{
private:
	double radius;
public:
	Round(double r, double x, double y);
	virtual double Area() const;
};


// class funtion realization
void EllipseBase::move(double a, double b) {
	x = a;
	y = b;
}

void EllipseBase::setX(double x) { 
	this->x = x;
}

void EllipseBase::setY(double y) {
	this->y = y;
}

Ellipse::Ellipse(double l, double s, double x, double y):EllipseBase(x,y) {
		semimajor = l;
		semiminor = s;
}

double Ellipse::Area() const{
	return PY * semimajor * semiminor;	
}


Round::Round(double r, double x, double y):EllipseBase(x,y) {
	radius = r;
}

double Round::Area() const{
	return PY * radius * radius;
}

// test main
int main()
{
	// Ellipse e1(5,3,0,0);
	// Round r1(3,0,0);

	// cout << "Round's area is: " << r1.Area() << endl;
	// cout << "Ellipse's area is: " << e1.Area() << endl;
    
    EllipseBase *p_ellipse = new Ellipse(5,3,0,0);
    EllipseBase *p_round   = new Round(3,0,0);

    cout << "Round area is " << p_round->Area() << endl;
    cout << "Ellipse area is " << p_ellipse->Area() << endl;

	return 0;
}
