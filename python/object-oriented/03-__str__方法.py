class Dog:
	"""定义了一个Dog类"""
	# init 方法在对象创建完之后自动执行,init方法也叫魔法方法，因为它是自动执行的。
	# 初始化对象
	def __init__(self,new_name,new_color,new_age):
		self.name = new_name 
		self.color = new_color
		self.age = new_age
	# 此魔法方法用于直接打印对象信息时使用
	def __str__(self):
		return "%s的年龄是%d"%(self.name,self.age)		

 	# 方法
	def introduce(self):
		print("My name's %s, I'm in %s and I'm %s years old"%(self.name,self.color,self.age))

def main():
	# 创建对象,并初始化属性
	dog1 = Dog("haha","white",23333)
	dog2 = Dog("waooo","yellow",1)
	
	# 调用方法
	dog1.introduce()
	dog2.introduce()

	# 直接调用魔法方法__str__
	print(dog1)
	print(dog2)


if __name__ == "__main__":
	main()
