#!/usr/bin/expect

set key_timeStamp [lindex $argv 0]

spawn ssh-keygen
expect "ssh/id_rsa):"
send "/root/.ssh/id_rsa$key_timeStamp\r"
expect "passphrase):"
send "\r"
expect "passphrase again:"
send "\r"
expect eof


