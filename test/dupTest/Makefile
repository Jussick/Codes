CC=gcc

all:app toupper

app:main.c
	$(CC) $^ -o $@

toupper:toUpper.c
	$(CC) $^ -o $@

clean:
	rm -f app toupper
