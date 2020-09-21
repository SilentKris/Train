vpath %.c src
vpath %.h include



SRC = add.c sub.c multi.c div.c main.c
TARGETS = $(patsubst %.c, %.o, $(SRC))

CC = gcc
AR = ar

CFALGS = -g -Wall -lmylib -L lib -I include 
ARFLAGS = -rcs -o



#libmylib.a:$(TARGETS)
#	$(AR) $(ARFALGS) $@ $^

main:$(TARGETS)
	$(CC) $(CFALGS) $^ -o $@
	echo $(CFLAGS)

$(TARGETS):%.o:%.c common.h
	$(CC) $(CFLAGS) -c  $< -I include  


.PHONY:clean

clean:
	-rm $(TARGETS) main
