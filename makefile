CC = gcc
CFLAGS = -Wall -g
SRC = main.c hub.c apps/cmd.c apps/calc.c apps/notepad.c
OBJ = main.o hub.o cmd.o calc.o notepad.o
TARGET = ziper

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

hub.o: hub.c
	$(CC) $(CFLAGS) -c hub.c -o hub.o

cmd.o: apps/cmd.c
	$(CC) $(CFLAGS) -c apps/cmd.c -o cmd.o

calc.o: apps/calc.c
	$(CC) $(CFLAGS) -c apps/calc.c -o calc.o

notepad.o: apps/notepad.c
	$(CC) $(CFLAGS) -c apps/notepad.c -o notepad.o

clean:
	rm -f $(OBJ) $(TARGET)