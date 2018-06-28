class Dog:
	"""定义了一个Dog类"""
	# init 方法在对象创建完之后自动执行,init方法也叫魔法方法，因为它是自动执行的。
	def __init__(self,new_name,new_color,new_age):
		self.name = new_name 
		self.color = new_color
		self.age = new_age
	#	print("An Dog object has been created.")
	# 属性

 	# 方法
	def eat(self):
		print("dog is eating shit...")
	
	def drink(self):
		print("dog is drinking,,,")
	
	def introduce(self):
		print("My name's %s, I'm in %s and I'm %s years old"%(self.name,self.color,self.age))

def main():
	# 创建对象
	dog1 = Dog("haha","white",23333)
	dog2 = Dog("waooo","yellow",1)
	#dog1 = Dog()
	#dog2 = Dog()
	#dog1.eat()
	#dog1.drink()
	
	# 给对象添加属性
	#dog1.name = "haha"
	#dog1.color = "white"
	#dog1.age = 23333
	
	#dog2.name = "waooo"
	#dog2.color = "yellow"
	#dog2.age = 1

	dog1.introduce()
	dog2.introduce()

   #	help(Dog)

if __name__ == "__main__":
	main()
