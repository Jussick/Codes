#-*- coding:utf-8 -*-

from socket import *

# 创建套接字，返回一个对象
udpSocket = socket(AF_INET,SOCK_DGRAM)

# 绑定端口，''不填IP代表本机的任意一个IP
bindAddr = ('',7788)
udpSocket.bind(bindAddr)

destIP = raw_input("输入要发送到的IP：")
destPort = int(input("请输入要发送到的端口："))
sendData = raw_input("输入要发送的内容：")

udpSocket.sendto(sendData.encode("utf-8"),(destIP,destPort))

# 发送到飞秋
#udpSocket.sendto("1:1231343141:Obama:Obama-pc:32:hahaha",("172.16.1.69",2425))
