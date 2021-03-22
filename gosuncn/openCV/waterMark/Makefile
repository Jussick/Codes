INC_DIR=-I./include
INC_DIR+=-I./include/freeType
INC_DIR+=-I./include/freeType/freetype

LIB_DIR=-L./libs
LIB_DIR+=-L./libs/freeType

RUNLIB_DIR=-Wl,-rpath=./libs:libs/ffmpeg-2.8.12/
RUNLIB_DIR+=-Wl,-rpath=./libs/freeType
RUNLIB_DIR+=-Wl,-rpath=/home/edward/mine/openCV/libs

LIB_DEPENDS=-lfreetype -lopencv_core -lopencv_highgui -lopencv_imgproc 

app:./DrawText.cpp ./CvxText.cpp
	g++ $^ -o $@ $(INC_DIR) $(LIB_DIR) $(LIB_DEPENDS) -std=c++11 $(RUNLIB_DIR) -g 
clean:
	rm -f app
