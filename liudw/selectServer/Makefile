BINARY=SelectServer Client 
LIBS=-L/Users/edwardlu/mine/Codes/liudw/selectServer -lwrap_s
all:$(BINARY) 

SelectServer:selectServer.c
	gcc $^ -o $@ $(LIBS)
Client:client.c
	gcc $^ -o $@ $(LIBS)

clean:
	rm -f $(BINARY) 



