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
    session sql("mysql", "dbname=test user=root password=123123");
    string user = "lucas";
    sql << "INSERT INTO test(name) values(:user)", use(user);


    return 0;
}
