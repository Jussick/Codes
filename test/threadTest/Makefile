CC=gcc
BINARY=mutex threadCreate semaphore
LIBS=-lpthread
#srcs=$(wildcard *.c)

all:$(BINARY)

mutex: threadmutex.c
	$(CC) -o $@ $^ $(LIBS)

threadCreate: threadCreate.c
	$(CC) -o $@ $^ $(LIBS)

semaphore: semaphore.c
	$(CC) -o $@ $^ $(LIBS)

clean:
	rm -f $(BINARY)
