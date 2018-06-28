class Dog:
	def msg(self):
		print("dog doggi")
	
	def __del__(self):
		print("object is deleted..")

dog1 = Dog()
dog2 = dog1

del dog1
del dog2
print("-"*20)

