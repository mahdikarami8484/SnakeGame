CC = x86_64-w64-mingw32-g++
CFLAGS = -std=c++2a -Wextra -Wall -I"$(CURDIR)/include"
EXT = .exe

all=main

main: point.o graphics.o main.cpp
	$(CC) $(CFLAGS) -o snake.exe *.o main.cpp

snake.o: snake.cpp point.o
	$(CC) $(CFLAGS) -o snake.o -c snake.cpp

point.o:
	$(CC) $(CFLAGS) -o point.o -c src/core/point.cpp

graphics.o:
	$(CC) $(CFLAGS) -o graphics.o -c src/core/graphics.cpp