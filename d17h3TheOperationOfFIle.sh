#!/bin/sh

tar -cf My_compress.tar

for FILE in `find ~/ -name "*.c"`
do
	cat $FILE >> My_file
	echo $FILE >> My_filename
	tar -rvf  My_compress.tar $FILE
done

file_count=`cat My_filename | wc -l`
echo "I have $file_count .c files!"
file_line_count=`cat My_file | wc -l`
echo "I have $file_line_count line code!"
tar -cjvf My_compress.tar.bz2 My_compress.tar --remove-file
rm My_file
