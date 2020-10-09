SRC = $(wildcard *.c)
TARGETS = $(patsubst %.c,%.o, $(SRC))
TARGET = $(patsubst %.c, %, $(SRC))
APP = client server

ALL:client server

client:client.o common.o common.h
	cc -g client.o common.o -o $@

server:server.o common.o common.h
	cc -g server.o common.o -o $@

server.o:server.c common.h
	cc -c server.c

common.o:common.c common.h
	cc -c common.c

client.o:client.c common.h
	cc -c client.c


.PHONY:clean
	
clean:
	rm $(TARGETS) $(TARGET) $(APP)
	
