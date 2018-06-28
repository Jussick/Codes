#-*- coding:utf-8 -*-

def main():
	i = 1;
	while i <= 9:
		j = 1;
		while j <= i:
			print("%s*%s=%d\t"%(i,j,i*j),end="")
			j+=1
		i+=1
		print()
if __name__=='__main__':
	main()
