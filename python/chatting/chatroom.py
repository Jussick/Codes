#coding=utf-8
from socket import *
import time

def main():
# 创建套接字
	udpSocket = socket(AF_INET,SOCK_DGRAM)

# 绑定源地址
	bindAddr = (("",7788)) # 绑定一个元组
	udpSocket.bind(bindAddr)


# 接收信息
	while True:
		recvData = udpSocket.recvfrom(1024) # recvData是一个元组，[0]里面是内容，[1]里面是发送方的IP和端口
		mytime = time.strftime("%Y-%M-%D %H:%M:S",time.localtime(time.time())) # 用time模块格式化输出当前时间
		print("[%s] %s: %s"%(mytime,recvData[1],recvData[0].decode("gb2312"))) # 只有python3有decode和encode

	udpSocket.close()

if __name__=='__main__':
	main()
