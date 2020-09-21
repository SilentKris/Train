#!/bin/bash

current=${HOME}/test/src
cd ${current}

file=`ls  ${current} | grep day`

for count in {1..9}
do
	 mv d${count}* day${count}
	
done
