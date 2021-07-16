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
