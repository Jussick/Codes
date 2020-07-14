#!/bin/bash

Usage(){
    echo "Usage: ./changeNetwork.sh [home/office/8floor]"
}

# need to be root to modify /etc/network/interfaces, use expect
ModifyInterfaceTo(){
    script=$1
expect <<- EOF
    spawn su - root
    expect "*Password*" 
    send "$passwd\n"
    expect "*root*"
    send "cat /etc/network/network-scripts/$script > /etc/network/interfaces\r"
    expect "*root*"
    send "exit\r"
    expect eof
EOF
}

# 参数个数判断
ARGC=$#
if [ $ARGC -ne 1 ];then
    Usage
    exit 1
else
    NETWORK=$1
fi

if [ $NETWORK != "home" -a $NETWORK != "office" -a $NETWORK != "8floor" ];then
    Usage
    exit 1
fi

read -p "Input root password:" passwd
ModifyInterfaceTo "interfaces-"$NETWORK

# restart network
echo "flush ip addr..."
echo ${passwd} | sudo ip addr flush dev eth0
echo "turn down eth0"
echo ${passwd} | sudo ifdown eth0
echo "turn up eth0"
echo ${passwd} | sudo ifup eth0

