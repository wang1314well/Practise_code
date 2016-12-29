#!/bin/bash

if [ "$1" = "" ] || [ "$2" = "" ]
then
	echo "please enter file name"
	exit 1
fi

if [ -e $2 ]
then
	echo "the file already exists"
	until [ ! -f $2 ]
	do
		sleep 1
	done
	echo "the file have been deleted"
fi

if [ !'mv $1 $2' ]
then 
	echo "mv successful"
else
	echo "mv error"
fi

