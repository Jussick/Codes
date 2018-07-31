#include<iostream>

using namespace std;

class Person{
	string name;
	string sex;
	int age;

public:
	Person();
	Person(string name, string sex, int age);
	~Person();
	void showInfo();
};
Person::Person() {
	this->name = "default";
	this->age = 24;
	this->sex = "???";
}
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
	//Person lucas("Lucas", "man", 24);
	//lucas.showInfo();
	//Person *Edward = new Person("Edward", "male", 18);
	//Edward -> showInfo();
	//delete(Edward);
	Person per[3] = {           // 对象数组必须要有默认构造函数
		Person("Lucas", "man", 24),
		Person("dream", "female", 24)
	};
	for (int i = 0; i < 3; i++)
	{
		per[i].showInfo();
	}

	return 0;
}
