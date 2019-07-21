//C++ file
/***********************************************
#
#      Filename: client.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 简单的http客户端请求模拟
#        Create: 2019-07-09 17:05:09
#**********************************************/
#include <iostream>
#include <string>
#include "../HttpLib/client_http.hpp"

using namespace std;
using HttpClient = SimpleWeb::Client<SimpleWeb::HTTP>;


int main() {

  HttpClient client("localhost:8080");

  string json_string = "{\"firstName\": \"John\",\"lastName\": \"Smith\",\"age\": 25}";
  string sendStr = "hahahahahaha";

  // Synchronous request examples
  try {
    /* GET match request */
    auto r1 = client.request("GET", "/match/123");
    cout << "GET match test:" << r1->content.rdbuf() << endl << endl; // Alternatively, use the convenience function r1->content.string()
    
    /* POST string request */
    auto r2 = client.request("POST", "/string", sendStr);
    cout << "POST string test: " << r2->content.rdbuf() << endl << endl;
  }
  catch(const SimpleWeb::system_error &e) {
    cerr << "Client request error: " << e.what() << endl;
  }

 // Asynchronous request example

  /* POST json request */
  client.request("POST", "/json", json_string, [](shared_ptr<HttpClient::Response> response, const SimpleWeb::error_code &ec) {
    if(!ec)
        cout << "POST json test: " << response->content.rdbuf() << endl << endl;
    else 
        cerr << "Client POST request error: " << ec << endl;
  });
  client.io_service->run();  // this line is used for Asynchronous request, Synchronous request do not need this.
  sleep(1);  // in order to avoid program terminate ahead of recieve from server.
}
