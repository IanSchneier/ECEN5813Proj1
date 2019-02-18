CC=gcc

CFLAGS=-Wall -Werror

DIR=src

TARGET=Project1

main: src/main.o 
	$(CC) $(CFLAGS) $(DIR)/*.c -o $(TARGET)

clean:
	rm -f $(DIR)/*.o $(TARGET)
