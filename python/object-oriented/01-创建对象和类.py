class Dog:
	"""定义了一个Dog类"""
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
	dog1 = Dog()
	dog2 = Dog()
	#dog1.eat()
	#dog1.drink()
	
	# 给对象添加属性
	dog1.name = "haha"
	dog1.color = "white"
	dog1.age = 23333

	dog2.name = "waooo"
	dog2.color = "yellow"
	dog2.age = 1

	dog1.introduce()
	dog2.introduce()

   #	help(Dog)

if __name__ == "__main__":
	main()
