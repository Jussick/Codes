all:app

CC=g++ -std=c++11
INCLUDE_DIR+=-I./include
LIB_DIR+=-L./lib
libs+=-lFoundation -pthread -ldl
libs+=-Wl,-rpath=./lib

SOURCE=$(wildcard *.cpp)
# app:$(SRC_DIR)/main.cpp $(SRC_DIR)/FTPTransfer.cpp
app:$(SOURCE)
	$(CC) $^ -o $@ $(INCLUDE_DIR) $(LIB_DIR) $(libs) 

clean:
	rm -f app
