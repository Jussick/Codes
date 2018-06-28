def factorial(n):
	if n < 1:
		return 1
	else:
		print("%d * %d"%(n,(n-1)))
		return n * factorial(n-1)

N = int(input("请输入要求的阶乘："))
result = factorial(N)
print("factorial %d is %d"%(N,result))

