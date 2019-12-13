
CC 	= gcc
CPP = g++
RM  = rm -rf

## target exec file name
TARGET     := jsonTest

## source file path
SRC_PATH   	:= .

## get all include path
INCS  += -I$(SRC_PATH)

## get all library path
LIBS  += -L$(SRC_PATH)

CPPSRCS = $(wildcard ./*.cpp)
CSRCS 	= $(wildcard ./*.c) 

COBJS 	:= $(CSRCS:.c=.o)
CPPOBJS := $(CPPSRCS:.cpp=.o)

# -Wall
CFLAGS 		+= $(INCS) 
CFLAGS 		+= -g -fPIC
CPPFLAGS 	+= $(INCS) 
CPPFLAGS 	+= -std=c++11 -g

LDFLAGS 	+= -lstdc++ -ljsoncpp

all:$(TARGET)

$(COBJS) : %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 
$(CPPOBJS) : %.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@ 

$(TARGET) : $(COBJS) $(CPPOBJS)
	$(CC) -o $(TARGET) $(COBJS) $(CPPOBJS) $(LDFLAGS) $(LIBS) 
	
	$(RM) $(COBJS) $(CPPOBJS)

clean:            
	$(RM) $(TARGET) $(COBJS) $(CPPOBJS)

