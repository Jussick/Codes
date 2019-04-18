CC=gcc

all:app toupper dup

app:main.c
	$(CC) $^ -o $@

toupper:toUpper.c
	$(CC) $^ -o $@

dup:dupTest.c
	$(CC) $^ -o $@

clean:
	rm -f app toupper dup

