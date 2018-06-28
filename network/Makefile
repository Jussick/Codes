BINERY=server client
all:$(BINERY)

server:server.c
	gcc server.c -o server

client:client.c
	gcc client.c -o client

clean:
	rm -f $(BINERY) *.o
