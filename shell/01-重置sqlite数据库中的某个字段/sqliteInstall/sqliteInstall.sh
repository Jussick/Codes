#!/bin/bash

type sqlite3 > /dev/null 2>&1   # type命令后跟一个已有的程序，命令返回0，否则返回非0
if [ $? -eq 0 ];then  # sqlite3已经安装了
    echo "sqlite3 has already exist, finish installation."
    exit 0
fi

echo "Please input password:"
read password

echo "extract package..."
tar zxvf sqlite-autoconf-3080100.tar.gz
cd sqlite-autoconf-3080100

echo "Installing..."
./configure > /dev/null 2>&1
make > /dev/null 2>&1
echo ${password} | sudo make install > /dev/null 2>&1

echo ${password} | sudo cp /usr/local/lib/libsqlite3.so.0.8.6 /usr/lib/x86_64-linux-gnu/libsqlite3.so.0.8.6

echo "Install complete!"
rm -rf sqlite-autoconf-3080100
