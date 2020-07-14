//C++ file
/***********************************************
#
#      Filename: 33s-IP地址无效化.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。

所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

 

示例 1：

输入：address = "1.1.1.1"
输出："1[.]1[.]1[.]1"
示例 2：

输入：address = "255.100.50.0"
输出："255[.]100[.]50[.]0"
 

提示：

给出的 address 是一个有效的 IPv4 地址

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/defanging-an-ip-address
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#        Create: 2020-06-20 15:37:33
#**********************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ret = "";
        string temp = "";

        unsigned long long pos;
        while ((pos = address.find(".")) != string::npos)
        {
            temp.assign(address, 0, pos);
            address = address.substr(pos + 1);
            ret += (temp + "[.]");
        }
        ret += address;
        return ret;
    }
};

int main()
{
    string ip = "10.7.5.88";
    Solution ss;
    string invalidIP = ss.defangIPaddr(ip);

    cout << "invalidIP: " << invalidIP << endl;
}
