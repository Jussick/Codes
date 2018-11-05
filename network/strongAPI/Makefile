all:libwrap.so

libwrap.so:wrap.c
	gcc -fPIC -shared -o libwrap.so wrap.c

clean:
	rm -f libwrap.so
