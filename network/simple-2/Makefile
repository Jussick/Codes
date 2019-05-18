BINERY=server client app
LIBS=unp

all:$(BINERY)

server:server.c
	gcc server.c -o server -l $(LIBS)

client:client.c
	gcc client.c -o client -l $(LIBS)

app:test.c
	gcc $^ -o $@

clean:
	rm -f $(BINERY) *.o
