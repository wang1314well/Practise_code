#!/bin/bash
a=$1
b=$2

if [ -z $a ] || [ -z $b ]
then
	echo "please enter two numbers"
	exit 1
fi

if [ $a -eq $b ];then
	echo "number a = number b"
else if [ $a -gt $b ]
	then
		echo "number a > number b"
	elif [ $a -lt $b ]
		then
			echo "number a < number b"
	fi
fi

