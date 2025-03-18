CC = x86_64-w64-mingw32-g++
CFLAGS = -std=c++2a -Wextra -Wall -I"$(CURDIR)/include"
EXT = .exe

all = main

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj

main: build gameView.o
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

view.o: graphics.o system.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/view.o -c src/views/view.cpp

viewController.o: system.o view.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/viewController.o -c src/views/viewController.cpp

object.o: point.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/object.o -c src/objects/object.cpp

food.o: object.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/food.o -c src/objects/food.cpp

block.o: object.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/block.o -c src/objects/block.cpp

player.o:
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/player.o -c src/objects/player.cpp

snake.o: player.o keyboard.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/snake.o -c src/objects/snake.cpp

gameView.o: view.o viewController.o food.o snake.o block.o
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/gameView.o -c src/views/gameView.cpp