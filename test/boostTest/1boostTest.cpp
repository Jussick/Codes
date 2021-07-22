//C++ file
/***********************************************
#
#      Filename: boostTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2021-06-29 16:08:52
#**********************************************/
#include <iostream>
#include "boost/asio/io_service.hpp"

using namespace std;

int main()
{
    // 创建io_service
    boost::asio::io_service io_service;

    // boost::asio::io_service::work work(io_service);

    io_service.run();

    cout << "io_service is returned.\n";

    return 0;
}
