SRC = $(wildcard *.c)
TARGETS = $(patsubst %.c, %, $(SRC))

CC = gcc
CFLAGS = -Wall -g 
ALL:$(TARGETS)

$(TARGETS):%:%.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY:clean

clean:
	-rm $(TARGETS)
