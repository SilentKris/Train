#!/bin/sh

echo "Please input a integer Number or "quit":"

while read SCORE
do
	if	test $SCORE = "quit"
	then	echo "quit!"
		break
	elif		test $SCORE -ge 90
	then		echo "The level is A!"
	elif		test $SCORE -ge 80
	then		echo "The level is B!"
	elif		test $SCORE -ge 70
	then		echo "The level is C!"
	elif		test $SCORE -ge 60
	then		echo "The level is D!"
	elif		test $SCORE -ge 0
	then 		echo "The level is false!"
	fi

done

while read SCORE
	if [ $SCORE = "quit"]
	then break
	else
	do
		case `expr $SCORE / 10` in
			10)
				echo "A"
				;;
			9)
				echo "B"
				;;
			8)
				echo "C"
				;;
			7)
				echo "D"
				;;
			0|1|2|3|4|5|6)
				echo "E"
				;;
		esac

	done
fi
