//C++ file
/***********************************************
#
#      Filename: singleObjectTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 单例模式的试验
#        Create: 2019-07-26 11:01:53
#**********************************************/
#include <iostream>

using namespace std;

/*  一个最简单的单例实现，是非线程安全的
 * class singleton
 * {
 * protected:
 *     singleton(){}
 * private:
 *     static singleton* p;
 * public:
 *     static singleton* instance();
 * };
 * singleton* singleton::p = NULL;
 * singleton* singleton::instance()
 * {
 *     if (p == NULL)
 *         p = new singleton();
 *     return p;
 * }
 */

class SingleOne {
private:
    SingleOne() {}
    ~SingleOne() {
        delete Instance;
        Instance = nullptr;
    }


public:
    static SingleOne* GetInstance();
    static void ReleaseInstance();
    void setName(string &name);
    string getName();

	SingleOne(const SingleOne &) = delete;
    SingleOne& operator=(const SingleOne &) = delete;
private:
    string name;
	static SingleOne* Instance;
    

};

void SingleOne::setName(string &name) {
    if (Instance)
        Instance->name = name;
}
string SingleOne::getName() { 
    if (Instance)
        return Instance->name; 
    else
        return "";
}

SingleOne* SingleOne::Instance = nullptr;

SingleOne* SingleOne::GetInstance() {
    if (Instance == nullptr) 
        Instance = new SingleOne();
    return Instance;
}

void SingleOne::ReleaseInstance() {
    delete Instance;
    Instance = nullptr;
}

int main() {
    SingleOne *obj1 = SingleOne::GetInstance();
    SingleOne *obj2 = SingleOne::GetInstance();

    // SingleOne ss(*obj1);
    // 会报错"use of deleted function ‘SingleOne::SingleOne(const SingleOne&)"，用到了delete限制的函数


    string setname1 = "Edward";
    obj1->setName(setname1);
    cout << "obj1->name: " << obj1->getName() << endl;
    cout << "obj2->name: " << obj2->getName() << endl;

    /*
     * SingleOne::ReleaseInstance();
     * 若把上句加上，后面的代码执行会出"段错误"，因为已经把唯一的对象指针释放了。
     */

    string setname2 = "Lucas";
    obj2->setName(setname2);
    /*
     * 两者都从Edward变成了Lucas，说明两个实例是指向同一个对象的
     */
    cout << "obj1->name: " << obj1->getName() << endl;
    cout << "obj2->name: " << obj2->getName() << endl;

    return 0;
}
