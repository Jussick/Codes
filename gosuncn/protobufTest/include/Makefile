CC = g++ -g -Wall -fPIC -std=c++11
AR = ar -r

PROJ_LIB = libTest.a
PROJ_OBJ = Test.pb.o

all:$(PROJ_LIB) 

prepare:
	protoc -I=./  --cpp_out=./  Test.proto

$(PROJ_LIB):$(PROJ_OBJ)
	$(AR) $(PROJ_LIB) $(PROJ_OBJ) 

.cc.o:
	$(CC) -c $< -o $@

clean:
	#rm -f *.o
	rm -f Test.pb.*
	rm -f $(PROJ_LIB)
