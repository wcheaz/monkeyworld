CC = gcc
CFLAGS = -Wall -std=c99
LIBS += -lm

MonkeyWorld: MonkeyWorld.o
	$(CC) $(CFLAGS) MonkeyWorld.o -o MonkeyWorld $(LIBS)

MonkeyWorld.o: MonkeyWorld.c