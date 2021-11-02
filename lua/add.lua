local class = {}

function class.add( a, b )  -- 这个写法的意思是class这个table下的一个键值为add的value为一个函数
	return a+b
end

-- 也可以这么写，一样的效果
-- class.add = function (a, b)
-- 	return a + b
-- end

return class
