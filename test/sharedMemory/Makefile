CC=gcc
all: writeProc readProc

writeProc:writeProcess.c
	$(CC) -o $@ $^

readProc:recieveProcess.c
	$(CC) -o $@ $^

clean:
	rm -f readProc writeProc
