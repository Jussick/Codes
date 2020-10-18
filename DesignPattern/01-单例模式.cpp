//C++ file
/***********************************************
#
#      Filename: 01-单例模式.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 饿汉式和懒汉式单例实现
#        Create: 2020-08-01 16:45:29
#**********************************************/
#include <iostream>
#include <mutex>

/* -------饿汉式单例------- */
class HungrySingleton {
    public:
        static HungrySingleton *GetInstance();
        static void ReleaseInstace();
        void isGood() { std::cout << "I am good..." << std::endl; }
    private:
        HungrySingleton() {}
        ~HungrySingleton() {}
        HungrySingleton(const HungrySingleton &obj) = delete;
        HungrySingleton &operator=(const HungrySingleton &obj) = delete;
        static HungrySingleton *Instance;
};

HungrySingleton* HungrySingleton::Instance = new HungrySingleton();  // 类的静态成员变量初始化时要有开头的类型

HungrySingleton* HungrySingleton::GetInstance() {
    return Instance;
}

void HungrySingleton::ReleaseInstace()
{
    delete Instance;
    Instance = NULL;
}
/* -------结束饿汉式单例------- */


/* 懒汉式单例 */
class LazySingleton {
    public:
        static LazySingleton* GetInstance(); 
        static LazySingleton* ReleaseInstace(); 
        LazySingleton(){}
        ~LazySingleton(){}
    private:
        LazySingleton(const LazySingleton& obj)= delete;
        LazySingleton &operator=(const LazySingleton& obj) = delete;

        static LazySingleton* Instance;
        static std::mutex m_Mtx;
};

LazySingleton* LazySingleton::Instance = NULL;
std::mutex LazySingleton::m_Mtx;  // mutex无需初始化值，但类静态量也需要在类外提前声明

LazySingleton* LazySingleton::GetInstance()
{
    if (Instance == NULL)
    {
        std::lock_guard<std::mutex> locker(LazySingleton::m_Mtx);  // 解决线程安全问题和加锁影响效率问题
        if (Instance == NULL)
            Instance = new LazySingleton();
    }
    return Instance;
}
/* -------懒汉式单例实现结束------- */

int main()
{
    HungrySingleton *obj_h = HungrySingleton::GetInstance();
    HungrySingleton *obj2_h = HungrySingleton::GetInstance();

    if (obj_h == obj2_h)
        std::cout << "HungrySingleton success!" << std::endl;
    else
        std::cout << "HungrySingleton failed!" << std::endl;



    LazySingleton *obj_l = LazySingleton::GetInstance();
    LazySingleton *obj2_l = LazySingleton::GetInstance();

    if (obj_l == obj2_l)
        std::cout << "LazySingleton success!" << std::endl;
    else
        std::cout << "LazySingleton failed!" << std::endl;

}
