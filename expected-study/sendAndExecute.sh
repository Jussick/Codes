#!/bin/bash

expect <<- EOF
set timeout 10
spawn scp /root/codes/slash root@10.10.3.102:~/.ssh
expect {
		"*(yes/no)?*" {
			send "yes\r"
			expect "password:"
			send "62960909\r"
		}
		"password:" { send "62960909\r" }
	   }
expect eof

spawn ssh root@10.10.3.102 

expect {
	"*(yes/no)?*" {
			send "yes\r"
			expect "password:"
			send "62960909\r"
			expect "*$*"
			send "/$1/.ssh/slash"
		}
	"password:" { 
			send "62960909\r"
			expect "Last"
			send "/$1/.ssh/slash\r" 
		}
}
expect "needed"
send "exit\r"
expect eof


EOF
