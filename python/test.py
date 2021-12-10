## -*- coding: UTF-8 -*-
import time
import sys
import operator

# 闭包
def test(num):
    print("---1---")
    def test_in(num_in):
        print("test_in")
        print(num+num_in)
    print("---2---")
    return test_in(100)

test(100)
# -------------------------------------------- #

###  时间戳的使用
keep_start_file = "20211128/11/42.log"
file1 = "20211128/11/43.log"

if file1 >= keep_start_file:
    print("yes")

now_time = time.time()
date_str = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(now_time))
minute_str = time.strftime("%M", time.localtime(now_time))
hour_str = time.strftime("%H", time.localtime(now_time))
print("date_str:" + date_str)
print("hour_str:" + hour_str)
print("minute_str:" + minute_str)

### 字符串排序
str1 = "20211206/13/25.log"
str2 = "20211206/13/26.log"
str3 = "20211205/13/27.log"

files = []
files.append(str2)
files.append(str1)
files.append(str3)
files.sort()  # 从小到大
for item in files:
    print(item)
print("file over---")

### 字符串切割
str = "/data/logs/INcipher/20211205/12/30.log"
start_pos = len("/data/logs/")
pos = str.find('/', start_pos)
print(str[pos+1:])
print(str[:pos+1])


print("-----------------")
### 字典排序
ddict = {
         '/data/logs/INcipher/' : '20211205/12/30.log', 
         '/data/logs/INplain/'  : '20211203/01/23.log',
         '/data/logs/doip/'     : '20211202/17/58.log',
         '/data/logs/log/'      : '20211203/00/58.log'
}
dSort = sorted(ddict.items(), key=operator.itemgetter(1))  # 按值排序
print("dSort:", dSort)

full_path = ""
for item in dSort:
    for para in item:
        full_path += para
    break;
print("full_path: ", full_path)

### 判断字段是否为空
myDict = {}
if  not bool(myDict):
    print("myDict is empty.")
else:
    print("myDict is not empty!")

