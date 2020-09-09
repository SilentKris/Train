#!/bin/bash

cd ~/test; mkdir A;cd A

for FILE in `find ~/test -name "*.c"`
do
	echo $FILE >> ~/test/A/count.txt
	cat  $FILE >> ~/test/A/line_count_file
	cp 	 $FILE ~/test/A
done


file_count=`cat count.txt | wc -l`
line_count=`cat line_count_file | wc -l`

echo "总文件数是 $file_count" >> ~/test/A/count.txt
echo "总行数是$line_count" >> ~/test/A/count.txt

tar -cjvf my_compress.tar.bz2 *.c
rm  `pwd`/line_count_file
