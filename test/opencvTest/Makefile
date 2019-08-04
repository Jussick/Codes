TARGET=app
ASSETS=dst.jpg baseDst.jpg
CFLAGS=-I/home/luhengguang/PHOENIX2.0/Include_external/opencv2.4.8 -L/home/luhengguang/PHOENIX2.0/Lib_external
CFLAGS+=-lopencv_highgui -lopencv_core -lavcodec -lavformat -lavutil -lswresample -lswscale # -lopencv_imgcodecs
all:$(TARGET)

app:./opencvTest.cpp ./Base64.cpp
	g++ $^ -o $@ $(CFLAGS)
clean:
	rm -f $(TARGET) $(ASSETS)
