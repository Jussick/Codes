class Dog(object):
	def print_self(self):
		print("大家好，请多多关照！")

class ZangAo(Dog):
	def print_self(self):
		print("hello,everybody~")


def intorduce(who):
	who.print_self()

dog1 = Dog()
dog2 = ZangAo()

intorduce(dog1)
intorduce(dog2)
