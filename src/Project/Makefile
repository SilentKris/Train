SRC = $(wildcard *.c)
TARGETS = $(patsubst %.c, %.o, $(SRC))
LIB = database.h personmanage.h msgque.h datastruct.h  

app:$(TARGETS) $(LIB)
	cc $(TARGETS) -o $@ -I . -lsqlite3 -lpthread

database.o:database.c $(LIB)
	cc -c $< -I . -lsqlite3 -lpthread

personmanage.o:personmanage.c $(LIB)

tcpser_fork.o:tcpser_fork.c $(LIB)

msgque.o: msgque.c $(LIB)

datastruct.o: datastruct.c $(LIB)


.PHONY:clean

clean:
	-rm -r $(TARGETS) app
	

