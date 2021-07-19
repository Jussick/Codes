#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <condition_variable>
#include <sstream>
#include <future>
#include <cctype>

using namespace std;

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}


/***********************************************
#      函数名称: stringToIntegerVector
#
#   Description: 字符串转成整型vector
#     parameter: input: [1,2,3,4,5]
#   returnValue: vector<int>
#   	 Author: luhg
#        Create: 2021-07-18 09:42:26
#**********************************************/
vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

void testGenTags()
{
    std::cout << "this is a test!" << std::endl;
}
