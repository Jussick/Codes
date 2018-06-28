#-*- coding:utf-8 -*-
import random as rm

def main():
	#初始化玩家和电脑的选择
	my_choice = input("请输入：1）石头 2）剪刀 3）布：")
	AI_choice = rm.randint(1,3)
	
	# choose 1
	if my_choice == 1:
		if AI_choice == 1:
			print("draw.")
		elif AI_choice == 2:
			print("win!!!")
		else:
			print("lose...")
	# choose 2
	elif my_choice == 2:
		if AI_choice == 1:
			print("lose...")
		elif AI_choice == 2:
			print("draw.")
		else: 
			print("win!!!")

	# choose 3
	else:
		if AI_choice == 1:
			print("win!!!")
		elif AI_choice == 2:
			print("lose...")
		else:
			print("draw.")

if __name__ == '__main__':
	main()
