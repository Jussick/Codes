class Animal:
	def __init__(self,new_name):
		self.name = new_name	
	def __str__(self):
		return "I'm a coffeeCat, and my name's %s"%self.name

class Cat(Animal):
	def wow(self):
		print("wowowowowowo")

class Coffe_cat(Cat):
	def wow(self):
		print("cooooofeeee...")
		Cat.wow(self)
		super().wow()


cfCat = Coffe_cat("rumzy")
print(cfCat)

cfCat.wow()
