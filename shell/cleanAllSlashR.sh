#!/bin/bash

# 删除当前目录和子目录下所有c++文件的结尾\r符号

find . -name "*.cpp" -o -name "*.cc" -o -name "*.h" -o -name "*.hpp" > fileList  # 找出所有特定后缀的文件
cat fileList | while read line
do
    echo "swipe File:${line}"
    if [ -f ${line} ]; then
        sed -i -e "s/\r//g" ${line}  # 每个符合条件的文件中的\r都删除之
    fi
done
echo "Clean done."
rm -f fileList
