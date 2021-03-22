PROJECT_ROOT = /home/edward/mine/gosuncn/AVFileTest

TARGET = $(PROJECT_ROOT)/src/app

LIB_PATHS += -L$(PROJECT_ROOT)/libs
LIB_PATHS += -L$(PROJECT_ROOT)/libs/ffmpeg
LIB_PATHS += -L$(PROJECT_ROOT)/libs/opus

INCLUDE_PATHS += -I$(PROJECT_ROOT)/include
INCLUDE_PATHS += -I$(PROJECT_ROOT)/include/ffmpeg
INCLUDE_PATHS += -I$(PROJECT_ROOT)/include/opus

# LIBS += -lmod_AVFileSystemManager
LIBS += -lavformat -lavutil -lavcodec -lswscale -lswresample 
LIBS += -pthread -ldl

LDFLAGS += -Wl,-rpath=$(PROJECT_ROOT)/libs:$(PROJECT_ROOT)/libs/ffmpeg:$(PROJECT_ROOT)/libs/opus

STANDERED = -std=c++11

SOURCE=$(wildcard $(PROJECT_ROOT)/src/*.cpp)

# $(TARGET):$(PROJECT_ROOT)/src/main.cpp
$(TARGET):$(SOURCE)
	g++ $^ -g -o $@ $(LIB_PATHS) $(INCLUDE_PATHS) $(LIBS) $(LDFLAGS) $(STANDERED)

.PHONY:all clean std_all std_clean

clean:
	rm -f $(TARGET)
