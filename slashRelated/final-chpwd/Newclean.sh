#!/bin/bash

# $1---deleteKeySeiralNum, $2--user, $3--IP，4--new_pub_key_num, $5---SPV'sIP
if [ $# -ne 5 ]; then
    echo "Five arguments are needed."
	echo 1、deleteKeySeiralNum， 2、user，3、IP，4、new_pub_keyNUM, 5.SPVIp
    exit
else
	# 删除authorized_keys中oldKey、删除oldKey、删除本地私钥,需先上传slash
	echo executing cleaning remote server public_key...
	expect <<- EOF
	spawn ssh -i /root/.ssh/id_rsa$1 $2@$3
	expect "*]*"

	send "scp root@$5:/home/spv/bin/slash ~/.ssh/slash\r"
	expect {
        "*(yes/no)?*" {
        send "yes\r"
        expect "password:"
        send "62960909\r"
     }
        "*password:*" { send "62960909\r" }
    }		

	expect "*]*"
	send "~/.ssh/slash ~/.ssh/id_rsa$1.pub\r"
	expect "done."
	send "rm -f ~/.ssh/id_rsa$1.pub\r"
	expect "*]*"
	send "exit\r"
	expect eof
	EOF
		
	echo "removing local old keys(old_pk and new_pub)..."
	rm -f /root/.ssh/id_rsa$4.pub 
	rm -f /root/.ssh/id_rsa$1
	echo "clean done." 
fi
