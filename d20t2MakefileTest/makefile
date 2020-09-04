app :fun1.o fun2.o main.o
	cc $^ -o $@

%.o : %.c %.h
	cc -c $^ -o $@


.PHONY=clean

clean:
	rm *.o app

