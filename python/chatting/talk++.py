# 这是一个聊天程序，能够实现信息的收和发
# 只能用python3执行，因为有encode和decode

#encoding="utf-8" 

from socket import *
from threading import Thread

# 检测消息，解码接收
def recvData():
	while True:
		recvContent = udpSocket.recvfrom(1024)
		print(">>[%s]:%s"%(recvContent[1],recvContent[0].decode("gb2312")))
		print("<<",end='')

# 监测键盘，发送消息
def sendData():
	while True:
		sendContent = input("<<")
		udpSocket.sendto(sendContent.encode("gb2312"),(destIP,destPort))

# 定义全局变量
# 对象最好初始化为None
udpSocket = None

#字符串最好初始化为“”
destIP = ""

# 数字最好初始化为0
destPort = 0

def main():
	
# 全局变量的声明
	global udpSocket
	global destIP
	global destPort
	

	udpSocket = socket(AF_INET,SOCK_DGRAM)	
	destIP = input("输入目的IP：")
	destPort = int(input("输入目的端口："))

# 创建线程并开始
	tr = Thread(target=recvData)
	ts = Thread(target=sendData)

	tr.start()
	ts.start()

	tr.join()
	ts.join()

if __name__=='__main__':
	main()
