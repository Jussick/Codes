SOURCE=$(wildcard ./*.cpp)

app:$(SOURCE)
	g++ $^ -o $@ -lboost_filesystem -lboost_system -I./boost-1.65.0 -LLibs -Wl,-rpath=./Libs
clean:
	rm -f app
