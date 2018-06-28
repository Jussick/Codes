#*-* coding:utf-8 *-*

a = 10
b = 20
print("a = %d, b = %d"%(a,b))

# 第一种异或
#a = a^b
#b = a^b
#a = a^b

# 第二种中间变量
#temp = a
#a = b
#b = temp

# 第三种加减大法
#a = a + b
#b = a - b
#a = a - b

#最后一种，python独有
a,b = b,a

print("a = %d, b = %d"%(a,b))
