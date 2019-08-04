//C++ file
/***********************************************
#
#      Filename: tryCatchTest.cpp
#
#        Author: luhg - luhengguang@gosuncn.com
#   Description: ---
#        Create: 2019-07-26 15:36:11
#**********************************************/
#include <iostream>

using namespace std;

int main() {
    double m, n;

    while (1) {
        cout << "Input m, n: \n";
        cin >> m;
        cin >> n;
        try {
            if (n == 0)
                throw -1;
            else {
                cout << "divide result is: " << m / n << endl;
                break;
            }
        }
        catch(...) {
            cout << "Input error, please input again.\n";
        }
    }

    return 0;
}
