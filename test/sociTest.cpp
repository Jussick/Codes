//C++ file
/***********************************************
#
#      Filename: sociTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-07-02 10:44:21
#**********************************************/
#include <iostream>
#include <soci/soci.h>

using namespace soci;
using namespace std;

int main() {
    session sql("mysql", "dbname=PHOENIX2 user=root password=gsy2017");
    string user;
    sql << "select User from mysql.user where Host=%", into(user);

    cout << "selected user is " << user << endl;

    return 0;
}
