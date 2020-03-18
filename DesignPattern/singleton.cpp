//C++ file
/***********************************************
#
#      Filename: singleton.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 单例模式
#        Create: 2020-02-10 22:58:24
#**********************************************/
#include <iostream>

class Random
{
public:
    Random(const Random &) = delete;
    Random & operator=(const Random &) = delete;

    static Random & Get() 
    { 
        static Random s_instance;
        return s_instance;
    }
    
    static float GetRandom() { return Get().GetRandomImpl(); }



private:
    Random() {}
    float GetRandomImpl() { return m_randomGenerator; }  // 写接口间接实现的目的是：可以直接像命名空间一样调用，如：Random::GetRandom()；
                                                         // 而非：Random::Get().GetRandomImpl() 这样就有点啰嗦
    float m_randomGenerator = 0.7f;
};

int main()
{
    float num = ;  // 像命名空间一样使用
    std::cout << num << std::endl;

    // 这样会报错
    // Random instance = Random::Get();

}
