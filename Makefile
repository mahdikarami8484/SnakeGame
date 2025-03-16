CC = x86_64-w64-mingw32-g++
CFLAGS = -std=c++2a -Wextra -Wall -I"$(CURDIR)/include"
EXT = .exe

all = main

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

main: build snake.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/snake.exe $(OBJ_DIR)/*.o main.cpp resources/logo.res

build:
	mkdir -p $(OBJ_DIR)

point.o:
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/point.o -c src/core/point.cpp

graphics.o: size.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/graphics.o -c src/core/graphics.cpp

system.o: graphics.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/system.o -c src/core/system.cpp

size.o:
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/size.o -c src/core/size.cpp

keyboard.o: system.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/keyboard.o -c src/core/keyboard.cpp

object.o: point.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/object.o -c src/objects/object.cpp

food.o: object.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/food.o -c src/objects/food.cpp

snake.o: food.o keyboard.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/snake.o -c src/objects/snake.cpp