BINARY=client server

all:$(BINARY)

server:./fileServer.c
	gcc -o $@ $^

client:./client.c
	gcc -o $@ $^

clean:
	rm -f $(BINARY)
