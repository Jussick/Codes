//C++ file
/***********************************************
#
#      Filename: 03-可变参数模板.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-08-15 13:54:16
#**********************************************/
#include <iostream>
#include <typeinfo>

using namespace std;

template<typename... A> class BMW{};  
  
template<typename Head, typename... Tail>  
class BMW<Head, Tail...> : public BMW<Tail...>  
{  
public:  
    BMW()  
    {  
        printf("type: %s\n", typeid(Head).name());  
    }  
private:  
    Head head;  
};  
  
template<> class BMW<>{};  // 边界条件

int main() {
    BMW<int, char, float> car;  
} 
