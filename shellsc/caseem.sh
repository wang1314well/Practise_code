#!/bin/sh
echo "Is it moring ? Please answear yes or no"
read timeofday

case "$timeofday" in
    yes|y|Yes|YES)
	     echo "Good Morning"
		 echo "Up bright and early this morning"
		 ;;
    [nN]*)
	     echo "Good Afternoon"
		 ;;
     *)
	 echo "Sorry, answer not recongnized"
	 echo "Please answear yes or no"
	 exit 1
	 ;;
esac
exit 0
