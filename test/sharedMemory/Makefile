CC=gcc
BINERY=writeProc readProc
all:$(BINERY)

writeProc:writeProcess.c
	$(CC) -o $@ $^

readProc:recieveProcess.c
	$(CC) -o $@ $^

clean:
	rm -f $(BINERY)
