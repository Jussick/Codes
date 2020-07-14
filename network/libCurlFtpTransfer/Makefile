all:app

INCLUDE_DIR+=-I./include
LIB_DIR+=-L./lib
libs+=-lcurl
libs+=-Wl,-rpath=./lib

SOURCE=$(wildcard src/*.cpp)
# app:$(SRC_DIR)/main.cpp $(SRC_DIR)/FTPTransfer.cpp
app:$(SOURCE)
	g++ $^ -o $@ $(INCLUDE_DIR) $(LIB_DIR) $(libs) 

clean:
	rm -f app
