//C++ file
/***********************************************
#
#      Filename: hash.cpp
#
#        Author: luhg - luhengguang@joyy.com
#   Description: 几种hash的实现
#        Create: 2021-12-08 23:01:48
#**********************************************/
#include <functional>
#include <iostream>
#include <list>
#include <memory>

using namespace std;


/* 链地址法 */
class Hash
{
    int N; // 哈希表的表长   
    list<int> *table;  // hash表

public:
    Hash(int n);
    void insertKey(int key);
    void deleteKey(int key);
    void displayHash();
    bool searchKey(int key);
    inline int hashFunction(int x) {  // hash函数，返回索引下标
        return x % N;
    }

};

Hash::Hash(int n) {
    this->N = n;
    table = new list<int>[n];
}

void Hash::insertKey(int key) {
    int index = hashFunction(key);
    table[index].insert(table[index].end(), key);
}

void Hash::deleteKey(int key) {
    int index = hashFunction(key);

    list<int>::iterator iter;
    for (iter = table[index].begin(); iter != table[index].end(); ++iter) {
        if (*iter == key) {
            break;
        }
    }

    if (iter != table[index].end()) {
        table[index].erase(iter);
    }
}

void Hash::displayHash() {
    cout << "------------hashtable-----------\n";
    for (int i = 0; i < N; ++i) {
        cout << i << ": ";
        for (int value : table[i]) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[] = {12,34,123,33,11,34,56,323,2354};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "array is: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    Hash hashtable(n);
    for (int i = 0; i < n; ++i) {
        hashtable.insertKey(a[i]); 
    }

    hashtable.displayHash();

    hashtable.deleteKey(56);
    hashtable.deleteKey(58);  // 删除一个不存在的
    hashtable.displayHash();

    return 0;
}
