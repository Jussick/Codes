//C++ file
/***********************************************
#
#      Filename: 03-运算符重载.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 重载格式：operatorop(argument list)
				 重载加号，把两个数组，逐位相加, 逐位相减, 逐位和一个数字相乘(需要友元函数)
#        Create: 2018-07-05 19:11:48
#**********************************************/
#include "my.h"

class my_array {
	int arr[MAX];

public:
	my_array() {
		int arr[MAX] = {0};
	}
	void showNumbers() {
		for (int i = 0; i < MAX; i++)
			cout << "arr[" << i << "] = " << arr[i] << " ";
		cout << endl;
	}
	void initialize() {
		for (int i = 0; i < 10; i++)
			arr[i] = i;	
	}

	const my_array operator+(const my_array &inArr) const {  // 重载加号
		my_array sumArr;
		for (int i = 0; i < MAX; i++) {
			sumArr.arr[i] = this-> arr[i] + inArr.arr[i];	
		}
		return sumArr;
	}
	const my_array operator-(const my_array &inArr) const {  // 重载减号
		my_array Darr;
		for (int i = 0; i < MAX; i++) {
			Darr.arr[i] = this-> arr[i] - inArr.arr[i];
		}
		return Darr;
	}
	const my_array operator-() {  // 整体变负数
		for (int i = 0; i < MAX; i++) {
			this->arr[i] = -this->arr[i];
		}
	}
	const my_array operator*(int num) {  // 乘号重载两次的意义：实现乘法的交换性
		my_array reArr;
		for (int i = 0; i < MAX; i++) {
			reArr.arr[i] = num * this-> arr[i];
		}
		return reArr;
	}
	friend const my_array operator*(int num, const my_array &inArr) {  // 开头的friend说明两件事：1、这个不是成员函数；2、此函数能够访问类私有成员
		my_array reArr;
		for (int i = 0; i < MAX; i++) {
			reArr.arr[i] = num * inArr.arr[i];
		}
		return reArr;
	}
	friend ostream &operator<<(ostream &os, const my_array &inArr);  // 返回ostream对象的引用，使得<<能够连续使用。
};

ostream &operator<<(ostream &os, const my_array &inArr) {  // 注意: 友元函数在实现时不用写类限制符，因为不是类的成员函数；也不用写friend关键字
		for (int i = 0; i < MAX; i++) {
			cout << "arr[" << i << "] = " << inArr.arr[i] << " ";
		}
		return os;
}

int main() {
	my_array arr1, arr2;
	arr1.initialize();
	arr2.initialize();
	arr1.showNumbers();
	arr2.showNumbers();

	// 加
	my_array sum = arr1 + arr2;
	cout << sum << endl;

	// 减
	my_array darr = arr1 - arr2;
	darr.showNumbers();

	// 变负数
	-sum;
	sum.showNumbers();

	// 乘(顺序可交换)
	my_array product = 5 * arr1;
	my_array product1 = arr1 * 5;
	product.showNumbers();
	cout << product1 << endl;

	return 0;
}
