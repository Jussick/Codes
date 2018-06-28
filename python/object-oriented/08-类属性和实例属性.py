class Phone(object):
	def __init__(self,new_brand,new_price,new_size):
		self.brand = new_brand  # 实例属性
		self.price = new_price
		self.size = new_size
		Phone.count += 1
	
	def __str__(self):
		return "This is a %s phone with the price of %d, the screnn size is %.1f"%\
				(self.brand,self.price,self.size)
	count = 0  # 类属性

phone1 = Phone("iPhoneX",8339,5.5)
phone2 = Phone("sumsung",4339,5.0)
phone3 = Phone("iPhone6s",3008,4.7)

print(phone1)
print(phone2)
print(phone3)
print("The total number of phone is:%d"%Phone.count)


