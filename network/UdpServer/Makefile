TARGET = server client
all: $(TARGET)

server:./udp-server.cpp
	g++ -g $^ -o $@

client:./udp-client.cpp
	g++ -g $^ -o $@

clean:
	rm -f $(TARGET)

rebuild:
	clean $(TARGET) all 
