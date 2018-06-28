#*-* coding:utf-8 *-*

class House:
	"""定义一个房子类"""
	def __init__(self, new_area, new_addr, new_info):
		self.area = new_area
		self.remain_area = new_area
		self.addr = new_addr
		self.info = new_info
		self.contains = []

	def __str__(self):
		msg = "房子的总面积：%d,剩余面积：%d，地址在：%s,户型为：%s"%(self.area,self.remain_area,self.addr,self.info)
		msg += " 当前房子里的物品有%s"%str((self.contains))
		return msg

	def add_furni(self,funiture):
		self.remain_area -= funiture.get_area()	
		self.contains.append(funiture.get_name())

class Furniture:
	def __init__(self, new_name, new_area):
		self.name = new_name
		self.area = new_area
	
	def __str__(self):
		return "家具名称：%s，所占面积：%d"%(self.name,self.area)

	def get_area(self):
		return self.area

	def get_name(self):
		return self.name

def main():
	my_home = House(180,"Singapore KingsLanding No.666","十室五厅")
	print(my_home)

	bed = Furniture("床",4)
	print(bed)
	my_home.add_furni(bed)
	print(my_home)
	sofa = Furniture("沙发",10)
	print(sofa)
	my_home.add_furni(sofa)
	print(my_home)
	




if __name__ == "__main__":
	main()
