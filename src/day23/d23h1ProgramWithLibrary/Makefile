CFLAGS= -g  -I ./include/
LDFLAGS= -L./lib -lmyfun  

APP = main
SRC = $(wildcard ./src/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

CC = gcc
$(APP):$(OBJ)
	$(CC) -o $(APP) $^ $(LDFLAGS) $(CFLAGS)
	rm -f $(OBJ)

.PHONY:clean
clean:
	rm -f $(OBJ) $(APP)

