//C++ file
/***********************************************
#
#      Filename: bridgePattern.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 桥接模式
#        Create: 2020-03-03 18:51:30
#**********************************************/
#include <iostream>

using namespace std;

class Software{  // 纯虚基类(不能生成对象，故也不能写构造和析构函数)
public:
    virtual void Run() = 0;
};

class MP3Player: public Software{
public:
    MP3Player() {}
    ~MP3Player() {}
    void Run() { cout << "Playing a music." << endl; }
};

class Game: public Software{
public:
    Game() {}
    ~Game() {}
    void Run() { cout << "Playing a game." << endl; }
};

class MobileBrand {
protected:
    Software *m_soft;

public:
    MobileBrand () { }
    ~MobileBrand () { }
    void SetSoftware(Software *soft) { m_soft = soft; }
    virtual void Run() = 0; 
};

class MobileBrandA : public MobileBrand{
private:
    string m_brand = "brand_A";
public:
    MobileBrandA() { };
    ~MobileBrandA() { };
    void Run() { m_soft->Run(); }
};

class MobileBrandB : public MobileBrand{
private:
    string m_brand = "brand_B";
public:
    MobileBrandB() { };
    ~MobileBrandB() { };
    void Run() { m_soft->Run(); }
};

int main()
{
    MobileBrandA *ma = new MobileBrandA();

    ma->SetSoftware(new MP3Player());
    ma->Run();
    ma->SetSoftware(new Game());
    ma->Run();
}

