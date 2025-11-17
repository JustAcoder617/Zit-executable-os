CC = gcc
CFLAGS = -Wall -g

TARGETS = ziper.exe hub.exe apps/notepad.exe apps/calc.exe apps/cmd.exe

all: $(TARGETS)

ziper.exe: main.c
	$(CC) $(CFLAGS) -o $@ main.c

hub.exe: hub.c hub.o
	$(CC) $(CFLAGS) -o $@ hub.c hub.o

apps/notepad.exe: apps/notepad.c apps/notepad.o
	$(CC) $(CFLAGS) -o $@ apps/notepad.o apps/notepad.c

apps/calc.exe: apps/calc.c apps/calc.o
	$(CC) $(CFLAGS) -o $@ apps/calc.o apps/calc.c -lm

apps/cmd.exe: apps/cmd_main.c
	$(CC) $(CFLAGS) -o $@ apps/cmd_main.c

.PHONY: all clean
clean:
	rm -f $(TARGETS) *.o hub_main.o