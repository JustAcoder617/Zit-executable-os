CC = gcc
CFLAGS = -Wall -g

TARGETS = ziper.exe hub.exe apps/notepad.exe apps/calc.exe apps/cmd.exe

all: $(TARGETS)

ziper.exe: main.c
	$(CC) $(CFLAGS) -o $@ main.c

hub.exe: hub_main.c hub.c
	$(CC) $(CFLAGS) -o $@ hub_main.c hub.c

apps/notepad.exe: apps/notepad_main.c apps/notepad.c
	$(CC) $(CFLAGS) -o $@ apps/notepad_main.c apps/notepad.c

apps/calc.exe: apps/calc_main.c apps/calc.c
	$(CC) $(CFLAGS) -o $@ apps/calc_main.c apps/calc.c -lm

apps/cmd.exe: apps/cmd_main.c
	$(CC) $(CFLAGS) -o $@ apps/cmd_main.c

.PHONY: all clean
clean:
	rm -f $(TARGETS) *.o hub_main.o