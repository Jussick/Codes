class Game(object):
	# 类属性
	game_num = 0

	# 静态方法，一般和类或实例都没有关系,不需要写参数,上面加@staticmethod声明
	@staticmethod
	def print_info():
		print("-"*20)
		print("OverWatch~".center(20))
		print("-"*20)

	# 类方法，用于修改类属性,传入参数cls,上面加@classmethod声明
	@classmethod
	def add_num(cls):
		cls.game_num += 1
		print("The total number of game is %d"%cls.game_num)

# 用类名能直接调用类属性和静态方法
Game.print_info()
Game.add_num()

# 用实例对象也能直接调用类属性和静态方法
game = Game()
game.print_info()
game.add_num()

