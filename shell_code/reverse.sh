#!/bin/bash
echo -n "Please enter number:"
read n
sd=0
rev=""
on=$n
echo "you put number is $n"
while [ $n -gt 0 ]
do
	sd=$(( $n % 10))
	n=$(($n / 10))
	rev="$rev$sd"
done
echo "$on in reverse order $rev"
