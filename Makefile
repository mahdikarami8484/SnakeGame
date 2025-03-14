CC=x86_64-w64-mingw32-g++
CFLAGS=-std=c++2a -Wextra -Wall -I"$(shell cygpath -m "$(CURDIR)/include")"

all=main

main: snake.o
	$(CC) $(CFLAGS) -o snake.exe *.o

snake.o: snake.cpp point.o
	$(CC) $(CFLAGS) -o snake.o -c snake.cpp

point.o:
	$(CC) $(CFLAGS) -o point.o -c src/core/point.cpp