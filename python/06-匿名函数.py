def annoymous(a,b,func):
	result = func(a,b)
	print("result is %d"%result) 

function = eval(input("输入一个匿名函数:"))

annoymous(3,4,function)
