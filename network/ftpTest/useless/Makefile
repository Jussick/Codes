#CROSS = arm-hisiv100nptl-linux-
CXX = $(CROSS)g++ -g
RM=rm -f
CFLAGS = -Wall -Os -DLINUX

ALL=ftpget

all: $(ALL)

ftpget: ftpDownload.c
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o $(ALL)
