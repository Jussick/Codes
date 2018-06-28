#-*- coding:utf-8 -*-

def main():
	str = input("Input a sentence:")
	count = 0
	for i in str.split(" "):  # split是字符串切割，“”里面的内容是以什么进行切割。
		print(i)
		count += 1
	
	print("%d words in total"%count)


if __name__ == '__main__':
	main()
