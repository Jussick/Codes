CC = g++ -Wall -fPIC -std=c++11

TARGET = app
LIBS = -lprotobuf

all:$(TARGET)

app:./include/Test.pb.cc ./protobufTest.cpp 
# app: ./protobufTest.cpp 
	$(CC) $^ -o $@ $(LIBS)

clean:
	rm -rf $(TARGET)*
