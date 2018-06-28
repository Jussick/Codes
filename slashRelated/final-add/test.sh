#!/bin/bash

# Judge if user is exist

user=$1

id $user >& /dev/null
if [ $? -eq 0 ];then
	exit 0
else
	exit 3
fi
