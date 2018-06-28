#!/bin/bash

# $1--user, $2--IP, $3--old_key_timeStamp, $4--new_key_timeStamp, $5---SPVIp                                                      
if [ $# -ne 5 ]; then                                                                                                         
    echo "Five arguments are needed." 
    echo "1. username   2. IP   3. old_key_timeStamp  4. new_key_timeStamp  5.SPVIp" 
    exit                                                                                                                      
else 
	expect <<- EOF
	spawn ssh -i /root/.ssh/id_rsa$3 $1@$2
	expect "*]*"
	send "cd ~/.ssh/\r"
	expect "*]*"
	send "scp root@$5:~/.ssh/id_rsa$4.pub .\r"
	expect {
		"*(yes/no)?*" {
			send "yes\r"
			expect "password"
			send "62960909\r"
			}
		"password" { send "62960909\r" }
	 }

	expect "*]*"
	send -- "cat id_rsa$4.pub >> authorized_keys\r"
	expect "*]*"
	send "echo authorized done.\r"
	expect "done."
	send "exit\r"
	expect eof


	EOF

fi

/home/spv/bin/Newclean.sh $3 $1 $2 $4 $5
