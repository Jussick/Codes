//C++ file
/***********************************************
#
#      Filename: httpTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2020-03-18 17:00:46
#**********************************************/
#include <iostream>
#include <sstream>
#include "client_http.hpp"

using namespace std;
using HttpClient = SimpleWeb::Client<SimpleWeb::HTTP>;

bool HttpDoorCtrl()
{
    // HttpClient *m_HttpClient= new HttpClient("183.232.231.172");
    HttpClient *m_HttpClient= new HttpClient("183.232.231.172:80");
    stringstream ss;
    
    ss << "these are http real sending data";  // http的数据内容
    string url = "/dac/uploadInfo/doorCtrl";
    
    try
    {
        auto r1 = m_HttpClient->request("POST",url, ss,
            {
                // 请求头的内容
                { "Content-Length", to_string(ss.str().length()) },
                { "Connection", "keep-alive" },
                { "Content-Type", "hohoho"},
                { "Accept", "text/html, */*" },
                { "data", "this is a test sentence."},
            });       
        stringstream ret;
        ret << r1->content.rdbuf();
        string ret1 = r1->content.string();
        cout << "ret: " << ret.str() << endl;
        
    }
    catch (const SimpleWeb::system_error &e) {
        cout << e.what() << endl;
        return false;
    }
    
    return true;
}


int main()
{
    bool res = HttpDoorCtrl();
    cout << res << endl;
    return 0;
}
