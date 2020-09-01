rm -rf ./200801

mkdir ./200801 

cp `find / -name sources.list`  ./200801

cd ./200801

touch {1..9}.c

tar -cvf my_test.tar *
