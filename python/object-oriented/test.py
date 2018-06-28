class A:
	def __init__(self,new_num):
		self.num1 = 100
		self.__num2 = 600
		self.test = new_num

class B(A):
	pass
class C(B):
	pass

test = C(1000)
print(test.test)
