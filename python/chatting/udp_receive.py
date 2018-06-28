#coding=UTF-8
from socket import *

# 创建套接字，返回一个对象
udpSocket = socket(AF_INET,SOCK_DGRAM)

# 绑定端口，''不填IP代表本机的任意一个IP
bindAddr = ('',7788)
udpSocket.bind(bindAddr)

recvData = udpSocket.recvfrom(1024)
content,destinfo = recvData
print("content is :%s"%content.decode("gb2312"))

