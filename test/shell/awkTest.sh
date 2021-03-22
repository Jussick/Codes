#!/bin/bash

# read 方法读文件内容
#cat hostList.txt | while read line
#do
#	echo "list:$line"
#done

# read 方法二
#while read line
#do
#	echo "file:$line"
#done < hostList.txt

# awk方式读文件内容, 到另一文件中
while read line
do
	echo $line | awk '{ print $1 }' >> new.txt
done < hostList.txt

