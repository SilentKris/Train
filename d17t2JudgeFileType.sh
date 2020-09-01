#!/bin/bash

if [ $# -lt 1 ]
then	echo "You are not input file name! "

elif	[ -d $1 ]
then	echo "This is a dictory!"

elif [ -f $1 ] 
then	echo "This is common dictory!"

elif [ -L $1 ]
then    echo "This is a link file"

else
	echo "I don't know!"
fi

