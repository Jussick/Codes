#!/bin/bash

temp=
# 第一种
cat filename | while read line;do
    echo $line
    temp=$line
done
echo "1、temp: " $temp  # 这里是空的！

# 第二种
while read line;do
    echo $line
    temp=$line
done < filename
echo "2、temp: " $temp  # 这里是有值的！

# 第一种和第二种都是把文件一行一行读出来，但前者会新起一个子进程，后者都是在同一个进程中的
# 造成的效果呢就是，若定义一个名为temp的空全局变量, 第一种执行过后temp还是空的；但第二种执行过后temp中是有值的
