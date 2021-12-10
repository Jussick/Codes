CC = g++ -Wall -fPIC -std=c++11

TARGET = app
LIB_PATH = -L./include
LIBS = -lprotobuf -lTest

all:$(TARGET)

app:./protobufTest.cpp 
	$(CC) $^ -o $@ $(LIB_PATH) $(LIBS)

clean:
	rm -rf $(TARGET)*
