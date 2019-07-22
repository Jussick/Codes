//C++ file
/***********************************************
#
#      Filename: server.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: 简单的实现http的get和post的服务器
#        Create: 2019-07-09 15:22:29
#**********************************************/
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "../HttpLib/server_http.hpp"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
using namespace std;
using namespace boost::property_tree;

using HttpServer = SimpleWeb::Server<SimpleWeb::HTTP>;


int main() {
    HttpServer http_server;
    http_server.config.port = 8080;
	
#if 1  
    /* POST string REST */
    http_server.resource["^/string$"]["POST"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
        auto content = request->content.string();

        *response << "HTTP/1.1 200 OK\r\nContent-Length: " << content.length() << "\r\n\r\n" << content;

        /* An alternative way */
				//stringstream stream;
		//stream << "HTTP/1.1 200 OK\r\nContent-Length:" << content.length() << "\n" << content;
        //response->write(stream);

    };
    cout << "string has been added" << endl;
#endif

#if 1  
    /* GET match REST */
	http_server.resource["^/match/([0-9]+)$"]["GET"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
	   response->write(request->path_match[1].str());
	};
    cout << "match has been added" << endl;
#endif
#if 1  /* POST json REST */
  http_server.resource["^/json$"]["POST"] = [](shared_ptr<HttpServer::Response> response, shared_ptr<HttpServer::Request> request) {
    try {
      ptree pt;
      read_json(request->content, pt);

      auto name = pt.get<string>("firstName") + " " + pt.get<string>("lastName");

      *response << "HTTP/1.1 200 OK\r\n"
                << "Content-Length: " << name.length() << "\r\n\r\n"
                << name;
    }
    catch(const exception &e) {
      *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                << e.what();
    }
  };
  cout << "json has been added." << endl;
#endif
#if 1
    thread server_thread([&http_server]() { 
        http_server.start(); 
    });
    server_thread.join();
#endif

    return 0;
}
