#!/bin/sh

for FILE in `find $HOME/test -name "*.c"`
do
#	echo "${FILE} has `wc -l $FILE | cut -c 1-3` line"
#	cat $FILE >> list
	cat $FILE | wc -l
	
done
