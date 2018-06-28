#include<iostream>

using namespace std;

class Person{
	string name;
	string sex;
	int age;

public:
	Person(string name, string sex, int age);
	~Person();
	void showInfo();
};

Person::Person(string name, string sex, int age) {
	this->name = name;
	this->sex = sex;
	this->age = age;
}

Person::~Person() {
	cout<<"This is destroy function."<<endl;
}

void Person::showInfo() {
	cout<<"name: "<<this->name<<endl;
	cout<<"sex: "<<this->sex<<endl;
	cout<<"age: "<<this->age<<endl;
}

int main()
{
	Person lucas("Lucas", "man", 24);
	lucas.showInfo();

	return 0;
}
