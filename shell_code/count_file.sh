#!/bin/bash
counter=0
for files in *
do 
	if [ -f "$files" ]
	then
		counter=`expr $counter + 1`
	fi
done
echo "there are $counter files in `pwd`"
