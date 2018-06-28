#!/bin/bash

if [ $# -ne 2 ];then
	echo "Two arguments should be given."
	echo "1.usermane, 2.pubKeySerialNum"
	exit 
else
	file="/home/$1/.ssh/id_rsa$2.pub"
	if [ ! -f $file ];then
		echo no
	else
		echo yes
	fi
fi
