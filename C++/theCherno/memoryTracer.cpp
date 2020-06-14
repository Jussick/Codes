//C++ file
/***********************************************
#
#      Filename: memoryTracer.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 在unix下delete重载不生效，ubuntu和windows上测试通过
#        Create: 2020-03-06 07:57:45
#**********************************************/
#include <iostream>
#include <memory>

struct Object {
    int a,b,c;
};

void* operator new(size_t size)
{
    std::cout << "Allocating " << size << " bytes of memory." << std::endl;
    return malloc(size);
}

void operator delete(void* addr, size_t size)
{
    std::cout << "Free " << size << " bytes of memory." << std::endl;
    free(addr);
}

int main()
{
    Object *ooo = new Object;    
    delete ooo;
    {
    }
}
