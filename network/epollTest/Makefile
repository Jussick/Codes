TARGET=server client
INCLUDES=./include
all:$(TARGET)

server:server.cpp wrap.c
	g++ -o $@ $^ -I$(INCLUDES)

client:client.cpp wrap.c
	g++ -o $@ $^ -I$(INCLUDES)

clean:
	rm -f $(TARGET)

.PHONY:clean
