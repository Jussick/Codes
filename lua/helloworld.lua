print("hello, world")

-- number
a = 3.14
print(a)

-- string
str = "haha"
print(str)

-- bool
ret = false
print(ret)

-- lua table = 数组 + 映射
arr = {}
arr[1] = 1
arr[2] = 2
arr[3] = "hello"
-- 或这样定义
-- arr = {
    -- [1] = 1,
    -- [2] = 2,  -- 注意这里一定不要少了逗号！
-- }
print(arr[1], arr[2], arr[3])

arr2 = {}
arr2["hello"] = 2
arr2[3] = false
print(arr2.hello, arr2[3])

-- lua function
function add(a, b)
    return a+b
end
print("func add result: ", add(1,2))

-- 多变量赋值
a,b,c = 1,2,3
print(a,b,c)

-- lua的表达式
-- 1、字符串拼接
print("str" .. "cat")
-- 2、局部变量定义
function foo()
    local num = 1  -- 若不加local，则num为全局变量
end
foo()
print(num)
-- 3、条件表达式
if (true)
then
    print("yes")
else
    print("no")
end

-- 4、循环
local i = 1
io.write("while: ")
while i < 10 do
    io.write(i, ", ")
    i = i + 1
end
io.write("\n")

io.write("for: ")
for i=1,10,2 do  -- 表示i从一到10，步长为2
    io.write(i, ", ")
end
io.write("\n")

-- for的泛型遍历
aTable = {
    ["aaa"] = 100,
    [200] = "heihei",
    [1] = 10,
    [2] = 20,
}
print("pairs遍历：")
for k,v in pairs(aTable) do  -- 需要注意：由于lua的table是以散列形式存储的，所以遍历是无序的
    print(k,v)
end

print("ipairs遍历：")
for k,v in ipairs(aTable) do  -- ipairs表示只遍历数组的部分
    print(k,v)
end


-- 5、lua的包（package）
local c = require("add")  -- require用来加载以字符串为名字的文件（不带.lua后缀）
print(c)  -- c就是add.lua返回的class的指针, require多次同一个文件返回的指针是同一个
print("1+2=", c.add(1,2))

    -- dofile也能加载文件，和require区别在于require对同一个文件只加载一次，而dofile有几次就加载几次
for i = 1,2 do
    local ptr = dofile("add.lua")  -- dofile要写文件的全名（带后缀）
    print(ptr)
end


-- 6、lua的系统库
local tt = {}
for i = 1,10 do
    table.insert(tt, i, i)  -- insert的第二个参数是插入的值，第三个参数是插入位置；若缺省第三个参数，则默认在最后插入
end
table.remove(tt, 2)  -- remove的第二个参数表示要移除元素的索引下标，若缺省，则移除最后一个元素

for k,v in pairs(tt) do
    print(k,v)
end

print("table tt element number is: ", #tt)  -- #表示计算对象的长度
local str = "hello"
print("str length is: ", #str)

print( type(tt), type(str) )  -- type方法打印出对象的类型

local num = tonumber("3.14")  -- 字符串转数字
print(num, type(num))

local ss = tostring(3.14)  -- 数字转字符串
print(ss, type(ss))

local ss_format = string.format("hi %d", 250)  -- 字符串格式化，和C语言printf一样
print( ss_format )
