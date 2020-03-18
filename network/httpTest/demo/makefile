all: client server

INCS=../HttpLib

client: client.cpp
	g++ client.cpp -o client -lboost_system -lboost_filesystem -lboost_regex -std=c++11 -lpthread

server: server.cpp
	g++ -DUSE_BOOST_REGEX server.cpp -o server -lboost_system -lboost_filesystem -lboost_regex -std=c++11 -lpthread

clean:
	rm -rf client server
