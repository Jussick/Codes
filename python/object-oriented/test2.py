import copy
a = [1,2]
b = [3,4]

c = [a,b]
d = copy.deepcopy(c)
e = c

print("修改前：",end="")
print(e)

c = [a,a]

print("修改后:",end="")
print(e)
