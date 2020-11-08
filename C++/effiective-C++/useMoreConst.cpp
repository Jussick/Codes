//C++ file
/***********************************************
#
#      Filename: useMoreConst.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 第一章，让自己习惯c++中，多用const的示例
#        Create: 2020-10-31 16:49:30
#**********************************************/
#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;

class TextBlock {
public:
    TextBlock(const char* text) { 
        length = strlen(text);
        this->pText = new char[length];
        printf("construct function, the address of pText is %p.\n", pText);
        strcpy(pText, text);
    }
    
    ~TextBlock() { 
        delete [] this->pText; 
    }

    void show() const {
        cout << "pText: " << pText << endl;
    }

    const char &operator[](std::size_t pos) const {  // const对象只能调用const修饰的成员函数，non-const对象可以调用const和non-const成员函数，在设计一个完善的类时，应该把
                                                     // const和non-const两种版本都实现了
        return this->pText[pos];
    }

    char &operator[](std::size_t pos) {
        // 若在上面还有许多操作的话，用non-const调用const成员函数可以**避免代码重复**
        return const_cast<char&>(
                static_cast<const TextBlock>((*this))[pos]
            );
    }

    void printPTextAddr()
    {
        printf("the address of pText is %p.\n", pText);
    }

    void thisAddr()
    {
        cout << "this pointer addr:" << static_cast<void *>(this) << endl;
    }



    // char& operator[](int pos) const{
        // return this->pText[pos];  // 虽然标定为const成员函数，理应不能改变成员变量，但把成员变量的引用返回出去还是能改变！
    // }

private:
    char *pText;
    int length = 0;
};

int main()
{
    TextBlock tb("hello");
    tb.printPTextAddr();
    tb.show();
    tb.thisAddr();
    char &p = tb[0];  // 这里调用non-const重载【】函数之后，会挂死，具体原因尚未查明
    p = 'i';
    tb.printPTextAddr();
    tb.show();
    tb.thisAddr();
}
