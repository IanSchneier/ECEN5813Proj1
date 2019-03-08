CC=gcc

CFLAGS=-Wall -Werror -Iinc/

SRC := main.c allocate.c display.c help.c invert.c pattern.c verify.c write.c

vpath %.c src/
vpath %.h inc/

OBJ := $(SRC:.c=.o)

Project1: $(OBJ) 
	$(CC) -o Project1 $(OBJ) $(CFLAGS)
clean:
	rm -f *.o Project1 test

test: $(OBJ) 
	$(CC) -o test $(OBJ) $(CFLAGS)
	./test < test_script.txt
