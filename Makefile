CC = x86_64-w64-mingw32-g++
CFLAGS = -std=c++2a -Wextra -Wall -I"$(CURDIR)/include"
EXT = .exe

all = main

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

main: build point.o graphics.o size.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/snake.exe $(OBJ_DIR)/*.o main.cpp

build:
	mkdir -p $(OBJ_DIR)

snake.o: snake.cpp point.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/snake.o -c snake.cpp

point.o:
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/point.o -c src/core/point.cpp

graphics.o:
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/graphics.o -c src/core/graphics.cpp

size.o:
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/size.o -c src/core/size.cpp